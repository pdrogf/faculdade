/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Horista extends  Trabalhador {
	private double horasTrabalhadas;

	public Horista(String nome, double salarioPorHora, double horasTrabalhadas) {
		super(nome, salarioPorHora);
		this.horasTrabalhadas = horasTrabalhadas;
	}

	public double calculaPagamento() {
		return super.getSalarioHora() * horasTrabalhadas;
	}

	public double getHorasTrabalhadas() {
		return horasTrabalhadas;
	}

	public void setHorasTrabalhadas(double horasTrabalhadas) {
		this.horasTrabalhadas = horasTrabalhadas;
	}
}
