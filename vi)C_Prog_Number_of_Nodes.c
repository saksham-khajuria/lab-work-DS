//Calculate the number of nodes in tree by Saksham Khajuria, IT, 11912058
#include<stdio.h>
#include<stdlib.h>

//Structure of Tree Node
struct node{
    int data;
    struct node *left;
    struct node *right;
};

//returns a new Node 
struct node *createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Count the nodes by recursion
int count(struct node *tree){
    int number = 0;
    if(tree == NULL){return number;}
    else{
        number = 1+count(tree->left)+count(tree->right);
    }
    return number;
}

int main(){
    struct node *tree = createNode(2);
    tree->left = createNode(4);
    tree->right = createNode(5);
    tree->right->right = createNode(3);
    tree->right->left = createNode(7);
    tree->left->right = createNode(8);
    printf("The number of nodes in the Tree = %d\n",count(tree));

}
