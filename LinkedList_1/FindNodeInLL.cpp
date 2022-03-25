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

int findNodeRec(Node *head, int n)
{
    // Write your code here
    return helper(head, n, 0);
    
}


int helper(Node *head, int n, int i){

    if(head==NULL){
        return -1;
    }

    if(head->data==n){
        return i;
    }

    return helper(head->next, n, i+1);
}

int main()
{
    return 0;
}