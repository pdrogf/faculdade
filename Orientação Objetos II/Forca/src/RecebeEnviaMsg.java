
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class RecebeEnviaMsg {

    public static String recebeMsg(Scanner in) {
        try {
            String texto = in.nextLine();
            return texto;
        } catch (NoSuchElementException ex) {
            return null;
        }
    }

    public static void enviaMsg(String mensagem, PrintWriter out) {
        out.println(mensagem);
        out.flush();
    }
}
