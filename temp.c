#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "login.c"
#include "time_table_view.c"

struct Student {
    char id[7];
    char name[20];
    char gender;
    int age;
    long int phone;
    char address[15];
    char year[10];
    float math;
    float physic;
    float chemistry;
    float gpa;
    char rank[10];
};

typedef struct Student ST;

void add_student(FILE *file);
void show_student(ST st);
void gpa_student(ST *st);
void rank_student(ST *st);
void update_student(FILE *file, char id[]);
void show_all_students(FILE *file);
void delete_student_by_id(FILE *file, char delete_id[8]);
void find_student_by_id(FILE *file, char find_id[]);
void find_student_by_name(FILE *file, char name[]);
void find_max_gpa(FILE *file);
void find_min_gpa(FILE *file);
void find_max_age(FILE *file);
void find_min_age(FILE *file);
void list_student_by_rank(FILE *file, char rank[]);
void list_student_by_year(FILE *file, char year[]);
void sort_list_student_by_name_a_z(FILE *file);
void sort_list_student_by_name_z_a(FILE *file);
void sort_list_student_by_gpa_0_10(FILE *file);
void sort_list_student_by_gpa_10_0(FILE *file);
void press_any_key();

void add_student(FILE *file) {
    ST st;

    printf("Personal Details\n");
    printf("ID[6]: ");
    scanf("%7s", st.id);
    printf("Name[14]: ");
    getchar();
    scanf(" %[^\n]s", st.name);
    while (strlen(st.name) < 14) {
        strcat(st.name," ");  // Append a space character
    }
//gender
    gender(&st); 

    printf("Age: ");
    scanf("%d", &st.age);

    printf("Phone[9]: ");
    scanf("%d", &st.phone);

    printf("Address[14]: ");
    getchar();
    gets(st.address);
    while (strlen(st.address) < 14) {
        strcat(st.address," ");  // Append a space character
    }

    
    fflush(stdin);
    printf("Academic Details\n");

    do {
        printf("Year(First/Second/Third/Fourth): ");
        //getchar();
        scanf("%s", st.year);
        //gets(st.year);
    } while (strcmp(st.year, "first") != 0 &&
            strcmp(st.year, "second") != 0 &&
            strcmp(st.year, "third") != 0 &&
            strcmp(st.year, "fourth") != 0 &&
            strcmp(st.year, "Second") != 0 &&
            strcmp(st.year, "Third") != 0 &&
            strcmp(st.year, "Fourth") != 0 &&
            strcmp(st.year, "First") != 0);
    fflush(file);
    yellow();
    printf("Math: ");
    scanf("%f", &st.math);
    green();
    
    yellow();
    printf("Physic: ");
    scanf("%f", &st.physic);
    green();

    yellow();
    printf("Chemistry: ");
    scanf("%f", &st.chemistry);
    green();

    gpa_student(&st);
    rank_student(&st);

    fseek(file, 0, SEEK_END); // Move file pointer to the end of file
    fprintf(file, "%s\t%s\t\t%c\t%d\t%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n", st.id, st.name, st.gender, st.age, st.phone, st.address, st.year, st.math, st.physic, st.chemistry, st.gpa, st.rank);

    purple();
    printf("Data appended successfully.\n");
    green();
    fclose(file);
    main(); 
}



void gender(ST *st){
    char temp;
    printf("Gender:(M/F):");
    scanf(" %c", &temp);
    if(temp != 'm' && temp !='M' && temp !='f' && temp !='F'){
        red();
        printf("\nInvalid input\n");
        green();
        gender(st);
    }
    st->gender = toupper(temp);
    }

void show_student(ST st) {
    printf("%s\t\t%s\t\t%c\t%d\t%ld\t%s\t%s\t%.2f\t%.2f\t%.2f\t\t%.2f\t%s\n", st.id, st.name, st.gender, st.age, st.phone, st.address, st.year, st.math, st.physic, st.chemistry, st.gpa, st.rank);
}

void gpa_student(ST *st) {
    st->gpa = (st->math + st->physic + st->chemistry) / 33;
}

