#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left,*right;
};
Node *newNode(int data){
    Node *new_node = new Node;
    new_node->data = data;
    new_node->left =NULL;
    new_node->right=NULL;
    return new_node;
}

void printAncestor(int arr[20][20],int n,Node *root){
    
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        int i = temp->data;
        if(temp->right!=NULL){
            int j = temp->right->data;
            q.push(temp->right);
            arr[i][j] =1;
            for(int k=0;k<n;k++){
                if(arr[k][i]==1){
                    arr[k][j]=1;
                }
            }
        }
        if(temp->left!=NULL){
            int j = temp->left->data;
            arr[i][j] =1;
            for(int k=0;k<n;k++){
                if(arr[k][i]==1){
                    arr[k][j]=1;
                }
            }
            q.push(temp->left);
        }
    }
    
}
int main(){
    Node *root = newNode(5);
    root->left=newNode(1);
    root->right = newNode(2);
    root->left->left= newNode(0);
    root->left->right = newNode(4);
    root->right->left = newNode(3);
    int arr[20][20]={{0}};
    printAncestor(arr,6,root);
    for(int i=0;i<6;i++){
        cout<<i<<"->";
        for(int j=0;j<6;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
