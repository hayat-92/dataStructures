#include <iostream>
#include <queue>
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

BinaryTreeNode<int> *takeInputLevelWise()
{
    int r;
    cin >> r;
    if (r == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(r);
    queue<BinaryTreeNode<int> *> pendingChild;
    pendingChild.push(root);
    while (!pendingChild.empty())
    {
        BinaryTreeNode<int> *front = pendingChild.front();
        pendingChild.pop();
        cout << "Enter left child of " << front->data << endl;
        int left;
        cin >> left;
        if (left != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(left);
            front->left = leftChild;
            pendingChild.push(leftChild);
        }

        cout << "Enter right child of " << front->data << endl;
        int right;
        cin >> right;
        if (right != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(right);
            front->right = rightChild;
            pendingChild.push(rightChild);
        }
    }

    return root;
}
int main()
{
    BinaryTreeNode<int> *root=takeInputLevelWise();
    PrintTreeDetailed(root);

    return 0;
}