# VERSION 1: Maximizar el [numero de objetos] por peso

def greedy_max_objects(weights, capacity):
    # Ordenamos el array de weights
    sorted_weights = sorted(weights)
    # Inicialmente
    total_weight = 0 # La mochila está vacía en peso
    num_objects = 0 # La mochila está vacía en n de objetos
    # Agregamos los objetos mas ligeros mientras la capacity (kg) lo permita 
    for weight in sorted_weights:
        if total_weight + weight <= capacity:
            total_weight += weight
            num_objects += 1
        else:
            break

    return num_objects

weights = [2, 3, 5, 7, 1, 4, 1]
capacity = 8
print("\nNúmero máximo de objetos que pueden introducirse en la mochila:", greedy_max_objects(weights, capacity), "\n")
        

