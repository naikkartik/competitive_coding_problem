#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node *left,*right;
};
Node *newNode(char key){
    Node *new_node = new Node;
    new_node->data = key;
    new_node->left =NULL;
    new_node->right =NULL;
    return new_node;
}

void printInorder(Node *root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}
Node *buildTree(char in[],char pre[],int &pre_index,int l,int r,int size){
    if(l>r or pre_index>=size){
        return NULL;
    }
    Node *root = newNode(pre[pre_index]);
    pre_index++;
    if(l==r){
        return root;
    }
    int i;
    for(int i=l;i<=r;i++){
        if(in[i]==pre[pre_index]){
            break;
        }
    }
    
    root->left =buildTree(in,pre,pre_index,l,i,size);
    root->right = buildTree(in,pre,pre_index,i+1,r,size);

    return root;
}
int main()
{
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);
    int pre_index = 0;
    struct Node* root = buildTree(in, pre, pre_index,0, len - 1,len);
    /* Let us test the built tree by printing Insorder traversal */
    printf("Inorder traversal of the constructed tree is \n");
    printInorder(root);
    
}