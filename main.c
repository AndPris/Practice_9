#include <stdio.h>
#include <string.h>
#include "myfuncs.h"

char signature[] = "Signature";

typedef struct {
    char area[50];
    float square;
    float cit;
} record;

void getName (char fpath[]) {
    char fname[25];
    strcat(fpath, "D:\\University\\programming\\GitHub\\Practice_9\\");
    printf("Enter the name of the file (max 20 characters):");
    fgets(fname, 20, stdin);
    fflush(stdin);
    strtok(fname, "\n");        // delete \n character in the end
    strcat(fname, ".myf");
    strcat(fpath, fname);
}

void createFile(FILE *fptr) {
    char fpath[255];
    getName(fpath);

   if((fptr = fopen(fpath, "rb")) != NULL) {
        printf("This file exists\n");
       fclose(fptr);
   } else {
       fclose(fptr);
       if ((fptr = fopen(fpath, "w+b")) == NULL) {
           printf("Can't create file\n");
       }
       fwrite(signature, sizeof(signature), 1, fptr);
       printf("File is created successfully\n");
       fclose(fptr);
   }
}

void deleteFile() {
    char fpath[255];
    getName(fpath);

    FILE *fptr;
    if((fptr = fopen(fpath, "rb")) == NULL) {
        printf("This file doesn't exists\n");
        fclose(fptr);
    } else {
        fclose(fptr);
        if ((remove(fpath)) == 0) {
            printf("The file is deleted successfully\n");
        } else {
            printf("The file is not deleted\n");
        }
    }
}

int main() {
    short choice;
    FILE *fptr;

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

        printf("Make your choice (Enter the number 1-9):");
        choose(&choice, 1, 9);
        switch (choice) {
            case 1:
                createFile(&fptr);
                printf("Press any key to continue\n");
                getchar();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                deleteFile();
                printf("Press any key to continue\n");
                getchar();
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
        }
    } while (choice != 9);
    return 0;
}
