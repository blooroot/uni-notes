package notes.cicloV.DataStructures.week1.classExercises;

public class MainFecha {

    public static void main(String[] args){
        Fecha fecha1 = new Fecha(15, 9, 2004);
        Fecha fecha2 = new Fecha(12, 5, 2024);

        System.out.println("\n[1] Día: " + fecha1.getDay());
        System.out.println("[2] Mes: " + fecha1.getMonth());
        System.out.println("[3] Nombre del mes: " + fecha1.getMonthName());
        System.out.println("[4] Año: " + fecha1.getYear());
        System.out.println("[5] Fecha en formato dd/mm/yyyy: " + fecha1.toString());
        System.out.println("[6] Número de días distantes de " + fecha2.toString() + ": " + fecha1.numDays(fecha2));
        System.out.println("[7] ¿Es año bisiesto?: " + fecha1.isLeapYear());
        System.out.println("[8] " + fecha2.toString() + " es (-1 = mayor, 0 = igual, 1 = menor) que " + fecha1.toString() + ": " + fecha1.compareTo(fecha2) + "\n");
    }

}
