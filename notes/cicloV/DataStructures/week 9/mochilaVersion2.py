# VERSION 2: Maximizar el [peso de los objetos] que se introducen en la mochila

def greedy_max_weight_ascendent(weights, capacity):
    # Ordenamos el array de weights
    sorted_weights = sorted(weights)
    # Inicialmente
    total_weight = 0
    # Vamos agregando los objetos más ligeros
    for weight in sorted_weights:
        if total_weight + weight <= capacity:
            total_weight += weight
        else:
            break

    return total_weight

def greedy_max_weight_descendent(weight, capacity):
    # Ordenamos el array de weights
    sorted_weights = sorted(weights, reverse = True)
    # Inicialmente
    total_weight = 0
    # Vamos agregando los objetos más pesados 
    for weight in sorted_weights:
        if total_weight + weight <= capacity:
            total_weight += weight
        else:
            break

    return total_weight

weights = [2, 3, 5, 7, 1, 4, 1]
capacity = 10
print("\nPeso máximo de los objetos en la mochila (ascendent):", greedy_max_weight_ascendent(weights, capacity))
print("Peso máximo de los objetos en la mochila (descendent):", greedy_max_weight_descendent(weights, capacity), "\n")
