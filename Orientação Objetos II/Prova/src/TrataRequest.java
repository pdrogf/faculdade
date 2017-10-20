
import java.net.*;
import java.io.*;
import java.util.*;

public class TrataRequest extends Thread {

    private Socket socket;
    private Scanner entrada;
    private PrintWriter saida;

    TrataRequest(Socket socket) throws IOException {
        this.socket = socket;
        this.entrada = new Scanner(this.socket.getInputStream());
        this.saida = new PrintWriter(this.socket.getOutputStream());
    }

    public void run() {

        String linha = entrada.nextLine();
        File file = new File(linha);
        File[] arquivos = file.listFiles();
        System.out.println("Requisicao Recebida: " + linha);

        if (!file.exists()) {
            saida.println("PASTA_INEXISTENTE");
        } else if (!file.canRead()) {
            saida.println("SEM_PERMISSÃO");
        } else {
            String listaArquivos = "";
            try {
                for (File arquivo : arquivos) {
                    listaArquivos += arquivo.getName()+" |";
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            saida.println(listaArquivos);
        }

        saida.println("Comando Invalido");
        saida.flush();

        System.out.println("Encerrando conexao: " + linha);
        try {
            this.socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
