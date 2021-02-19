#include <iostream>
using namespace std ;

struct Node {  
    int data;  
    struct Node* next;  
}; 

void push(struct Node** head_ref, char new_data)  
{  
    /* allocate node */
    struct Node* new_node = new Node();
  
    /* put in the data */
    new_node->data = new_data;  
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);  
  
    /* move the head to pochar to the new node */
    (*head_ref) = new_node;  
} 


void printList(struct Node* ptr)  
{  
    while (ptr != NULL) {  
        cout << ptr->data << "->";  
        ptr = ptr->next;  
    }  
    cout << "NULL\n" ;  
}  

Node* isIntersection(Node* first , Node* second) {
    Node* head1 = first ;
    while (head1 != NULL)
    {
        
        Node* head2 = second ;
        while (head2 != NULL)
        {
            
            if (head1 == head2) {
                return head1;
            }
            head2 = head2->next ;
        }
        head1 = head1 ->next ;
        
    }
    return NULL ;
}

//  static Node MegeNode(Node n1, Node n2)
//     {
//         // define hashset
//         unordered_set<Node> hs = new unordered_set<Node>();
//         while (n1 != null) {
//             hs.add(n1);
//             n1 = n1.next;
//         }
//         while (n2 != null) {
//             if (hs.contains(n2)) {
//                 return n2;
//             }
//             n2 = n2.next;
//         }
//         return null;
//     }

int main(int argc, char const *argv[])
{
    Node* first1 = new Node();
    Node* second1 = new Node();

    Node* node2 = new Node();
    Node* node3 = new Node();

   first1->data = 10 ;
   second1->data = 20 ;

   node2 ->data = 8 ;
   node3 ->data = 9 ;

    node2 ->next = node3 ;
    node3 ->next = NULL ;

    first1 ->next = node2;
    second1->next = node2 ;

    printList(first1 ) ;
    printList(second1);

    Node* inter = isIntersection(first1 , second1);
    if (inter != NULL) {
        cout << "data : " << inter->data << endl ;
    }else {
        cout << "error" << endl ;
    }

    return 0;
}
