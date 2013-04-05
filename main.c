#include <stdio.h>
#include <stdlib.h>
#include "lib1.h"
#include <string.h>

#define MAX_NUMBER_OF_SEMS 10
#define MAX_NUMBER_OF_EXAMS 5
#define MAX_NUMBER_OF_STUDENTS 30
#define MAX_NUMBER_OF_SYMBOLS 40

typedef struct semester {
    char exams[MAX_NUMBER_OF_SYMBOLS];
    int number_of_exams;
} semester_t;      

typedef struct semester_marks {
    int semester_number;
    int marks[MAX_NUMBER_OF_EXAMS];
} semester_marks_t;

typedef struct student {
    char surname[MAX_NUMBER_OF_SYMBOLS];
    char name[MAX_NUMBER_OF_SYMBOLS];
    char patronymic[MAX_NUMBER_OF_SYMBOLS];
    semester_marks_t marks[MAX_NUMBER_OF_SEMS];
} student_t;

/* functions from lib1.h */
void input_valid_string_data(char *, char *, int);
int input_valid_int_data(char *,int ,int );
void auxiliary_information_for_user();

/* functions for exams */
int select_input_of_exams(semester_t *);
int manual_input_of_exams(semester_t *);
int automat_input_of_exams(semester_t *);

/* functions for students */
void information_about_students(student_t *, semester_t *, int);
void students_input(student_t *, semester_t *, int, int);
void input_of_marks(student_t *, semester_t *, int, int);
void students_output(student_t *, semester_t *, int, int);

int main(int argc, char **argv)
{
    if (argc > 1 && !strcmp(argv[1], "-h")) {
        auxiliary_information_for_user();
        exit(0);
    }
    student_t students[MAX_NUMBER_OF_STUDENTS];
    semester_t semesters[MAX_NUMBER_OF_SEMS];
    information_about_students(students, semesters, select_input_of_exams(semesters));
    return 0;
}

/* select input for exams */
int select_input_of_exams(semester_t * semesters)
{
    int select;
    select = input_valid_int_data("\nSelect type of exams input:\n 1)automatic input.\n 2)manual input.\nSymbols for input:", 1, 2);
    if (select == 1) {
        return automat_input_of_exams(semesters);
    }
    else {
        return manual_input_of_exams(semesters);
    }
}

/* automat input of exams */
int automat_input_of_exams(semester_t * semesters)
{
    int i;
    strcpy(semesters[0].exams, "Math, Arithmetic, History");
    semesters[0].number_of_exams = 3 ;
    strcpy(semesters[1].exams, "Programming, Physics, English");
    semesters[1].number_of_exams = 3 ;
    strcpy(semesters[2].exams, "Math, Algorithmization, Programming");
    semesters[2].number_of_exams = 3 ;
    puts("\nList of exams:");
    for (i = 0; i < 3; i++) {
        printf(" %d semester : %s\n", i + 1, semesters[i].exams);
    }
    return 3;
 }

/* manual input of exams */
int manual_input_of_exams(semester_t * semesters)
{
    int i,number_of_semesters;
    number_of_semesters = input_valid_int_data("Enter, please, number of semesters for input", 1, MAX_NUMBER_OF_SEMS);
    for (i = 0; i < number_of_semesters; i++) {
        printf("\nInformation about exams for semester number %d)", i + 1);
        semesters[i].number_of_exams = input_valid_int_data("\nNumber of exams", 1, MAX_NUMBER_OF_EXAMS);
        input_valid_string_data( "\nEnter exams titles(through gap):", semesters[i].exams, MAX_NUMBER_OF_SYMBOLS);
    }
    return number_of_semesters;
}

/* all information of students */
void information_about_students(student_t * students, semester_t * semesters, int number_of_semesters)
{
    int number_of_students;
    number_of_students = input_valid_int_data("\nEnter, please,  number of students", 1, MAX_NUMBER_OF_STUDENTS);
    students_input(students, semesters, number_of_students, number_of_semesters);
    students_output(students, semesters, number_of_students, number_of_semesters);
}

/* input of all information for students */
void students_input(student_t *students, semester_t *semesters, int number_of_students, int number_of_semesters)
{
    int i;
    for (i = 0; i < number_of_students; i++) {
        printf("\nInformation about student number %d)", i + 1);
        input_valid_string_data( "\nsurname: ", students[i].surname, MAX_NUMBER_OF_SYMBOLS);
        input_valid_string_data("name: ", students[i].name, MAX_NUMBER_OF_SYMBOLS);
        input_valid_string_data("patronymic: ", students[i].patronymic, MAX_NUMBER_OF_SYMBOLS);
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
        printf("Semester number %d \nExams: %s", j + 1, semesters[j].exams);
        students[i].marks[j].semester_number=j;
        puts("\n");
        for (j1 = 0; j1 < semesters[j].number_of_exams; j1++) {
        students[i].marks[j].marks[j1] = input_valid_int_data("mark:", 1, 10);
        }
    }
}

/* output of all necessary information */
void students_output(student_t *students, semester_t *semesters, int number_of_students, int number_of_semesters)
{
    int semester_output_number, i, j;
    puts("\n------------ Output of information ------------\n");
    semester_output_number = input_valid_int_data("Enter number of semester for output:", 1, number_of_semesters);
    for (i = 0; i < number_of_students; i++) {
        printf("\n%d.\n surname: %s name: %s patronymic: %s \n", i + 1, students[i].surname, students[i].name, students[i].patronymic);
        printf("Exams: %s \nMarks:", semesters[semester_output_number].exams);
        for (j = 0; j < semesters[semester_output_number].number_of_exams; j++) {
            printf(" %d",students[i].marks[semester_output_number].marks[j]);
        }
    }
    puts("\n\nEnd.\n");
}
