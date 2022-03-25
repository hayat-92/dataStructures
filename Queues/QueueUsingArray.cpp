#include<iostream>
using namespace std;

class QueueUsingArray
{
private:
    int *data;
    int front;
    int rear;
    int size;
    int capacity;


public:
    QueueUsingArray(){
        data=new int[5];
        front=-1;
        rear=-1;
        size=0;
        capacity=5;

    }

    QueueUsingArray(int capacity){
        data=new int[capacity];
        front=-1;
        rear=-1;
        size=0;

    }

    int sizes(){
        return size;
    }

    bool isEmpty(){
        return size==0;
    }

    void enqueue(int elem){
        if(size==capacity){
            // return -1;
        }
        if(size==0){
            front=0;
        }
        rear++;
        if(rear==capacity){
            rear=0;
        }
        data[rear]=elem;
        size++;

    }

    int frontx(){
        if(size==0){
            return -1;
        }
        return data[front];
    }
    int dequeue(){
        if(size==0){
            return -1;
        }
        int temp=data[front];
        front++;
        if(front==capacity){
            front=0;
        }
        size--;
        if(size==0){
            front=-1;
            rear=-1;
        }
        return temp;

    }

};



int main(){
    QueueUsingArray q=QueueUsingArray();
    int arr[]={10, 20, 30, 40};
    for(int i=0; i<4; i++){
        q.enqueue(arr[i]);
    }

    cout<<q.sizes()<<endl;
    cout<<q.frontx()<<endl;
    cout<<q.isEmpty()<<endl;

    for(int i=0; i<4; i++){
        cout<<q.dequeue()<<" ";
    }
    return 0;
}