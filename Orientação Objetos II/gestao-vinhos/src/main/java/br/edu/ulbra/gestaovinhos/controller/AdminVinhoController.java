package br.edu.ulbra.gestaovinhos.controller;

import br.edu.ulbra.gestaovinhos.input.VinhoInput;
import br.edu.ulbra.gestaovinhos.model.Avaliacao;
import br.edu.ulbra.gestaovinhos.model.TipoVinho;
import br.edu.ulbra.gestaovinhos.model.Vinho;
import br.edu.ulbra.gestaovinhos.repository.AvaliacaoRepository;
import br.edu.ulbra.gestaovinhos.repository.TipoVinhoRepository;
import br.edu.ulbra.gestaovinhos.repository.VinhoRepository;
import br.edu.ulbra.gestaovinhos.service.interfaces.SecurityService;
import org.modelmapper.ModelMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import java.io.File;
import java.io.IOException;
import java.nio.file.Paths;
import java.util.List;
import java.util.UUID;

@Controller
@RequestMapping("/admin/vinho")
public class AdminVinhoController {
	@Value("${gestao-vinhos.uploadFilePath}")
	private String uploadFilePath;
	@Autowired
	VinhoRepository vinhoRepository;
	@Autowired
	SecurityService securityService;
	@Autowired
	TipoVinhoRepository tipoVinhoRepository;
	@Autowired
	AvaliacaoRepository avaliacaoRepository;

	private ModelMapper mapper = new ModelMapper();

	@RequestMapping()
	public ModelAndView listaVinhos(RedirectAttributes redirectAttrs) {
		ModelAndView mv = new ModelAndView("admin/vinho/lista");
		mv.addObject("userLogged", securityService.findLoggedInUser());
		mv.addObject("admin", true);
		List<Vinho> vinhos = (List<Vinho>) vinhoRepository.findAll();
		mv.addObject("wines", vinhos);
		return mv;
	}

	@GetMapping("/novo")
	public ModelAndView novoVinhoForm(@ModelAttribute("wine") VinhoInput wine){
		List<TipoVinho> tipos = (List<TipoVinho>)tipoVinhoRepository.findAll();

		ModelAndView mv = new ModelAndView("admin/vinho/novo");
		mv.addObject("userLogged", securityService.findLoggedInUser());
		mv.addObject("admin", true);
		mv.addObject("wine", wine);
		mv.addObject("types", tipos);
		return mv;
	}

	@PostMapping("/novo")
	public String novoVinho(VinhoInput wineInput, RedirectAttributes redirectAttrs) throws IOException {
		if (wineInput.getNome().length() == 0 || wineInput.getVinicola().length() == 0 || wineInput.getImagem() == null || (wineInput.getImagem() != null && wineInput.getImagem().isEmpty()))
		{
			redirectAttrs.addFlashAttribute("error", "Preencha os campos obrigatórios.");
			redirectAttrs.addFlashAttribute("wine", wineInput);
			return "redirect:/admin/vinho/novo";
		}

		Vinho wine = mapper.map(wineInput, Vinho.class);

		TipoVinho tipo = tipoVinhoRepository.findOne(wineInput.getIdTipo());
		wine.setTipo(tipo);

		MultipartFile imagemFile = wineInput.getImagem();
		String fileName = UUID.randomUUID().toString() + "-" + imagemFile.getOriginalFilename();
		File file = new File(Paths.get(uploadFilePath, fileName).toString());
		file.createNewFile();
		imagemFile.transferTo(file);
		wine.setNomeImagem(fileName);

		vinhoRepository.save(wine);

		redirectAttrs.addFlashAttribute("success", "Cadastro realizado com sucesso.");
		return "redirect:/admin/vinho/";
	}

	@GetMapping("/{id}")
	public ModelAndView detalheVinho(@PathVariable("id") Long idVinho, RedirectAttributes redirectAttrs){
		Vinho vinho = vinhoRepository.findOne(idVinho);

		if (vinho == null) {
			redirectAttrs.addFlashAttribute("error", "Vinho não cadastrado.");
			return new ModelAndView("redirect:/admin/vinho");
		}

		VinhoInput vinhoInput = mapper.map(vinho, VinhoInput.class);

		ModelAndView mv = new ModelAndView("admin/vinho/detalhe");
		List<TipoVinho> tipos = (List<TipoVinho>)tipoVinhoRepository.findAll();
		mv.addObject("types", tipos);
		mv.addObject("avaliations", (vinho.getAvaliacoes().isEmpty() ? null : vinho.getAvaliacoes()));
		mv.addObject("userLogged", securityService.findLoggedInUser());
		mv.addObject("admin", true);
		mv.addObject("wine", vinhoInput);
		return mv;
	}

	@PostMapping("/{id}")
	public String salvarVinho(@PathVariable("id") Long idVinho, VinhoInput wineInput, RedirectAttributes redirectAttrs) throws IOException {
		Vinho wine = vinhoRepository.findOne(idVinho);

		if (wine == null) {
			redirectAttrs.addFlashAttribute("error", "Cadastro inexistente.");
			redirectAttrs.addFlashAttribute("user", wineInput);
			return "redirect:/admin/vinho/" + idVinho;
		}

		if (wineInput.getNome().length() == 0 || wineInput.getVinicola().length() == 0 )
		{
			redirectAttrs.addFlashAttribute("error", "Preencha todos os campos");
			redirectAttrs.addFlashAttribute("wine", wineInput);
			return "redirect:/admin/vinho/" + idVinho;
		}

		if (wineInput.getImagem() != null && !wineInput.getImagem().isEmpty()) {
			MultipartFile imagemFile = wineInput.getImagem();
			String fileName = UUID.randomUUID().toString() + "-" + imagemFile.getOriginalFilename();
			File file = new File(Paths.get(uploadFilePath, fileName).toString());
			file.createNewFile();
			imagemFile.transferTo(file);
			wine.setNomeImagem(fileName);
		}

		TipoVinho tipo = tipoVinhoRepository.findOne(wineInput.getIdTipo());
		wine.setTipo(tipo);
		wine.setNome(wineInput.getNome());
		wine.setVinicola(wineInput.getVinicola());

		vinhoRepository.save(wine);

		redirectAttrs.addFlashAttribute("success", "Cadastro alterado com sucesso.");

		return "redirect:/admin/vinho/" + idVinho;
	}

	@RequestMapping("/{id}/delete")
	public String deletarVinho(@PathVariable("id") Long idVinho, RedirectAttributes redirectAttrs) {
		Vinho vinho = vinhoRepository.findOne(idVinho);
		if (vinho == null) {
			redirectAttrs.addFlashAttribute("error", "Vinho não cadastrado.");
		} else {
			vinhoRepository.delete(vinho);
			redirectAttrs.addFlashAttribute("success", "Cadastro deletado com sucesso.");
		}

		return "redirect:/admin/vinho";
	}

	@RequestMapping("/{vid}/avaliacao/{id}/delete")
	public String deletarComentario(@PathVariable("vid") Long idVinho, @PathVariable("id") Long idAvaliacao, RedirectAttributes redirectAttrs) {
		Avaliacao avaliacao = avaliacaoRepository.findOne(idAvaliacao);
		if (avaliacao == null) {
			redirectAttrs.addFlashAttribute("error", "Cadastro não encontrado.");
		} else {
			avaliacaoRepository.delete(avaliacao);
			redirectAttrs.addFlashAttribute("success", "Avaliacao deletada com sucesso.");
		}

		return "redirect:/admin/vinho/" + idVinho;
	}
}
