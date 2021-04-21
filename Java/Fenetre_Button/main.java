public class main{
   public static void main (String args[]){
      for (int i=0;i < args.length; i++)
         System.out.println(args[i]);
      int largeur = 300;
      int hauteur = 200;
   
      try{
         if (args.length==2){
            largeur = java.lang.Integer.parseInt(args[0]);
            hauteur = java.lang.Integer.parseInt(args[1]);
            System.out.println(largeur);
            System.out.println(hauteur);
         }
      }
      catch (NumberFormatException e) {
         System.out.println("Exception");
         
      }
      Fenetre f = new Fenetre(largeur,hauteur);
   
   }
}
