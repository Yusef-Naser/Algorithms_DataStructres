#include <iostream>
#include <string>
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

void append (Node** head , int newData) {
    Node *newNode = new Node();
    newNode->data = newData;
    newNode ->next = NULL ;

    Node *last = *head ;

    if (*head== NULL) {
        *head = newNode;
        return ;
    }

    while (last ->next != NULL)
    {
        last = last ->next ;
    }
    last ->next = newNode ;

}

void printList(Node *head) {
    while (head != NULL)
    {
        cout << head->data << " "  ;
        head = head ->next ;
    }
    
}

string getNumber(Node *head) {
    string number = "" ;
    while (head != NULL)
    {
        number += to_string(head->data);
        head = head ->next ;
    }
    return number ;
}

Node* getDigits (int number) {
    string s = to_string(number) ;
    Node* head = NULL ;
    for (int i = 0; i < s.size() ; i++)
    {
        
        cout<< s[i] << endl ;
        append(&head , s[i]-'0')    ;
    }
    return head ;
}

int main(int argc, char const *argv[])
{
    Node* head1 = NULL; 
    Node* head2 = NULL; 
  
    // Use push() to construct 
    // below list 
    // 1->12->1->4->1 
    push(&head1, 7); 
    push(&head1, 1); 
    push(&head1, 6); 
   
    push(&head2, 5); 
    push(&head2, 9); 
    push(&head2, 2); 
    

string firstNumber = getNumber(head1);
string secondNumber = getNumber(head2);
int nn = stoi(firstNumber) + stoi(secondNumber) ;

cout <<  nn << endl ;

Node* node = getDigits(nn);

printList(node);

    return 0;
}
