
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;           
    string name;
    int age;
    string category;
    Node* left;
    Node* right;

    Node(int id, string n, int a, string c) {
        data = id;
        name = n;
        age = a;
        category = c;
        left = NULL;
        right = NULL;
    }
};

Node* root = NULL;

// Insert a new patient
Node* insert(Node* root, int id, string name, int age, string category) {
    if (root == NULL) {
        return new Node(id, name, age, category);
    }

    if (id < root->data) {
        root->left = insert(root->left, id, name, age, category);
    }
    else if (id > root->data) {
        root->right = insert(root->right, id, name, age, category);
    }
    else {
        cout << "Duplicate Patient ID! Record not inserted.\n";
    }

    return root;
}

// Find minimum node
Node* findMin(Node* root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

// Search for a patient
Node* search(Node* root, int id) {
    if (root == NULL || root->data == id)
        return root;

    if (id < root->data)
        return search(root->left, id);

    return search(root->right, id);
}

// Delete a patient (all three cases)
Node* deleteNode(Node* root, int id) {
    if (root == NULL)
        return NULL;

    if (id < root->data) {
        root->left = deleteNode(root->left, id);
    }
    else if (id > root->data) {
        root->right = deleteNode(root->right, id);
    }
    else {
        // Case 1 and Case 2: No left child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: No right child
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(root->right);

        root->data = temp->data;
        root->name = temp->name;
        root->age = temp->age;
        root->category = temp->category;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Display one patient
void displayPatient(Node* p) {
    cout << "Patient ID: " << p->data
         << " | Name: " << p->name
         << " | Age: " << p->age
         << " | Emergency Category: " << p->category
         << endl;
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    displayPatient(root);
    inorder(root->right);
}

// Display patients within a given ID range
void rangeSearch(Node* root, int low, int high) {
    if (root == NULL)
        return;

    if (root->data > low)
        rangeSearch(root->left, low, high);

    if (root->data >= low && root->data <= high)
        displayPatient(root);

    if (root->data < high)
        rangeSearch(root->right, low, high);
}

int countPatients(Node* root) {
    if (root == NULL)
        return 0;

    return 1 + countPatients(root->left)
             + countPatients(root->right);
}

int main() {
    int input = 1;


    root = insert(root, 450, "Patient450", 45, "High");
    root = insert(root, 250, "Patient250", 35, "Medium");
    root = insert(root, 650, "Patient650", 60, "High");
    root = insert(root, 150, "Patient150", 25, "Low");
    root = insert(root, 350, "Patient350", 40, "Medium");
    root = insert(root, 550, "Patient550", 50, "High");
    root = insert(root, 750, "Patient750", 70, "Low");
    root = insert(root, 300, "Patient300", 30, "Medium");
    root = insert(root, 400, "Patient400", 42, "Low");
    root = insert(root, 600, "Patient600", 55, "High");

    while (input != 0) {
     
        cout << "1. Register New Patient\n";
        cout << "2. Search Patient by ID\n";
        cout << "3. Update Emergency Category\n";
        cout << "4. Delete Patient Record\n";
        cout << "5. Display All Patients (Ascending ID)\n";
        cout << "6. Display Patients Within ID Range\n";
        cout << "7. Count Total Patients\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> input;

        if (input == 1) {
            int id, age;
            string name, category;

            cout << "Enter Patient ID: ";
            cin >> id;

            if (search(root, id) != NULL) {
                cout << "Patient ID already exists!\n";
                continue;
            }

            cout << "Enter Patient Name: ";
            getline(cin >> ws, name);

            cout << "Enter Patient Age: ";
            cin >> age;

            cout << "Enter Emergency Category: ";
            getline(cin >> ws, category);

            root = insert(root, id, name, age, category);
            cout << "Patient registered successfully!\n";
        }
        else if (input == 2) {
            int id;

            cout << "Enter Patient ID to search: ";
            cin >> id;

            Node* p = search(root, id);

            if (p != NULL)
                displayPatient(p);
            else
                cout << "Patient ID does not exist!\n";
        }
        else if (input == 3) {
            int id;
            string category;

            cout << "Enter Patient ID: ";
            cin >> id;

            Node* p = search(root, id);

            if (p == NULL) {
                cout << "Patient ID does not exist!\n";
            }
            else {
                cout << "Enter New Emergency Category: ";
                getline(cin >> ws, category);

                p->category = category;
                cout << "Emergency category updated successfully!\n";
            }
        }
        else if (input == 4) {
            int id;

            cout << "Enter Patient ID to delete: ";
            cin >> id;

            if (search(root, id) == NULL) {
                cout << "Patient ID does not exist!\n";
            }
            else {
                root = deleteNode(root, id);
                cout << "Patient record deleted successfully!\n";
            }
        }
        else if (input == 5) {
            if (root == NULL)
                cout << "No patient records available.\n";
            else
                inorder(root);
        }
        else if (input == 6) {
            int low, high;

            cout << "Enter minimum Patient ID: ";
            cin >> low;

            cout << "Enter maximum Patient ID: ";
            cin >> high;

            if (low > high) {
                cout << "Invalid range! Minimum ID must not exceed maximum ID.\n";
            }
            else {
                cout << "Patients in the given range:\n";
                rangeSearch(root, low, high);
            }
        }
        else if (input == 7) {
            cout << "Total registered patients: "
                 << countPatients(root) << endl;
        }
        else if (input == 0) {
            cout << "Exiting Hospital Patient System.\n";
        }
        else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
