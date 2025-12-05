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
    char st_name[3];

    struct Citizen* next;
} Citizen;



typedef struct District {
    int district_id;
    char name[50];
    int population;

    char st_name[3];

    struct District* next;
    Citizen* var;
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