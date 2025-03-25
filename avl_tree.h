#include <iostream>

template<typename T>
struct Node {
    T data;
    int height;
    Node<T>* left;
    Node<T>* right;
    bool visited;

    Node(T _data):data(_data), height(-1), left(nullptr), right(nullptr), visited(false){}
    Node(T _data, int _height):data(_data), height(_height), left(nullptr), right(nullptr), visited(false){}

};

template<typename T>
class avl_tree {

    Node<T>* root;

    public:

    avl_tree():root(nullptr){}

    void insert(T val) {
        if(root==nullptr) {
            root = new Node<T>(val, 0);
        } else {
            insert_aux(root, val);
        }
    }

    void in_order(){
        in_order_aux(root); std::cout << std::endl;
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



    private:

    void insert_aux(Node<T>* &node, T val) {

        if(node==nullptr) {
            node = new Node<T>(val, 0);
            return;
        } 

        if(node->data > val) {
            insert_aux(node->left, val);
        } else {
            insert_aux(node->right, val);
        }

        update_height(node);
        balance(node);

    }

    void update_height(Node<T>* &node) {
        if(node==nullptr) return;

        int right = (node->right!=nullptr) ? node->right->height : -1;
        int left = (node->left!=nullptr) ? node->left->height : -1;

        node->height = std::max(right, left) +1;
    }

    void left_rotation(Node<T>* &x){
        Node<T>* z = x->right;
        x->right = z->left;
        z->left = x;
        x = z;
        update_height(x->left);
        update_height(x);

    }

    void right_rotation(Node<T>* &y) {
        Node<T>* z = y->left;
        y->left = z->right;
        z->right = y;
        y = z;
        update_height(y->right);
        update_height(y);
    }

    void in_order_aux(Node<T>* node){
        
        if(node == nullptr) return;
        
        in_order_aux(node->left);
        std::cout <<"value: " << node->data << " height: " << node->height << std::endl;
        in_order_aux(node->right);
    }

    void balance(Node<T>* &node) {

        if(node==nullptr) return;
        
        if (hb(node) >= 2) {
            if(hb(node->left) <= -1)
                left_rotation(node->left);
            right_rotation(node);

        }

        if(hb(node) <= -2) {
            if(hb(node->right) >= 1)
                right_rotation(node->right);
            left_rotation(node);
        }
    }

    int hb(Node<T>* node){
        int right = (node->right!=nullptr) ? node->right->height : -1;
        int left = (node->left!=nullptr) ? node->left->height : -1;
        return left - right;
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
        }

        // when it has just 1 child;
        else if(waste->left==nullptr && waste->right!=nullptr) {
            if(par->left!=nullptr && par->left->data==val) par->left = waste->right;
            else par->right = waste->right;
            delete waste;
            waste = nullptr;
        }

        else if(waste->left!=nullptr && waste->right==nullptr) {
            if(par->left!=nullptr && par->left->data==val) par->left = waste->left;
            else par->right = waste->left;
            delete waste;
            waste = nullptr;
        }

        // when it has 2 children
        else if(waste->left!=nullptr && waste->right!=nullptr) {
            Node<T>* pred = min_value_aux(waste->right);
            T new_data = pred->data;
            remove_aux(root, pred->data);

            if(par->right!=nullptr && par->right->data==val) 
                par->right->data = new_data;
            
            if(par->left!=nullptr && par->left->data==val)
                par->left->data = new_data;
            
            std::cout << new_data << std::endl;
        }

        update_height(par);


    }


};