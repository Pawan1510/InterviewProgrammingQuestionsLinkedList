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
void getNthNode( Node *head, int n )
{
    Node *ref_ptr = head, *main_ptr = head;
    int count = 0;
    if( head != NULL )
    {
        while( count < n ) {
            if( ref_ptr == NULL )
                cout<<"Be in Limit\n";
            ref_ptr = ref_ptr->next;
            count++;
        }
        if( ref_ptr == NULL ) {
            head = head->next;
            if( head != NULL ) {
                cout<<n<<" node from last: "<<main_ptr->data;
                return;
            }
        }
        else {
            while( ref_ptr != NULL ) {
                ref_ptr = ref_ptr->next;
                main_ptr = main_ptr->next;
            }
            cout<<n<<" node from last is: "<<main_ptr->data;
            return;
        }
    }
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
    getNthNode( head, 6 );
}
