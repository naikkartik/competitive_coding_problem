#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};
Node *newNode(int key){
    Node *new_node = new Node;
    new_node->data = key;
    new_node->left =NULL;
    new_node->right =NULL;
    return new_node;
}


Node *constructTree(int pre[],int post[],int &preindex,int l,int h,int size){
    //base condition 
    if(preindex>=size or l>h){
        return NULL;
    }
    Node *root = newNode(pre[preindex]);
    preindex++;
    if(l==h){
        return root;
    }
    //find the index at posorder 
    int i;
    for(i=l;i<=h;i++){
        if(post[i]==pre[preindex]){
            break;
        }
    }
    if(i<=h){
        root->left =constructTree(pre,post,preindex,l,i,size);
        root->right = constructTree(pre,post,preindex,i+1,h,size);
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
int main ()
{
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int size = sizeof( pre ) / sizeof( pre[0] );
    int preindex =0;
    struct Node *root = constructTree(pre,post,preindex,0,size-1,size);
    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);
    return 0;
}
