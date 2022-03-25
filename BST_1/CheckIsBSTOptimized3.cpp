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

bool IsBST3(BinaryTreeNode<int>* root, int minRange, int maxRange){
    if(root==NULL){
        return true;
    }

    if(root->data<minRange || root->data>maxRange){
        return false;
    }

    bool isLeftWithinRange=IsBST3(root->left, minRange, root->data-1);
    bool isRightWithinRange=IsBST3(root->right, root->data, maxRange);

    return isLeftWithinRange && isRightWithinRange;
}
int main()
{

    return 0;
}