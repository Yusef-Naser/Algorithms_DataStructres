#include <iostream>
using namespace std ;

struct Node
{   
    int data; 
    Node *next;
};

void push(Node** head_ref, int new_data) 
{ 
  
    // allocate node 
    Node* new_node = new Node(); 
  
    // put in the data 
    new_node->data = new_data; 
  
    // link the old list 
    // off the new node 
    new_node->next = (*head_ref); 
  
    // move the head to point 
    // to the new node 
    (*head_ref) = new_node; 
} 

int getKth(Node* head , int index ) {
    Node* current = head ;
    int count = 0 ;
    while (current != NULL)
    {
        if (count == index) {
            return current->data ;
        }
        current = current->next ;
        count ++ ;
    }
    
}


void printList(Node* node) 
{ 
    while (node != NULL)  
    { 
        cout << node->data << " "; 
        node = node->next; 
    } 
} 


int main(int argc, char const *argv[])
{
    Node* head = NULL; 
  
    // Use push() to construct 
    // below list 
    // 1->12->1->4->1 
    push(&head, 1); 
    push(&head, 4); 
    push(&head, 1); 
    push(&head, 12); 
    push(&head, 1); 
  
    // Check the count 
    // function 
    cout << "Element at index 3 is " << getKth(head, 3); 

    return 0;
}
