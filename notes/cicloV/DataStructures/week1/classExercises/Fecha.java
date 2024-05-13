package notes.cicloV.DataStructures.week1.classExercises;

public class Fecha implements iFecha {

    private int day;
    private int month;
    private int year;
    // Constructor
    public Fecha(int day, int month, int year) {
        this.day = day;
        this.month = month;
        this.year = year;
    }

    // Creación de la instancia de tipo Fecha
    public static iFecha createDate(int day, int month, int year) {
        return new Fecha(day, month, year);
    }
    // Devuelve el valor numérico del día de la fecha
    @Override
    public int getDay() {
        return this.day;
    }
    // Devuelve el valor numérico del mes de la fecha
    @Override
    public int getMonth() {
        return this.month;
    }
    // Devuelve el nombre del mes de la fecha
    @Override
    public String getMonthName() {
        String[] monthNames = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
        if ( this.month >= 1 && this.month <= 12 ) {
            return monthNames[this.month - 1];
        } else {
            return "Mes inválido";
        }
    }
    // Devuelve el valor numérico del año de la fecha
    @Override
    public int getYear() {
        return this.year;
    }
    // Devuelve el número de días entre dos fechas
    @Override
    public int numDays(iFecha otherDate){
        Fecha other = (Fecha) otherDate;
        int julianDateThis = toJulianDate(this.day, this.month, this.year);
        int julianDateOther = toJulianDate(other.day, other.month, other.year);
        return Math.abs(julianDateThis - julianDateOther);
    }
    // Método auxiliar para conversión a fechas julianas
    public int toJulianDate(int day, int month, int year) {
        double a = ((14 - month) / 12);
        double y = year + 4800 - a;
        double m = month + 12*a - 3;
        int julianDay = (int)(day + ((153*m + 2) / 5) + 365*y + (y/4) - (y/100) + (y/400) - 32045);
    
        return julianDay;
    }
    // Devuelve true si el año es bisiesto, sino devuelve false
    @Override
    public boolean isLeapYear(){
        if ((this.year % 4 == 0 && (this.year % 100 != 0 || this.year % 400 == 0))) {
            return true;
        } else {
            return false;
        }
    }
    // Compara el orden lógico de las fechas
    @Override
    public int compareTo(iFecha otherDate){
        Fecha other = (Fecha) otherDate;
        switch (Integer.compare(this.year, other.year)) {
            case -1:
                return -1;
            case 1:
                return 1;
            default:
                switch (Integer.compare(this.month, other.month)) {
                    case -1:
                        return -1;
                    case 1:
                        return 1;
                    default:
                        switch (Integer.compare(this.day, other.day)) {
                            case -1:
                                return -1;
                            case 1:
                                return 1;
                            default:
                                return 0;
                        }
                }
        }
    }
    // Devuelve la fecha en el formato 'dd/mm/yyyy'
    @Override
    public String toString(){
        String formattedDay = String.format("%02d", this.day);
        String formattedMonth = String.format("%02d", this.month);
        String formattedYear = String.format("%04d", this.year);

        return formattedDay + "/" + formattedMonth + "/" + formattedYear;
    }
}
