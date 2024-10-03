#include<stdio.h>
#include<stdlib.h>

struct term{
    int coeff;
    int exp;
    struct term *next;


};


struct term *insert(struct term *head,struct term *newnode){
  if(head==NULL){
    return newnode;
  }
  struct term *temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=newnode;
  return head;
}

struct term *create(struct term *head){
  int m,i;
  printf("Enter the number of terms in the polynomial:\n");
  scanf("%d",&m);
  printf("(Make sure it is in the decreasing exponent form!!!)");
  
  for(i=0;i<m;i++){
    struct term *newnode = (struct term *)malloc(sizeof(struct term ));
    newnode->next=NULL;
    printf("Coefficient:");
    scanf("%d",&newnode->coeff);
    printf("Power");
    scanf("%d",&newnode->exp);
    head=insert(head,newnode);
    
  }

  return head;
}

struct term *add(struct term *poly1,struct term *poly2){
    struct term *head=NULL;
    while (poly1 != NULL && poly2 != NULL) {

    struct term *newnode = (struct term *)malloc(sizeof(struct term ));
    newnode->next=NULL;
    if (poly1->exp > poly2->exp) {

      newnode->exp = poly1->exp;
      newnode->coeff = poly1->coeff;

      poly1 = poly1->next;

    } else if (poly2->exp > poly1->exp) {

      newnode->exp = poly2->exp;
      newnode->coeff = poly2->coeff;

      poly2 = poly2->next;

    } else {

      newnode->exp = poly1->exp;
      newnode->coeff = poly1->coeff + poly2->coeff;

      poly1 = poly1->next;
      poly2 = poly2->next;
    }

    head = insert(head, newnode);
  }
  while (poly1 != NULL) {
        struct term *newnode = (struct term *)malloc(sizeof(struct term));
        newnode->exp = poly1->exp;
        newnode->coeff = poly1->coeff;
        newnode->next = NULL;
        head = insert(head, newnode);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        struct term *newnode = (struct term *)malloc(sizeof(struct term));
        newnode->exp = poly2->exp;
        newnode->coeff = poly2->coeff;
        newnode->next = NULL;
        head = insert(head, newnode);
        poly2 = poly2->next;
    }


 

  return head;
}


struct term *multi(struct term *poly1, struct term *poly2){
    struct term *head = NULL;
    struct term *start2 = poly2; 

    while(poly1 != NULL){
        poly2 = start2; 

        while(poly2 != NULL){
            struct term *newnode = (struct term*)malloc(sizeof(struct term));
            newnode->coeff = poly1->coeff * poly2->coeff;
            newnode->exp = poly1->exp + poly2->exp;
            newnode->next = NULL;

           
            if (head == NULL) {
                head = newnode; 
            } else {
                struct term *temp = head;
                struct term *prev = NULL;

               
                while (temp != NULL && temp->exp > newnode->exp) {
                    prev = temp;
                    temp = temp->next;
                }

               
                if (temp != NULL && temp->exp == newnode->exp) {
                    temp->coeff += newnode->coeff;
                    free(newnode);
                } else {
                    
                    if (prev == NULL) {
                        
                        newnode->next = head;
                        head = newnode;
                    } else {
                        
                        newnode->next = prev->next;
                        prev->next = newnode;
                    }
                }
            }

            poly2 = poly2->next;
        }

        poly1 = poly1->next;
    }

    return head;
}





void display(struct term *head){
  struct term *temp=head;
  while(temp!=NULL){
    printf("%dx^%d\t",temp->coeff,temp->exp);
    temp=temp->next;
    if (temp != NULL)
      printf("+ ");
  }
}


int main(){
  int op;
  printf("CHOOSE FROM BELOW\n 1.ADDITION\n 2.MULTIPLICATION\n");
  struct term *p1=NULL,*p2=NULL,*p3=NULL,*p4=NULL;
  scanf("%d",&op);
  
  switch(op){
    case 1:
        printf("Enter the first polynomial:\n");
        p1=create(p1);
        printf("Enter the second polynomial:\n");
        p2=create(p2);
        p3=add(p1,p2);
       printf("The resulting polynomial after addition is:\n");

        display(p3);
        break;
    case 2:
        printf("Enter the first polynomial:\n");
        p1=create(p1);
        printf("Enter the second polynomial:\n");
        p2=create(p2);
        p4=multi(p1,p2);
        printf("Reultant polynomial is\n");
        display(p4);
        break;
    case 3:
        exit(0);
    default:
      printf("Invalid Input");
        

  }
  return 0;
  }



