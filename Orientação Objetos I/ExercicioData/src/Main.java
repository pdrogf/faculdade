/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Main {
    public static void main(String[] args) {
        Data data1 = new Data();
        Data data2 = new Data();
        Data data3 = new Data();
        
        data1.setDia(01);
        data1.setMes(01);
        data1.setAno(1991);
        
        data2.setDia(01);
        data2.setMes(01);
        data2.setAno(1991);
        
        data3.setDia(01);
        data3.setMes(01);
        data3.setAno(1991);
        
        System.out.println(data1.mostrarData()); 
        System.out.println(data2.mostrarData()); 
        System.out.println(data3.mostrarData()); 
    }
}
