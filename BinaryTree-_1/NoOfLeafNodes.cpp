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

int numLeaves(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }

    if(root->left==NULL && root->right==NULL){
        return 1;
    }

    return numLeaves(root->left)+numLeaves(root->right);
}
int main()
{

    return 0;
}