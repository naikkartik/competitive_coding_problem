#include <bits/stdc++.h>
using namespace std; 

struct Node{
    int data;
    Node *left,*right;
};
struct NodeDetails{
    Node *ptr;
    int min,max;
}
Node* getNode(int data)
{
  Node *new_node = new Node;
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}
Node *constructBst(int arr[],int n){
    if(n==0){
        return NULL;
    }
    Node *root;
    queue<NodeDetails>q;
    int i =0;
    NodeDetails new_node;
    new_node.ptr = getNode(arr[i++]);
    new_node.min = INT_MIN;
    new_node.max =INT_MAX;
    q.push(new_node);
    root = new_node.ptr;
    while(i!=n){
        NodeDetails temp = q.front();
        q.pop();
        if((i<n) and (arr[i]<temp.ptr->data && arr[i]>temp.min)){
            new_node.ptr = getNode(arr[i++]);
            new_node->min = temp.ptr.data;
            new_node->max = temp.max;
            temp.ptr.right = new_node.ptr;
            q.push(new_node);
        }
        else{
            
        }
    }
}
int main(){
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = constructBst(arr, n);
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    return 0;
}