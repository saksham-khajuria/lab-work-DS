//Program to Count Leaf nodes and Non-Leaf Nodes by Saksham Khajuria,IT, 11912058
#include<stdio.h>
#include<stdlib.h>

//Structure of tree node
struct node{
    int data;
    struct node *left;
    struct node *right;
};

//returns a new node
struct node *createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//total number of nodes
int count(struct node *tree){
    int number = 0;
    if(tree == NULL){return number;}
    else{
        number = 1+count(tree->left)+count(tree->right);
    }
    return number;
}

//number of leaf nodes
int countLeaves(struct node *tree){
    if(tree == NULL){return 0;}
    else if(tree->left == NULL && tree->right == NULL)
    {
        return 1;
    }
    return countLeaves(tree->left)+countLeaves(tree->right);
}

int main(){
    struct node *tree = createNode(2);
    tree->left = createNode(4);
    tree->right = createNode(5);
    tree->right->right = createNode(3);
    tree->right->left = createNode(7);
    tree->left->right = createNode(8);
    int nonleaves = count(tree)-countLeaves(tree);
    printf("The number of Leaves in the Tree = %d\n",countLeaves(tree));
    printf("Number of non-leaves in the tree  = %d\n",nonleaves);

}
