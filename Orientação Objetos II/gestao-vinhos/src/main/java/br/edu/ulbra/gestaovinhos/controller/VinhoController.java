package br.edu.ulbra.gestaovinhos.controller;

import br.edu.ulbra.gestaovinhos.general.SessionHandler;
import br.edu.ulbra.gestaovinhos.input.AvaliacaoInput;
import br.edu.ulbra.gestaovinhos.model.Avaliacao;
import br.edu.ulbra.gestaovinhos.model.Vinho;
import br.edu.ulbra.gestaovinhos.repository.AvaliacaoRepository;
import br.edu.ulbra.gestaovinhos.repository.VinhoRepository;
import org.modelmapper.ModelMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import java.util.Date;
import java.util.List;

@Controller
@RequestMapping("/vinhos")
public class VinhoController {
	@Autowired
	AvaliacaoRepository avaliacaoRepository;
	@Autowired
	VinhoRepository vinhoRepository;

	private ModelMapper mapper = new ModelMapper();

	@RequestMapping("/minhalista")
	public ModelAndView minhaLista(RedirectAttributes redirectAttrs) {
		if (!SessionHandler.isUserLogged()) {
			redirectAttrs.addFlashAttribute("error", "Efetue login para acessar.");
			return new ModelAndView("redirect:/");
		}

		ModelAndView mv = new ModelAndView("vinhos/listarVinhos");
		mv.addObject("userLogged", SessionHandler.getUserSession());
		mv.addObject("admin", false);
		List<Avaliacao> avaliations = avaliacaoRepository.findByUser(SessionHandler.getUserSession());
		mv.addObject("avaliations", avaliations);
		return mv;
	}

	@RequestMapping("/vinho/{id}")
	public ModelAndView detalhe(@PathVariable("id") Long idVinho, RedirectAttributes redirectAttrs) {
		if (!SessionHandler.isUserLogged()) {
			redirectAttrs.addFlashAttribute("error", "Efetue login para acessar");
			return new ModelAndView("redirect:/");
		}

		Vinho vinho = vinhoRepository.findOne(idVinho);

		if (vinho == null) {
			redirectAttrs.addFlashAttribute("error", "Vinho inexistente.");
			return new ModelAndView("redirect:/inicio");
		}

		ModelAndView mv = new ModelAndView("vinhos/detalhe");
		mv.addObject("userLogged", SessionHandler.getUserSession());
		mv.addObject("admin", false);
		mv.addObject("avaliations", (vinho.getAvaliacoes().isEmpty() ? null : vinho.getAvaliacoes()));
		mv.addObject("wine", vinho);
		return mv;
	}

	@GetMapping("/vinho/{id}/avaliar")
	public ModelAndView avaliarForm(@PathVariable("id") Long idVinho, RedirectAttributes redirectAttrs){
		if (!SessionHandler.isUserLogged()) {
			redirectAttrs.addFlashAttribute("error", "Efetue login para acessar");
			return new ModelAndView("redirect:/");
		}

		Vinho vinho = vinhoRepository.findOne(idVinho);

		if (vinho == null) {
			redirectAttrs.addFlashAttribute("error", "Vinho inexistente.");
			return new ModelAndView("redirect:/inicio");
		}

		ModelAndView mv = new ModelAndView("vinhos/avaliar");
		Avaliacao avaliacao = avaliacaoRepository.findByUserAndVinho(SessionHandler.getUserSession(), vinho);
		AvaliacaoInput avaliacaoInput = mapper.map((avaliacao == null ? new Avaliacao() : avaliacao), AvaliacaoInput.class);
		mv.addObject("avaliation", avaliacaoInput);
		mv.addObject("userLogged", SessionHandler.getUserSession());
		mv.addObject("admin", false);
		mv.addObject("date", new Date());
		mv.addObject("wine", vinho);
		return mv;
	}

	@PostMapping("/vinho/{id}/avaliar")
	public String enviarAvaliacao(@PathVariable("id") Long idVinho, AvaliacaoInput avaliacaoInput, RedirectAttributes redirectAttrs){
		if (!SessionHandler.isUserLogged()) {
			redirectAttrs.addFlashAttribute("error", "Efetue login para acessar");
			return "redirect:/";
		}

		Vinho vinho = vinhoRepository.findOne(idVinho);
		if (vinho == null) {
			redirectAttrs.addFlashAttribute("error", "Vinho inexistente.");
			return "redirect:/inicio";
		}

		Avaliacao avaliacao = avaliacaoRepository.findByUserAndVinho(SessionHandler.getUserSession(), vinho);
		if (avaliacao == null) {
			avaliacao = new Avaliacao();
			avaliacao.setDateTime(new Date());
			avaliacao.setDescricao(avaliacaoInput.getDescricao());
			avaliacao.setPositivo(avaliacaoInput.isPositivo());
			avaliacao.setUser(SessionHandler.getUserSession());
			avaliacao.setVinho(vinho);
		} else {
			avaliacao.setDateTime(new Date());
			avaliacao.setDescricao(avaliacaoInput.getDescricao());
			avaliacao.setPositivo(avaliacaoInput.isPositivo());
		}
		avaliacaoRepository.save(avaliacao);

		redirectAttrs.addFlashAttribute("success", "Avaliado com sucesso.");

		return "redirect:/vinhos/vinho/" + idVinho;
	}
}
