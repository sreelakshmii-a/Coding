#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};
struct Node *head=NULL,*rear=NULL;



void Enqueue(int value){
  struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
  newnode->data=value;
  newnode->next=NULL;
  if(head==NULL && rear==NULL){
      head=rear=newnode;
      
  }
  else{
    rear->next=newnode;
    rear=newnode;
    
  }
  
}

int Dequeue(){
  if(head==NULL){
    return -1;
  } 
  else{
    struct Node  *temp=head;
    int x;
    x= temp->data;
    head=head->next;
    free(temp);
    return x;
  } 
}

  void display(){
    if(head==NULL){
      printf("The queue is empty");
      
    }
    else{
      struct Node* temp=head;
      while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
      }
      
    printf("\n");
  }

}


int main(){
  int op,value;
  
  while(1){
    printf("CHOOSE FROM BELOW:\n 1.ENQUEUE\n 2.DEQUEUE\n 3.DISPLAY\n4.EXIT ");
    scanf("%d",&op);
    switch(op){
      case 1:
        printf("Enter the value:");
        scanf("%d",&value);
        Enqueue(value);    
        printf("Value has been entered");
        break;
      case 2:
        value=Dequeue();
        if(value==-1){
          printf("Queue Empty");
        }
        else{
          printf("%d removed",value);
        }
        break;
      case 3:
        display();
        break;
      case 4:
        exit(0);
      default:
        printf("INVALID INPUT");
        break;
   }
  }
  return 0;
}


