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

void insertAtBeg(Node* &head,int val){
    Node* node = new Node(val);

    if(head==NULL){
        head = node;
        node->next = head;
        return;
    }

    Node* temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }

    temp->next=node;
    node->next = head;
    head = node;
}

void insertAtEnd(Node* &head,int val){
    Node* node = new Node(val);

    if(head==NULL){
        head = node;
        head->next = head;
        return;
    }

    Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }

    temp->next = node;
    node->next = head;
}

void display(Node* head){
    if(head==NULL) return;

    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);

    
}

int main(){
    Node* head = NULL;

    insertAtBeg(head,3);
    insertAtBeg(head,1);
    insertAtEnd(head,5);
    insertAtEnd(head,7);
    insertAtBeg(head,100);

    display(head);
}



//deletion in circular linked list  at last
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




void display(Node* head){
    if(head==NULL) return;

    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    
}
void deleteLast(Node* &head){
    if(head==NULL) return;

    if(head->next==head){
        delete head;
        head=NULL;
        return;
    }

    Node* temp=head;
    while(temp->next->next!=head){
        temp=temp->next;
    }

    Node* last=temp->next;
    temp->next=head;
    delete last;
}
int main(){
    Node* head = NULL;

    insertAtBeg(head,3);
    insertAtBeg(head,1);
    insertAtEnd(head,5);
    insertAtEnd(head,7);
    insertAtBeg(head,100);
    deleteLast(head);

    display(head);
}







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

void insertAtBeg(Node* &head,int val){
    Node* node = new Node(val);

    if(head==NULL){
        head = node;
        node->next = head;
        return;
    }

    Node* temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }

    temp->next=node;
    node->next = head;
    head = node;
}

void insertAtEnd(Node* &head,int val){
    Node* node = new Node(val);

    if(head==NULL){
        head = node;
        head->next = head;
        return;
    }

    Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }

    temp->next = node;
    node->next = head;
}

void display(Node* head){
    if(head==NULL) return;

    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
}

void deleteLast(Node* &head){
    if(head==NULL) return;

    if(head->next==head){
        delete head;
        head=NULL;
        return;
    }

    Node* temp=head;
    while(temp->next->next!=head){
        temp=temp->next;
    }

    Node* last=temp->next;
    temp->next=head;
    delete last;
}
void deleteBeg(Node* &head){
    if(head==NULL) return;
    if(head->next==head){
        delete head;
        head=NULL;
        return;
    }

    Node* last=head;
    while(last->next!=head){
        last=last->next;
    }

    Node* temp=head;
    last->next=head->next;
    head=head->next;

    delete temp;
}


int main(){
    Node* head = NULL;

    insertAtBeg(head,3);
    insertAtBeg(head,1);
    insertAtEnd(head,5);
    insertAtEnd(head,7);
    insertAtBeg(head,100);

    deleteLast(head);

    display(head);
    deleteBeg(head);
    cout<<endl;
    display(head);
}