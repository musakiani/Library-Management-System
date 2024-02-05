# Library-Management-System

C++ Library Management System with Access Control
This repository holds the source code for a C++ Library Management System with user roles and access control. It enables efficient management of library resources through various functionalities:

Features:

User Roles:
Admin: Full access to create, update, delete records, and manage user accounts.
User: Can search, view, and borrow/return books within set limits.
Record Management:
Create Records: Add new books with details (title, author, ISBN, etc.).
Update Records: Modify existing book information (restricted to admin).
List Records: View all or specific books (search by title, author, ISBN).
Delete Records: Remove books from the database (restricted to admin).
Borrowing and Returning:
Borrow Books: Users can request available books within borrowing limits.
Return Books: Submit borrowed books and update records.
Overdue Tracking: System tracks due dates and generates notifications for overdue books.
Access Control:
Separate login credentials for admins and users.
Function restrictions based on user role (e.g., only admin can edit sensitive information).
1: Create Record
2: update record with new values
3: list all records
4: list an individual record
5: delete record

Project Structure:

src: Contains all C++ source code files (.cpp).
include: Holds header files (.h) for function declarations and structures.
data: (Optional) Stores sample data files for testing.
bin: (Optional) Holds compiled executables (e.g., LibraryManagement.exe).
README.md: This file (you are reading it!).
This is only a Command Line Interface.

Author: Muhammad Musa Kiani.
