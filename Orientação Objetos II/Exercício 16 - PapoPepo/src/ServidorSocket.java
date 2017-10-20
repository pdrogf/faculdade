
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class ServidorSocket {
    public static void main(String[] args){
        try {
            ServerSocket server = new ServerSocket(6543);
            Socket s = server.accept();
            Scanner input = new Scanner(s.getInputStream());
            PrintWriter output = new PrintWriter(s.getOutputStream());
            
            String linha;
            while ((linha = input.nextLine()) != null) {
                System.out.println(linha);
                output.println("PEPO");
                output.flush();
            }          
            
            input.close(); 
            output.close();
            s.close();            
        } catch (Exception e) {
            System.out.println("Erro ao processar entrada!"+e);
        }
    }
}
