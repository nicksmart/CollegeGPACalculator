//
//  main.cpp
//  GPACalculator
//
//  Created by Nick Smart on 12/21/16.
//  Copyright © 2016 Nick Smart. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

void getGradesFromUser(double &gpa);
double gradeToDouble(string &grade, int creditCount);

int main(int argc, const char * argv[]) {
    cout << setprecision(4);
    
    double gpa;
    getGradesFromUser(gpa);
    
    cout << "\nTerm GPA = " << gpa << endl << endl;
    
    return 0;
}

void getGradesFromUser(double &gpa) {
    int numCourses, loopCounter = 0, creditCount, creditsTaken = 0;
    double creditsReceived = 0;
    string grade;
    
    cout << "How many courses did you take?" << endl;
    cin >> numCourses;
    cout << endl;
    
    while (loopCounter < numCourses) {
        cout << "How many credits was course #" << loopCounter + 1 << "?" << endl;
        cin >> creditCount;
        creditsTaken += creditCount;
        cout << "What letter grade did you receive in course #" << loopCounter + 1 << "?" << endl;
        cin >> grade;
        if (grade[0] > 90)
            grade[0] = grade[0] - 32;
        creditsReceived += gradeToDouble(grade, creditCount);
        
        loopCounter++;
    }
    
    gpa = creditsReceived / creditsTaken;
}

double gradeToDouble(string &grade, int creditCount) {
    if (grade.length() == 1) {
        if (grade.compare("A") == 0) {
            return 4 * creditCount;
        }
        else if (grade.compare("B") == 0) {
            return 3 * creditCount;
        }
        else if (grade.compare("C") == 0) {
            return 2 * creditCount;
        }
        else if (grade.compare("D") == 0) {
            return creditCount;
        }
        else if (grade.compare("F") == 0 or grade.compare("F") == 0) {
            return 0;
        }
        else {
            cerr << "Invalid letter grade input" << endl;
            exit(1);
        }
    }
    else {
        if (grade[0] == 'A') {
            if (grade[1] == '-')
                return 3.7 * creditCount;
            else
                return 4 * creditCount;
        }
        else if (grade[0] == 'B') {
            if (grade[1] == '+')
                return 3.3 * creditCount;
            else
                return 2.7 * creditCount;
        }
        else if (grade[0] == 'C') {
            if (grade[1] == '+')
                return 2.3 * creditCount;
            else
                return 1.7 * creditCount;
        }
        else if (grade[0] == 'D') {
            if (grade[1] == '+')
                return 1.3 * creditCount;
            else
                return 0.7 * creditCount;
        }
        else {
            cerr << "Invalid letter grade input" << endl;
            exit(1);
        }
    }
    
    return 0;
}









