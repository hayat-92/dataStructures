#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> *children;

    // public:
    TreeNode(T data)
    {
        this->data = data;
        this->children = new vector<TreeNode<T> *>();
    }
};

TreeNode<int> *takeInputLevelWise()
{
    cout << "Enter root data" << endl;
    int rootData;
    cin >> rootData;
    queue<TreeNode<int> *> *pendingNodes = new queue<TreeNode<int> *>();
    TreeNode<int> *root = new TreeNode<int>(rootData);
    pendingNodes->push(root);
    while (!pendingNodes->empty())
    {
        TreeNode<int> *frontNode = pendingNodes->front();
        pendingNodes->pop();
        cout << "Enter num of children of " << frontNode->data << endl;
        int numChildren;
        cin >> numChildren;
        for (int i = 0; i < numChildren; i++)
        {
            cout << "Enter " << (i + 1) << " child of " << frontNode->data << endl;
            int child;
            cin >> child;
            TreeNode<int> *childNode = new TreeNode<int>(child);
            frontNode->children->push_back(childNode);
            pendingNodes->push(childNode);
        }
    }

    return root;
}

void printLevelWise(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
    queue<TreeNode<int>*> *pendingNodes=new queue<TreeNode<int>*>();
     pendingNodes->push(root);
     while (!pendingNodes->empty())
     {
         TreeNode<int> *frontNode=pendingNodes->front();
         pendingNodes->pop();
         cout<<frontNode->data<<" ";
         for(int i=0; i<(frontNode->children->size()); i++){
             pendingNodes->push(frontNode->children->at(i));
         }
     }
     


}
int main()
{
    TreeNode<int> *root=takeInputLevelWise();
    printLevelWise(root);

    return 0;
}