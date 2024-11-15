#include<stdio.h>
#include<stdlib.h>
#define maxsize 100;

struct Node{
  int data;
  struct Node *next;
};



struct Node* push(struct Node *head,int data){
  struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
  newnode->data=data;
  newnode->next=NULL;
  if(head==NULL){
    head=newnode; 
  }
  else{
    newnode->next=head;
    head=newnode;
  }
  return head;
}


int pop(struct Node *head){
  if(head==NULL){
    printf("Stack is empty");

  }
  else{
    struct Node *temp=head;
    head=head->next;
    temp->next=NULL;
    free(temp);
  }
}

void display(struct Node *head){
  if(head==NULL){
    printf("Stack Empty");
  }
  else{
    struct Node *temp=head;
    while(temp!=NULL){
      printf("%d->",temp->data);
    }
    printf("NULL");
  }
}

void main(){
  int choice=0,value;
  struct Node *head=NULL;
  while(choice!=4){
    printf("\nCHOOSE FROM BELOW\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
    printf("CHOICE:");
    scanf("%d",&choice);
    switch(choice){
      case 1: printf("Enter the value:");
              scanf("%d",&value);
              head=push(head,value);
              break;
      case 2: value=pop(head);
              printf("Removed value is:%d",value);
              break;
      case 3:display(head);
              break;
      case 4:printf("Exited");
              break;
      default:
              printf("Invalid Input");
    }
  }
}


