 import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
 import java.io.FileReader;
 import java.io.FileWriter;

 import java.io.File;



 public class Reader{
  public static void main(String[] args) throws IOException {
 
    File file1 = new File("file1.txt");
    File file2 = new File("file2.txt");
    try {
      
      if (!file1.exists()) {
          file1.createNewFile();
          System.out.println("file1.txt has been created.");
          
      }
      if (!file2.exists()) {
        file2.createNewFile();
        System.out.println("file2.txt has been created.");
        
    }

   
    FileReader input =new FileReader(file1);
    FileWriter output=new FileWriter(file2);

    BufferedReader buffer = new BufferedReader(input);
    String line;
    
      do{
        line=buffer.readLine();
        
        if(line!=null){
          output.write(line);
          System.out.println(line);
          output.write(System.lineSeparator());
        }
      }while(line!=null);
            buffer.close();
            input.close();
            output.close();
            System.out.println("Content from file1.txt has been copied to file2.txt.");

      
    }catch(FileNotFoundException e){
      System.out.println("This file doesn't exist");

  }
  

  }
}