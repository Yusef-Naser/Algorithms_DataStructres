#include<iostream>
#include <queue>

using namespace std ;

struct Node {
    int key;
    struct Node *left, *right;
};

Node* newNode (int key) {
    Node* node = new Node ;
    node ->key = key; 
    node->left = node ->right = NULL ;
    return node ;
}

void inorder (Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->key << "  " << endl;
    inorder(root ->right) ;
}

void deleteDeepestNode (Node* root , Node* d_Node) {

    queue <Node*> q ;
    q.push(root);

    Node* temp ;
    while (!q.empty())
    {
        temp = q.front() ;
        q.pop() ;

        if (temp == d_Node ){
            temp = NULL;
            delete(d_Node);
            return ;
        }
        if (temp->right) {
            if(temp->right == d_Node){
                temp->right = NULL ;
                delete(d_Node);
                return ;
            }else {
                q.push(temp->right);
            }
        }
        if (temp->left) {
            if(temp->left == d_Node){
                temp->left = NULL ;
                delete(d_Node);
                return ;
            }else {
                q.push(temp->left);
            }
        }
    }
    


}


Node* deletion (Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root ->left == NULL && root ->right == NULL) {
        if (root ->key == key) {
            return NULL;
        }else {
            return root; 
        }
    }

    queue<Node*> q ;
    q.push(root) ;

    Node* temp ;
    Node* d_Node = NULL ;

    while (!q.empty())
    {
        temp = q.front() ;
        q.pop() ;
        if (temp->key == key) {
            d_Node = temp ;
        }

        if (temp ->left) {
            q.push(temp->left) ;
        }
        if (temp ->right) {
            q.push(temp->right );
        }
    }

    if ( d_Node != NULL ) {
        int x = temp->key ;
        deleteDeepestNode(root , temp);
        d_Node ->key = x ;
    }
    
    return root ;
}

int main(int argc, char const *argv[])
{
    struct Node* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->left->right = newNode(12);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
 
    cout << "Inorder traversal before deletion : " << endl;
    inorder(root);
 
    int key = 11;
    root = deletion(root, key);
 
    cout << endl;
    cout << "Inorder traversal after deletion : " << endl;
    inorder(root);
    
    return 0;
}
