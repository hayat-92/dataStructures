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

int length(Node*head){
    Node *temp=head;
    int count=0;
    while(temp != NULL){
        temp=temp->next;
        count++;
    }

    return count;
}

Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    if(head==NULL){
        return NULL;
    }

    int len=length(head);

    int count=0;
    Node *temp=head;
    while(count<len-n){
        temp=temp->next;
        count++;
    }

    Node *newtemp=head;

    while(newtemp->next!=NULL){
        newtemp=newtemp->next;
    }

    newtemp->next=head;
    head=temp->next;
    temp->next=NULL;
    return head;
}

int main()
{
    return 0;
}