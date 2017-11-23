package br.edu.ulbra.gestaovinhos.controller;

import br.edu.ulbra.gestaovinhos.input.UserInput;
import br.edu.ulbra.gestaovinhos.model.User;
import br.edu.ulbra.gestaovinhos.repository.UserRepository;
import org.modelmapper.ModelMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

@Controller
@RequestMapping("/usuario")
public class UserController {
	@Autowired
	UserRepository userRepository;

	private ModelMapper mapper = new ModelMapper();

	@GetMapping("/novo")
	public ModelAndView newUserForm(@ModelAttribute("user") UserInput user){
		ModelAndView mv = new ModelAndView("user/new");
		mv.addObject("user", user);
		return mv;
	}

	@PostMapping("/novo")
	public String newUser(UserInput userInput, RedirectAttributes redirectAttrs){
		User usuario = userRepository.findByUsername(userInput.getUsername());

		if (usuario != null) {
			redirectAttrs.addFlashAttribute("error", "Email já cadastrado.");
			redirectAttrs.addFlashAttribute("user", userInput);
			return "redirect:/usuario/novo";
		}

		if (userInput.getPassword().length() == 0) {
			redirectAttrs.addFlashAttribute("error", "Informe a senha.");
			redirectAttrs.addFlashAttribute("user", userInput);
			return "redirect:/admin/usuario/novo";
		}

		if (!userInput.getPassword().equals(userInput.getPasswordConfirm())) {
			redirectAttrs.addFlashAttribute("error", "Senhas não conferem.");
			redirectAttrs.addFlashAttribute("user", userInput);
			return "redirect:/usuario/novo";
		}

		User user = mapper.map(userInput, User.class);
		userRepository.save(user);

		redirectAttrs.addFlashAttribute("success", "Cadastradp com sucesso, realize login.");
		return "redirect:/";
	}
}
