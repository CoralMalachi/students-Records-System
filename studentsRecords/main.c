#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "linkedList.h"

int main(void) 
{
	student* head = NULL;
	
	int run_program = 1;
	int selection;
	while (run_program)
	{
		printf("______________________________________________________________________________________\n");
		printf("|Option Number|                            Description                             |\n");
		printf("|_______________|____________________________________________________________________|\n");
		printf("|       1       |Print Records of all students                                       |\n");
		printf("|       2       |Add student record                                                  |\n");
		printf("|       3       |Delete record(s) of student based on name                           |\n");
		printf("|       4       |Search student record based on name                                 |\n");
		printf("|       5       |Edit student record                                                 |\n");
		printf("|       0       |Exit program                                                        |\n");
		printf("|_______________|____________________________________________________________________|\n");
		printf("\nWhat do you want to do?\n\n");

		scanf("%d", &selection);
		getchar();

		switch (selection)
		{
		case 0:
			//free allocated memory end terminate program
			run_program = 0;
			freeStudents(head);
			break;
		case 1:
			printStudenrsList(head);
			break;
		case 2:
			createStudent(&head);
			break;
		case 3:
			Remove(&head);
			break;
		case 4:
			Search(&head);
			break;
		case 5:
			Edit(&head);
			break;

		default:
			printf("\nERROR: You did not enter a valid input. Please try again.\n\n");
			break;
		}
	}


	return 0;
}