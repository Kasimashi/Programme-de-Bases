import java.io.*;

public class BufferReader {
   public static void main (String[] args) {
      int firstNum, secondNum, result;
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      try {
         System.out.println("Enter a first number:");
         firstNum = Integer.parseInt(br.readLine());
         System.out.println("Enter a second number:");
         secondNum = Integer.parseInt(br.readLine());
         result = firstNum * secondNum;
         System.out.println("The Result is: " + result);
      } catch (IOException ioe) {
         System.out.println(ioe);
      }
   }
}
