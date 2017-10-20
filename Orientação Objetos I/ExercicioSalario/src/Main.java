
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
    public static void main(String[] args) {
        Empregado emp1 = new Empregado();
        Scanner teclado = new Scanner(System.in);
        
        System.out.println("Digite o nome: ");
        emp1.setNome(teclado.nextLine());
        System.out.println("Digite o salário: ");
        emp1.setSalario(teclado.nextDouble());
        System.out.println("Digite o % de aumento: ");
        System.out.println(emp1.aumentaSalario(teclado.nextDouble()));        
    }
}
