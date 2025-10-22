#include <stdio.h>
#include <string.h>

#define MAX_CLASSES 10
#define MAX_STUDENTS 100

// Global variables
char classTimes[MAX_CLASSES][7]; // Stores class times
char classNames[MAX_CLASSES][50]; // Stores class names
char venues[MAX_CLASSES][50];     // Stores class venues\n
int totalClasses = 0;             // Tracks number of classes

char students[MAX_STUDENTS][50];  // Stores student names
int totalStudents = 0;            // Tracks number of students

int attendance[MAX_CLASSES][MAX_STUDENTS]; // 2D array for attendance records

// Function declarations
void displayMenu();
void scheduleClass();
void addStudent();
void recordAttendance();
void studentAttendanceSummary();
void classAttendanceSummary();

int main() {
    displayMenu();
    return 0;
}

// Function to display menu
void displayMenu() {
    int choice;

    while (1) { // Infinite loop for menu
        printf("\n---Attendance Management System---\n");
        printf("1. Schedule Class\n");
        printf("2. Add Student\n");
        printf("3. Record Attendance\n");
        printf("4. Student Attendance Summary\n");
        printf("5. Class Attendance Summary\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: scheduleClass(); break;
            case 2: addStudent(); break;
            case 3: recordAttendance(); break;
            case 4: studentAttendanceSummary(); break;
            case 5: classAttendanceSummary(); break;
            case 6: 
                printf("Exiting program...\n");
                return; // Exits function, stopping the loop
            default: 
                printf("Invalid choice! Try again.\n");
        }
    }
}

// Function to schedule a class
void scheduleClass() {
    if (totalClasses >= MAX_CLASSES || strchr(classTimes[totalClasses], '-') != NULL) {
    printf("Class limit reached or invalid time input!\n");
    printf("Invalid time! '-' is not allowed in time input.\n");
    return;
 }


    
    printf("Enter class name: ");
    scanf(" %[^\n]", classNames[totalClasses]); // Reads full line including spaces

    printf("Enter venue: ");
    scanf(" %[^\n]", venues[totalClasses]);

    printf("Enter class time (HH:MM): ");
    scanf(" %[^\n]", classTimes[totalClasses]); // Reads full line including spaces

    printf("Class '%s' scheduled in '%s'.\n", classNames[totalClasses], venues[totalClasses]);
    totalClasses++;
}

// Function to add a student
void addStudent() {
    if (totalStudents >= MAX_STUDENTS) {
        printf("Student limit reached!\n");
        return;
    }


    printf("Enter student name: ");
    scanf(" %[^\n]", students[totalStudents]); // Reads full line including spaces

    printf("Student '%s' added successfully.\n", students[totalStudents]);
    totalStudents++;
}

// Function to record attendance
void recordAttendance() {
    int classIndex, studentIndex, present;

    if (totalClasses == 0 || totalStudents == 0) {
        printf("No classes or students available!\n");
        return;
    }

    // Display available classes
    printf("Available classes:\n");
    for (int i = 0; i < totalClasses; i++) {
        printf("%d. %s (%s)\n", i, classNames[i], venues[i]);
    }

    printf("Enter class index (0 to %d): ", totalClasses - 1);
    scanf("%d", &classIndex);

    if (classIndex < 0 || classIndex >= totalClasses) {
        printf("Invalid class index!\n");
        return;
    }

    printf("Recording attendance for %s class:\n", classNames[classIndex]); 

    for (int i = 0; i < totalStudents; i++) {
        printf("Is %s present? (1 for Yes, 0 for No): ", students[i]);
        scanf("%d", &present);
        attendance[classIndex][i] = present;
    }
    printf("Attendance recorded successfully!\n");
}

// Function to show student attendance summary
void studentAttendanceSummary() {
    int studentIndex;

    if (totalStudents == 0) {
        printf("No students available!\n");
        return;
    }

    // Display available students
    printf("Available students:\n");
    for (int i = 0; i < totalStudents; i++) {
        printf("%d. %s\n", i, students[i]);
    }

    printf("Enter student index (0 to %d): ", totalStudents - 1);
    scanf("%d", &studentIndex);

    if (studentIndex < 0 || studentIndex >= totalStudents) {
        printf("Invalid student index!\n");
        return;
    }

    printf("Attendance Summary for %s:\n", students[studentIndex]);
    for (int i = 0; i < totalClasses; i++) {
        printf("%s: %s\n", classNames[i], attendance[i][studentIndex] ? "Present" : "Absent");
    }
}

// Function to show class attendance summary
void classAttendanceSummary() {
    int classIndex;

    if (totalClasses == 0) {
        printf("No classes available!\n");
        return;
    }

    // Display available classes
    printf("Available classes:\n");
    for (int i = 0; i < totalClasses; i++) {
        printf("%d. %s (%s)\n", i, classNames[i], venues[i]);
    }

    printf("Enter class index (0 to %d): ", totalClasses - 1);
    scanf("%d", &classIndex);

    if (classIndex < 0 || classIndex >= totalClasses) {
        printf("Invalid class index!\n");
        return;
    }

    printf("Attendance Summary for %s class:\n", classNames[classIndex]);
    for (int i = 0; i < totalStudents; i++) {
        printf("%s: %s\n", students[i], attendance[classIndex][i] ? "Present" : "Absent");
    }
}












