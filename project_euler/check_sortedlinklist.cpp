#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
};
Node *newNode(int key){
    Node *new_node =new Node;
    new_node->data = key;
    new_node->next = NULL;
    return new_node;
}
bool isSortedDesc(Node *head){
    if(head==NULL){
        return true;
    }
    while(head->next!=NULL){
        if(head->data>head->next->data){
            return false;
        }
        head = head->next;
    }
    return true;
}
int main()
{
    struct Node *head = newNode(7);
    head->next = newNode(5);
    head->next->next = newNode(4);
    head->next->next->next = newNode(3);
    isSortedDesc(head) ? cout << "Yes" :
    cout << "No";
    return 0;
}
