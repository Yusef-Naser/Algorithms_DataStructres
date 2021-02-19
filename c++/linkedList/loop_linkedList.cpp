#include <iostream>
#include <unordered_set>

using namespace std ;

struct Node { 
    int data; 
    struct Node* next; 
}; 
  
void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node = new Node; 
  
    /* put in the data  */
    new_node->data = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 

Node* detectedLoop(Node* head) {
    unordered_set<Node*> s ;
    
    Node* ssss = head ;
    while (ssss != NULL)
    {
        if(s.find(ssss) != s.end()) {
            return ssss ;
        }
        s.insert(ssss);
        ssss = ssss ->next ;
    }
    
    return NULL ;  
}

int main(int argc, char const *argv[])
{
    
     Node* node1 = new Node(); 
     Node* node2 = new Node(); 
     Node* node3 = new Node(); 
     Node* node4 = new Node(); 
     Node* node5 = new Node(); 
   // 10->15->4->20->30
   //         |_______|
                   

    node1 ->data = 10 ;
    node1->next = node2;

    node2->data = 15 ;
    node2->next = node3;

    node3->data = 4 ;
    node3->next = node4 ;

    node4->data = 20 ;
    node4->next = node5 ;

    node5 ->data = 30 ;
    node5 ->next = node3;

    Node* node = detectedLoop(node1);
    if (node != NULL) {
        cout << "data : "<< node->data << endl;
    }else {
        cout << "error" << endl ;
    }
    return 0;
}
