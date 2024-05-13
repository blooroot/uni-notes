package notes.cicloV.DataStructures.week1.classExercises;

public interface iFecha {

    // Devuelve el día (valor numérico) de la fecha.
    public int getDay();
    
    // Devuelve el mes (valor numérico) de la fecha.
    public int getMonth();
    
    // Devuelve el nombre del mes de la fecha.
    public String getMonthName();
    
    // Devuelve el año de la fecha.
    public int getYear();
    
    // Devuelve el número de días que hay de diferencia entre la fecha y la fecha pasada como parámetro otherDate.
    public int numDays(iFecha otherDate);
    
    // Devuelve True si el año de la fecha es bisiesto y False en otro caso.
    public boolean isLeapYear();
    
    // Compara la fecha con la fecha otherDate para determinar su orden lógico.
    // Si la fecha es anterior a otherDate, devuelve -1.
    // Si las dos fechas son iguales, devuelve 0.
    // Si la fecha es posterior a otherDate, devuelve 1.
    public int compareTo(iFecha otherDate);
    
    // Devuelve un string representando la fecha en el formato ‘dd/mm/yyyy’
    public String toString();
}