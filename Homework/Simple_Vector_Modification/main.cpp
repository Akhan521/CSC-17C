/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: 9-12-2022 @ 7:45 PM
 * Purpose: Modifying the Simple Vector class. 
 */

//System Libraries.
#include <iostream>  //I/O Library.
#include <cstdlib>   //CSTD Library.
#include <ctime>     //Time Library.
using namespace std;

//User Libraries.
#include "SimpleVector.h"
//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function prototypes:
int mrkRand(int seed=0);                //Random number generator.
void fillVec(SimpleVector<char> &);     //Fill vector function.
void prntVec(SimpleVector<char> &,int); //Print vector function.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Declare Variables.
    int size;
    //Determine the size of our vector.
    cout<<"Input the Size of the Array 10-100:"<<endl;
    cin>>size;
    cout<<"The array size = "<<size<<endl;
    //Create a vector of the given size.
    SimpleVector<char> sv(size);
    //Fill the Vector.
    fillVec(sv);
    //Print the Vector.
    prntVec(sv,10);
    //Add values to the array.
    char vlFrnt=mrkRand()%26+65;
    char vlBack=mrkRand()%26+65;
    cout<<"The value added to the front is = "<<vlFrnt<<endl;
    cout<<"The value added to the back  is = "<<vlBack<<endl;
    sv.pshFrnt(vlFrnt);
    sv.pshBack(vlBack);
    //Print the Vector.
    prntVec(sv,10);
    //Remove 2 values from the front and the back.
    cout<<endl;
    cout<<"Removing 2 values from the front and the back."<<endl;
    cout<<"Front Removed = "<<sv.popFrnt()<<endl;
    cout<<"Front Removed = "<<sv.popFrnt()<<endl;
    cout<<"Back  Removed = "<<sv.popBack()<<endl;
    cout<<"Back  Removed = "<<sv.popBack()<<endl;
    //Print the Vector.
    prntVec(sv,10);
    //Exit main.
    return 0;
}
//Print vector function.
void prntVec(SimpleVector<char> &sv,int perLine){
    cout<<endl;
    for(int i=0;i<sv.size();i++){
        cout<<sv[i]<<" ";
        if(i%perLine==(perLine-1))
            cout<<endl;
    }
    cout<<endl;
}
//Fill vector function.
void fillVec(SimpleVector<char> &sv){
    for(int i=0;i<sv.size();i++){
        sv[i]=mrkRand(sv.size())%26+65;
    }
}
//Random number generator written by Dr.Lehr.
int mrkRand(int seed){
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