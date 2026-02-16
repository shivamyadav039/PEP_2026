#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    void inorder(Node* root){
        if(root==NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

        void preorder(Node* root){
        if(root==NULL) return;
        
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    int count(Node* root){
        if(root == NULL) return 0;
        int x = count(root->left);
        int y = count(root->right);
        return x+y+1;
    }
    int countleafnode(Node* root){
        if(root==NULL || root->left == NULL && root->right) return 1;
        
        int y = countleafnode(root->right);
        
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->inorder(root);
    cout<<endl;

    int res = root->count(root);
    cout<<res;
}
