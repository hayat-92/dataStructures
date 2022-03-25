#include <iostream>
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

struct Pair{
    Node<int> *head;
    Node<int>* tail;
};

Pair helper(BinaryTreeNode<int> *root){
    if(root==NULL){
        Pair p;
        p.head=NULL;
        p.tail=NULL;
        return p;
    }

    Pair LeftLL=helper(root->left);
    Pair RightLL=helper(root->right);

    Pair newLL;
    Node<int> *rootNode=new Node<int>(root->data);
    if(LeftLL.head !=NULL && RightLL.head!=NULL){
        LeftLL.tail->next=rootNode;
        rootNode->next=RightLL.head;
        newLL.head=LeftLL.head;
        newLL.tail=RightLL.tail;
    }else if(LeftLL.head==NULL && RightLL.head==NULL){
        newLL.head=rootNode;
        newLL.tail=rootNode;
    }else if(LeftLL.head==NULL){
        rootNode->next=RightLL.head;
        newLL.head=rootNode;
        newLL.tail=RightLL.tail;
    }else{
        LeftLL.tail->next=rootNode;
        newLL.head=LeftLL.head;
        newLL.tail=rootNode;
    }

    return newLL;


}

Node<int> *constructLinkedList(BinaryTreeNode<int> *root)
{
    // Write your code here
    Pair p=helper(root);
    return p.head;
}
int main()
{

    return 0;
}