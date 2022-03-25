#include<iostream>
using namespace std;

class Node {
    	public :
    	int data;
    	Node *next;

    	Node(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

class QueueUsingLL
{
    Node *frontv;
    Node *rear;
    int size;   


public:
    QueueUsingLL(){
        frontv=NULL;
        rear=NULL;
        size=0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size==0;
    }

    void enqueue(int data){
        Node *newNod=new Node(data);
        if(size==0){
            frontv=newNod;
            rear=newNod;
            size++;
        }else{
            size++;
            rear->next=newNod;
            rear=rear->next;
        }
    }

    int dequeue(){
        if(size==0){
            return -1;
        }
        size--;
        int temp=frontv->data;
        frontv=frontv->next;
        return temp;
    }

    int front(){
        if(size==0){
            return -1;
        }
        return frontv->data;
    }
    
};

int main(){
    QueueUsingLL q=QueueUsingLL();
    int arr[]={1,2,3,4,5};
    for(int i=0; i<5; i++){
        q.enqueue(arr[i]);
    }

    for(int i=0; i<5; i++){
        cout<<q.dequeue()<<endl;
    }

    // cout<<q.front()<<endl;
    return 0;
}


