//vlist.cpp
//Aaron Nicanor
//anicanor

// libraries needed for this project
#include<iostream>
#include<string>

//including the header files
#include"vlist.h"
#include"video.h"

using namespace std;

// constructor
Vlist::Vlist(){
    
    m_head = NULL;
}

// destructor
Vlist::~Vlist(){
    
    Node *ptr = m_head;
    while(ptr != NULL){
        
        Node *temp;
        temp = ptr;
        ptr = ptr->m_next;
        delete temp;
    }
}

// checks through the list for the given title
Video* Vlist::lookup(string title){
    
    //exits if list is empty
    if(!m_head){
        return NULL;
    }
    for( Node *tmp = m_head; tmp != NULL; tmp = tmp->m_next ){
        
        if( title == tmp->m_video->name() ){
            
            return tmp->m_video;
        }
    }
    return NULL;
}

// goes through the list and returns the length of it
int Vlist::length(){
    
    int length = 0;

    for (Node *ptr = m_head; ptr != NULL; ptr=ptr->m_next){
        
        length++;
    }
    return length;
}

// prints the list
void Vlist::print(){
    
    Node *ptr = m_head;
    // cycles through the list printing out the elements
    while(ptr != NULL){
        
        ptr->m_video->print();
        ptr = ptr->m_next;
    }
}

// finds the given node target, removes it from the list
bool Vlist::remove(string target){
    
    // stops if list is empty
    if(m_head==NULL){
        
        return false;
    }
    // this checks the first element of the list to see if it's the target. If it is, it deletes it
    if( m_head->m_video->name()==target ){
        
        Node *tmp = m_head;
        m_head = m_head->m_next;
        delete tmp;
        return true;
    }
    // cycles through the list looking for the target
    Node *ptr = m_head;
    while(ptr->m_next != NULL && ptr->m_next->m_video->name() != target){
        
        ptr = ptr->m_next;
    }
    // quits out of the function if the target is not within the list
    if(ptr->m_next == NULL){
        
        return false;
    }else{
        
        // found the target to delete
        Node *tmp = ptr->m_next;
        ptr->m_next = ptr->m_next->m_next;
        delete tmp;
        return true;
    }
}

// inserts a node. Looks through for any null points in the list then inserts itself in there
bool Vlist::insert(Video *video){
    
    if(m_head == NULL){
        
        m_head = new Node(video, m_head);
        return true;
    }
    // handles the header node. This loop below stops any duplicates
    if( m_head->m_video->name() == video->name() ){
        
        return false;
    }
    // adds in a node if the header is empty
    if( m_head->m_video->name() > video->name() ){
        
        m_head = new Node(video, m_head);
        return true;
    }else{
        // goes through the rest of the list
        Node *ptr = m_head;
        while (( ptr->m_next != NULL) && (ptr->m_next->m_video->name() <= video->name())){
            // stops any duplicates
            if( ptr->m_next->m_video->name() == video->name() ){
                
                return false;
            }
            ptr = ptr->m_next;
        }
        ptr->m_next = new Node(video, ptr->m_next);
        return true;
    }
}





