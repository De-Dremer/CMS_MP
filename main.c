#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"

// global BST root
BST_NODE *bst_root = NULL;

int main()
{
    // Allocate and initialize country
    Country country;
    strcpy(country.name, "INDIA");
    country.states = NULL;

    int ch;

    for (;;)
    {
        printf("\n===== CENSUS MANAGEMENT SYSTEM =====\n");
        printf("1. Enter Details\n");
        printf("2. Search & Display by Citizen ID\n");
        printf("3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            printf("\n=== ADD COMPLETE ENTRY ===\n");

            /* STEP 1: ENTER STATE */
            char state_name[3];
            printf("Enter State Code (2 letters): ");
            scanf("%s", state_name);

            State *s = get_state(country, state_name);

            /* STEP 2: ENTER DISTRICT */
            int district_id;
            char district_name[50];

            printf("Enter District ID: ");
            scanf("%d", &district_id);
            printf("Enter District Name: ");
            scanf("%s", district_name);

            District *d = get_district(s, district_name);

            /* STEP 3: ENTER CITIZEN DETAILS */
            int citizen_id;
            char citizen_name[50];
            int age, income;
            char occupation[50];
            char gender;

            printf("Enter Citizen ID: ");
            scanf("%d", &citizen_id);

            printf("Enter Citizen Name: ");
            scanf("%s", citizen_name);

            printf("Enter Age: ");
            scanf("%d", &age);

            printf("Enter Gender (M/F/O): ");
            scanf(" %c", &gender);

            printf("Enter Occupation: ");
            scanf("%s", occupation);

            printf("Enter Income: ");
            scanf("%d", &income);

            /* STEP 4: ADD CITIZEN */
            Citizen *c = add_citizen(
                s,
                d,
                citizen_id,
                citizen_name,
                age,
                gender,
                income,
                occupation);

            if (c)
            {
                printf("✓ Citizen Added Successfully!\n");

                /* STEP 5: INSERT INTO BST */
                bst_root = bst_insert(bst_root, c);
            }

            break;
        }

        case 2:
        {
            int cid;
            printf("Enter Citizen ID to search: ");
            scanf("%d", &cid);

            Citizen *res = bst_search(bst_root, cid);

            if (res)
                printf("FOUND: %s (Age %d)\n", res->name, res->age);
            else
                printf("Not Found.\n");

            break;
        }

        case 3:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }
}
