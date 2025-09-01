#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>
#include <stdbool.h>
#include "header.h"
#define SCREENX 800
#define SCREENY 800

void randomArray(int list[], int size){
	for (int i=0;i < size; i++){
		list[i]=(rand() % (size+1));
		}
}



int main(){
		size=800;clearing=2;clear=false;cleared=false;int greenTimer=0;
		srand(time(NULL));
		if(size <= 0)return 1;
		int list[size];
		InitWindow(SCREENX, SCREENY, "segmentation fault");
		SetTargetFPS(60);
		while(!WindowShouldClose()){
				BeginDrawing();
				if(cleared==false)ClearBackground(BLACK);
				if(cleared==true)ClearBackground(WHITE);
				switch(mode)
				{
						case 0:{
						DrawText("select sorting algorithm", (SCREENX/2)-100, (SCREENY/2)-20, 20, BLACK);
						DrawText("press [1] to bubble", (SCREENX/2)-70, SCREENY/2, 20, BLACK);
						cleared=true;
						if (IsKeyPressed(KEY_ONE)) {
						mode = 1;
						cleared=false;
						clearing=2;
						randomArray(list, size);
						}
						break;
						}

						case 1:{
						if (clearing>0){
								clearing=0;
								for(j=1;j<size;j++){
										DrawRectangle(j, 800-list[j], 1, list[j], RAYWHITE);											
										prev=list[j-1];
										if (prev > list[j]){
												temp=list[j];
												list[j]=prev;
												list[j-1]=temp;
												clearing++;
												}
										}
								}
							else{
								mode=6;
								i=1;
								}
								break;
						}
						case 6:{
								for (i=1;i<size;i++){
								DrawRectangle(i, 800 - list[i], 1, list[i], GREEN);
								}
								//i++;
								//if(i==800){
								greenTimer++;
								if (greenTimer > 200) {
								mode=0;
								}
								
								break;
							   }
				}
		
						
		EndDrawing();
		}
		
		CloseWindow();

}
