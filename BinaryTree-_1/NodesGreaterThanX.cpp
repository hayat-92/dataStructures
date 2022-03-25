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

int countNodesGreaterThanX(BinaryTreeNode<int>* root, int x) {
    // Write our code here
    if(root==NULL){
        return 0;
    }

    int lCount=countNodesGreaterThanX(root->left, x);
    int rCount=countNodesGreaterThanX(root->right, x);

    if(root->data>x){
        return 1+lCount+rCount;
    }else{
        return lCount+rCount;
    }
}
int main()
{
    return 0;
}