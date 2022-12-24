#include <stdio.h>
#include <string.h>
#include "myfuncs.h"

typedef struct {
    char area[50];
    float square;
    int population;
} record;

void getName (char fpath[]) {
    char fname[25];
    strcat(fpath, "D:\\University\\programming\\GitHub\\Practice_9\\");
    printf("Enter the name of the file (max 20 characters):");
    fgets(fname, 21, stdin);
    fflush(stdin);
    strtok(fname, "\n");        // delete \n character in the end
    strcat(fname, ".myf");
    strcat(fpath, fname);
}

void createFile() {
    char fpath[255];
    FILE *fptr;
    getName(fpath);

   if((fptr = fopen(fpath, "rb")) != NULL) {
        printf("This file exists\n");
   } else {
       if ((fptr = fopen(fpath, "wb")) == NULL) {
           printf("Can't create file\n");
       } else {
           printf("File is created successfully\n");
       }
   }
    fclose(fptr);
}

void readFile() {
    char fpath[255];
    FILE *fptr;
    getName(fpath);

    if((fptr = fopen(fpath, "rb")) == NULL) {
        printf("\nThis file doesn't exists or you don't have an access to it\n");
    } else {
        fseek(fptr, 0, SEEK_END);
        if((ftell(fptr)) == 0) {
            printf("This file is empty\n");
        } else {
            record data;
            fseek(fptr, 0, SEEK_SET);
            while((fread(&data, sizeof(record), 1, fptr)) != 0) {
                printf("Area:%sSquare:%g\nPopulation:%d\n\n", data.area, data.square, data.population);
            }
        }
    }

    fclose(fptr);
}

void makeRecord() {
    char fpath[255];
    FILE *fptr;
    getName(fpath);

    if((fptr = fopen(fpath, "rb")) == NULL) {
        printf("\nThis file doesn't exists or you don't have an access to it\n");
    } else {
        fclose(fptr);
        if ((fptr = fopen(fpath, "ab")) == NULL) {
            printf("Can't open file\n");
        } else {
            record rec;

            printf("\nEnter the name of the area(max 50 characters):");
            fgets(rec.area, 51, stdin);
            fflush(stdin);
            printf("\nEnter the square of the area:");
            floatInput(&rec.square);
            printf("\nEnter the population of the area:");
            intInput(&rec.population);

            if ((fwrite(&rec, sizeof(record), 1, fptr)) != 0) {
                printf("\nThe record is added successfully\n");
            } else {
                printf("\nError adding the record\n");
            }
        }

    }

    fclose(fptr);
}

void deleteFile() {
    char fpath[255];
    FILE *fptr;
    getName(fpath);

    if((fptr = fopen(fpath, "rb")) == NULL) {
        printf("\nThis file doesn't exists or you don't have an access to it\n");
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

    do {
        printf("\t----MENU----\n");
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
                createFile();
                printf("Press any key to continue\n");
                getchar();
                break;
            case 2:
                readFile();
                printf("Press any key to continue\n");
                getchar();
                break;
            case 3:
                makeRecord();
                printf("Press any key to continue\n");
                getchar();
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
