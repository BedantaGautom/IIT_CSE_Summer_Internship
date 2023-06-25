#include <stdio.h>
#include <math.h>

double GetMinkowskiDistance(double *x, double *y, int n, double r) {
    double sum = 0;
    for (int i = 0; i < n; i ++) {
        sum += pow(x[i] - y[i], r);
    }
    return pow(sum, 1.0 / r);
}

int main(){
    double x[3] = {1, 2, 3};
    double y[3] = {4, 5, 6};
    double r = 2;
    double distance = GetMinkowskiDistance(x, y, 3, r);
    printf("The Minkowski distance is %f\n", distance);
    return 0;
}