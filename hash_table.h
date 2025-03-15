#include <iostream>

const int max_col = 3;

size_t fhash(const std::string& key) {
    size_t hash = 0;
    for (char c : key) {
        hash = hash * 31 + c;
    }
    return hash;
}

size_t fhash(int key) {
    return std::hash<int>{}(key);
}

template<typename TK, typename TV>
struct Node {
    Node* next;
    TK key;
    TV value;

    Node(TK _key, TV _value):key(_key),value(_value),next(nullptr){}

};

template<typename TK, typename TV>
class hash_table{
    
    int capacity;
    int size;
    Node<TK, TV>** array; //[[][][]]

    public:

    hash_table(int _capacity=5) : capacity(_capacity), size(0) {
        
        array = new Node<TK,TV>*[capacity];

        for(int i=0; i<capacity; i++) {
            array[i] = nullptr;
        }

    }

    void insert(TK key, TV value){

        size_t hash_code = fhash(key);
        int idx = hash_code % capacity;

        int i=0;
        Node<TK, TV>* curr = array[idx];
        Node<TK, TV>* node = new Node<TK, TV>(key, value);

        if(curr != nullptr) {

            while (curr->next != nullptr) {
                if(curr->key == key) {
                    curr->value = value;
                    return;
                }
                curr = curr->next; i++;
            }

            if(curr->key == key) {
                curr->value = value;
                return;
            }

            if(i+1>=max_col) {
                rehashing();
            }

            curr->next = node;
            
        } else {array[idx] = node;}
        size++;
    }

    TV find(TK key) {
        size_t hash_code = fhash(key);
        int idx = hash_code % capacity;

        Node<TK,TV>* current = array[idx];
        while (current != nullptr) {
            if(current->key == key) return current->value;
            current = current->next;
        } 
        throw std::runtime_error("key doesn't exist");
    }

    void remove(TK key) {
        size_t hash_code = fhash(key);
        int idx = hash_code % capacity;

        Node<TK,TV>* current = array[idx];

        if(current->key == key) {
            Node<TK,TV>* waste = current;
            current = current->next;
            delete waste;
            waste = nullptr;
            array[idx] = current;
            size--;
            return;
        }

        while (current != nullptr) {
            if(current->next->key == key) {
                Node<TK,TV>* waste = current->next;
                current->next = current->next->next;
                delete waste;
                waste = nullptr;
                size--;
                return;
            }
            current = current->next;
        } 
        throw std::runtime_error("key doesn't exist");
    }

    void display() {

        std::cout << "{";
        for(int i=0; i<capacity; i++) {

            Node<TK,TV>* temp = array[i];
            if (temp==nullptr) continue;
            
            while (temp!=nullptr) {
                std::cout << temp->key << ": " << temp->value << ", ";
                temp = temp->next;                
            } std::cout << std::endl;
            
        }
        std::cout << "}" << std::endl;

    }
    
    int size() {
        return size;
    }
    
    private:

    void rehashing(){
        int new_capacity = capacity*2;
        Node<TK,TV>** new_array = new Node<TK,TV>*[new_capacity];

        for(int i=0; i<new_capacity; i++) {
            new_array[i] = nullptr;
        }

        for (int i=0;i<capacity; i++) {
            if(array[i] == nullptr) continue;
            Node<TK,TV>* temp = array[i];
            while (temp!=nullptr) {
                size_t hash_code = fhash(temp->key);
                int idx = hash_code % new_capacity;
                Node<TK,TV>* next = temp->next;
                temp->next = new_array[idx];
                new_array[idx] = temp;
                temp = next;
            }
            
        }

        delete[] array;
        array = nullptr;

        array = new_array;
        capacity = new_capacity;
    }

};
