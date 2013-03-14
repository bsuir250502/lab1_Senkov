#include<stdio.h>
#include<stdlib.h>

struct people {
	char surname[50];
	char name[50];
	char patronymic[50];
	int semester;
};

struct university {
	struct people student ;
	/*union b {
		int i; 
		char ch;
	};*/
};

int main () {
	int i,j,n;
	char exam_1[2][20]={"Math","Arithmetic"};
	char exam_2[3][20]={"Programming","Physics","English"};
	char exam_3[4][20]={"Math","Algorithmization","Programming","History"};
	char exam_4[4][20]={"Physics","Logic","Math","English"};
	puts("\nEnter, please,  number of students and semesters (in series)");
	puts("students: max-30, min-1.\n semesers: max-4, min-1\ninput:"); 
	scanf("%d %d",&n,&j); // n - students, j - semesters.
 	struct university mas[n];
 	for (i=0;i<n;i++) {
		printf("Enter information about student, №%d :",i+1);
		puts("\nsurname: ");
		__fpurge(stdin);
		fgets(mas[i].student.surname,50,stdin) ;
		puts("name: ");
		fgets(mas[i].student.name,50,stdin) ;
		puts("patronymic: ");
		fgets(mas[i].student.patronymic,50,stdin) ;
		printf("Enter number of semeser(max is %d): ",j);
		scanf("%d",&mas[i].student.semester);
	}
    return 1;
}
