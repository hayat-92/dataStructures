#include <iostream>
#include<vector>
#include<queue>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    // Write your code here
    vector<Node<int>*> v= vector<Node<int>*>();
    if(root==NULL){
        return v;
    }
    queue<BinaryTreeNode<int>*> *q=new queue<BinaryTreeNode<int>*>();
    q->push(root);
    q->push(NULL);
    Node<int> *head, *tail;
    head=NULL;
    tail==NULL;
    
    while(!q->empty()){
        BinaryTreeNode<int>* front=q->front();
        q->pop();
        if(front==NULL){
            if(!q->empty()){
                q->push(NULL);
            }
            
            v.push_back(head);
            head=NULL;
            tail=NULL;
            continue;
        }
        if(head==NULL){
            head=new Node<int>(front->data);
            tail=head;
        }else{
            Node<int> *temp=new Node<int>(front->data);
            tail->next=temp;
            tail=tail->next;
        }


        if(front->left!=NULL){
            q->push(front->left);
        }

        if(front->right!=NULL){
            q->push(front->right);
        }
    }

    return v;


}

int main()
{

    return 0;
}