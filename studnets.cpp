
#include <iostream>
using namespace std;

// Node structure for student
struct Student {
    string name;
    int rollNo;
    Student* next;
};

// Linked list class for student management system
class StudentManagementSystem {
private:
    Student* head;

public:
    // Constructor
    StudentManagementSystem() {
        head = NULL;
    }

    // Function to insert a student at the end of the list
    void insertStudent(string name, int rollNo) {
        Student* newStudent = new Student;
        newStudent->name = name;
        newStudent->rollNo = rollNo;
        newStudent->next = NULL;

        if (head == NULL) {
            head = newStudent;
        } else {
            Student* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newStudent;
        }

        cout << "Student inserted successfully!" << endl;
    }

    // Function to search for a student by roll number
    Student* searchStudent(int rollNo) {
        Student* temp = head;
        while (temp != NULL) {
            if (temp->rollNo == rollNo) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    // Function to update a student's details
    void updateStudent(int rollNo, string newName) {
        Student* student = searchStudent(rollNo);
        if (student != NULL) {
            student->name = newName;
            cout << "Student details updated successfully!" << endl;
        } else {
            cout << "Student not found!" << endl;
        }
    }

    // Function to delete a student by roll number
    void deleteStudent(int rollNo) {
        if (head == NULL) {
            cout << "Student list is empty!" << endl;
            return;
        }

        if (head->rollNo == rollNo) {
            Student* temp = head;
            head = head->next;
            delete temp;
            cout << "Student deleted successfully!" << endl;
            return;
        }

        Student* prev = NULL;
        Student* curr = head;

        while (curr != NULL && curr->rollNo != rollNo) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Student not found!" << endl;
            return;
        }

        prev->next = curr->next;
        delete curr;
        cout << "Student deleted successfully!" << endl;
    }

    // Function to count the number of students in the list
    int countStudents() {
        int count = 0;
        Student* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    StudentManagementSystem sms;

    int choice;
    while (true) {
        cout << "-------------------------" << endl;
        cout << "Student Management System" << endl;
        cout << "-------------------------" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Search Student" << endl;
        cout << "3. Update Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Count Students" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int rollNo;
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter student roll number: ";
            cin >> rollNo;
            sms.insertStudent(name, rollNo);
        } else if (choice == 2) {
            int rollNo;
            cout << "Enter roll number to search: ";
            cin >> rollNo;
            Student* searchResult = sms.searchStudent(rollNo);
            if (searchResult != NULL) {
                cout << "Student found - Name: " << searchResult->name << ", Roll No: " << searchResult->rollNo << endl;
            } else {
                cout << "Student not found!" << endl;
            }
        } else if (choice == 3) {
            int rollNo;
            string newName;
            cout << "Enter roll number of student to update: ";
            cin >> rollNo;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, newName);
            sms.updateStudent(rollNo, newName);
        } else if (choice == 4) {
            int rollNo;
            cout << "Enter roll number of student to delete: ";
            cin >> rollNo;
            sms.deleteStudent(rollNo);
        } else if (choice == 5) {
            cout << "Total students: " << sms.countStudents() << endl;
        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
