#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtBeg(Node* &head,int val){
    Node* node = new Node(val);
    if(head!=NULL){
        node->next = head;
        head->prev = node;
    }
    head = node;
}

void insertAtEnd(Node* &head,int val){
    Node* node = new Node(val);

    if(head==NULL){
        head = node;
        return;
    }

    Node* temp = head;
    while(temp->next!=NULL)
        temp = temp->next;

    temp->next = node;
    node->prev = temp;
}

void insertAtPos(Node* &head,int val,int pos){
    Node* node = new Node(val);

    if(pos==1){
        node->next = head;
        if(head!=NULL) head->prev = node;
        head = node;
        return;
    }

    Node* temp = head;
    for(int i=1;i<pos-1 && temp!=NULL;i++)
        temp = temp->next;

    if(temp==NULL) return;

    node->next = temp->next;
    node->prev = temp;

    if(temp->next!=NULL)
        temp->next->prev = node;

    temp->next = node;
}

void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"NULL";
}

int main(){
    Node* head = NULL;

    insertAtBeg(head,3);
    insertAtBeg(head,1);
    insertAtEnd(head,5);
    insertAtEnd(head,7);
    insertAtPos(head,9,3);

    display(head);
}


