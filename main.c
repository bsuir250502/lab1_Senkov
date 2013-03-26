#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

typedef struct semester {
    char *exam_1;
    char *exam_2;
    char *exam_3;
} semester_t;

typedef struct student {
    char *surname;
    char *name;
    char *patronymic;
    int semester_number;
    int marks[3];
} student_t;

void students_quantity(int *);
char *check_input();
void exams_filling(semester_t *);
void exams_automat(semester_t *);
void exams_select(semester_t *);
void students_input(student_t *, int, semester_t *);
void students_output(student_t *, int, semester_t *);
void input_of_marks(student_t *, semester_t *, int);

int main()
{
    int max_number_of_students = 30;
    student_t mas[max_number_of_students];    /* create of array for students. */
    int number_of_students;
    semester_t array[3] = {
        {"Math", "Arithmetic", "History"},
        {"Programming", "Physics", "English"},
        {"Math", "Algorithmization", "Programming"},
    };
    exams_select(array);                             /* select exams input. */
    students_quantity(&number_of_students);          /* input number_of_student. */
    students_input(mas, number_of_students, array);  /* input information about students. */
    students_output(mas, number_of_students, array); /* output. */
    return 0;
}

char *check_input()    /* function for checking input infomation (srting). */
{                               
    char *input_text;
    input_text = (char *)malloc(sizeof(char));
    do {
        __fpurge(stdin);
        fgets(input_text, 30, stdin);
        if (input_text[0] == '\n' || input_text[0] == ' ') {
            puts("Invalid input, try again.");
            continue;
		}
		else
            break;
    } while (1);
    return input_text;
}
 
void students_quantity(int *number_of_students)    /* function for input number of students. */
{                              
    puts("\nEnter, please,  number of students(max is 30):");
    while (!scanf("%d", &*number_of_students) || *number_of_students < 1) {    /* n - number of students. */
        __fpurge(stdin);
        puts("Invalid input, try again.");
    }
}

void exams_automat(semester_t * array)    /* automat input of exams. */
{                               
    int i;
    puts("\nList of exams:");
    for (i = 0; i < 3; i++) {
        printf(" %d semester:\n", i + 1);
        puts(array[i].exam_1);
        puts(array[i].exam_2);
        puts(array[i].exam_3);
    }
}

void exams_filling(semester_t * array)    /* clever input of exams. */
{                               
    int i;
    puts("Enter, please, exams for 3 semesters:");
    for (i = 0; i < 3; i++) {
        printf("Information about semester number %d)", i + 1);
        __fpurge(stdin);
        puts("\n1 exam: ");
        array[i].exam_1 = check_input();
        puts("2 exam: ");
        array[i].exam_2 = check_input();
        puts("3 exam: ");
        array[i].exam_3 = check_input();
    }
}

void exams_select(semester_t * array)    /* select exam. */
{                               
    int select, check = 0;
    puts("\nSelect type of exams input:\n1)automatic input.\n2)clever input.");
    while (check == 0) {
        scanf("%d", &select);
        switch (select) {
        case 1:
            exams_automat(array);
            check = 1;
            break;
        case 2:
            exams_filling(array);
            check = 1;
            break;
        default:
            puts("Invalid input, try again.");
        }
    }
}

void students_input(student_t * mas, int number_of_students,  semester_t * array)    /* input of all informaion about student. */
{                               
    int i;
    for (i = 0; i < number_of_students; i++) {
        printf("\nInformation about student number %d)", i + 1);
        __fpurge(stdin);
        puts("\nsurname: ");
        mas[i].surname = check_input();
        puts("name: ");
        mas[i].name = check_input();
        puts("patronymic: ");
        mas[i].patronymic = check_input();
        puts("Enter number of semester(max is 3): ");
        while (!scanf("%d", &mas[i].semester_number) || mas[i].semester_number < 1 || mas[i].semester_number > 3) {
            __fpurge(stdin);
            puts("Invalid input,try again.");
        }
        input_of_marks(mas, array, i);
    }
}

void input_of_marks(student_t * mas, semester_t * array, int i)
{
	int enumeration_of_marks;
    puts("\n----------------- Marks ------------------");
    printf("\nPut marks for %s", mas[i].name);
    printf("%s mark:", array[mas[i].semester_number - 1].exam_1);
    while (!scanf("%d", &mas[i].marks[0]) || mas[i].marks[0] < 1 || mas[i].marks[0] > 10) {
        __fpurge(stdin);
        puts("Invalid input,try again.");
    }
    printf("%s mark:", array[mas[i].semester_number - 1].exam_2);
    while (!scanf("%d", &mas[i].marks[1]) || mas[i].marks[1] < 1 || mas[i].marks[1] > 10) {
        __fpurge(stdin);
        puts("Invalid input,try again.");
    }
    printf("%s mark:", array[mas[i].semester_number - 1].exam_3);
    while (!scanf("%d", &mas[i].marks[2]) || mas[i].marks[2] < 1 || mas[i].marks[2] > 10) {
        __fpurge(stdin);
        puts("Invalid input,try again.");
    }
}

void students_output(student_t * mas, int number_of_students, semester_t * array)   /* output. */
{                               
    int output_number, i;
    int student_output_number = 0, flag = 0;

    puts("\n------------ Output of information ------------");

    puts("\nEnter, please, number of semester for output:");
    do {
        while (!scanf("%d", &output_number) || output_number < 1 || output_number > 3) {
            __fpurge(stdin);
            puts("Invalid input,try again.");
        }
        for (i = 0; i < number_of_students; i++) {
            student_output_number++;
            if (mas[i].semester_number == output_number) {
                printf("\n%d. \n surname: %s name: %s patronymic: %s \n", student_output_number, mas[i].surname, mas[i].name, mas[i].patronymic);
                printf("%s : %d \n", array[output_number - 1].exam_1, mas[i].marks[0]);
                printf("%s : %d \n", array[output_number - 1].exam_2, mas[i].marks[1]);
                printf("%s : %d \n", array[output_number - 1].exam_3, mas[i].marks[2]);
                flag = 1;
            }
        }
        if (flag == 0)
            puts("Invalid input,try again.");
    } while (flag == 0);
}
