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
void removeLoop( Node *loop_point, Node *head )
{
    Node *ptr1 = loop_point, *ptr2 = loop_point;
    unsigned int k=1, i;
    while( ptr1->next != ptr2 ) {
        ptr1 = ptr1->next;
        k++;
    }
    ptr1 = head;
    ptr2 = head;
    for( i=0; i<k; i++ ) {
        ptr2 = ptr2->next;
    }

    while( ptr1 != ptr2 ) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    while( ptr2->next != ptr1 )
        ptr2 = ptr2->next;

    ptr2->next = NULL;
}
int detectAndRemoveLoop( Node *head )
{
    Node *slw_ptr = head, *fast_ptr = head;
    while( slw_ptr && fast_ptr && fast_ptr->next ) {
        fast_ptr = fast_ptr->next->next;
        slw_ptr = slw_ptr->next;
        if( slw_ptr == fast_ptr ) {
            removeLoop( slw_ptr, head );
            return 1;
        }
    }
    return 0;
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
    head->next->next = head->next->next;
    detectAndRemoveLoop( head );
    printList(head);

}
