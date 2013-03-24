#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

typedef struct semester {
	char *exam_1;
	char *exam_2;
	char *exam_3;
} semester;

typedef struct student {
	char *surname;
	char *name;
	char *patronymic;
	int semester_number;
	int marks[3];
} student;

void fun_students_quantity (int *);
char* fun_check_input();
void fun_exams_filling(semester *);
void fun_exams_automat(semester *);
void fun_exams_select(semester *);
void fun_student_input(student *,int ,semester *);
void fun_student_output(student *,int ,semester *);

int main () {
	int number_of_students;
	semester array[3]= {
	{"Math","Arithmetic","History"},
	{"Programming","Physics","English"} ,
	{"Math","Algorithmization","Programming"},
	};                            
	fun_exams_select(array);                              // select exams input.
	fun_students_quantity (&number_of_students);          // input number_of_student.
 	student mas[number_of_students];	                  // create of array for students.	
	fun_student_input (mas,number_of_students,array);     // input information about students.
	fun_student_output (mas,number_of_students,array);    // output.
	return 0;
}

char* fun_check_input() {	// function for checking input infomation (srting).
	char *input_text;
	input_text = (char*)malloc(30*sizeof(char));
	do {
		__fpurge(stdin);
		fgets(input_text, 30, stdin);
		if (input_text[0] == '\n' || input_text[0]=='0' || input_text[0]=='9') { 
			puts("Invalid input, try again.");			
			continue;
		}
		else if (input_text[0]>'0' && input_text[0]<'9') {
			puts("Invalid input, try again.");			
			continue;		
		}
		else
			break;	
	} while (1);
	return input_text;
}
	
void fun_students_quantity (int *number_of_students) {  // function for input number of students. 
	puts("\nEnter, please,  number of students:");
	while (!scanf("%d",& *number_of_students) || *number_of_students<1) {   // n - number of students.
		__fpurge(stdin);
		puts("Invalid input, try again.");	
	}
}

void fun_exams_automat (semester *array) {       // automat input of exams.
	puts("\nList of exams:");
	for (int i=0;i<3;i++) {
		printf(" %d semester:\n",i+1);
		puts(array[i].exam_1);
		puts(array[i].exam_2);
		puts(array[i].exam_3);
	}		
}

void fun_exams_filling (semester *array) {                  // clever input of exams.
	puts("Enter, please, exams for 3 semesters:");
	for (int i=0;i<3;i++) {
		printf("Information about semester number %d)",i+1);
		__fpurge(stdin);
		puts("\n1 exam: ");
		array[i].exam_1=fun_check_input();
		puts("2 exam: ");
		array[i].exam_2=fun_check_input();
		puts("3 exam: ");
		array[i].exam_3=fun_check_input();
	}
}

void fun_exams_select(semester * array) {            //select exam.
	int select, check=0;
	puts("\nSelect type of exams input:\n1)automatic input.\n2)clever input.");
	while (check==0) {
		scanf("%d",&select);	
		switch (select) {
			case 1: 
				fun_exams_automat(array);
				check=1;
				break;
			case 2: 
				fun_exams_filling(array);
				check=1;
				break;
			default:
				puts("Invalid input, try again.");
		}
	}
}

void fun_student_input (student *mas, int number_of_students, semester *array) {       // input of all informaion about student.
	for (int i=0;i<number_of_students;i++) {
		printf("\nInformation about student number %d)",i+1);
		__fpurge(stdin);
		puts("\nsurname: ");
		mas[i].surname=fun_check_input();
		puts("name: ");
		mas[i].name=fun_check_input();
		puts("patronymic: ");
		mas[i].patronymic=fun_check_input();
		puts("Enter number of semester(max is 3): ");
		while (!scanf("%d",&mas[i].semester_number) || mas[i].semester_number<1 || mas[i].semester_number>3 ) {
			__fpurge(stdin);
			puts("Invalid input,try again.");		
		}

		puts("\n----------------- Marks ------------------");

		printf("\nPut marks for %s",mas[i].name);
		printf("%s mark:",array[mas[i].semester_number - 1].exam_1);
		while (!scanf("%d",&mas[i].marks[0]) || mas[i].marks[0]<1 || mas[i].marks[0]>10) {
			__fpurge(stdin);
			puts("Invalid input,try again.");	
		}
		printf("%s mark:",array[mas[i].semester_number - 1].exam_2);
		while (!scanf("%d",&mas[i].marks[1]) || mas[i].marks[1]<1 || mas[i].marks[1]>10) {
			__fpurge(stdin);
			puts("Invalid input,try again.");	
		}
		printf("%s mark:",array[mas[i].semester_number - 1].exam_3);
		while (!scanf("%d",&mas[i].marks[2]) || mas[i].marks[2]<1 || mas[i].marks[2]>10) {
			__fpurge(stdin);
			puts("Invalid input,try again.");	
		}					
	}
}

void fun_student_output (student *mas, int number_of_students, semester *array) { // output.
	int output_number;
	int student_output_number=0, flag=0;

	puts("\n------------ Output of information ------------");

	puts("\nEnter, please, number of semester for output:");
	do {	
		while (!scanf("%d",&output_number) || output_number<1 || output_number>3) {
				__fpurge(stdin);
				puts("Invalid input,try again.");
		}
		for (int i=0;i<number_of_students;i++) {
			student_output_number ++;
			if (mas[i].semester_number == output_number) {	
				printf("\n%d. \n surname: %s name: %s patronymic: %s \n",student_output_number,mas[i].surname,mas[i].name,mas[i].patronymic);	
				printf("%s : %d \n",array[output_number-1].exam_1,mas[i].marks[0]);
				printf("%s : %d \n",array[output_number-1].exam_2,mas[i].marks[1]);
				printf("%s : %d \n",array[output_number-1].exam_3,mas[i].marks[2]);	
				flag=1;
			}
		}	
		if (flag==0) puts("Invalid input,try again.");
	} while (flag==0);
}




