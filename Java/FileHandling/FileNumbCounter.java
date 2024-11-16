import java.io.*;
import java.util.Scanner;

public class FileNumbCounter{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String fileName = "output.txt"; // Name of the file to write to

        try {
            // Create a FileWriter in append mode
            FileWriter fileWriter = new FileWriter(fileName, true);
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

            System.out.println("Enter words to append to the file (type 'exit' to stop):");
            int count =0;
            while (true) {
                String word = scanner.nextLine();
                count++;
                // Exit condition
                if (word.equalsIgnoreCase("exit")) {
                    break;
                }

                // Write word to the file and add a newline
                bufferedWriter.write(word);
                bufferedWriter.newLine();
            }

            // Close resources
            bufferedWriter.close();
            System.out.println(count +" Words have been appended to " + fileName);

        } catch (IOException e) {
            System.out.println("An error occurred while writing to the file.");
            e.printStackTrace();
        } finally {
            scanner.close();
        }
    }
}
