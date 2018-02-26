// main.cpp
// Aaron Nicanor
// anicanor

// various libraries needed for this project
#include <iostream>
#include <fstream>
#include <istream>
#include <string> 
// including the header files
#include "video.h"
#include "vlist.h"

using namespace std;

int main(){
    
// declaring my variables here
    Vlist list;
    float length;
    int rating;
    string title;
    string comments;
    string input;
    string URL;
    
// this part deals with the user's inputs
while(getline(cin,input)){
    
     if( input == "lookup" ){
        
        getline(cin, title);
        Video *video = list.lookup(title);
        if(video){
            
            video->print();
        }else{
            
        cerr << "Title <" << title << "> not in list." << endl;
        }
      }else if( input == "length" ){
        
        cout<<list.length()<<endl;
     }else if( input == "print"){
        
        list.print();
     }else if( input == "remove" ){
        
        getline(cin, title);
        if ( !list.remove(title) ){
            
            cerr<<"Title <" <<title<< "> not in list, could not delete." << endl;
        }
    }else if ( input == "insert"){
        
        getline(cin,title);
        getline(cin,URL);
        getline(cin,comments);
        cin>>length;
        cin>>rating;
        cin.ignore();
        Video *new_video = new Video(title, URL, comments, length, rating);
        // sends out an error if it's already in the list
        if (!list.insert(new_video)){
            
            cerr << "Could not insert video <" <<title<< ">, already in list."<<endl;
        }
     }else{
        
        // will print out an error if the input is unrecognized
        cerr << "<" << input << "> is not a legal command, giving up." << endl;
        return 1;
     }
    }
    return 0;
}


