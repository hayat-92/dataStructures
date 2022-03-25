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

int height(BinaryTreeNode<int>* root) {
    // Write our code here
    if(root==NULL){
        return 0;
    }

    int lHeight=height(root->left);
    int rHeight=height(root->right);
    return 1+max(lHeight, rHeight);
}
int main()
{

    return 0;
}