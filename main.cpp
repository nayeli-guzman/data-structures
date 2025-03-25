//#include "list.h"
//#include "forward_list.h"
//#include "circular_list.h"
//#include "circular_array.h"
//#include "hash_table.h"
#include "tree.h"
#include <list>
//using namespace std;

int main(){

    tree<int> tree;

    tree.insert(35);
    tree.insert(25);
    tree.insert(17);
    tree.insert(10);
    tree.insert(28);
    tree.insert(27);
    tree.insert(26);
    tree.insert(30);
    tree.insert(29);
    tree.insert(31);
    tree.insert(23);
    tree.insert(20);
    tree.insert(24);

    tree.insert(40);
    tree.insert(36);
    tree.insert(48);
    tree.insert(60);
    tree.insert(54);
    tree.insert(50);
    tree.insert(55);
    tree.insert(68);
    tree.insert(67);
    tree.insert(70);

    tree.in_order();

    tree.remove(20);
    tree.remove(48);
    
    tree.in_order();

    tree.remove(40);
    tree.pre_order();
    
    tree.remove(25);
    tree.pre_order();

    tree.remove(35);
    tree.remove(36);
    tree.remove(50);
    tree.remove(26);
    tree.remove(17);
    tree.remove(54);
    tree.remove(60);
    tree.remove(27);
    tree.remove(28);
    tree.remove(55);
    tree.remove(67);
    tree.remove(68);
    tree.remove(70);
    
    tree.remove(31);
    tree.remove(23);
    tree.remove(29);
    tree.remove(30);

    tree.pre_order();

    tree.clear();

    tree.in_order();
    std::cout << tree.height() << std::endl;
    
    tree.insert(35);
    tree.insert(25);
    tree.insert(17);
    tree.insert(10);
    tree.insert(28);
    tree.insert(27);
    tree.insert(26);

    std::cout << tree.height() << std::endl;

    /*
    std::cout << tree.find(6) << std::endl;
    std::cout << tree.find(12) << std::endl;

    tree.pre_order();
    tree.post_order();

    std::cout << tree.height() << std::endl;
    std::cout << tree.min_value() << std::endl;
    std::cout << tree.max_value() << std::endl;
*/
    

    /*
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

*/
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