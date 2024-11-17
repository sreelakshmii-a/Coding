import java.util.*;
import java.io.IOException;

public class ArrayOutOfBound {
  public static void main(String[]args){
    Scanner s=new Scanner(System.in);
    int[] A=new int[10];
    System.out.println("Enter an array of 10 numbers");
    for(int i=0;i<10;i++){
      A[i]=s.nextInt();
    }
    try{
      System.out.println("Enter the index of an element you want to retrieve");
    int i=s.nextInt();
    
      System.out.println("The element is: "+A[i]);
    }catch(ArrayIndexOutOfBoundsException e){
      System.out.println("Give an index which is less than 10");
    
    }
    System.out.println("Program Executed");
    s.close();
  }
}
