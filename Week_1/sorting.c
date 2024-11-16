#include<stdio.h>
#define maxsize 100

int insertion(int a[maxsize],int n){
  int i,j,temp;
 
  for(i=1;i<n;i++){
    
     temp=a[i];
      j=i-1;
      while(j>=0 && a[j]>temp){
        a[j+1]=a[j];
        j--;
      }
      a[j+1]=temp;
  }
}



void insertionSort(int A[],int n){
  for(int i=0;i<n;i++){
    int j=i;
    int temp=A[i];
    while(j>0 && A[j-1]>temp){
      A[j]=A[j-1];
      j--;
    }
    A[j]=temp;
  }
}
void swap(int A[maxsize],int a, int b){}

void heapify(int A[],int n,int i){
  int largest=i;
  int lc=2*i;
  int rc=2*i+1;
  while(lc <=n && A[lc]>A[largest]){
    largest=lc;
  }
  while(rc<=n && A[rc]>A[largest]){
    largest=rc;
  }
  if(largest!=i){
    swap(A,A[largest],A[i]);
  }

}


void HeapSort(int A[],int n,int i){
  for(int i=(n/2);i>=1;i--){
    heapify(A,n,i);
  }
  for(int i=n;i>=1;i--){
    swap(A,A[i],A[1]);
    heapify(A,i,1);
  }
}