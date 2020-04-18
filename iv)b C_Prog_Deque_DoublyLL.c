//Implementation of Deque with Doubly LL by Saksham khajuria, IT, 11912058
#include<stdio.h>
#include<stdlib.h>
//Structure for Doubly linked list node
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
//inititalizing node
struct node *newNode(int data){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    return new;
}
//structure of deque
struct deque{
    struct node *front;
    struct node *rear;
    int size;
};
//init state of deque
struct deque *Deque(){
    struct deque *init = (struct deque*)malloc(sizeof(struct deque));
    init->front = NULL;
    init->rear = NULL;
    init->size = 0;
    return init;
}
//to check if deque is empty
int isEmpty(struct deque* root){
    return (root->front == NULL);
}
//to insert at front of the deque
void insertFront(struct deque *root,int data){
    struct node *frontNode = newNode(data);
    if(root->front == NULL){
        root->rear = frontNode;
        root->front = frontNode;
    }else{
        frontNode->next = root->front;
        root->front->prev = frontNode;
        root->front = frontNode;
    }
    printf("%d added at front \n",data);
    root->size++;
}
//to insert at rear
void insertRear(struct deque *root,int data){
    struct node *RearNode = newNode(data);
    if(root->front == NULL){
        root->rear = RearNode;
        root->front = RearNode;
    }else{
        RearNode->prev = root->rear;
        root->rear->next = RearNode;
        root->rear = RearNode;
    }
    printf("%d added at rear \n",data);
    root->size++;
}
//to delete from front
void deleteFront(struct deque *root){
    struct node *temp = root->front;
    int data = root->front->data;
    root->front = root->front->next;
    root->front->prev = NULL;
    free(temp);
    printf("%d removed from front \n",data);
    root->size--;
}
//to delete from end
void deleteEnd(struct deque *root){
    struct node *temp = root->rear;
    int data = root->rear->data;
    root->rear = root->rear->prev;
    root->rear->next = NULL;
    free(temp);
    printf("%d removed from end\n",data);
    root->size--;
}
//returns front element
int getFront(struct deque* root){
    return root->front->data;
}
//return rear element
int getRear(struct deque* root){
    return root->rear->data;
}
//returns the size of deque
int getSize(struct deque* root){
    return root->size;
}

int main(){
    struct deque *root = Deque();
    insertFront(root,5);
    insertFront(root,6);
    insertFront(root,3);
    insertRear(root,1);
    insertRear(root,2);
    deleteFront(root);
    deleteEnd(root);
    deleteFront(root);
    printf("%d at front \n",getFront(root));
    printf("%d at rear \n",getRear(root));
    printf("%d is the size \n",getSize(root));
    return 0;
}
