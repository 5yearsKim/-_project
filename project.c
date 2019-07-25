#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "project.h"

void add(void){
	int id, birth;
	char name[10];
	printf("id number? ");
	scanf("%d",&id);
	printf("birth date?(ex:19990101) ");
	scanf("%d",&birth);
	printf("name? ");
	scanf("%s",name);
	
	add_student(id, name, birth);

}
void add_student(int id, char *name, int birth){
	struct student *s1 = malloc(sizeof(struct student));
	strcpy(s1->name , name);
	s1->id = id;
	s1->birth = birth;
	
	Slist.arr[Slist.size++] =s1; 
}

void delete_id(void){
	int id, i, j;
	int found = false;
	printf("id number that you want to delete = ");
	scanf("%d",&id);
	for (i = 0; i<Slist.size; i++){
		if (Slist.arr[i]->id == id){
			found = true;
			break;
		}
	}
	if (found == true){
		free(Slist.arr[i]);
		for (j = i; j<Slist.size-1; j++){
			Slist.arr[j] = Slist.arr[j+1];
		}
		Slist.size--;
		
		grade();
	}
	else {
		printf("%d is not found\n",id);
	}

}

void find_id(){
	int id, i;
	int found = false;
	printf("id number that you want to find = ");
	scanf(" %d",&id);
	for (i = 0; i<Slist.size; i++){
		if (Slist.arr[i]->id == id){
			found = true;
			break;
		}
	}
	if (found == true){

		printf("index     id           name    birthday   mid fin avg\n");
		printf("%3d:  %8d %10s  %8d   %2d  %2d  %3.1f\n",
				i,
				Slist.arr[i]->id,
				Slist.arr[i]->name,
				Slist.arr[i]->birth,
				Slist.arr[i]->mid,
				Slist.arr[i]->fin,
				Slist.arr[i]->avg );
	}
	else{
		printf("%d is not found\n",id);
	}	

}

void input_exam(){
	char mode;
	int i;
	printf("midterm(m) or final(f)? ");
	scanf(" %c", &mode);
	if (mode =='m'){
		for (i = 0; i< Slist.size; i++){
			printf("%d : ",Slist.arr[i]->id);
			scanf(" %d",&Slist.arr[i]->mid);		
			Slist.arr[i]->avg = ((float)Slist.arr[i]->mid + (float)Slist.arr[i]->fin )/2;
		}
	}
	else {
		for (i = 0; i< Slist.size; i++){
			printf("%d : ",Slist.arr[i]->id);
			scanf(" %d",&Slist.arr[i]->fin);		
			Slist.arr[i]->avg = ((float)Slist.arr[i]->mid + (float)Slist.arr[i]->fin )/2;
		}
	
	}

	grade();


}

void modify_id(){
	char mode;
	int i, id;
	int found = false;

	printf("id number that you want to find = ");
	scanf(" %d",&id);
	for (i = 0; i<Slist.size; i++){
		if (Slist.arr[i]->id == id){
			found = true;
			break;
		}
	}
	if (found == true){
		printf("midterm(m) or final(f)? ");
		scanf(" %c", &mode);
		if (mode == 'm'){
			printf("new midterm score is?");
			scanf(" %d", &Slist.arr[i]->mid);
			Slist.arr[i]->avg = ((float)Slist.arr[i]->mid + (float)Slist.arr[i]->fin )/2;
		}	
		else if (mode == 'f'){
			printf("new final score is?");
			scanf(" %d", &Slist.arr[i]->fin);
			Slist.arr[i]->avg = ((float)Slist.arr[i]->mid + (float)Slist.arr[i]->fin )/2;
		}

		printf("index     id          name  birthday   mid fin avg \n");
		printf("%3d:  %8d %10s  %8d   %2d  %2d  %3.1f \n",
				i,
				Slist.arr[i]->id,
				Slist.arr[i]->name,
				Slist.arr[i]->birth,
				Slist.arr[i]->mid,
				Slist.arr[i]->fin,
				Slist.arr[i]->avg);
		grade();
	}
	else{
		printf("%d is not found\n",id);
	}	


}

