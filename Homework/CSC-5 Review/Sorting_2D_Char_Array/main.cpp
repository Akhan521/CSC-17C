/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: 8-30-2022 @ 6:25 PM
 * Purpose: Sorting a 2-D array of characters.
 */

//System Libraries Here.
#include <iostream>  //cin and cout.
#include <cstring>   //strlen(), strcmp(), strcpy().
using namespace std;

//User Libraries Here.

//Global Constants Only, No Global Variables.
//Allowed like PI, e, Gravity, conversions, array dimensions necessary.
const int COLMAX=80;  //Only 20 required, and 1 for null terminator.

//Function Prototypes Here.
int  read(char [][COLMAX],int &);          //Reads a 2-D char array, and returns rows and columns detected.
void sort(char [][COLMAX],int,int);        //Sorts the 2-D char array by row.
void print(const char [][COLMAX],int,int); //Prints the sorted 2-D array.

//Program Execution Begins Here.
int main(int argc, char** argv) {
    //Declare all Variables Here.
    const int ROW=30;              //Only 20 required.
    char array[ROW][COLMAX];       //Bigger than necessary.
    int colIn,colDet,rowIn,rowDet; //Rows and Cols inputted and detected.
    
    //Input the size of the array you are sorting.
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size.
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    //Compare the size inputted vs. size detected and sort if same.
    //Else, output different size.
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
               "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
               "Column Input size greater than specified.")<<endl;
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
//Sort function. To compare char arrays, we use strcmp().
//We compare our rows with one another in this sort.
void sort(char a[][COLMAX],int row,int col){
    for(int i=0;i<row-1;i++){
        for(int j=i+1;j<row;j++){
            //If a[i] is greater than a[j], we swap the 2 rows.
            if(strcmp(a[i],a[j])>0){
                //Swap the 2 rows using strcpy().
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