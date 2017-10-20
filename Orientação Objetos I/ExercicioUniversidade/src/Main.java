
import java.util.ArrayList;
import java.util.Scanner;

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

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
                
        Aluno al1 = new Aluno();
        Endereco endR1 = new Endereco();
        Endereco endC1 = new Endereco();
        
        Aluno al2 = new Aluno();
        Endereco endR2 = new Endereco();
        Endereco endC2 = new Endereco();
        
        Aluno al3 = new Aluno();
        Endereco endR3 = new Endereco();
        Endereco endC3 = new Endereco();
        
        //Aluno1
        System.out.println("Digite o nome do aluno: ");
        al1.setNome(teclado.nextLine());
        System.out.println("Digite o número de matrícula: ");
        al1.setnMatricula(teclado.nextInt());
        
        System.out.println("Digite o endereço residencial.");
        
        System.out.println("Nome da rua: ");
        endR1.setRua(teclado.nextLine());
        System.out.println("Número: ");
        endR1.setNumero(teclado.nextInt());
        System.out.println("Complemento: ");
        endR1.setComplemento(teclado.nextLine());
        System.out.println("Bairro: ");
        endR1.setBairro(teclado.nextLine());
        System.out.println("CEP: ");
        endR1.setCep(teclado.nextLine());
        System.out.println("Cidade: ");
        endR1.setCidade(teclado.nextLine());
        
        System.out.println("Digite o endereço comercial.");
        
        System.out.println("Nome da rua: ");
        endR1.setRua(teclado.nextLine());
        System.out.println("Número: ");
        endR1.setNumero(teclado.nextInt());
        System.out.println("Complemento: ");
        endR1.setComplemento(teclado.nextLine());
        System.out.println("Bairro: ");
        endR1.setBairro(teclado.nextLine());
        System.out.println("CEP: ");
        endR1.setCep(teclado.nextLine());
        System.out.println("Cidade: ");
        endR1.setCidade(teclado.nextLine());
        
        //Aluno2
        System.out.println("Digite o nome do aluno: ");
        al2.setNome(teclado.nextLine());
        System.out.println("Digite o número de matrícula: ");
        al2.setnMatricula(teclado.nextInt());
        
        System.out.println("Digite o endereço residencial.");
        System.out.println("Nome da rua: ");
        endR2.setRua(teclado.nextLine());
        System.out.println("Número: ");
        endR2.setNumero(teclado.nextInt());
        System.out.println("Complemento: ");
        endR2.setComplemento(teclado.nextLine());
        System.out.println("Bairro: ");
        endR2.setBairro(teclado.nextLine());
        System.out.println("CEP: ");
        endR2.setCep(teclado.nextLine());
        System.out.println("Cidade: ");
        endR2.setCidade(teclado.nextLine());
        
        System.out.println("Digite o endereço comercial.");
        System.out.println("Nome da rua: ");
        endR2.setRua(teclado.nextLine());
        System.out.println("Número: ");
        endR2.setNumero(teclado.nextInt());
        System.out.println("Complemento: ");
        endR2.setComplemento(teclado.nextLine());
        System.out.println("Bairro: ");
        endR2.setBairro(teclado.nextLine());
        System.out.println("CEP: ");
        endR2.setCep(teclado.nextLine());
        System.out.println("Cidade: ");
        endR2.setCidade(teclado.nextLine());
        //Aluno3
        System.out.println("Digite o nome do aluno: ");
        al3.setNome(teclado.nextLine());
        System.out.println("Digite o número de matrícula: ");
        al3.setnMatricula(teclado.nextInt());
        
        System.out.println("Digite o endereço residencial.");
        System.out.println("Nome da rua: ");
        endR3.setRua(teclado.nextLine());
        System.out.println("Número: ");
        endR3.setNumero(teclado.nextInt());
        System.out.println("Complemento: ");
        endR3.setComplemento(teclado.nextLine());
        System.out.println("Bairro: ");
        endR3.setBairro(teclado.nextLine());
        System.out.println("CEP: ");
        endR3.setCep(teclado.nextLine());
        System.out.println("Cidade: ");
        endR3.setCidade(teclado.nextLine());
        
        System.out.println("Digite o endereço comercial.");
        System.out.println("Nome da rua: ");
        endR3.setRua(teclado.nextLine());
        System.out.println("Número: ");
        endR3.setNumero(teclado.nextInt());
        System.out.println("Complemento: ");
        endR3.setComplemento(teclado.nextLine());
        System.out.println("Bairro: ");
        endR3.setBairro(teclado.nextLine());
        System.out.println("CEP: ");
        endR3.setCep(teclado.nextLine());
        System.out.println("Cidade: ");
        endR3.setCidade(teclado.nextLine());
        
        System.out.println("Nome: " + al1.getNome());
        System.out.println("Matricula : " + al1.getnMatricula());
        
        System.out.println("Endereço Residencial ");
        System.out.println("Rua: " + endR1.getRua());
        System.out.println("Número: " + endR1.getNumero());
        System.out.println("Complemento: " + endR1.getComplemento());
        System.out.println("Bairro: " + endR1.getBairro());
        System.out.println("Cep: " + endR1.getCep());
        System.out.println("Cidade: " + endR1.getCidade());
        
        System.out.println("Endereço Comercial ");
        System.out.println("Rua: " + endC1.getRua());
        System.out.println("Número: " + endC1.getNumero());
        System.out.println("Complemento: " + endC1.getComplemento());
        System.out.println("Bairro: " + endC1.getBairro());
        System.out.println("Cep: " + endC1.getCep());
        System.out.println("Cidade: " + endC1.getCidade());        
        
        //print Aluno2
        System.out.println("Nome: " + al2.getNome());
        System.out.println("Matricula : " + al2.getnMatricula());
        
        System.out.println("Endereço Residencial ");
        System.out.println("Rua: " + endR2.getRua());
        System.out.println("Número: " + endR2.getNumero());
        System.out.println("Complemento: " + endR2.getComplemento());
        System.out.println("Bairro: " + endR2.getBairro());
        System.out.println("Cep: " + endR2.getCep());
        System.out.println("Cidade: " + endR2.getCidade());
        
        System.out.println("Endereço Comercial ");
        System.out.println("Rua: " + endC2.getRua());
        System.out.println("Número: " + endC2.getNumero());
        System.out.println("Complemento: " + endC2.getComplemento());
        System.out.println("Bairro: " + endC2.getBairro());
        System.out.println("Cep: " + endC2.getCep());
        System.out.println("Cidade: " + endC2.getCidade());
        //print Aluno3
        System.out.println("Nome: " + al3.getNome());
        System.out.println("Matricula : " + al3.getnMatricula());
        
        System.out.println("Endereço Residencial ");
        System.out.println("Rua: " + endR3.getRua());
        System.out.println("Número: " + endR3.getNumero());
        System.out.println("Complemento: " + endR3.getComplemento());
        System.out.println("Bairro: " + endR3.getBairro());
        System.out.println("Cep: " + endR3.getCep());
        System.out.println("Cidade: " + endR3.getCidade());
        
        System.out.println("Endereço Comercial ");
        System.out.println("Rua: " + endC3.getRua());
        System.out.println("Número: " + endC3.getNumero());
        System.out.println("Complemento: " + endC3.getComplemento());
        System.out.println("Bairro: " + endC3.getBairro());
        System.out.println("Cep: " + endC3.getCep());
        System.out.println("Cidade: " + endC3.getCidade());
    }
}
