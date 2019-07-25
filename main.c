#include <stdio.h>
#include <stdlib.h>
#include "project.h"

int main(){
	char command;
	int i;
	Slist.size = 0;
	printf("##what do you want to do?##  ");
	while(1){
		if ((command = getchar())!= '\n'){
			switch (command){
				case 'a':
					add();
					break;
				case 'd':
					delete_id();
					break;
				case 'f':
					find_id();
					break;
				case 'i':
					input_exam();
					break;
				case 'm':
					modify_id();
					break;
				case 'p':
					print();
					break;
				case 'r':
					read_txt();
					break;
				case 's':
					sort();
					break;

				case 'q':
					exit(1);
					break;
				case 'w':
					write_txt();
					break;
			
			}
		printf("##what do you want to do?##  ");
		}
	
	}
	for (i = 0; i < Slist.size; i++){
	free(Slist.arr[i]);
	}

	return 0;
}
