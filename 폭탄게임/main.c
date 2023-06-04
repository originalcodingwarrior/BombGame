#include "main.h"
#include "util.h"



int main() {
	init();
	while (1) {
		int menuCode = menuDraw(); //플레이어 선택 저장 (0,1,2)
		if (menuCode == 0){
			//게임 시작

			int SKIPorNOT = Opening_SKIP(); //플레이어 선택 저장 (0,1) ~ 0이면 스킵, 1이면 스킵X

			if (SKIPorNOT == 1) {
				Opening();
			}
			
			Tutorial();
			gLoop();

			return 0;

		}
		else if (menuCode == 1){
			//게임 정보
			infoDraw();
		}
		else if (menuCode == 2){
			//종료
			return 0;
		}
		system("cls"); //창 비움
		setColor(white, black);
	}

	
	


}