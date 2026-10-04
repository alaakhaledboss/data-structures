#include <iostream>
#include <string>
using namespace std;

const int SIZE = 4;

struct Date {
    int d;
    int m;
    int y;
};

struct Student {
    double ID;
    string name;
    double gpa;
    Date dob;
    bool ap;        // Academic Probation status (1 = true, 0 = false)
    char co[4];     // Grades for PHY, CHY, MATH, BIO
};

// Function to manually input student data
void read(Student a[]) {
    cout << "\n--- Enter Data for " << SIZE << " Students ---\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Enter ID: ";
        cin >> a[i].ID;
        cout << "Enter Name: ";
        cin >> a[i].name;
        cout << "Enter GPA: ";
        cin >> a[i].gpa;
        cout << "Enter Date of Birth (Day Month Year): ";
        cin >> a[i].dob.d >> a[i].dob.m >> a[i].dob.y;
        cout << "Academic Probation (1 for Yes, 0 for No): ";
        cin >> a[i].ap;
        cout << "Enter 4 course grades (PHY CHY MATH BIO): ";
        for (int j = 0; j < 4; j++) {
            cin >> a[i].co[j];
        }
    }
}

// Function to auto-fill preset sample data from document
void autoFill(Student a[]) {
    // Student 1: Ahmad
    a[0] = {998542, "Ahmad", 3.8, {19, 5, 2002}, false, {'A', 'C', 'F', 'D'}};
    
    // Student 2: Sara
    a[1] = {986521, "Sara", 3.5, {20, 6, 2002}, false, {'F', 'B', 'A', 'C'}};
    
    // Student 3: Rami
    a[2] = {995271, "Rami", 2.8, {18, 1, 2003}, false, {'F', 'A', 'A', 'A'}};
    
    // Student 4: Rania
    a[3] = {987741, "Rania", 4.0, {13, 8, 2003}, false, {'A', 'A', 'A', 'A'}};

    cout << "\nPreset data successfully loaded!\n";
}

// Function to print student details
void print(Student a[]) {
    cout << "\n--- Student Records ---\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "ID: " << a[i].ID 
             << " | Name: " << a[i].name 
             << " | GPA: " << a[i].gpa 
             << " | DOB: " << a[i].dob.d << "/" << a[i].dob.m << "/" << a[i].dob.y 
             << " | AP: " << (a[i].ap ? "Yes" : "No") 
             << " | Grades: ";
        for (int j = 0; j < 4; j++) {
            cout << a[i].co[j] << " ";
        }
        cout << endl;
    }
}

// Function to check and print students on Academic Probation
void APs(Student a[]) {
    cout << "\n--- Students on Academic Probation ---\n";
    bool found = false;
    for (int i = 0; i < SIZE; i++) {
        if (a[i].ap) {
            cout << a[i].name << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "None\n";
    }
}

// Function to count and print number of 'F' grades per student
void Fs(Student a[]) {
    cout << "\n--- Number of Fs per Student ---\n";
    for (int i = 0; i < SIZE; i++) {
        int count = 0;
        for (int j = 0; j < 4; j++) {
            if (a[i].co[j] == 'F' || a[i].co[j] == 'f') {
                count++;
            }
        }
        cout << a[i].name << ": " << count << " F(s)\n";
    }
}

// HW Function: Print students born after 2002 (y > 2002)
void printDOBLargerThan2002(Student a[]) {
    cout << "\n--- Students born after 2002 ---\n";
    bool found = false;
    for (int i = 0; i < SIZE; i++) {
        if (a[i].dob.y > 2002) {
            cout << a[i].name << " (Year: " << a[i].dob.y << ")\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No students found born after 2002.\n";
    }
}

int main() {
    Student students[SIZE];
    int choice;

    do {
        cout << "\n=========================================\n";
        cout << "           STUDENT MANAGEMENT MENU      \n";
        cout << "=========================================\n";
        cout << "1. Auto-fill Data (Pre-defined values)\n";
        cout << "2. Manually Enter Student Data\n";
        cout << "3. Print All Student Data\n";
        cout << "4. Print Students on Academic Probation\n";
        cout << "5. Count 'F' Grades per Student\n";
        cout << "6. Print Students Born After 2002\n";
        cout << "7. Exit\n";
        cout << "Enter option (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1:
                autoFill(students);
                break;
            case 2:
                read(students);
                break;
            case 3:
                print(students);
                break;
            case 4:
                APs(students);
                break;
            case 5:
                Fs(students);
                break;
            case 6:
                printDOBLargerThan2002(students);
                break;
            case 7:
                cout << "\nExiting Program. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid option! Please try again.\n";
                break;
        }
    } while (choice != 7);

    return 0;
}