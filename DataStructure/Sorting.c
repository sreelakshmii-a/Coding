#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define size 100000

void fill(int A[]){
  for(int i=0;i<size;i++){
    A[i]=rand();
  }
}
void swap(int A[],int x,int y){
  int temp;
  temp=A[x];
  A[x]=A[y];
  A[y]=temp;
  

}

void SelectionSort(int A[],int n){
  int i,j,min;
  for(i=0;i<n-1;i++){
    min=i;
    for(j=i+1;j<n;j++){
      if(A[j]<A[min]){
        min=j;
      }
    }
    if(min!=i){
      int temp;
       temp=A[i];
       A[i]=A[min];
       A[min]=temp;
    }
  }
}


void Insertion(int A[],int n){
  int i,j,temp;
  for(i=1;i<n;i++){
    temp=A[i];
    j=i-1;
    while(j>=0 && A[j]>temp){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=temp;
  }
}



int Partition(int A[],int lb,int ub){
  int pivot=A[lb];
  int start=lb;
  int end=ub;
  while(start<end){
      while(A[start]<=pivot){
        start++;
      }
      while(A[end]>pivot){
        end--;
      }
      if(start<end){
        int temp;
       temp=A[start];
       A[start]=A[end];
       A[end]=temp;
      }

  }
   int temp;
  temp=A[lb];
  A[lb]=A[end];
  A[end]=temp;
  return end;
}
void Quick(int A[],int lb,int ub){
  
  if(lb<ub){
    int pivloc;
    pivloc=Partition(A,lb,ub);
    Quick(A,lb,pivloc);
    Quick(A,pivloc+1,ub);
  }
}



void Merge(int A[],int lb,int mid,int ub){
  int* B = (int*)malloc((ub - lb + 1) * sizeof(int));
  int i,j,k;
  i=lb;
  j=mid +1;
  k=0;
  while(i<=mid && j<=ub){
    if(A[i]<=A[j]){
      B[k++]=A[i++];
      
    }
    else{
      B[k++]=A[j++];
     
    }
    

  }
  while (i <= mid) {
        B[k++] = A[i++];
    }

    
    while (j <= ub) {
        B[k++] = A[j++];
    }

  for(k=0;k<=(ub-lb);k++){
    A[lb+k]=B[k];
  }
}
void  MergeSort(int A[],int lb,int ub){
  if(lb<ub){
    int mid=(lb+ub)/2;
    MergeSort(A,lb,mid);
    MergeSort(A,mid+1,ub);
    Merge(A,lb,mid,ub);
  }
}


void MaxHeapify(int A[],int n,int i){
  int largest =i;
  int l=2*i+1;
  int r=2*i+2;
  if(l<n && A[l]>A[largest]){
    largest=l;
  }
  if(r<n&& A[r]>A[largest]){
    largest=r;
  }
  if(largest!=i){
    swap(A,i,largest);
    MaxHeapify(A,n,largest);
  }
}

void heapSort(int A[],int n){
  
  for(int i=(n/2)-1;i>=0;i--){
    MaxHeapify(A,n,i);
  }
  for(int i =n-1;i>=0;i--){
    swap(A,0,i);
    MaxHeapify(A,i,0);
  }
}




void display(int A[],int n){
   int i;
   for(i=0;i<n;i++){
    printf("%d\t",A[i]);
  }
}



int main(){
  int n=size,i,lb,ub;
  clock_t start,end;
  double time;
  int A[size];
  


  //SelectionSort
  fill(A);
  start=clock();
  SelectionSort(A,size);
  end=clock();
  
  time=(double)(end-start)/CLOCKS_PER_SEC;
  printf("TIME COMPLEXITY FOR SELECTION SORT IS %f\n",time);

 //INSERTIONSORT
  fill(A);
  start=clock();
  Insertion(A,size);
  end=clock();
  
  time=(double)(end-start)/CLOCKS_PER_SEC;
  printf("TIME COMPLEXITY FOR INSERTION SORT IS %f\n",time);


  //QUICKSORT
  fill(A);
  lb=0;
  ub=n;
  start=clock();
  Quick(A,lb,ub);
  end=clock();
  
  time=(double)(end-start)/CLOCKS_PER_SEC;
  printf("TIME COMPLEXITY FOR QUICK SORT IS %f\n",time);


  //MERGESORT
  fill(A);
  lb=0;
  ub=n;
  start=clock();
  MergeSort(A,lb,ub);
  end=clock();
  
  time=(double)(end-start)/CLOCKS_PER_SEC;
  printf("TIME COMPLEXITY FOR MERGE SORT IS %f\n",time);

  //HEAPSORT
  fill(A);
  start=clock();
  heapSort(A,size);
  end=clock();
 
  time=(double)(end-start)/CLOCKS_PER_SEC;
  printf("TIME COMPLEXITY FOR HEAP SORT IS %f\n",time);

  return 0;

}