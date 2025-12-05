#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"

BST_NODE *bst_root = NULL;

int main()
{
    Country country;
    strcpy(country.name, "INDIA");
    country.states = NULL;

    int ch;

    while (1)
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
            char state_name[3];
            printf("Enter State Code (2 letters): ");
            scanf("%s", state_name);

            State *s = get_state(&country, state_name);

            int district_id;
            char district_name[50];

            printf("Enter District ID: ");
            scanf("%d", &district_id);
            printf("Enter District Name: ");
            scanf("%s", district_name);

            District *d = get_district(s, district_name);

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
                printf("Citizen Added Successfully!\n");
                bst_root = bst_insert(bst_root, c);
            }
            break;
        }

        case 2:
        {
            int cid;
            printf("Enter Citizen ID to search: ");
            scanf("%d", &cid);

            BST_NODE *node = bst_search(bst_root, cid);

            if (node)
            {
                printf("\n--- CITIZEN FOUND ---\n");
                printf("Name     : %s\n", node->citizen_ptr->name);
                printf("Age      : %d\n", node->citizen_ptr->age);
                printf("Gender   : %c\n", node->citizen_ptr->gender);
                printf("State    : %s\n", node->citizen_ptr->state_name);
                printf("District : %s\n", node->citizen_ptr->district_name);
            }
            else
            {
                printf("Not Found.\n");
            }
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
