/* 
 * File:    LinkedList.h
 * Author:  Dr. Mark E. Lehr
 * Purpose: Linked List Implementation.
 */

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

template<class T>
class LinkedList{
    private:
        struct Link{
            T data;         //For our 2D matrix objects.
            Link *linkPtr;  //Pointer to the next link.
        };
        //Crucial link pointers.
        Link *front,*next,*temp,*found;
        //Determine the address of link that contains the data.
        fndLst(const T&); 
    public:
        LinkedList(const T&);    //Constructor.
        ~LinkedList();           //Destructor.
        void prntLst();          //Print each data element in the list.
        void  addLst(const T&);  //Add data at the end of the list.
        int  findLst(const T&);  //Determine what link contains the data.
        int   cntLst();          //To count how many elements are in the list.
        T     getObj(int);       //Returns a specific object.
        T    &getPtr(int);       //Returns the pointer of a specific object.
};

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function: Create a linked list and fill it with our data.
//Input  -> data  The data of the very first link we'll create.
template<class T>
LinkedList<T>::LinkedList(const T &data){
    //Constructor.
    front=new Link;      //Allocate a link at the front of the list.
    front->data=data;    //Initialize it with data.
    front->linkPtr=NULL; //At the moment, it is not pointing to anything.
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function: Print the contents of the linked list.
//Output-> Display the entire linked list.
template<class T>
void LinkedList<T>::prntLst(){
    next=front;                 //Create a pointer to the front.
    cout<<endl<<"The Beginning of the List:"<<endl;
    do{
        cout<<next->data<<endl; //Print the contents of the link.
        next=next->linkPtr;     //Go to the next link in the list.
    }while(next!=NULL);         //Loop until we reach the end.
    cout<<"The End of the List."<<endl<<endl;
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function: Deallocate the entire list from the front to the end.
//Output-> Deallocate and return a NULL for the linked list pointer.
template<class T>
LinkedList<T>::~LinkedList(){
    do{
       temp=front->linkPtr;   //Point to the next link in the list.
       delete front;          //Delete the front of the list.
       front=temp;            //Update the front.
    }while(front!=NULL);
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function: Add a link with data to the end of the list.
//Input -> data  Data to embed at the last link in the list.
template<class T>
void LinkedList<T>::addLst(const T &data){
    //Go to the end of the list.
    Link *end;
    temp=front;             //Declare a pointer that's used to step through the list.
    do{
        end=temp;           //Point to the current link.
        temp=temp->linkPtr; //Point to the next link.
    }while(temp!=NULL);     //You're done when you hit the end.
    //Now, we add to the end of the list.
    Link *add=new Link;     //Create the new link.
    add->data=data;         //Add the data.
    add->linkPtr=NULL;      //Set the pointer to NULL.
    end->linkPtr=add;       //Point to the new end of the list.
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function: Find the number of the link that matches the data.
//Input -> value  The object we want to find.
//Output-> The Link<Object> number from the front, where the data is found.
template<class T>
int LinkedList<T>::findLst(const T &value){
    int n=0;                //Initialize the counter.
    temp=front;             //Prepare to traverse the Link<Object> list.
    do{
        n++;                //Increment the counter.
        if(temp->data==value)
            return n;       //Return the counter where the data is found.
        temp=temp->linkPtr; //Move to the next link.
    }while(temp!=NULL);     //We end when we reach the end of the linked list.
    return 0;               //Not found, return a 0.
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function: Find the address of the link that matches the data.
//Input -> value  The object that we want to find.
//Output-> The Link<Object> address from the front, where the data is found.
template<class T>
LinkedList<T>::fndLst(const T &value){
    found=front;  //Set the cursor to move through the list.
    do{
        if(found->data==value)
            return found;     //We return the address of link with the matching data.
        found=found->linkPtr; //Next link in the list.
    }while(found!=NULL);      //End of the list.
    found=NULL;               //Not found.
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function: Find the number of links in the list.
//Output-> The number of links in the list.
template<class T>
int LinkedList<T>::cntLst(){
    int n=0;                //Initialize the counter.
    temp=front;             //Set the cursor to the front.
    do{
        n++;                //Increment the counter.
        temp=temp->linkPtr; //Move to the next link.
    }while(temp!=NULL);     //Loop until the end is reached.
    return n;               //Return the counter value.
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function: Find a specific object.
//Input -> indx  The number of the link that we want to return.
//Output-> The object that matches our link number.
template<class T>
T LinkedList<T>::getObj(int indx){
    int n=0;                      //Initialize the counter.
    temp=front;                   //Set the cursor to the front.
    do{
        if(n==indx)
            return temp->data;    //Return the data if we've found the link.
        n++;                      //Increment the counter.
        temp=temp->linkPtr;       //Move to the next link.
    }while(temp!=NULL);           //Loop until the end is reached.
    return front->data;           //Not found, return the data of the 1st link.
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function: Find a specific object and return a reference to it.
//Input -> indx  The number of the link that we want to return.
//Output-> The object that matches our link number.
template<class T>
T &LinkedList<T>::getPtr(int indx){
    int n=0;                      //Initialize the counter.
    temp=front;                   //Set the cursor to the front.
    do{
        if(n==indx)
            return temp->data;    //Return the data if we've found the link.
        n++;                      //Increment the counter.
        temp=temp->linkPtr;       //Move to the next link.
    }while(temp!=NULL);           //Loop until the end is reached.
    return front->data;           //Not found, return the data of the 1st link.
}

#endif	/* LINKEDLIST_H */