import java.awt.*; 
import javax.swing.*;
import java.awt.event.*;
  
public class Fenetre extends JFrame implements ActionListener{    
   private JButton Bouton1,Bouton2;
   private JLabel Label;
   public Fenetre(int largeur,int hauteur) {
      super();
      this.setSize(largeur,hauteur);
      this.setTitle("Essai");
      Bouton1 = new  JButton("Bouton 1");
      Bouton2 = new  JButton("Bouton 2");
      Label = new JLabel("LABEL");
      Container c = this.getContentPane();
      c.add(Bouton1, BorderLayout.WEST);
      c.add(Bouton2, BorderLayout.EAST);
      c.add(Label, BorderLayout.CENTER);
      Bouton1.addActionListener(this);
      Bouton2.addActionListener(this);
      Label.setOpaque(true);
      this.setVisible(true);
   }
   public void actionPerformed(ActionEvent e) {
      if (e.getSource() == Bouton1) {
         System.out.println("Bouton 1");
         Label.setText("C'est le bouton 1");
         Label.setForeground(Color.red);
      }
      if (e.getSource() == Bouton2) {
         System.out.println ("Bouton 2");
         Label.setText("C'est le bouton 2");
         Label.setForeground(Color.green);
      }
             
   }
   
}

