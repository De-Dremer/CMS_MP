#include "model.h"
State* get_state(Country* country,char* state_name) {
    State* temp = country->states;

    while (temp != NULL) {
        if (strcmp(temp->name, state_name) == 0)
            return temp;
        temp = temp->next;
    }
    State* s = (State*)malloc(sizeof(State));
    strcpy(s->name, state_name);
    s->districts = NULL;
    s->next = country->states;
    country->states = s;

    printf("New state created: %s\n", state_name);
    return s;
}
District* get_district(State* state, const char* district_name) {
    District* temp = state->districts;
    while (temp != NULL) {
        if (strcmp(temp->name, district_name) == 0)
            return temp;
        temp = temp->next;
    }
    District* d = (District*)malloc(sizeof(District));
    strcpy(d->name, district_name);
    d->citizens = NULL;
    d->next = state->districts;
    state->districts = d;
    printf("New district created: %s\n", district_name);
    return d;
}
Citizen* add_citizen(State *state,District* district,
                     int id,
                     char* name,
                     int age,
                     char gender,int sal,char occ)
{
    
    Citizen* temp = district->citizens;
    while (temp != NULL) {
        if (strcmp(temp->id, id) == 0) {
            printf("❌ Citizen ID '%s' already exists! Duplicate not allowed.\n", id);
            return NULL;   
        }
        temp = temp->next;
    }
    Citizen* c = (Citizen*)malloc(sizeof(Citizen));
    if (!c) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(c->citizen_id, id);
    strcpy(c->name, name);
    c->age = age;
    strcpy(c->gender, gender);
    c->income=sal;
    c->occ=occ;
    strcpy(c->dist_name=district);
    strcpy(c->st_name=state);
    printf("✔ Citizen added: %s (ID: %s)\n", name, id);

    return c;
}

