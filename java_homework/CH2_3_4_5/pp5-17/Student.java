public class Student {
    private String name;
    private String grade;

    public Student(String studentName, String studentGrade){
        this.name = studentName;
        this.grade = studentGrade;
    }

    public void setName(String name) {this.name = name;}
    public void setGrade(String grade) {this.grade = grade;}
    public String getName() {return name;}
    public String getGrade() {return grade;}
}
