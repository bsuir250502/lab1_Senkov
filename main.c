#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

//int semester(int ,struct student mas[i],int ); 

struct people {
	char surname[30];
	char name[30];
	char patronymic[30];
	int semester;
};

struct university {
	struct people student ;
	int marks[4];
};

int main () {
	int i,n,i1,j,output_number,student_output_number=0; 
    // n - students, j - semesters, i1 - flag for semester
	//puts("\nSelect: 1)automatic input of exams.\n   2)clever input.\nEnter 1 or 2:");
	char exam_1[2][20]={"Math","Arithmetic"};
	char exam_2[3][20]={"Programming","Physics","English"};
	char exam_3[4][20]={"Math","Algorithmization","Programming","History"};
	char exam_4[5][20]={"Physics","Logic","Math","English","Programming"};
	puts("\nEnter, please,  number of students and semesters (in series)");
	puts("students: max-30, min-1.\nsemesers: max-4, min-1.\ninput:"); 
	scanf("%d %d",&n,&j); // n - students, j - semesters.
 	struct university mas[n];
 	for (i=0;i<n;i++) {
		printf("Enter information about student, number %d :",i+1);
		puts("\nsurname: ");
		__fpurge(stdin);
		fgets(mas[i].student.surname,30,stdin) ;
		puts("name: ");
		fgets(mas[i].student.name,30,stdin) ;
		puts("patronymic: ");
		fgets(mas[i].student.patronymic,30,stdin) ;
		//semester(i,mas,j);
		printf("Enter number of semester(max is %d): ",j);
		scanf("%d",&mas[i].student.semester);
		printf("\nPut marks for %s",mas[i].student.name);
		if (mas[i].student.semester == 1) 
			for (i1=0;i1<2;i1++) {			
				printf("%s:\n",exam_1[i1]);
				scanf("%d",&mas[i].marks[i1]);
			} 
		else if (mas[i].student.semester == 2) 
			for (i1=0;i1<3;i1++) {			
				printf("%s:\n",exam_2[i1]);
				scanf("%d",&mas[i].marks[i1]);
			} 	
		else if (mas[i].student.semester == 3) 
			for (i1=0;i1<4;i1++) {			
				printf("%s:\n",exam_3[i1]);
				scanf("%d",&mas[i].marks[i1]);
			} 	
		else if (mas[i].student.semester == 4)
			for (i1=0;i1<5;i1++) {			
				printf("%s:\n",exam_4[i1]);
				scanf("%d",&mas[i].marks[i1]);
			} 	
	}
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




