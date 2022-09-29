public class CarApplication {
    public static void main(String[] args) {
        Car one_Car = new Car("A", "1888",30000);
        Car two_Car = new Car("B", "1950", 50000);
        
        System.out.println("<One Car>");
        one_Car.print_info();
        System.out.println("<Two Car>");
        two_Car.print_info();
        
        one_Car.discount(7);
        two_Car.discount(5);

        System.out.println("<After discount>");
        System.out.printf("One Car price: %.0f\n", one_Car.getPrice());
        System.out.printf("Two Car price: %.0f\n", two_Car.getPrice());
                
    }
}