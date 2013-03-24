#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

typedef struct semester {
	char exam_1[30];
	char exam_2[30];
	char exam_3[30];
} semester;

typedef struct student {
	char surname[40];
	char name[40];
	char patronymic[40];
	int semester_number;
	int marks[3];
} student;

void fun_students_quantity (int *);
void fun_exams_filling(semester *);
void fun_exams_automat(semester *);
void fun_exams_select(semester *);
void fun_student_input(student *,int ,semester *);
void fun_student_output(student *,int ,semester *);

int main () {
	int number_of_students;
	semester array[3];                                     
	fun_exams_select(array);                              // select exams input.
	fun_students_quantity (&number_of_students);          // input number_of_student.
 	student mas[number_of_students];	                  // create of array for students.	
	fun_student_input (mas,number_of_students,array);     // input information about students.
	fun_student_output (mas,number_of_students,array);    // output.
	return 0;
}

void fun_students_quantity (int *number_of_students) {  // function for input number of students. 
	puts("\nEnter, please,  number of students:");
	while (!scanf("%d",& *number_of_students) || *number_of_students<1) {   // n - number of students.
		__fpurge(stdin);
		puts("Invalid input, try again.");	
	}
}

void fun_exams_automat (semester *array) {
	/*array[0]={"Math","Arithmetic","History"};
	array[1]={"Programming","Physics","English"};
	array[2]={"Math","Algorithmization","Programming"};*/
	
}

void fun_exams_filling (semester *array) {                  // clever input of exams.
	puts("Enter, please, exams for 3 semesters:");
	for (int i=0;i<3;i++) {
		printf("Information about semester number %d)",i+1);
		__fpurge(stdin);
		puts("\n1 exam: ");
		fgets(array[i].exam_1,30,stdin) ;
		puts("2 exam: ");
		fgets(array[i].exam_2,30,stdin) ;
		puts("3 exam: ");
		fgets(array[i].exam_3,30,stdin) ;
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

void fun_student_input (student *mas, int number_of_students, semester *array) {       // all informaion about student.
	for (int i=0;i<number_of_students;i++) {
		printf("\nInformation about student number %d)",i+1);
		__fpurge(stdin);
		puts("\nsurname: ");
		fgets(mas[i].surname,40,stdin) ;
		puts("name: ");
		fgets(mas[i].name,40,stdin) ;
		puts("patronymic: ");
		fgets(mas[i].patronymic,40,stdin) ;
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

void fun_student_output (student *mas, int number_of_students, semester *array) {
	int output_number;
	int student_output_number=0;
	puts("\n------------ Output of information ------------");
	puts("\nEnter, please, number of semester for output:");
	while (!scanf("%d",&output_number) || output_number<1 || output_number>3) {
			__fpurge(stdin);
			puts("Invalid input,try again.");
	}
	for (int i=0;i<number_of_students;i++) {
		student_output_number ++;
		if (mas[i].semester_number == output_number) {	
			printf("\n%d. \n surname: %s name: %s patronymic: %s \n",student_output_number,mas[i].surname,mas[i].name,mas[i].patronymic);	
			printf("%s mark: %d \n",array[output_number-1].exam_1,mas[i].marks[0]);
			printf("%s mark: %d \n",array[output_number-1].exam_2,mas[i].marks[1]);
			printf("%s mark: %d \n",array[output_number-1].exam_3,mas[i].marks[2]);	
		}
	}	
}




