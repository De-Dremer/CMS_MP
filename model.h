#ifndef MODEL_H
#define MODEL_H

typedef struct Citizen
{
    int citizen_id;
    char name[50];
    int age;
    char gender;
    char occupation[50];
    int income;

    int household_id;

    char district_name[50];
    char state_name[50];

    struct Citizen *next;
} Citizen;

typedef struct District
{
    char name[50];
    Citizen *citizens;
    struct District *next;
} District;

typedef struct State
{
    char name[50];
    District *districts;
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

State *get_state(Country *country, char *state_name);
District *get_district(State *state, const char *district_name);

Citizen *add_citizen(State *state, District *district,
                     int id, char *name, int age,
                     char gender, int sal, char *occ);

BST_NODE *getnode();
BST_NODE *bst_insert(BST_NODE *root, Citizen *cit);
BST_NODE *bst_search(BST_NODE *root, int id);

#endif
