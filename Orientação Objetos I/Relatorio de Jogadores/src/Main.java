/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.ArrayList;
import java.util.TreeSet;
/**
 *
 * @author Pedro Grazziani
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Time t = new Time();
        Jogador j1 = new Jogador();
        Titulo t1 = new Titulo();
        Tecnico tec1 = new Tecnico();
    /*
    private String nome;
    private String matricula;
    private double salarioBase;
    private String posicao;
    private double bonificacao;
    private double gratificacao;
    private double peso;
    private double altura;*/

        t.setNome("Grêmio Foot-Baal Portoalegrense");
        j1.setAltura(1.80);
        j1.setBonificacao(500);
        j1.setGratificacao(500);
        j1.setMatricula("0005");
        j1.setNome("Marcelo");
        j1.setPeso(80);
        j1.setPosicao("Goleiro");
        j1.setSalarioBase(25000);
        t.setJogadores(j1);
        t1.setAnoTitutlo(1991);
        t1.setDescricao("Ganhou uma abraço");
        t.setTitulos(t1);
        tec1.setMatricula("1234");
        tec1.setNome("Viroloco");
        tec1.setSalarioBase(50000);
        tec1.setQtdTitulos(10);
        t.setTecnico(tec1);
        
        t.exibeRelatorioCadastral();
    }
}
