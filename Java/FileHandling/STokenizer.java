import java.util.*;
import java.io.IOException;

public class STokenizer {
  public static void main(String[] args){
    Scanner s= new Scanner(System.in);
   
    System.out.println("Enter a line of integers:");
    String line=s.nextLine();
    StringTokenizer tokens = new StringTokenizer(line);
    
  
    int sum=0;
    do{
      try{
      String number =tokens.nextToken();
      System.out.println(number);
      int token = Integer.parseInt(number);
      sum += token;
      }catch(NumberFormatException e){
        
        System.err.println("Invalid Input:");
      }
      
    }while(tokens.hasMoreTokens());

    System.out.println("SUM"+sum);
  }
}
