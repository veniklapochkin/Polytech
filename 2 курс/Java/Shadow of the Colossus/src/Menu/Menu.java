package Menu;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;
 
public class Menu extends JFrame {
 
     private JTextField textField;
 
     public Menu() {
          super("Menu");
          createGUI();
     }
 
     public void createGUI() {
          setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 
          JPanel panel = new JPanel();
          panel.setLayout(new FlowLayout());
 
          JButton button1 = new JButton("New Game");
          button1.setActionCommand("GO!");
          panel.add(button1);
 
          JButton button2 = new JButton("Exit");
          button2.setActionCommand("Goodbuy!");
          panel.add(button2);
          textField = new JTextField();
          textField.setColumns(23);
          panel.add(textField);
          //System.exit(4);
          ActionListener actionListener = new TestActionListener();
           
          button1.addActionListener(actionListener);
          button2.addActionListener(actionListener);
          getContentPane().add(panel);
          setPreferredSize(new Dimension(320, 100));
     }
 
     public class TestActionListener implements ActionListener {
          public void actionPerformed(ActionEvent e) {
               textField.setText(e.getActionCommand());
               System.exit(0);
          }
     }
 
     public static void main(String[] args) {
          javax.swing.SwingUtilities.invokeLater(new Runnable() {
               public void run() {
                    JFrame.setDefaultLookAndFeelDecorated(true);
                    Menu frame = new Menu();
                    frame.pack();
                    frame.setLocationRelativeTo(null);
                    frame.setVisible(true);
               }
          });
     }
}