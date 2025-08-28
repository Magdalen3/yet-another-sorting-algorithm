#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>

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
		if(size <= 0)return 1;
		printf("%d\n", size);

		int list[size];
		randomArray(list, size);
		
		//el resto
		const int screenX =800; const int screenY=600;
		InitWindow(screenX, screenY, "segmentation fault");

		SetTargetFPS(60);
		
		while (!WindowShouldClose()){
				BeginDrawing();

						ClearBackground(RAYWHITE);

						DrawText("lol lmao\n",190, 200, 20, LIGHTGRAY);
				EndDrawing();
		}
		CloseWindow();

}
