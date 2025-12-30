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
int Search(Node *root,int key)
    { if(root==NULL)
        return -1;
        if(root->data==key)
        return key;
        if(root->data>key)
        return Search(root->left,key);
        if(root->data<key);
        return Search(root->right,key);
    }


int main()
{
    int arr[] = {3,2,1,5,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node *root = BuildBst(arr, n);
    inorder(root);
   int result= Search(root,6);
    if(result==-1)
    cout<<"Element not found";
    else
    cout<<"Element found: "<<result;
    return 0;
}
