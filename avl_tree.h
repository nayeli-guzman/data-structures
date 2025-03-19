#include <iostream>

template<typename T>
struct Node {
    T data;
    int height;
    Node<T>* left;
    Node<T>* right;
    bool visited;

    Node(T _data):data(_data), left(nullptr), right(nullptr), visited(false){}
};

class avl_tree {

};