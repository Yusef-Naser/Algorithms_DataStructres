#include <iostream> 
#include <stack>

using namespace std ;

//enQueue operation costly
struct Queue1
{
    stack<int> s1 , s2 ;
    
    void enQueue (int x ){ 
        while ( !s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x) ;
        while (!s2.empty())
        {
            s1.push(s2.top()) ;
            s2.pop();
        }
        
        
    }

    int deQueue () {
        if (s1.empty()) {
            cout << "Q is empty" ;
            exit(0) ;
        }       
        int x = s1.top() ;
        s1.pop() ;
        return x ;
    }

};

//deQueue operation costly
struct Queue2 
{
    stack<int> s1, s2; 

    void enQueue (int x ) {
        s1.push(x) ;
    }

    int deQueue () {
        if (s1.empty() && s2.empty()) {
            cout << "Q is empty" ;
            exit(0) ;
        }
        if (s2.empty()) {
            while (!s1.empty())
            {
                s2.push(s1.top()) ;
                s1.pop() ;
            }
        }
        int x = s2.top() ;
        s2.pop() ;
        return x ;
    }

};

//using Function Call Stack
struct Queue3
{
    stack<int> s ;
    void enQueue(int x) {
        s.push(x) ;
    }

    int deQueue () {
        if (s.empty()) {
            cout << "Q is empty" ;
            exit(0); 
        }
        int x = s.top() ;
        s.pop() ;

        

        if (s.empty()) {
            return x ;
        }
        int item = deQueue(); 

        s.push(x) ;

        while (!s.empty())
        {
            cout << s.top() << endl;
            s.pop() ;
        }
        


        return item ;
    }

};



int main(int argc, char const *argv[])
{
    
  //  Queue1 q; 
  //  Queue2 q ;
    Queue3 q ;
    q.enQueue(1); 
    q.enQueue(2); 
    q.enQueue(3); 
  
    cout << q.deQueue() << '\n'; 
    // cout << q.deQueue() << '\n'; 
    // cout << q.deQueue() << '\n'; 
    return 0;
}
