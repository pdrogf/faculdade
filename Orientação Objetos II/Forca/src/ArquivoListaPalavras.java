
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class ArquivoListaPalavras {
    
    public void criaArquivo(){ 
        
        try {
            FileWriter arq = new FileWriter("ListaPalavras.txt");
            PrintWriter escreve = new PrintWriter(arq);
            escreve.print("Abagualado|o cara\n" +
"Abostado|abobado, burro\n" +
"Ala-putcha-tche|interjeição de surpresa.\n" +
"Arrancar-se|sair logo, rapidamente. \n" +
"Arrecem|há pouco\n" +
"Arreganho|brincadeira\n" +
"Arriado|debochado, fazer deboche\n" +
"Atucanado|preocupado\n" +
"Bagual|homem, o cara\n" +
"Bah|Interjeição que vale para quase tudo, dependendo da entonação, pode ser usado como surpresa, rejeição, aprovação, admiração. \n" +
"Baixado|doente, derrubado, acamado \n" +
"Balaca|enfeite\n" +
"Balaqueiro|enfeitado \n" +
"Barbaridade|pode ser tanto um adjetivo, quanto uma interjeição de espanto \n" +
"Bergamota|tangerina, mexerica \n" +
"Bombear|Observar\n" +
"Bucha|difícil \n" +
"Cacetinho|Pão francês\n" +
"Cagaco|susto, medo \n" +
"Caiu os butia do bolso|expressão de surpresa \n" +
"Campeando|procurando \n" +
"Capaz|imagina\n" +
"Chinaredo|casa de prostituição\n" +
"Chinelear|humilhar \n" +
"Chinoca|mulher\n" +
"Churras|Churrasco\n" +
"Cusco|Cachorro\n" +
"Dar um laco|enrolar, bater em alguém\n" +
"Dar uma banda|dar uma volta\n" +
"Deitar o cabelo|fugir, sair, ir embora \n" +
"Despacito|devagar\n" +
"Em cima do laco|Com pressa, apressado, com pouco tempo\n" +
"Entrevero|briga generalizada. Também é um prato típico\n" +
"Espraiar|se jogar, espalhar\n" +
"Faixa|estrada, asfalto\n" +
"Farroupilha|misto com pão francês\n" +
"Fatiota|bem vestido, paletó, terno\n" +
"Ficar de cara|Aborrecido\n" +
"Fresquear|ficar de frescura\n" +
"Frio de renguear cusco|muito frio\n" +
"Gauderiar|adotar o estilo gaudério ou gaúcho.\n" +
"Gringo|Como são chamados os descendentes de italianos \n" +
"Grossura|Grosseria \n" +
"Guaiaca|Cinto com bolsos feito de couro usado na indumentária gaúcha \n" +
"Guaipeca|Cachorro\n" +
"Guampa|chifre, corno\n" +
"Guapo|Forte, bonito\n" +
"Guasca|Esperto\n" +
"Guaiba|Lago que é chamado de rio \n" +
"Guria|menina\n" +
"Guri|Menino\n" +
"Indiada|vários homens ou situação ruim\n" +
"Lomba|Ladeira\n" +
"Labia|papo, conversa\n" +
"Magrao|rapaz \n" +
"Mate|Chimarrão (espécie de chá feito com erva mate e consumido tanto durante o inverno, quanto sob sol escaldante no verão)\n" +
"Merca|meninas, oriundo de dialeto de Livramento, na fronteira \n" +
"Minuano|Vento comum nos meses de inverno\n" +
"Mongolao|abobado, burro \n" +
"Mosquear|distrair\n" +
"Naco|pedaço\n" +
"Negacear|Espreitar\n" +
"Negrinho|brigadeiro\n" +
"No nas tripas|cólicas estomacais\n" +
"Oigale|expressão de espanto, alegria\n" +
"Pago|lugar\n" +
"Paleta|Costela\n" +
"Pandorga|pipa, confusão\n" +
"Patrao|Chefe, está podendo.\n" +
"Pechada|batida, acidente\n" +
"Peleia|Briga, disputa\n" +
"Pila|moeda virtual local\n" +
"Pilcha|indumentária típica completa do gaúcho\n" +
"Pia|menino\n" +
"Prenda|mulher\n" +
"Profe|professora \n" +
"Quebra-mola|lombada\n" +
"Querencia|Terra natal\n" +
"Refri|Refrigerante\n" +
"Relho|Chicote\n" +
"Rincao|área de campo, recanto\n" +
"Se arriar|tirar sarro, fazer graça\n" +
"Sinaleira|farol, sinal, semáforo\n" +
"Super|Supermercado\n" +
"Surra de relho|apanhar\n" +
"Taipa|burro, incapaz\n" +
"Talagaco|De uma vez só.\n" +
"Torrada|misto quente\n" +
"Tramposo|Mentiroso\n" +
"Tri|prefixo que pode ser usado para quase tudo e tem o mesmo significado de muito \n" +
"Trovador|Mentiroso\n" +
"Vareio|surra, vencer com vantagem\n" +
"Vazio|Peça de carne conhecida como Fraldinha em outras regiões\n" +
"Vianda|Marmita\n" +
"Vivente|Pessoa\n" +
"Xis|Sanduiche, uma variação mais reforçada do hambúrguer.");   
            arq.close();
        } catch (Exception e) {
            System.out.println("Erro ao criar o arquivo, encerrando sistema");
            System.exit(1);
        }       
    }
    
}
