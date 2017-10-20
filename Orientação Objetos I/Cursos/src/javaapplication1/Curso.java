/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

/**
 *
 * @author Pedro Grazziani
 */
public class Curso {
    private int numero;
    private String nome;
    private Professor professor;

    public Professor getProfessor() {
        return professor;
    }

    public void setProfessor(Professor professor) {
        this.professor = professor;
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void exibeDados(){
        System.out.println("Número do curso: " + numero);
        System.out.println("Nome do curso: " + nome);
        System.out.println("Nome do professor: " + professor.getNome());
    }
}
