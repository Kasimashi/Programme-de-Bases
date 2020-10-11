import java.util.*;

public class Lettre {
	public static void main(String args[]) {}
	
	private static Character[] voyelles = {'a', 'e', 'i','o','u','y','A','E','I','O','U','Y'}; 

	/**
	* Le constructeur de la classe Lettre.
	*
	* @param N/A
	*/
	 
	 public Lettre() {
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
	 public static boolean estY(char y) {
		 if (y=='y' || y =='Y') {
			 return true;
		 }
		 return false;
	 }
	
	 public void finalize() //Objet récolté par le Garbage Collector --> Le destructeur n'existe pas en Java.
	 {
	      System.out.println("Objet nettoyé de la mémoire");  
	 }
}
