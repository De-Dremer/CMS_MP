📘 Census Data Management & Population Analytics
Mini Project — C Program (Console-Based)
📌 Overview
This project is a C-based census management system that stores population data in a hierarchical format:

Country → State → District → Citizen
It uses structures + linked lists for storing data and a Binary Search Tree (BST) for fast citizen lookup using Citizen ID.

The system supports:

Add State, District, Citizen

Search citizen by ID (via BST)

Maintain population counts

Simple text‑based console menu

📁 Project Structure
census_project/
├── model.h          // All structure definitions
├── hierarchy.c      // State/District/Citizen linked-list functions
├── search.c         // BST insert/search
├── main.c           // Menu, input handling, workflow control
├── Makefile         // Build rules
└── README.md        // Documentation
🧩 Data Structures
Country
name

pointer to list of states

State
name

population

linked list of districts

District
district_id

name

population

linked list of citizens

Citizen
citizen_id

name

age

gender

occupation

income

next citizen pointer

BST Node
Used for searching citizens efficiently by ID.

⚙️ Features Implemented
✔ Add Complete Entry
User can enter:

State

District

Citizen details (ID, name, age, gender, occupation, income)

System automatically:

Creates state/district if not found

Inserts citizen into district list

Inserts citizen ID into BST

✔ Search by Citizen ID
Fast lookup using BST.

✔ Display Citizen Details
✔ Input Validations
No duplicate IDs

Basic error checking

Dynamic memory usage

▶️ How to Compile and Run
Using Makefile
make
./census
Without Makefile
gcc main.c hierarchy.c search.c -o census
./census
🖥 Sample Main Menu
===== CENSUS MANAGEMENT SYSTEM =====
1. Enter details
2. Search and display details
3. Exit
🧪 Recommended Test Cases
Test	Description
1	Add multiple citizens across states/districts
2	Add a citizen with same ID → should show error
3	Search existing citizen ID
4	Search non-existing ID
5	Add 20+ entries, test BST behavior
👥 Team Roles
Member	Work Assigned
Member 1	model.h + hierarchy.c
Member 2	search.c (BST)
Member 3	history / undo (optional)
Member 4	main.c + Makefile + README
📎 Notes
Household feature removed (household ID stored only as a simple integer field).

No file handling added yet — optional future upgrade.

Code kept modular and compatible with GCC.