#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};
Node *newNode(int data){
    Node *new_node = new Node;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right =NULL;
    return new_node;
}
Node *constructTree(int pre[],int n){
    stack<Node*>s;
    Node *root = newNode(pre[0]);
    s.push(root);
    for(int i=1;i<n;i++){
        Node *temp =NULL;
        while(!s.empty() and pre[i]>s.top()->data){
            temp = s.top();
            s.pop();
        }
        if(temp!=NULL){
            temp->right = newNode(pre[i]);
            s.push(temp);
        }
        else{
            Node *cur = newNode(pre[i]);
            s.top()->left = cur;
            s.push(cur);
        }
    }
    return root;
}
void printInorder(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printInorder(root->left);
    printInorder(root->right);
}
int main ()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );
    Node *root = constructTree(pre, size);
    printf("Inorder traversal of the constructed tree: \n");
    
    printInorder(root);
    return 0;
}