void rank_student(ST *st) {
    if (st->gpa > 7.0) {
        strcpy(st->rank, "Distinction");
    } else if (st->gpa > 5.5) {
        strcpy(st->rank, "Credit");
    } else if (st->gpa > 3.0) {
        strcpy(st->rank, "Pass");
    } else {
        strcpy(st->rank, "Fail");
    }
}

void update_student(FILE *file, char id[6]) {
    ST st;
    int found = 0;
    long int size;

    rewind(file);
    while (fscanf(file, "%7s\t%[^\t]\t %c\t%d\t%ld\t %[^\t]\t %[^\t]\t%f\t%f\t%f\t%f\t %[^\n]", st.id, st.name, &st.gender, &st.age, &st.phone, st.address, st.year, &st.math, &st.physic, &st.chemistry, &st.gpa, st.rank) != EOF) {
        if (strcmp(st.id ,id) == 0) {
            blue();
            printf("Personal Details\n");
            green();
            printf("ID[6]: ");
            scanf("%d", &st.id);
            printf("Name[14]: ");
            getchar();

            gets(st.name);
            //gender
            gender(&st);

            printf("Age: "); 
            scanf("%d", &st.age);
            printf("Phone[9]: "); 
            scanf("%d", &st.phone);
            printf("Address[15]: "); 
            while (strlen(st.name) < 14) {
            strcat(st.name," ");  
    }
    fflush(stdin);
    blue();
    printf("Academic Details\n");
    green();

    do {
        printf("Year(First/Second/Third/Fourth): ");
        //getchar();
        scanf("%s", st.year);
        //gets(st.year);
    } while (strcmp(st.year, "first") != 0 &&
            strcmp(st.year, "second") != 0 &&
            strcmp(st.year, "third") != 0 &&
            strcmp(st.year, "fourth") != 0 &&
            strcmp(st.year, "Second") != 0 &&
            strcmp(st.year, "Third") != 0 &&
            strcmp(st.year, "Fourth") != 0 &&
            strcmp(st.year, "First") != 0);
            gets(st.address);

            printf("Math: "); 
            scanf("%f", &st.math);
            printf("Physic: "); 
            scanf("%f", &st.physic);
            printf("Chemistry: "); 
            scanf("%f", &st.chemistry);

    gpa_student(&st);
    rank_student(&st);

            fseek(file, -sizeof(st), SEEK_CUR);
            fwrite(&st, sizeof(st), 1, file);
            found = 1;
            break;
        }
    }

    if (!found) {
        red();
        //printf("Student with ID %d not found.\n", id);
        green();
    } else {
        cyan();
        printf("Student updated successfully.\n");
        green();
    }
}


