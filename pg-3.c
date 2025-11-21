#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int tph, philname[20], status[20], howhung, hu[20], cho;

void one();
void two();

int main()
{
    int i;
    printf("\nDINING PHILOSOPHER PROBLEM");

    printf("\nEnter the total number of philosophers: ");
    scanf("%d", &tph);

    for(i = 0; i < tph; i++)
    {
        philname[i] = i + 1;
        status[i] = 1;
    }

    printf("How many are hungry: ");
    scanf("%d", &howhung);

    if(howhung == tph)
    {
        printf("\nAll are hungry.. Deadlock will occur!");
        printf("\nExiting...\n");
        exit(0);
    }
    else
    {
        for(i = 0; i < howhung; i++)
        {
            printf("Enter philosopher %d position (0 to %d): ", i + 1, tph - 1);
            scanf("%d", &hu[i]);
            status[hu[i]] = 2;
        }
    }

    do
    {
        printf("\n\n1. One can eat at a time");
        printf("\n2. Two can eat at a time");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &cho);

        switch(cho)
        {
            case 1:
                one();
                break;

            case 2:
                two();
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid option...");
        }

    } while(1);

    return 0;
}

void one()
{
    int pos = 0, x, i;
    printf("\nAllow one philosopher to eat at any time\n");

    for(i = 0; i < howhung; i++, pos++)
    {
        printf("\nP%d is granted to eat", philname[hu[pos]]);
        for(x = pos + 1; x < howhung; x++)
        {
            printf("\nP%d is waiting", philname[hu[x]]);
        }
        printf("\n");
    }
}

void two()
{
    int i, j, s = 0, t, r, x;

    printf("\nAllow two philosophers to eat at the same time\n");

    for(i = 0; i < howhung; i++)
    {
        for(j = i + 1; j < howhung; j++)
        {
            if(abs(hu[i] - hu[j]) >= 1 && abs(hu[i] - hu[j]) != tph - 1)
            {
                printf("\n\nCombination %d\n", (s + 1));

                t = hu[i];
                r = hu[j];
                s++;

                printf("P%d and P%d are granted to eat",
                       philname[t], philname[r]);

                for(x = 0; x < howhung; x++)
                {
                    if(hu[x] != t && hu[x] != r)
                        printf("\nP%d is waiting", philname[hu[x]]);
                }
            }
        }
    }
}
