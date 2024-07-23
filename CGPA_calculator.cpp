#include <iostream>
#include <vector>
using namespace std;

// Function-1 to calculate SGPA
double calculateSGPA(vector<int> credits, vector<double> gradePoints) {
    double sumCP = 0.0, sumC = 0.0;
    int n = credits.size();
    for (int i = 0; i < n; ++i) {
        sumCP += credits[i] * gradePoints[i];
        sumC += credits[i];
    }
    return sumCP / sumC;
}

// Function-2 to calculate CGPA
double calculateCGPA(vector<double> sgpas, vector<int> totalCredits) {
    double sumSGNC = 0.0, sumNC = 0.0;
    int m = sgpas.size();
    for (int j = 0; j < m; ++j) {
        sumSGNC += sgpas[j] * totalCredits[j];
        sumNC += totalCredits[j];
    }
    return sumSGNC / sumNC;
}
// this is main function
int main() {
    int numSemesters;
    cout << "Enter the number of semesters: ";
    cin >> numSemesters;

    vector<double> sgpas(numSemesters);
    vector<int> totalCredits(numSemesters);

    for (int i = 0; i < numSemesters; ++i) {
        cout << "Enter SGPA for semester " << i + 1 << ": ";
        cin >> sgpas[i];
        cout << "Enter total credits for semester " << i + 1 << ": ";
        cin >> totalCredits[i];
    }

    double cgpa = calculateCGPA(sgpas, totalCredits);
    cout << "Your CGPA is: " << cgpa << endl;

    return 0;
}