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

Node *skipMdeleteN(Node *head, int M, int N)
{
    // Write your code here
    if (head == NULL)
    {
        return head;
    }

    if (M == 0)
    {
        return NULL;
    }

    if (N == 0)
    {
        return head;
    }

    Node *temp = head;
    while (temp != NULL)
    {

        int c1 = 1;
        Node *t1 = temp;
        while (t1 != NULL && c1 < M)
        {
            t1 = t1->next;
            c1++;
        }

        Node *t2 = NULL;
        if (t1 != NULL)
        {
            t2 = t1->next;
        }

        int c2 = 1;
        while (t2 != NULL && c2 < N)
        {
            t2 = t2->next;
            c2++;
        }

        if (t2 != NULL)
        {
            t2 = t2->next;
        }

        if (t1 != NULL)
        {
            t1->next = t2;
            t1 = t1->next;
        }

        temp = t1;
    }
    return head;
}

int main()
{
    return 0;
}