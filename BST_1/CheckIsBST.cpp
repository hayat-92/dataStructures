#include <iostream>
#include<algorithm>
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

int minimum(BinaryTreeNode<int> *root){
    if(root==NULL){
        return INT_MAX;
    }

    int leftMin=minimum(root->left);
    int rightMin=minimum(root->right);
    return min(root->data, min(leftMin, rightMin));
}

int maximum(BinaryTreeNode<int> *root){
    if(root==NULL){
        return INT_MIN;
    }

    int leftMax=maximum(root->left);
    int rightMax=maximum(root->right);
    return max(leftMax, rightMax);
}


bool isBST(BinaryTreeNode<int> *root){
    if(root==NULL){
        return true;
    }

    int leftMax=maximum(root->left);
    if(leftMax>=root->data){
        return false;
    }

    int rightMin=minimum(root->right);
    if(rightMin<root->data){
        return false;
    }

    bool isLeftBST=isBST(root->left);
    bool isRightBST=isBST(root->right);
    return isLeftBST && isRightBST;
}
int main()
{

    return 0;
}