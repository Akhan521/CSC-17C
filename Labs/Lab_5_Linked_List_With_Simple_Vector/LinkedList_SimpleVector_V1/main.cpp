/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: October 5, 2022, 1:00 PM
 * Purpose: Creating a linked list.
 */

//System Libraries.
#include <iostream>  //I/O Library.
#include <cstdlib>   //NULL Pointer.
using namespace std;

//User Libraries.
struct Link{
    int data;   //Some data.
    Link *next; //Next link.
};

//Global/Universal Constants -- No Global Variables.
//Science, Math, Conversions, Higher Dimensioned constants only.

//Function Prototypes.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Creating 5 links.
    Link *lnk1=new Link;
    Link *lnk2=new Link;
    Link *lnk3=new Link;
    Link *lnk4=new Link;
    Link *lnk5=new Link;
    
    //Filling the links with data.
    lnk1->data=1;
    lnk2->data=2;
    lnk3->data=3;
    lnk4->data=4;
    lnk5->data=5;
    
    //Connecting the links.
    lnk1->next=lnk2;
    lnk2->next=lnk3;
    lnk3->next=lnk4;
    lnk4->next=lnk5;
    lnk5->next=NULL;
    
    //Printing the list.
    Link *node=lnk1;
    //As long as we have a valid node...
    while(node!=NULL){
        //We output its data.
        cout<<node->data<<endl;
        //We advance to the next node/link.
        node=node->next;
    }
    
    //Deleting the list.
    Link *front=lnk1;
    //As long as we still have a node to delete...
    while(front!=NULL){
        Link *temp=front;  //Store the current node that will be deleted.
        front=front->next; //Advance to the next node/link.
        delete temp;       //Delete the stored node.
    }
    
    //Exit stage right.
    return 0;
}