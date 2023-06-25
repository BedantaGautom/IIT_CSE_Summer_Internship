#include <stdio.h>
#include <math.h>

double dotProduct(double *vector1, double *vector2, int size) {
    double result = 0.0;
    for (int i = 0; i < size; i++) {
        result += vector1[i] * vector2[i];
    }
    return result;
}

double magnitude(double *vector, int size) {
    double result = 0.0;
    for (int i = 0; i < size; i++) {
        result += vector[i] * vector[i];
    }
    return sqrt(result);
}

double cosineSimilarity(double *vector1, double *vector2, int size) {
    double dot = dotProduct(vector1, vector2, size);
    double mag1 = magnitude(vector1, size);
    double mag2 = magnitude(vector2, size);
    return dot / (mag1 * mag2);
}

int main() {
    // Example usage
    double vector1[] = {1.0, 2.0, 3.0};
    double vector2[] = {4.0, 5.0, 6.0};
    int size = sizeof(vector1) / sizeof(double);

    double similarity = cosineSimilarity(vector1, vector2, size);
    printf("Cosine similarity: %f\n", similarity);

    return 0;
}