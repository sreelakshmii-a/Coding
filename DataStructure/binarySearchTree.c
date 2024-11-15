#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *rc;
  struct node *lc;
};
struct node* Create(int data){
  struct node *newnode=(struct node*)malloc(sizeof(struct node)); 
  newnode->data=data;
  newnode->lc=newnode->rc=NULL;
  return newnode;
}
struct node* Insert(struct node *root,int data){
  if(root==NULL){
     root=Create(data);
  }
  else if(data < root->data){
    root->lc=Insert(root->lc,data);
  }
  else{
    root->rc=Insert(root->rc,data);
  }
  return root;
}


void inorder(struct node *root){
  if(root!=NULL){
    inorder(root->lc);
    printf("%d\t",root->data);
    inorder(root->rc);
  }
}

void preorder(struct node *root){
  if(root!=NULL){
    printf("%d\t",root->data);
    preorder(root->lc);
    preorder(root->rc);
  }
}

void postorder(struct node *root){
  if(root!=NULL){
    postorder(root->lc);
    postorder(root->rc);
    printf("%d\t",root->data);
  }
}

struct node* search(struct node *root,int data){
  struct node *ptr=root;
  while(ptr!=NULL){
    if(ptr->data == data){
      return ptr;
    }
    else if(ptr->data>data){
      ptr=ptr->lc;
    }
    else{
      ptr=ptr->rc;
    }
  }
return NULL;
  
  
  
} 















void main(){
  int a,choice=0;
  struct node *root=NULL;


  while(choice!=7){
    printf("\nCHOOSE FROM BELOW\n1.INSERT\n2.IN-ORDER\n3.PRE-ORDER\n4.POST-ORDER\n5.SEARCH\n6.DELETE\n7.EXIT\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    int element;
    struct node *key;
    switch(choice){
      case 1:
        
        printf("Enter the element to be added:");
        scanf("%d",&element);
        root=Insert(root,element);
        break;
      case 2:
        inorder(root);
        break;

      case 3:
        preorder(root);
        break;
      case 4:
        postorder(root);
        break;
      case 5:
        
        printf("Enter the element to be searched:");
        scanf("%d",&element);
        key=search(root,element);
        if(key==NULL){
          printf("Element not exist");
        }
        else{
          printf("Element found");
        }
        break;
      default:
        printf("Invalid Input");

    }
  }

}
