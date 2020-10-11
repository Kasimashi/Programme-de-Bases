import java.util.*;
import static java.lang.Character.*;


public class Lettre {
 
 private static Character[] voyelles = {'a', 'e', 'i','o','u','y'}; 

/**
* Le constructeur de la classe Lettre.
*
* @param char Le caractère concerné
*/
 
 public Lettre(char x) {
 }

/**
* Cette méthode permet de savoir si la lettre est une voyelle.
*
* @return boolean Vrai si voyelle, faux sinon
*/
 public static boolean estVoyelle(char c) {
 List<Character> list = Arrays.asList(voyelles);
 if (list.contains(c)) {
	return(true);
	 }
	 else {
		return(false);
	 }
 }

/**
* Cette méthode permet de savoir si la lettre est un y.
*
* @return boolean Vrai si y, faux sinon
*/
 public boolean estY() {
 }

 public static void main(String args[]) {
	  String maChaine = new String ("train");
	  /*
	  for (int i=0; i< maChaine.length(); i++){
		  char test = (char) maChaine.charAt(i);
		  if (test == 'a' || test == 'A' || test == 'e' || test == 'E' || test == 'i' ||test == 'I' || test == 'o' || test == 'O' || test == 'u' || test=='U'){ 
					maChaine.replace(test,"av"+test);
		  }else{
			  if (test=='y'){
					  char test2 = maChaine.charAt(i+1);
					  if (test2 == 'a' || test2 == 'A' || test2 == 'e' || test2 == 'E' || test2 == 'i' ||test2 == 'I' || test2 == 'o' || test2 == 'O' || test2 == 'u' || test2=='U')
					  {
					  }
					  else{
						  maChaine.replace(test,"av"+test);
					  }
				  
		  }
		//buffer.setCharAt(2,'4');
		//System.out.println(maChaine.charAt(i));
		}
	  }
	  maChaine = buffer.toString();
	  System.out.println(maChaine);
	  */
	  
   }
}
