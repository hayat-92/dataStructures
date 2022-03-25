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

BinaryTreeNode<int> *takeTreeInputBetter(bool isRoot, int parentData, bool isLeft)
{
    if (isRoot)
    {
        cout << "Enter root data" << endl;
    }
    else
    {
        if (isLeft)
        {
            cout << "Enter left child of " << parentData << endl;
        }
        else
        {
            cout << "Enter right child of " << parentData << endl;
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

int numberOfNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftCount = numberOfNodes(root->left);
    int rightCount = numberOfNodes(root->right);
    return 1 + leftCount + rightCount;
}

int main()
{
    BinaryTreeNode<int> *root=takeTreeInputBetter(true, 0, true);
    cout<<numberOfNodes(root)<<endl;

    return 0;
}