
import java.io.*;
import java.net.*;
import java.util.*;

public class Cliente {

    public static void main(String[] args) {

        Scanner teclado = new Scanner(System.in);
        String ipServer = "localhost";
        int portServer = 12345;
        String path = "";
        Socket socket;
        System.out.println("Conectando no servidor...");
        System.out.println("Digite o caminho do diretorio: ");
        path = teclado.nextLine();
        try {
            socket = new Socket(ipServer, portServer);
            Scanner entrada = new Scanner(socket.getInputStream());
            PrintWriter saida = new PrintWriter(socket.getOutputStream());
            saida.println(path);
            saida.flush();

            while (entrada.hasNextLine()) {
                System.out.println(entrada.nextLine());
            }

            socket.close();
            System.out.println("Conexao encerrada");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
