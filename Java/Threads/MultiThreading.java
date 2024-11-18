import java.util.*;
import java.io.InterruptedIOException;
import java.lang.Thread;
//Implement a multithreaded program where one thread calculates the sum of an array and another thread finds the maximum value in the array.



class t1 extends Thread{
  int[] A;
  t1(int[] A){
    this.A=A;
  }
  public void run(){
    
      int sum=0;
      
      for(int i : A){
        sum+=i;
      }
      System.out.println("Sum is : "+sum);
    
  }
}

class t2 extends Thread{
  int[] A;
  t2(int[] A){
    this.A=A;
  }
  public void run(){
    
      int max=A[0];
      
      for(int i :A){
        if(i>max){
          max=i;
        }
      }

      System.out.println("Largest no: "+max);
    
  }
}








public class MultiThreading {
  public static void main(String[] args){
    try
    {
    Random rand=new Random();
    for(int j=0;j<10;j++){
    int n = rand.nextInt(0,50); 
    int[] A = new int[n];
    
      for(int i=0;i<n;i++){
        A[i]=(rand.nextInt(0,100));
      }
      System.out.println("Array contents: ");
        for (int num : A) {
            System.out.print(num + " ");
        }
        System.out.println();
      
      t1 threadone =new t1(A);
      t2 threadtwo = new t2(A);
      threadone.start();
      threadtwo.start();
      threadone.join();
      threadtwo.join();
      Thread.sleep(5000);
     
       }
      }catch(InterruptedException e){
    e.printStackTrace();
     }
    
     System.out.println("Main thread finished execution.");
    }
  }
  



