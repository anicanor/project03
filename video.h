// video.h
// Aaron Nicanor
// anicanor

#include<iostream>
#include<string>

#ifndef VIDEO_H
#define VIDEO_H

using namespace std;

class Video{
    
    public:
        Video (string name, string url, string comment, float length, int rating);
        void print();
        bool ratingCheck(Video *tester);
        bool lengthCheck(Video *tester);
        bool titleCheck(Video *tester);
        string name();
    
    private:
        string m_name, m_url, m_comment;
        float m_length;
        int m_rating;
};
#endif
