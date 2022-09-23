/* 
 * File:    RowAray.h
 * Author:  Aamir Khan
 * Created: September 21, 2022, 11:15 PM
 */

#ifndef ROWARAY_H
#define ROWARAY_H

#include "AbsRow.h" //Including our abstract row class.

//Our row array class:
class RowAray:public AbsRow{
    public:
        RowAray(unsigned int); //Constructor.
        virtual ~RowAray();    //Destructor.
        int mrkRand(int);      //PSRNG function.
        //Getter function for the size.
        int getSize()const{return size;}
        //Getter function for the data.
        //Declaring it as const specifies that
        //it's a "read-only" member function.
        int getData(int i)const{
            if(i>=0&&i<size)
                return rowData[i];
            else 
                return 0;
        }
        //Setter function for our data.
        void setData(int,int);
};

//Random number generator written by Dr.Lehr.
int RowAray::mrkRand(int seed){
    //X_n+1 = (a*X_n + c) mod m.
    //Where X is the sequence of pseudo-random values.
    //m, 0 < m - modulus.
    //a, 0 < a < m - multiplier.
    //c, 0 ≤ c < m - increment.
    //x_0, 0 ≤ x_0 < m - the seed or starting value.
    unsigned int a=31051;      //Short Prime.
    unsigned int c=997;        //Another Prime.
    unsigned int shrt=1<<15-1; //Range of a positive signed short.
    unsigned int m=1<<31-1;    //Range of a positive signed int.
    static int Xn=30937;       //Short Prime.
    static int cnt=0;          //Initialize the seed.
    //Setting the seed as a short.
    if(cnt==0&&seed<=shrt)
        Xn=seed;
    //Increment the count.
    cnt++;
    //Our sequence definition.
    Xn=(a*Xn+c)%m;
    //Returning our random number.
    return Xn;
}

//Constructor.
RowAray::RowAray(unsigned int n){
    //Setting our size.
    size=n;
    //Creating our array.
    rowData=new int[size];
    //Filling our array.
    for(int i=0;i<size;i++){
        rowData[i]=mrkRand(size)%90+10;
    }
}

//Destructor.
RowAray::~RowAray(){
    //Deleting our row array.
   delete []rowData;
}

//Setter function to set data within our array.
void RowAray::setData(int row,int val){
    //If we have a valid index to set data at...
    if(row>=0&&row<size)
        rowData[row]=val;
    else
        cout<<"Error: Invalid Index."<<endl;
}

#endif /* ROWARAY_H */

