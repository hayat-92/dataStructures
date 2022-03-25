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

Node *evenAfterOdd(Node *head)
{
    // write your code here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *EH = NULL, *ET = NULL, *OH = NULL, *OT = NULL;
    while (head != NULL)
    {
        if ((head->data) % 2 == 0)
        {
            if (EH == NULL)
            {
                EH = head;
                ET = head;
            }
            else
            {
                ET->next = head;
                ET=ET->next;
            }
            head = head->next;
        }
        else
        {
            if (OH == NULL)
            {
                OH = head;
                OT = head;
            }
            else
            {
                OT->next = head;
                OT=OT->next;
            }
            head = head->next;
        }
    }

    if (OT != NULL)
    {
        OT->next = EH;
        // head=OH;
    }

    if (ET != NULL)
    {
        ET->next = NULL;
    }

    if(OH==NULL){
        head=EH;
    }else{
        head=OH;
    }

    return head;
}

int main()
{
    return 0;
}