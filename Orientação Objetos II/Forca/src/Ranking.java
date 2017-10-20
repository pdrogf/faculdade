
import com.google.gson.annotations.Expose;

import java.io.Serializable;
import java.util.ArrayList;

public class Ranking implements Serializable {

    @Expose()
    private ArrayList<CalculoPercentualJogador> ranking;

    public Ranking() {
        ranking = new ArrayList<>();
    }

    public Ranking(ArrayList<CalculoPercentualJogador> ranking) {
        this.ranking = ranking;
    }

    public ArrayList<CalculoPercentualJogador> getRanking() {
        return ranking;
    }

    public void setRanking(ArrayList<CalculoPercentualJogador> ranking) {
        this.ranking = ranking;
    }
}
