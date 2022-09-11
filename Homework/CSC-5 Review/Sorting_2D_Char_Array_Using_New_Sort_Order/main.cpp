/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: 8-30-2022 @ 11:15 PM
 * Purpose: Sorting a 2D char array using a new sort order.
 *          Creating our own strcmp() function that takes 
 *          this new sort order into account. We're defining
 *          how our char arrays will be sorted.
 */

//System Libraries Here.
#include <iostream> //cin and cout.
#include <cstring>  //strlen(), strcmp(), and strcpy().
using namespace std;

//Global Constants Only, No Global Variables.
//Allowed like PI, e, Gravity, conversions, array dimensions necessary.
const int COLMAX=80; //Only 20 required, and 1 for the null terminator.

//Function Prototypes Here.
//Returns the number of rows and columns detected from input.
int  read(char [][COLMAX],int &);
//Sort by row using our own strcmp() function.
void sort(char [][COLMAX],int,int, const char[],const char[]);
//Print the sorted 2D array.
void print(const char [][COLMAX],int,int);
//Our strcmp() function that uses a new sort order.
int strcmp(char [],char [],const char [],const char []);

//Program Execution Begins Here.
int main(int argc, char** argv) {
    //Declare all Variables Here.
    const int ROW=30;        //Only 20 required.
    char array[ROW][COLMAX]; //Bigger than necessary.
    int colIn,colDet,        //Columns inputted and detected.
        rowIn,rowDet;        //Rows inputted and detected.
    char replace[COLMAX],    //Char array of characters we're replacing.
         with[COLMAX];       //Char array of what we're replacing it with.
    
    //Input the new sort order, then sort.
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now, read in the array of characters and determine it's size.
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size inputted vs. size detected and sort if they match.
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }
    
    //Exit.
    return 0;
}
//Read function. Returns the number of columns detected. 
//We also return the number of rows detected.
int read(char a[][COLMAX],int &rowDet){
    int row=0,maxCol=0; //Declare and Initialize our Variables.
    char str[COLMAX];   //Going to store row inputs as 1-D char arrays.
    //Read in as many char arrays as we want.
    while(cin>>str){
        row++;                 //Increment our row count since we read in a char array.
        int len = strlen(str); //To determine the length of the input.
        if(len>maxCol)         //Find the maximum number of columns. 
            maxCol=len;
        //Fill our 2-D array with the 1-D array we read in.
        for(int i=0;i<len;i++){
            //Put our 1-D array into the proper row of our 2-D array.
            a[row-1][i]=str[i];
        }
        //Setting the null term to indicate the end of the char array.
        a[row-1][len]='\0';
    }
    //Detecting how many rows we have.
    rowDet=row;
    //Returning the maximum column count.
    return maxCol;
}
//Sort function. Utilizes our new sort order and our strcmp() function.
//We input our 2D array, its dimensions, the char array of the chars we're
//swapping, and the char array of the chars we're swapping it with.
void sort(char a[][COLMAX],int row,int col, const char replace[],const char with[]){
    for(int i=0;i<row-1;i++){
        for(int j=i+1;j<row;j++){
            //Returns a 1 if the first char array is greater than the second.
            if(strcmp(a[i],a[j],replace,with)>0){
                //Perform a memory swap.
                char temp[col];
                strcpy(temp,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],temp);
            }
        }
    }
}
//Print function. 
void print(const char a[][COLMAX],int row,int col){
    for(int i=0;i<row;i++){
        cout<<a[i]<<endl;
    }
}
//String compare function. We input the first char array, the second char
//array, the char array of the characters we're swapping, and the char array
//of the characters we're swapping the previous array with.
//Our new sort order involves swapping a set of characters.
//An array representing the ascii values is used. This array is then modified 
//based on the chars that we're swapping. We're essentially swapping the ascii
//values of the chars in this ascii array. (Like an indexed array.)
int strcmp(char a[],char b[], const char replace[], const char with[]){
    const int ASCII=128;  //How many ASCII values we have.
    char newOrder[ASCII]; //The ASCII indexed array.
    //Filling our indexed array.
    for(int i=0;i<ASCII;i++){
        newOrder[i]=i;
    }
    //Swapping the ASCII values of our chars in our indexed array.
    //We're swapping the replace elements and the with elements.
    //We'll be modifying our ASCII indexed array.
    for(int i=0;i<strlen(replace);i++){ 
        //A temporary variable to hold an ASCII value.
        int temp;
        //replace[i] will return an ascii value. We go to that ascii value in
        //our indexed array, so that we can swap it with another ascii value.
        //with[i] will return the ascii value that we'll be swapping it with.
        temp=newOrder[replace[i]];
        newOrder[replace[i]]=newOrder[with[i]];
        newOrder[with[i]]=temp;
    }
    //Perform the sort using a while loop.
    int compare=0, //To hold the final result.
              i=0; //Index variable for our arrays.
    //As long as neither char arrays have reached the null term, and 
    //the current letters are equal to one another...
    while(a[i]!='\0'&&b[i]!='\0'&&newOrder[a[i]]==newOrder[b[i]]){
        //Increment the index variable. This allows us to check
        //the next letters until we find a mismatch or reach the end.
        i++;
    }
    //If both char arrays are equal, we return a 0.
    //Else if, the first char array is greater, we return a 1.
    //Otherwise, we return a -1 (The first char array is smaller).
    return compare=(newOrder[a[i]]==newOrder[b[i]])?0:
                   (newOrder[a[i]]>newOrder[b[i]])?1:-1;
}