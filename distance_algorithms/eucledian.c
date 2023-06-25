#include <stdio.h>
#include <math.h>
  
// Function to calculate distance
float distance(int x1, int y1, int x2, int y2)
{
    // Calculating distance
    return sqrt(pow(x2 - x1, 2)
                + pow(y2 - y1, 2) * 1.0);
}
  
// Driver Code
int main()
{
    printf("%.2f", distance(3, 4, 4, 3));
    return 0;
}