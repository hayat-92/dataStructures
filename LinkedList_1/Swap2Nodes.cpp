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

Node *swapNodes(Node *head, int i, int j)
{
    // Write your code here
    if(head==NULL){
        return head;
    }
    if(i>j){
        int temp=i;
        i=j;
        j=temp;
    }
    int counti=0;
    Node *temp=head;
    Node *prev1=NULL, *curr1=head, *prev2=NULL, *curr2=head;
    while(counti<i && curr1!=NULL){
        prev1=curr1;
        curr1=curr1->next;
        counti++;
    }

    int countj=0;

    while(countj<j && curr2!=NULL){
        prev2=curr2;
        curr2=curr2->next;
        countj++;
    }
    
    if(i==0 && (j-i)==1){
        Node *temp=curr2->next;
        head->next=temp;
        curr2->next=head;
        head=curr2;
    }
    else if(i==0){
        Node *temp=curr2->next;
        curr2->next=head->next;
        prev2->next=head;
        head->next=temp;
        head=curr2;
    }else if((j-i)==1){
        Node *temp=curr2->next;
        prev1->next=curr2;
        curr2->next=curr1;
        curr1->next=temp;
    }else{
        prev1->next=curr2;
        prev2->next=curr1;
        Node *temp=curr1->next;
        curr1->next=curr2->next;
        curr2->next=temp;
    }

    return head;
}

int main()
{
    return 0;
}