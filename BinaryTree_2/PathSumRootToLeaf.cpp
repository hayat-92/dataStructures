#include <iostream>
#include <queue>
#include <string>
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

void rootToLeafHelper(BinaryTreeNode<int> *root, int k, string output)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        k -= root->data;
        output += to_string(root->data);
        if (k == 0)
        {
            for (int i = 0; i < output.length(); i++)
            {
                cout << output[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    output += to_string(root->data);
    k -= (root->data);
    rootToLeafHelper(root->left, k, output);

    rootToLeafHelper(root->right, k, output);
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    rootToLeafHelper(root, k, "");
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);

    return 0;
}