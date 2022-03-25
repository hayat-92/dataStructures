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

Node* reverseLL(Node *head){
    if(head->next==NULL){
        return head;
    }

    Node *LLn=reverseLL(head->next);
    head->next->next=head;
    head->next=NULL;
    return LLn;
}

bool isPalindrome(Node *head)
{
    // Write your code here
    if(head==NULL){
        return false;
    }
    if(head->next==NULL){
        return true;
    }
    int len=length(head);
    Node *temp=head;
    int count=0;
    while(count<((len+1)/2)-1){
        temp=temp->next;
        count++;
    }
    Node *curr=temp->next;
    temp->next=NULL;
    Node *newHead=reverseLL(curr);
    while(head!=NULL && newHead!= NULL){
        if(head->data!=newHead->data){
            return false;
        }
        head=head->next;
        newHead=newHead->next;
    }
    return true;
    
}

int main()
{
    return 0;
}