/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pedro.grazziani
 */
public class Operacoes {
    
    
    public void emprestaLivro(String titulo, String autor, String isbn, String usuario){
        Livro l = new Livro();
        
        l.setAutor(autor);
        l.setEmprestado(true);
        l.setIsbn(isbn);
        l.setTitulo(titulo);
        l.setUsuario(usuario);
    }
}
