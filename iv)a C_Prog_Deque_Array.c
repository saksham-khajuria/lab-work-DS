//Implementation of Deque in Array by Saksham khajuria, IT, 11912058
#include<stdio.h>
#include<stdlib.h>
//Structure of deque
struct deque{
    int *arr;
    int size;
    int front;
    int rear;
};

//Init state of deque with size
struct deque *Deque(int size){
    struct deque *init = (struct deque*)malloc(sizeof(struct deque));
    init->size = size;
    init->front = -1;
    init->rear= 0;
    init->arr = (int*)malloc(size*sizeof(int));
    return init;
}
//to check if deque is full
int isFull(struct deque* root){
    return (root->front == 0 && root->rear == root->size -1) || (root->front == root->rear + 1);
}
//to check if deque is empty
int isEmpty(struct deque* root){
    return (root->front == -1);
}
//to insert at front
void insertFront(struct deque *root,int data){
    if(isFull(root)){return;}
    if(root->front == -1){
        root->front = 0;
        root->rear = 0;
    }else{
        if(root->front == 0){
            root->front = root->size -1;
        }else{
            root->front = root->front -1;
        }
    }
    root->arr[root->front] = data;
    printf("%d added in the front\n",data);
}
//to insert at rear
void insertRear(struct deque *root,int data){
    if(isFull(root)){return;}
    if(root->front == -1){
        root->front = 0;
        root->rear = 0;
    }
    else{
        if(root->rear == root->size-1){
            root->rear = 0;
        }
        else{
            root->rear = root->rear + 1;
        }

    }
    root->arr[root->rear] = data;
    printf("%d added at the rear\n",data);
}
//to delete from front
void deleteFront(struct deque *root){
    if(isEmpty(root)){return;}
    if(root->front == root->rear){
        root->front = -1;
        root->rear = -1;
    }else{
        if(root->front == root->size - 1){
            root->front = 0;
        }
        else{
            root->front = root->front + 1;
        }
    }
}
//to del at end
void deleteEnd(struct deque *root){
    if(isEmpty(root)){return;}
    if(root->front == root->rear){
        root->front = -1;
        root->rear = -1;
    }
    else{
        if(root->rear ==0){
            root->rear = root->size-1;
        }
        else{
            root->rear = root->rear -1;
        }
    }
}
//returns front element
int getFront(struct deque* root){
    return root->arr[root->front];
}
//returns rear element
int getRear(struct deque* root){
    return root->arr[root->rear];
}

int main(){
    struct deque *root = Deque(5);
    insertFront(root,3);
    insertFront(root,6);
    insertRear(root,5);
    insertRear(root,1);
    printf("%d at front\n",getFront(root));
    printf("%d at rear\n",getRear(root));
    deleteEnd(root);
    deleteFront(root);
    printf("%d at front\n",getFront(root));
    printf("%d at rear\n",getRear(root));
    return 0;
}
