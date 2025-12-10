<h1>CENSUS MANAGEMENT AND POPULATION ANALYTICS</h1>
Mini Project – C Program  

___


<h2>Overview</h2>
This project is a C-based census management system that organizes population data in a hierarchical structure: 

```
Country → State → District → Citizen
```

The system uses:  
- **Structures + Linked Lists** for hierarchical data  
- **Binary Search Tree (BST)** for fast citizen lookup  
- **Menu-driven console interface**  
___

<h2>Features Implemented</h2>
- Add complete entry (State → District → Citizen)  
- Automatically create State/District if they don’t exist  
- Insert citizen into District linked list  
- Insert citizen ID into BST for fast searching  
- Search citizen by ID  
- Display all citizen details  
- Basic input validations (no duplicate IDs)  

___
<h2>Project Structure</h2>

census_project/

├── model.h 

├── hierarchy.c 

├── search.c 

├── main.c 

├── tree_fun.c 

└── README.md 

___

<h2>How to Compile and Run</h2>

Makefile
```bash
gcc main.c hierarchy.c stats.c tree_fun.c -o census
./census
```
___

<h2>Test Cases and Menu Actions</h2>

| Test No. | Menu / Action                         | Description / Expected Behavior                        |
|:--------:|:------------------------------------:|:------------------------------------------------------:|
| 1        | Enter Details                         | Add new State, District, and Citizen entry            |
| 2        | Add multiple citizens across states/districts | Add multiple citizens in different states/districts |
| 3        | Add a citizen with duplicate ID       | Should show an error (duplicate ID not allowed)       |
| 4        | Search an existing citizen            | Verify BST search returns correct citizen details     |
| 5        | Search a non-existing citizen         | Should indicate citizen not found                     |
| 6        | Search & Display by Citizen ID        | Search for any citizen by ID and display full details |
| 7        | Generate Report                        | Generate a population / census report                 |
| 8        | Add 20+ entries                        | Stress-test BST and data structure performance       |
| 9        | Exit                                   | Exit the program                                      |




