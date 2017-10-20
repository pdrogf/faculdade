import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
 
public class Main {
 
  public static void main(String[] args) {
    Scanner ler = new Scanner(System.in);
    int a=0,e=0,i=0,o=0,u=0;
 
    System.out.printf("Informe o nome de arquivo texto:\n");
    String nome = ler.nextLine();
    try {
      FileReader arq = new FileReader(nome);
      BufferedReader lerArq = new BufferedReader(arq);
 
      String linha = lerArq.readLine();
      
      while (linha != null) { 
        linha = lerArq.readLine(); // lê da segunda até a última linha
        for (int j=0; j<linha.length(); j++) {
        char c = linha.charAt(j);
        if(c =='a'){
            a++;
        }
        if(c =='e'){
            e++;
        }
        if(c =='i'){
            i++;
        }
        if(c =='o'){
           o++; 
        }
        if(c =='u'){
           u++; 
        }
      }
        System.out.println("A: "+a + " E:"+e + " I:"+i+" O:"+o+" U"+u);
    }
 
      arq.close();
    } catch (IOException error) {
        System.err.printf("Erro na abertura do arquivo: %s.\n",
          error.getMessage());
    } 
    
  }
}