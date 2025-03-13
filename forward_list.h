#include <stdexcept>
#include <iostream>

template<typename T>
struct Node {
    Node* next;
    T val;

    Node(): next(nullptr){}
    Node(T _val): val(_val), next(nullptr) {}
};

template<typename T>
class forward_list {

    private:

    Node<T>* head;
    int nodes;

    public:

    forward_list() : head(nullptr), nodes(0) {}

    ~forward_list() {
        clear();
    }

    T front() {

        if(empty()){
            throw std::runtime_error("forward list is empty");
        }

        return head->val;
    }

    T back() {
        if(empty()){
            throw std::runtime_error("forward list is empty");
        }

        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->val;

    }

    bool empty() {
        return head==nullptr;
    }

    void push_front(T val){ 

        Node<T>* node = new Node<T>(val);    
        node->next = head;
        head = node;
        nodes++;

    }

    void push_back(T val) {

        Node<T>* node = new Node<T>(val);
        
        if(empty()) {
            head = node;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = node;
        } nodes++;

    }

    void pop_front() {

        if(empty()){
            throw std::runtime_error("forward list is empty");
        }

        Node<T>* waste = head;
        head = head->next;
        delete waste;
        waste = nullptr;
        nodes--;

    }

    void pop_back(){

        if(empty()){
            throw std::runtime_error("forward list is empty");
        }

        if (head->next == nullptr) {
            head = nullptr;
        } else {
            Node<T>* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            Node<T>* waste = temp->next;
            temp->next = nullptr;
            delete waste;
            waste = nullptr;
        } nodes--;

    }

    void display(){

        Node<T>* temp = head;

        std::cout << "[";

        while (temp != nullptr) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }

        std::cout << "]" << std::endl;
        
    }

    void insert(T val, int idx) { // indexed from 0
        if (nodes<idx+1 || idx<0) 
            throw std::runtime_error("index out of range");

        if(idx==0) {
            push_front(val);
            return;
        }

        Node<T>* node = new Node<T>(val);
        Node<T>* temp = head;
        
        for(int i=0; i<idx-1; i++)
            temp = temp->next;

        node->next = temp->next;
        temp->next = node;
        nodes++;
    }

    void remove(int idx){ 

        if (nodes<idx+1 || idx<0) 
        throw std::runtime_error("index out of range");

        if(idx==0) {
            pop_front();
            return;
        }

        Node<T>* temp = head;
        
        for(int i=0; i<idx-1; i++)
            temp = temp->next;

        Node<T>* waste = temp->next;
        temp->next = temp->next->next;

        delete waste;
        waste = nullptr;

        nodes--;

    }

    T& operator[](int idx) {

        if (nodes<idx+1 || idx<0) 
            throw std::runtime_error("index out of range");

        Node<T>* temp = head;
        
        for(int i=0; i<idx; i++)
            temp = temp->next;

        return temp->val;
    }

    int size(){
        return nodes;
    }

    void clear() {

        if(empty()) return;

        while(head->next != nullptr) {
            Node<T>* waste = head;
            head = head->next;
            delete waste;
            waste = nullptr;
        }
        head = nullptr;
        nodes = 0;

    }

    void reverse(){

        Node<T>* curr = head, next=nullptr, prev = nullptr;

        while (curr != nullptr) {
            
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

        }

        head = prev;

    }

};