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

void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        bool lflag = false;
        bool rflag = false;
        if (front->left == NULL)
        {
            lflag = true;
        }

        if (front->right == NULL)
        {
            rflag = true;
        }
        string s = "";
        s = s + to_string(front->data) + ":";
        if (!lflag)
        {
            s = s + "L" + ":" + to_string(front->left->data) + ",";
        }
        else
        {
            s = s + "L" + ":" + to_string(-1) + ",";
        }

        if (!rflag)
        {
            s = s + "R" + ":" + to_string(front->right->data);
        }
        else
        {
            s = s + "R" + ":" + to_string(-1);
        }
        if(front->left!=NULL){
            q.push(front->left);
        }

        if(front->right!=NULL){
            q.push(front->right);
        }
        
        
        cout << s << endl;
    }
}
int main()
{

    BinaryTreeNode<int> *root=takeInputLevelWise();
    printLevelWise(root);

    return 0;
}