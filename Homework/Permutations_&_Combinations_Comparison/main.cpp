/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: Oct. 3, 2022, 12:40 PM
 * Purpose: Comparing Permutations & Combinations.
 */

//System Libraries.
#include <iostream>  //I/O Library.
#include <cmath>     //Math Library.
#include <iomanip>   //Formatting.
using namespace std;

//User Libraries.

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes.
float log10Fact(int);  //Returns the log of the factorial in base 10.
void permRep(int,int); //Returns the # of permutations with replacement allowed.
void perm(int,int);    //Returns the # of permutations w/o replacement.
void combRep(int,int); //Returns the # of combinations with replacement allowed.
void comb(int,int);    //Returns the # of combinations w/o replacement.

//Execution Begins Here.
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    
    //Declare Variables.
    
    //Initialize Variables.
    
    //Map Inputs to Outputs -> Process.
    
    //Display Inputs/Outputs.
    
    //Outputting key information:
    cout<<"P -> Permutation (Order Matters.)"<<endl;
    cout<<"C -> Combination (Order Does Not Matter.)"<<endl;
    cout<<"Rep -> With Replacement."<<endl;
    cout<<"No Rep -> No Replacement."<<endl;
    cout<<"N -> Number of Total Elements."<<endl;
    cout<<"M -> Number of Elements to Take From the Total."<<endl<<endl;
    cout<<" P Rep  P No Rep         C Rep          C No Rep"<<endl;
    cout<<"  N^M   N!/(N-M)! (N+M-1)!/((N-1)!M!) N!/((N-M)!M!)"<<endl<<endl;
    
    //Our table headers:
    cout<<"  N  M \t\t P Rep\t\t P No Rep \t\tC Rep \t\t C No Rep"<<endl;
    cout<<"-----------------------------------------"
        <<"-----------------------------------------"<<endl;
    
    //Outputting our table:
    for(int n=2;n<=26;n++){
        for(int m=0;m<=n;m++){
            //Outputting N and M:
            cout<<setw(3)<<n<<setw(3)<<m;
            //Outputting P w/ Rep:
            cout<<setw(14);
            permRep(n,m);
            //Outputting P w/o Rep:
            cout<<setw(14);
            perm(n,m);
            //Outputting C w/ Rep:
            cout<<setw(14);
            combRep(n,m);
            //Outputting C w/o Rep:
            cout<<setw(12);
            comb(n,m);
            cout<<endl;
        }
    }
    
    //Exit the Program - Cleanup.
    return 0;
}

float log10Fact(int n){
    //Initializing our variable to 0.
    float logFact=0.0f;
    //Log of a product = Sum of the logs.
    //Log(n!) = Log(1*2*...*n) = Log(1)+Log(2)+...+Log(n).
    for(int i=1;i<=n;i++){
        //Summing our logs.
        logFact+=log(i);
    }
    //Change of base formula:
    //LogB(A) = logC(A)/logC(B).
    //Log10(n!) = ln(n!)/ln(10).
    logFact/=log(10);
    //Returning our log.
    return logFact;
}

//nPm w/ repetition = n^m.
void permRep(int n,int m){
    //Outputting our result.
    cout<<pow(n,m);
}

//nPm w/o repetition = n!/(n-m)!.
void perm(int n,int m){
    int logInt1,logInt2;             //The integer components of our logs (characteristics).
    float logFrac1,logFrac2;         //The fractional components of our logs (mantissas).
    
    //n!:
    logInt1=log10Fact(n);            //Storing the integer component of log(n!).
    logFrac1=log10Fact(n)-logInt1;   //Storing the fractional component of log(n!).
    
    //(n-m)!:
    logInt2=log10Fact(n-m);          //Storing the integer component of log((n-m)!).
    logFrac2=log10Fact(n-m)-logInt2; //Storing the fractional component of log((n-m)!).
    
    //n!/(n-m)!:
    //We take the exponents and subtract them, since division with the same base
    //requires that we subtract the exponents. (10^5/10^3 = 10^(5-3) = 10^2).
    int exponent=logInt1-logInt2;
    //For the mantissa, we need to first raise 10 to each of our fractional components
    //to determine the first terms in the scientific notations of each factorial. Then, 
    //we can divide the 2 terms to return the mantissa for our scientific notation result.
    //(For ex: if we had 2.4 x 10^1, 2.4 would be l0^logFrac1. Then,
    // if we had 2 x 10^0, 2 would be 10^logFrac2. Then, we would divide 
    // 2.4 by 2 to get our final mantissa for our result or 1.2 in this case).
    float mantissa=pow(10,logFrac1)/pow(10,logFrac2);
    
    //Outputting our result in scientific notation.
    cout<<mantissa<<" x 10^"<<exponent;
}

