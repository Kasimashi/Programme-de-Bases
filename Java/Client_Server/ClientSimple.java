import java.io.*;
import java.net.*;

/**
 * Classe ClientSimple
 * Cette classe permet de cr�er un client pour communiquer avec un serveur TCP
 * @see ServeurSimple
 * @version 1.0 
 */
public class ClientSimple {

   private InetAddress hote;
   private int port;
   private Socket socket;
   
/**
 * Constructeur par d�faut
 * Les param�tres sont initialis�s "en dur"
 */
   public ClientSimple() {
      //initialisations
      this.hote = null;
      this.port = 8888;
      this.socket = null;
      //recuperation de l'adresse IP du serveur (votre machine)   
      try {
         hote = InetAddress.getByName("127.0.0.1");
      } 
      catch (UnknownHostException e) {}
          
      try { 
         socket = new Socket(hote, port);
         System.out.println("Connect� au serveur: " + socket.getInetAddress() + ":" + socket.getPort());
         //l'objet input contient le texte tap� sur la console
         BufferedReader input = new BufferedReader(new InputStreamReader(System.in)); 
         //l'objet output est ce qui transmis sur la socket
         PrintWriter output = new PrintWriter(socket.getOutputStream(),true);
         String message;
      	//acquisition via le clavier d'un message et envoi au serveur
         while(true) {
            message = input.readLine();
			if (message.equals("stop")){
				socket.close();
				break;
			}
            output.println(message);
         }
      } 
      catch(IOException e) {}
      try {
       //fermeture de la socket      
         socket.close();
      } 
      catch(IOException e) {}
   
   }

   public static void main( String [] args ) {
      new ClientSimple();
   }
   
}

