#include "main.h"
#include "util.h"



int main() {
	init();
	while (1) {
		int menuCode = menuDraw(); //�÷��̾� ���� ���� (0,1,2)
		if (menuCode == 0){
			//���� ����

			int SKIPorNOT = Opening_SKIP(); //�÷��̾� ���� ���� (0,1) ~ 0�̸� ��ŵ, 1�̸� ��ŵX

			if (SKIPorNOT == 1) {
				Opening();
			}
			
			Tutorial();
			gLoop();

			return 0;

		}
		else if (menuCode == 1){
			//���� ����
			infoDraw();
		}
		else if (menuCode == 2){
			//����
			return 0;
		}
		system("cls"); //â ���
		setColor(white, black);
	}

	
	


}