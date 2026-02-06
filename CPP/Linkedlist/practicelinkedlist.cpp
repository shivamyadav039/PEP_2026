bool recursive(Node* head,int key){
    if(head==NULL) return false;
    if(head->data==key) return true;
    return recursive(head->next,key);
}