void show_all_students(FILE *file) {
    ST st;
    rewind(file); //in case pointer kahi aur ho toh beginning chl
    yellow();
    printf("ID\t\tName\t\t\tGender\tAge\tPhone\t\tAddress\t\tYear\tMath\tPhysics\tChemistry\tGPA\tRank\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
    green();
    while (fscanf(file, "%s\t %[^\t]\t %c\t%d\t%ld %[^\t]\t %[^\t]\t%f\t%f\t%f\t%f %[^\n]", &st.id, st.name, &st.gender, &st.age, &st.phone, st.address, st.year, &st.math, &st.physic, &st.chemistry, &st.gpa, st.rank) == 12) {
        show_student(st);
    }

    rewind(file);

}

void delete_student_by_id(FILE *file, char delete_id[6]) {
    
    FILE *tempFile = fopen("xyz.txt", "w+");
    if (!tempFile) {
        printf("Error creating temporary file.");
        return;
    }
    
    ST st;
    int found = 0;
    rewind(file);
    while (fscanf(file, "%7s\t%[^\t]\t %c\t%d\t%ld\t %[^\t]\t %[^\t]\t%f\t%f\t%f\t%f\t %[^\n]", &st.id, st.name, &st.gender, &st.age, &st.phone, st.address, st.year, &st.math, &st.physic, &st.chemistry, &st.gpa, st.rank) != EOF) {
        char tempid[7];
        strcpy(tempid, st.id);
        if (strcmp(strupr(st.id), strupr(delete_id)) != 0){
    fprintf(tempFile, "%s\t%s\t%c\t%d\t%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n", tempid, st.name, st.gender, st.age, st.phone, st.address, st.year, st.math, st.physic, st.chemistry, st.gpa, st.rank);
        }
        else {
            found = 1;
        }
    }
    fclose(file);
    fclose(tempFile);

    remove("MANGA.txt");
    rename("xyz.txt", "MANGA.txt");

    if (found) {
        printf("Delete successful for student ID %s.\n", delete_id);
    } 
    else {
        red();
        printf("Student with ID %s not found.\n", delete_id);
    }
    main();
}

void find_student_by_id(FILE *file, char find_id[]) {
    ST st;
    int found = 0;
    rewind(file);

    while (fscanf(file, "%7s\t%[^\t]\t %c\t%d\t%ld\t %[^\t]\t %[^\t]\t%f\t%f\t%f\t%f\t %[^\n]", st.id, st.name, &st.gender, &st.age, &st.phone, st.address, st.year, &st.math, &st.physic, &st.chemistry, &st.gpa, st.rank) != EOF) {

        if (strcmp(st.id, find_id) == 0) {
            printf("Student found:\n");
            show_student(st);
            found = 1;
            break;
        }
    }
    if (!found) {
        red();
        printf("Student with ID %s not found.\n", find_id);
        green();
    }
}




void find_student_by_name(FILE *file, char name[]) {
    ST st;
    int found = 0;
    rewind(file);

    printf("Searching for name: %s\n", name); 
    while (strlen(name) < 14) {
        strcat(name," ");  // Append a space character
    }
    while (fscanf(file, "%7s\t%[^\t]\t %c\t%d\t%ld\t %[^\t]\t %[^\t]\t%f\t%f\t%f\t%f\t %[^\n]", &st.id, st.name, &st.gender, &st.age, &st.phone, st.address, st.year, &st.math, &st.physic, &st.chemistry, &st.gpa, st.rank) != EOF) {

        if (strcmp(strupr(st.name), strupr(name)) == 0) {
            printf("Student found:\n");
            show_student(st);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with name '%s' not found.\n", name);
    }
}


void find_max_gpa(FILE *file) {
    ST st;
    float max_gpa = -1;
    rewind(file);
    while (fscanf(file, "%7s\t%[^\t]\t %c\t%d\t%ld\t %[^\t]\t %[^\t]\t%f\t%f\t%f\t%f\t %[^\n]", &st.id, st.name, &st.gender, &st.age, &st.phone, st.address, st.year, &st.math, &st.physic, &st.chemistry, &st.gpa, st.rank) != EOF) {
        if (st.gpa > max_gpa) {
            max_gpa = st.gpa;
        }
    }
    printf("Maximum GPA: %.2f of student %s\n", max_gpa, st.name);
    
}

void find_min_gpa(FILE *file) {
    ST st;
    float min_gpa = 11;
    rewind(file);
    while (fscanf(file, "%7s\t%[^\t]\t %c\t%d\t%ld\t %[^\t]\t %[^\t]\t%f\t%f\t%f\t%f\t %[^\n]", &st.id, st.name, &st.gender, &st.age, &st.phone, st.address, st.year, &st.math, &st.physic, &st.chemistry, &st.gpa, st.rank) != EOF) {
        if (st.gpa < min_gpa) {
            min_gpa = st.gpa;
        }
    }
    printf("Minimum GPA: %.2f of student %s\n", min_gpa, st.name);
}

void find_max_age(FILE *file) {
    ST st;
    ST tempst;
    int max_age = -1;
    rewind(file);
    while (fscanf(file, "%7s\t%[^\t]\t %c\t%d\t%ld\t %[^\t]\t %[^\t]\t%f\t%f\t%f\t%f\t %[^\n]", st.id, st.name, &st.gender, &st.age, &st.phone, st.address, st.year, &st.math, &st.physic, &st.chemistry, &st.gpa, st.rank) != EOF) {
        if (st.age > max_age) {
            tempst = st;
            max_age = st.age;
            
        }
    }
    printf("ID\t\tName\t\t\tGender\tAge\tPhone\t\tAddress\t\tYear\tMath\tPhysic\tChemistry\tGPA\tRank\n");
    show_student(st);
    printf("Maximum Age: %d\n", max_age);
}

void find_min_age(FILE *file) {
    ST st;
    ST tempst;
    int min_age = 200;
    rewind(file);
    while (fscanf(file, "%7s\t%[^\t]\t %c\t%d\t%ld\t %[^\t]\t %[^\t]\t%f\t%f\t%f\t%f\t %[^\n]", st.id, st.name, &st.gender, &st.age, &st.phone, st.address, st.year, &st.math, &st.physic, &st.chemistry, &st.gpa, st.rank) != EOF){
        if (st.age < min_age) {
            tempst = st;
            min_age = st.age;
        }
    }
    printf("ID\t\tName\t\t\tGender\tAge\tPhone\t\tAddress\t\tYear\tMath\tPhysic\tChemistry\tGPA\tRank\n");
    show_student(tempst);
    printf("Minimum Age: %d\n", min_age);
}

void list_student_by_rank(FILE *file, char rank[]) {
    ST st;
    int found = 0;
    rewind(file);
    printf(""); //ye line nhi likh rha tha toh 'distinction' likha tha.
    while (fscanf(file, "%7s\t%[^\t]\t %c\t%d\t%ld\t %[^\t]\t %[^\t]\t%f\t%f\t%f\t%f\t %[^\n]", st.id, st.name, &st.gender, &st.age, &st.phone, st.address, st.year, &st.math, &st.physic, &st.chemistry, &st.gpa, st.rank) != EOF) {
        if (strcmp(strupr(st.rank), strupr(rank)) == 0) {
            show_student(st);
            found = 1;
        }
    }
    if (!found) {
        printf("No students with rank '%s' found.\n", rank);
    }
}

void list_student_by_year(FILE *file, char year[]) {
    ST st;
    int found = 0;
    rewind(file);
    while (fscanf(file, "%7s\t%[^\t]\t %c\t%d\t%ld\t %[^\t]\t %[^\t]\t%f\t%f\t%f\t%f\t %[^\n]", &st.id, st.name, &st.gender, &st.age, &st.phone, st.address, st.year, &st.math, &st.physic, &st.chemistry, &st.gpa, st.rank) != EOF) {
        if (strcmp(strupr(st.year), strupr(year)) == 0) {
            show_student(st);
            found = 1;
        }
    }
    if (!found) {
        printf("No students in year '%s' found.\n", year);
    }
}


void sort_list_student_by_name_a_z(FILE *file) {
    ST st[100], temp;
    int count = 0;

    rewind(file);
    while (fscanf(file, "%7s\t%[^\t]\t %c\t%d\t%ld\t %[^\t]\t %[^\t]\t%f\t%f\t%f\t%f\t %[^\n]", st[count].id, st[count].name, &st[count].gender, &st[count].age, &st[count].phone, st[count].address, st[count].year, &st[count].math, &st[count].physic, &st[count].chemistry, &st[count].gpa, st[count].rank) != EOF) {
        count++;
    }


    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(st[i].name, st[j].name) > 0) {
                temp = st[i];
                st[i] = st[j];
                st[j] = temp;
            }
        }
    }

