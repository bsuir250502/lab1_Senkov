#include<stdio.h>
#include<stdlib.h>

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
	int n,i1,j,semester,output_number; 
    // n - students, j - semesters, i1 - flag for semester.
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
		printf("Enter information about student, №%d :",i+1);
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
		semester=mas[i].student.semester;
		printf("\nPut marks for %s",mas[i].student.name);
		if (semester == 1) 
			for (i1=0;i1<2;i1++) {			
				printf("%s:\n",exam_1[i1]);
				scanf("%d",&mas[i].marks[i1]);
			} 
		else if (semester == 2) 
			for (i1=0;i1<3;i1++) {			
				printf("%s:\n",exam_2[i1]);
				scanf("%d",&mas[i].marks[i1]);
			} 	
		else if (semester == 3) 
			for (i1=0;i1<4;i1++) {			
				printf("%s:\n",exam_3[i1]);
				scanf("%d",&mas[i].marks[i1]);
			} 	
		else if (semester == 4)
			for (i1=0;i1<5;i1++) {			
				printf("%s:\n",exam_2[i1]);
				scanf("%d",&mas[i].marks[i1]);
			} 	
	}
	printf("Enter number of semester, in which informathion you want to know:");
	scanf("%d",&output_number);
    return 1;
}




