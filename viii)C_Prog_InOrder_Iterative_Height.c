//Iterative version of InOrder Traversal & Max Height by Saksham Khajuria, IT, 11912058
#include<stdio.h>
#include<stdlib.h>

//Structure of Tree
struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};

//Creating a new tree node
struct tree *newNode(int data){
    struct tree *node = (struct tree*)malloc(sizeof(struct tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//Structure of Stack node
struct stack{
    struct tree *t;
    struct stack *next;
};

//push function
void push(struct stack **stack,struct tree *tree){
    struct stack *newTree = (struct stack*) malloc (sizeof(struct stack));
    newTree->t = tree;
    newTree->next = (*stack);
    (*stack) = newTree;
}

//to check if stack is empty
int isEmpty(struct stack *stack){
    return (stack==NULL);
}

//pop function that returns a tree node
struct tree *pop(struct stack** stack){
    struct stack *temp;
    struct tree *root;
    temp = *stack;
    root = temp->t;
    *stack = temp->next;
    free(temp);
    return root;
}

//InOrder Traversal
void InOrder(struct tree *root){
    struct tree* curr = root;
    struct stack *s = NULL;         //Stack is initialized NULL
    int flag = 0;
    while(!flag){
        if(curr != NULL){
            push(&s,curr);          //Push the current tree node to stack
            curr = curr->left;      //change the current tree to to left side
        }
        else{
            if(!isEmpty(s)){
                curr = pop(&s);     //pop the stack
                printf("%d\t",curr->data);      
                curr = curr->right;         //shift the curr tree node to the right of it
            }
            else{
                flag = 1;
            }
        }
    }

}

//Calculating Max Height of the tree
int height(struct tree *root){
    if(root == NULL){
        return 0;
    }
    else{
        int lst;
        int rst;
        lst = height(root->left);
        rst = height(root->right);
        //max(lst,rst)+1 is the max height
        if(rst>lst){
            return rst+1;
        }else{
            return lst+1;
        }
    }
}

int main(){
    struct tree *root = newNode(2);
    root->left = newNode(5);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(1);
    root->right->left = newNode(8);
    printf("InOrder Tree Traversal without recursion:\n");
    InOrder(root);
    printf("\n Height of Tree is = %d\n",height(root));
    return 0;
}
