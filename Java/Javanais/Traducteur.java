import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Traducteur extends JFrame implements ActionListener{

	/**
	 *
	 */
	private static final long serialVersionUID = 1L;
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
         text.setText("");
		 traduction_text.setText("");
      }
	  if (e.getSource() == quitter) {
         System.out.println("Quitter");
		 System.exit(0);
      }

   }

   public void Traduire(String texte){
	   String texte_traduit;
	   StringBuilder temp = new StringBuilder();

	  for (int i=0; i< texte.length(); i++){

		  Lettre lettre_buffer = new Lettre(texte.charAt(i));
		  Lettre next_letter = new Lettre(' ');
		  
		try {
          next_letter.setLettre(texte.charAt(i+1));
        }
        catch(Exception e) {

        }

	      if(lettre_buffer.estUneLettre()){
	    	  System.out.print(lettre_buffer.getLettre() + " est une lettre et c'est une ");

	    	  if (lettre_buffer.estVoyelle()) {
  					System.out.println("voyelle");
  					if (!(lettre_buffer.estY() && i!=texte.length() && next_letter.estVoyelle()))   {
  						if(lettre_buffer.estMajuscule())
  						{
  							temp.append('A');
  							temp.append('V');
  						}
  						else {
  							temp.append('a');
  							temp.append('v');
  						}
  					}
					else {
						System.out.println("Y : Suivi d'une voyelle ?");
					}
			  }else{
				  System.out.println("consomne");
			  }

	      }
	      else{
	    	  System.out.println(lettre_buffer.getLettre() + " n'est pas une lettre.");
	      }

		  temp.append(lettre_buffer.getLettre());

	  }
	  texte_traduit = temp.toString();
	  System.out.println(texte_traduit);

	  traduction_text.setText(texte_traduit);
   }
   public static void main(String args[]) {
      @SuppressWarnings("unused")
	Traducteur fenetre = new Traducteur();
   }
}
