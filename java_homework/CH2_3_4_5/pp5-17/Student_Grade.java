import java.util.Scanner;
public class Student_Grade {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        int[] grade_table = new int[4];
        Student[] students = new Student[5];
        String name, grade;
        for (int i=0 ; i<5 ; i++){
            System.out.printf("Enter %d student name and grade: ", i + 1);
            name = input.next();
            grade = input.next();
            students[i] = new Student(name, grade);
        }

        for (int i=0 ; i<students.length ; i++){
            switch(students[i].getGrade()){
                case "A":
                    grade_table[0]++;
                    break;
                case "B":
                    grade_table[1]++;
                    break;
                case "C":
                    grade_table[2]++;
                    break;
                case "D":
                    grade_table[3]++;
                    break;
                default:
                    break;
            }
        }
        System.out.print("\n");
        for (int i=0 ; i<4 ; i++){
            System.out.printf("Number of student take %c: %d\n", i + 65, grade_table[i]);
        }
        input.close();
    }
}
