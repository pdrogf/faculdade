package br.edu.ulbra.gestaovinhos.controller;
import br.edu.ulbra.gestaovinhos.general.SessionHandler;
import br.edu.ulbra.gestaovinhos.input.UserInput;
import br.edu.ulbra.gestaovinhos.model.User;
import br.edu.ulbra.gestaovinhos.repository.UserRepository;
import org.modelmapper.ModelMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import java.util.List;

@Controller
@RequestMapping("/admin/usuario")
public class AdminUserController {
	@Autowired
	UserRepository userRepository;

	private ModelMapper mapper = new ModelMapper();

	@RequestMapping()
	public ModelAndView listaUsuarios(RedirectAttributes redirectAttrs) {
		if (!SessionHandler.isUserLogged()) {
			redirectAttrs.addFlashAttribute("error", "Usuário não é administrador.");
			return new ModelAndView("redirect:/admin");
		}

		if (!SessionHandler.getUserSession().isAdmin()) {
			redirectAttrs.addFlashAttribute("error", "Usuário não é administrador.");
			return new ModelAndView("redirect:/admin");
		}

		ModelAndView mv = new ModelAndView("admin/usuario/lista");
		mv.addObject("userLogged", SessionHandler.getUserSession());
		mv.addObject("admin", true);
		List<User> usuarios = (List<User>) userRepository.findAll();
		mv.addObject("users", usuarios);
		return mv;
	}

	@GetMapping("/novo")
	public ModelAndView novoUsuarioForm(@ModelAttribute("user") UserInput user, RedirectAttributes redirectAttrs){
		if (!SessionHandler.isUserLogged()) {
			redirectAttrs.addFlashAttribute("error", "Usuário não é administrador.");
			return new ModelAndView("redirect:/admin");
		}

		if (!SessionHandler.getUserSession().isAdmin()) {
			redirectAttrs.addFlashAttribute("error", "Usuário não é administrador.");
			return new ModelAndView("redirect:/admin");
		}

		ModelAndView mv = new ModelAndView("admin/usuario/novo");
		mv.addObject("userLogged", SessionHandler.getUserSession());
		mv.addObject("admin", true);
		mv.addObject("user", user);
		return mv;
	}

	@PostMapping("/novo")
	public String novoUsuario(UserInput userInput, RedirectAttributes redirectAttrs){
		if (!SessionHandler.isUserLogged()) {
			redirectAttrs.addFlashAttribute("error", "Usuário não é administrador.");
			return "redirect:/admin";
		}

		if (!SessionHandler.getUserSession().isAdmin()) {
			redirectAttrs.addFlashAttribute("error", "Usuário não é administrador.");
			return "redirect:/admin";
		}

		User usuario = userRepository.findByUsername(userInput.getUsername());

		if (usuario != null) {
			redirectAttrs.addFlashAttribute("error", "Usuário já cadastrado");
			redirectAttrs.addFlashAttribute("user", userInput);
			return "redirect:/admin/usuario/novo";
		}

		if (userInput.getPassword().length() == 0) {
			redirectAttrs.addFlashAttribute("error", "Informe a senha");
			redirectAttrs.addFlashAttribute("user", userInput);
			return "redirect:/admin/usuario/novo";
		}

		if (!userInput.getPassword().equals(userInput.getPasswordConfirm())) {
			redirectAttrs.addFlashAttribute("error", "Senhas não conferem.");
			redirectAttrs.addFlashAttribute("user", userInput);
			return "redirect:/admin/usuario/novo";
		}

		User user = mapper.map(userInput, User.class);
		userRepository.save(user);

		redirectAttrs.addFlashAttribute("success", "Cadastrado com sucesso.");
		return "redirect:/admin/usuario";
	}

