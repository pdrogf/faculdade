/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class FabricaLampadas {
    
    public Object criaLampada(String tipo){
        if(tipo == "L"){
            Led lampada = new Led();
            return lampada;
        }else if(tipo == "F"){
            Fluorescente lampada = new Fluorescente();
            return lampada;
        }else{
            return null;
        }
    }
}
