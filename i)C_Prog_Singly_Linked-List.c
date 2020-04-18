//Linked List Implementation in C by Saksham Khajuria,IT, 11912058
#include<stdio.h>
#include<stdlib.h>

//Structure of Node
struct node{
    int data;
    struct node *link;
} *head;


//Creating a list
void createNode(int n){
    int data,i;
    struct node *temp;
    head = (struct node*)malloc(sizeof(struct node));
    if(head == NULL){
        printf("Head Node not created");
        return;
    }
    printf("Enter Data for head node:");
    scanf("%d",&data);
    head->data = data;
    head->link = NULL;
    temp = head;
    for(i = 1;i<n;i++){                         //Linking the nodes
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the value of next node:");
        scanf("%d",&data);
        newNode->data = data;
        temp->link = newNode;
        newNode->link = NULL;
        temp = temp->link;
    }
    printf("List with %d nodes created\n",n);
}

//Program to Traverse a List
void traverse(){
    struct node* temp = head;
    int i = 1;
    while(temp){
        printf("Data at %d node = %d\n",i,temp->data);
        i++;
        temp = temp->link;
    }
}

//Program to Delete a Node
void deleteNode(int n){
    struct node *temp = head;
    while(temp->link->data != n){
        temp = temp->link;
    }
    struct node *del = temp->link;
    temp->link = del->link;
    free(del);
    del = NULL;
}

int main(){
    int n;
    printf("Enter the number of nodes to be created:");
    scanf("%d",&n);
    createNode(n);          //creating n nodes
    printf("Before Deletion:\n");
    traverse();     
    printf("\nEnter the node data to be deleted:\n");
    scanf("%d",&n);
    deleteNode(n);          //deleting the node with the data n
    printf("After Deletion\n");
    traverse();             //printing the list
    return 0;
}
