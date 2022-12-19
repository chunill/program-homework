import java.awt.*;
import java.awt.event.*;

public class app17_18 {
    static Frame frm = new Frame ("Panel class");
    static Panel pnl = new Panel(new GridLayout(3, 3));
    static Panel operation = new Panel(new GridLayout(4, 1));
    static Panel equal_clear = new Panel(new GridLayout(2, 1));
    static Label lab = new Label("0 ", Label.RIGHT);
    static Label DSG = new Label("DSG Calculator");
    static Button button = new Button();
    static Button zero = new Button("0");
    static Button bot = new Button(".");
    public static void main (String args[]){
        String[] operator = {"+", "-", "x", "/"};
        String[] equal_clear_text = {"=", "clear"};
        frm.setLayout(null);
        frm.setSize(440, 300);
        frm.setResizable(false);

        lab.setBounds(40, 60 , 240, 40);
        lab.setBackground(new Color(255, 175, 176));
        lab.setFont(new Font("Sans", Font.BOLD, 18));
        DSG.setBounds(300, 60, 100, 40);
        DSG.setFont(new Font("Sans", Font.BOLD + Font.ITALIC, 12));

        pnl.setBounds(40, 120, 165, 120);
        operation.setBounds(230, 120, 55, 160);
        equal_clear.setBounds(305, 120, 90, 160);

        zero.setBounds(40, 240, 110, 40);
        zero.setFont(new Font("Sans", Font.BOLD, 18));
        bot.setBounds(150, 240, 55, 40);
        bot.setFont(new Font("Sans", Font.BOLD, 18));

        for(int i=1;i<=9;i++){
            button = new Button(Integer.toString(i));
            button.setFont(new Font("Sans", Font.BOLD + Font.ITALIC, 18));
            pnl.add(button);
        }

        for(int i=0;i<4;i++){
            button = new Button(operator[i]);
            button.setForeground(Color.blue);
            button.setFont(new Font("Sans", Font.BOLD,18));
            operation.add(button);
        }

        for(int i=0;i<2;i++){
            button = new Button(equal_clear_text[i]);
            button.setForeground(Color.red);
            button.setFont(new Font("Sans", Font.BOLD, 18));
            equal_clear.add(button);
        }

        frm.add(lab);
        frm.add(pnl);
        frm.add(operation);
        frm.add(DSG);
        frm.add(equal_clear);
        frm.add(zero);
        frm.add(bot);
        frm.setVisible(true);

        frm.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e){System.exit(0);}});
    }
    
}
