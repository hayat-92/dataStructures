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

Node *removeDuplicates(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        return NULL;
    }
    // Write your code here
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            if (temp->next->next != NULL)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp->next = NULL;
            }
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
}

int main()
{
    return 0;
}