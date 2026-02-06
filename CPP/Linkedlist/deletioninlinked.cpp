void deleteAtPos(Node* &head, int pos){
    if(head==NULL) return;

    // delete first node
    if(pos==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return;
    }

    Node* temp=head;

    for(int i=1;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }

    if(temp==NULL || temp->next==NULL) return;

    Node* del=temp->next;
    temp->next=temp->next->next;
    delete del;
}
