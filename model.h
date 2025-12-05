#ifndef MODEL_H
#define MODEL_H

typedef struct Citizen
{
    int citizen_id;
    char name[50];
    int age;
    char gender; // single character M/F/O
    char occupation[50];
    int income;

    int household_id; // not used, but stored

    // for displaying origin
    char district_name[50];
    char state_name[50];

    struct Citizen *next;
} Citizen;

typedef struct District
{
    char name[50];
    Citizen *citizens; // linked list of citizens
    struct District *next;
} District;

typedef struct State
{
    char name[50];
    District *districts; // linked list of districts
    struct State *next;
} State;

typedef struct Country
{
    char name[50];
    State *states;
} Country;

typedef struct BST_NODE
{
    int citizen_id;
    struct BST_NODE *left;
    struct BST_NODE *right;
    Citizen *citizen_ptr;
} BST_NODE;

#endif
