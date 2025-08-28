#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>
#include <stdbool.h>

void randomArray(int list[], int size){
	for (int i=0;i < size; i++){
		list[i]=(rand() % (size+1));
		}
}

int main(){
		//setting array
		srand(time(NULL));

		const int size=800;int i;int resto;int temp; bool clear =false;
		printf("insertando tamaño\n");
		//scanf("%d", &size);
		if(size <= 0)return 1;
		printf("%d\n", size);

		int list[size];
		randomArray(list, size);
		
		//el resto
		const int screenY=600;
		InitWindow(size, screenY, "segmentation fault");

		SetTargetFPS(60);
		
		while(!WindowShouldClose()){
				BeginDrawing();
				ClearBackground(BLACK);
				
				do{		
						for(i=1;i<size;i++){
								DrawRectangle(i, 1, 1, list[i], RAYWHITE);
						}
						for(int j=2;j<size;j++){
						resto=list[j-1];
								if (resto > list[j]){
										temp=list[j];
										list[j]=resto;
										list[j-1]=temp;
								}
						}

				}while(clear=false);

				EndDrawing();
		}
		CloseWindow();

}
