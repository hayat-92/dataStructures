#include <iostream>
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

Node *deleteNodeRec(Node *head, int pos)
{
    // Write your code here
    if(head==NULL){
        return head;
    }

    if(pos==0){
        return head->next;
    }

    Node *temp=deleteNodeRec(head->next, pos-1);
    head->next=temp;
}

int main()
{

    return 0;
}