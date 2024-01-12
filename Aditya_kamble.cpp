#include <bits/stdc++.h>
using namespace std;

class student {
private:
    string name;
    vector<string> subjects;
    vector<int> marks;
    vector<int> totalMarks;

public:
    student(const string& studentName, const vector<int>& studentMarks)
        : name(studentName),
          subjects({"DSA", "OOPS", "DBMS", "CCN", "Math"}),
          totalMarks({100, 100, 100, 100, 100}),
          marks(studentMarks.begin(), studentMarks.end()) {}

    template <typename S>
    void printv(const vector<S>& v) const {
        cout << "[ ";
        for (auto elem : v) {
            cout << elem << " ";
        }
        cout << "]";
        cout << endl;
    }

    int calculateTotalMarks() const {
        int sum = 0;
        for (int mark : marks) {
            sum += mark;
        }
        return sum;
    }

    void printStudent() const {
        cout << "Student Details:" << endl << endl;
        cout << "Name: " << name << endl;
        cout << "Subjects: ";
        printv(subjects);
        cout << "Total Marks: ";
        printv(totalMarks);
        cout << "Marks: ";
        printv(marks);
        cout << "Total Marks Obtained: " << calculateTotalMarks() << endl;
    }
};

bool compareStudents(const student& s1, const student& s2) {
    return s1.calculateTotalMarks() > s2.calculateTotalMarks();
}

int main() {
    vector<student> students;
    for (int i = 1; i <= 20; ++i) {
        string studentName = "Student" + to_string(i);
        vector<int> studentMarks;
        for (int j = 0; j < 5; ++j) {
            studentMarks.push_back(rand() % 41 + 60);
        }
        students.push_back(student(studentName, studentMarks));
    }

    sort(students.begin(), students.end(), compareStudents);

    for (int i = 0; i < 5; ++i) {
        students[i].printStudent();
        cout << "------------------------" << endl;
    }

    return 0;
}

