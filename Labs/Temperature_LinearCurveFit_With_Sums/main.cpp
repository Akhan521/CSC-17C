/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: 9-15-2022 @ 6:45 PM
 * Purpose: Curve fitting temperature data.
 * 
 * In class, we took an equation of the form y = mx + b,
 * and we solved for the slope and intercept using sums.
 * We curve fitted our data using a least squares sum.
 * This program simply implements the formulas we found
 * for the slope and intercept that use sums.
 * 
 * Slope:     m = (SySx - NSxy)/(S^2x - NSx^2).
 * Intercept: b = (Sy - mSx)/N.
 * 
 * Sy   = Sum of the y's.
 * Sx   = Sum of the x's.
 * Sxy  = Sum of the x*y's.
 * Sx^2 = Sum of the x squares. 
 * S^2x = Sx * Sx.
 * N    = Number of data points.
 */

//System Libraries.
#include <iostream>  //I/O Library.
#include <iomanip>   //Formatting.
#include <fstream>   //File Library.
using namespace std;

//User Libraries.

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
float **input(char *,int &,int &);   //Creates a 2D array for our data.
float calcRes(float **,int,float &); //Calculates our sums, m, and b.
void cleanup(float **,int);          //Deallocates memory.
//Execution Begins Here.
int main(int argc, char** argv) {
    //Declare Variables:
    //Our rows and columns.
    int rows,cols;
    //Our filename with our data.
    char tempData[]="temp_data.dat";
    //Creating and filling our array.
    float **data=input(tempData,rows,cols);
    //To hold our intercept.
    float b=0.0f;
    
    //Map Inputs to Outputs -> Process.
    //Solve for m and b:
    float m=calcRes(data,rows,b);
    
    //Display Inputs/Outputs.
    cout<<"Temperature Linear Curve Fit Lab:\n";
    cout<<"---------------------------------\n";
    cout<<fixed<<setprecision(4);
    cout<<"Slope     = "<<m<<endl;
    cout<<"Intercept = "<<b<<endl;
    
    //Exit the Program - Cleanup
    cleanup(data,rows);
    return 0;
}

//Our input function accepts the filename of our data.
//We also input our row and col variables.
//We return a 2D array with our temperature data.
float **input(char *fn,int &rows,int &cols){
    //Input stream object.
    ifstream in;
    //Open our file.
    in.open(fn);
    //Read in our rows and columns.
    in>>rows>>cols;
    //Create our 2D float array.
    float **data=new float *[rows];
    for(int i=0;i<rows;i++){
        data[i]=new float[cols];
    }
    //Read in our data into our array.
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            in>>data[r][c];
        }
    }
    //Close the object.
    in.close();
    //Return our array.
    return data;
}

//Our calcRes function calculates our results. It calculates our sums
//that are needed to solve for our slope m, and it also uses these 
//sums to solve for our intercept b. We return the slope m. 
//We pass our intercept in as a reference variable and set it inside.
float calcRes(float **data,int r,float &b){
    //We begin by calculating our sums:
    float sumX,sumY,sumXY,sumXsqrd; //sumXsqrd is the sum of the x squares.
    sumX=sumY=sumXY=sumXsqrd=0.0f;  //Initialize all of our variables.
    //Calculating our sums:
    for(int i=0;i<r;i++){
        //Sum of the x's:
        sumX+=data[i][0];
        //Sum of the y's:
        sumY+=data[i][1];
        //Sum of the products:
        sumXY+=(data[i][0]*data[i][1]);
        //Sum of the x squares:
        sumXsqrd+=(data[i][0]*data[i][0]);
    }
    //Solving for our slope:
    float m=(sumY*sumX-r*sumXY)/((sumX*sumX)-r*sumXsqrd);
    //Solving for our intercept:
    b=(sumY-m*sumX)/r;
    //Returning our slope:
    return m;
}

//Our cleanup function deallocates all of our memory.
void cleanup(float **data,int rows){
    //We delete each row of data.
    for(int i=0;i<rows;i++){
        delete []data[i];
    }
    //We delete the array of pointers.
    delete []data;
}