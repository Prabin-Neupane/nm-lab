/*
2. Write a program to solve non-linear equation using Newton’s method. Your program should
read an initial guess from keyboard and display the followings if the solution is obtained:
a. Estimated root of the equation
b. Functional value at calculated root
c. Required number of iterations
*/
#include<stdio.h>
#include<math.h>

#define fx x*x*x - x*x + 4*x - 4
#define fxd 3*x*x - 2*x +4

float calc_fun(float x){
    return fx;
}
float calc_der(float x){
    return fxd;
}
float cal_xi(float a,float b, float c){
    return (a-(b/c));
}

float error(float a, float b){
    return((a-b)/a);
}

int main(){

    float xi,xiplus;
    printf("initial guess ? ");
    scanf("%f",&xi);
    xiplus = cal_xi(xi,calc_fun(xi),calc_der(xi));
    //printf("\n%f\n%f",xi,xiplus);
    printf("\n%f\n",fabsf(error(xiplus,xi)));

    printf("xi\t\t f(xi)\t\t Xi+1\t\t f(xi+1)\t\t error\n");
    while (fabsf(error(xiplus,xi)) > 0.0005)
    {
        /* code */
    
    
    printf("%f\t%f\t%f\t%f\t%f\n",xi,calc_fun(xi),xiplus,calc_fun(xiplus),fabs(error(xiplus,xi)));
    xi = xiplus;
    
    xiplus = cal_xi(xi,calc_fun(xi),calc_der(xi));
    //printf("\n%f\n%f\n",xi,xiplus);

    }

    return 0;
}


