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

void PrintTreeDetailed(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ":";

    if (root->left != NULL)
    {
        cout << "L" << (root->left->data) << ", ";
    }

    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }

    cout << endl;

    // cout << root->data << endl;
    PrintTreeDetailed(root->left);
    PrintTreeDetailed(root->right);
}

BinaryTreeNode<int> *takeTreeInput()
{
    cout << "Enter root data" << endl;
    int r;
    cin >> r;
    if (r == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(r);
    BinaryTreeNode<int> *leftChild = takeTreeInput();
    BinaryTreeNode<int> *rightChild = takeTreeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

BinaryTreeNode<int> *takeTreeInputBetter(bool isRoot, int parentData, bool isLeft)
{
    if(isRoot){
        cout<<"Enter root data"<<endl;
    }else{
        if(isLeft){
            cout<<"Enter left child of "<<parentData<<endl;
        }else{
            cout<<"Enter right child of "<<parentData<<endl;
        }
    }
    int r;
    cin >> r;
    if (r == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(r);
    BinaryTreeNode<int> *leftChild = takeTreeInputBetter(false, r, true);
    BinaryTreeNode<int> *rightChild = takeTreeInputBetter(false, r, false);
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

int main()
{
    BinaryTreeNode<int> *root=takeTreeInputBetter(true, 0, true);
    PrintTreeDetailed(root);

    return 0;
}