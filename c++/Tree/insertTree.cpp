
/*

properties:  https://www.geeksforgeeks.org/binary-tree-set-2-properties/

*/

#include <iostream>
#include <queue>

using namespace std; 

struct Node {
    int data ;
    struct Node* right;
    struct Node* left ;  

    Node (int val) {
        data = val ;
        left = NULL;
        right = NULL;
    }
};

Node* InsertNode (Node* root, int data) {
    if ( root == NULL ) {
        root = new Node(data);
        return root ;
    }
    queue<Node*> q ;
    q.push(root) ;

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp ->left != NULL) {
            q.push(temp->left);
        }else {
            temp->left = new Node(data);
            return root;
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        }else {
            temp ->right = new Node(data) ;
            return root ;
        }
    }

}

void inorder(Node* temp)
{
    if (temp == NULL)
        return;
 
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}

int main(int argc, char const *argv[])
{
    Node* root = new Node(10);
    root->left = new Node(11);
    root->left->left = new Node(7);
    root->right = new Node(9);
    root->right->left = new Node(15);
    root->right->right = new Node(8);
 
    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;
 
    int key = 12;
    root = InsertNode(root, key);
 
    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;

    return 0;
}
