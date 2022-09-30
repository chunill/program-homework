import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int item = 1, number;
        double item_value[] = {239.99, 129.75, 99.95, 350.89};
        double revenue = 200;

        while(item != 0) {
            System.out.print("Enter the salesperson’s item numbering (If ending enter zero): ");
            item = input.nextInt();
            if (item != 0){
                System.out.print("Enter number of the item: ");
                number = input.nextInt();
                revenue += item_value[item - 1] * number * 0.09;
            }
        }

        System.out.print("The salesperson’s earnings: ");
        System.out.printf("%.2f", revenue);
        input.close();
    }
}
