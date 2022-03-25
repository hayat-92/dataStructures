#include<iostream>
using namespace std;

class Node
    {
    	public:
        int data;
        Node *next;
        Node(int data)
        {
	        this->data = data;
	        this->next = NULL;
        }
    };

int findNode(Node *head, int n){
    // Write your code here.
    int count=0;
    while((head)!=NULL){
        if((*head).data==n){
            return count;
        }
        count++;
        head=head->next;
    }

    return -1;
}

int main(){
    return 0;
}