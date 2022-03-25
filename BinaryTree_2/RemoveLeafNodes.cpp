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

BinaryTreeNode<int>* removeLeaves(BinaryTreeNode<int> *root){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        return NULL;
    }

    root->left=removeLeaves(root->left);
    root->right=removeLeaves(root->right);
    return root;


}
int main(){

return 0;
}