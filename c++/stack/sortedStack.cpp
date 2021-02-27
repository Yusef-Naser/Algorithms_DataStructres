#include <iostream>
#include <stack>

using namespace std ;


class SortedStack : public stack<int> {
    stack temp ;
    public :
        void push (int x) {
            if (stack::empty()) {
                stack::push(x) ;
            }else {
                manageSortedItems(x) ;
            }
        }
        
        void manageSortedItems ( int x ) {
            int value = stack::top() ;
             if (value >= x) {
                stack::push(x) ;
              }else {
                transferItemsToTemp(x) ;
            }
                
            
        }

        void transferItemsToTemp ( int x ) {
            while ( ! stack::empty()) {
                int value = stack::top() ;
                if (value < x) {
                    stack::pop() ;
                    temp.push(value) ;
                }else {
                    stack::push(x);
                    transferItemsToMainStack();
                    break;
                }
            }
            if (stack::empty()) {
                stack::push(x);
                 transferItemsToMainStack();
            }
            

        }

        void transferItemsToMainStack () {
            while ( ! temp.empty()) {
                int s = temp.top() ;
                temp.pop();
                stack::push(s) ;
            }
        }


};

int main(int argc, char const *argv[])
{
     SortedStack s ;
     s.push(10) ;
     s.push(20);
     s.push(8) ;
     s.push(30);
     s.push(9);
     s.push(5) ;
     s.push(40) ;
     s.push(4) ;
     s.push(35);


    while (!s.empty())
    {
        cout << "value : " << s.top() << endl ;
        s.pop();
    }
    
    return 0;
}
