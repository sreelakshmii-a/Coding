import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

import java.io.File;


public class Stream {
  public static void main(String[] args)throws IOException{
    FileInputStream input=null;
    FileOutputStream output=null;

    try{
     


      File file1 =new File("C:/Users/ULTRABOOK/Documents/GitHub/Coding_1/Java/FileHandling/file1.txt");
      File file2 =new File("C:/Users/ULTRABOOK/Documents/GitHub/Coding_1/Java/FileHandling/file2.txt");
      if(!file1.exists()){
        file1.createNewFile();
        System.out.println("file1.txt has been created.");
      }
      if(!file2.exists()){
        file2.createNewFile();
        System.out.println("file2.txt has been created.");
      }
      input =new FileInputStream("C:/Users/ULTRABOOK/Documents/GitHub/Coding_1/Java/FileHandling/file1.txt");
      output =new FileOutputStream("C:/Users/ULTRABOOK/Documents/GitHub/Coding_1/Java/FileHandling/file2.txt");
      int ch;
      do{
        
        ch=input.read();
        if(ch!=-1){
          output.write((char)ch);
          System.out.println((char)ch);
        }
      }while(ch!=-1);
      System.out.println("\nFile copy completed successfully!");
    }catch(IOException e){
        System.out.println("No file exist");
    }
    finally {
     
          if (input != null) input.close();
          if (output != null) output.close();
      } 
  }
}

