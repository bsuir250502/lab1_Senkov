#include <stdio.h>
#include <stdlib.h>
#include "lib1.h"
#include <string.h>

#define max_number_of_sems 42
#define max_number_of_exams 10
#define max_number_of_students 30
#define max_number_of_symbols 60

typedef struct semester {
    char *exams;
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
void input_valid_string_data(char *, char *, int);
int input_valid_int_data(char *,int ,int );

/* functions for exams */
int select_input_of_exams(semester_t *);
int manual_input_of_exams(semester_t *);
int automat_input_of_exams(semester_t *);

/* functions for students */
void information_about_students(student_t *, semester_t *, int);
void students_input(student_t *, semester_t *, int, int);
void input_of_marks(student_t *, semester_t *, int, int);
void students_output(student_t *, semester_t *, int, int);
void auxiliary_information_for_user(int argc, char **argv);

int main(int argc, char **argv)
{
    auxiliary_information_for_user(argc,argv);
    student_t students[max_number_of_students];
    semester_t semesters[max_number_of_sems];
    information_about_students(students, semesters, select_input_of_exams(semesters));
    return 0;
}

/* -h */
void auxiliary_information_for_user(int argc, char **argv)
{
    if (argc > 1 && !strcmp(argv[1], "-h")) {
        puts("\n=====================================================================\n"
             "MANUAL:\n\n"
             "1)Select variant of input of exams:\n"
             "- automatic input.\n"
             "- manual input of exams.\n"
             "2)Enter information about students:\n"
             "- name.\n"
             "- sername.\n"
             "- patronymic.\n"
             "- marks.\n"
             "3)Enter number of semester, for output information about this semester.\n"
             "                      >>And output of main task<< \n"
             "=====================================================================\n");
        exit(0);
    }
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
    semesters[0].exams = "Math, Arithmetic, History";
    semesters[0].number_of_exams = 3 ;
    semesters[1].exams = "Programming, Physics, English";
    semesters[1].number_of_exams = 3 ;
    semesters[2].exams = "Math, Algorithmization, Programming";
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
    number_of_semesters = input_valid_int_data("Enter, please, number of semesters for input", 1, max_number_of_sems);
    for (i = 0; i < number_of_semesters; i++) {
        printf("\nInformation about exams for semester number %d)", i + 1);
        semesters[i].number_of_exams = input_valid_int_data("\nNumber of exams", 1, max_number_of_exams);
        semesters[i].exams=(char*)malloc(max_number_of_symbols*sizeof(char));
        input_valid_string_data( "\nEnter exams titles:", semesters[i].exams, max_number_of_symbols);
    }
    return number_of_semesters;
}

/* all information of students */
void information_about_students(student_t * students, semester_t * semesters, int number_of_semesters)    
{
    int number_of_students;                   
    number_of_students = input_valid_int_data("\nEnter, please,  number of students", 1, max_number_of_students); 
    students_input(students, semesters, number_of_students, number_of_semesters);
    students_output(students, semesters, number_of_students, number_of_semesters); 
}

/* input of all information for students */
void students_input(student_t *students, semester_t *semesters, int number_of_students, int number_of_semesters)    
{
    int i;
    for (i = 0; i < number_of_students; i++) {
        printf("\nInformation about student number %d)", i + 1);
        input_valid_string_data( "\nsurname: ", students[i].surname, max_number_of_symbols);
        input_valid_string_data("name: ", students[i].name, max_number_of_symbols);
        input_valid_string_data("patronymic: ", students[i].patronymic, max_number_of_symbols);
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
        for (j1 = 0; j1 < semesters[i].number_of_exams; j1++) {
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
    for (i = 0; i < number_of_semesters; i++) {
        free(semesters[i].exams);
    }
    puts("\n\nEnd.\n");
}