	@GetMapping("/{id}")
	public ModelAndView detalheUsuario(@PathVariable("id") Long idUsuario, RedirectAttributes redirectAttrs){
		if (!SessionHandler.isUserLogged()) {
			redirectAttrs.addFlashAttribute("error", "Usuário não é administrador.");
			return new ModelAndView("redirect:/admin");
		}

		if (!SessionHandler.getUserSession().isAdmin()) {
			redirectAttrs.addFlashAttribute("error", "Usuário não é administrador.");
			return new ModelAndView("redirect:/admin");
		}

		User usuario = userRepository.findOne(idUsuario);

		if (usuario == null) {
			redirectAttrs.addFlashAttribute("error", "Usuário inexistente");
			return new ModelAndView("redirect:/admin/usuario");
		}

		UserInput userInput = mapper.map(usuario, UserInput.class);

		ModelAndView mv = new ModelAndView("admin/usuario/detalhe");
		mv.addObject("userLogged", SessionHandler.getUserSession());
		mv.addObject("admin", true);
		mv.addObject("user", userInput);
		return mv;
	}

	@PostMapping("/{id}")
	public String salvarUsuario(@PathVariable("id") Long idUsuario, UserInput userInput, RedirectAttributes redirectAttrs) {
		if (!SessionHandler.isUserLogged()) {
			redirectAttrs.addFlashAttribute("error", "Usuário não é administrador.");
			return "redirect:/admin";
		}

		if (!SessionHandler.getUserSession().isAdmin()) {
			redirectAttrs.addFlashAttribute("error", "Usuário não é administrador.");
			return "redirect:/admin";
		}

		User usuario = userRepository.findOne(idUsuario);

		if (usuario == null) {
			redirectAttrs.addFlashAttribute("error", "Usuário inexistente.");
			redirectAttrs.addFlashAttribute("user", userInput);
			return "redirect:/admin/usuario/" + idUsuario;
		}

		User usuarioTest = userRepository.findByUsername(userInput.getUsername());
		if (usuarioTest != null && !usuario.getUsername().equals(usuarioTest.getUsername())) {
			redirectAttrs.addFlashAttribute("error", "Email já utilizado");
			redirectAttrs.addFlashAttribute("user", userInput);
			return "redirect:/admin/usuario/" + idUsuario;
		}

		if (userInput.getPassword().length() == 0) {
			redirectAttrs.addFlashAttribute("error", "Informe a senha.");
			redirectAttrs.addFlashAttribute("user", userInput);
			return "redirect:/admin/usuario/" + idUsuario;
		}

		if (!userInput.getPassword().equals(userInput.getPasswordConfirm())) {
			redirectAttrs.addFlashAttribute("error", "Senhas não conferem.");
			redirectAttrs.addFlashAttribute("user", userInput);
			return "redirect:/admin/usuario/" + idUsuario;
		}

		usuario.setName(userInput.getName());
		usuario.setUsername(userInput.getUsername());
		usuario.setPassword(userInput.getPassword());

		userRepository.save(usuario);

		redirectAttrs.addFlashAttribute("success", "Cadastro alterado com sucesso.");
		redirectAttrs.addFlashAttribute("user", userInput);
		return "redirect:/admin/usuario/" + idUsuario;
	}

	@PostMapping("/{id}/resetSenha")
	public String resetarSenhaUsuario(@PathVariable("id") Long idUsuario){
		return "redirect:/admin/usuario/" + idUsuario;
	}

	@RequestMapping("/{id}/delete")
	public String deletarUsuario(@PathVariable("id") Long idUsuario, RedirectAttributes redirectAttrs) {
		if (!SessionHandler.isUserLogged()) {
			redirectAttrs.addFlashAttribute("error", "Usuário não é administrador.");
			return "redirect:/admin";
		}

		if (!SessionHandler.getUserSession().isAdmin()) {
			redirectAttrs.addFlashAttribute("error", "Usuário não é administrador.");
			return "redirect:/admin";
		}

		User usuario = userRepository.findOne(idUsuario);
		if (usuario == null) {
			redirectAttrs.addFlashAttribute("error", "Usuário inexistente.");
		} else {
			userRepository.delete(usuario);
			redirectAttrs.addFlashAttribute("success", "Cadastro deletado com sucesso.");
		}

		return "redirect:/admin/usuario";
	}
}
