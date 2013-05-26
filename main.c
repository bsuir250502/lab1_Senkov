#include <stdio.h>
#include <stdlib.h>
#include "lib1.h"
#include <string.h>

#define SEMS_MAX 10
#define EXAMS_MAX 5
#define STUDENT_MAX 30
#define SYMB_MAX 40

typedef struct semester {
    char exam[EXAMS_MAX][SYMB_MAX];
    int number_of_exams;
} semester_t;      

typedef struct semester_marks {
    int semester_number;
    int marks[EXAMS_MAX];
} semester_marks_t;

typedef struct student {
    char surname[SYMB_MAX];
    char name[SYMB_MAX];
    char patronymic[SYMB_MAX];
    semester_marks_t marks[SEMS_MAX];
} student_t;

void input_valid_string_data(char *, char *, int);
int input_valid_int_data(char *,int ,int );
void help_output();
int input_of_exams(semester_t *);
void information_about_students(student_t *, semester_t *, int);
void input_of_marks(student_t *, semester_t *, int, int);
void students_output(student_t *, semester_t *, int, int);

int main(int argc, char **argv)
{
    student_t students[STUDENT_MAX];
    semester_t semesters[EXAMS_MAX];
    if (argc > 1 && !strcmp(argv[1], "-h")) {
        help_output();
        return 0;
    }
    information_about_students(students, semesters, input_of_exams(semesters));
    return 0;
}

int input_of_exams(semester_t * semesters)
{
    int i, j;
    strcpy(semesters[0].exam[0], "Math");
    strcpy(semesters[0].exam[1], "Arithmetic");
    strcpy(semesters[0].exam[2], "History");
    semesters[0].number_of_exams = 3 ;
    strcpy(semesters[1].exam[0], "Programming");
    strcpy(semesters[1].exam[1], "Physics");
    strcpy(semesters[1].exam[2], "English");
    semesters[1].number_of_exams = 3 ;
    strcpy(semesters[2].exam[0], "Math");
    strcpy(semesters[2].exam[1], "Algorithmization");
    strcpy(semesters[2].exam[2], "Programming");
    semesters[2].number_of_exams = 3 ;
    puts("\nList of exams:");
    for (i = 0; i < 3; i++) {
        printf(" \n%d semester :\n", i + 1);
        for (j = 0; j < 3; j++) {
            printf(" %s" , semesters[i].exam[j]);
        }
    }
    return 3;
 }

void information_about_students(student_t * students, semester_t * semesters, int number_of_semesters)
{
    int i;
    int number_of_students;
    number_of_students = input_valid_int_data("\nEnter, please,  number of students", 1, STUDENT_MAX);
    for (i = 0; i < number_of_students; i++) {
        printf("\nInformation about student number %d)", i + 1);
        input_valid_string_data( "\nsurname: ", students[i].surname, SYMB_MAX);
        input_valid_string_data("name: ", students[i].name, SYMB_MAX);
        input_valid_string_data("patronymic: ", students[i].patronymic, SYMB_MAX);
        input_of_marks(students, semesters, i, number_of_semesters);
    }
    students_output(students, semesters, number_of_students, number_of_semesters);
}

void input_of_marks(student_t *students, semester_t *semesters, int i, int number_of_semesters)
{
    int i1, j, j1;
    puts("\n----------------- Marks ------------------");
    printf("\nPut marks for %s", students[i].name);
    for (j = 0; j < number_of_semesters; j++) {
        printf("Semester number %d \n", j + 1);
        puts ("Exams:");
        for (i1 = 0; i1 < 3; i1++) {
            printf (" %s ", semesters[j].exam[i1]);
        }
        students[i].marks[j].semester_number = j;
        puts("\n");
        for (j1 = 0; j1 < semesters[j].number_of_exams; j1++) {
            students[i].marks[j].marks[j1] = input_valid_int_data("mark:", 1, 10);
        }
    }
}

void students_output(student_t *students, semester_t *semesters, int number_of_students, int number_of_semesters)
{
    int semester_output_number, i, j, j1;
    puts("\n------------ Output of information ------------\n");
    semester_output_number = input_valid_int_data("Enter number of semester for output:", 1, number_of_semesters);
    for (i = 0; i < number_of_students; i++) {
        printf("\n%d.\n surname: %s name: %s patronymic: %s \n", i + 1, students[i].surname,
                                                                 students[i].name, students[i].patronymic);
        puts("Exams:");
        for (j1 = 0; j1 < 3; j1++) {
            printf(" %s \n", semesters[semester_output_number].exam[j1]);
        }
        puts("Marks:");
        for (j = 0; j < semesters[semester_output_number].number_of_exams; j++) {
            printf(" %d",students[i].marks[semester_output_number].marks[j]);
        }
    }
    puts("\n\nEnd.\n");
}