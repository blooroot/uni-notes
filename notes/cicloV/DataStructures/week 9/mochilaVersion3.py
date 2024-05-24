# VERSION 3: menor peso, mayor peso, mayor valor

def fractional_knapsack_max_weight_light(weights, values, capacity):
    # Calcular el valor por unidad de peso para cada objeto
    value_per_weight = [(values[i] / weights[i], weights[i], values[i]) for i in range(len(weights))]
    
    # Array de valor/peso en orden ascendente
    value_per_weight.sort(key=lambda x: x[1])
    
    total_weight = 0.0
    for vpw, weight, value in value_per_weight:
        if capacity >= weight:
            total_weight += weight
            capacity -= weight
        else:
            # Si la mochila no puede contener todo el objeto, añadir la fracción que cabe
            total_weight += capacity
            break
    
    return total_weight

# testeamos :)
weights1 = [10, 20, 30]
values1 = [60, 100, 120]
capacity1 = 50
print("\nMayor peso almacenado (objetos más ligeros):", fractional_knapsack_max_weight_light(weights1, values1, capacity1), "\n")

def fractional_knapsack_max_weight_heavy(weights, values, capacity):
    # Array de valor/peso
    value_per_weight = [(values[i] / weights[i], weights[i], values[i]) for i in range(len(weights))]
    
    # Array de valor/peso en orden descendente
    value_per_weight.sort(key=lambda x: x[1], reverse=True)
    
    total_weight = 0.0
    for vpw, weight, value in value_per_weight:
        if capacity >= weight:
            total_weight += weight
            capacity -= weight
        else:
            total_weight += capacity
            break
    
    return total_weight

# Testeamos :)
weights2 = [10, 20, 30]
values2 = [60, 100, 120]
capacity2 = 50
print("\nMayor peso almacenado (objetos más pesados):", fractional_knapsack_max_weight_heavy(weights2, values2, capacity2), "\n")

def fractional_knapsack_max_value(weights, values, capacity):
    # Array valor/peso para cada objeto
    value_per_weight = [(values[i] / weights[i], weights[i], values[i]) for i in range(len(weights))]
    
    # Array de valor/peso en orden descendente
    value_per_weight.sort(key=lambda x: x[0], reverse=True)
    
    total_value = 0.0
    for vpw, weight, value in value_per_weight:
        if capacity >= weight:
            total_value += value
            capacity -= weight
        else:
            total_value += vpw * capacity
            break
    
    return total_value

# testeamos :)
weights3 = [10, 20, 30]
values3 = [60, 100, 120]
capacity3 = 50
print("\nMayor valor almacenado en la mochila:", fractional_knapsack_max_value(weights3, values3, capacity3), "\n")
