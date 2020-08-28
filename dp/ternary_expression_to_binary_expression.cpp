#include <bits/stdc++.h>
using namespace std; 

struct Node{
    char data;
    Node *left,*right;
};

Node *newNode(char data){
    Node *new_node = new Node;
    new_node->data = data;
    new_node->left =new_node->right =NULL;
    return new_node;
}
void printNode(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printNode(root->left);
    printNode(root->right);
}
Node *convertExpression(string str,int &i){
    Node *root = newNode(str[i]);
    if(i==str.length()-1){
        return root;
    }
    i++;
    if(str[i]=='?'){
        i++;
        root->left =convertExpression(str,i);
        i++;
        root->right = convertExpression(str,i);
        return root;
    }
    else return root;
}
int main(){
    string expression ="a?b?c:d:e";
    int i=0;
    Node *root = convertExpression(expression,i);
    printNode(root);
}


void rightViewUtil(struct Node *root, int level, int *max_level)
{
    // Base Case
    if (root==NULL)  return;

    // If this is the last Node of its level
    if (*max_level < level)
    {
        printf("%d ", root->data);
        *max_level = level;
    }

    // Recur for right subtree first, then left subtree
    rightViewUtil(root->right, level+1, max_level);
    rightViewUtil(root->left, level+1, max_level);
}

// A wrapper over rightViewUtil()
void rightView(struct Node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}

