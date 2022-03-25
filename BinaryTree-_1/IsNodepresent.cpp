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

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
    if(root==NULL){
        return false;
    }

    if(root->data==x){
        return true;
    }

    return (isNodePresent(root->left, x) || isNodePresent(root->right, x));
}
int main(){

return 0;
}