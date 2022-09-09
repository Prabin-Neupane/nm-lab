/*
3. Write a program to solve non-linear equation using Secant method. Your program should read
an initial guess from keyboard and display the followings if the solution is obtained:
a. Estimated root of the equation
b. Functional value at calculated root
c. Required number of iterations
*/
#include<stdio.h>
#include<math.h>
#define fx x*x*x - x*x + 4*x - 4

float cal_fun(float x){
    return fx;

}

float error(float new,float old){
    return fabsf((new-old)/new);
}

float cal_xkplus(float xk, float xkminus){
    return (xk-(xkminus-xk)/(cal_fun(xkminus)-cal_fun(xk))*cal_fun(xk));
}



int main(){
    float xk,xkminus,xkplus;
    printf("enter initial guess ");
    scanf("%f%f",&xkminus,&xk);
    xkplus = cal_xkplus(xk,xkminus);
    //printf("%f",xkplus);
    printf("xk-1\t\tf(xk-1)\t\txk\t\tf(xk)\t\txk+1\t\tf(xk+1)\t\terror\n\n\n");
    while (error(xkplus,xk) > 0.0005){
        printf("%f\t%f\t%f\t%f\t%f\t%f\t%f\n",xkminus,cal_fun(xkminus),xk,cal_fun(xk),xkplus,cal_fun(xkplus),error(xkplus,xk));
        xkminus = xk;
        xk = xkplus;
        xkplus = cal_xkplus(xk,xkminus);
    }
    
    
    return 0;
}