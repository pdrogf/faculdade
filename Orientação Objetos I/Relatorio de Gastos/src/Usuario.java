
import java.util.TreeMap;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Pedro Grazziani
 */
public class Usuario implements ICalcula,IExibido{
    private String nome;
    private String celular;
    private String email;
    TreeMap<String, Double> gastosMes = new TreeMap<>();
    private double total;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCelular() {
        return celular;
    }

    public void setCelular(String celular) {
        this.celular = celular;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    @Override
    public void incluirGasto(Gasto gasto) {
        gastosMes.put(gasto.getDescricao(), gasto.getValor());
        total +=gasto.getValor();
    }

    @Override
    public void exibeRelatorio() {
        for(String n : gastosMes.keySet()){
            System.out.println(gastosMes.getOrDefault(n, total));
        }
    }
    
    
}
