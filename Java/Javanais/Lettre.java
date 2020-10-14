import java.util.*;

public class Lettre {

	private static Character[] voyelles = {'a', 'e', 'i','o','u','y'};
	private Character lettre;

	/**
	* Le constructeur de la classe Lettre.
	*
	* @param N/A
	*/

	 public Lettre() {
		 lettre=' ';
	 }

	 public Lettre(char lettre) {
		 this.lettre = lettre;
	 }

	/**
	* Cette méthode permet de savoir si la lettre est une voyelle.
	*
	* @return boolean Vrai si voyelle, faux sinon
	*/

	 public boolean estVoyelle() {
	 	List<Character> list = Arrays.asList(Lettre.voyelles);
		return(list.contains(Character.toLowerCase(this.lettre)));
	 }

	/**
	* Cette méthode permet de savoir si la lettre est un y.
	*
	* @return boolean Vrai si y, faux sinon
	*/
	 public boolean estY() {
		 return (this.lettre=='y' || this.lettre=='Y');
	 }
	 
	 public boolean estUneLettre() {
		 return (( this.lettre >= 'A' && this.lettre <= 'Z') || (this.lettre >= 'a' && this.lettre <= 'z'));
	 }
	 
	 public boolean estMajuscule() {
		 return ((this.lettre >= 'A' && this.lettre <= 'Z'));
	 }
	 
	 public boolean estMinuscule() {
		 return ((this.lettre >= 'a' && this.lettre <= 'z'));
	 }

	 public char getLettre() {
		 return this.lettre;
	 }
	 public void setLettre(char lettre) {
		 this.lettre=lettre;
	 }

}

