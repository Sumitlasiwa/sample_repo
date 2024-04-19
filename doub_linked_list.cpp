#include <iostream>
using namespace std;
class Node{
    int data;
    Node *next;
    Node *prev;
    public:
    void createList();
    void insertAtbeg(int);
    void insertAfter(int,int);
    void insertBefore(int,int);
    void insertAtend(int);
    void deleteAtbeg();
    void delteAtPos(int);
    void deleteAtEnd();
    void displayList();
};
int i=1,pos,count;
Node *head=0,*newnode,*temp;
void Node::createList(){
    newnode=new Node();
    newnode->next=0;
    newnode->prev=0;
    cout<<"Enter data: ";
    cin>>newnode->data;
    if(head==0){
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
    }
}
void Node::insertAtbeg(int data){
    newnode=new Node();
    newnode->next=0;
    newnode->prev=0;
    newnode->data=data;
    if(head==0){
        head=temp=newnode;
    }
    else{
    newnode->next=temp;
    temp->prev=newnode;
    head=newnode;
    }
}
void Node::insertAfter(int pos,int data){
    temp=head;
    newnode=new Node();
    newnode->next=0;
    newnode->prev=0;
    newnode->data=data;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    if(temp->next==NULL){    //if insertion is done at last
        Node::insertAtend(data);
    }
    else{
    newnode->next=temp->next;
    temp->next->prev=newnode;
    newnode->prev=temp;
    temp->next=newnode;
    }
}
void Node::insertBefore(int pos,int data){
    temp=head;
    newnode=new Node();
    newnode->next=0;
    newnode->prev=0;
    newnode->data=data;
    while(i<(pos-1)){
        temp=temp->next;
        i++;
    }
    if(temp==head){
        Node::insertAtbeg(data);
    }
    else{
    newnode->next=temp->next;
    temp->next->prev=newnode;
    newnode->prev=temp;
    temp->next=newnode;
    }
}
void Node::insertAtend(int data){
    temp=head;
    newnode=new Node();
    newnode->next=0;
    newnode->prev=0;
    newnode->data=data;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}
void Node::deleteAtbeg(){
    temp=head;
    head=temp->next;
    delete temp;
}
void Node::deleteAtEnd(){
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        i++;
    }
    temp->prev->next=0;
    delete temp;
}
void Node::delteAtPos(int pos){
    temp=head;
    while(i<=pos){
        temp=temp->next;
        i++;
    }
    if(temp->prev==NULL)
         Node::deleteAtbeg();
    else if(temp->next==NULL)
         Node::deleteAtEnd();
    else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}
void Node::displayList(){
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    Node n;
    n.insertAtbeg(4);
    n.insertAtbeg(5);
    n.insertAfter(1,6);
    n.insertAtend(7);
    n.insertBefore(3,9);
    n.delteAtPos(4);
    n.displayList();
}
