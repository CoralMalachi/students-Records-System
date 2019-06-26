#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "linkedList.h"

#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
char* read_line(char* line) {

	int c;
	line = malloc(sizeof(char));
	//checking if allocation was successful or not
	if (line == NULL)
	{
		printf("%s\n", "Allocation failed");
		exit(1);
	}

	/*
	unsigned type might be seen used as loop variable as loop variables
	are typically greater than or equal to 0
	*/

	size_t i = 0;
	while ((c = getchar()) != '\n' && c != EOF)
	{
		//type casting `int` to `char`, since getchar return int
		line[i] = (char)c;
		i++;
		line = realloc(line, (i + 1) * sizeof(char));
		if (line == NULL) {
			printf("%s\n", "Reallocation failed");
			exit(1);
		}
	}
	//inserting null character at the end
	line[i] = '\0';


	return line;
}

void createStudent(student** head)
{
	student* s = malloc(sizeof(student));
	if (s == NULL)
	{
		printf("unsuccessful Allocation student");
		exit(1);
	}
	(s->name_student) = NULL;
	//char* a = NULL;
	//prevent read_line function refer to the enter after 2 in the menu
	//getchar();
	printf("What is the name of the new student? \n");
 	(s->name_student) = read_line(s->name_student);
	
	s->courses = NULL;
	printf("What is the age of the new student? \n");
	scanf("%u", &(s->age));
	//course* c_head = NULL;
	//getchar();
	int keep = 1;
	while (keep) {
		addCourse(&(s->courses));
		printf("Have more courses? y/n \n");
		getchar();
		char a;
		a = getchar();
		//getchar(); /* takes the enter key */
		if (a == 'n')
			keep = 0;
	}
	PushStudentRecord(head, s);

	
}

void PushStudentRecord(student** head, student* s)
{
	if (*head == NULL) {
		*head = s;
		(*head)->next = NULL;
	}
	else {
		student* cure = *head;
		while (cure->next) {
			cure = cure->next;
		}
		cure->next = s;
		cure->next->next = NULL;
	}
}

void RemoveStudentRecord(student** head, student* s)
{
	student* tmp=NULL;
	//if we need to delete head of list
	if (*head == s) {
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	else
	{
		student* cure = *head;
		while (cure)
		{
			if (cure->next == s) {
				tmp = cure->next;
				cure->next = tmp->next;
				free(tmp);
			}
		}
	}	
}

student* SearchStudentRecord(student** head, char* name_student)
{
	if (*head == NULL) {
		printf("student list is empty \n");
		return NULL;
	}
	else
	{
		student* s = *head;
		while (s)
		{
			if (strcmp(s->name_student, name_student) == 0)
			{
				printf("student found \n");
				return s;
			}
		}
		printf("student is not in list \n");
		return NULL;

	}

	
}

void Remove(student** head)
{
	printf("What is the name of the student? ");
	char* name=NULL;
	name = read_line(name);
	student* s = SearchStudentRecord(head, name);
	if (s == NULL) {
		printf("cant delete, student not in list \n");
	}
	else
	{
		RemoveStudentRecord(head, s);
	}

}

//void Add(student** head)
//{
//
//}

void Search(student** head)
{
	printf("What is the name of the student? ");
	char* name=NULL;
	name = read_line(name);
	student* s = SearchStudentRecord(head, name);
	printStudentRecord(s);

}

void Edit(student** head)
{
	printf("What is the name of the student? ");
	char* name = NULL;
	name = read_line(name);
	student* s = SearchStudentRecord(head, name);
	
	int selection=1;
	while (selection) {
		printf("|_______________|____________________________________________________________________|\n");
		printf("|       1       |Edit name                                                           |\n");
		printf("|       2       |Edit age                                                            |\n");
		printf("|       3       |Edit courses                                                        |\n");
		printf("|       0       |back to menu                                                        |\n");
		printf("|_______________|____________________________________________________________________|\n");
		printf("\nWhat do you want to do?\n\n");
		scanf("%d", &selection);
		getchar();
		switch (selection)
		{
		case 1:
			editName(s);
			break;
		case 2:
			editAge(s);
			break;
		case 3:
			editCorses(s);
		default:
			printf("\nERROR: You did not enter a valid input. Please try again.\n\n");
			break;			
		}
	}

	

}



void editName(student* s)
{
	printf("enter new name \n");
	free(s->name_student);
	s->name_student = NULL;
	(s->name_student) = read_line(s->name_student);
}

void editAge(student* s)
{
}



void editCorses(student* s)
{
}

void printStudentRecord(student* s)
{
	printf("|___________________________________________________________________________________|\n");
	printf("  name: %s \n", s->name_student);
	printf("  age : %u \n", s->age);
	printf("  student courses:  \n");
	printCourses(s->courses);
	
}

void addCourse(course** head)
{
	printf("Enter course name and grade of student if has\n ");
	course* c = malloc(sizeof(course));
	if (c == NULL)
	{
		printf("unsuccessful Allocation course \n");
		exit(1);
	}
	scanf("%s %d", &(c->name_course), &(c->grade));
	if(*head == NULL) {
		*head = c;
		(*head)->next = NULL;
	}
	else {
		course* cure = *head;
		while (cure->next)
		{
			cure = cure->next;
		}
		cure->next = c;
		cure->next->next = NULL;
	}
}

void push(course** head, course* c)
{
}

void printStudenrsList(student* head)
{
	if (head == NULL)
	{
		printf("empty students list \n");
	}
	else
	{
		student* cure = head;
		while (cure)
		{			
			/*printf("|___________________________________________________________________________________|\n");
			printf("  name: %s \n", cure->name_student);
			printf("  age : %d \n", cure->age);
			printf("  student courses:  \n");
			printCourses(cure->courses);*/
			printStudentRecord(cure);
			cure = cure->next;
			
		}
	}
}

void printCourses(course* head)
{
	if (head == NULL)
	{
		printf("student does not have cureses yet \n");
	}
	else
	{
		course* cure = head;

		while (cure)
		{
			printf("******************************************\n");
			printf("course's name: %s \n", cure->name_course);
			printf("course's grade: %d \n", cure->grade);	
			printf("******************************************\n");
			
			cure = cure->next;
		}
	}

}

void freeCourses(course* head)
{
	if (head == NULL)
		return;
	else
	{		
		while (head)
		{
			course* tmp = head;
			head = head->next;
			free(tmp);
		}
	}
}

void freeStudents(student* head)
{
	if (head == NULL)
		return;
	else
	{
		while (head) {
			student* tmp = head;
			head = head->next;
			free(tmp->name_student);
			freeCourses(tmp->courses);
			free(tmp);
		}
	}
}
