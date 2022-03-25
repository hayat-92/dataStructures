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

int height(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }

    return 1+max(height(root->left), height(root->right));
}

int diameterOfBinaryTree(BinaryTreeNode<int>* root) {
	// Write your code here
    if(root==NULL){
        return 0;
    }

    int Lheight=height(root->left);
    int Rheight=height(root->right);

    int Fheight=1+Lheight+Rheight;

    int LDiameter=diameterOfBinaryTree(root->left);
    int RDiameter=diameterOfBinaryTree(root->right);
    return max(Fheight, max(Lheight, Rheight));
}
int main()
{

    return 0;
}