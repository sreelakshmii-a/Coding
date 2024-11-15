#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *lc;
    struct node *rc;
};

struct node *root = NULL, *parent, *ptr1;

void insert();
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void deleteNode(int);
void search(int);
struct node* succ(struct node*);

int main() {
    int ch, key;
    do {
        printf("\n1. Insertion\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Deletion\n6. Search\n7. EXIT\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert();
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
                printf("Enter the element to delete from the tree: ");
                int del;
                scanf("%d", &del);
                deleteNode(del);
                break;
            case 6:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    } while (1);

    return 0;
}

void insert() {
    int item;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element to insert: ");
    scanf("%d", &item);
    p->data = item;
    p->rc = NULL;
    p->lc = NULL;

    if (root == NULL) {
        root = p;
    } else {
        struct node *ptr = root;
        while (ptr != NULL) {
            parent = ptr;
            if (item < ptr->data) {
                ptr = ptr->lc;
            } else {
                ptr = ptr->rc;
            }
        }
        if (item < parent->data) {
            parent->lc = p;
        } else {
            parent->rc = p;
        }
    }
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->lc);
        printf("%d\t", root->data);
        inorder(root->rc);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->lc);
        preorder(root->rc);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->lc);
        postorder(root->rc);
        printf("%d\t", root->data);
    }
}

void deleteNode(int it) {
    int flag = 0;
    struct node *ptr = root;
    while (ptr != NULL) {
        if (it < ptr->data) {
            parent = ptr;
            ptr = ptr->lc;
        } else if (it > ptr->data) {
            parent = ptr;
            ptr = ptr->rc;
        } else {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("Element not found, hence deletion not possible\n");
    } else {
        if (ptr->lc == NULL && ptr->rc == NULL) { // Case 1: No children
            if (parent->lc == ptr) {
                parent->lc = NULL;
            } else {
                parent->rc = NULL;
            }
            free(ptr);
        } else if (ptr->lc != NULL && ptr->rc != NULL) { // Case 2: Two children
            ptr1 = succ(ptr);
            int succData = ptr1->data;
            deleteNode(ptr1->data);
            ptr->data = succData;
        } else { // Case 3: One child
            struct node *child = (ptr->lc != NULL) ? ptr->lc : ptr->rc;
            if (parent->lc == ptr) {
                parent->lc = child;
            } else {
                parent->rc = child;
            }
            free(ptr);
        }
    }
}

struct node *succ(struct node *ptr) {
    struct node *ptr1 = ptr->rc;
    while (ptr1 && ptr1->lc != NULL) {
        ptr1 = ptr1->lc;
    }
    return ptr1;
}

void search(int key) {
    int flag = 0;
    struct node *pt = root;
    while (pt != NULL) {
        if (pt->data == key) {
            flag = 1;
            break;
        } else if (key < pt->data) {
            pt = pt->lc;
        } else {
            pt = pt->rc;
        }
    }
    if (flag == 0) {
        printf("Key not found\n");
    } else {
        printf("Key found\n");
    }
}
