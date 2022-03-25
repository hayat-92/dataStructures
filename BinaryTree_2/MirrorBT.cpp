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

void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    // Write your code here
    if(root==NULL){
        return;
    }
    BinaryTreeNode<int> *temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}
int main()
{

    return 0;
}