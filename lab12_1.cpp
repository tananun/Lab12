#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum = 0,sq = 0,sumRe=0,GM=1;
    double Max = A[0] ,Min = A[0];
    for (int i = 0; i < N; i++){
        sum = sum + A[i];
        sq += pow(A[i],2.0);
        GM = GM*A[i];
        sumRe = sumRe + 1/A[i]; 
        if (A[i]>Max) Max = A[i];
        if(A[i]<Min) Min = A[i];
    }
    B[0] = sum/N;
    B[1] = pow((sq/N-B[0]*B[0]),0.5);
    B[2] = pow(GM,(1.0/N));
    B[3] = N/sumRe; 
    B[4] = Max;
    B[5] = Min;
}