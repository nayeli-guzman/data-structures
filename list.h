// list == double linked list

#include <iostream>

template<typename T>
struct Node {
    T val;
    Node<T>* next;
    Node<T>* prev;

    Node(): next(nullptr), prev(nullptr){}
    Node(T _val) : val(_val), next(nullptr), prev(nullptr){}

};


template<typename T>
class list {

    Node<T>* head;
    Node<T>* tail;
    int nodes;

    public:

    list(): head(nullptr), tail(nullptr), nodes(0) {}

    ~list(){
        clear();
    }

    T front(){
        return head->val;
    }

    T back() {
        return tail->val;
    }

    bool empty() {
        return head == nullptr && tail == nullptr;
    }

    void push_front(T val) {
        
        Node<T>* node = new Node<T>(val);

        if(empty()) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        } nodes++;

    }

    void push_back(T val){
        
        Node<T>* node = new Node<T>(val);
        if(tail==nullptr) {
            head = node;
            tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }nodes++;
    }

    void pop_front(){

        if(empty()){
            throw std::runtime_error("list is empty");
        }

        if(head == tail){
            head = nullptr;
            tail = nullptr;
        } else {
            Node<T>* waste=head;
            head = head->next;
            head->prev = nullptr;
            delete waste;
            waste = nullptr;
        } nodes--;
        
    }

    void pop_back(){
        if(empty()){
            throw std::runtime_error("list is empty");
        }
        if(tail == head) {
            tail = nullptr;
            head = nullptr;
        } else {
            Node<T>* waste = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete waste;
            waste = nullptr;
        } nodes--;

    }

    void display(){
        
        Node<T>* temp = head;

        std::cout<<"[";
        while (temp != nullptr) {

            std::cout << temp->val << " ";

            temp=temp->next;
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
        Node<T>* temp = head; //2
        
        for(int i=0; i<idx-1; i++) // <1
            temp = temp->next;

        node->prev = temp;
        node->next = temp->next;
        temp->next->prev = node;
        temp->next = node;
        nodes++;
    }

    void remove(int idx) {
    
        if (nodes<idx+1 || idx<0) 
            throw std::runtime_error("index out of range");

        if(idx==0) {
            pop_front();
            return;
        } else if(idx==nodes-1) {
            pop_back();
            return;
        }

        Node<T>* temp = head;

        for(int i=0; i<idx-1; i++) 
            temp = temp->next;

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

        if(idx == nodes-1) return tail->val;

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
        
        while(head->next != nullptr){

            head = head->next;

            delete head->prev;
            head->prev = nullptr;

        }

        head = nullptr;
        tail = nullptr;
        nodes = 0;
    }

    void reverse() {
        
        Node<T>* curr = head;
        Node<T>* prev = nullptr;

        while (curr != nullptr) { 

            prev = curr->prev;
            curr->prev = curr->next;
            curr->next = prev;
            curr = curr->prev;

        }
        
        head = tail;
        tail = curr;

    }

};