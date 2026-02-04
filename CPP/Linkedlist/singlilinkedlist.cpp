#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtEnd(Node* &head, int val){
    Node* node = new Node(val);

    if(head == NULL){
        head = node;
        return;
    }

    Node* temp = head;


    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
}
void insertAtBeg(Node* &head,int val){
    Node* node = new Node(val);
    if(head == NULL){
        head =node;
        return;
    }
    node->next = head;
    head = node;
}
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
void insertAtpos(Node* &head,int val,int pos){
    Node* node = new Node(val);
    if(pos==1){
        node->next = head;
        head = node;
        return;
    }
    Node* temp = head;
    for(int i=1;i<pos-1 && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp==NULL){
        return;
    }
    node->next = temp->next;
    temp->next = node;
}
 
int main()
{
    Node* head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtBeg(head,5);
    insertAtpos(head,100,1);
    print(head);
    
}