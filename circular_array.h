#include <iostream>

template<typename T>
class circular_array {

    T *array;
    int capacity;
    int back, front;

    public:

    circular_array(int _capacity=5) : capacity(_capacity), front(-1), back(-1) {
        array = new T [capacity];
    }

    bool is_empty() {
        return front == -1 && back == -1;
    }

    bool is_full() {
        return  size() == capacity;
    }

    void push_front(T val) {
        if(is_empty()) {
            front = back = 0;
        } else if (is_full()){
            resize();
            front = prev(front);
        } else{
            front = prev(front);
        } array[front] = val;

    }

    void push_back(T val){
        if(is_empty()) {
            front = back = 0;
        } else if (is_full()){
            resize();
            back = next(back);
        } else{
            back = next(back);
        } array[back] = val;

    }

    void pop_front() {
        
        if(is_empty()) {
            throw std::runtime_error(" circular array is empty");
        }

        if(front==back) {
            front = back = -1;
        } else {
            front = next(front);
        }   
    
    }

    void pop_back() {

        if(is_empty()) {
            throw std::runtime_error(" circular array is empty");
        }

        if(front==back) {
            front = back = -1;
        } else {
            back = prev(back);
        }   

    }

    void insert(T val, int idx) {
        if(idx>=size() || idx<0)
            throw std::runtime_error("index out of range");
        
        if(is_full()) {
            resize();
        }

        int temp = front, curr, last;
        for(int i=0; i<=this->size(); i++) {
            if(i >= idx) {
                curr = array[temp];
                array[temp] = val;
                val = curr;
            }
            temp = next(temp);
        }

        back = next(back);

    }

    void display() {

        int temp = front;

        std::cout << "[ ";
        for (int i=0; i<size(); i++) {
            std::cout << array[temp] << " ";
            temp = next(temp);
        }
        std::cout << "]" << std::endl;
        

    }
    
    int size() {

        if(is_empty()) return 0;
        if(front==back) return 1;
        if(back>front) return back-front+1;
        return capacity-front+back+1;

    }

    void clear(){
        front = back = -1;
    }

    void reverse() {
        T* new_array = new T[capacity];
        int temp = back;
        for (int i=0; i<this->size(); i++) {
            new_array[i] = array[temp];
            temp = prev(temp);
        }
        delete [] array;
        back = size()-1;
        front = 0;
        array = nullptr;
        array = new_array;
    }

    private:

    void resize(){
        int new_capacity = capacity*2;
        T* new_arr = new T[new_capacity];
        for(int i=0; i<capacity; i++) {
            new_arr[i] = array[front];
            front = next(front);
        } 
        delete [] array;
        array = nullptr;
        front = 0;
        back = capacity-1;
        array = new_arr;
        capacity = new_capacity;
    }

    int prev(int idx) {
        return idx-1<0 ? capacity-idx-1 : idx-1;
    }

    int next(int idx) {
        return (idx+1) % capacity ;
    }

};