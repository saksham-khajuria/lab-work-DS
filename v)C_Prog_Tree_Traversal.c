//Tree Traversal in C by Saksham khajuria, IT, 11912058
#include<stdio.h>
#include<stdlib.h>

//Structure of Tree Node
struct node{
    char data;
    struct node* left;
    struct node* right;
};

//create a new node 
struct node* newNode(char data){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new; 
}

//Inorder Algorithm Recursive
void inorder(struct node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%c\t",root->data);
    inorder(root->right);
}

//Postorder Algorithm
void postorder(struct node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c\t",root->data);

}

//Preorder Algorithm
void preorder(struct node* root){
    if(root == NULL){
        return;
    }
    printf("%c\t",root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(){
    struct node *root = newNode('a');
    root->right = newNode('b');
    root->left = newNode('c');
    root->left->right = newNode('d');
    root->right->left = newNode('e');
    printf("InOrder traversal of the BST is:\n");
    inorder(root); 
    printf("\nPostOrder traversal of the BST is:\n");
    postorder(root); 
    printf("\nPreOrder traversal of the BST is:\n");
    preorder(root); 
    return 0;
}

