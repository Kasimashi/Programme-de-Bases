import java.io.*;
import java.util.Scanner; 

public class Regex {
    public static void main(String[] args) {
    
          String regex = "[A-Z]{2}[0-9]{9}[A-Z]";
          Scanner input = new Scanner(System.in);
	      
          System.out.println("Entrez Deux majuscule, neuf chiffre et une majuscule");              
          
          String s = input.nextLine();
          
          System.out.println(s.matches(regex)); 
          }      
}
