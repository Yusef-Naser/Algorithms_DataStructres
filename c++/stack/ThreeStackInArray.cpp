#include <iostream>

using namespace std ; 

class ThreeStack {

    int *arr ;
    int size ;
    int top1, top2 , top3 ;
    public :
        ThreeStack(int n) {
            size = n ;
            arr = new int[size] ;
            top1 = (n/3) ;
            top2 = ( (2*n) / 3 ) ;
            top3 = ( (2*n) / 3 ) - 1 ;
        }
    
    void push_1 (int x) {
        if (top1 > 0) {
            top1-- ;
            arr[top1] = x ;
        }else {
            cout << "Stack Overflow by element : " << x << endl;
            return ;
        }
    }

    void push_2 (int x ) {
        if (top2 > ( size /3) ) {
            top2-- ;
            arr[top2] = x ;
        }else {
            cout << "Stack Overflow by element : " << x << endl;
            return ;
        }
    }

    void push_3 (int x) {

        if (top3 < ( size - 1) ) {
            top3++ ;
            arr[top3] = x ;
        }else {
            cout << "Stack Overflow by element : " << x << endl;
            return ;
        }
    }

    int pop_1 () {
        if (top1 <= size/3 - 1 ) {
            int x = arr[top1] ;
            top1++ ;
            return x ;
        }else {
            cout << "Stack Underflow "  << endl;
            exit(1); 
        }
        
    }

    int pop_2 () {
        if (top2 <= (2*size) / 3 - 1 ) {
            int x = arr[top2] ;
            top2++ ;
            return x ;
        }else {
            cout << "Stack Underflow "  << endl;
            exit(1); 
        }
    }

    int pop_3 () {
        if (top3 > ( (2* size ) / 3 ) - 1  ) {
            int x = arr[top3] ;
            top3-- ;
            return x ;
        }else {
            cout << "Stack Underflow "  << endl;
            exit(1); 
        }
    }

};

int main(int argc, char const *argv[])
{
    ThreeStack s(15) ;
    s.push_1(1) ;
    s.push_1(2) ;
    s.push_1(3) ;
    s.push_1(4) ;
    s.push_1(5) ;
    s.push_1(555) ;

    s.push_2(6) ;
    s.push_2(7) ;
    s.push_2(8) ;
    s.push_2(9) ;
    s.push_2(10) ;
    s.push_2(10000) ;

    s.push_3 (11) ;
    s.push_3(12) ;
    s.push_3(13) ;
    s.push_3(14) ;
    s.push_3(15) ;
    s.push_3(15555) ;


    cout << s.pop_3() << endl ;
    cout << s.pop_3() << endl ;
    cout << s.pop_3() << endl ;
    cout << s.pop_3() << endl ;
    cout << s.pop_3() << endl ;
//    cout << s.pop_3() << endl ;


    cout << s.pop_2 () << endl ;
    cout << s.pop_2 () << endl ;
    cout << s.pop_2 () << endl ;
    cout << s.pop_2 () << endl ;
    cout << s.pop_2 () << endl ;
//    cout << s.pop_2 () << endl ;

    cout << s.pop_1() << endl;
    cout << s.pop_1() << endl;
    cout << s.pop_1() << endl;
    cout << s.pop_1() << endl;
    cout << s.pop_1() << endl;
//    cout << s.pop_1() << endl;
    
    return 0;
}
