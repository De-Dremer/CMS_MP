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
        printf("3. Generate Report\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            char state_name[10];
            printf("Enter State Code (2 letters): ");
            scanf("%s", state_name);
            while (getchar() != '\n')
                ;

            State *s = get_state(&country, state_name);

            int district_id;
            char district_name[50];

            printf("Enter District ID: ");
            scanf("%d", &district_id);
            while (getchar() != '\n')
                ;

            printf("Enter District Name: ");
            fgets(district_name, sizeof(district_name), stdin);
            district_name[strcspn(district_name, "\n")] = 0;

            District *d = get_district(s, district_name);

            int citizen_id;
            char citizen_name[50];
            int age, income;
            char occupation[50];
            char gender;

            printf("Enter Citizen ID: ");
            scanf("%d", &citizen_id);
            while (getchar() != '\n')
                ;

            printf("Enter Citizen Name: ");
            fgets(citizen_name, sizeof(citizen_name), stdin);
            citizen_name[strcspn(citizen_name, "\n")] = 0;

            printf("Enter Age: ");
            scanf("%d", &age);
            while (getchar() != '\n')
                ;

            printf("Enter Gender (M/F/O): ");
            scanf(" %c", &gender);
            while (getchar() != '\n')
                ;

            printf("Enter Occupation: ");
            fgets(occupation, sizeof(occupation), stdin);
            occupation[strcspn(occupation, "\n")] = 0;

            printf("Enter Income: ");
            scanf("%d", &income);
            while (getchar() != '\n')
                ;

            Citizen *c = add_citizen(
                s, d,
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

            if (node && node->citizen_ptr)
            {
                printf("\n--- CITIZEN FOUND ---\n");
                printf("%-12s: %s\n", "Name", node->citizen_ptr->name);
                printf("%-12s: %d\n", "Age", node->citizen_ptr->age);
                printf("%-12s: %c\n", "Gender", node->citizen_ptr->gender);
                printf("%-12s: %s\n", "State", node->citizen_ptr->state_name);
                printf("%-12s: %s\n", "District", node->citizen_ptr->district_name);
            }
            else
            {
                printf("Not Found.\n");
            }
            break;
        }

        case 3:
        {
            ReportStats rep = generate_report(&country);

            printf("\n===== CENSUS REPORT =====\n");
            printf("%-25s: %d\n", "Total Citizens", rep.total);

            printf("\n--- COUNT SECTION ---\n");
            printf("%-25s: %d\n", "Children Count (<18)", rep.children_count);
            printf("%-25s: %d\n", "Adult Count (18 - 35)", rep.adult_count);
            printf("%-25s: %d\n", "Senior Count (50+)", rep.senior_count);

            printf("\n--- PERCENTAGE SECTION ---\n");
            printf("%-35s: %.2f%%\n", "Children Percentage (<18)", rep.children_percent);
            printf("%-35s: %.2f%%\n", "Adult Percentage (18 - 35)", rep.adult_percent);
            printf("%-35s: %.2f%%\n", "Senior Percentage (>45)", rep.senior_percent);

            break;
        }

        case 4:
            printf("Freeing memory\n");
            free_all(&country, bst_root);
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }
}
