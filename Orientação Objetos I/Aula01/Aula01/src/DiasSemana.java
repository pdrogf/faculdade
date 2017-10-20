
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 * Faça um programa em Java que receba um número fornecido pelo usuário e 
 * exiba o dia correspondente da semana. (1-Domingo, 2- Segunda, etc.), 
 * se digitar outro valor deve aparecer valor inválido.
 *  Utilize uma estrutura switch/case para este exercício
 */
public class DiasSemana {
    public static void main(String[] args) {
        int dia=0;
        Scanner teclado = new Scanner(System.in);
        System.out.println("Digite o dia da semana entre 1 e 8: ");
        dia = teclado.nextInt();
        while(dia < 1 || dia > 7){
            System.out.println("Valor inválido, digite novamente: ");
            dia = teclado.nextInt();
        }
        switch(dia){
            case 1:
                System.out.println("Domingo");
                break;
            case 2:
                System.out.println("Segunda-Feira");
                break;                
            case 3:
                System.out.println("Terça-Feira");
                break;
            case 4:
                System.out.println("Quarta-Feira");
                break;
            case 5:
                System.out.println("Quinta-Feira");
                break;
            case 6:
                System.out.println("Sexta-Feira");
                break;
            case 7:
                System.out.println("Sábado");
                break;
        }
    }
}
