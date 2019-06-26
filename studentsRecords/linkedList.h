
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct courses {

	char name_course[20];
	unsigned int grade;
	struct courses* next;

}course;

typedef struct students {

	char* name_student;
	unsigned int age;
	course* courses;

	struct students* next;

}student;

char* read_line(char* line);
void createStudent(student** head);


void PushStudentRecord(student** head,student* s);
void RemoveStudentRecord(student** head, student* s);
student* SearchStudentRecord(student** head,char* name_student);

void Remove(student** head);
//void Add(student** head);
void Search(student** head);
void Edit(student** head);

void editName(student* s);
void editAge(student* s);
void editCorses(student* s);
void printStudentRecord(student* s);
void addCourse(course** head);
//void push(course** head, course* c);
void printStudenrsList(student* head);
void printCourses(course* head);
void freeCourses(course* head);
void freeStudents(student* head);


#endif