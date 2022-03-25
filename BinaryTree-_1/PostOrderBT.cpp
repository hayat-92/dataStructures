#include<iostream>
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

void postOrder(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root==NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
int main(){

return 0;
}