remove(file);
file = fopen("MANGA.txt", "w");

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\t%s\t%c\t%d\t%ld\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n", st[i].id, st[i].name, st[i].gender, st[i].age, st[i].phone, st[i].address, st[i].year, st[i].math, st[i].physic, st[i].chemistry, st[i].gpa, st[i].rank);
    }
    rewind(file);
    fclose(file);
    file = fopen("MANGA.txt", "a+");
    show_all_students(file);
}


void sort_list_student_by_name_z_a(FILE *file) {
    ST st[100], temp;
    int count = 0;

    rewind(file);
    while (fscanf(file, "%7s\t%[^\t]\t %c\t%d\t%ld\t %[^\t]\t %[^\t]\t%f\t%f\t%f\t%f\t %[^\n]", st[count].id, st[count].name, &st[count].gender, &st[count].age, &st[count].phone, st[count].address, st[count].year, &st[count].math, &st[count].physic, &st[count].chemistry, &st[count].gpa, st[count].rank) != EOF) {
        count++;
    }


    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(st[i].name, st[j].name) < 0) {
                temp = st[i];
                st[i] = st[j];
                st[j] = temp;
            }
        }
    }

remove(file);
file = fopen("MANGA.txt", "w");

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\t%s\t%c\t%d\t%ld\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n", st[i].id, st[i].name, st[i].gender, st[i].age, st[i].phone, st[i].address, st[i].year, st[i].math, st[i].physic, st[i].chemistry, st[i].gpa, st[i].rank);
    }
    fclose(file);
    file = fopen("MANGA.txt", "a+");
    show_all_students(file);
}

