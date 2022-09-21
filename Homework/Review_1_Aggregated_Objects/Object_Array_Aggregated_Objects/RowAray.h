/* 
 * File:    RowAray.h
 * Author:  Aamir Khan
 * Created: September 20, 2022, 8:45 PM
 */

#ifndef ROWARAY_H
#define ROWARAY_H

//Our row array class:
class RowAray{
    private:
        int size;         //Size of our array.
        int *rowData;     //Our row data.
        int mrkRand(int); //PSRNG written by Dr. Lehr.
    public:
        RowAray(int);     //Constructor.
        ~RowAray();       //Destructor.
        //Getter method for our size.
        int getSize(){return size;}
        //Getter method for our indexed data.
        int getData(int i){return rowData[i];}
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
RowAray::RowAray(int n){
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

#endif /* ROWARAY_H */

