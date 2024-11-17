import java.util.*;

public class Occurence {
  public static void main(String args[]){
    Scanner s=new Scanner(System.in);
    System.out.println("Enter a word");
    String word=s.next();
    word=word.toLowerCase();
    System.out.println("Enter the char");
    char ch=s.next().charAt(0);
    int count=0;
    int n=word.length();
    for(int i=0;i<n;i++){
      if(word.charAt(i)==ch){
        count++;
      }
    }
    if(count==0){
      System.out.println("Occurance is 0");
    }
    else{
      System.out.println("Occurance is "+count);
    }
    s.close();
  }
}
