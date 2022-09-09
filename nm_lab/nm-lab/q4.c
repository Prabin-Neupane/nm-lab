/*
4. Write a program to solve non-linear equation using Fixed Point Iteration method. Your
program should read an initial guess from keyboard and display the followings if the solution is
obtained:
a. Estimated root of the equation
b. Functional value at calculated root
c. Required number of iterations
*/
#include<stdio.h>
#include<math.h>
#define fx x*x*x + 2*x*x - 4*x + 4
#define gx (x*x*x+2*x*x+4)/4

float cal_fun(float x){
    return gx;
}

 float cal_xiplus(float x){
     return cal_fun(x);

 }
float error(float new, float old){
    return fabsf((new-old)/new);
}

int main(){
    float xi,xiplus;
    printf("initial guess ");
    scanf("%f",&xi);
    xiplus = cal_xiplus(xi);
    printf("xi\t\txi+1\t\tf(xi+1)\t\terror\n");
    while (error(xiplus,xi) > 0.0000005)
    {
        printf("%f\t%f\t%f\t%f\n",xi,xiplus,cal_fun(xiplus),error(xiplus,xi));
        xi = xiplus;
        xiplus = cal_xiplus(xi);
        //printf("\n%f\n",xi);
    }
    
    return 0;
}
