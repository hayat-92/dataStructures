#include <iostream>
#include<queue>
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

void nodesAtDistanceKDown(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }

    nodesAtDistanceKDown(root->left, k - 1);
    nodesAtDistanceKDown(root->right, k - 1);
}

int nodesAtDistanceKHelper(BinaryTreeNode<int> *root, int target, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == target)
    {
        nodesAtDistanceKDown(root, k);
        return 0;
    }

    int leftD = nodesAtDistanceKHelper(root->left, target, k);

    if (leftD != -1)
    {
        if (leftD + 1 == k)
        {
            cout << root->data << endl;
        }
        else
        {
            nodesAtDistanceKDown(root->right, k - leftD - 2);
        }
        return 1 + leftD;
    }

    int rightD = nodesAtDistanceKHelper(root->right, target, k);
    if (rightD != -1)
    {
        if (rightD + 1 == k)
        {
            cout << root->data << endl;
        }
        else
        {
            nodesAtDistanceKDown(root->left, k - rightD - 2);
        }

        return 1 + rightD;
    }

    return -1;
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k)
{
    // Write your code here
    nodesAtDistanceKHelper(root, node, k);
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
    int target, k;
    cin>>target>>k;
    nodesAtDistanceK(root, target, k);

    return 0;
}