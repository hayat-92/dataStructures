#include <iostream>
using namespace std;

template <class T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void helper(BinaryTreeNode<int> *root, int k){
    if(root==NULL){
        return;
    }

    root->data=k;
    helper(root->left, k+1);
    helper(root->right, k+1);
}

void changeToDepthTree(BinaryTreeNode<int> *root)
{
    // Write our code here
    helper(root, 0);
}

int main()
{

    return 0;
}