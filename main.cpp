//#include "list.h"
//#include "forward_list.h"
//#include "circular_list.h"
#include "circular_array.h"
#include <list>
//using namespace std;

int main(){

    std::list<int> n;

    circular_array<int> s;

    s.push_front(1);
    s.push_front(2);
    s.push_front(3);
    s.push_front(4);
    s.push_front(5);

    s.display();


    s.push_back(10);
    s.push_back(0);
    s.push_back(7);
    s.push_back(9);

    s.display();

    s.pop_front();
    s.pop_front();
    
    std::cout << s.size();

    s.display();


    s.pop_back();
    s.pop_back();
    s.pop_back();


    s.display();

    
    s.insert(19,0);
    s.display();
/*
    s.remove(3);

    
    s.display();

    std::cout << s[3] << std::endl;
    std::cout << s[s.size()-1] << std::endl;
*/
    s.reverse();
    s.display();


    return 0;

}