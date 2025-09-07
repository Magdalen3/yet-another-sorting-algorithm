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
	int size;
	int arraySorting; //if the array completed the sorting it should be 0 or 1, if it isn't, is still sorting
	int drawSize; int i;int prev;int temp;int j;bool clear;
	int caseCleared;
	int selectMode; //selecting mode
	options_t mode;	//the mode that was selected
	size=800;arraySorting=2;caseCleared=false;int green_i = 0;
	srand(time(NULL));
	if(size <= 0)return 1;
	int list[size];
	InitWindow(SCREENX, SCREENY, "segmentation fault");
	SetTargetFPS(60);

	//explaining modes
	//mode 0 start menu
	//mode 1 bubble sorting
	//the rest of the modes to be programmed
	//mode 6 just an "animation" of the array
	//
	while(!WindowShouldClose()){
		BeginDrawing();
		if(caseCleared==false)ClearBackground(BLACK);
		if(caseCleared==true)ClearBackground(WHITE);
		if(mode!=START_MENU){
				for(int k = 0;k<size;k++){
					DrawRectangle(k, 800 - list[k], 1, list[k], RAYWHITE);
				}
		}
		switch(mode){
			case START_MENU:{
				DrawText("select sorting algorithm", (SCREENX/2)-100, (SCREENY/2)-20, 20, BLACK);
				DrawText("press [1] to bubble", (SCREENX/2)-70, SCREENY/2, 20, BLACK);
				DrawText("press [2] to gnome", (SCREENX/2)-70, (SCREENY/2)+20, 20, BLACK);
		
				caseCleared=true;
				if (IsKeyPressed(KEY_ONE)) {
					mode = BUBBLE_SORTING;
					caseCleared=false;
					arraySorting=2;
					randomArray(list, size);
				}
				if (IsKeyPressed(KEY_TWO)) {
					mode = GNOME_SORTING;
					caseCleared=false;
					i=1;
					green_i = 0;
					arraySorting=2;
					randomArray(list, size);
				}
				break;
			}

			case BUBBLE_SORTING:{
				green_i = 0;
				if (arraySorting==0){
					mode = ANIMATION;
					break;
				}
				arraySorting=0;
				for(j=1;j<size;j++){
					prev=list[j-1];
					if (prev > list[j]){
						temp=list[j];
						list[j]=prev;
						list[j-1]=temp;
						arraySorting++;
					}
				}
				break;
			}
			case GNOME_SORTING:{
				clear=0;
				for(int k = 0; k<arraySorting;k++){
					if (list[i] >= list[i-1]) {
						i++;
					}
					else {
						temp = list[i];
						list[i] = list[i-1];
						list[i-1] = temp;
						if (i > 1) i--;
					}	
				}
				if(arraySorting<size){
					arraySorting++;
				}
				else{
					mode = ANIMATION;
				}

				break;
			}
			case ANIMATION:{
				for(int k = 0;k<green_i;k++){
					DrawRectangle(k, 800 - list[k], 1, list[k], GREEN);
				}
				green_i+=8;
				if (green_i >= size) {
					mode = START_MENU;
				}
				break;
			}
		}			
	EndDrawing();
	}
	CloseWindow();
}
