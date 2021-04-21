import java.io.*;
import java.net.*;
/**
 * Classe ServeurSimple
 * Cette classe permet de créer un serveur pour communiquer avec un client TCP
 * @see ClientSimple
 * @version 1.0 
 */
public class ServeurSimple implements Runnable {

   private int port = 8888; 
   private ServerSocket socketServeur = null;
   private Socket socket = null;
   private Thread ma_tache;
   
/**
 * Constructeur par défaut
 * Les paramètres sont initialisés "en dur"
 */

   public ServeurSimple() {         
      try {  
         socketServeur = new ServerSocket( port );
         System.out.println("Bonjour, je suis le serveur\nJ'attends des clients sur le port " + socketServeur.getLocalPort());
      } 
      catch( IOException e ) {
         System.err.println( "Impossible de créer un ServerSocket" );
      }     
      while (true) {
         try {
            socket = socketServeur.accept();
         } 
         catch ( IOException e) {}
         ma_tache = new Thread(this);
         ma_tache.start();    
      }       
   }

   public void run() {
      try {
         System.out.println("Connexion acceptée : " + socket.getInetAddress());    
         BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));           
         while(true) {
            String message = in.readLine();
            if (message == null) 
               break;
            System.out.println(message);             
         }   
         socket.close();
         System.out.println("Le serveur ferme la socket avec le client");                  
      } 
      catch( IOException e ) {}
   }

   public static void main( String [] args ) {
      new ServeurSimple();
   }

}
 
