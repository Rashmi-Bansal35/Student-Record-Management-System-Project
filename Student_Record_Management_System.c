#include<stdio.h>
#include<string.h>

// Declare functions
void viewStudent();
void addStudent();
void deleteStudent();
void updateStudent();
void searchStudent();

// Define struct for student record
struct Student{
    char name[50];
    int rollNo;
    char grade[4];
};

int main(){
    int option;

    // Take input from user
    do {
        printf("\n---*---*--- Student Record System ---*---*---\n");
        printf("1. View all students\n");
        printf("2. Add Student\n");
        printf("3. Delete student\n");
        printf("4. Update Student\n");
        printf("5. Search Student\n");
        printf("6. Exit\n");
        printf("Select one: ");
        scanf("%d", &option);
        getchar();

        switch (option){
            case 1:
                viewStudent();// Call function to see details of all students
                break;
            case 2:
                addStudent();// Call function to add student
                break;
            case 3:
                deleteStudent();// Call function to delete details of a student
                break;
            case 4:
                updateStudent();// Call function to change details of student
                break;
            case 5:
                searchStudent();// Call function to search a student
                break;
            case 6:
                printf("Exit \n");
                break;
            default:
                printf("Please enter valid option...");
        }
    }
    while(option != 6);


    return 0;
}

void viewStudent(){
    struct Student s;
    FILE *fp = fopen("students.txt", "rb");

    if (fp == NULL){
        printf("No record found!!\n");
        return;
    }

    printf("Name \t  Roll No \t Grade\n");
    printf("---*---*---*---*---*---*---*---*---\n");
    while (fread(&s, sizeof(s), 1, fp) == 1){
        printf("%s \t %d \t %s\n", s.name, s.rollNo, s.grade);
    }

    fclose(fp);
}

void addStudent(){
    struct Student s;
    FILE *fp = fopen("students.txt", "ab");

    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; 
    printf("Enter Roll No.: ");
    scanf("%d", &s.rollNo);
    getchar();
    printf("Enter Grade: ");
    fgets(s.grade, sizeof(s.grade), stdin);
    s.grade[strcspn(s.grade, "\n")] = '\0';

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Record Added Successfully.\n");
}

void deleteStudent(){
    struct Student s;
    FILE *fp, *temp;
    int roll, found = 0;

    fp = fopen("students.txt", "rb");
    if (fp == NULL){
        printf("No recod found!!\n");
    }

    temp = fopen("temp.txt", "wb");
    printf("Enter roll no.: ");
    scanf("%d", &roll);
    getchar();

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        // If this student's roll number matches, skip writing
        if (s.rollNo == roll) {
            found = 1; 
            continue;  
        }
        // Write student record to temp file
        fwrite(&s, sizeof(s), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    // Delete original file and rename temp to original filename
    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        printf("Student record deleted successfully.\n");
    else
        printf("Student record not found.\n");
}

void updateStudent(){
    struct Student s;
    int roll, found = 0;
    FILE *fp = fopen("students.txt", "rb");
    FILE *temp = fopen("temp.txt", "wb");

    printf("Enter roll number to update: ");
    scanf("%d", &roll);
    getchar();

    if (fp == NULL){
        printf("No result found.\n");
        return;
    }

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.rollNo == roll) {
            found = 1;

            // Take new details from user
            printf("Enter new name: ");
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = '\0';
            printf("Enter new grade: ");
            scanf("%s", s.grade);
        }
        // Write data to temp file
        fwrite(&s, sizeof(s), 1, temp);
    }

    remove("students.txt");
    rename("temp.txt", "students.txt");

    fclose(fp);
    fclose(temp);

    if(found){
        printf("Record Updated.\n");
    }
    else{
        printf("Record not found.");
    }
}

void searchStudent(){
    struct Student s;
    int roll, found = 0;
    FILE *fp = fopen("students.txt", "rb");

    printf("Enter roll no.: ");
    scanf("%d", &roll);

    while(fread(&s, sizeof(s), 1, fp) == 1){
        if(s.rollNo == roll){
            printf("Record Found:\nName: %s\tRoll No.: %d\tGrade: %s\n", s.name, s.rollNo, s.grade);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("NOT FOUND!!\n");
    }
    fclose(fp);
}