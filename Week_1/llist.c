#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head;

struct Node* insert_beg(struct Node* head, int value){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    if(head==NULL){
      head=newnode;
      newnode->next=NULL;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
    return head;

}

struct Node* insert_end(struct Node* head, int value){
  struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
  newnode->data=value;
  if(head==NULL){
    head=newnode;
    newnode->next=NULL;
  }
  else{
    struct Node* temp=head;
    
    while(temp->next!=NULL);{
      temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
  }
  return head;
}

struct Node* insert_pos(struct Node* head,int value,int pos){
  struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
  newnode->data=value;
  if(head==NULL){
    head=newnode;
    newnode->next=NULL;
  }
  else{
    struct Node* temp=head,*prev=NULL;
    int i=1;
    while(i<pos){
      prev=temp;
      temp=temp->next;
      i++;
    }
    newnode->next=temp;
    prev->next=newnode;
    
  }
  return head;
}