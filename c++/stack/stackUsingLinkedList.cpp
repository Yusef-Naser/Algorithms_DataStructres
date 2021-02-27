#include <iostream>

using namespace std ;

class StackNode {
    public :
        int data ;
        StackNode* next ;
};

StackNode* newNode (int data) {
    StackNode* node = new StackNode() ;
    node ->data = data ;
    node ->next = NULL ;
    return node ;
}
int isEmpty (StackNode* root) {
    return !root ;
}
void push (StackNode** root , int data) {
    StackNode* node = new StackNode() ;
    node ->next = *root ;
    node -> data = data ;
    *root = node ;
    cout << data << "pushed"<< endl ;
}

int pop (StackNode** root) {
    if (isEmpty(*root)) {
        return INT_MIN ;
    }
    StackNode* temp = *root ;
    *root = (*root) ->next ;
    int popped = temp ->data ;
    free(temp) ;
    return popped ;
}

int peek (StackNode* root) {
    if (isEmpty(root)) return INT_MIN ;
   return root -> data ; 
}

int main(int argc, char const *argv[])
{
    
    StackNode* root = NULL ;

    push(&root , 1 ) ;
    push(&root , 2 ) ;
    push(&root , 3 ) ;

    cout << pop(&root) << " popped from stack\n";
 
    cout << "Top element is " << peek(root) << endl;


    return 0;
}