
import java.util.Random;
import java.io.InterruptedIOException;

class thread1 extends Thread{
  Random randomobj = new Random(1000);
  
  public void run() {
    try{
    for(int i=0;i<10;i++){
      int number=ramndomobj.nextInt(10);
      System.out.println("Number is:"+ number);
    
  if(number%2==0){
    thread2 t2=new thread2(number);
    t2.start();
   
  }
  else{
    
    thread3 t3 =new thread3(number);
    t3.start();
  }Thread.sleep(i);
}
    }catch(InterruptedException e){
      e.printStackTrace();
    }
}
}


class thread2 extends Thread{
  int number;
  public thread2(int number){
    this.number=number;
  }
    public void run(){
   System.out.println("It's Square: "+number*number);
  
    
  }
}

class thread3 extends Thread{
  int number;
  public thread3(int number){
    this.number=number;
  }
  public void run(){
    System.out.println("It's Cube: "+number*number*number);
  }
}


  public class MultiThreading {
  public static void main(String[] args){
  thread1 t1=new thread1();
  t1.start();
  

  }
}
// unchecked exception comes under RunTimeException while chechked Exceptions comes under Exception class