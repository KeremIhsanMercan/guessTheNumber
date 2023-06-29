#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    FILE *record_file = fopen("record.txt", "r");
    int last_record;
    fscanf(record_file, "%d", &last_record);

    srand(time(0));

    printf("I picked a number between 0-100. Try to guess it! Higest Score: %d\n", last_record);
    fclose(record_file);

    int picked_num = rand() % 100;
    int guess = 212;
    int guess_count = 0;

    while (guess != picked_num)
    {
        scanf("%d", &guess);

        if (guess > picked_num)
        {
            printf("Try to go lower\n");
            guess_count++;
        } else if (guess < picked_num) {
            printf("Try to go above\n");
            guess_count++;
        } else {
            printf("You got it in %d tries!\n", guess_count);

            if (guess_count < last_record)
            {
                printf("NEW RECORD");
                FILE *record_file = fopen("record.txt", "w");
                fprintf(record_file, "%d", guess_count);
                fclose(record_file);
            }
            
            return EXIT_SUCCESS;
        }

         
    }
    



    return EXIT_SUCCESS;
}