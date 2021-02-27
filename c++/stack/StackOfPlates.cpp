#include <iostream>
#include <vector>
#include <stack>

using namespace std ;


class Stack : public stack<int> {
    int capacity ;
    public:
        Stack(int cap ) {
            capacity = cap ;
        }

        void push (int x) {
            if (stack::size() >= capacity ) {
                cout << "stack is full" << endl ;
            }else {
                stack::push(x) ;
            }    
        }

        bool isFull () {
            return capacity == (stack::size()) ;
        }

};

class SetOfStacks {
    vector< Stack* > v ;

    public:
        void push(int x) {
            Stack* s = getLastStack() ;
            if ( s != NULL ,  !s -> isFull() ) {
                cout << "not null " << endl ;
                s -> push(x) ;
            }else {
                cout << "null object " << endl ;
                Stack* s = new Stack (10) ;
                s->push(x);
                v.push_back(s) ;
            }
            
        }

        int pop() {

        }

        Stack* getLastStack () {
            if (v.size() > 0) {
                return v.back () ;
            }else {
                return NULL ;
            }
           
        }
};

 int main(int argc, char const *argv[])
 {

    //  vector< stack<int> > v ;
    
    // stack<int> s1 ;
    // stack<int> s2 ;

    // s1.push(5) ;

    // v.push_back(s1) ;
    // v.push_back(s2);
    
    // int value = v.at(0).top() ;

    // cout << value << endl ;

    SetOfStacks s ;
    s.push (10) ;


     return 0;
 }
 