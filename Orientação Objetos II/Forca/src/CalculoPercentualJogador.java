
import com.google.gson.annotations.Expose;
import java.io.Serializable;

public class CalculoPercentualJogador extends Jogador implements Serializable {

    @Expose()
    private double percentual;

    public CalculoPercentualJogador(String usuario, int vitorias, int derrotas) {
        setJogador(usuario);
        setVitorias(vitorias);
        setDerrotas(derrotas);
        percentual = (getVitorias() * 100) / (getVitorias() + getDerrotas());
    }

    public CalculoPercentualJogador() {

    }

    public double getPercentual() {
        return percentual = (getVitorias() * 100) / (getVitorias() + getDerrotas());
    }
}
