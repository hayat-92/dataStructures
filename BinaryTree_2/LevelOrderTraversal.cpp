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

void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL){
        return;
    }

    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BinaryTreeNode<int> *topNode=q.front();
        q.pop();
        // if(q)
        if(topNode==NULL && !q.empty()){
            q.push(NULL);
            cout<<endl;
        }else{
            if(topNode==NULL){
                continue;
            }
            cout<<topNode->data<<" ";
            if(topNode->left!=NULL){
                q.push(topNode->left);
            }

            if(topNode->right!=NULL){
                q.push(topNode->right);
            }
        }
    }
}
int main()
{

    BinaryTreeNode<int> *root=takeInputLevelWise();
    printLevelWise(root);

    return 0;
}