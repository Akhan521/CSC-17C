/* 
 * File: main.cpp
 * Author of driver: Dr. Mark E. Lehr
 * Author of fillAry & prntAry: Aamir Khan
 * Created: 9-12-2022 @ 9:20 PM
 * Purpose: Triangular Array Sorted by Columns.
 */

//System Libraries Here.
#include <iostream>  //I/O Library.
using namespace std;

//User Libraries Here.

//Global Constants Only, No Global Variables.
//Like PI, e, Gravity, or conversions.

//Function Prototypes Here.
int  mrkRand(int=1<<15-1);            //PSRNG repeating the same sequence.
int *fillAry(int);                    //Randomly fill a 1-D column array.
void prntAry(int *,int);              //Print a 1-D array.
void destroy(int **,int *,int *,int); //Deallocate memory.
int *fillIdx(int);                    //Fill our index array.
void mrkSort(int *,int *,int);        //Database sort on our column array.
//These were written by me:
int**fillAry(int *,int);              //Randomly fill a triangular array.
void prntAry(int **,int *,int *,int); //Print an ordered triangular array.

//Program Execution Begins Here:
int main(int argc, char** argv) {
    //Declare all variables here.
    int *col;      //Column array.
    int *indx;     //Index array.
    int **trangl;  //Triangular array.
    int rowSize;   //Number of rows.
    //Input or initialize values here.
    cout<<"Input the number of rows in the array:"<<endl;
    cin>>rowSize;
    //Filling our index array.
    indx=fillIdx(rowSize);       //Index array used for the Database Sort.
    col=fillAry(rowSize);        //Dynamic 1-D column array.
    trangl=fillAry(col,rowSize); //Dynamic triangular array.
    //Output Located Here.
    cout<<endl;
    cout<<"The Column Array Dimensions:"<<endl;
    prntAry(col,rowSize);
    cout<<"The Triangular Array Sorted:"<<endl;
    mrkSort(col,indx,rowSize);        //Sort the columns with an indexed array.
    prntAry(trangl,col,indx,rowSize); //Display the matrix with columns sorted.
    //Deallocate the array.
    destroy(trangl,col,indx,rowSize);
    //Exit main.
    return 0;
}

//Fill array function to fill a 2D triangular array.
//Input our column array and our row count.
int **fillAry(int *col,int rows){
    //Allocate memory given our rows.
    int **array=new int*[rows];
    //For each row, we allocate an array with a specified number of columns.
    for(int i=0;i<rows;i++){
        array[i]=new int[col[i]]; //Our column sizes are in our col array.
    }
    //Filling our triangular array with 1 digit numbers.
    for(int i=0;i<rows;i++){
        //We use col[i] because it holds how many columns each row has.
        for(int j=0;j<col[i];j++){
            array[i][j]=mrkRand()%9+1; //1 Digit numbers [1-9].
        }
    }
    //Return our triangular array.
    return array;
}

//Print array function to print our triangular array in sorted order.
//The column array holds how many columns our rows have.
//The index array was used to database sort our column array.
void prntAry(int **array,int *col,int *indx,int rows){
    for(int i=0;i<rows;i++){
        //We use col[indx[i]] because it holds our columns in sorted order.
        for(int j=0;j<col[indx[i]];j++){
            //We use indx[i] because it holds the row indices in order based
            //on how many columns our rows have. We have to use indx[i] to make
            //sure we're reading data from the correct row based on our sort.
            cout<<array[indx[i]][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

//Sort function that is used to database sort our column array.
void mrkSort(int *array,int *indx,int size){
    for(int pos=0;pos<size-1;pos++){
        for(int lst=pos+1;lst<size;lst++){
            //Comparing elements using the indexed array.
            if(array[indx[pos]]>array[indx[lst]]){
                //Logic swap.
                indx[pos]=indx[pos]^indx[lst];
                indx[lst]=indx[pos]^indx[lst];
                indx[pos]=indx[pos]^indx[lst];
            }
        }
    }
}

//Destroy function to deallocate memory.
void destroy(int **a,int *c,int *indx,int n){
    //Delete every row of the triangular array.
    for(int i=0;i<n;i++){
        delete []a[i];
    }
    //Delete the pointers.
    delete []a;    //Our array of pointers.
    delete []c;    //Our column array.
    delete []indx; //Our index array.
}

//Print array function for a 1D array.
void prntAry(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl<<endl;
}

//Fill array function used to fill our column array.
int *fillAry(int n){
    //Allocating memory.
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=mrkRand()%9+1; //1 Digit numbers [1-9].
    }
    //Returning our array.
    return array;
}

//Fill index function to fill our indexed array.
int *fillIdx(int n){
    //Allocate memory.
    int *array=new int[n];
    //Fill the array.
    for(int i=0;i<n;i++){
        array[i]=i;
    }
    //Return the index array.
    return array;
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
