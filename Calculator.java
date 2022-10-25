//calculator
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;



public class Calculator extends JFrame implements ActionListener {
    static JFrame f;
    static JButton b1, b2, b3, b4, b5, b6, b7, b8, b9, b0, dot;
    static JButton plus, minus, mult, divide, clear, equals;
    static JTextField t1;
    
    static String s0, s1, s2;

    Calculator() {
        s1 = s2 = s0 = "";
    }

    public static void main(String[] args) {
        Calculator c = new Calculator();

        JPanel p1 = new JPanel();
        JPanel p2 = new JPanel();
        JPanel p3 = new JPanel();

        f = new JFrame("Calculator");

        b1 = new JButton("1");
        b2 = new JButton("2");
        b3 = new JButton("3");
        b4 = new JButton("4");
        b5 = new JButton("5");
        b6 = new JButton("6");
        b7 = new JButton("7");
        b8 = new JButton("8");
        b9 = new JButton("9");
        b0 = new JButton("0");
        dot = new JButton(".");
        plus = new JButton("+");
        minus = new JButton("-");
        mult = new JButton("x");
        divide = new JButton("/");
        equals = new JButton("=");
        clear = new JButton("AC");

        t1 = new JTextField(24);
        t1.setEditable(false);
        // t1.setBounds(10,10,300, 30);

        b1.addActionListener(c);
        b2.addActionListener(c);
        b3.addActionListener(c);
        b4.addActionListener(c);
        b5.addActionListener(c);
        b6.addActionListener(c);
        b7.addActionListener(c);
        b8.addActionListener(c);
        b9.addActionListener(c);
        b0.addActionListener(c);
        dot.addActionListener(c);
        plus.addActionListener(c);
        minus.addActionListener(c);
        mult.addActionListener(c);
        divide.addActionListener(c);
        equals.addActionListener(c);
        clear.addActionListener(c);

        p1.add(t1);

        p2.add(b7);
        p2.add(b8);
        p2.add(b9);
        p2.add(divide);

        p2.add(b4);
        p2.add(b5);
        p2.add(b6);
        p2.add(mult);

        p2.add(b1);
        p2.add(b2);
        p2.add(b3);
        p2.add(minus);

        p2.add(b0);
        p2.add(dot);
        p2.add(equals);
        p2.add(plus);

        p3.add(clear);

        p2.setLayout(new GridLayout(4, 4, 2, 2));
        // p1.setBounds(20, 10, 350, 30);
        f.add(p1, BorderLayout.NORTH);
        f.add(p2);
        f.add(p3, BorderLayout.SOUTH);

        f.setDefaultCloseOperation(EXIT_ON_CLOSE);
        f.setSize(400, 400);
        f.setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        String s = e.getActionCommand();
        if ((s.charAt(0) >= '0' && s.charAt(0) <= '9') || s.charAt(0) == '.') {

            if (!s1.equals(""))
                s2 = s2 + s;
            else
                s0 = s0 + s;

            t1.setText(s0 + s1 + s2);

        } else if (s.equals("AC")) {

            s0 = s1 = s2 = "";
            t1.setText(s0 + s1 + s2);

        } else if (s.charAt(0) == '=') {

            double result;

            if (s1.equals("+"))
                result = Double.parseDouble(s0) + Double.parseDouble(s2);
            else if (s1.equals("-"))
                result = Double.parseDouble(s0) - Double.parseDouble(s2);
            else if (s1.equals("x"))
                result = Double.parseDouble(s0) * Double.parseDouble(s2);
            else
                result = Double.parseDouble(s0) / Double.parseDouble(s2);

            s0 = Double.toString(result);
            t1.setText(s0);
            s1 = s2 = "";
        } else {
            if (s1.equals("") || s2.equals("")) {
                s1 = s;
            } else {
                double result;

                if (s1.equals("+"))
                    result = Double.parseDouble(s0) + Double.parseDouble(s2);
                else if (s1.equals("-"))
                    result = Double.parseDouble(s0) - Double.parseDouble(s2);
                else if (s1.equals("x"))
                    result = Double.parseDouble(s0) * Double.parseDouble(s2);
                else
                    result = Double.parseDouble(s0) / Double.parseDouble(s2);

                s0 = Double.toString(result);
                s1 = s;
                s2 = "";
            }
            t1.setText(s0 + s1 + s2);
        }
    }
}
