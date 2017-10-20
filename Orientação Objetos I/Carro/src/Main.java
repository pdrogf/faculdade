
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Pedro Grazziani
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int opcao;
        Scanner teclado = new Scanner(System.in);

        System.out.println("Escolha uma das opções abaixo:");
        System.out.println("0 para Sair");
        System.out.println("1 para aumentar velocidade");
        System.out.println("2 para diminuir velocidade");
        opcao = teclado.nextInt();
        
        if(opcao != 1 && opcao != 2){
            System.out.println("Encerrando programa...");
            return; 
        }
        System.out.println("Digite a cor do carro: ");
        String cor = teclado.nextLine();
        System.out.println("Digite a capacidade do motor do carro: ");
        double capacidade = teclado.nextDouble();
        Carro carro = new Carro(cor, capacidade);

        switch (opcao) {
            case 1:
                System.out.println("Digite quantos KM/H deseja aumentar na velocidade: ");
                carro.aumentarVelocidade(teclado.nextDouble());
                System.out.println("Velocidade atual: " + carro.getVelocidade() + "km/h");
                break;
            case 2:
                System.out.println("Digite quantos KM/H deseja diminuir na velocidade: ");
                carro.reduzirVelocidade(teclado.nextDouble());
                System.out.println("Velocidade atual: " + carro.getVelocidade() + "km/h");
                break;            
        }
    }
}
