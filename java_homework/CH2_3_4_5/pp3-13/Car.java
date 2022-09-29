public class Car {
    private String model;
    private String year;
    private double price;
    
    public Car(String model, String year, double price) {
        this.model = model;
        this.year = year;
        if (price >= 0) {
            this.price = price;
        }
    }
    
    public String getModel() {return model;}
    public String getYear() {return year;}
    public double getPrice() {return price;}
    public void setModel(String model) {this.model = model;}
    public void setYear(String year) {this.year = year;}
    public void setPrice(double price) {
        if (price >= 0) {
            this.price = price;
        }
    }

    public double discount(double discount){
        this.setPrice(this.price * (1 - (discount / 100)));
        return this.price;
    }
    public void print_info(){
        System.out.printf("Model: %s\n", this.getModel());
        System.out.printf("Year: %s\n", this.getYear());
        System.out.printf("Price: %.0f\n", this.getPrice());
        System.out.printf("\n");
    }
}