
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 * Dado um número inteiro positivo fornecido pelo usuário, informe a soma dos 
 * números ímpares entre 0 e o número informado pelo usuário.
 * Nota: o úsuário não poderá informar números negativos, nem 0.
 * Caso ele informe, informar uma mensagem de erro.
 */
public class SomaImpares {
    public static void main(String[] args) {
        int n=0, soma=0;
        Scanner teclado = new Scanner(System.in);
        System.out.println("Digite o número: ");
        n = teclado.nextInt();
        while(n < 1){
            System.out.println("Número inválido");
            System.out.println("Digite o número novamente: ");
            n = teclado.nextInt();
        }
        for(int j=1; j <= n; j++){
            if(j%2 != 0){
                soma += j;
            }
        }
        System.out.println("Soma dos ímpares é = " + soma);
    }
}
