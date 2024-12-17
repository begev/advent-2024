#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int comp(const void *a, const void *b) {


    int int_a, int_b;

    int_a = *(int *)a;
    int_b = *(int *)b;

    return (int_a > int_b) - (int_a < int_b);

}


int main(void) {

    int *array1, *array2;

    FILE *input;

    char row[100];
    char numchar1[6], numchar2[6];

    int i, j, row_index;

    int sum;


    /*Input file has 1000 rows*/
    array1 = malloc(sizeof(int) * 1000);
    array2 = malloc(sizeof(int) * 1000);

    input = fopen("input.txt", "r");

    row_index = 0;
    while(fgets(row, 14, input)) {

        /*Skip wrongly formatted lines*/
        if (strlen(row) < 13) continue;

        for (i = 0; i < 5; i++) {
            numchar1[i] = row[i];
            numchar2[i] = row[8+i];

        }

        array1[row_index] = atoi(numchar1);
        array2[row_index] = atoi(numchar2);
        row_index++;

    }

    fclose(input);

    qsort(array1, 1000, sizeof(int), comp);
    qsort(array2, 1000, sizeof(int), comp);

    sum = 0;
    for (i = 0; i < 1000; i++) {

        for (j = 0; j < 1000; j++) {

            if (array1[i] < array2[j]) break;

            if (array1[i] == array2[j]) {
                sum += array1[i];
            }
        }
    }

    printf("%d\n", sum);

}
