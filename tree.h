#include <iostream>

template<typename T>
struct Node {
    T data;
    int height;
    Node<T>* left;
    Node<T>* right;

    Node(T _data):data(_data), left(nullptr), right(nullptr){}
};

template<typename T>
class tree {

    Node<T>* root;

    public:

    tree():root(nullptr){}

    ~tree(){
        this->clear();
    }

    void insert(T val) {
        if(root==nullptr) {
            root = new Node<T>(val);
        } else {
            insert_aux(root, val);
        }
    }

    bool find(T val) {
        return find_aux(root, val) == nullptr? false:true;
    }

    void in_order(){
        in_order_aux(root); std::cout << std::endl;
    }

    void pre_order() {
        pre_order_aux(root); std::cout << std::endl;
    }

    void post_order() {
        post_order_aux(root); std::cout << std::endl;
    }
    
    int height(){
        if(root==nullptr) return -1;
        return 1 + std::max(height_aux(root->right), height_aux(root->left));
    }

    T min_value(){
        return min_value_aux(root)->data;
    }

    T max_value(){
        return max_value_aux(root)->data;
    }

    void remove(T val) {

        if(val==root->data) {
            if(root->left==nullptr && root->right==nullptr)
                root = nullptr;
            else if(root->left!=nullptr && root->right==nullptr) {
                Node<T>* pred = max_value_aux(root->left);
                T new_data = pred->data;
                remove_aux(root, pred->data);
                root->data = new_data;
            }
            else if ((root->left==nullptr && root->right!=nullptr)||
                    (root->left!=nullptr && root->right!=nullptr)) {
                Node<T>* pred = min_value_aux(root->right);
                T new_data = pred->data;
                remove_aux(root, pred->data);
                root->data = new_data;
            }
            return;
        }

        remove_aux(root, val);
    }

    void clear() {
        clear_aux(root);
    }

    private:

    int height_aux(Node<T>* node) {
        if(node == nullptr) return -1;
        return 1 + std::max(height_aux(node->right), height_aux(node->left));
    }

    void insert_aux(Node<T>* &node, T val) {

        if(node==nullptr) {
            node = new Node<T>(val);
            return;
        } 

        if(node->data > val) {
            insert_aux(node->left, val);
        } else {
            insert_aux(node->right, val);
        }

    }

    Node<T>* find_aux(Node<T>* node, T val){

        if(node == nullptr) {
            return nullptr;
        }

        if(node->data == val) {
            return node;
        }

        if(node->data > val) {
            return find_aux(node->left, val);
        } else {
            return find_aux(node->right, val);
        }

    }

    void in_order_aux(Node<T>* node){
        
        if(node == nullptr) return;
        
        in_order_aux(node->left);
        std::cout << node->data << " ";
        in_order_aux(node->right);
    }

    void pre_order_aux(Node<T>* node) {
        if(node==nullptr) return;
        std::cout << node->data << " ";
        pre_order_aux(node->left);
        pre_order_aux(node->right);
    }

    void post_order_aux(Node<T>* node) {
        if(node==nullptr) return;
        post_order_aux(node->left);
        post_order_aux(node->right);
        std::cout << node->data << " ";
    }

    Node<T>* min_value_aux(Node<T>* node) {
        Node<T>* temp = node;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        return temp;
    }
    
    Node<T>* max_value_aux(Node<T>* node){

        Node<T>* temp = node;
        while (temp->right != nullptr) {
            temp = temp->right;
        }
        return temp;

    }

    void remove_aux(Node<T>* &node, T val) {

        Node<T>* par = parent(root, val);
        if(par == nullptr) return;
        
        Node<T>* waste = (par->left!=nullptr && par->left->data==val)? par->left:par->right;

        // when it's a leave
        if(waste->left==nullptr && waste->right==nullptr) {
            
            if(par->left!=nullptr && par->left->data==val) par->left = nullptr;
            else par->right = nullptr;
            
            delete waste;
            waste = nullptr;
            return;
        }

        // when it has just 1 child;
        if(waste->left==nullptr && waste->right!=nullptr) {

            if(par->left!=nullptr && par->left->data==val)
                par->left = waste->right;
            else par->right = waste->right;

            delete waste;
            waste = nullptr;
            return;
        }

        if(waste->left!=nullptr && waste->right==nullptr) {

            if(par->left!=nullptr && par->left->data==val)
                par->left = waste->left;
            else par->right = waste->left;

            delete waste;
            waste = nullptr;
            return;
        }

        // when it has 2 children
        if(waste->left!=nullptr && waste->right!=nullptr) {
            Node<T>* pred = min_value_aux(waste->right);
            T new_data = pred->data;
            remove_aux(root, pred->data);

            if(par->right!=nullptr && par->right->data==val) 
                par->right->data = new_data;
            
            if(par->left!=nullptr && par->left->data==val)
                par->left->data = new_data;
            
            std::cout << new_data << std::endl;
        }

    }

    Node<T>* parent(Node<T>* node, T val) {
        if(node==nullptr) return nullptr;
        if((node->left!=nullptr && node->left->data==val) || (node->right!=nullptr && node->right->data==val))
            return node;
        
        if(node->data > val) {
            return parent(node->left, val);
        } else {
           return parent(node->right, val);
        }
    }

    void clear_aux(Node<T>* node){
        if(node==nullptr) return;
        clear_aux(node->left);
        clear_aux(node->right);
        remove(node->data);
    }

};