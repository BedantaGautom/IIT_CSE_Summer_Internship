#include <stdio.h>
#include <math.h>

double chebyshevDistance(double x1, double y1, double x2, double y2) {
    double dx = fabs(x1 - x2);
    double dy = fabs(y1 - y2);
    return fmax(dx, dy);
}

int main() {
    double x1, y1, x2, y2;
    
    printf("Enter the coordinates of point 1 (x1 y1): ");
    scanf("%lf %lf", &x1, &y1);
    
    printf("Enter the coordinates of point 2 (x2 y2): ");
    scanf("%lf %lf", &x2, &y2);
    
    double distance = chebyshevDistance(x1, y1, x2, y2);
    
    printf("The Chebyshev distance between the two points is: %lf\n", distance);
    
    return 0;
}