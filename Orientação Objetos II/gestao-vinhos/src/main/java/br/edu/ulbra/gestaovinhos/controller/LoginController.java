package br.edu.ulbra.gestaovinhos.controller;

import br.edu.ulbra.gestaovinhos.general.SessionHandler;
import br.edu.ulbra.gestaovinhos.input.UserInput;
import br.edu.ulbra.gestaovinhos.model.User;
import br.edu.ulbra.gestaovinhos.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import javax.servlet.http.HttpSession;

@Controller
public class LoginController {
	@Autowired
	UserRepository userRepository;

	@PostMapping("/login")
	public String login (UserInput userInput, RedirectAttributes redirectAttrs) {
		User usuario = userRepository.findByUsername(userInput.getUsername());

		if (usuario != null) {
			if (usuario.getPassword().equals(userInput.getPassword())) {
				if (usuario.isAdmin()) {}

				SessionHandler.setUserSession(usuario);
				return "redirect:/inicio";
			} else {
				redirectAttrs.addFlashAttribute("error", "Senha inválida.");
			}
		} else {
			redirectAttrs.addFlashAttribute("error", "Usuário inexistente.");
		}

		return "redirect:/";
	}
}
