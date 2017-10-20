
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

public class Servidor {

    public static void main(String[] args) {
        ServerSocket server;
        ArrayList<Palavra> palavras = new ArrayList<>();

        try {//Verificacao e criacao do arquivo ListaPalavras
            File arq = new File("ListaPalavras.txt");
            if (!arq.exists()) {
                ArquivoListaPalavras a = new ArquivoListaPalavras();
                a.criaArquivo();
            }
            System.out.println("Arquivo carregado!");
            Scanner sc = new Scanner(new File("ListaPalavras.txt"));
            String linha;
            while (sc.hasNextLine() && (linha = sc.nextLine()) != null) {
                String[] lineSplit = linha.split("\\|");
                if (lineSplit.length == 2) {
                    palavras.add(new Palavra(lineSplit[0], lineSplit[1]));
                }
            }
            sc.close();
        } catch (FileNotFoundException ex) {
            System.out.println("Arquivo de palavras não encontrado. Encerrando programa.");
            System.exit(1);
        }
        try {// Inicia o servidor
            server = new ServerSocket(8765);
            while (true) {
                Socket s = server.accept();
                new ServidorThread(s, palavras).start();
            }
        } catch (IOException ex) {
            System.out.println("Nao foi possível iniciar o servidor na porta 8765\n" +ex);
            System.exit(1);
        }
    }
}
