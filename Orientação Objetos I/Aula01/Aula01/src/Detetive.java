/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
import java.util.Scanner;

public class Detetive {
    
public static int question(String j){
    Scanner teclado = new Scanner(System.in);
    String resp;
    System.out.println(j);
    resp = teclado.nextLine();
    while((!"sim".equals(resp)) && (!"nao".equals(resp))){
        System.out.println("Resposta inválida, digite sim ou nao");
        resp = teclado.nextLine();
    }
    if("sim".equals(resp) ){
        return 1;
    }else{
        return 0;
    }
}
    public static void main(String[] args) {
        int cont=0;
    
        cont = question("Telefonou para a vítima?");
        cont += question("Esteve no local do crime?");
        cont += question("Mora perto da vítima?");
        cont += question("Devia para a vítima?");
        cont += question("Já trabalhou com a vítima?");
    
        if(cont == 2){
            System.out.println("Suspeita");
        }else if(cont == 3 || cont == 4){
            System.out.println("Cúmplice");
        }else if(cont == 5){
            System.out.println("Assasino");
        }else{
            System.out.println("Inocente");
        }
    }
}
