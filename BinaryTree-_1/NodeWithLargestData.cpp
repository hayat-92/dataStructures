#include <iostream>
#include<algorithm>
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

int LargestNode(BinaryTreeNode<int> *root){
    if(root==NULL){
        return -1;
    }

    int lLargest=LargestNode(root->left);
    int rLargest=LargestNode(root->right);
    return max(root->data, max(lLargest, rLargest));
}
int main()
{

    return 0;
}