#include <iostream>
#include <iomanip>  // For setprecision
#include <limits>    // For numeric_limits
#include<string>
using namespace std;

int main()
{
    int num_of_courses;
    float total_grade_points = 0;
    int total_credit_hours = 0;
    int previous_credits = 0;
    float previous_cgpa = 0;

    cout << "----------CGPA CALCULATOR----------\n";

    // Previous academic history input
    cout << "Enter your previous total credits (0 if first semester): ";
    cin >> previous_credits;

    if (previous_credits > 0) {
        cout << "Enter your previous CGPA: ";
        cin >> previous_cgpa;
    }

    // Number of courses
    cout << "\nEnter Number Of Courses: ";
    cin >> num_of_courses;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer

    const int MAX_COURSES = 50;
    char grades[MAX_COURSES];
    int credits[MAX_COURSES];
    float points[MAX_COURSES];

    for (int i = 0; i < num_of_courses && i < MAX_COURSES; i++)
    {
        cout << "\nCourse " << i + 1 << ":\n";

        // Get grade with proper input handling
        bool valid_grade = false;
        while (!valid_grade) {
            cout << "Enter Grade (A,B+,B,C+,C,D,F): ";
            string grade_input;
            getline(cin, grade_input);

            // Convert to uppercase
            for (char& c : grade_input) {
                c = toupper(c);
            }

            // Grade to points conversion
            if (grade_input == "A") {
                points[i] = 4.0;
                grades[i] = 'A';
                valid_grade = true;
            }
            else if (grade_input == "B+") {
                points[i] = 3.5;
                grades[i] = 'P';  // Using 'P' to represent B+
                valid_grade = true;
            }
            else if (grade_input == "B") {
                points[i] = 3.0;
                grades[i] = 'B';
                valid_grade = true;
            }
            else if (grade_input == "C+") {
                points[i] = 2.5;
                grades[i] = 'Q';  // Using 'Q' to represent C+
                valid_grade = true;
            }
            else if (grade_input == "C") {
                points[i] = 2.0;
                grades[i] = 'C';
                valid_grade = true;
            }
            else if (grade_input == "D") {
                points[i] = 1.5;
                grades[i] = 'D';
                valid_grade = true;
            }
            else if (grade_input == "F") {
                points[i] = 0.0;
                grades[i] = 'F';
                valid_grade = true;
            }
            else {
                cout << "Invalid grade. Please try again.\n";
            }
        }

        // Get credit hours with validation
        bool valid_credits = false;
        while (!valid_credits) {
            cout << "Enter Number Of Credit Hours: ";
            cin >> credits[i];

            if (cin.fail() || credits[i] <= 0) {
                cout << "Invalid input. Please enter a positive integer.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                valid_credits = true;
            }
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer

        // Add to totals
        total_grade_points += points[i] * credits[i];
        total_credit_hours += credits[i];
    }

    // Calculate GPA and CGPA
    float semester_gpa = 0.0;
    if (total_credit_hours > 0) {
        semester_gpa = total_grade_points / total_credit_hours;
    }

    float cgpa = semester_gpa;  // Default to semester GPA if no previous credits
    if (previous_credits + total_credit_hours > 0) {
        cgpa = ((previous_cgpa * previous_credits) + total_grade_points) /
            (previous_credits + total_credit_hours);
    }

    // Display results
    cout << fixed << setprecision(2);
    cout << "\n\n----------RESULTS----------\n";
    cout << "Semester GPA: " << semester_gpa << endl;
    cout << "Overall CGPA: " << cgpa << endl;

    return 0;
}