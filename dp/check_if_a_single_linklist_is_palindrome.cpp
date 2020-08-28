#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *newNode(int data){
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
bool isCircular(Node *head){
    if(head==NULL){
        return true;
    }
    Node *cur = head->next;
    while(cur!=NULL and cur!=head){
        cur = cur->next;
    }
    return cur==head;
}
int main(){
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    isCircular(head)? cout << "Yes\n" :
    cout << "No\n" ;
    // Making linked list circular
    head->next->next->next->next = head;
    isCircular(head)? cout << "Yes\n" :
    cout << "No\n" ;
    return 0;
}