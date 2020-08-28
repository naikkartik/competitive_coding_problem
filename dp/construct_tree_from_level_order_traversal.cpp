#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left,*right;
};
Node *newNode(int data){
    Node *new_node = new Node;
    new_node->data = data;
    new_node->left=NULL;
    new_node->right =NULL;
    return new_node;
}

Node *construct_level(int arr[],int n){
    queue<Node *>q;
    Node *root = newNode(arr[0]);
    q.push(root);
    int i=1;
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(i<n){
            Node *left = newNode(arr[i]);
            temp->left=left;
            q.push(left);
            i++;
        }
        if(i<n){
            Node *right = newNode(arr[i]);
            temp->right = right;
            q.push(right);
            i++;
        }
    }
    return root;
}
void printInorder(Node *root){
    if(root==NULL){
        return ;
    }
    
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}
int main(){
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = construct_level(arr, n);
    cout << "Inorder Traversal: ";
    printInorder(root);
    return 0;
}
