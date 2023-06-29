#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    FILE *record_file = fopen("record.txt", "r"); // opening save file to read last record
    int last_record;
    fscanf(record_file, "%d", &last_record);

    srand(time(0)); // changing the rand() seed for every game

    printf("I picked a number between 0-100. Try to guess it! Higest Score: %d\n", last_record);
    fclose(record_file);

    int picked_num = rand() % 100; // maniplating rand() to get the number between 0-100
    int guess = -1; // initial temporary guess
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
                FILE *record_file = fopen("record.txt", "w"); // opening save file to update/create(for first play) the record 
                fprintf(record_file, "%d", guess_count);
                fclose(record_file);
            }
            
            return EXIT_SUCCESS;
        }
    }
    
    return EXIT_SUCCESS;
}
