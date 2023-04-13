import java.awt.*;
import java.awt.event.*;

public class AWT_4 extends Frame implements ActionListener, MouseMotionListener, MouseListener{
    AWT_4(String title){super(title);}
    static AWT_4 frm = new AWT_4("AWT_4");
    static MenuBar mb = new MenuBar();
    static Menu menu1 = new Menu("工具");
    static MenuItem mi1 = new MenuItem("直線");
    static MenuItem mi2 = new MenuItem("橢圓填滿");
    static MenuItem mi3 = new MenuItem("矩形填滿");
    static MenuItem mi4 = new MenuItem("橡皮筋");
    static MenuItem mi5 = new MenuItem("移動");
    private int mode = 0;
    private int x1, x2, y1, y2;

    public static void main(String args[]){
        frm.setLayout(null);
        frm.setSize(800, 800);
        frm.setResizable(false);

        mb.add(menu1);
        menu1.add(mi1);
        mi1.addActionListener(frm);
        menu1.add(mi2);
        mi2.addActionListener(frm);
        menu1.add(mi3);
        mi3.addActionListener(frm);
        menu1.add(mi4);
        mi4.addActionListener(frm);
        menu1.add(mi5);
        mi5.addActionListener(frm);
        frm.setMenuBar(mb);
        
        frm.addMouseListener(frm);
        frm.addMouseMotionListener(frm);
        frm.setVisible(true);

        frm.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e){System.exit(0);}});
        
    }
    public void actionPerformed(ActionEvent e){
        MenuItem mi = (MenuItem) e.getSource();
        if(mi == mi1){mode = 1;}
        else if(mi == mi2){mode = 2;}
        else if(mi == mi3){mode = 3;}
        else if(mi == mi4){mode = 4;}
        else if(mi == mi5){mode = 5;}
    }
    public void mouseEntered(MouseEvent e){}
    public void mouseClicked(MouseEvent e){}
    public void mouseExited(MouseEvent e){}
    public void mousePressed(MouseEvent e){
        x1 = e.getX();
        y1 = e.getY();
    }
    public void mouseReleased(MouseEvent e){
        x2 = e.getX();
        y2 = e.getY();
        Graphics g = getGraphics();
        if (mode == 1 || mode == 2 || mode == 3)
            update(g);
    }

    public void mouseMoved(MouseEvent e){}
    public void mouseDragged(MouseEvent e){}

    
    private void XYSize(){
        int temp;
        System.out.printf("x1: %d x2: %d y1: %d y2: %d\n", x1, x2, y1, y2);
        if (x1 < x2 && y1 > y2){
            temp = y1;
            y1 = y2;
            y2 = temp;
        }
        else if(x1 > x2 && y1 < y2){
            temp = x1;
            x1 = x2;
            x2 = temp;
        }
        else if(x1 > x2 && y1 > y2){
            temp = x1;
            x1 = x2;
            x2 = temp;
            temp = y1;
            y1 = y2;
            y2 = temp;
        }
        System.out.printf("x1: %d x2: %d y1: %d y2: %d\n", x1, x2, y1, y2);
    }
    public void paint(Graphics g){
        if(mode == 1){
            g.drawLine(x1, y1, x2, y2);
        }
        else if(mode == 2){
            XYSize();
            g.setColor(Color.red);
            g.fillOval(x1, y1, x2 - x1, y2 - y1);
        }
        else if(mode == 3){
            XYSize();
            g.setColor(Color.yellow);
            g.fillRect(x1, y1, x2 - x1, y2 - y1);
        }
        else if(mode == 4){


        }
        else if(mode == 5){

        }
    }
}

