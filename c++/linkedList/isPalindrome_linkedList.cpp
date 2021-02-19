#include <iostream>
#include <stack> 
using namespace std ;

struct Node {  
    char data;  
    struct Node* next;  
};  
  

void push (struct Node** head ,char data ) {

     Node* newNode = new Node() ;
    newNode ->data = data ;
    newNode ->next = *head;

    *head = newNode;

}

bool isPalin(Node* head) {
    Node* last = head ;  
    stack<char> s ;

    while (last  != NULL)
    {
        s.push(last->data);
        last = last ->next ;
    }
    
    while (head != NULL)
    {
        char c = s.top();
        s.pop();
        if (head ->data != c) {
            return false;
        }
        head = head ->next ;
    }
    return true ;

}


void printList(struct Node *head) 
{ 
    struct Node *temp = head; 
    while (temp != NULL) 
    { 
        printf("%d  ", temp->data); 
        temp = temp->next; 
    } 
} 

bool isPalindromeUtil (Node** left, Node* right) {
    if (right == NULL) {
        return true ;
    }

    bool isp = isPalindromeUtil(left , right ->next) ;
    if (isp == false) return false ;

    bool ispl = (right ->data == (*left)->data);
    *left = (*left) -> next ;
    return ispl ;
}

bool isPalindrome(struct Node* head)  
{  
    isPalindromeUtil(&head, head);  
}  

int main(int argc, char const *argv[])
{
    // Node* head = NULL;
    // push(&head , 'A') ;
    // push(&head , 'B') ;
    // push(&head , 'C') ;
    // push(&head , 'B') ;
    // push(&head , 'A') ;

    // printList(head);

    // bool result = isPalin(head); 
    
    // if(result == true) 
    //         cout<<"isPalindrome is true\n"; 
    // else
    //     cout<<"isPalindrome is false\n"; 

    struct Node* head = NULL;  
    char str[] = "abacaba";  
    int i;  
  
    for (i = 0; str[i] != '\0'; i++) {  
        push(&head, str[i]);  
        printList(head);  
        isPalindrome(head) ? cout << "Is Palindrome\n\n" : cout << "Not Palindrome\n\n";  
    }  


    return 0;
}
