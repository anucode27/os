#include <stdio.h>
#include <conio.h>

#define MAX 25

void main()
{
    int frag[MAX], b[MAX], f[MAX];
    int bf[MAX], ff[MAX];
    int i, j, nb, nf, temp;
    int lowest = 10000;

    clrscr();

    printf("\nMEMORY MANAGEMENT SCHEME - BEST FIT\n");

    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
        bf[i] = 0;   // block is free
    }

    printf("\nEnter the size of the files:\n");
    for (i = 1; i <= nf; i++)
    {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
        ff[i] = 0;
    }

    /* Best Fit Allocation */
    for (i = 1; i <= nf; i++)
    {
        lowest = 10000;
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] == 0)
            {
                temp = b[j] - f[i];
                if (temp >= 0 && temp < lowest)
                {
                    ff[i] = j;
                    lowest = temp;
                }
            }
        }

        if (ff[i] != 0)
        {
            frag[i] = lowest;
            bf[ff[i]] = 1;
        }
    }

    /* Output */
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment");
    for (i = 1; i <= nf; i++)
    {
        if (ff[i] != 0)
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",
                   i, f[i], ff[i], b[ff[i]], frag[i]);
        else
            printf("\n%d\t\t%d\t\tNot Allocated", i, f[i]);
    }

    getch();
}
