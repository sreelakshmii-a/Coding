import java.util.*;

class ReadMat{
  int rows,cols;
  ReadMat(int rows,int cols){
    this.rows=rows;
    this.cols=cols;
  }
  void read(int A[][]){
    
    Scanner s=new Scanner(System.in);
    System.out.println("Enter the elements\n");    
    for(int i=0;i<rows;i++){
      for(int j=0;j<cols;j++){
        A[i][j]=s.nextInt();
      }
    }
  }
  void display(int A[][]){
    for(int i=0;i<rows;i++){
      for(int j=0;j<cols;j++){
        System.out.print(A[i][j]+" ");
      }
      System.out.println();
    }
  }

  

  


}

class Mult{
  int rows1,cols1,rows2,cols2;
  int[][] A,B,M;



  Mult(int[][] A, int rows1, int cols1, int[][] B, int rows2, int cols2){
    this.A = A;
        this.B = B;
        this.rows1 = rows1;
        this.cols1 = cols1;
        this.rows2 = rows2;
        this.cols2 = cols2;
        this.M=new int[rows1][cols2];
  }
  public  void mult(int row1,int cols2){
    if(cols1!=rows2){
      System.out.println("Cannot Multiply");
    
    }
    else{
      for(int i=0;i<rows1;i++){
        for(int j=0;j<cols2;j++){
          M[i][j]=0;
          for(int k=0;k<cols1;k++){
            M[i][j]+=A[i][k]*B[k][j];
          }
        }
      }
    }
    ReadMat obj=new ReadMat(rows1, cols2);
   
    System.out.println("RESULTANT MATRIX");
    
    obj.display(M);
    
  }
}

public class MatMulti {
  public static void main(String args[]){
    Scanner s = new Scanner(System.in);
    System.out.println("Enter the number of rows and columns of MAT1");
    int rows1=s.nextInt();
    int cols1=s.nextInt();
    int A[][]=new int[rows1][cols1];
    ReadMat mat1=new ReadMat(rows1,cols1);
    mat1.read(A);
    mat1.display(A);


    System.out.println("Enter the number of rows and columns of MAT2");
    int rows2=s.nextInt();
    int cols2=s.nextInt();
    int B[][]=new int[rows2][cols2];
    ReadMat mat2=new ReadMat(rows2,cols2);
    mat2.read(B);
    mat2.display(B);

    
    Mult product =new Mult(A,rows1,cols1,B,rows2,cols2);
    product.mult(rows1,cols2);
  }
  
}
