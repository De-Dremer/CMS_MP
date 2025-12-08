#include <stdio.h>
#include "model.h"

ReportStats generate_report(Country *country)
{
    ReportStats r;

    r.total = 0;

    r.children_count = 0;
    r.adult_count = 0;
    r.senior_count = 0;

    int percent_children = 0;
    int percent_adults = 0;
    int percent_seniors = 0;

    State *s = country->states;

    while (s != NULL)
    {
        District *d = s->districts;

        while (d != NULL)
        {
            Citizen *c = d->citizens;

            while (c != NULL)
            {
                int age = c->age;

                /* ====================== */
                /*  OFFICIAL COUNT LOGIC  */
                

                if (age < 18)
                    r.children_count++;

                else if (age >= 18 && age <= 35)
                    r.adult_count++;

                else if (age >= 50)
                    r.senior_count++;

                /* Ignored ages 36–49 for COUNT */

                /* =========================== */
                /*  PERCENTAGE LOGIC (100%)    */
                

                if (age < 18)
                    percent_children++;

                else if (age >= 18 && age <= 45)
                    percent_adults++;

                else if (age > 45)
                    percent_seniors++;

                r.total++;

                c = c->next;
            }

            d = d->next;
        }

        s = s->next;
    }

    /* ========================= */
    /*  PERCENTAGE CALCULATION   */
    

    if (r.total == 0)
    {
        r.children_percent = 0;
        r.adult_percent = 0;
        r.senior_percent = 0;
    }
    else
    {
        r.children_percent = (percent_children * 100.0f) / r.total;
        r.adult_percent = (percent_adults * 100.0f) / r.total;
        r.senior_percent = (percent_seniors * 100.0f) / r.total;
    }

    return r;
}
