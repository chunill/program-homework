import java.awt.*;
import java.awt.event.*;

public class AWT_2 extends Frame implements ActionListener{
    static AWT_2 frm = new AWT_2();
    static Panel pnl_row = new Panel(new FlowLayout(FlowLayout.CENTER, 5, 15));
    static Panel text_input = new Panel(new GridLayout(3, 1, 0, 15));
    static Panel gender_input = new Panel(new GridLayout(1, 2, 0, 15));

    static TextField name = new TextField(1);
    static TextField weight = new TextField(1);
    static TextField length = new TextField(1);
    static CheckboxGroup gender = new CheckboxGroup();
    static Checkbox male = new Checkbox("男性", true, gender);
    static Checkbox female = new Checkbox("女性", false, gender);
    static Choice age = new Choice();
    static Button compute = new Button("Compute BMI");
    static Button exitButton = new Button("Exit");
        
    public static void main(String args[]){
        String[] row = {"名字", "體重", "身高", "性別", "年齡"};
        Font font = new Font("Serief", Font.PLAIN, 21);
        Label row_text;

        for(int i=1;i<=99;i++){
            age.add(String.format("%d", i));
        }

        frm.setLayout(null);
        frm.setSize(510, 630);
        frm.setResizable(false);

        pnl_row.setBounds(40, 80, 100, 300);

        for (int i=0;i<5;i++){
            row_text = new Label(row[i]);
            row_text.setFont(font);
            pnl_row.add(row_text);
        }

        text_input.add(name);
        text_input.add(weight);
        text_input.add(length);

        text_input.setBounds(180, 95, 200, 150);

        gender_input.add(male);
        gender_input.add(female);

        gender_input.setBounds(180, 258, 100, 30);

        frm.add(gender_input);
        frm.add(text_input);

        name.setFont(new Font("Serief", Font.PLAIN, 16));
        weight.setFont(new Font("Serief", Font.PLAIN, 16));
        length.setFont(new Font("Serief", Font.PLAIN, 16));
        male.setFont(font);
        female.setFont(font);
        age.setBounds(180, 310, 60, 30);
        age.setFont(font);

        compute.setBounds(60, 530, 250, 40);
        compute.setFont(font);
        exitButton.setBounds(350, 530, 100, 40);
        exitButton.setFont(font);

        row_text = new Label("(公斤)");
        row_text.setFont(font);
        row_text.setBounds(380, 156, 100, 30);
        frm.add(row_text);

        row_text = new Label("(公分)");
        row_text.setFont(font);
        row_text.setBounds(380, 212, 100, 30);
        frm.add(row_text);

        frm.add(age);
        frm.add(pnl_row);
        frm.add(compute);
        frm.add(exitButton);
        frm.setVisible(true);

        compute.addActionListener(frm);
        exitButton.addActionListener(frm);
        frm.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e){System.exit(0);}});
    }
    public void actionPerformed(ActionEvent e){
        Button btn = (Button) e.getSource();
        Label grade = new Label();
        Label suggestion = new Label();

        if (btn == compute){
            double BMI, weight_value, length_value;
            String suggestion_text = "";

            grade.setBounds(60, 380, 390, 70);
            grade.setAlignment(Label.CENTER);
            grade.setFont(new Font("Serif", Font.PLAIN, 24));
            grade.setForeground(Color.blue);

            suggestion.setBounds(60, 430, 390, 70);
            suggestion.setAlignment(Label.CENTER);
            suggestion.setFont(new Font("Serif", Font.PLAIN, 18));

            weight_value = Double.parseDouble(weight.getText());
            length_value = Double.parseDouble(length.getText());
            
            if (male.getState() == true)
                suggestion_text = String.format("%s(%s, %s): ", name.getText(), age.getSelectedItem(), "男性");
            else
                suggestion_text = String.format("%s(%s, %s): ", name.getText(), age.getSelectedItem(), "女性");

            BMI = (weight_value / ((length_value * length_value) * 0.0001));
            System.out.printf("%f %f", weight_value, length_value);
           
            if (BMI < 18.5){
                grade.setText("Under weight");
                suggestion_text += "Eat more !";
            }
            else if (BMI <= 23.9){
                grade.setText("Normal weight");
                suggestion_text += "Great!";
            }
            else if (BMI <= 26.9){
                grade.setText("Over weight");
                suggestion_text += "Remember to do exercises!";
            }
            else{
                grade.setText("Obesity");
                suggestion_text += "Go on diet, now!";
            }

            suggestion.setText(suggestion_text);
        }
        else{
            System.exit(0);
        }

        frm.add(grade);
        frm.add(suggestion);
    }
}