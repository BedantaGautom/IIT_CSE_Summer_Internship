#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1e20
#define MAX_SIZE 100

char findminimum(double a,double b,double c,double d,double e) {
    double min = a;
    char letter = 'A';

    if(b<min){
        b = min; 
        letter = 'E';
    }
    if(c<min){
        c = min;
        letter = 'I';
    }
    if(d<min){
        d = min;
        letter = 'O';
    }
    if(e<min){
        e = min;
        letter = 'U';
    }
    
    return letter;
}

double distance(double x, double y) {
    // Euclidean distance
    return sqrt(pow(x - y, 2));
}

double dtw(double* sequence1, int len1, double* sequence2, int len2) {
    double cost[MAX_SIZE][MAX_SIZE];
    int i, j;

    // Initialize cost matrix
    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {

            cost[i][j] = INF;
        }
    }
    cost[0][0] = 0;

    // Compute cost matrix
    for (i = 1; i < len1; i++) {
        for (j = 1; j < len2; j++) {
            double d = distance(sequence1[i], sequence2[j]);
            cost[i][j] = d + fmin(cost[i-1][j], fmin(cost[i][j-1], cost[i-1][j-1]));
        }
    }
    // Return DTW distance
    return cost[len1-1][len2-1];
}

int main() {

    FILE* file2 = fopen("vectors/test1.txt", "r");
    FILE* file7 = fopen("vectors/test2.txt", "r");
    FILE* file8 = fopen("vectors/test3.txt", "r");
    FILE* file9 = fopen("vectors/test4.txt", "r");
    FILE* file10 = fopen("vectors/test5.txt", "r");
    FILE* file11 = fopen("vectors/test6.txt", "r");
    FILE* file12 = fopen("vectors/test7.txt", "r");
    FILE* file13 = fopen("vectors/test8.txt", "r");
    FILE* file14 = fopen("vectors/test9.txt", "r");
    FILE* file15 = fopen("vectors/test10.txt", "r");
    FILE* file1 = fopen("vectors/reference1.txt", "r");
    FILE* file3 = fopen("vectors/reference2.txt", "r");
    FILE* file4 = fopen("vectors/reference3.txt", "r");
    FILE* file5 = fopen("vectors/reference4.txt", "r");
    FILE* file6 = fopen("vectors/reference5.txt", "r");

    if (file1 == NULL || file2 == NULL || file3 == NULL || file4 == NULL || file5 == NULL || file6 == NULL || file7 == NULL || file8 == NULL || file9 == NULL || file10 == NULL || file11 == NULL || file12 == NULL || file13 == NULL || file14 == NULL || file15 == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    double sequence1[MAX_SIZE];
    double sequence2[MAX_SIZE];
    double sequence3[MAX_SIZE];
    double sequence4[MAX_SIZE];
    double sequence5[MAX_SIZE];
    double sequence6[MAX_SIZE];
    double sequence7[MAX_SIZE];
    double sequence8[MAX_SIZE];
    double sequence9[MAX_SIZE];
    double sequence10[MAX_SIZE];
    double sequence11[MAX_SIZE];
    double sequence12[MAX_SIZE];
    double sequence13[MAX_SIZE];
    double sequence14[MAX_SIZE];
    double sequence15[MAX_SIZE];
    int len1 = 0, len2 = 0;
    double value;

    // Read data from file
    while (fscanf(file1, "%lf", &value) == 1 && len1 < MAX_SIZE) {
        sequence1[len1++] = value;
    }
    while (fscanf(file2, "%lf", &value) == 1 && len2 < MAX_SIZE) {
        sequence2[len2++] = value;
    }
    while (fscanf(file3, "%lf", &value) == 1 && len1 < MAX_SIZE) {
        sequence3[len1++] = value;
    }
    while (fscanf(file4, "%lf", &value) == 1 && len1 < MAX_SIZE) {
        sequence4[len2++] = value;
    }
    while (fscanf(file5, "%lf", &value) == 1 && len1 < MAX_SIZE) {
        sequence5[len1++] = value;
    }
    while (fscanf(file6, "%lf", &value) == 1 && len1 < MAX_SIZE) {
        sequence6[len2++] = value;
    }
    while (fscanf(file7, "%lf", &value) == 1 && len2 < MAX_SIZE) {
        sequence7[len2++] = value;
    }
    while (fscanf(file8, "%lf", &value) == 1 && len2 < MAX_SIZE) {
        sequence8[len2++] = value;
    }
    while (fscanf(file9, "%lf", &value) == 1 && len2 < MAX_SIZE) {
        sequence9[len2++] = value;
    }
    while (fscanf(file10, "%lf", &value) == 1 && len2 < MAX_SIZE) {
        sequence10[len2++] = value;
    }
    while (fscanf(file11, "%lf", &value) == 1 && len2 < MAX_SIZE) {
        sequence11[len2++] = value;
    }
    while (fscanf(file12, "%lf", &value) == 1 && len2 < MAX_SIZE) {
        sequence12[len2++] = value;
    }
    while (fscanf(file13, "%lf", &value) == 1 && len1 < MAX_SIZE) {
        sequence13[len2++] = value;
    }
     while (fscanf(file14, "%lf", &value) == 1 && len1 < MAX_SIZE) {
        sequence14[len2++] = value;
    }
    while (fscanf(file15, "%lf", &value) == 1 && len1 < MAX_SIZE) {
        sequence15[len2++] = value;
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);
    fclose(file4);
    fclose(file5);
    fclose(file6);
    fclose(file7);
    fclose(file8);
    fclose(file9);
    fclose(file10);
    fclose(file11);
    fclose(file12);
    fclose(file13);
    fclose(file14);
    fclose(file15);

    // Calculate the DTW distance
    double dtw_distance1 = dtw(sequence1, len1, sequence2, len2);
    printf("DTW distance A & test1: %.2f\n", dtw_distance1);
    double dtw_distance2 = dtw(sequence3, len1, sequence2, len2);
    printf("DTW distance E & test1: %.2f\n", dtw_distance2);
    double dtw_distance3 = dtw(sequence4, len1, sequence2, len2);
    printf("DTW distance I & test1: %.2f\n", dtw_distance3);
    double dtw_distance4 = dtw(sequence5, len1, sequence2, len2);
    printf("DTW distance O & test1: %.2f\n", dtw_distance4);
    double dtw_distance5 = dtw(sequence6, len1, sequence2, len2);
    printf("DTW distance U & test1: %.2f\n", dtw_distance5);

    printf("The test vector1 is closest to the letter %c\n",findminimum(dtw_distance1,dtw_distance2,dtw_distance3,dtw_distance4,dtw_distance5));

    double dtw_distance6 = dtw(sequence1, len1, sequence7, len2);
    printf("DTW distance A & test2: %.2f\n", dtw_distance6);
    double dtw_distance7 = dtw(sequence3, len1, sequence7, len2);
    printf("DTW distance E & test2: %.2f\n", dtw_distance7);
    double dtw_distance8 = dtw(sequence4, len1, sequence7, len2);
    printf("DTW distance I & test2: %.2f\n", dtw_distance8);
    double dtw_distance9 = dtw(sequence5, len1, sequence7, len2);
    printf("DTW distance O & test2: %.2f\n", dtw_distance9);
    double dtw_distance10 = dtw(sequence6, len1, sequence7, len2);
    printf("DTW distance U & test2: %.2f\n", dtw_distance10);

    printf("The test vector2 is closest to the letter %c\n",findminimum(dtw_distance6,dtw_distance7,dtw_distance8,dtw_distance9,dtw_distance10));

    double dtw_distance11 = dtw(sequence1, len1, sequence8, len2);
    printf("DTW distance A & test3: %.2f\n", dtw_distance11);
    double dtw_distance12 = dtw(sequence3, len1, sequence8, len2);
    printf("DTW distance E & test3: %.2f\n", dtw_distance12);
    double dtw_distance13 = dtw(sequence4, len1, sequence8, len2);
    printf("DTW distance I & test3: %.2f\n", dtw_distance13);
    double dtw_distance14 = dtw(sequence5, len1, sequence8, len2);
    printf("DTW distance O & test3: %.2f\n", dtw_distance14);
    double dtw_distance15 = dtw(sequence6, len1, sequence8, len2);
    printf("DTW distance U & test3: %.2f\n", dtw_distance15);

    printf("The test vector3 is closest to the letter %c\n",findminimum(dtw_distance11,dtw_distance12,dtw_distance13,dtw_distance14,dtw_distance15));

    double dtw_distance16 = dtw(sequence1, len1, sequence9, len2);
    printf("DTW distance A & test4: %.2f\n", dtw_distance16);
    double dtw_distance17 = dtw(sequence3, len1, sequence9, len2);
    printf("DTW distance E & test4: %.2f\n", dtw_distance17);
    double dtw_distance18 = dtw(sequence4, len1, sequence9, len2);
    printf("DTW distance I & test4: %.2f\n", dtw_distance18);
    double dtw_distance19 = dtw(sequence5, len1, sequence9, len2);
    printf("DTW distance O & test4: %.2f\n", dtw_distance19);
    double dtw_distance20 = dtw(sequence6, len1, sequence9, len2);
    printf("DTW distance U & test4: %.2f\n", dtw_distance20);

    printf("The test vector4 is closest to the letter %c\n",findminimum(dtw_distance16,dtw_distance17,dtw_distance18,dtw_distance19,dtw_distance20));

    double dtw_distance21 = dtw(sequence1, len1, sequence10, len2);
    printf("DTW distance A & test5: %.2f\n", dtw_distance21);
    double dtw_distance22 = dtw(sequence3, len1, sequence10, len2);
    printf("DTW distance E & test5: %.2f\n", dtw_distance22);
    double dtw_distance23 = dtw(sequence4, len1, sequence10, len2);
    printf("DTW distance I & test5: %.2f\n", dtw_distance23);
    double dtw_distance24 = dtw(sequence5, len1, sequence10, len2);
    printf("DTW distance O & test5: %.2f\n", dtw_distance24);
    double dtw_distance25 = dtw(sequence6, len1, sequence10, len2);
    printf("DTW distance U & test5: %.2f\n", dtw_distance25);

    printf("The test vector5 is closest to the letter %c\n",findminimum(dtw_distance21,dtw_distance22,dtw_distance23,dtw_distance24,dtw_distance25));

    double dtw_distance26 = dtw(sequence1, len1, sequence11, len2);
    printf("DTW distance A & test6: %.2f\n", dtw_distance26);
    double dtw_distance27 = dtw(sequence3, len1, sequence11, len2);
    printf("DTW distance E & test6: %.2f\n", dtw_distance27);
    double dtw_distance28 = dtw(sequence4, len1, sequence11, len2);
    printf("DTW distance I & test6: %.2f\n", dtw_distance28);
    double dtw_distance29 = dtw(sequence5, len1, sequence11, len2);
    printf("DTW distance O & test6: %.2f\n", dtw_distance29);
    double dtw_distance30 = dtw(sequence6, len1, sequence11, len2);
    printf("DTW distance U & test6: %.2f\n", dtw_distance30);

    printf("The test vector6 is closest to the letter %c\n",findminimum(dtw_distance26,dtw_distance27,dtw_distance28,dtw_distance29,dtw_distance30));

    double dtw_distance31 = dtw(sequence1, len1, sequence12, len2);
    printf("DTW distance A & test7: %.2f\n", dtw_distance31);
    double dtw_distance32 = dtw(sequence3, len1, sequence12, len2);
    printf("DTW distance E & test7: %.2f\n", dtw_distance32);
    double dtw_distance33 = dtw(sequence4, len1, sequence12, len2);
    printf("DTW distance I & test7: %.2f\n", dtw_distance33);
    double dtw_distance34 = dtw(sequence5, len1, sequence12, len2);
    printf("DTW distance O & test7: %.2f\n", dtw_distance34);
    double dtw_distance35 = dtw(sequence6, len1, sequence12, len2);
    printf("DTW distance U & test7: %.2f\n", dtw_distance35);

    printf("The test vector7 is closest to the letter %c\n",findminimum(dtw_distance31,dtw_distance32,dtw_distance33,dtw_distance34,dtw_distance35));

    double dtw_distance36 = dtw(sequence1, len1, sequence13, len2);
    printf("DTW distance A & test8: %.2f\n", dtw_distance36);
    double dtw_distance37 = dtw(sequence3, len1, sequence13, len2);
    printf("DTW distance E & test8: %.2f\n", dtw_distance37);
    double dtw_distance38 = dtw(sequence4, len1, sequence13, len2);
    printf("DTW distance I & test8: %.2f\n", dtw_distance38);
    double dtw_distance39 = dtw(sequence5, len1, sequence13, len2);
    printf("DTW distance O & test8: %.2f\n", dtw_distance39);
    double dtw_distance40 = dtw(sequence6, len1, sequence13, len2);
    printf("DTW distance U & test8: %.2f\n", dtw_distance40);

    printf("The test vector8 is closest to the letter %c\n",findminimum(dtw_distance36,dtw_distance37,dtw_distance38,dtw_distance39,dtw_distance40));

    double dtw_distance41 = dtw(sequence1, len1, sequence14, len2);
    printf("DTW distance A & test9: %.2f\n", dtw_distance41);
    double dtw_distance42 = dtw(sequence3, len1, sequence14, len2);
    printf("DTW distance E & test9: %.2f\n", dtw_distance42);
    double dtw_distance43 = dtw(sequence4, len1, sequence14, len2);
    printf("DTW distance I & test9: %.2f\n", dtw_distance43);
    double dtw_distance44 = dtw(sequence5, len1, sequence14, len2);
    printf("DTW distance O & test9: %.2f\n", dtw_distance44);
    double dtw_distance45 = dtw(sequence6, len1, sequence14, len2);
    printf("DTW distance U & test9: %.2f\n", dtw_distance45);

    printf("The test vector9 is closest to the letter %c\n",findminimum(dtw_distance41,dtw_distance42,dtw_distance43,dtw_distance44,dtw_distance45));

    double dtw_distance46 = dtw(sequence1, len1, sequence15, len2);
    printf("DTW distance A & test10: %.2f\n", dtw_distance46);
    double dtw_distance47 = dtw(sequence3, len1, sequence15, len2);
    printf("DTW distance E & test10: %.2f\n", dtw_distance47);
    double dtw_distance48 = dtw(sequence4, len1, sequence15, len2);
    printf("DTW distance I & test10: %.2f\n", dtw_distance48);
    double dtw_distance49 = dtw(sequence5, len1, sequence15, len2);
    printf("DTW distance O & test10: %.2f\n", dtw_distance49);
    double dtw_distance50 = dtw(sequence6, len1, sequence15, len2);
    printf("DTW distance U & test10: %.2f\n", dtw_distance50);

    printf("The test vector10 is closest to the letter %c\n",findminimum(dtw_distance46,dtw_distance47,dtw_distance48,dtw_distance49,dtw_distance50));

    return 0;
}


