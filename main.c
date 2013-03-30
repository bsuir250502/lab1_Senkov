#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include"lib1.h"
#define max_number_of_sems 42
#define max_number_of_exams 10
#define max_number_of_students 30
#define max_number_of_symbols 60

typedef struct semester {
    char *exams[256];
    int number_of_exams;
} semester_t;      

typedef struct semester_marks {
    int semester_number;
    int marks[max_number_of_exams];
} semester_marks_t;

typedef struct student {
    char surname[max_number_of_symbols];
    char name[max_number_of_symbols];
    char patronymic[max_number_of_symbols]; 
    semester_marks_t marks[max_number_of_sems];
} student_t;

/* functions from lib1.h */
void students_quantity(int *);
char *input_valid_data();

/* functions for exams */
int information_about_semesters(semester_t *, int);
int select_input_of_exams(semester_t *, int);
int manual_input_of_exams(semester_t *, int);
int automat_input_of_exams(semester_t *, int);

/* functions for students */
void information_about_students(student_t *, semester_t *, int, int);
void students_input(student_t *, semester_t *, int, int);
void input_of_marks(student_t *, semester_t *, int);
void students_output(student_t *, int, semester_t *, int);

int main()
{
    student_t students[max_number_of_students];    /* create of array for students. */
    semester_t semesters[max_number_of_sems];  /* create of array for semesters. */
    information_about_semesters(semesters, max_number_of_exams);  /* all information about semesters. */
    int number_of_semesters = 20;
    information_about_students(students, semesters, number_of_semesters);  /* all information about students. */
    return 0;
}

/* all information for semesters */
int information_about_semesters(semester_t *semesters, int max_number_of_exams)
{
    int number_of_semesters;
    number_of_semesters = select_input_of_exams(semesters, max_number_of_sems); 
    return number_of_students;   
}

/* select input for exams */
int select_input_of_exams(semester_t * semesters, int max_number_of_sems) 
{
    int select;
    puts ("\nSelect type of exams input:\n"
            "1)automatic input.\n"
            "2)manual input.");
    while (1) {
        scanf ("%d", &select);
        switch (select) {
        case 1: 
            return automat_input_of_exams(semesters, max_number_of_sems);
            break;
        case 2:
            return manual_input_of_exams(semesters, max_number_of_sems);
            break;
        default:
             puts("Invalid input, try again.");
        }
    }
}

/* automat input of exams */
int automat_input_of_exams(semester_t * semesters, int max_number_of_sems)    
{
    int i;
    semesters[0].exams = {"Math", "Arithmetic", "History"};
    semesters[0].number_of_exams = 3 ;
    semesters[1].exams = {"Programming", "Physics", "English"};
    semesters[1].number_of_exams = 3 ;
    semesters[2].exams = {"Math", "Algorithmization", "Programming"};
    semesters[2].number_of_exams = 3 ;
    puts("\nList of exams:");
    for (i = 0; i < 3; i++) {
        printf(" %d semester : %s\n", i + 1, semesters[i].exams);
    }
    return 3;
 }

/* manual input of exams */
int manual_input_of_exams(semester_t * semesters, int max_number_of_sems)    
{                               
    int i,number_of_semesters;
    printf("Enter, please, number of semesters for input\n"
           "(Max number is %d)",max_number_of_sems);
    scanf("%d",&number_of_semesters);
    for (i = 0; i < number_of_semesters; i++) {
        printf("Information about exams for semester number %d)", i + 1);
        __fpurge(stdin);
        printf("Number of exams (max is %d):",max_number_of_exams);
        scanf("%d",&semesters[i].number_of_exams);
        semesters[i].exams = input_valid_data();
    }
    return number_of_semesters;
}

/* all information of students */
void information_about_students(student_t * students, int max_number_of_students,  semester_t * semesters, int number_of_semesters)    
{                      
    printf("\nEnter, please,  number of students(max is %d):",max_number_of_students);
    scanf("%d",number_of_students);
    number_of_students = students_quantity(&number_of_students); 
    students_input(students, number_of_student, semesters, number_of_students, number_of_semesters)
    students_output(students, number_of_students, semesters, number_of_semesters, number_of_semesters); 
}

/* input of all information for students */
void students_input(student_t *students, semester_t *semesters, int number_of_student, int number_of_semesters)    
{                      
    int i;
    for (i = 0; i < number_of_students; i++) {
        printf("\nInformation about student number %d)", i + 1);
        __fpurge(stdin);
        puts("\nsurname: ");
        students[i].surname = input_valid_data();
        puts("name: ");
        students[i].name = input_valid_data();
        puts("patronymic: ");
        students[i].patronymic = input_valid_data();
        input_of_marks(students, semesters, i, number_of_semesters);
    }	
}

/* input of marks */
void input_of_marks(student_t *students, semester_t *semesters, int i, int number_of_semesters)
{
    int j,j1;
    puts("\n----------------- Marks ------------------");
    printf("\nPut marks for %s", students[i].name);
    for (j = 0; j < number_of_semesters; j++) {
        printf("semester number %d \n",j + 1
               "exams: %s",semesters[j].exams);
        students[i].marks[j].semester_number=j;
        for (j1 = 0; j1 < semesters[i].number_of_exams; j1++) {
            scanf("%d",students[i].marks[j].marks[j1]);
        }
    }
}

/* output of all necessary information */
void students_output(student_t *students, int number_of_students, semester_t *semesters, int number_of_semesters)  
{                               
    int semester_output_number, i, j, j1;
    puts("\n------------ Output of information ------------\n"
         "Enter, please, number of semester for output:");
    scanf("%d", &semester_output_number);
    for (i = 0; i < number_of_students; i++) {
        printf("\n%d.\n surname: %s name: %s patronymic: %s \n", i, students[i].surname, students[i].name, students[i].patronymic);
        for (j = 0; j < number_of_semesters; j++) {
            if (studentsmas[i].marks[j].semester_number == semester_output_number) {
            printf("Exams: %s \n", semesters[semester_output_number].exams
                   "Marks:");
            for (j1 = 0; j1 < semesters[semester_output_number].number_of_exams; j1++) {
                printf("%d",students[i].marks[semester_output_number].marks[j1]);
            }
        }
    }
}
