#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

char findminimum(double a,double b,double c,double d,double e) {
    double min3 = a;
    char letter = 'A';

    if(b<min3){
        min3 = b; 
        letter = 'E';
    }
    if(c<min3){
        min3= c;
        letter = 'I';
    }
    if(d<min3){
        min3 = d;
        letter = 'O';
    }
    if(e<min3){
        min3= e;
        letter = 'U';
    }
    
    return letter;
}

struct Point {
    double x;
    double y;
};

double euclideanDistance(const Point& p1, const Point& p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

double max(double a, double b) {
    return (a > b) ? a : b;
}

double min(double a, double b, double c) {
    return min(a, min(b, c));
}

double frechetDistance(const vector<Point>& path1, const vector<Point>& path2) {
    int size1 = path1.size();
    int size2 = path2.size();

    vector<vector<double>> distance_matrix(size1, vector<double>(size2, numeric_limits<double>::infinity()));

    distance_matrix[0][0] = euclideanDistance(path1[0], path2[0]);

    for (int i = 1; i < size1; i++) {
        distance_matrix[i][0] = max(euclideanDistance(path1[i], path2[0]), distance_matrix[i - 1][0]);
    }

    for (int j = 1; j < size2; j++) {
        distance_matrix[0][j] = max(euclideanDistance(path1[0], path2[j]), distance_matrix[0][j - 1]);
    }

    for (int i = 1; i < size1; i++) {
        for (int j = 1; j < size2; j++) {
            double d = euclideanDistance(path1[i], path2[j]);
            distance_matrix[i][j] = max(min(distance_matrix[i - 1][j], distance_matrix[i][j - 1], distance_matrix[i - 1][j - 1]), d);
        }
    }
    return distance_matrix[size1 - 1][size2 - 1];
}

int main() {
    string filename1 = "vectors/reference1.txt";
    string filename2 = "vectors/reference2.txt";
    string filename3 = "vectors/reference3.txt";
    string filename4 = "vectors/reference4.txt";
    string filename5 = "vectors/reference5.txt";
    string filename6 = "vectors/test1.txt";
    string filename7 = "vectors/test2.txt";
    string filename8 = "vectors/test3.txt";
    string filename9 = "vectors/test4.txt";
    string filename10 = "vectors/test5.txt";
    string filename11 = "vectors/test6.txt";
    string filename12 = "vectors/test7.txt";
    string filename13 = "vectors/test8.txt";
    string filename14 = "vectors/test9.txt";
    string filename15 = "vectors/test10.txt";

    // // Open the files
    ifstream file1(filename1);
    ifstream file2(filename2);
    ifstream file3(filename3);
    ifstream file4(filename4);
    ifstream file5(filename5);
    ifstream file6(filename6);
    ifstream file7(filename7);
    ifstream file8(filename8);
    ifstream file9(filename9);
    ifstream file10(filename10);
    ifstream file11(filename11);
    ifstream file12(filename12);
    ifstream file13(filename13);
    ifstream file14(filename14);
    ifstream file15(filename15);

    // Read the number of points in each path
    int size1, size2;
    file1 >> size1;
    file2 >> size1;
    file3 >> size1;
    file4 >> size1;
    file5 >> size1;
    file6 >> size2;
    file7 >> size2;
    file8 >> size2;
    file9 >> size2;
    file10 >> size2;
    file11 >> size2;
    file12 >> size2;
    file13 >> size2;
    file14 >> size2;
    file15 >> size2;

    // Read the points
    vector<Point> path1(size1);
    for (int i = 0; i < size1; i++) {
        file1 >> path1[i].x >> path1[i].y;
    }
    vector<Point> path2(size1);
    for (int i = 0; i < size2; i++) {
        file2 >> path2[i].x >> path2[i].y;
    }
    vector<Point> path3(size1);
    for (int i = 0; i < size1; i++) {
        file3 >> path3[i].x >> path3[i].y;
    }
    vector<Point> path4(size1);
    for (int i = 0; i < size1; i++) {
        file4 >> path4[i].x >> path4[i].y;
    }
    vector<Point> path5(size1);
    for (int i = 0; i < size1; i++) {
        file5 >> path5[i].x >> path5[i].y;
    }
    vector<Point> path6(size2);
    for (int i = 0; i < size2; i++) {
        file6 >> path6[i].x >> path6[i].y;
    }
    vector<Point> path7(size1);
    for (int i = 0; i < size1; i++) {
        file7 >> path7[i].x >> path7[i].y;
    }
    vector<Point> path8(size2);
    for (int i = 0; i < size2; i++) {
        file8 >> path8[i].x >> path8[i].y;
    }
    vector<Point> path9(size1);
    for (int i = 0; i < size1; i++) {
        file9 >> path9[i].x >> path9[i].y;
    }
    vector<Point> path10(size2);
    for (int i = 0; i < size2; i++) {
        file10 >> path10[i].x >> path10[i].y;
    }
    vector<Point> path11(size2);
    for (int i = 0; i < size2; i++) {
        file11 >> path11[i].x >> path11[i].y;
    }
    vector<Point> path12(size2);
    for (int i = 0; i < size2; i++) {
        file12 >> path12[i].x >> path12[i].y;
    }
    vector<Point> path13(size2);
    for (int i = 0; i < size2; i++) {
        file13 >> path13[i].x >> path13[i].y;
    }
    vector<Point> path14(size2);
    for (int i = 0; i < size2; i++) {
        file14 >> path14[i].x >> path14[i].y;
    }
    vector<Point> path15(size2);
    for (int i = 0; i < size2; i++) {
        file15 >> path15[i].x >> path15[i].y;
    }

    // Close the files
    file1.close();
    file2.close();
    file3.close();
    file4.close();
    file5.close();
    file6.close();
    file7.close();
    file8.close();
    file9.close();
    file10.close();
    file11.close();
    file12.close();
    file13.close();
    file14.close();
    file15.close();

    // Calculate the Fréchet distance
    double frechet_distance1 = frechetDistance(path1, path6);
    printf("Frechet distance A & test1: %.2f\n", frechet_distance1);
    double frechet_distance2 = frechetDistance(path2, path6);
    printf("Frechet distance E & test1: %.2f\n", frechet_distance2);
    double frechet_distance3 = frechetDistance(path3, path6);
    printf("Frechet distance I & test1: %.2f\n", frechet_distance3);
    double frechet_distance4 = frechetDistance(path4, path6);
    printf("Frechet distance O & test1: %.2f\n", frechet_distance4);
    double frechet_distance5 = frechetDistance(path5, path6);
    printf("Frechet distance U & test1: %.2f\n", frechet_distance5);

    printf("The test vector1 is closest to the letter %c\n",findminimum(frechet_distance1,frechet_distance2,frechet_distance3,frechet_distance4,frechet_distance5));

    double frechet_distance6 = frechetDistance(path1, path7);
    printf("Frechet distance A & test2: %.2f\n", frechet_distance6);
    double frechet_distance7 = frechetDistance(path2, path7);
    printf("Frechet distance E & test2: %.2f\n", frechet_distance7);
    double frechet_distance8 = frechetDistance(path3, path7);
    printf("Frechet distance I & test2: %.2f\n", frechet_distance8);
    double frechet_distance9 = frechetDistance(path4, path7);
    printf("Frechet distance O & test2: %.2f\n", frechet_distance9);
    double frechet_distance10 = frechetDistance(path5, path7);
    printf("Frechet distance U & test2: %.2f\n", frechet_distance10);

   printf("The test vector2 is closest to the letter %c\n",findminimum(frechet_distance6,frechet_distance7,frechet_distance8,frechet_distance9,frechet_distance10));

    double frechet_distance11 = frechetDistance(path1, path8);
    printf("Frechet distance A & test3: %.2f\n", frechet_distance11);
    double frechet_distance12 = frechetDistance(path2, path8);
    printf("Frechet distance E & test3: %.2f\n", frechet_distance12);
    double frechet_distance13 = frechetDistance(path3, path8);
    printf("Frechet distance I & test3: %.2f\n", frechet_distance13);
    double frechet_distance14 = frechetDistance(path4, path8);
    printf("Frechet distance O & test3: %.2f\n", frechet_distance14);
    double frechet_distance15 = frechetDistance(path5, path8);
    printf("Frechet distance U & test3: %.2f\n", frechet_distance15);

    printf("The test vector3 is closest to the letter %c\n",findminimum(frechet_distance11,frechet_distance12,frechet_distance13,frechet_distance14,frechet_distance15));

    double frechet_distance16 = frechetDistance(path1, path9);
    printf("Frechet distance A & test4: %.2f\n", frechet_distance16);
    double frechet_distance17 = frechetDistance(path2, path9);
    printf("Frechet distance E & test4: %.2f\n", frechet_distance17);
    double frechet_distance18 = frechetDistance(path3, path9);
    printf("Frechet distance I & test4: %.2f\n", frechet_distance18);
    double frechet_distance19 = frechetDistance(path4, path9);
    printf("Frechet distance O & test4: %.2f\n", frechet_distance19);
    double frechet_distance20 = frechetDistance(path5, path9);
    printf("Frechet distance U & test4: %.2f\n", frechet_distance20);

    printf("The test vector4 is closest to the letter %c\n",findminimum(frechet_distance16,frechet_distance17,frechet_distance18,frechet_distance19,frechet_distance20));

    double frechet_distance21 = frechetDistance(path1, path10);
    printf("Frechet distance A & test1: %.2f\n", frechet_distance21);
    double frechet_distance22 = frechetDistance(path2, path10);
    printf("Frechet distance E & test1: %.2f\n", frechet_distance22);
    double frechet_distance23 = frechetDistance(path3, path10);
    printf("Frechet distance I & test1: %.2f\n", frechet_distance23);
    double frechet_distance24 = frechetDistance(path4, path10);
    printf("Frechet distance O & test1: %.2f\n", frechet_distance24);
    double frechet_distance25 = frechetDistance(path5, path10);
    printf("Frechet distance U & test1: %.2f\n", frechet_distance25);

    printf("The test vector5 is closest to the letter %c\n",findminimum(frechet_distance21,frechet_distance22,frechet_distance23,frechet_distance24,frechet_distance25));

    double frechet_distance26 = frechetDistance(path1, path11);
    printf("Frechet distance A & test6: %.2f\n", frechet_distance26);
    double frechet_distance27 = frechetDistance(path2, path11);
    printf("Frechet distance E & test6: %.2f\n", frechet_distance27);
    double frechet_distance28 = frechetDistance(path3, path11);
    printf("Frechet distance I & test6: %.2f\n", frechet_distance28);
    double frechet_distance29 = frechetDistance(path4, path11);
    printf("Frechet distance O & test6: %.2f\n", frechet_distance29);
    double frechet_distance30 = frechetDistance(path5, path11);
    printf("Frechet distance U & test6: %.2f\n", frechet_distance30);

    printf("The test vector6 is closest to the letter %c\n",findminimum(frechet_distance26,frechet_distance27,frechet_distance28,frechet_distance29,frechet_distance30));

    double frechet_distance31 = frechetDistance(path1, path12);
    printf("Frechet distance A & test7: %.2f\n", frechet_distance31);
    double frechet_distance32 = frechetDistance(path2, path12);
    printf("Frechet distance E & test7: %.2f\n", frechet_distance32);
    double frechet_distance33 = frechetDistance(path3, path12);
    printf("Frechet distance I & test7: %.2f\n", frechet_distance33);
    double frechet_distance34 = frechetDistance(path4, path12);
    printf("Frechet distance O & test7: %.2f\n", frechet_distance34);
    double frechet_distance35 = frechetDistance(path5, path12);
    printf("Frechet distance U & test7: %.2f\n", frechet_distance35);

    printf("The test vector7 is closest to the letter %c\n",findminimum(frechet_distance31,frechet_distance32,frechet_distance33,frechet_distance34,frechet_distance35));

    double frechet_distance36 = frechetDistance(path1, path13);
    printf("Frechet distance A & test8: %.2f\n", frechet_distance36);
    double frechet_distance37 = frechetDistance(path2, path13);
    printf("Frechet distance E & test8: %.2f\n", frechet_distance37);
    double frechet_distance38 = frechetDistance(path3, path13);
    printf("Frechet distance I & test8: %.2f\n", frechet_distance38);
    double frechet_distance39 = frechetDistance(path4, path13);
    printf("Frechet distance O & test8: %.2f\n", frechet_distance39);
    double frechet_distance40 = frechetDistance(path5, path13);
    printf("Frechet distance U & test8: %.2f\n", frechet_distance40);

    printf("The test vector8 is closest to the letter %c\n",findminimum(frechet_distance36,frechet_distance37,frechet_distance38,frechet_distance39,frechet_distance40));

    double frechet_distance41 = frechetDistance(path1, path14);
    printf("Frechet distance A & test9: %.2f\n", frechet_distance41);
    double frechet_distance42 = frechetDistance(path2, path14);
    printf("Frechet distance E & test9: %.2f\n", frechet_distance42);
    double frechet_distance43 = frechetDistance(path3, path14);
    printf("Frechet distance I & test9: %.2f\n", frechet_distance43);
    double frechet_distance44 = frechetDistance(path4, path14);
    printf("Frechet distance O & test9: %.2f\n", frechet_distance44);
    double frechet_distance45 = frechetDistance(path5, path14);
    printf("Frechet distance U & test9: %.2f\n", frechet_distance45);

    printf("The test vector9 is closest to the letter %c\n",findminimum(frechet_distance41,frechet_distance42,frechet_distance43,frechet_distance44,frechet_distance45));

    double frechet_distance46 = frechetDistance(path1, path15);
    printf("Frechet distance A & test10: %.2f\n", frechet_distance46);
    double frechet_distance47 = frechetDistance(path2, path15);
    printf("Frechet distance E & test10: %.2f\n", frechet_distance47);
    double frechet_distance48 = frechetDistance(path3, path15);
    printf("Frechet distance I & test10: %.2f\n", frechet_distance48);
    double frechet_distance49 = frechetDistance(path4, path15);
    printf("Frechet distance O & test10: %.2f\n", frechet_distance49);
    double frechet_distance50 = frechetDistance(path5, path15);
    printf("Frechet distance U & test10: %.2f\n", frechet_distance50);

    printf("The test vector10 is closest to the letter %c\n",findminimum(frechet_distance46,frechet_distance47,frechet_distance48,frechet_distance49,frechet_distance50));

    return 0;
}
