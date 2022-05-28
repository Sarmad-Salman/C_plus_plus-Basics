/*Lab 9
Sarmad Salman
Muhammad Hassaan*/
#include<iostream>
using namespace std;
struct Node{
    int data, height;
    Node *left, *right;
};
int height(Node *N){
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b){
    return (a > b) ? a : b;
}
Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Node *riteRot(Node *y){
    Node *x = y->left;
    Node *i = x->right;
    x->right = y;
    y->left = i;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
Node *lftRot(Node *x){
    Node *y = x->right;
    Node *i = y->left;
    y->left = x;
    x->right = i;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
int level(Node *N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
Node* insert(Node* node, int data){
    if (node == NULL)
        return(newNode(data));
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else 
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = level(node);
    if (balance > 1 && data < node->left->data)
        return riteRot(node);
    if (balance < -1 && data > node->right->data)
        return lftRot(node);
    if (balance > 1 && data > node->left->data){
        node->left = lftRot(node->left);
        return riteRot(node);
    }
    if (balance < -1 && data < node->right->data){
        node->right = riteRot(node->right);
        return lftRot(node);
    }
    return node;
}
void preOrder(Node *root){
    if(root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(Node *root){
    if(root != NULL){
        inOrder(root->left);
        cout<< root->data <<" ";
        inOrder(root->right);
    }
}
void postOrder(Node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<< root->data <<" ";
    }
}
int main()
{
    Node *root = NULL; int data;
    while(true){
        cout<<"Enter an integer to insert in the AVL Tree, press -99 to exit: ";
        cin>>data;
        if (data == -99)
            break;
        root = insert(root, data);
    }
    cout<<"PreOrder traversal of the AVL Tree is: \n";
    preOrder(root);
    cout<<"\nInOrder Traversal of the AVL Tree is: \n";
    inOrder(root);
    cout<<"\nPostOrder Traversal of the AVL Tree is: \n";
    postOrder(root);
    return 0;
}