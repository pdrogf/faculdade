
import java.util.ArrayList;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Pedro
 */
public class ThreadNoticia extends Thread {

    ArrayList<String> noticias = new ArrayList<String>() {
        {
            add("Bla bla batatinha");
            add("Dorgas legalizadas");
            add("A mascada gloriosa");
            add("A volta dos que não foram");
            add("Zerando a vida 123");
            add("Star Wars I");
            add("Velozes e furiosos 18");
            add("Parangaricomicotiruar");
            add("Pneumoltramicroscopicasilivulcanicacaniotica");
            add("Dormir ou fazer os trabalhos, eis a questão");
        }
    };

    @Override
    public void run() {

        while (true) {
            for (String noticia : noticias) {
                try {
                    sleep(5000);
                } catch (InterruptedException ie) {
                }

                System.out.println(noticia);
            }
        }
    }
}
