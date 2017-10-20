/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Assalariado extends  Trabalhador{
	public Assalariado(String nome, double salarioPorHora) {
		super(nome, salarioPorHora);
	}

	public double calculaPagamento() {
		return super.getSalarioHora() * 250;
	}
}