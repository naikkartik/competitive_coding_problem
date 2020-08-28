#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};
Node *newNode(int key){
    Node *new_node = new Node;
    new_node->data = key;
    new_node->left =NULL;
    new_node->right =NULL;
    return new_node;
}
Node *solution(int n,int arr[]){
    stack <Node *>s;
    Node *root = newNode(arr[0]);
    s.push(root);
    for(int i=1;i<n;i++){
        //create the newnode = 
        Node *cur_node = newNode(arr[i]);
        Node *temp =NULL;
        while(!s.empty() and arr[i]>s.top()->data){
            temp = s.top();
            s.pop();
        }
        if(temp==NULL){
            s.top()->left = cur_node;
            s.push(cur_node);
        }
        else{
            temp->right = cur_node;
            s.push(cur_node);
        }
    }
    return root;
}
void printInorder(Node *root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node *root = solution(n,arr);
    printInorder(root);

}