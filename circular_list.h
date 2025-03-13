#include <iostream>

template<typename T>
struct Node {
    T val;
    Node<T>* next;
    Node<T>* prev;

    Node():next(nullptr), prev(nullptr){}
    Node(T _val):val(_val), next(nullptr), prev(nullptr){}
};

template<typename T>
class circular_list {

    Node<T>* head;
    int nodes;

    public:

    circular_list(){
        head = new Node<T>();
        head->next = head;
        head->prev = head;
        nodes = 0;
    }

    ~circular_list(){
        clear();
    }

    T front() {
        if(empty()) 
            throw std::runtime_error(" circular list is empty");
        return head->next->val;
    }

    T back() {
        if(empty()) 
            throw std::runtime_error(" circular list is empty");
        return head->prev->val;
    }

    bool empty(){
        return head == head->prev && head == head->next;
    }

    void push_front(T val) {

        Node<T>* node = new Node<T>(val);

        node->next = head->next;
        node->prev = head;

        head->next = node;
        head->next->next->prev = node;

        nodes++;

    }

    void push_back(T val){

        Node<T>* node = new Node<T>(val);
        
        node->next = head;
        node->prev = head->prev;
        head->prev->next = node;
        head->prev = node;
        nodes++;

    }

    void pop_back() {

        if(empty()) 
            throw std::runtime_error(" circular list is empty");

        Node<T>* waste = head->prev;

        head->prev = head->prev->prev;
        head->prev->next = head;

        delete waste;
        waste = nullptr;
        nodes--;

    }

    void pop_front() {
        
        if(empty()) 
            throw std::runtime_error(" circular list is empty");

        Node<T>* waste = head->next;

        head->next = head->next->next;
        head->next->prev = head;

        delete waste;
        waste = nullptr;
        nodes--;

    }

    void display() {
        
        Node<T>* temp = head;

        std::cout << "[";

        while (temp->next != head) {
            
            temp = temp->next;
            std::cout << temp->val << " ";

        }      
        
        std::cout << "]" << std::endl;

    }

    void insert(T val, int idx) {

        if (nodes<idx+1 || idx<0) 
            throw std::runtime_error("index out of range");

        Node<T>* node = new Node<T>(val);
        Node<T>* temp = head;

        for(int i=0; i<= idx-1; i++)
            temp =temp->next;

        node->next = temp->next;
        node->prev = temp;
        temp->next->prev = node;
        temp->next = node;
        nodes++;

    }

    void remove(int idx) {

        if (nodes<idx+1 || idx<0) 
            throw std::runtime_error("index out of range");

        Node<T>* temp = head;

        for(int i=0; i<= idx-1; i++)
            temp =temp->next;
        
        Node<T>* waste = temp->next;     

        temp->next->next->prev = temp;
        temp->next = temp->next->next;
        delete waste;
        waste = nullptr;
        nodes--;

    }

    T& operator[](int idx) {

        if (nodes<idx+1 || idx<0) 
            throw std::runtime_error("index out of range");

        if(idx == nodes-1) return head->prev->val;

        Node<T>* temp = head->next;
        
        for(int i=0; i<idx; i++)
            temp = temp->next;

        return temp->val;
    }

    int size() {
        return nodes;
    }

    void clear() {

        if(empty()) return;
        
        Node<T>* temp = head->next;

        while(temp->next != head){

            temp = temp->next;
            delete temp->prev;
            temp->prev = nullptr;

        }

        delete temp;
        temp = nullptr;
        head->next = head;
        head->prev = head;
        nodes = 0;
    }

    void reverse() {
        
        Node<T>* curr = head->next;
        Node<T>* next = nullptr;

        while(curr != head) {
            next = curr->next;
            curr->next = curr->prev;
            curr->prev = next;
            curr = next;
        }
        next = head->next;
        head->next = head->prev;
        head->prev = next;
    }

};