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

class StackUsingLL
{
// private:
Node *head;
int size;

public:
    StackUsingLL(){
        head=NULL;
        size=0;
    };

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size==0;
    }

    void push(int elem){
        Node *newNode=new Node(elem);
        newNode->next=head;
        head=newNode;
        size++;

    }

    int top(){
        if(head==NULL){
            return -1;
        }

        return head->data;
    }

    int pop(){
        if(head==NULL){
            return -1;
        }
        int temp=head->data;
        head=head->next;
        size--;
        return temp;


    }
};



int main(){
    return 0;
}