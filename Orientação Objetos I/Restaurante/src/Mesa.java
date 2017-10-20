
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
public class Mesa {
    private int numero;
    private String cliente;
    public ArrayList<Pedido> listaMesa = new ArrayList<>();

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public String getCliente() {
        return cliente;
    }

    public void setCliente(String cliente) {
        this.cliente = cliente;
    }

    public ArrayList<Pedido> getListaMesa() {
        return listaMesa;
    }

    public void setListaMesa(ArrayList<Pedido> listaMesa) {
        this.listaMesa = listaMesa;
    }
    
    public void adicionaPedido(Pedido pedido){
        listaMesa.add(pedido);
    }
        
}
