#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomArray(int list[], int size){
	for (int i=0;i < size; i++){
		list[i]=(rand() % (size+1));
		}

}
int main(){
		//setting array
		srand(time(NULL));

		int size;int i;
		printf("insertando tamaño\n");
		scanf("%d", &size);

		int list[size];
		randomArray(list, size);
		
		//el resto

}
