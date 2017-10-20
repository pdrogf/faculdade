
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;



/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Pedro
 */
public class ThreadDataHora extends Thread{
            
    @Override
    public void run(){
        DateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
        
        
        int qtd=0;
        while(true){
            if(qtd == 5){
                System.out.println("Impresso 5x data atual, finalizando sistema..");
                System.exit(qtd);
            }
            Date date = new Date();
            System.out.println(dateFormat.format(date));
            qtd++;
            try {
                Thread.sleep(10000);
            } catch (Exception e) {
            }
        }
    }
}
