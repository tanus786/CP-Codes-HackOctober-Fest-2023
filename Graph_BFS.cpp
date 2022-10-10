#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int*arr;
};

int isEmpty(struct queue*q){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}

int isFull(queue*q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

void enqueue(queue*q,int value){
    if(isFull(q)){
        printf("It's full!\n");
    }
    else{
        q->r++;
        q->arr[q->r]=value;
    }
}

int dequeue(struct queue*q){
    int temp =-1;
    if(isEmpty){
        printf("It's Empty!");
    }
    else{
        temp=q->arr[q->f];
        q->f++;
    }
    return temp;
}

    int visited[7]={0,0,0,0,0,0,0};
    int v[7][7]={
        (0,1,1,1,0,0,0),
        (1,0,0,1,0,0,0),
        (1,0,0,1,1,0,0),
        (1,1,1,0,1,0,0),
        (0,0,1,1,0,1,1),
        (0,0,0,0,1,0,0),
        (0,0,0,0,1,0,0)
    };

void BFS(queue*q,int i){
 printf("%d",i);
    visited[i] = 1;
    enqueue(q,i);
    while (!isEmpty(q)){
        i = dequeue(q);
        for(int j=0;j<7;j++){
            if(v[i][j]==1 && visited[j]==0){
                BFS(q,j);
            }
        }
    }
}
int main(){
    int n;
    struct queue*q;
    printf("Enter the node from where you want to start the traversal:\n");
    scanf("%d",&n);
    q->size =100;
    q->f=q->r=0;
    q->arr = (int*)malloc(sizeof(int)*q->size);
    BFS(q,n);
    return 0;
}