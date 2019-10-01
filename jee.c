#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"

typedef double** matrix;

//Writing the functions for the integrands
double f1(double x);
double f2(double x);
double f3(double x);
double f4(double x);
double f5(double x);
double f6(double x);
double sec(double x);//function for sec
matrix gen_func_pts(double (*f)(double), double a, double b, int len);//Generating the points lying on a given function
double lsum(double (*f)(double), double a, double b, int n);//function for calculating the sum of the areas of the lower rectangles
double usum(double (*f)(double), double a, double b, int n);//function for calculating the sum of the areas of the upper rectangles
matrix vstack(double **x, double **y, int a, int b, int c);//function for vertically stacking two given matrices
void save_int(int i,char *str);//function for saving the value of an integer in a dat file

int main(){
    int len = 100;
    save_int(len,"data/len.dat");

    matrix I1 = gen_func_pts(f1,0,M_PI_2,len);
    savetxt(I1,"data/I1.dat",2,len);

    matrix I2 = gen_func_pts(f2,0,M_PI_2,len);
    savetxt(I2,"data/I2.dat",2,len);

    matrix I3 = gen_func_pts(f3,0,M_PI_2,len);
    savetxt(I3,"data/I3.dat",2,len);

    matrix I4 = gen_func_pts(f4,0,M_PI_4,len);
    savetxt(I4,"data/I4.dat",2,len);

    matrix I5 = gen_func_pts(f5,0,M_PI_4,len);
    savetxt(I5,"data/I5.dat",2,len);

    matrix I6 = gen_func_pts(f6,1,2,len);
    savetxt(I6,"data/I6.dat",2,len);

    printf("Definite integral as limit of a sum:");

    printf("\n\nWhen n=10 :");
    printf("\nSum of areas of lower rectangles = %lf\nSum of areas of upper rectangles = %lf",lsum(f1,0,M_PI_2,10),usum(f1,0,M_PI_2,10));

    printf("\n\nWhen n=1000 :");
    printf("\nSum of areas of lower rectangles = %lf\nSum of areas of upper rectangles = %lf",lsum(f1,0,M_PI_2,1000),usum(f1,0,M_PI_2,1000));

    printf("\n\nWhen n=10000 :");
    printf("\nSum of areas of lower rectangles = %lf\nSum of areas of upper rectangles = %lf",lsum(f1,0,M_PI_2,10000),usum(f1,0,M_PI_2,10000));

    return 0;
}

double f1(double x){
    double y = (3*sqrt(cos(x)))/(pow((sqrt(cos(x))+sqrt(sin(x))),5));
    return y;
}

double f2(double x){
    double y = (3*sqrt(sin(x)))/(pow((sqrt(cos(x))+sqrt(sin(x))),5));
    return y;
}

double f3(double x){
    double y = 1.5*(1/(pow((sqrt(cos(x))+sqrt(sin(x))),4)));
    return y;
}

double f4(double x){
    double y = 3*(1/(pow((sqrt(cos(x))+sqrt(sin(x))),4)));
    return y;
}

double f5(double x){
    double y = 3*((pow(sec(x),2))/(pow((1+sqrt(tan(x))),4)));
    return y;
}

double f6(double x){
    double y = 3*((2*(x-1))/(pow(x,4)));
    return y;
}

double sec(double x){
    return 1/cos(x);
}

matrix gen_func_pts(double (*f)(double), double a, double b, int len){

    int i;
    matrix x = linspace(a,b,len);//filling x values
    matrix y = createMat(1,len);

    //filling y values
    for(i=0;i<len;i++){
        y[0][i] = f(x[0][i]);
    }

    matrix X = vstack(x,y,1,1,len);
    return X;
}

double lsum(double (*f)(double), double a, double b, int n){
    double h = (b-a)/n;//width of a rectangle
    int i;
    double sum =0;

    //calculating the sum of the areas of the rectangles
    for(i=0;i<n;i++){
        double x = f(a+(i*h));
        double y = f(a+(i+1)*h);

        if(x<y)
        sum+=x*h;

        else
        sum+=y*h;
    }
    return sum;
}

double usum(double (*f)(double), double a, double b, int n){
    double h = (b-a)/n;//width of a rectangle
    int i;
    double sum =0;

    //calculating the sum of the areas of the rectangles
    for(i=0;i<n;i++){
        double x = f(a+(i*h));
        double y = f(a+(i+1)*h);

        if(x>y)
        sum+=x*h;

        else
        sum+=y*h;
    }
    return sum;
}

matrix vstack(double **x, double **y, int a, int b, int c){
    int i,j;
    matrix z = createMat(a+b,c);

    //filling the values of the first matrix
    for(i=0;i<a;i++){
        for(j=0;j<c;j++){
            z[i][j] = x[i][j];
        }
    }

    //filling the values of the second matrix
    for(i=0;i<b;i++){
        for(j=0;j<c;j++){
            z[a+i][j] = y[i][j];
        }
    }
    return z;
}

void save_int(int i,char *str){
    FILE *fp;
    fp = fopen(str,"w");
    fprintf(fp,"%d",i);//printing the value
    fclose(fp);
}
