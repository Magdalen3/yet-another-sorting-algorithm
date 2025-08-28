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
void imprimirArray(){
			for(i=1;i<size;i++){
								DrawRectangle(i, 1, 1, list[i], RAYWHITE);
			}
}

int main(){
		//setting array
		srand(time(NULL));

		const int size=800;int i;
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
		
		while (!WindowShouldClose()){
				BeginDrawing();
				ClearBackground(BLACK);
				
				//while(int j=1;clear=false
						for(i=1;i<size;i++){
										DrawRectangle(i, 1, 1, list[i], RAYWHITE);
						}

				EndDrawing();
		}
		CloseWindow();

}
