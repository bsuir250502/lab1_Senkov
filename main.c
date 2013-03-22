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
void fun_exams_select();
void fun_student(student *,int ,semester *);
void fun_student_output(student *,int ,semester *);

int main () {
	int number_of_students; 
	fun_exams_select();                                   // select exams input.
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

void fun_exams_select() {            //select exam.
	int select, check=0;
	semester array[3];
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

		puts("----------------- Marks ------------------");

		printf("\nPut marks for %s",mas[i].name);
		printf("%s:",array[mas[i].semester_number - 1].exam_1);
		while (!scanf("%d",&mas[i].marks[0]) || mas[i].marks[0]<1 || mas[i].marks[0]>10) {
			__fpurge(stdin);
			puts("Invalid input,try again.");	
		}
		printf("%s:",array[mas[i].semester_number - 1].exam_2);
		while (!scanf("%d",&mas[i].marks[1]) || mas[i].marks[1]<1 || mas[i].marks[1]>10) {
			__fpurge(stdin);
			puts("Invalid input,try again.");	
		}
		printf("%s:",array[mas[i].semester_number - 1].exam_3);
		while (!scanf("%d",&mas[i].marks[2]) || mas[i].marks[2]<1 || mas[i].marks[2]>10) {
			__fpurge(stdin);
			puts("Invalid input,try again.");	
		}					
	}
}

void fun_student_output (student *mas, int number_of_students, semester *array) {
	puts("------------ Output of information ------------");
}


/*
	char exam_1[2][20]={"Math","Arithmetic"};
	char exam_2[3][20]={"Programming","Physics","English"};
	char exam_3[4][20]={"Math","Algorithmization","Programming","History"};
	char exam_4[5][20]={"Physics","Logic","Math","English","Programming"};

	printf("\nEnter number of semester for output:");
	scanf("%d",&output_number);
	for (i=0;i<n;i++) {
		student_output_number ++;
		if (mas[i].student.semester == output_number) 	
		printf("\n%d. \n surname: %s \n name: %s \n patronymic: %s \n",student_output_number,mas[i].student.surname,mas[i].student.name,mas[i].student.patronymic);
		if (mas[i].student.semester == 1) 
			for (i1=0;i1<2;i1++)		
				printf("%s: %d ",exam_1[i1],mas[i].marks[i]);
		else if (mas[i].student.semester == 2) 
			for (i1=0;i1<3;i1++) 			
				printf("\n%s: %d",exam_2[i1],mas[i].marks[i]);
		else if (mas[i].student.semester == 3) 
			for (i1=0;i1<4;i1++) 			
				printf("\n%s: %d",exam_3[i1],mas[i].marks[i]);
		else if (mas[i].student.semester == 4)
			for (i1=0;i1<5;i1++) 		
				printf("\n%s: %d",exam_4[i1],mas[i].marks[i]);
	}
    return 0;
}
*/




