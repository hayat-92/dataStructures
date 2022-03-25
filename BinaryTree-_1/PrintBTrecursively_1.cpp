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
        this->left=NULL;
        this->right=NULL;
    }
};

void PrintTreeDetailed(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout<<root->data<<":";

    if(root->left!=NULL){
        cout<<"L"<<(root->left->data)<<", ";
    }

    if(root->right!=NULL){
        cout<<"R"<<root->right->data;
    }

    cout<<endl;


    // cout << root->data << endl;
    PrintTreeDetailed(root->left);
    PrintTreeDetailed(root->right);
}

void PrintTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << endl;
    PrintTree(root->left);
    PrintTree(root->right);
}
int main()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *rootLeft = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *rootRight = new BinaryTreeNode<int>(3);
    root->left = rootLeft;
    root->right = rootRight;

    BinaryTreeNode<int> *twoRight = new BinaryTreeNode<int>(4);
    BinaryTreeNode<int> *threeLeft = new BinaryTreeNode<int>(5);

    rootLeft->right = twoRight;
    rootRight->left = threeLeft;

    PrintTreeDetailed(root);

    return 0;
}