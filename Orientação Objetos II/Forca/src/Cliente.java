
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

public class Cliente {

    private static <T> T recebeMensagem(Scanner in, Class<T> classe) {
        GsonBuilder gsonb = new GsonBuilder();
        Gson gson = gsonb.excludeFieldsWithoutExposeAnnotation().create();
        String mensagem = RecebeEnviaMsg.recebeMsg(in);
        return gson.fromJson(mensagem, classe);
    }

    public static void printPalavra(Palavra palavra, ArrayList<Character> letrasAcertadas) {
        System.out.print("Tamanho da palavra sorteada =  " + palavra.getPalavra().length());
        int acertos = 0;
        for (int i = 0; i < palavra.getPalavra().length(); i++) {
            char charAt = palavra.getPalavra().toUpperCase().charAt(i);
            if (letrasAcertadas.contains(charAt)) {
                acertos++;
                System.out.print(palavra.getPalavra().charAt(i));
            } else if (!Character.isLetter(charAt)) {
                System.out.print(palavra.getPalavra().charAt(i));
            } else {
                System.out.print("_");
            }
        }
        if (acertos >= (palavra.getPalavra().length() / 2)) {
            System.out.println("Dica da palavra: " + palavra.getDica());
        }        
    }
    public static boolean acertouPalavra(Palavra palavra, ArrayList<Character> letrasAcertadas) {
        for (int i = 0; i < palavra.getPalavra().length(); i++) {
            char charAt = palavra.getPalavra().toUpperCase().charAt(i);

            if (Character.isLetter(charAt) && !letrasAcertadas.contains(charAt)) {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int porta = 0;
        System.out.print("Qual o ip do servidor? ");
        String endereco = sc.nextLine();
        System.out.print("Qual a porta do servidor? ");        
        porta = Integer.parseInt(sc.nextLine());           
        System.out.print("Informe o nome do jogador: ");
        String nomeUsuario = sc.nextLine();
        System.out.print("Informe a chave do usuário: ");
        String chaveUsuario = sc.nextLine();
        try {
            Socket s = new Socket(endereco, porta);
            Scanner in = new Scanner(s.getInputStream());
            PrintWriter out = new PrintWriter(s.getOutputStream());

            int vitorias = 0;
            int derrotas = 0;
            while (true) {
                RecebeEnviaMsg.enviaMsg("BUSCARPALAVRA", out);
                Palavra palavra = recebeMensagem(in, Palavra.class);

                int erros = 0;
                ArrayList<Character> letrasAcertadas = new ArrayList<>();
                while (true) {
                    printPalavra(palavra, letrasAcertadas);

                    System.out.print("\nDigite uma letra: ");
                    String letraDigitada = sc.nextLine();
                    char letra = Character.toUpperCase(letraDigitada.charAt(0));
                    if (!Character.isLetter(letra)) {
                        System.out.println("Caracter inválido");
                        continue;
                    }
                    if (palavra.getPalavra().toUpperCase().indexOf(letra) != -1) {
                        if (letrasAcertadas.indexOf(letra) == -1) {
                            letrasAcertadas.add(letra);
                            if (acertouPalavra(palavra, letrasAcertadas)) {
                                System.out.println("Correto, palavra da forca é:  " + palavra.getPalavra());
                                vitorias++;
                                break;
                            }
                        } else {
                            System.out.println("Letra já escolhida! ");
                        }
                    } else {
                        erros++;
                        if (erros <= 4) {
                            System.out.println("Letra não existe na palavra!");
                        } else {
                            System.out.println("5 erros, perdeu!");
                            System.out.println("A palavra da forca é: " + palavra.getPalavra());
                            derrotas++;
                            break;
                        }
                    }
                }
                System.out.print("Jogar novamente? (responda com SIM ou NÃO) ");
                String resposta = sc.nextLine().toUpperCase();
                while (!resposta.equals("SIM") && !resposta.equals("NÃO") && !resposta.equals("NAO")) {
                    System.out.println("Responda com SIM ou NÃO");
                    resposta = sc.nextLine().toUpperCase();
                }
                if (!resposta.equals("SIM")) {
                    RecebeEnviaMsg.enviaMsg("ENCERRARJOGO " + nomeUsuario + " " + chaveUsuario + " " + vitorias + " " + derrotas, out);
                    Jogador usuario = recebeMensagem(in, Jogador.class);
                    break;
                }
            }
            RecebeEnviaMsg.enviaMsg("BUSCARRANKING", out);
            Ranking ranking = recebeMensagem(in, Ranking.class);
            System.out.println("Ranking de usuários:");
            for (CalculoPercentualJogador jogPercentual : ranking.getRanking()) {
                System.out.println("Usuário: " + jogPercentual.getJogador());
                System.out.println("Vitórias: " + jogPercentual.getVitorias());
                System.out.println("Derrotas: " + jogPercentual.getDerrotas());
                System.out.println("Percentual de vitórias: " + jogPercentual.getPercentual() + "\n");
            }
            in.close();
            out.close();
            s.close();
        } catch (IOException ex) {
            System.out.println("Erro ao conectar no servidor \n"+ ex);
        }
    }
}
