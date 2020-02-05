import java.io.FileNotFoundException;
import java.io.FileReader;
import com.google.gson.*;

public class Diet{
    public static void main(String[] args) throws FileNotFoundException {
        Gson gson = new Gson();
        String fileName = args[0];
        JsonObject reader = gson.fromJson(new FileReader(fileName), JsonObject.class);
        JsonElement data;
        
        data = reader.get("nutrientes");
        int nutrientes = gson.fromJson(data, int.class);
        
        data = reader.get("comidas");
        int comidas = gson.fromJson(data, int.class);
        
        data = reader.get("nutr_comida");
        double[][] nutr_comida = gson.fromJson(data, double[][].class);
        
        data = reader.get("costo_comida");
        double[] costo_comida = gson.fromJson(data, double[].class);
        
        data = reader.get("comida_minima");
        double[] comida_minima = gson.fromJson(data, double[].class);
        
        data = reader.get("comida_maxima");
        double[] comida_maxima = gson.fromJson(data, double[].class);
        
        data = reader.get("nutr_minimo");
        double[] nutr_minimo = gson.fromJson(data, double[].class);
        
        data = reader.get("nutr_maximo");
        double[] nutr_maximo = gson.fromJson(data, double[].class);
        
    }
} 
