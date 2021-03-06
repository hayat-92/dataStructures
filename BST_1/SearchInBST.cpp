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

bool searchInBST(BinaryTreeNode<int> *root , int k) {
	// Write your code here
    if(root==NULL){
        return false;
    }

    if(k==root->data){
        return true;
    }

    if(k>(root->data)){
        return searchInBST(root->right, k);
    }else{
        return searchInBST(root->left, k);
    }
}


int main()
{

    return 0;
}