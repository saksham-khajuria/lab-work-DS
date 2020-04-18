//Doubly Linked List Implementation in C by Saksham Khajuria,IT ,11912058
#include<stdio.h>
#include<stdlib.h>

//Structure of Node
struct node{
    int data;
    struct node *left;
    struct node *right;
} *head;            //creating a global node HEAD

//Creating n nodes
void createNode(int n){
    head = (struct node*)malloc(sizeof(struct node));
    int data,i;
    printf("Enter data for head node:");
    scanf("%d",&data);
    struct node *temp;
    temp=head;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    for(i = 1;i<n;i++){         //Linking new nodes
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the value of new node");
        scanf("%d",&data);
        newNode->data = data;
        newNode->right = NULL;
        newNode->left = temp;
        temp->right = newNode;
        temp = temp->right;
    }
    printf("Doubly Linked List with %d nodes created",n);
}

//Traversing the list
void traverse(){
    struct node *temp = head;
    int i = 1;
    while(temp){
        printf("Data at node %d = %d\n",i,temp->data);
        i++;
        temp = temp->right;
    }
}

//Deleting a node with data n
void deleteNode(int n){
    struct node *temp = head;
    while(temp->right->data != n){
        temp = temp->right;
    }
    struct node *del = temp->right;
    temp->right = del->right;
    free(del);
    del = NULL;
}

int main(){
    int n;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    createNode(n);          //creating n nodes
    printf("\nEnter the data of the node to be deleted:\n");
    scanf("%d",&n);
    printf("Before deletion\n");
    traverse();
    deleteNode(n);          //deleting the node with n data
    printf("\nAfter Deletion\n");
    traverse();             //printing the list

    return 0;
}
