/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Date:    8-29-2022 @ 12:55 PM
 * Purpose: More Output Formatting
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    float inp1, inp2, inp3, inp4;
    //Initialize or input data here
    cin >> inp1;
    cin >> inp2;
    cin >> inp3;
    cin >> inp4;
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    cout << setw(9) << static_cast<int>(inp1) << setw(10) << setprecision(1) << fixed << showpoint << inp1 << setw(10) << setprecision(2) << fixed << showpoint << inp1 << endl;
    cout << setw(9) << static_cast<int>(inp2) << setw(10) << setprecision(1) << fixed << showpoint << inp2 << setw(10) << setprecision(2) << fixed << showpoint << inp2 << endl;
    cout << setw(9) << static_cast<int>(inp3) << setw(10) << setprecision(1) << fixed << showpoint << inp3 << setw(10) << setprecision(2) << fixed << showpoint << inp3 << endl;
    cout << setw(9) << static_cast<int>(inp4) << setw(10) << setprecision(1) << fixed << showpoint << inp4 << setw(10) << setprecision(2) << fixed << showpoint << inp4;
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}