void print(void){
	int i;
	printf("index     id           name  birthday   mid fin avg\n");
	for (i = 0; i<Slist.size; i++){
		
		printf("%3d:  %8d %10s  %8d   %2d  %2d  %3.1f  %c ",
				i+1,
				Slist.arr[i]->id,
				Slist.arr[i]->name,
				Slist.arr[i]->birth,
				Slist.arr[i]->mid,
				Slist.arr[i]->fin,
				Slist.arr[i]->avg,
				Slist.arr[i]->grade);
		printf("\n");
	}

}


void read_txt(){
	FILE *fp;
	char buf[50];
	char id[10], name[10], birth[10];
	int inc = 0;
	char *ptr;

	fp = fopen("students.txt","r");
	if(fp !=NULL){
		while(!feof(fp)){
			if (fgets(buf,sizeof(buf),fp) == NULL){ 
				break;
			}
			inc = 0;
			ptr = strtok(buf, " ");  
			while (ptr != NULL)               
			{	
				if (inc ==0){
					strcpy(id,ptr);
				}
				else if(inc == 1){
					strcpy(name,ptr);
				}
				else if(inc == 2){
					strcpy(birth,ptr);
				}
				inc++;
				ptr = strtok(NULL, " ");  
			}
			add_student(atoi(id), name, atoi(birth)); 
		}
	
	}
}

void sort(){
	char mode;
	printf("sort with name(n), avg(a), grade(g)?  ");
	scanf(" %c", &mode);
	sort_mode(mode);

}

void sort_mode(char mode){
	int loop, i;
	if (mode == 'n'){
		for (loop = 0; loop < Slist.size - 1; loop++) {
		    for (i = 0; i < Slist.size - 1 - loop; i++) {
				if (strcmp(Slist.arr[i]->name,Slist.arr[i+1]->name) > 0) {
					swap(i,i+1);
				}
			}
		}
	}

	
	else {
		for (loop = 0; loop < Slist.size - 1; loop++) {
		    for (i = 0; i < Slist.size - 1 - loop; i++) {
				if (Slist.arr[i]->avg < Slist.arr[i+1]->avg) {
					swap(i,i+1);
				}
			}
		}
	}

}

void write_txt(){
	FILE *fp;
	int i;
	fp = fopen("new_students.txt","w");
	for (i = 0; i<Slist.size; i++){	
	fprintf(fp,"%3d:  %8d %10s  %8d   %2d  %2d  %3.1f  %c \n",
			i+1,
			Slist.arr[i]->id,
			Slist.arr[i]->name,
			Slist.arr[i]->birth,
			Slist.arr[i]->mid,
			Slist.arr[i]->fin,
			Slist.arr[i]->avg,
			Slist.arr[i]->grade);
	printf("%3d:  %8d %10s  %8d   %2d  %2d  %3.1f  %c \n",
			i+1,
			Slist.arr[i]->id,
			Slist.arr[i]->name,
			Slist.arr[i]->birth,
			Slist.arr[i]->mid,
			Slist.arr[i]->fin,
			Slist.arr[i]->avg,
			Slist.arr[i]->grade);
	

	}
	fclose(fp);
}

void swap(int i, int j){
	struct student *temp = Slist.arr[i];
	Slist.arr[i] = Slist.arr[j];
	Slist.arr[j] = temp;
}

void grade(){
	int i;
	sort_mode('a');
	for (i = 0; (float)i<(float)Slist.size * 0.35 ; i++ ){
		Slist.arr[i]->grade = 'A';
	}
	for ( ; (float)i<(float)Slist.size * 0.7 ; i++ ){
		Slist.arr[i]->grade = 'B';
	}
	for ( ; (float)i<(float)Slist.size * 0.9 ; i++ ){
		Slist.arr[i]->grade = 'C';
	}	
	for ( ; (float)i<(float)Slist.size * 0.95 ; i++ ){
		Slist.arr[i]->grade = 'D';
	}
	for ( ; (float)i<(float)Slist.size  ; i++ ){
		Slist.arr[i]->grade = 'F';
	}


}
