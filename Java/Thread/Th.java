public class Th implements Runnable{
   public Thread fen;
   public Th(){
      fen = new Thread(this);
   }   
   public void start(){
      fen.start();
   }
   public void run(){
      String texte = " On s'en branle Marcel !! ";
      for (int c=0;c<texte.length();c++){
         try {
            System.out.print(texte.charAt(c));
            Thread.sleep(1000);
         } catch (InterruptedException e) {
            Thread.currentThread().interrupt();  // set interrupt flag
            System.out.println("Failed to compute sum");
         }
      }
      System.out.println();
   }
}
