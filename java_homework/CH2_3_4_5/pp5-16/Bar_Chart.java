import java.util.Scanner;
public class Bar_Chart {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int[] chart_number = new int[5];
        for (int i = 0;i < 5;i++){
            System.out.printf("Enter the bar chart number of %d: ", i + 1);
            chart_number[i] = input.nextInt();
        }

        System.out.print("\n");
        System.out.println("Bar chart:");
        for (int i = 0; i < 5; i++){
            System.out.printf("Number %d: ", i + 1);
            for (int j = 0; j < chart_number[i]; j++) System.out.print("*");
            System.out.print("\n");
        }
        input.close();
        
    }
}
