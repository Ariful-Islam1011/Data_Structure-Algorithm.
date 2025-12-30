#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int val)
{
    if(root == NULL)
        return new Node(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

Node* BuildBst(int arr[], int n)
{
    Node *root = NULL;
    for(int i = 0; i < n; i++)
        root = insert(root, arr[i]);
    return root;
}

void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
Node *inordersuccessor(Node*root)
{
    Node* curr=root;
    while(curr!=NULL && curr->left!=NULL)
    curr=curr->left;
    return curr;
}
 Node* DeleteNode(Node*root,int value)
 {
    if(root==NULL)
    return root;
    if(value>root->data)
    {root->right=DeleteNode(root->right,value);}
    else if(value<root->data)
    {
        root->left=DeleteNode(root->left,value);
    }
    else{
        //Cse-01: No child
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        //case-02: One child
        else if(root->left==NULL)
        {
        Node*temp=root->right;
        delete root;
        return temp;
        }
        else if(root->right==NULL)
        {Node*temp=root->left;
        delete root;
        return temp;
        }
       // case-03:Two Children
       Node*temp=inordersuccessor(root->right);
       root->data=temp->data;
       root->right=DeleteNode(root->right,temp->data);
       
        }
    return root;
    }



int main()
{
    int arr[] = {3,2,1,5,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node *root = BuildBst(arr, n);
    cout << "Before deletion: ";
    inorder(root);
    cout << endl;
    root=DeleteNode(root,4);
    cout << "After deletion: ";
    inorder(root);
    cout << endl;
    return 0;
}