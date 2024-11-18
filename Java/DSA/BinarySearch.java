import java.util.*;
 class search{
  int[] A;
  int n,key;
  search(int[] A,int n,int key){
    this.A=A;
    this.n=n;
    this.key=key;
  }

  public int ToSearch(){
    int low=0;
    int high =n-1;
    
    while(low<=high){
      int mid=(low+high)/2;
      if(A[mid]>key){
        high=mid-1;
      }
      else if(A[mid]<key){
        low=mid+1;
      }
      else{
        return mid;
      }
     
    }
    return -1;
    
  }

 }


class Sort{
  int[] A;
  int n;
  Sort(int[] A,int n){
 this.A=A;
 this.n=n;
    

  }
  public void sorting(){
    int i,j,temp;
    for (i = 0; i < n - 1; i++) {
     
      for (j = 0; j < n - i - 1; j++) {
          if (A[j] > A[j + 1]) {
              
              temp = A[j];
              A[j] = A[j + 1];
              A[j + 1] = temp;
          }
      }
  }
  }
}





public class BinarySearch {
  public static void main(String[]args){
    Scanner s=new Scanner(System.in);
    System.out.println("Enter the number of elements");
    int n =s.nextInt();
    int[] A=new int[n];
    System.out.println("Enter the array");
    for(int i=0;i<n;i++){
      A[i]=s.nextInt();
    }
    System.out.println("The array is");
    for(int i:A){
      System.out.println(i);
    }
    Sort S=new Sort(A,n);
    S.sorting();
    System.out.println("Enter the search element");
    int key=s.nextInt();
   search sh=new search(A,n,key);
   int mid=sh.ToSearch();
   if(mid==-1){
    System.out.println("Element not found");
   }
   else{
    System.out.println("Element  found");
   }
   }
    
  }





