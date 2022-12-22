#include <stdio.h>
#include "myfuncs.h"

typedef struct {
    char area[50];
    float square;
    float cit;
} record;

int main() {
    short choice;

    do {
        printf("----MENU----\n");
        printf("\t1 -> Create file\n");
        printf("\t2 -> Open existed file and read its data\n");
        printf("\t3 -> Make a record to a file\n");
        printf("\t4 -> Delete records from the file\n");
        printf("\t5 -> Delete file\n");
        printf("\t6 -> Edit records in a file\n");
        printf("\t7 -> Sort records in a file\n");
        printf("\t8 -> Insert sorted record into a file\n");
        printf("\t9 -> Close the program\n");

        printf("Make your choice (Enter the number 1-9): ");
        choose(&choice, 1, 9);
    } while (choice != 9);
    return 0;
}
