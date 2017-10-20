
import java.util.ArrayList;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Turma {
    private String NomeDisciplina;
    private int numero;
    ArrayList<Aluno> alunos = new ArrayList<>();

    public Turma() {
    
    }

    
    public String getNomeDisciplina() {
        return NomeDisciplina;
    }

    public void setNomeDisciplina(String nome) {
        this.NomeDisciplina = nome;
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }
    
    public void adicionaAluno(Aluno a){
        alunos.add(a);        
    }
    public void listaAlunos(){
        System.out.println("Nome da discipla: "+ getNomeDisciplina());
        System.out.println("Número da turma: "+ getNumero());
        for(Aluno a : alunos){
            System.out.println("Nome aluno: " + a.getNome());
            System.out.println("Número aluno: " + a.getNumero());
        }
    }
   
}
