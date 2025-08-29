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

		const int size=800;int i;int resto;int temp; bool clear =false;int j=2;
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
		int clearing=2;
		bool cleared=false;
		while(!WindowShouldClose()){
				BeginDrawing();
				if(cleared==false)ClearBackground(BLACK);
				if(cleared==true)ClearBackground(WHITE);
				
						
			//	switch(currentScreen)
			//	{
			//			case logo:
			//			{
							if (clearing>0){
								clearing=0;
						//	for(i=1;i<size;i++){
						//				DrawRectangle(i, 1, 1, list[i], RAYWHITE);
						//		}
								for(j=2;j<size;j++){
										DrawRectangle(j, 1, 1, list[j], RAYWHITE);
										resto=list[j-1];
										if (resto > list[j]){
												temp=list[j];
												list[j]=resto;
												list[j-1]=temp;
												clearing++;
										}
										}
								}
								else{
										clear=true;
								}
						
						
						if(clear==true && cleared==false){
								WaitTime(1.0);
								for(i=1;i<size;i++){
										DrawRectangle(i, 1, 1, list[i], GREEN);
								}
								WaitTime(1.0);
								cleared++;
						}
						if(clear==true && cleared==true){
								DrawText("pipopipopipo", (size/2)-50, screenY/2, 20, BLACK);

						}
						EndDrawing();
						}
		
		CloseWindow();

}
