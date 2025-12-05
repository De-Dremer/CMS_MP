#include "model.h"
#include <stdlib.h>
State *get_state(Country *country, char *state_name)
{
    State *temp = country->states;

    while (temp != NULL)
    {
        if (strcmp(temp->name, state_name) == 0)
            return temp;
        temp = temp->next;
    }

    State *s = (State *)malloc(sizeof(State));
    strcpy(s->name, state_name);
    s->districts = NULL;
    s->next = country->states;
    country->states = s;

    printf("New state created: %s\n", state_name);
    return s;
}

District *get_district(State *state, const char *district_name)
{
    District *temp = state->districts;

    while (temp != NULL)
    {
        if (strcmp(temp->name, district_name) == 0)
            return temp;
        temp = temp->next;
    }

    District *d = (District *)malloc(sizeof(District));
    strcpy(d->name, district_name);
    d->citizens = NULL;
    d->next = state->districts;
    state->districts = d;

    printf("New district created: %s\n", district_name);
    return d;
}

Citizen *add_citizen(State *state, District *district,
                     int id, char *name, int age,
                     char gender, int sal, char *occ)
{
    // Check duplicate citizen ID
    Citizen *temp = district->citizens;
    while (temp != NULL)
    {
        if (temp->citizen_id == id)
        {
            printf("❌ Citizen ID %d already exists! Duplicate not allowed.\n", id);
            return NULL;
        }
        temp = temp->next;
    }

    // Create new citizen
    Citizen *c = (Citizen *)malloc(sizeof(Citizen));
    if (!c)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    c->citizen_id = id;
    strcpy(c->name, name);
    c->age = age;
    c->gender = gender;
    strcpy(c->occupation, occ);
    c->income = sal;

    // store origin
    strcpy(c->district_name, district->name);
    strcpy(c->state_name, state->name);

    // insert in district list
    c->next = district->citizens;
    district->citizens = c;

    printf("✔ Citizen added: %s (ID: %d)\n", name, id);
    return c;
}

BST_NODE *getnode()
{
    BST_NODE *temp = (BST_NODE *)malloc(sizeof(BST_NODE));
    if (temp == NULL)
    {
        printf("No memory\n");
        return;
    }
    return temp;
}

BST_NODE *bst_insert(BST_NODE *root, int cit_id)
{
    BST_NODE *pre = NULL;
    BST_NODE *cur = NULL;
    BST_NODE *new = getnode();
    new->citizen_id = cit_id;
    new->left = new->right = NULL;
    if (root == NULL)
        return new;

    cur = root;
    while (cur != NULL)
    {
        pre = cur;
        if (new->citizen_id < cur->citizen_id)
        {
            cur = cur->left;
        }
        else if (new->citizen_id > cur->citizen_id)
        {
            cur = cur->right;
        }
    }
    if (new->citizen_id < pre->citizen_id)
    {
        pre->left = new;
    }
    else
    {
        pre->right = new;
    }
    return root;
}

BST_NODE *bst_search(BST_NODE *root, int id)
{
    if (root == NULL)
        return NULL;
    if (id == root->citizen_id)
        return root;
    if (id < root->citizen_id)
        return bst_search(root->left, id);
    else
    {
        return bst_search(root->right, id);
    }
}