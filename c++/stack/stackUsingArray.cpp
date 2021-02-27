#include <iostream>

#define MAX 1000 

using namespace std ;

class Stack {
    int top ;
    
    public:
        int a[MAX] ;
        Stack () {
            top = -1 ;
        }

        bool push (int number) {
            if (top >= ( MAX-1 )) {
                cout << "Stack Overflow" ;
                return false ;
            }
            a[++top] = number;
            cout << number << " pushed into stack" << endl ;
            return true ;

        }
        
        int pop () {
            if (top < 0) {
                cout << "stack underflow" << endl ;
                return 0 ;
            }
            int x = a[top--] ;
            return x ;
        }

        int peek () {
            if (top < 0) {
                cout << "stack is empty" ;
                return 0 ;
            }
            int x = a[top] ;
            return x ;
        }

        bool isEmpty () {
            return (top < 0) ;
        }

};

int main(int argc, char const *argv[])
{
    
    Stack s ;
    s.push(5) ;
    s.push(10) ;

    cout << s.pop() << endl ;
    cout << s.pop() << endl ;
    cout << s.pop() << endl ;
    
    return 0;
}
