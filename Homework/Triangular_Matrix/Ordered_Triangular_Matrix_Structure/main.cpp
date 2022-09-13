/* 
 * File: main.cpp
 * Author of driver: Dr. Mark E. Lehr
 * Author of fillAry & prntAry: Aamir Khan
 * Created: 9-12-2022 @ 10:10 PM
 * Purpose: Triangular Array Structure.
 */

//System Libraries Here.
#include <iostream>  //I/O Library.
using namespace std;

//User Libraries Here.
struct TriMatx{
     int size;   //Represents the number of rows.
     int *col;   //Represents the column array (Number of columns for each row.)
     int *indx;  //Represents the index array.
     int **data; //Represents the data of the Triangular matrix.
};

//Global Constants Only, No Global Variables.
//Like PI, e, Gravity, or conversions.

//Function Prototypes Here.
int  mrkRand(int=1<<15-1);  //PSRNG repeating the same sequence.
void prntAry(int *,int);    //Print a 1-D array.
void destroy(TriMatx *);    //Deallocate memory.
//These were written by me:
TriMatx *fillMat(int);      //Randomly fill a triangular matrix structure.
void mrkSort(TriMatx *);    //Use a database sort on our column array.
void prntAry(TriMatx *);    //Print our triangular matrix.

//Program Execution Begins Here:
int main(int argc, char** argv) {
    //Declare all variables here.
    int rowSize;    //Number of rows in the array.
    TriMatx *triMt; //Triangular Matrix Structure.
    //Input or initialize values here.
    cout<<"Input the number of rows in the array:"<<endl;
    cin>>rowSize;
    //Fill the array structure.
    triMt=fillMat(rowSize); //Dynamic triangular array.
    //Output Located Here.
    cout<<endl;
    cout<<"The Column Array Dimensions:"<<endl;
    prntAry(triMt->col,triMt->size);
    cout<<"The Triangular Array Sorted:"<<endl;
    mrkSort(triMt); //Sort the columns with an index array.
    prntAry(triMt); //Display the matrix with columns sorted.
    //Deallocate the structure.
    destroy(triMt);
    //Exit main.
    return 0;
}

//Fill matrix function used to fill our triangular matrix structure.
//We create our column, index, and triangular arrays and fill them.
TriMatx *fillMat(int rows){
    //Declare and create our triangular array.
    TriMatx *triMt=new TriMatx;
    //Set our array's size.
    triMt->size=rows;
    //Allocate memory for the column and index arrays.
    triMt->col=new int[triMt->size];
    triMt->indx=new int[triMt->size];
    //Fill our column and index arrays.
    for(int i=0;i<triMt->size;i++){
        triMt->col[i]=mrkRand()%9+1; //1 Digit numbers [1-9].
        triMt->indx[i]=i;            //Filling our index array.
    }
    //Allocate memory for our 2D triangular array.
    triMt->data=new int *[triMt->size];
    //Allocating each row with the specified number of columns.
    for(int i=0;i<triMt->size;i++){
        //Our column sizes are in our col array.
        triMt->data[i]=new int[triMt->col[i]]; 
    }
    //Filling our array with random 1 digit numbers.
    for(int i=0;i<triMt->size;i++){
        //We use col[i] because it holds how many columns each row has.
        for(int j=0;j<triMt->col[i];j++){
            triMt->data[i][j]=mrkRand()%9+1; //1 Digit numbers [1-9].
        }
    }
    //Return the triangular matrix.
    return triMt;
}

//Print array function to print our triangular array in sorted order.
//The column array holds how many columns our rows have.
//The index array was used to database sort our column array.
void prntAry(TriMatx *triMt){
    //Output all of our rows.
    for(int i=0;i<triMt->size;i++){
        //We use col[indx[i]] because it holds our columns in sorted order.
        for(int j=0;j<triMt->col[triMt->indx[i]];j++){
            //We use indx[i] because it holds the row indices in order based
            //on how many columns our rows have. We have to use indx[i] to make
            //sure we're reading data from the correct row based on our sort.
            cout<<triMt->data[triMt->indx[i]][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

//Sort function that is used to database sort our column array in our structure.
void mrkSort(TriMatx *triMt){
    for(int pos=0;pos<triMt->size-1;pos++){
        for(int lst=pos+1;lst<triMt->size;lst++){
            //Sorting our indexed array based on our column array.
            //The notation used is necessary to access our arrays.
            if(triMt->col[triMt->indx[pos]]>triMt->col[triMt->indx[lst]]){
                //Logic swap.
                triMt->indx[pos]=triMt->indx[pos]^triMt->indx[lst];
                triMt->indx[lst]=triMt->indx[pos]^triMt->indx[lst];
                triMt->indx[pos]=triMt->indx[pos]^triMt->indx[lst];
            }
        }
    }
}

//Destroy function to deallocate memory.
void destroy(TriMatx *triMt){
    //Deleting every row of the triangular array.
    for(int i=0;i<triMt->size;i++){
        delete []triMt->data[i];
    }
    //Delete the arrays we created.
    delete []triMt->data; //Our array of pointers.
    delete []triMt->col;  //Our column array.
    delete []triMt->indx; //Our index array.
    delete triMt;         //Our triangular array structure.
}

//Print array function for a 1D array.
void prntAry(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl<<endl;
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
