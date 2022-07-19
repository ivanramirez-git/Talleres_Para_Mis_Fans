// Problem A Acquapia
// Language: C
#include <stdio.h>
#include <string.h>
#define INFINITY 9999999

// argumentos del main
int main(int argc, char *argv[])
{

    if (strcmp(argv[1], "-V") == 0 || strcmp(argv[1], "-v") == 0)
    {
        // cat file
        FILE *fp;
        fp = fopen("input.txt", "r");
        char line[100];
        if (fp == NULL)
        {
            printf("Error al abrir el archivo\n");
            return 1;
        }
        while (fgets(line, 100, fp) != NULL)
        {
            printf("%s", line);
        }
        fclose(fp);
    }

    char result[255] = "";
    while (1)
    {
        // indices
        int i, j, k;

        // inputs
        int c; // 2 <= c <= 10^3, cities
        scanf("%d", &c);
        int r; // 1 <= r <= c/2, rivers
        scanf("%d", &r);
        int s; // 1 <= s <= c-1, river sections
        scanf("%d", &s);
        int q; // 1 <= q <= 10^5, queries
        scanf("%d", &q);

        // zeros
        if (!c && !r && !s && !q)
        {
            printf("%s", result);
            // print in output.txt
            FILE *fp;
            fp = fopen("output.txt", "w");
            fprintf(fp, "%s", result);
            fclose(fp);
            return 0;
        }

        int typeError = 0;

        // check if c is valid
        if (c < 2 || c > 1000)
            typeError = 1;
        // check if r is valid
        if (r < 1 || r > c / 2)
            typeError = 1;
        // check if s is valid
        if (s < 1 || s > c - 1)
            typeError = 1;
        // check if q is valid
        if (q < 1 || q > 100000)
            typeError = 1;
        if (typeError)
        {
            printf("Error in input\n");
            return 0;
        }

        // read cities where rivers start
        int cities[r];
        for (i = 0; i < r; i++)
        {
            scanf("%d", &cities[i]);
            if (cities[i] < 1 || cities[i] > c)
            {
                printf("Error in input\n");
                return 0;
            }
        }

        // read river sections
        int riverSections[s][2];
        for (i = 0; i < s; i++)
        {
            scanf("%d %d", &riverSections[i][0], &riverSections[i][1]);
            if (riverSections[i][0] < 1 || riverSections[i][0] > c)
            {
                printf("Error in input\n");
                return 0;
            }
            if (riverSections[i][1] < 1 || riverSections[i][1] > c)
            {
                printf("Error in input\n");
                return 0;
            }
        }

        // read queries
        int queries[q][2];
        for (i = 0; i < q; i++)
        {
            scanf("%d %d", &queries[i][0], &queries[i][1]);
            if (queries[i][0] < 1 || queries[i][0] > c)
            {
                printf("Error in input\n");
                return 0;
            }
            if (queries[i][1] < 1 || queries[i][1] > c)
            {
                printf("Error in input\n");
                return 0;
            }
        }

        // outputs

        // adjacency matrices
        int adj[c][c];

        // initialize adjacency matrices in -1
        for (i = 0; i < c; i++)
        {
            for (j = 0; j < c; j++)
            {
                adj[i][j] = 0;
            }
        }

        // fill adjacency matrices with stream changes
        for (i = 0; i < s; i++)
        {
            adj[riverSections[i][0] - 1][riverSections[i][1] - 1] = 1;
            adj[riverSections[i][1] - 1][riverSections[i][0] - 1] = 100;
        }

        // matrix transitive closure
        int transitiveClosure[c][c];
        for (i = 0; i < c; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (adj[i][j] == 0)
                {
                    transitiveClosure[i][j] = 0;
                }
                else
                {
                    transitiveClosure[i][j] = 1;
                }
            }
        }

        // matrix of minimum paths
        int minPaths[c][c];
        int recorridos[c][c];
        for (i = 0; i < c; i++)
        {
            for (j = 0; j < c; j++)
            {
                recorridos[i][j] = j;
                if (i == j)
                {
                    minPaths[i][j] = 0;
                    recorridos[i][j] = -1;
                }
                else if (adj[i][j] == 0)
                {
                    minPaths[i][j] = INFINITY;
                }
                else
                {
                    minPaths[i][j] = adj[i][j];
                }
            }
        }

        // n^3; n = c
        for (i = 0; i < c; i++)
        {
            for (i = 0; i < c; i++)
            {
                for (j = 0; j < c; j++)
                {

                    if (minPaths[i][j] > minPaths[i][k] + minPaths[k][j])
                    {
                        minPaths[i][j] = minPaths[i][k] + minPaths[k][j]; // matrix of minimum paths
                        recorridos[i][j] = recorridos[i][k];              // matrix of recorridos
                    }
                    if (transitiveClosure[i][j] == 0)
                    {
                        transitiveClosure[i][j] = transitiveClosure[i][k] * transitiveClosure[k][j]; // matrix of transitive closure
                    }
                }
            }
        }

        // print queries
        strcat(result, "\n");

        // for each query
        for (i = 0; i < q; i++)
        {
            // city stream change
            int city = 0;
            // if city is not connected to another city, print -1
            if (transitiveClosure[queries[i][0] - 1][queries[i][1] - 1] == 0)
            {
                strcat(result, "-1\n");
            }
            else
            {
                if (minPaths[queries[i][0] - 1][queries[i][1] - 1] == INFINITY)
                {
                    // if city is not connected to another city, print -1
                    strcat(result, "-1\n");
                }
                else
                {
                    // if city is connected to another city, validate if another city is between the two cities
                    if (1 + recorridos[queries[i][0] - 1][queries[i][1] - 1] == queries[i][1] || 1 + recorridos[queries[i][0] - 1][queries[i][1] - 1] == queries[i][0])
                    {
                        strcat(result, "0\n");
                    }
                    else
                    {
                        //
                        int printer = 1 + recorridos[queries[i][0] - 1][queries[i][1] - 1];
                        int count = 0;

                        for (k = 0; k < s; k++)
                        {
                            if (riverSections[k][1] == queries[i][0] || riverSections[k][1] == queries[i][1])
                            {
                                count++;
                            }
                        }
                        if (count == 2)
                        {
                            if (minPaths[queries[i][0] - 1][queries[i][1] - 1] % 2 != 0)
                            {
                                char aux[10] = "";
                                sprintf(aux, "%d", printer);
                                strcat(aux, "\n");
                                strcat(result, aux);
                            }
                            else
                            {
                                strcat(result, "0\n");
                            }
                        }
                        else
                        {
                            strcat(result, "0\n");
                        }
                    }
                }
            }
        }
    }
}