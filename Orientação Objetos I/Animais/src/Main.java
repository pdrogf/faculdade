
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
        Scanner teclado = new Scanner(System.in);
        Animal animal = null;

        int tipo;

        System.out.println("Selecione: ");
        System.err.println("1 - Peixe");
        System.out.println("2 - Mamífero");

        tipo = teclado.nextInt();
        if (tipo == 1) {            
            System.out.print("Digite o nome do peixe: ");
            String nome = teclado.nextLine();
            System.out.println("Digite o comprimento: ");
            int comprimento = teclado.nextInt();
            System.out.println("Digite a cor do peixe: ");
            String cor = teclado.nextLine();
            System.out.println("Digite o ambiente do peixe: ");
            String ambiente = teclado.nextLine();
            System.out.println("Digite a velocidade: ");
            int velocidade = teclado.nextInt();
            animal = new Peixe(nome, comprimento, 0, cor, ambiente, velocidade); 
            
        } else if (tipo == 2) {
            System.out.print("Digite o nome do mamífero: ");
            String nome = teclado.nextLine();
            System.out.println("Digite o comprimento: ");
            int comprimento = teclado.nextInt();
            System.out.println("Digite a cor do mamífero: ");
            String cor = teclado.nextLine();
            System.out.println("Digite o ambiente do mamífero: ");
            String ambiente = teclado.nextLine();
            System.out.println("Digite a velocidade: ");
            int velocidade = teclado.nextInt();
            animal = new Mamifero(nome, comprimento, 4, cor, ambiente, velocidade);
        } else {
            System.out.println("Valor informado invalido");
            return;
        }
        animal.listaDados();
    }
}
        