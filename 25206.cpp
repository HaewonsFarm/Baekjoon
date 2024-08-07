#include <iostream>
#include <string>

using namespace std;

int main() {
    string lecture, grade;
    double score, sum = 0, scoreSum = 0;
    string lectureArray[20];
    double scoreArray[20] = {0.0};
    double gradeArray[20] = {0.0};

    for (int i = 0; i < 20; i++) {
        cin >> lecture >> score >> grade;
        lectureArray[i] = lecture;
        scoreArray[i] = score;

        if (grade == "A+")
            gradeArray[i] = 4.5;
        else if (grade == "A0")
            gradeArray[i] = 4.0;
        else if (grade == "B+")
            gradeArray[i] = 3.5;
        else if (grade == "B0")
            gradeArray[i] = 3.0;
        else if (grade == "C+")
            gradeArray[i] = 2.5;
        else if (grade == "C0")
            gradeArray[i] = 2.0;
        else if (grade == "D+")
            gradeArray[i] = 1.5;
        else if (grade == "D0")
            gradeArray[i] = 1.0;
        else if (grade == "F")
            gradeArray[i] = 0.0;
        else
            gradeArray[i] = -1;
    }

    for (int i = 0; i < 20; i++) {
        if (gradeArray[i] == -1)
            continue;
        sum += scoreArray[i] * gradeArray[i];
        scoreSum += scoreArray[i];
    }

    cout << sum / scoreSum << endl;


    return 0;
}