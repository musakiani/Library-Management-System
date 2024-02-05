// Muhammad Musa Kiani.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_RECORDS = 100;

// Structure to represent a library record
struct LibraryRecord {
    int bookId;
    string bookTitle;
    string author;
};

// Function to create a new library record
void createRecord(LibraryRecord library[], int& recordCount) {
    if (recordCount < MAX_RECORDS) {
        cout << "Enter Book ID: ";
        cin >> library[recordCount].bookId;

        cin.ignore(); // Clear the newline character from the buffer
        cout << "Enter Book Title: ";
        getline(cin, library[recordCount].bookTitle);

        cout << "Enter Author: ";
        getline(cin, library[recordCount].author);

        cout << "Record added successfully.\n";
        recordCount++;
    } else {
        cout << "Library is full. Cannot add more records.\n";
    }
}

// Function to update an existing library record
void updateRecord(LibraryRecord library[], int recordCount) {
    int bookId;
    cout << "Enter Book ID to update: ";
    cin >> bookId;

    bool found = false;
    for (int i = 0; i < recordCount; ++i) {
        if (library[i].bookId == bookId) {
            cin.ignore(); // Clear the newline character from the buffer
            cout << "Enter new Book Title: ";
            getline(cin, library[i].bookTitle);

            cout << "Enter new Author: ";
            getline(cin, library[i].author);

            cout << "Record updated successfully.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book ID not found.\n";
    }
}

// Function to list all library records
void listAllRecords(const LibraryRecord library[], int recordCount) {
    cout <<setw(10) << "Book ID" <<setw(30) << "Book Title" << setw(20) << "Author" << "\n";
    cout <<setfill('-') <<setw(60) << "\n" <<setfill(' ');

    for (int i = 0; i < recordCount; ++i) {
        cout <<setw(10) << library[i].bookId <<setw(30) << library[i].bookTitle <<setw(20) << library[i].author << "\n";
    }
}

// Function to list an individual library record
void listIndividualRecord(const LibraryRecord library[], int recordCount) {
    int bookId;
    cout << "Enter Book ID to display: ";
    cin >> bookId;

    bool found = false;
    for (int i = 0; i < recordCount; ++i) {
        if (library[i].bookId == bookId) {
            cout <<setw(10) << "Book ID" <<setw(30) << "Book Title" <<setw(20) << "Author" << "\n";
            cout <<setfill('-') <<setw(60) << "\n" <<setfill(' ');

            cout <<setw(10) << library[i].bookId <<setw(30) << library[i].bookTitle <<setw(20) << library[i].author << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book ID not found.\n";
    }
}

// Function to delete a library record
void deleteRecord(LibraryRecord library[], int& recordCount) {
    int bookId;
    cout << "Enter Book ID to delete: ";
    cin >> bookId;

    int indexToDelete = -1;
    for (int i = 0; i < recordCount; ++i) {
        if (library[i].bookId == bookId) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete != -1) {
        for (int i = indexToDelete; i < recordCount - 1; ++i) {
            library[i] = library[i + 1];
        }
        recordCount--;
        cout << "Record deleted successfully.\n";
    } else {
        cout << "Book ID not found.\n";
    }
}

// Function to display menu for library administrator
void adminMenu(LibraryRecord library[], int& recordCount) {
    int choice;

    do {
        cout << "\nAdmin Menu\n";
        cout << "1. Create Record\n";
        cout << "2. Update Record\n";
        cout << "3. List All Records\n";
        cout << "4. List an Individual Record\n";
        cout << "5. Delete Record\n";
        cout << "0. Exit Admin Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createRecord(library, recordCount);
                break;
            case 2:
                updateRecord(library, recordCount);
                break;
            case 3:
                listAllRecords(library, recordCount);
                break;
            case 4:
                listIndividualRecord(library, recordCount);
                break;
            case 5:
                deleteRecord(library, recordCount);
                break;
            case 0:
                cout << "Exiting admin menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

// Function to display menu for normal user
void userMenu(const LibraryRecord library[], int recordCount) {
    int choice;

    do {
        cout << "\nUser Menu\n";
        cout << "1. List All Records\n";
        cout << "2. List an Individual Record\n";
        cout << "0. Exit User Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                listAllRecords(library, recordCount);
                break;
            case 2:
                listIndividualRecord(library, recordCount);
                break;
            case 0:
                cout << "Exiting user menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

int main() {
    LibraryRecord library[MAX_RECORDS];
    int recordCount = 0;

    int userRole; // 1 for administrator, 0 for normal user

    cout << "Enter user role (1 for administrator, 0 for normal user): ";
    cin >> userRole;

    if (userRole == 1) {
        adminMenu(library, recordCount);
    } else {
        userMenu(library, recordCount);
    }
	system("pause");
    return 0;
}

