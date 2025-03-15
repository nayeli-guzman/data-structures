//#include "list.h"
//#include "forward_list.h"
//#include "circular_list.h"
//#include "circular_array.h"
#include "hash_table.h"
#include <list>
//using namespace std;

int main(){

    hash_table<int, int> hash;

    hash.insert(6,2);
    hash.insert(10,1);
    hash.insert(5,1);
    hash.insert(6,0);
    hash.insert(5,0);
    hash.insert(4,0);
    hash.insert(3,0);
    hash.insert(2,0);
    hash.insert(6,0);
    hash.insert(11,0);
    hash.insert(10,0);
    hash.insert(9,0);
    hash.insert(8,0);
    hash.insert(7,0);
    hash.insert(1,0);
    hash.insert(4,3);
    hash.insert(1,8);
    hash.insert(12,1);

    hash.display();

    std::cout << hash.find(3);
    //std::cout << hash.find(30);
    hash.remove(3);
    hash.display();

    hash.remove(8);
    hash.remove(10);
    hash.display();
    hash.remove(9); 
    hash.display();


    /*
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

    s.remove(3);

    
    s.display();

    std::cout << s[3] << std::endl;
    std::cout << s[s.size()-1] << std::endl;

    s.reverse();
    s.display();
*/

    return 0;

}