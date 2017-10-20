
import java.util.ArrayList;
import java.util.TreeSet;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Pedro Grazziani
 */
public class Time implements IExibicao{
    private String nome;
    ArrayList<Jogador> jogadores = new ArrayList<>();
    TreeSet<Titulo> titulos = new TreeSet<>();
    Tecnico tecnico = new Tecnico();

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public ArrayList<Jogador> getJogadores() {
        return jogadores;
    }

    public void setJogadores(Jogador jogador) {
        jogadores.add(jogador);
    }

    public TreeSet<Titulo> getTitulos() {
        return titulos;
    }

    public void setTitulos(Titulo t) {
        titulos.add(t);
    }

    public Tecnico getTecnico() {
        return tecnico;
    }

    public void setTecnico(Tecnico tecnico) {
        this.tecnico = tecnico;
    }
    
    @Override
    public void exibeRelatorioCadastral(){
        System.out.println("Nome: " + getNome());
        System.out.println("Jogadores: \n");
        for(Jogador j:jogadores){
            System.out.println("- "+j.getMatricula()+" - "+j.getNome()+" ("+j.getPosicao()+")");
            System.out.println("Salário = "+j.calculaSalario());
            System.out.println("Salário Base: "+j.getSalarioBase());
            System.out.println("Bonificação: "+j.getBonificacao());
            System.out.println("Gratificação: "+j.getGratificacao());
            System.out.println("IMC = "+j.calculaIMC());
            System.out.println("Peso: "+j.getPeso());
            System.out.println("Altura: "+j.getAltura());
        }
        System.out.println("Matrícula Técnico: "+tecnico.getMatricula());
        System.out.println("Nome do Técnico: "+tecnico.getNome());
        System.out.println("Salário: "+tecnico.calculaSalario());
        System.out.println("Salário Base: "+tecnico.getSalarioBase());
        System.out.println("Quantidade de títulos: "+tecnico.getQtdTitulos());
        
        System.out.println("Títulos: ");
        for(Titulo t:titulos){
            System.out.println(t.getAnoTitutlo());
            System.out.print(": "+t.getDescricao());
        }
    }
    
    
}
