package br.edu.ulbra.gestaovinhos.controller;

import br.edu.ulbra.gestaovinhos.general.SessionHandler;
import br.edu.ulbra.gestaovinhos.input.UserInput;
import br.edu.ulbra.gestaovinhos.model.User;
import br.edu.ulbra.gestaovinhos.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.context.request.RequestContextHolder;
import org.springframework.web.context.request.ServletRequestAttributes;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import javax.servlet.http.HttpSession;

@Controller
@RequestMapping("/admin")
public class AdminIndexController {
	@Autowired
	UserRepository userRepository;

	@RequestMapping()
	public String index(){
		if (SessionHandler.isUserLogged()) {
			return "redirect:/admin/inicio";
		}

		return "admin/index";
	}

	@PostMapping("/login")
	public String login(UserInput userInput, RedirectAttributes redirectAttrs){
		User usuario = userRepository.findByUsername(userInput.getUsername());

		if (usuario != null) {
			if (usuario.getPassword().equals(userInput.getPassword())) {
				if (usuario.isAdmin())
				{
					ServletRequestAttributes attr = (ServletRequestAttributes) RequestContextHolder.currentRequestAttributes();
					HttpSession session = attr.getRequest().getSession();
					session.setAttribute("user", usuario);

					return "redirect:/admin/inicio";
				}

				redirectAttrs.addFlashAttribute("error", "Usuário não é administrador.");
			} else {
				redirectAttrs.addFlashAttribute("error", "Senha inválida.");
			}
		} else {
			redirectAttrs.addFlashAttribute("error", "Usuário inexistente.");
		}

		return "redirect:/admin";
	}

	@RequestMapping("/inicio")
	public ModelAndView home(RedirectAttributes redirectAttrs){
		if (!SessionHandler.isUserLogged()) {
			redirectAttrs.addFlashAttribute("error", "Usuário não é administrador.");
			return new ModelAndView("redirect:/admin");
		}

		if (!SessionHandler.getUserSession().isAdmin()) {
			redirectAttrs.addFlashAttribute("error", "Usuário não é administrador.");
			return new ModelAndView("redirect:/");
		}

		ModelAndView mv = new ModelAndView("admin/inicio");
		mv.addObject("userLogged", SessionHandler.getUserSession());
		mv.addObject("admin", true);
		return mv;
	}

	@RequestMapping("/logout")
	public String logout(){
		SessionHandler.logout();

		return "redirect:/admin";
	}
}
