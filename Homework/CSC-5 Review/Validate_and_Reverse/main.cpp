/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: 8-30-2022 @ 10:00 PM
 * Purpose: Input a number, then output it reversed with some modifications.
 * Note:    Range should be 5 digits. Ex. 321 = 00321 -> Reversed = 12300.
 *          12300 - 999 = 11301 (After subtraction.)
 *          12300 = 00321 = 321 (After reversal.)
 */

//System Libraries Here.
#include <iostream> //cin and cout.
#include <cstring>  //strlen().
using namespace std;
//User Libraries Here.

//Global Constants Only, No Global Variables.
//Like PI, e, Gravity, or conversions.

//Function Prototypes Here.
bool  inRange(const char [],unsigned short &); //Tests for being in range of an unsigned short.
bool  reverse(unsigned short,signed short &);  //Tests for being in range of an signed short.
short subtrct(signed short,int);               //Performs the subtraction.

//Program Execution Begins Here.
int main(int argc, char** argv) {
    //Declare all Variables Here.
    const int SIZE=80;      //More than enough.
    char  digits[SIZE];     //Our digits as a char array.
    unsigned short unShort; //Unsigned short.
    short snShort;          //Signed short.
    
    //Input or initialize values Here.
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    
    //Test if it is in the Range of an unsigned short.
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Reverse and see if it falls in the range of an signed short.
    if(!reverse(unShort,snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Now, subtract if the result is not negative.
    snShort=subtrct(snShort,999);
    
    //Output the result.
    cout<<snShort<<endl;
    
    //Exit.
    return 0;
}
//In Range function. Tests to see if the number we entered is in the 
//range of an unsigned short. The second argument will hold our number
//as an unsigned short. The first argument is our digits as a char array.
bool inRange(const char a[],unsigned short &num){
    //Store the length of our number.
    int len = strlen(a);
    //We can only have up to 5 digits, so we check for this.
    if(len<=5){
        //Making sure our digits are valid (0-9).
        for(int i=0;i<len;i++){
            if(a[i]<'0'||a[i]>'9'){
                //If it isn't a digit, return false.
                return false;
            }
        }
    //If we have more than 5 digits...
    }else{
        cout<<"Longer than 5 digits\n";
        //If we have more than 5 digits, we simply return false.
        return false;
    }
    //Converting our char array number into an actual number.
    int mult=1; //Multiplier for the place we're on (ones, tens, hundreds, etc.)
    num=0;      //Initialize the variable with 0 to avoid errors.
    //Conversion starts here.
    for(int i=len-1;i>=0;i--){
        //We subtract off '0' to give us the right number. 
        num+=(a[i]-'0')*mult;
        //Moving to the next place (ones, tens, hundreds, etc.)
        mult*=10;
    }
    //Test to see if our number is in range of an unsigned short.
    if(num>=0&&num<=65535){
        return true;
    }
    //If it isn't in range...
    return false;
}
//Reverse function. Reverses our number, then checks to see if the reversed
//number is in range of a signed short. The second argument will hold our
//reversed number if it's in range, and it is passed by reference.
bool reverse(unsigned short n,signed short &b){
    int reverse=0;  //To store the reversed number.
    int num = n;    //To hold the original number.
    //Reversing our number using a while loop.
    //Credit for this reversal goes to GeeksforGeeks.
    while(num>0){
        //Perform our operations.
        reverse = (reverse*10)+(num%10);
        num/=10;
    }
    //If we need to, we put trailing zeros onto our number.
    //If we have 1 digit, we need to add 4 trailing zeros.
    if(n>0&&n<10)
        reverse*=10000;
    //If we have 2 digits, we need to add 3 trailing zeros.
    else if(n>10&&n<100)
        reverse*=1000;
    //If we have 3 digits, we need to add 2 trailing zeros.
    else if(n>100&&n<1000)
        reverse*=100;
    //If we have 4 digits, we need to add 1 trailing zero.
    else if(n>1000&&n<10000)
        reverse*=10;
    //Nothing needs to be done if you already have 5 digits.
    //Test to see if the reversed number is in range.
    if(reverse>=-32768&&reverse<=32767){
        b=reverse;   //We store the number if it's in range.
        return true; //We return true since it's in range.
    }
    //We return false if it isn't in range of a signed short.
    return false;
}
//Subtract function. If our number after the subtraction is not 
//negative, we perform the subtraction. Otherwise, we simply
//return our number without performing the subtraction.
short subtrct(signed short num,int n){
    //If our number after the subtraction is not negative...
    if(num-n>0){
        //We perform the subtraction.
        num-=n;
    }
    //Return our result.
    return num;
}