#include <iostream>
#include<algorithm>
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

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root==NULL){
        pair<int, int> p;
        p.second=INT_MIN;
        p.first=INT_MAX;
        return p;
    }

    pair<int, int> lPair=getMinAndMax(root->left);
    pair<int, int> rPair=getMinAndMax(root->right);
    pair<int, int> nPair;
    nPair.second=max(root->data,max(lPair.second, rPair.second));
    nPair.first=min(root->data,min(lPair.first, rPair.first));
    return nPair;
}
int main()
{

    BinaryTreeNode<int> *root=takeInputLevelWise();
    pair<int, int> p=getMinAndMax(root);
    cout<<p.first<<" "<<p.second<<endl;

    return 0;
}