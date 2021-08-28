#include <iostream>

using namespace std ;

struct Node
{
    int key, count ;
    Node *left, *right;
};

Node* newNode (int key) {
    Node* node = new Node();
    node->count = 1 ;
    node->key = key ;
    node ->left = node->right = NULL;
    return node ;
}

void inorder(Node* root) {
    if (root == NULL) {
        return ;
    }
    inorder(root->left) ;
    cout << root->key << "(" << root->count << ")" << endl;
    inorder(root->right);
}

Node* insert (Node* root , int key) {
    if (root == NULL) return newNode(key);
    if (root->key == key) {
        (root->count) ++ ;
        return root ;
    }

    if (root->key > key) {
        root ->left = insert(root->left , key);
    }else {
        root->right = insert(root->right , key) ;
    }
    return root ;
}

Node* minValueNode(Node* root) {
    Node* current = root ;
    while (root ->left != NULL) {
        current = current->left ;
    }
    return current ;
    
}

Node* deleteNode (Node* root , int key ) {
    if (root == NULL) return root ;

    if (root->key > key ) {
        root->left = deleteNode(root->left , key);
    }else if (root->key < key) {
        root->right = deleteNode(root->right , key) ;
    }else {
        if (root->count > 1) {
            (root->count)-- ;
            return root;
        }

        if (root->left == NULL) {
            Node *temp = root->right ;
            free(root);
            return temp;
        }else if (root->right == NULL) {
            Node *temp = root->left ;
            free(root) ;
            return temp;
        }

        Node *temp = minValueNode(root->right) ;
        root->key = temp->key;

        root->right = deleteNode(root->right , temp->key) ;


    }
    return root ;
}

int main(int argc, char const *argv[])
{

/* Let us create following BST
            12(3)
        /     \
    10(2)     20(1)
    / \
    9(1) 11(1) */
    struct Node *root = NULL;
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 9);
    root = insert(root, 11);
    root = insert(root, 10);
    root = insert(root, 12);
    root = insert(root, 12);
  
    cout << "Inorder traversal of the given tree " 
         << endl;
    inorder(root);
  
    cout << "\nDelete 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
  
    cout << "\nDelete 12\n" ;
    root = deleteNode(root, 12);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
  
    cout << "\nDelete 9\n";
    root = deleteNode(root, 9);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    return 0;
}
