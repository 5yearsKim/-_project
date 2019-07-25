#ifndef __pj__
#define __pj__

#define true 1
#define false 0

#include <stdio.h>


struct student{
	int id;
	char name[10];
	int birth; //birth date
	int mid, fin;
	float avg;
	char grade;
};

struct slist{
	struct student *arr[25];
	int size;
};

struct slist Slist;


void add(void);
void add_student(int id, char *name, int birth);
void find_id();
void input_exam();
void delete_id();
void read_txt();
void print(void);
void sort();
void sort_mode(char mode);

void grade();
void swap(int i, int j);
#endif
