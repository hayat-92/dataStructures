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

Node *midPoint(Node *head)
{
    // Write your code here
    if(head==NULL){
        return head;
    }
     Node *slow=head;
     Node *fast=head;
     while(fast->next != NULL && fast->next->next != NULL){
         slow=slow->next;
         fast=fast->next->next;
     }

     return slow;
}


Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    // Write your code here
    Node *head=NULL;
    Node *tail=NULL;
    Node *t1=head1;
    Node *t2=head2;

    if(head1==NULL && head2==NULL){
        return NULL;
    }else if(head1==NULL){
        head=head2;
    }else if(head2==NULL){
        head=head1;
    }
    
    while(t1!=NULL && t2!=NULL){
        if(t1->data <= t2->data){
            if(head==NULL){
                head=t1;
                tail=t1;
            }else{
                tail->next=t1;
                tail=tail->next;
                // tail->next=NULL;
            }
            t1=t1->next;
        }else{
            if(head==NULL){
                head=t2;
                tail=t2;
            }else{
                tail->next=t2;
                tail=tail->next;
                // tail->next=NULL;
            }
            t2=t2->next;
        }
    }

    if(t1==NULL && tail!=NULL){
        tail->next=t2;
    }

    if(t2==NULL && tail!=NULL){
        tail->next=t1;
    }

    return head;
}

Node *mergeSort(Node *head)
{
    // Write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node *mid=midPoint(head);
    Node *head1=head;
    Node *head2=mid->next;
    mid->next=NULL;
    Node *rtHead1=mergeSort(head1);
    Node *rthead2=mergeSort(head2);
    Node *finalHead=mergeTwoSortedLinkedLists(rtHead1, rthead2);
    return finalHead;

}

int main()
{
    return 0;
}