#include<stdio.h>
#define max 100
int q[max];
int front=-1,rear=-1;

void enqueue(int q[],int value){
  if(rear== (max-1)){
    printf("Queue is full");
  }
  else if(front==-1 && rear==-1)
  {
    rear++;
    front++;
    q[rear]=value;
  }
  else{
    rear++;
    q[rear]=value;
  }
}

int dequeue(int q[]){
  if(front==-1 && rear==-1){
   return -1;
  }
  else if(front==rear){
    int value;
    value=q[front];
    front=rear=-1;
    return value;
  }
  else{
    int value;
    value=q[front++];
    return value;
  }
}

void display(int q[]){
  if(front==-1 && rear==-1){
    printf("Queue Empty");
  }
  else{
  for(int i=front;i<=rear;i++){
    printf("%d\t",q[i]);
  }
  }
}


void main(){
  int choice=0,value;
  while(choice!=4){
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        printf("Enter the value to be inserted");
        scanf("%d",&value);
        enqueue(q,value);
        break;
        case 2:
        value=dequeue(q);
        if(value==-1){
          printf("Queue Empty");
        }
        else{
        printf("Removed Element:%d",value);
        }
        break;
        case 3:
        display(q);
        break;
        default:
        printf("Invalid Input");

    }
    
  }
}
