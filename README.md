**CENSUS MANAGEMENT AND POPULATION ANALYTICS**  
Mini Project – C Program  

___


**Overview**  
This project is a C-based census management system that organizes population data in a hierarchical structure:  
```
Country → State → District → Citizen
```

The system uses:  
- **Structures + Linked Lists** for hierarchical data  
- **Binary Search Tree (BST)** for fast citizen lookup  
- **Menu-driven console interface**  
___

**Features Implemented**  
- Add complete entry (State → District → Citizen)  
- Automatically create State/District if they don’t exist  
- Insert citizen into District linked list  
- Insert citizen ID into BST for fast searching  
- Search citizen by ID  
- Display all citizen details  
- Basic input validations (no duplicate IDs)  

___
**Project Structure**  
census_project/

├── model.h // Structure definitions

├── hierarchy.c // Linked list operations

├── search.c // BST functions

├── main.c // Menu + integration

├── Makefile // Build instructions

└── README.md // Documentation

___

**How to Compile and Run**
Makefile
```bash
gcc main.c hierarchy.c search.c -o census
./census
```
___


| Test No. | Menu / Action                         | Description / Expected Behavior                        |
|:--------:|:------------------------------------:|:------------------------------------------------------:|
| 1        | Enter Details                         | Add new State, District, and Citizen entry            |
| 2        | Search & Display by Citizen ID        | Search for a citizen using ID and display details     |
| 3        | Generate Report                        | Generate a population / census report                 |
| 4        | Exit                                   | Exit the program                                      |
| 5        | Add multiple citizens across states/districts | Add multiple citizens in different states/districts |
| 6        | Add a citizen with duplicate ID       | Should show an error (duplicate ID not allowed)       |
| 7        | Search an existing citizen            | Verify BST search returns correct citizen details     |
| 8        | Search a non-existing citizen         | Should indicate citizen not found                     |
| 9        | Add 20+ entries                        | Test BST performance and data structure handling     |



