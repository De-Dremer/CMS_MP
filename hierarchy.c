#include "model.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    //printf("New state created: %s\n", state_name);
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

    //printf("New district created: %s\n", district_name);
    return d;
}

Citizen *add_citizen(State *state, District *district,
                     int id, char *name, int age,
                     char gender, int sal, char *occ)
{
    Citizen *temp = district->citizens;

    while (temp != NULL)
    {
        if (temp->citizen_id == id)
        {
            printf(" Citizen ID %d already exists! Duplicate not allowed.\n", id);
            return NULL;
        }
        temp = temp->next;
    }

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

    strcpy(c->district_name, district->name);
    strcpy(c->state_name, state->name);

    c->next = district->citizens;
    district->citizens = c;

    printf("Citizen added: %s (ID: %d)\n", name, id);
    return c;
}

/*Memory deallocation*/
/* free citizens, districts and states */
void free_hierarchy(Country *country)
{
    State *s = country->states, *s_tmp;
    District *d, *d_tmp;
    Citizen *c, *c_tmp;

    while (s)
    {
        d = s->districts;
        while (d)
        {
            c = d->citizens;
            while (c)
            {
                c_tmp = c->next;
                free(c);
                c = c_tmp;
            }
            d_tmp = d->next;
            free(d);
            d = d_tmp;
        }
        s_tmp = s->next;
        free(s);
        s = s_tmp;
    }
}

/* free BST nodes */
void free_bst(BST_NODE *root)
{
    if (!root)
        return;

    free_bst(root->left);
    free_bst(root->right);
    free(root);
}

/* call other 2 functions */
void free_all(Country *country, BST_NODE *root)
{
    free_hierarchy(country);
    free_bst(root);
}
