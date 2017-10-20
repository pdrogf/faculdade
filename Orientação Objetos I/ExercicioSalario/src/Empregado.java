/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Empregado {
    private String nome;
    private double salario;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        if(salario < 0){
            this.salario = 0;
        }else{
            this.salario = salario;
        }        
    }
    public double aumentaSalario(double percentual){
        if(percentual < 0){
            System.out.println("Percentual de aumento inválido!");
        }
        salario += salario * (percentual/100);
        return  salario;
    }
}
