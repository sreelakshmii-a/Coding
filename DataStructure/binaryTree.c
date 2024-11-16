#include<stdio.h>
#include<stdlib.h>
#define maxsize 10;
int q[maxsize];
int front,rear;
front = -1;
rear=-1;

void enqueue(int value){
    if(rear==maxsize-1){
        return NULL;
    }
    else if(front=-1){
        front=rear=0;
        q[front]=value;
        
        
    }
    else{
        rear++;
        q[rear]=value;
        
    }
    
}

struct Node* dequeue(){
    if(front==-1||front>rear){
        return -1;
    }
    else if(front==rear){
        int value=q[front];
        front=rear=-1;
        return value;
    }
    else{
        int value=q[front];
        front++;
        return value;
    }
    
}

struct Node{
    int data;
    struct Node *lc;
    struct Node *rc;
};

struct Node* create(struct Node *root,int value){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->lc=newnode->rc=NULL;
    if(root==NULL){
        root=newnode;
        enqueue(root);
        return root;
    }
    while(front<=rear){
        struct Node *node=dequeue();
        if(node->lc!=NULL&&node->rc!=NULL){
            enqueue(node->lc);
            enqueue(node->rc);

        }
        else if(node->lc==NULL){
            node->lc=newnode;
        }
        else{
            node->rc=newnode;
        }
    }return root;
    

}