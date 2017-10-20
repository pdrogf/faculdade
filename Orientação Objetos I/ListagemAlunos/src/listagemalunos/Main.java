/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package listagemalunos;

/**
 *
 * @author pedro.grazziani
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Cria um Objeto do tipo Turma
        Turma turma = new Turma();

        // Cria 5 objetos do tipo Aluno
        Aluno aluno1 = new Aluno("Tales", 1);
        Aluno aluno2 = new Aluno("Alessandro", 2);
        Aluno aluno3 = new Aluno("Diego", 3);
        Aluno aluno4 = new Aluno("Fernando", 4);
        Aluno aluno5 = new Aluno("Marli", 5);

        // Define o nome da disciplina
        turma.setNomeDisciplina("Logica e Algoritmos de Programacao");
        turma.setNumero(10);
        // Adiciona os alunos na turma
        turma.adicionaAluno(aluno1);
        turma.adicionaAluno(aluno2);
        turma.adicionaAluno(aluno3);
        turma.adicionaAluno(aluno4);
        turma.adicionaAluno(aluno5);

        // Listagem dos alunos da turma
        turma.listaAlunos();
    }

}
