#include <stdio.h>
#include <string.h>
#include "myfuncs.h"

typedef struct {
    int id;
    char area[51];
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
                printf("Id:%d\nArea:%sSquare:%g\nPopulation:%d\n\n", data.id, data.area, data.square, data.population);
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
            printf("\nEnter the id of the area:");
            intInput(&rec.id);
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

void deleteRecords() {
    char fpath[255];
    FILE *fptr;
    getName(fpath);

    if((fptr = fopen(fpath, "rb")) == NULL) {
        printf("\nThis file doesn't exists or you don't have an access to it\n");
    } else {
        short delete;
        printf("\nEnter 1 to delete one record or 2 to delete all the records:");
        choose(&delete, 1, 2);
        if(delete == 1) {
            FILE *fptr_temp;
            record edit;
            int tempId;
            short flag;
            printf("\nEnter the id of the record you'd like to delete:");
            intInput(&tempId);

            if ((fptr_temp = fopen("D:\\University\\programming\\GitHub\\Practice_9\\copy.bin", "w+b")) == NULL) {
                printf("Can't delete a record\n");
                fclose(fptr_temp);
                remove("D:\\University\\programming\\GitHub\\Practice_9\\copy.bin");
            } else {
                rewind(fptr);
                while ((fread(&edit, sizeof(record), 1, fptr)) != NULL) {
                    if (edit.id != tempId) {
                        fwrite(&edit, sizeof(record), 1, fptr_temp);
                    } else {
                        flag = 1;
                    }
                }

                if (!flag) {
                    printf("\nThere is no record with such id\n");
                    fclose(fptr_temp);
                    remove("D:\\University\\programming\\GitHub\\Practice_9\\copy.bin");
                } else {
                    fclose(fptr);
                    fptr = fopen(fpath, "wb");
                    rewind(fptr_temp);
                    rewind(fptr);
                    while ((fread(&edit, sizeof(record), 1, fptr_temp)) != NULL) {
                            fwrite(&edit, sizeof(record), 1, fptr);
                    }
                    fclose(fptr);
                    fclose(fptr_temp);
                    remove("D:\\University\\programming\\GitHub\\Practice_9\\copy.bin");
                    printf("\nThe record is deleted successfully\n");
                }
            }
        } else {
            fclose(fptr);
            if ((fptr = fopen(fpath, "wb")) == NULL) {
                printf("Can't delete records\n");
            } else {
                printf("\nThe records are deleted successfully\n");
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

void editRecord() {
    char fpath[255];
    FILE *fptr;
    getName(fpath);

    if((fptr = fopen(fpath, "r+b")) == NULL) {
        printf("\nThis file doesn't exists or you don't have an access to it\n");
    } else {
        record edit;
        int tempId;

        printf("\nEnter the id of the record you'd like to edit:");
        intInput(&tempId);

        while(edit.id != tempId && !feof(fptr)) {
            fread(&edit, sizeof(record), 1, fptr);
        }

        if(edit.id != tempId) {
            printf("\nThere is no record with such id\n");
        } else {
            short editChoice;
            do {
                printf("\t----EDITING MENU----\n");
                printf("\t1 -> Edit the id of the area:\n");
                printf("\t2 -> Edit the name of the area\n");
                printf("\t3 -> Edit the square of the area:\n");
                printf("\t4 -> Edit the population of the area:\n");
                printf("\t5 -> Stop editing\n");

                printf("Make your choice (Enter the number 1-5):");
                choose(&editChoice, 1, 5);
                if(editChoice != 5) {
                    switch (editChoice) {
                        case 1:
                            printf("\nEnter the new id:");
                            intInput(&edit.id);
                            printf("Press Enter to continue\n");
                            getchar();
                            break;
                        case 2:
                            printf("\nEnter the new name of the area (max 50 characters):");
                            fgets(edit.area, 51, stdin);
                            fflush(stdin);
                            printf("Press Enter to continue\n");
                            getchar();
                            break;
                        case 3:
                            printf("\nEnter the new square of the area:");
                            floatInput(&edit.square);
                            printf("Press Enter to continue\n");
                            getchar();
                            break;
                        case 4:
                            printf("\nEnter the new population of the area:");
                            intInput(&edit.population);
                            printf("Press Enter to continue\n");
                            getchar();
                            break;
                    }
                    fseek(fptr, -sizeof(record), SEEK_CUR);
                    fwrite(&edit, sizeof(record), 1, fptr);
                }
            } while(editChoice != 5);
        }
    }

    fclose(fptr);
}

void sortRecords() {

}

int main() {
    short menuChoice;

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
        choose(&menuChoice, 1, 9);
        switch (menuChoice) {
            case 1:
                createFile();
                printf("Press Enter to continue\n");
                getchar();
                break;
            case 2:
                readFile();
                printf("Press Enter to continue\n");
                getchar();
                break;
            case 3:
                makeRecord();
                printf("Press Enter to continue\n");
                getchar();
                break;
            case 4:
                deleteRecords();
                printf("Press Enter to continue\n");
                getchar();
                break;
            case 5:
                deleteFile();
                printf("Press Enter to continue\n");
                getchar();
                break;
            case 6:
                editRecord();
                printf("Press Enter to continue\n");
                getchar();
                break;
            case 7:
                sortRecords();
                printf("Press Enter to continue\n");
                getchar();
                break;
            case 8:
                break;
        }
    } while (menuChoice != 9);
    return 0;
}
