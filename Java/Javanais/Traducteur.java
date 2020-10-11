import java.awt.*; 
import javax.swing.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
 
public class Traducteur extends JFrame implements ActionListener{
	
	JButton bouton,effacer,quitter;
	//Traduction traduction;
	JTextField text,traduction_text;
	
	public Traducteur() {
      super();
      this.setSize(800, 500);
      this.setTitle("Javanesse");
      	
      JPanel panel = new JPanel();
      GridLayout gl = new GridLayout(1,3); //1 ligne et n colonnes
      panel.setLayout(gl);
	  
	  text = new JTextField ("Bonjour !");
	  traduction_text = new JTextField ("Traduction !");
      bouton = new JButton("Traduire");
	  effacer = new JButton("Effacer");	  
	  quitter = new JButton("Quitter");
	  
	  
      panel.add(text);
	  panel.add(traduction_text);
	  panel.add(bouton);
	  panel.add(effacer);
	  panel.add(quitter);
	  
      bouton.addActionListener(this);
	  effacer.addActionListener(this);
	  quitter.addActionListener(this);
      	         
      this.setDefaultCloseOperation(EXIT_ON_CLOSE);
      this.setContentPane(panel);
      this.setVisible(true);
   }
  public void actionPerformed(ActionEvent e) {
      if (e.getSource() == bouton) {
		 Traduire(text.getText());
		 //traduction.start();
		 //traduction.setText("put your text here");
      }
	  if (e.getSource() == effacer) {
         System.out.println("Effacer");
		 traduction_text.setText("");
      }
	  if (e.getSource() == quitter) {
         System.out.println("Quitter");
		 System.exit(0);
      }
             
   }
   
   public void Traduire(String texte){
	   System.out.println(texte);
	  
	  for (int i=0; i< texte.length(); i++){
	  
	      char lettre_buffer = texte.charAt(i);
	      
		  if (Lettre.estVoyelle(lettre_buffer)) { 
				System.out.println(lettre_buffer + " est une voyelle");  
		  }else{
			  System.out.println(lettre_buffer + " est une consomne");  
		  }
		  /*
		  if(lettre_buffer.estY()){
		  
		    System.out.println("ALEEEEEEEEEEEERTE !"); 
		  }
		  */
		  
		//buffer.setCharAt(2,'4');
		//System.out.println(maChaine.charAt(i));
	  }
	  /*
	  maChaine = buffer.toString();
	  System.out.println(maChaine);
	  */
	   traduction_text.setText(texte + " : TRADUIIT !!");
   }
   public static void main(String args[]) {
      Traducteur fenetre = new Traducteur(); 
   }
}
