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

BinaryTreeNode<int>* helper(BinaryTreeNode<int> *root, int val1, int val2){
    if(root==NULL || root->data==val1 || root->data==val2){
        return root;
    }

    if(root->data<val1 && root->data<val2){
        return helper(root->right, val1, val2);
    }

    if(root->data>val1 && root->data>val2){
        return helper(root->left, val1, val2);
    }

    BinaryTreeNode<int>* left=helper(root->left, val1, val2);
    BinaryTreeNode<int>* right=helper(root->right, val1,val2);
    

    if(left!=NULL && right!=NULL){
        return root;
    }else if(left!=NULL){
        return left;
    }

    return right;
}
int getLCA(BinaryTreeNode<int> *root, int val1, int val2)
{
    // Write your code here
    BinaryTreeNode<int> *Node=helper(root, val1, val2);
    if(Node==NULL){
        return -1;
    }else{
        return Node->data;
    }
}
int main()
{

    return 0;
}