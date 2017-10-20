
import java.util.Random;
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
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
       Random gerador = new Random();
       int n1=0, n2=0, qtdJogadores=0, nTentativas=1;
       
        System.out.println("Quantos jogadores?");
        qtdJogadores = sc.nextInt();
        
        
        if(qtdJogadores == 1){
            n1 = gerador.nextInt(1000);
            
            while(true){
                System.out.println("Adivinhe o número sorteado:");
                n2 = sc.nextInt();
                if(n1 == n2){
                    System.out.println("Adivinhou");
                    System.out.println("Número de tentativas: "+nTentativas);
                    break;
                }else if(n2 > n1){
                   System.out.println("O número digitado é maior que o número a ser adivinhado");
                   nTentativas++; 
                }else{
                   System.out.println("O número digitado é menor que o número a ser adivinhado");
                   nTentativas++; 
                }
            }
        }else if(qtdJogadores ==2){
            System.out.println("Primeiro Jogador, digite um numero entre 1 e 1000");
            n1 = sc.nextInt();            
            while(true){
                System.out.println("Segundo Jogador, adivinhe o número do primeiro jogador");
                n2 = sc.nextInt();
                if(n2 == n1){
                    System.out.println("Adivinhou o número digitado!");
                    System.out.println("Número de tentativas:"+nTentativas);
                    break;
                }else if(n2 > n1){
                    System.out.println("O número digitado é maior que o número a ser adivinhado");
                    nTentativas++;
                }else{
                   System.out.println("O número digitado é menor que o número a ser adivinhado");
                   nTentativas++; 
                }
            }
        }       
    }
    
}
