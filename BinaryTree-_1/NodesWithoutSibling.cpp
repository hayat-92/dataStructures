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

void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL){
        return;
    }

    if(root->left!=NULL && root->right==NULL){
        cout<<root->left->data<<" ";
        printNodesWithoutSibling(root->left);
        return;
    }
    if(root->left==NULL && root->right!=NULL){
        cout<<root->right->data<<" ";
        printNodesWithoutSibling(root->right);
        return;
    }

    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);


}
int main(){

return 0;
}