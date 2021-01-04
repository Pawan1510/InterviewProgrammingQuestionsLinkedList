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
Node *rotateList( Node *head, int k )
{
    if( !head ) return head;
    Node *tail = head;
    int n = 1;
    while( tail->next ) {
        tail = tail->next;
        n++;
    }
    k = k%n;
    if( k == 0 ) return head;
    Node *new_tail = tail;
    tail->next = head; // this statement makes the list circular
    int steps_to_new_head = n-k;
    while( steps_to_new_head-- ) {
        new_tail = new_tail->next;
    }
    Node *new_head = new_tail->next;
    new_tail->next = NULL;
    return new_head;
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
    Node *new_head = rotateList(head,2);
    printList(new_head);
    return 0;
}
