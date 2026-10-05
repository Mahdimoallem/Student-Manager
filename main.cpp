#include <iostream>
#include <cstring>
using namespace std;

const int MAXSTUDENTS = 100;

struct Student
{
   char name[50];
   int age;
   float grade;
};
Student students[MAXSTUDENTS];
int studentCount = 0;
void addStudent()
{
    if (studentCount >= MAXSTUDENTS)
    {
        cout << "Student list is full!" <<endl;
        return;
    }
    cout << "Enter name: ";
    cin.ignore();
    cin.getline(students[studentCount].name, 50);

    cout << "Enter age: ";
    cin >> students[studentCount].age;

    cout << "Enter grade: ";
    cin >> students[studentCount].grade;

    studentCount++;

    cout << "Student added!" << endl;
}
void viewALLStudents()
{
    if(studentCount == 0)
    {
        cout << "No student yet."<< endl;
        return;
    }
    for (int i = 0; i < studentCount; i++)
    {
        cout << i + 1 << ". Name: "<< students[i].name << ", Age: "<< students[i].age<< ", Grade: "<< students[i].grade<< endl;
    }
}
int findStudentByName(const char* name)
{
    for (int i = 0; i < studentCount;i++)
    {
        if(strcmp(students[i].name, name) == 0)
            return i;
    }
    return -1;
}
void searchStudent()
{
    char name[50];
    cout << "Enter name to search: ";
    cin.ignore();
    cin.getline(name, 50);

    int index = findStudentByName(name);

    if (index == -1)
    {
        cout << "Student not found." << endl;
    }
    else
    {
        cout << "found name: "<< students[index].name << ", Age: " << students[index].age <<", Grade:" << students[index].grade << endl;
    }
}
void deleteStudent()
{
    char name[50];

    cout << "Enter name to delete: ";
    cin.ignore();
    cin.getline(name, 50);

    int index = findStudentByName(name);

    if (index == -1)
    {
        cout << "Student not found." << endl;
    }
    for(int i = index; i < studentCount -1;i++)
        students[i] = students[i + 1];

    studentCount--;

    cout << "Student delete!" << endl;
}
float averageGrade()
{
    if (studentCount == 0)
        return 0;

    float sum = 0;

    for (int i = 0;i < studentCount;i++)
        sum += students[i].grade;

    return sum / studentCount;
}
int main()
{
    int choice;

    do
    {
        cout << endl << "1. Add Student" << endl;
        cout << "2. View All Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. delete Student" << endl;
        cout << "5. Average grade"<< endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1)
            addStudent();
        else if (choice == 2)
            viewALLStudents();
        else if (choice == 3)
            searchStudent();
        else if (choice == 4)
             deleteStudent();
        else if (choice == 5)
             cout << "Average Grade: " << averageGrade() <<endl;
        else if (choice == 6)
             cout << "Goodbye!" << endl;
        else
             cout << "Invalid choice! Try again." << endl;
    }
    while (choice != 6);
    return 0;
}