void sort_list_student_by_gpa_0_10(FILE *file) {
    ST st[100], temp;
    int count = 0;

    rewind(file);
    while (fscanf(file, "%7s\t%[^\t]\t %c\t%d\t%ld\t %[^\t]\t %[^\t]\t%f\t%f\t%f\t%f\t %[^\n]", st[count].id, st[count].name, &st[count].gender, &st[count].age, &st[count].phone, st[count].address, st[count].year, &st[count].math, &st[count].physic, &st[count].chemistry, &st[count].gpa, st[count].rank) != EOF) {
        count++;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (st[i].gpa > st[j].gpa) {
                temp = st[i];
                st[i] = st[j];
                st[j] = temp;
            }
        }
    }
remove(file);
file = fopen("MANGA.txt", "w");

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\t%s\t%c\t%d\t%ld\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n", st[i].id, st[i].name, st[i].gender, st[i].age, st[i].phone, st[i].address, st[i].year, st[i].math, st[i].physic, st[i].chemistry, st[i].gpa, st[i].rank);
    }
    fclose(file);
    file = fopen("MANGA.txt", "a+");
    show_all_students(file);
}

void sort_list_student_by_gpa_10_0(FILE *file) {
    ST st[100], temp;
    int count = 0;

    rewind(file);
    while (fscanf(file, "%7s\t%[^\t]\t %c\t%d\t%ld\t %[^\t]\t %[^\t]\t%f\t%f\t%f\t%f\t %[^\n]", st[count].id, st[count].name, &st[count].gender, &st[count].age, &st[count].phone, st[count].address, st[count].year, &st[count].math, &st[count].physic, &st[count].chemistry, &st[count].gpa, st[count].rank) != EOF) {
        count++;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (st[i].gpa < st[j].gpa) {
                temp = st[i];
                st[i] = st[j];
                st[j] = temp;
            }
        }
    }
remove(file);
file = fopen("MANGA.txt", "w");

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\t%s\t%c\t%d\t%ld\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n", st[i].id, st[i].name, st[i].gender, st[i].age, st[i].phone, st[i].address, st[i].year, st[i].math, st[i].physic, st[i].chemistry, st[i].gpa, st[i].rank);
    }
    fclose(file);
    file = fopen("MANGA.txt", "a+");
    show_all_students(file);
}

void no_of_records() {
    ST st;
    int n;
    FILE *fp = fopen("MANGA.txt", "rb");
    if (fp == NULL) {
        printf("\n\tFile doesn't exist! Please ADD RECORD first.\n\n\t");
        system("pause");
        main();
    }

    fseek(fp, 0, SEEK_END); // Move the file position pointer to the end
    n = ftell(fp) / sizeof(ST); // Calculate the number of records based on file size and record size
    fclose(fp);

    printf("Number of records: %d\n", n+2);
}


void press_any_key() {
    getchar();
    printf("Press enter to continue...\n");
    getchar();
}

int log = 1;

