
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.*;

public class ServidorThread extends Thread {

    private Socket s;
    List<Palavra> palavras;

    public ServidorThread(Socket socket, List<Palavra> palavras) {
        this.s = socket;
        this.palavras = palavras;
    }

    @Override
    public void run() {
        try {            
            GsonBuilder gsonb = new GsonBuilder();
            Gson gson = gsonb.excludeFieldsWithoutExposeAnnotation().create();
            Scanner in = new Scanner(s.getInputStream());
            PrintWriter out = new PrintWriter(s.getOutputStream());
            String caminhoArq = "usuarios.bin";

            while (true) {
                String mensagem = RecebeEnviaMsg.recebeMsg(in);
                if (mensagem != null && mensagem.trim().toUpperCase().equals("BUSCARPALAVRA")) {
                    int index = (int) (Math.random() * palavras.size());
                    RecebeEnviaMsg.enviaMsg(gson.toJson(palavras.get(index)), out);
                } else if (mensagem != null && mensagem.trim().toUpperCase().equals("BUSCARRANKING")) {
                    ArrayList<Jogador> jogadores = new ArrayList<>();
                    ArrayList<CalculoPercentualJogador> storePercentual = new ArrayList<>();
                    try {
                        jogadores = LeituraEscritaArquivo.leArquivoObjeto(caminhoArq, ArrayList.class);
                    } catch (FileNotFoundException ex) {
                    }
                    for (Jogador usuarioStore : jogadores) {
                        storePercentual.add(new CalculoPercentualJogador(usuarioStore.getJogador(), usuarioStore.getVitorias(), usuarioStore.getDerrotas()));
                    }
                    storePercentual.sort((sp1, sp2) -> Double.compare(sp2.getPercentual(), sp1.getPercentual()));
                    RecebeEnviaMsg.enviaMsg(gson.toJson(new Ranking(storePercentual)), out);
                } else if (mensagem != null && mensagem.trim().toUpperCase().startsWith("ENCERRARJOGO")) {
                    try {
                        String[] dados = mensagem.trim().split(" ");
                        ArrayList<Jogador> store = new ArrayList<>();
                        try {
                            store = LeituraEscritaArquivo.leArquivoObjeto(caminhoArq, ArrayList.class);
                        } catch (FileNotFoundException ex) {
                        }
                        Jogador usuario = null;
                        for (Jogador usuarioStore : store) {
                            if (usuarioStore.getJogador().equals(dados[1]) && usuarioStore.getChave().equals(dados[2])) {
                                usuarioStore.setVitorias(usuarioStore.getVitorias() + Integer.parseInt(dados[3]));
                                usuarioStore.setDerrotas(usuarioStore.getDerrotas() + Integer.parseInt(dados[4]));
                                usuario = usuarioStore;
                            }
                        }
                        if (usuario == null) {
                            usuario = new Jogador();
                            usuario.setJogador(dados[1]);
                            usuario.setChave(dados[2]);
                            usuario.setVitorias(Integer.parseInt(dados[3]));
                            usuario.setDerrotas(Integer.parseInt(dados[4]));
                            store.add(usuario);
                        }
                        LeituraEscritaArquivo.escreveArquivoObjeto(caminhoArq, store);
                        RecebeEnviaMsg.enviaMsg(gson.toJson(usuario), out);
                    } catch (Exception ex) {
                        ex.printStackTrace();
                        break;
                    }
                } else if (mensagem == null) {
                    break;
                }
            }
            in.close();
            out.close();
            s.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
