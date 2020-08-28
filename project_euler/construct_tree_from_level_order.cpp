#include <bits/stdc++.h>
using namespace std; 

struct Node{
    int data;
    Node *left,*right;
};

Node *newNode(int key){
    Node *new_node = new Node;
    new_node->data = kefy;
    new_node->left=NULL;
    new_node->right = NULL;
    return new_node;
}

struct NodeDetails{
    Node *node;
    int mini;
    int maxi;
};
Node *solution(int n,int arr[]){
    if(n==0){
        return NULL;
    }
    Node *root = newNode(arr[0]);
    queue<NodeDetails>q;
    NodeDetails temp = new NodeDetails;
    temp->node = root;
    temp->mini = INT_MIN;
    temp->maxi = INT_MAX;
    q.push(temp);
    int i=1;
    while(i<n){
        temp = q.front();
        q.pop();
        if(arr[i]<temp->ptr->data and arr[i]>temp.mini){
            Node *temp2 = newNode(arr[i]);
            Node
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node *root = solution(n,arr);
    print(root);
}