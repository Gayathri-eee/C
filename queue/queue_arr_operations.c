#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int f=-1,r=-1;
int queue_array[SIZE];

int isEmpty(){
    if(f==-1 &&r==-1 || f==SIZE)
    return 1;
    else return 0;
}

int isFull(){
    if(r==SIZE-1)return 1;
    else return 0;
}

void enqueue(int d){
    if(isFull()){
        printf("queue overflow");
        return;
    }
    if(isEmpty() || f==SIZE) {
        ++r;
        ++f;
        queue_array[r]=d;
    }
    else{
        ++r;
        queue_array[r]=d;
    }
    return;
}

int dequeue(){
    int val;
    if(isEmpty()){
        printf("queue underflow");
    }
    val=queue_array[f];
    f++;
    return val;
}

void show(){
    printf("f=%d,r=%d\n",f,r);
    for(int i=f;i<=r;i++){
        printf("%d\n",queue_array[i]);
    }
}

void peak(){
    if(isEmpty()){
        printf("stack underflow");
        return;
    }
    printf("\n%d is top most element",queue_array[f]);
}

int main() {
    int ch,val;
    while(1){
        printf("\nOperations on Queue\n\t\t1.enqueue()\n\t\t2.dequeue()\n\t\t3.peak()\n\t\t4.print()\n\t\t5.exit\nenter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\n enter data to enqueue:");
                int d;
                scanf("%d",&d);
                enqueue(d);
                break;
            case 2:
                val=dequeue();
                printf("\n%d is dequeued\n",val);
                break;
            case 3:
                printf("the top element is %d\n",queue_array[f]);
                break;
            case 4:
                show();
                break;
            case 5:
                printf("\nexiting the program\n");
                exit(0);
            default:
                printf("\ninvalid choice");
        }
    }
    return 0;
}
