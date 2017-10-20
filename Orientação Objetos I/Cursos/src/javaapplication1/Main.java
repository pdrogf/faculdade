/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.util.ArrayList;

/**
 *
 * @author Pedro Grazziani
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Professor professor1 = new Professor();
        Professor professor2 = new Professor();
        Curso c1 = new Curso();
        Curso c2 = new Curso();
        Curso c3 = new Curso();

        professor1.setNumero(1);
        professor1.setNome("Joao");
        professor2.setNumero(2);
        professor2.setNome("Joana");

        c1.setNumero(123);
        c1.setNome("OOI");
        c1.setProfessor(professor1);
        c2.setNumero(1234);
        c2.setNome("ARQI");
        c2.setProfessor(professor2);
        c3.setNumero(12345);
        c3.setNome("FORMAIS");
        c3.setProfessor(professor2);

        c1.exibeDados();
        System.out.println(" ");
        c2.exibeDados();
        System.out.println(" ");
        c3.exibeDados();
    }
}
