#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    int safe_rows, is_safe;
    
    char row[30]; 
    char *row_num;

    FILE *input;
    int current, previous, is_growing, diff;
    

    input = fopen("input.txt", "r");


    
    safe_rows = 0;

    while (fgets(row, sizeof(row), input) != NULL ) {

        previous = -1;
        current = -1;
        is_growing = -1;
        is_safe = 1;
        
        row_num = strtok(row, " \n");
        while(row_num) {

           current = atoi(row_num);
            

            
            if (previous != -1) {
                diff = current-previous;
                if (is_growing == -1) {

                    if (diff < 0 && diff >= -3) is_growing = 0;
                    else if (diff > 0 && diff <= 3) is_growing = 1;
                    else {
                        printf("UNSAFE");
                        is_safe = 0;
                        break;
                    }
                    
                }

                else if (is_growing) {
                    
                    if (diff <= 0 || diff > 3) {
                        printf("UNSAFE (%d), is_growing = %d",current, is_growing);
                        is_safe = 0;
                        break;
                    } 

                }
                else if (is_growing == 0) {

                    if (diff >= 0 || diff < -3) {
                        printf("UNSAFE (%d), is_growing = %d",current, is_growing);
                        is_safe = 0;
                        break;
                    } 
                }

            }


            printf("%d ", current);
  

            previous = current;
            row_num = strtok(NULL, " \n");
            
        }
        printf("\n");

        if(is_safe) safe_rows++;

    }

    

    fclose(input);

    printf("\nTotal safe reports: %d\n", safe_rows);
    

}