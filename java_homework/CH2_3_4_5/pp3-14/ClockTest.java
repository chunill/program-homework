import java.util.Scanner;

public class ClockTest {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.println("input now time: ");
        System.out.print("hour : ");
        int hour = input.nextInt();
        System.out.print("minute : ");
        int minute = input.nextInt();
        System.out.print("second : ");
        int second = input.nextInt();
        input.close();

        Clock clock = new Clock(hour, minute, second);

        System.out.println("\n<now time>");
        clock.print_clock();
    }
}
