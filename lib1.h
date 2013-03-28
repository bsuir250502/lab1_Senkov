#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

char *input_valid_data()    /* function for checking input infomation (srting). */
{   
    char *input_text; 
    input_text = (char *)malloc(sizeof(char));                        
    do {    
        __fpurge(stdin) 
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

void students_quantity(int *number_of_students)   
{                              
    puts("\nEnter, please,  number of students(max is 30):");
    while (!scanf("%d", &*number_of_students) || *number_of_students < 1) {   
        __fpurge(stdin);
        puts("Invalid input, try again.");
    }
}
