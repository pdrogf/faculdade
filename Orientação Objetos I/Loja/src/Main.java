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
        
        Livro livro1 = new Livro("Java I", 150, "Magaiver");
        Livro livro2 = new Livro("Java II", 200, "Helio dos passos");
        Cd cd = new Cd("Linkin Park", 10, 12);
        Dvd dvd1 = new Dvd("Galinha Pintadinha VII", 15, 180);
        Dvd dvd2 = new Dvd("Sr dos Anéis", 15, 180);

        System.out.println(livro1.toString());
        System.out.println(livro2.toString());
        System.out.println(cd.toString());
        System.out.println(dvd1.toString());
        System.out.println(dvd2.toString());
    }
}
