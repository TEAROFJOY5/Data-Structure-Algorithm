/*
Q5. Employee Management Hierarchy
Scenario: In a company, each manager supervises several employees, and some employees may themselves be managers. The company wants to count all employees working under a particular manager, including employees in lower-level departments.
Task:
Write a recursive C++ function countEmployees() that counts all employees under a given manager.
Requirements:
Each employee can supervise zero or more employees.
Recursively count employees in all subordinate branches.
Do not count the given manager as their own subordinate.
Example:
CEO
├── Manager A
│   ├── Employee 1
│   └── Employee 2
└── Manager B
    ├── Employee 3
    └── Team Leader
        ├── Employee 4
        └── Employee 5
Expected Output:
Total employees under CEO = 8
*/
#include <iostream>
using namespace std;

struct Employee {
    char name[50];
    Employee* subordinates[10];
    int count;
};

int countEmployees(Employee* manager) {
    int total = 0;

    for (int i = 0; i < manager->count; i++) {
        total++;
        total += countEmployees(manager->subordinates[i]);
    }

    return total;
}

int main() {
    Employee e1 = {"Employee 1", {}, 0};
    Employee e2 = {"Employee 2", {}, 0};
    Employee e3 = {"Employee 3", {}, 0};
    Employee e4 = {"Employee 4", {}, 0};
    Employee e5 = {"Employee 5", {}, 0};

    Employee teamLeader = {"Team Leader", {}, 2};
    teamLeader.subordinates[0] = &e4;
    teamLeader.subordinates[1] = &e5;

    Employee managerA = {"Manager A", {}, 2};
    managerA.subordinates[0] = &e1;
    managerA.subordinates[1] = &e2;

    Employee managerB = {"Manager B", {}, 2};
    managerB.subordinates[0] = &e3;
    managerB.subordinates[1] = &teamLeader;

    Employee CEO = {"CEO", {}, 2};
    CEO.subordinates[0] = &managerA;
    CEO.subordinates[1] = &managerB;

    cout << "Total employees under CEO = "
         << countEmployees(&CEO);

    return 0;
}
