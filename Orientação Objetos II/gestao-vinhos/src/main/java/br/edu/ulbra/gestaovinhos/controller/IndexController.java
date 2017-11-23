package br.edu.ulbra.gestaovinhos.controller;

import br.edu.ulbra.gestaovinhos.general.SessionHandler;
import br.edu.ulbra.gestaovinhos.model.Vinho;
import br.edu.ulbra.gestaovinhos.repository.VinhoRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.core.io.FileSystemResource;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import java.nio.file.Paths;
import java.util.List;

@Controller
public class IndexController {
	@Value("${gestao-vinhos.uploadFilePath}")
	private String uploadFilePath;
	@Autowired
	VinhoRepository vinhoRepository;

	@RequestMapping("/")
	public String index(){
		if (SessionHandler.isUserLogged()) {
			return "redirect:/inicio";
		}

		return "index";
	}

	@RequestMapping("/inicio")
	public ModelAndView home(RedirectAttributes redirectAttrs) {
		if (!SessionHandler.isUserLogged()) {
			redirectAttrs.addFlashAttribute("error", "Realize login para acessar.");
			return new ModelAndView("redirect:/");
		}

		ModelAndView mv = new ModelAndView("home");
		mv.addObject("userLogged", SessionHandler.getUserSession());
		mv.addObject("admin", false);
		List<Vinho> vinhos = (List<Vinho>) vinhoRepository.findAll();
		mv.addObject("wines", vinhos);
		return mv;
	}

	@RequestMapping("/minhalista")
	public ModelAndView minhalista(RedirectAttributes redirectAttrs) {
		if (!SessionHandler.isUserLogged()) {
			redirectAttrs.addFlashAttribute("error", "Realize login para acessar.");
			return new ModelAndView("redirect:/");
		}

		ModelAndView mv = new ModelAndView("lista");
		mv.addObject("userLogged", SessionHandler.getUserSession());
		mv.addObject("admin", false);
		mv.addObject("avaliations", SessionHandler.getUserSession().getAvaliacoes());
		return mv;
	}

	@RequestMapping("/logout")
	public String logout(){
		SessionHandler.logout();

		return "redirect:/";
	}

	@GetMapping("/images/{fileName:.+}")
	@ResponseBody
	public FileSystemResource getFile(@PathVariable("fileName") String fileName){
		FileSystemResource fileSystemResource = new FileSystemResource(Paths.get(uploadFilePath, fileName).toString());
		return fileSystemResource;
	}
}
