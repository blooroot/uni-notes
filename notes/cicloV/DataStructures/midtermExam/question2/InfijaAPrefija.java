package question2;

import java.util.HashMap;
import java.util.Scanner;
import java.util.Stack;

public class InfijaAPrefija {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        HashMap<Character, Integer> operador = new HashMap<>();

        operador.put('+', 1);
        operador.put('-', 1);
        operador.put('*', 2);
        operador.put('/', 2);
        operador.put('^', 3);
        operador.put('(', 0);
        operador.put(')', 0);

        System.out.println("Ingrese una expresión infija:");
        String infijaExpresion = scanner.nextLine();

        String prefix = conversion(infijaExpresion, operador);
        System.out.println("Expresión prefija: " + prefix);

        double result = resultadoPrefija(prefix);
        System.out.println("Resultado de la expresión: " + result);
    
        scanner.close();
    }

    private static String conversion(String infijaExpresion, HashMap<Character, Integer> operador) {
        StringBuilder infija = new StringBuilder(infijaExpresion).reverse();

        Stack<Character> salida = new Stack<>();
        Stack<Character> operadores = new Stack<>();
        String regex = "[0-9a-zA-Z]";

        for (int i = 0; i < infija.length(); i++) {
            char character = infija.charAt(i);
            if (String.valueOf(character).matches(regex)) {
                salida.push(character);
            } else if (character == ')') {
                operadores.push(character);
            } else if (character == '(') {
                // Añadimos verificación para el caso de un paréntesis sin su correspondiente
                if (!operadores.empty()) {
                    while (!operadores.empty() && operadores.peek() != ')') {
                        salida.push(operadores.pop());
                    }
                    if (!operadores.empty()) {
                        operadores.pop(); // Sacamos el paréntesis de cierre
                    } else {
                        throw new IllegalArgumentException("Expresión infija inválida: Paréntesis sin cerrar");
                    }
                } else {
                    throw new IllegalArgumentException("Expresión infija inválida: Paréntesis sin abrir");
                }
            } else {
                while (!operadores.empty() && operador.getOrDefault(operadores.peek(), 0) >= operador.get(character)) {
                    salida.push(operadores.pop());
                }
                operadores.push(character);
            }
        }

        StringBuilder prefix = new StringBuilder();
        while (!salida.empty()) {
            prefix.append(salida.pop());
        }

        return prefix.reverse().toString();
    }

    private static double resultadoPrefija(String prefix) {
        Stack<Double> stack = new Stack<>();

        for (int i = prefix.length() - 1; i >= 0; i--) {
            char c = prefix.charAt(i);

            if (Character.isDigit(c)) {
                stack.push((double) (c - '0'));
            } else {
                double op1 = stack.pop();
                double op2 = stack.pop();

                switch (c) {
                    case '+':
                        stack.push(op1 + op2);
                        break;
                    case '-':
                        stack.push(op1 - op2);
                        break;
                    case '*':
                        stack.push(op1 * op2);
                        break;
                    case '/':
                        stack.push(op1 / op2);
                        break;
                    case '^':
                        stack.push(Math.pow(op1, op2));
                        break;
                }
            }
        }

        return stack.pop();
    }
}
