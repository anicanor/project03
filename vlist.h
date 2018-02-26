//vlist.h
//Aaron Nicanor
//anicanor

#ifndef VLIST_H
#define VLIST_H

//libraries needed
#include<iostream>
#include<string>

//header files
#include "video.h"

using namespace std;

class Vlist{
    
    public:
        Vlist();
        ~Vlist();
        Video* lookup(string title);
        int length();
        void print();
        bool remove(string target);
        bool insert(Video *video);


    private:
        // node definition
        class Node{
            
            public:
                Node(Video *video, Node *next)
                {m_video = video; m_next = next;}
                Video *m_video;
                Node *m_next;
        };
        Node *m_head;
};
#endif





