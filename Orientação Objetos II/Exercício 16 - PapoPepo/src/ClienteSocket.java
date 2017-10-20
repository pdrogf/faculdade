
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *Faça um sistema em Java para que dois programas conversem o Papo/Pepo.

O cliente deve conectar a um servidor executando na porta 6543 e enviar ao servidor o texto PAPO.

O servidor deve receber a conexão, imprimir o texto recebido e retornar para o cliente o texto PEPO.

Fazer os dois programas ficarem imprimindo PAPO e PEPO até parar os programas
 * @author pedro.grazziani
 */
public class ClienteSocket {

    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 6543);
            PrintWriter output = new PrintWriter(socket.getOutputStream());
            Scanner input = new Scanner(new InputStreamReader(socket.getInputStream()));
            
            output.println("PAPO");
            output.flush();
            
            String linha;
            while ((linha = input.nextLine()) != null) {
                System.out.println(linha);
                output.println("PAPO");
                output.flush();
            } 
            output.close();
            input.close();
            socket.close();
        } catch (Exception e) {
            System.out.println("Erro ao comunicar com servidor!"+e);
        }
        
    }
    
}
