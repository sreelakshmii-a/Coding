import java.util.*;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;



public class oneFileToAnother {
  public static void main(String[]args){
  File file1=new File("C:\\Users\\ULTRABOOK\\Documents\\GitHub\\Coding_1\\Java\\File\\File1.txt");
  File file2=new File("C:\\Users\\ULTRABOOK\\Documents\\GitHub\\Coding_1\\Java\\File\\File2.txt");

  if(!file1.exists()){
    System.out.println("File1 doesn't exist");
    return;
  }
  try{
  if(!file2.exists()){
    file2.createNewFile();
    System.out.println("File2 created");
  }


BufferedReader bufferRead =new BufferedReader(new FileReader(file1));
BufferedWriter bufferWrite =new BufferedWriter(new FileWriter(file2));

 String line;

 while((line=bufferRead.readLine())!=null){
  
  bufferWrite.write(line);
  bufferWrite.newLine();
 }
 bufferWrite.flush();
 bufferRead.close();
 bufferWrite.close();
System.out.println("Sucessfully Copied");
  }catch (IOException e){
    e.printStackTrace();
  }
  
}
}
