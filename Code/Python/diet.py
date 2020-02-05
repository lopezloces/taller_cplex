import sys
import json

def dieta(fileName):
    with open(fileName) as file:
        data = json.load(file)
    nutrientes = data['nutrientes']
    comidas = data['comidas']
    nutr_comida = data['nutr_comida']
    costo_comida = data['costo_comida']
    comida_minima = data['comida_minima']
    comida_maxima = data['comida_maxima']
    nutr_minimo = data['nutr_minimo']
    nutr_maximo = data['nutr_maximo']


if __name__ == "__main__":
    dieta(str(sys.argv[1]))