//nCm w/ repetition = (n+m-1)!/(n-1)!m!.
void combRep(int n,int m){
    int logInt1,logInt2,logInt3;       //The integer components of our logs (characteristics).
    float logFrac1,logFrac2,logFrac3;  //The fractional components of our logs (mantissas).
    
    //(n+m-1)!:
    logInt1=log10Fact(n+m-1);          //Storing the integer component of log((n+m-1)!).
    logFrac1=log10Fact(n+m-1)-logInt1; //Storing the fractional component of log((n+m-1)!).
    
    //(n-1)!:
    logInt2=log10Fact(n-1);            //Storing the integer component of log((n-1)!).
    logFrac2=log10Fact(n-1)-logInt2;   //Storing the fractional component of log((n-1)!).
    
    //m!:
    logInt3=log10Fact(m);              //Storing the integer component of log(m!).
    logFrac3=log10Fact(m)-logInt3;     //Storing the fractional component of log(m!).
    
    //(n+m-1)!/(n-1)!m!.
    //We take the exponents and subtract them, since division with the same base
    //requires that we subtract the exponents. (10^5/(10^3*10^2) = 10^(5-3-2) = 10^0).
    int exponent=logInt1-logInt2-logInt3;
    //For the mantissa, we need to first raise 10 to each of our fractional components
    //to determine the first terms in the scientific notations of each factorial. Then, 
    //we can divide the first term by the product of the 2nd and 3rd terms. This will
    //give us the final mantissa for our scientific notation result.
    //(For ex: if we had 1.2 x 10^2, 1.2 would be 10^logFrac1. Then, if we had 
    // 0.3 x 10^1, 0.3 would be 10^logFrac2. Finally, if we had 0.4 x 10^1, 0.4
    // would be 10^logFrac3. We would then do: 1.2/(0.3*0.4) to get our mantissa).
    float mantissa=pow(10,logFrac1)/(pow(10,logFrac2)*pow(10,logFrac3));
    
    //Outputting our result in scientific notation.
    cout<<mantissa<<" x 10^"<<exponent;
}

//nCm w/o repetition = n!/(n-m)!m!.
//This is also equivalent to -> nPm/m!.
void comb(int n,int m){
    int logInt1,logInt2,logInt3;       //The integer components of our logs (characteristics).
    float logFrac1,logFrac2,logFrac3;  //The fractional components of our logs (mantissas).
    
    //(n+m-1)!:
    logInt1=log10Fact(n);              //Storing the integer component of log(n!).
    logFrac1=log10Fact(n)-logInt1;     //Storing the fractional component of log(n!).
    
    //(n-1)!:
    logInt2=log10Fact(n-m);            //Storing the integer component of log((n-m)!).
    logFrac2=log10Fact(n-m)-logInt2;   //Storing the fractional component of log((n-m)!).
    
    //m!:
    logInt3=log10Fact(m);              //Storing the integer component of log(m!).
    logFrac3=log10Fact(m)-logInt3;     //Storing the fractional component of log(m!).
    
    //n!/(n-m)!m!.
    //We take the exponents and subtract them, since division with the same base
    //requires that we subtract the exponents. (10^5/(10^3*10^2) = 10^(5-3-2) = 10^0).
    int exponent=logInt1-logInt2-logInt3;
    //For the mantissa, we need to first raise 10 to each of our fractional components
    //to determine the first terms in the scientific notations of each factorial. Then, 
    //we can divide the first term by the product of the 2nd and 3rd terms. This will
    //give us the final mantissa for our scientific notation result.
    //(For ex: if we had 1.2 x 10^2, 1.2 would be 10^logFrac1. Then, if we had 
    // 0.3 x 10^1, 0.3 would be 10^logFrac2. Finally, if we had 0.4 x 10^1, 0.4
    // would be 10^logFrac3. We would then do: 1.2/(0.3*0.4) to get our mantissa).
    float mantissa=pow(10,logFrac1)/(pow(10,logFrac2)*pow(10,logFrac3));
    
    //Outputting our result in scientific notation.
    cout<<mantissa<<" x 10^"<<exponent;
}