int main() {
    system("cls");
    red();
    if(wrong == 1){
        printf("\033[1;31m");
        printf("Invalid id or password\n\n");
        printf("\033[1;32m");
    }
    printf("--------------------------------------\n\n");
    printf("WELCOME TO STUDENT MANAGEMENT SYSTEM!\n\n");
    printf("--------------------------------------\n\n");
    green();
    int option;
    if(log){
    printf("1. Signup\n");
    printf("2. Login\n");
    
scanf("%d", &option);
system("cls");
if(option == 2){
    login();}
else if(option == 1){
    signup();
}
else if(option == 3){
    deleteid();
}
    }
    log = 0;
    system("color f0"); //background
    FILE *file;
    file = fopen("MANGA.txt", "a+");
    if (file == NULL) {
        red();
        printf("Error opening file.\n");
        green();
        return 1;
    }

    int choice;
    char delete_id[6], section;
    char find_id[7];
    char find_name[50], find_rank[10], find_year[10];

    do {
        system("cls"); 
        red();
        printf(" \n======= Student Management System =======\n\n");
        green();
        printf("1. Add Student\n");
        printf("2. Show All Students\n");
        printf("3. Find Student by ID\n");
        printf("4. Find Student by Name\n");
        printf("5. Find Students with Maximum GPA\n");
        printf("6. Find Students with Minimum GPA\n");
        printf("7. Find Students with Maximum Age\n");
        printf("8. Find Students with Minimum Age\n");
        printf("9. List Students by Rank\n");
        printf("10. List Students by year\n");
        printf("11. Sort Students by Name (A-Z)\n");
        printf("12. Sort Students by Name (Z-A)\n");
        printf("13. Sort Students by GPA (0-10)\n");
        printf("14. Sort Students by GPA (10-0)\n");
        printf("15. Delete Student by ID\n");
        printf("16. Update Student\n");
        printf("17. Number of Records\n");
        printf("18. View Time Table\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        system("cls");
        switch (choice) {
            case 1:
                add_student(file);
                break;
            case 2:
                show_all_students(file);
                break;
            case 3:
                printf("Enter student ID to fnd: ");
                fflush(stdin);
                scanf("%s", find_id);
                getchar();
                find_student_by_id(file, find_id);
                break;
            case 4:
                printf("Enter student name to find: ");
                getchar();
                fgets(find_name, 50, stdin);
                size_t len = strlen(find_name);
                if (len > 0 && find_name[len - 1] == '\n') {
                    find_name[len - 1] = '\0';
                }
                find_student_by_name(file, find_name);
                break;
            case 5:
                find_max_gpa(file);
                break;
            case 6:
                find_min_gpa(file);
                break;
            case 7:
                find_max_age(file);
                break;
            case 8:
                find_min_age(file);
                break;
            case 9:
                printf("Enter rank to list students: ");
                fflush(stdin);
                scanf("%s", find_rank);
                list_student_by_rank(file, find_rank);
                break;
            case 10:
                printf("Enter year (first/second/third/fourth) to list students: ");
                fflush(stdin);
                getchar();
                gets(find_year);
                list_student_by_year(file, find_year);
                break;
            case 11:
                sort_list_student_by_name_a_z(file);
                break;
            case 12:
                sort_list_student_by_name_z_a(file);
                break;
            case 13:
                sort_list_student_by_gpa_0_10(file);
                break;
            case 14:
                sort_list_student_by_gpa_10_0(file);
                break;
            case 15:
                
                printf("Enter student ID to delete: ");
                getchar();
                gets(delete_id);
                delete_student_by_id(file, delete_id);
                break;
            case 16:
                printf("Enter student ID to update: ");
                scanf("%s", find_id);
                find_student_by_id(file, find_id);
                update_student(file, find_id);
                break;
            case 17:
                no_of_records();
                break;
            case 18:
            printf("Enter Section(A/B):");
            getchar();
            scanf("%c",&section);
                time_table(section);
            case 0:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        press_any_key();
        system("cls"); 
    } while (choice != 0);

    fclose(file);
    return 0;
}


//COLORS


void black()
{
	printf("\033[1;30m");
}
void red()
{
	printf("\033[1;31m"); // changes text to red
}
void green()
{
	printf("\033[1;32m");
}
void yellow()
{
	printf("\033[33m");
}

void blue()
{
	printf("\033[1;34m");
}
void purple()
{
	printf("\033[1;35m");
}
void cyan()
{
	printf("\033[1;36m");
}
void white()
{
	printf("\033[1;37m");
}
