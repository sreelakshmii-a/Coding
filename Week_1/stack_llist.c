#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to push an element onto the stack
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to display the stack
void display(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = *top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
   
}

int  main() {
  struct Node* stack = NULL;
  int flag=0,value;
  while(flag!=1){
    int op;
    printf("CHOOSE AN OPTION\n");
    printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
    scanf("%d",&op);
    switch(op){
        case 1:
              printf("Enter the element to be inserted:");
              scanf("%d",&value);
              push(&stack, value);
              printf("Element has been inserted\n");
              break;
        case 2:
              value=pop(&stack);
              if(value!=-1){
                  printf("%d is removed",value);
              }
              
              break;
        case 3:
              display(&stack);
              break;
        case 4:
              printf("Program Exited");
              flag=1;
              break;
             
        default:
              printf("Invalid option");

            




    }
  }
   return 0;
}