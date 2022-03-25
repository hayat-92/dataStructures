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

void preOrder(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{

    return 0;
}