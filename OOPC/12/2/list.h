#include <iostream>
#ifndef LIST_H
#define LIST_H

template<typename T>
class List{
    struct Node{
        T value;
        Node *next;
    };
    Node *head, *tail;
public:
    List();
    ~List();
    void prepend(T value);
    void apend(T value);
    void detachHead();
    void detachTail();
    void display();
};
template<typename T>
List<T>::List()
{
      head = NULL;
      tail = NULL;
}

template<typename T>
List<T>::~List()
{
    Node* temp = head;
    Node* temp2 = nullptr;
    while(temp){
        temp2 = temp->next;
        delete temp;
        temp = temp2;
    }
}

template<typename T>
void List<T>::prepend(T value){
    Node* node = new Node;
    node->value = value;
    if(head){
        node->next = head;
        head = node ;
    }
    else {
        head = node;
        tail = node;
        node->next = nullptr;
    }
}

template<typename T>
void List<T>::apend(T value)
{
    Node* node = new Node;
    node->value = value;
    node->next = nullptr;
    if(tail){
        tail->next = node;
        tail = node;
    }else{
        head = node;
        tail = node;
    }

}

template<typename T>
void List<T>::detachHead(){
    if(!head){
        return ;
    }
    else if(head == tail){
        delete head;
        head = tail = nullptr;
    }else{
        Node* temp = head->next;
        delete head;
        head = temp;
    }
}
template<typename T>
void List<T>::detachTail()
{
    if(!tail){
        return ;
}
else if(tail==head){
    delete tail;
    tail = head = nullptr;
}else{
 Node *temp = head;
 while(temp->next!=tail)
 {
     temp = temp->next;
 }
 delete tail;
  tail = temp;
  temp->next = nullptr;
    }
}

template<typename T>
void List<T>::display()
{
 Node *node;
 node = head;
 while(node){
     std::cout<<node->value<<std::endl;
     node = node->next;
 }
}
#endif // LIST_H
