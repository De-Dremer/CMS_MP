#ifndef MODEL_H
#define MODEL_H


typedef struct Citizen {
    int citizen_id;
    char name[50];
    int age;
    char gender[1];
    char occupation[50];
    int income;

    int household_id;
    int district_id;
    int state_id;

    struct Citizen* next;
} Citizen;


typedef struct Household {
    int household_id;
    char address[100];
    int num_members;

    int district_id;
    int state_id;

    struct Household* next;
    Citizen* citizen_var;   
} Household;

typedef struct District {
    int district_id;
    char name[50];
    int population;

    int state_id;

    struct District* next;
    Household* household_var;
} District;

typedef struct State {

    char name[2];
    int population;

    struct State* next;
    District* district_var;
} State;

typedef struct Country {
    State* state_var;
    char name[10];
} Country;


typedef struct BST_NODE
{
    int citizen_id;
    struct BST_NODE *left;
    struct BST_NODE *right;
    Citizen* citizen_ptr;
}BST_NODE;


#endif