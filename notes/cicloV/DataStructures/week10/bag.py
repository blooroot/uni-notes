def es_factible(pesos, k, M, solucion_parcial): 
    
    peso_total = sum(pesos[i] for i in range(k) if solucion_parcial[i] == 1)
    return peso_total <= M # (it means la sol parcial es factible)

def backtrack(pesos, beneficios, k, M, solucion_parcial, mejor_solucion, mejor_beneficio):
   
    if k == len(pesos): # Caso base = 'k' = longitud de la lista de pesos (considerando todos los elementos)
        beneficio_actual = sum(beneficios[i] for i in range(len(pesos)) if solucion_parcial[i] == 1)
        if beneficio_actual > mejor_beneficio:
            mejor_beneficio = beneficio_actual
            mejor_solucion[:] = solucion_parcial[:]
    else: # si 'k' no es len(pesos)
        solucion_parcial[k] = 0
        backtrack(pesos, beneficios, k+1, M, solucion_parcial, mejor_solucion, mejor_beneficio)
        solucion_parcial[k] = 1
        if es_factible(pesos, k+1, M, solucion_parcial):
            backtrack(pesos, beneficios, k+1, M, solucion_parcial, mejor_solucion, mejor_beneficio)

def mochila(pesos, beneficios, M):
    n = len(pesos)
    solucion_parcial = [0] * n # Inicializo solucion_parcial como una lista de ceros de tamaño n
    mejor_solucion = [0] * n # same con mejor_solucion
    mejor_beneficio = 0
    # Llamo a backtrack para comenzar el proceso de exploracion de combinaciones desde el indice 0
    backtrack(pesos, beneficios, 0, M, solucion_parcial, mejor_solucion, mejor_beneficio)
    
    return mejor_solucion, mejor_beneficio

pesos = [2, 3, 4, 5]
beneficios = [3, 4, 5, 6]
M = 10

mejor_solucion, mejor_beneficio = mochila(pesos, beneficios, M)
print("\n")
print("Mejor combinacion de elementos: ", mejor_solucion)
print("Máximo beneficio: ", mejor_beneficio)
print("\n")

