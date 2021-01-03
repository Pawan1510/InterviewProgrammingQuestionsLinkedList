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
bool detectLoop( Node *head )
{
    Node *slw_ptr = head, *fast_ptr = head;
    while( slw_ptr && fast_ptr && fast_ptr->next )
    {
        fast_ptr = fast_ptr->next->next;
        slw_ptr = slw_ptr->next;
        if( slw_ptr == fast_ptr )
            return true;
    }
    return false;
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
    //head->next->next = head;
    //for creating loop in list please uncomment the above line of code
    detectLoop( head ) ? cout<<"Loop Found\n" : cout<<"No Loop\n";
}
