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
void printMiddle( Node *head )
{
    Node *slw_ptr = head, *fast_ptr = head;
    while( fast_ptr != NULL && fast_ptr->next != NULL ) {
        fast_ptr = fast_ptr->next->next;
        slw_ptr = slw_ptr->next;
    }
    cout<<slw_ptr->data<<endl;
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

    printMiddle( head );
}
