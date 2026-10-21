/*
  Q1. File and Folder Size Calculator
Scenario: A computer stores files inside folders. A folder may contain files as well as other
subfolders. To calculate the total storage used by a folder, the computer must include the
sizes of all files inside it, including those in nested subfolders.
Task:
Write a recursive C++ function calculateSize() that calculates the total size of a folder.
Requirements:
1. If the item is a file, return its size.
2. If the item is a folder, recursively calculate the sizes of all its contents.
3. Return the total storage used in KB.
Example:
Folder Structure
Root (Folder)
├── file1.txt (100 KB)
├── file2.txt (200 KB)
└── Documents (Folder)
├── file3.pdf (300 KB)
└── Notes (Folder)
└── file4.docx (150 KB)
Expected Output:
Total Folder Size = 750 KB
*/

#include <iostream>
using namespace std;

struct Item {
    char name[50];
    bool isFile;
    int size;
    Item* contents[10];
    int count;
};

int calculateSize(Item* item) {
    if (item->isFile) {
        return item->size;
    }

    int total = 0;

    for (int i = 0; i < item->count; i++) {
        total += calculateSize(item->contents[i]);
    }

    return total;
}

int main() {
    Item file1 = {"file1.txt", true, 100, {}, 0};
    Item file2 = {"file2.txt", true, 200, {}, 0};
    Item file3 = {"file3.pdf", true, 300, {}, 0};
    Item file4 = {"file4.docx", true, 150, {}, 0};

    Item notes = {"Notes", false, 0, {}, 1};
    notes.contents[0] = &file4;

    Item documents = {"Documents", false, 0, {}, 2};
    documents.contents[0] = &file3;
    documents.contents[1] = &notes;

    Item root = {"Root", false, 0, {}, 3};
    root.contents[0] = &file1;
    root.contents[1] = &file2;
    root.contents[2] = &documents;

    cout << "Total Folder Size = "
         << calculateSize(&root) << " KB";

    return 0;
}

