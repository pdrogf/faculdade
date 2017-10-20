/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package listagemalunos;

import java.util.ArrayList;

/**
 *
 * @author pedro.grazziani
 */
public class Turma {
    private String nomeDisciplina;
    private int numero;
    public ArrayList<Aluno> listaAlunos = new ArrayList<>();

    public String getNomeDisciplina() {
        return nomeDisciplina;
    }

    public void setNomeDisciplina(String nomeDisciplina) {
        this.nomeDisciplina = nomeDisciplina;
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }
    
    public void adicionaAluno(Aluno aluno){
        listaAlunos.add(aluno);
    }
    
    public void listaAlunos(){
        System.out.println(getNomeDisciplina()+ " - " +getNumero());
        for(int i=0; i<listaAlunos.size(); i++){
            System.out.println(listaAlunos.get(i).getNome() + " - " + listaAlunos.get(i).getNumero());
        }
    }
    
}
