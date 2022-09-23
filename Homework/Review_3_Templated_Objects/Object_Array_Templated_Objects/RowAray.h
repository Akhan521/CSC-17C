/* 
 * File:    RowAray.h
 * Author:  Aamir Khan
 * Created: September 22, 2022, 9:15 PM
 */

#ifndef ROWARAY_H
#define ROWARAY_H

//Our template row array class:
template<class T>
class RowAray{
    protected:
        int size;   //The size of our array.
        T *rowData; //Our row array data.
    public:
        RowAray(int);       //Constructor.
        virtual ~RowAray(); //Destructor.
        int mrkRand(int);   //PSRNG function.
        //Getter method for our size.
        int getSize()const{return size;}
        //Getter method for our data.
        T getData(int i)const{
            if(i>=0&&i<size)
                return rowData[i];
            else 
                return 0;
        }
        //Setter method for our data.
        void setData(int,T);
};

//Random number generator written by Dr.Lehr.
template<class T>
int RowAray<T>::mrkRand(int seed){
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
template<class T>
RowAray<T>::RowAray(int n){
    //Setting our size.
    size=n;
    //Creating our array.
    rowData=new T[size];
    //Filling our array.
    for(int i=0;i<size;i++){
        rowData[i]=mrkRand(size)%90+10;
    }
}

//Destructor.
template<class T>
RowAray<T>::~RowAray(){
    //Deleting our row array.
    delete []rowData;
}

//Setter method for our data. 
template<class T>
void RowAray<T>::setData(int row,T val){
    //If the index is valid...
    if(row>=0&&row<size)
        rowData[row]=val;
    else 
        cout<<"Error: Invalid Index."<<endl;
}

#endif /* ROWARAY_H */

