import java.util.*;

public class Pal{
  public static void main(String[] args){
    Scanner s= new Scanner(System.in);
    System.out.println("Enter a word:");
    String word=s.nextLine();
    word=word.toLowerCase();
    int n =word.length();
    int i=0,j=n-1,flag=0;
    boolean isPal=true;
    while(i<j){
      if(word.charAt(i)!=word.charAt(j)){
        isPal=false;
        break;
      }
      i++;
      j--;
    }
    if(isPal){
      System.out.println("The word is Palindrome");
    }
    else{
      System.out.println("The word is not Palindrome");
    }
    s.close();
    }
}
