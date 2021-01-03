#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void append( Node **head_ref, int new_data )
{
    Node *new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref==NULL) {
        *head_ref = new_node;
        return;
    }
    while( last->next != NULL ) {
        last = last->next;
    }
    last->next = new_node;
    return;
}
void printList( Node *head )
{
    while( head != NULL ) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
void reverseList( Node **head )
{
    stack<Node *> s;
    Node *temp = *head;
    while( temp->next != NULL ) {
        s.push(temp);
        temp = temp->next;
    }
    *head = temp;
    while(!s.empty()) {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}
int main()
{
    Node *head = NULL;
    append(&head,1);
    append(&head,2);
    append(&head,3);
    append(&head,4);
    append(&head,5);
    printList(head);
    reverseList(&head);
    printList(head);

}
