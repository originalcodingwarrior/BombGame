#include "game.h"
#include "util.h"


char map[21][65] = {
	{"1111111111111111111111111111111111111111111111111111111111"},
	{"1000000000000000000000000000000000000000000000001000000001"},
	{"1000000000000000000000000000000000000000000000001000000001"},
	{"1000000000000000000000000000000000000000000000001000000001"},
	{"1000000000000000000000001111111111111111000000001000000001"},
	{"1000000000000001000000000000000000000001000000000000000001"},
	{"1000000000000001000000000000000000000001000000000000000001"},
	{"1000000000000001000000000000000000000001000000000000000001"},
	{"1000000001111111111111111111100000000001111111111000000001"},
	{"1000000000000000000000000000000000000000000000000000000001"},
	{"1000000000000000000000000s00000000000000000000000000000001"},
	{"1000000000000000000000000000000000000000000000000000000001"},
	{"1111111111100000000010000000000001111111111111111000000001"},
	{"1000000000000000000010000000000000000000000000001000000001"},
	{"1000000000000000000010000000000000000000000000001000000001"},
	{"1000000000000000000010000000000000000000000000001000000001"},
	{"1000000000011111111110000000011111111110000000001000000001"},
	{"1000000000000000000000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000000000000000000000001"},
	{"1111111111111111111111111111111111111111111111111111111111"}

};  //���� ���� �̸� �ۼ��س��� ��

int keyControl() {
	char temp = _getch(); //_getch = �Էµ� Ű���� ��� ��ȯ ~ Ű�Է¿� ���

	if (temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 'a' || temp == 'A') {
		return LEFT;
	}
	else if (temp == 's' || temp == 'S') {
		return DOWN;
	}
	else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	}
	else if (temp == ' ') {
		return SUBMIT;
	}


}



int menuDraw() {

	setColor(lightblue, black);
	printf("\n\n\n\n");
	printf("             :::::::::   ::::::::  ::::    ::::  ::::::::: \n");
	printf("             :+:    :+: :+:    :+: +:+:+: :+:+:+ :+:    :+: \n");
	printf("             +:+    +:+ +:+    +:+ +:+ +:+:+ +:+ +:+    +:+ \n");
	printf("             +#++:++#+  +#+    +:+ +#+  +:+  +#+ +#++:++#+  \n");
	printf("             +#+    +#+ +#+    +#+ +#+       +#+ +#+    +#+ \n");
	printf("             #+#    #+# #+#    #+# #+#       #+# #+#    #+# \n");
	printf("             #########   ########  ###       ### #########  \n");
	printf("\n\n");
	setColor(white, black);
	printf("                      <���轼�� õ�� ���� ����>");

	setColor(white, black);

	gotoxy(0, 17);
	printf("     W: ��\n");
	printf("     S: �Ʒ�\n");
	printf("     SPACE: ����");

	setColor(yellow, black);

	int x = 30;
	int y = 15;
	gotoxy(x - 2, y); // '>' ����� ���� x�� -2
	printf("> ���ӽ���");
	gotoxy(x, y + 1);
	printf("��������");
	gotoxy(x, y + 2);
	printf("  ����  ");

	while (1) {
		// �÷��̾��� Ű ���ۿ� ���� '>' ��ġ ����

		int n = keyControl(); //�Է� ���� Ű ����
		switch (n) {
		case UP: {
			if (y > 15) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 17) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			return y - 15;
			//�÷��̾� ���ÿ� ���� ���� �ٸ� �� ��ȯ
			//���� ���� : 0, ���� ���� : 1, ���� : 2
			//menuCode ������ ����� ����
		}

		}
	}

}

void infoDraw() {
	system("cls");
	printf("\n\n");
	printf("                        [ ���۹� ]\n\n");
	printf("                    �̵� : W, A, S, D\n");
	printf("                    ���� : �����̽���\n\n\n\n\n\n");
	printf("       �����̽��ٸ� ������ ����ȭ������ �̵��մϴ�.");

	while (1) {
		if (keyControl() == SUBMIT) {
			break; //�����̽��� ������ �Լ� ������������
		}
	}
}

int drawMap(int* x, int* y) {

	srand(time(NULL)); // ������Ʈ �������� ��ġ�ϱ� ���� ���� ����

	system("cls");
	int h, w; //����, ����
	int Bomb = 0;

	for (h = 0; h < 21; h++) {
		for (w = 0; w < 65; w++) {

			char temp = map[h][w]; // �� �� ĭ �� ĭ �о����

			//'0'���� �� ���� �Ǵ� ��ź �Ǵ� ȸ����
			if (temp == '0') {
				
				int BOMBorHorNOT = rand() % 100; //��ź���� ��Ʈ���� �� �������� �������� ����������

				if (BOMBorHorNOT <= 2) {
					setColor(lightred, black);
					printf("o");
					map[h][w] = 'b'; // '0'���� 'b'�� �� ���� �ٲٱ� ( ��ź �ڸ� ��� )
					Bomb++; //������ ��ź �� +1
				}

				else if (BOMBorHorNOT > 2 && BOMBorHorNOT <= 4) {
					setColor(lightgreen, black);
					printf("*");
					map[h][w] = 'h'; //'0'���� 'h'�� �� ���� �ٲٱ� ( ȸ���� �ڸ� ��� )
				}

				else {
					setColor(black, black);
					printf(" ");
				}
				
			} 

			//'1'���� ��
			else if (temp == '1') {
				setColor(white, white);
				printf("#");
			}

			//'s'���� �÷��̾�
			else if (temp == 's') {

				*x = w;
				*y = h;
				//�÷��̾� ��ġ ����

				setColor(cyan, black);
				printf("��");
			}
		}
		printf("\n");
	}
	setColor(white, black);

	return Bomb;
	// ������ ��ź ���� ��ȯ

}

int drawPerson() {

	srand(time(NULL)); // �������� ��ġ�ϱ� ���� ���� ����

	int h, w; //����, ����
	int Person = 0;

	for (h = 0; h < 21; h++) {
		for (w = 0; w < 65; w++) {

			char temp = map[h][w]; //�� �� ĭ �� ĭ �о����

			//'0'�̸� ���
			if (temp == '0') {

				int PorNOT = rand() % 100; //������� �ƴ��� �������� ����������

				if (PorNOT <= 0) {
					setColor(yellow, black);
					gotoxy(w, h); //�ش� ��ġ�� ���� -> �̰� �� �ϸ� ������ ���� �׷���
					printf("��"); //���
					map[h][w] = 'p'; // '0'���� 'p'�� �� ���� �ٲٱ� ( ��� ��ġ ��� )
					Person++; //������ ��� �� +1
				}
			}
		}
		printf("\n");
	}
	setColor(white, black);

	return Person;
	//������ ��� �� ��ȯ
}

int gLoop() {
	int x, y; //�÷��̾� ��ǥ ���� ����

	int playing = 1; //1�̸� ���� ��, 0�̸� ���� ����

	int Bomb = drawMap(&x, &y); // �� ���� �� ���
	//�ʿ� ��ǥ ������ ����
	//������ ��ź ���� �ޱ�
	
	int Person = drawPerson(); // ��� ����
	//������ ��� �� �ޱ�

	int Walking = (Bomb + Person) * 3; // ���� �� ����


	//���� ����
	while (playing) {

		if ((Bomb == 0 && Person == 0) || (Walking == 0)) {
			playing = 0; // ���� ���� -> ���� ���������� �������� �Ѿ ����

		}

		drawUI(Bomb, Person, Walking); // ����ؼ� �� �����鼭 UI ����

		switch (keyControl()) { //Ű�Է¿� ���� ������ ��ġ ����
		case UP:
			move(&x, &y, 0, -1, &Bomb, &Person, 65, 0, &Walking);
			break;

		case DOWN:
			move(&x, &y, 0, 1, &Bomb, &Person, 65, 0, &Walking);
			break;

		case RIGHT:
			move(&x, &y, 1, 0, &Bomb, &Person, 65, 0, &Walking);
			break;

		case LEFT:
			move(&x, &y, -1, 0, &Bomb, &Person, 65, 0, &Walking);
			break;


		}
		}

	Sleep(1000);

	setColor(black, white);

	gotoxy(x + 1, y);
	printf("           "); //��� ����ؾ��ϴϱ� ��������� ����α�
	gotoxy(x + 1, y);
	printf("< ���̴�..."); //��� ���

	Sleep(3000);

	setColor(white, black);

	What_Ending(Bomb, Person); //���� ��� ~ ���� ��ź�� ��� �� ����

}


// W = ������ ��� ����� ���� ��ǥ
// H = ������ ��� ����� ���� ��ǥ
// ���� ��ǥ (x, y) ������ ��ǥ(_x, _y)
void move(int* x, int* y, int _x, int _y, int* Bomb, int* Person, int W, int H, int* Walking) {

	char mapObject = map[*y + _y][*x + _x]; //�̵��� ��ġ
	setColor(white, black);

	//�� �� �������� ��ġ�����Ͱ� 0�̳� s�� ���� �̵�
	if (mapObject == '0'||mapObject == 's') { // �̵��� ��ġ�� �� �����̸�

		*Walking -= 1; // ���� �� -1

		gotoxy(*x, *y); //�÷��̾� �ִ� ��ġ
		printf(" "); //�����

		setColor(cyan, black);
		gotoxy(*x + _x, *y + _y); //�÷��̾� �̵��� ��ġ
		printf("��"); //�÷��̾� ���

		*x += _x; 
		*y += _y;
		// �÷��̾� ��ġ ����

	}
	else if (mapObject == 'b') { //�̵��� ��ġ�� ��ź�� ������
		*Bomb -= 1; // ��ź ���� -1
		*Walking -= 1;
		map[*y + _y][*x + _x] = '0'; // �� �������� �� ���� �ٲٱ�
		gotoxy(*x + _x, *y + _y); // ��ź ��ü�� ��ġ
		printf(" "); // �� �������� ���

	}

	else if (mapObject == 'h') { //�̵��� ��ġ�� ȸ������ ������
		*Walking += 10; // ���� �� +10
		map[*y + _y][*x + _x] = '0'; // �� �������� �� ���� �ٲٱ�
		gotoxy(*x + _x, *y + _y); //ȸ���� ȹ���� ��ġ
		printf(" "); // �� �������� ���
	}

	else if (mapObject == 'p') { //�̵��� ��ġ�� ����� ������
		*Person -= 1;
		*Walking -= 1;
		map[*y + _y][*x + _x] = '0'; // �� �������� �� ���� �ٲٱ�
		gotoxy(*x + _x, *y + _y); //��� ������ ��ġ
		printf(" "); // �� �������� ���
		

		//������ ��� ǥ���� ��ġ �������� ����
		int RW = rand() % 20; 
		int RH = rand() % 20; 

		W += RW;
		H += RH;
		// �ʰ� UI ���� ħ������ �ʵ��� + ������

		setColor(yellow, black);
		gotoxy(W, H);
		printf("��");
		setColor(white, black);
		gotoxy(W + 2, H);

		int Psay = rand() % 4; // ��� ��� �����ϰ� ���

		switch (Psay) {
		case 0:
			printf("�� ��Ҵ�!");
			break;

		case 1:
			printf("�ѽ�~");
			break;

		case 2:
			printf("�����մϴ�");
			break;

		case 3:
			printf("�״���;");
			break;

		}

	}

	
}


void drawUI(int Bomb, int Person, int Walking) {

	setColor(white, black);

	gotoxy(35, 22);
	printf("+-------------------+");
	setColor(yellow, black);
	gotoxy(35, 23);
	printf("| ���� ��� : %3d�� |", Person);
	setColor(white, black);
	gotoxy(35, 24);
	printf("+-------------------+");

	gotoxy(35, 25);
	printf("+-------------------+");
	setColor(yellow, black);
	gotoxy(35, 26);
	printf("| ���� ��ź : %3d�� |", Bomb);
	setColor(white, black);
	gotoxy(35, 27);
	printf("+-------------------+");

	gotoxy(3, 22);
	printf("+-------------------+");
	setColor(yellow, black);
	gotoxy(3, 23);
	printf("| ���� ���� : %3d   |", Walking);
	setColor(white, black);
	gotoxy(3, 24);
	printf("+-------------------+");

}

int Opening_SKIP() {

	system("cls");

	setColor(white, black);

	printf("\n\n\n\n\n\n");
	printf("                                ���丮�� ��ŵ�Ͻðڽ��ϱ�?");

	setColor(yellow, black);

	int x = 30;
	int y = 15;
	gotoxy(x - 2, y); // '>' ����� ���� x�� -2
	printf("> ��");
	gotoxy(x, y + 1);
	printf("�ƴϿ�");

	while (1) {
		// �÷��̾��� Ű ���ۿ� ���� '>' ��ġ ����

		int n = keyControl(); //�Է� ���� Ű ����
		switch (n) {
		case UP: {
			if (y > 15) {
				gotoxy(x - 2, y); //ȭ��ǥ �����
				printf(" ");
				gotoxy(x - 2, --y); //y�� -1�ؼ� ȭ��ǥ ���� �ø���
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 16) {
				gotoxy(x - 2, y); //ȭ��ǥ �����
				printf(" ");
				gotoxy(x - 2, ++y); //y�� +1�ؼ� ȭ��ǥ �Ʒ��� ������
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			return y - 15;
			//�÷��̾� ���ÿ� ���� ���� �ٸ� �� ��ȯ
			//0�̸� ��ŵ 1�̸� ��ŵ����
			//SKIPorNOT ������ ����� ����
		}

		}
	}
}

void Opening() {


		system("cls");

		setColor(lightblue, black);

		printf("�ƹ� Ű�� ������ ����");

		setColor(white, black);

		printf("\n\n��� ��ȭ�ο� ����, C ��ȭ������ ������� ��ſ� ������ ���� ���̾���. �׷���...\n\n");
		_getch();

		printf("��� �����ϼ���!! �� �ǹ��� ");
		setColor(lightred, black);
		printf("��ź");
		setColor(white, black);
		printf("�� �ִٰ� �մϴ�!!!!\n\n");
		_getch();

		setColor(yellow, black);
		printf("        ��?! ��ź�̶��?!\n\n");
		_getch();
		printf("              �츰 ���� �� �״´�!\n\n");
		_getch();
		printf("   ���ƾƾƾƾ�~ ����~!\n\n");
		_getch();

		setColor(white, black);
		printf("�ٵ� �����ϼ���! ��ź�� ���� ó�����״� ���ǿ��� ���ÿ� ���� �����ְ� �������ּ���! ���轼!\n\n");
		_getch();
		printf("�˰ڽ��ϴ�! ��ź Ž���� �۵�!\n");
		_getch();
		printf("...����α�, ����!\n\n");
		_getch();
		printf("����...�ùε鸸�̶� �����Ҽ� �ֱ⸦...\n");
		_getch();

	
}

void Tutorial() {

	system("cls");

	setColor(white, black);
	printf("\n\n");
	printf("                                     [ ���۹� ]\n\n");

	printf("                                �̵� : W, A, S, D\n\n");

	setColor(white, black);

	printf("                                    [ ������Ʈ ]\n\n");

	printf("                                    �÷��̾�: ");
	setColor(cyan, black);
	printf("��\n");

	setColor(white, black);
	printf("                                       ��ź: ");
	setColor(lightred, black);
	printf("o\n");

	setColor(white, black);
	printf("                                       ���: ");
	setColor(yellow, black);
	printf("��\n");

	setColor(white, black);
	printf("                                      ȸ����: ");
	setColor(lightgreen, black);
	printf("*\n\n");


	setColor(white, black);
	printf("               ���ѵ� ���� �� �ȿ� ��ź�� ��ü�ϰ� ����� �����ؾ� �մϴ�.\n\n");
	printf("                   ȸ���� ȹ�� �� ���� ���� 10��ŭ ȸ���� �� �ֽ��ϴ�.\n\n\n");
	printf("           ������Ʈ �������� �̵�Ű�� ������ [��ü/����/ȹ��] �� �� �ֽ��ϴ�.\n\n\n\n");

	setColor(yellow, black);
	printf("                         �����̽��ٸ� ������ ������ �����մϴ�.");

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}

}


//��ź, ��� �� �� ����
void BAD_Ending() {
	
	setColor(yellow, black);
	printf("	         . . . \n");
	printf("              .| / \n");
	printf("            `--+--'\n");
	printf("              /|. \n");
	printf("             ' | '\n");
	setColor(white, black);
	printf("               |\n");
	printf("               |\n");
	setColor(lightred, black);
	printf("           ,--'#`--.\n");
	printf("           |#######|\n");
	printf("        _.-'#######`-.\n");
	printf("     ,-'###############`-.\n");
	printf("   ,'#####################`,\n");
	printf("  /#########################\ \n");
	printf(" |###########################|\n");
	printf("|#############################|\n");
	printf("|#############################|\n");
	printf("|#############################|\n");
	printf("|#############################|\n");
	printf(" |###########################|\n");
	printf("  .#########################/ \n");
	printf("   `.#####################,' \n");
	printf("     `._###############_,' \n");
	printf("        `--..#####..--'\n");
	printf("\n\n\n");


	printf("     3...");
	Sleep(1000);
	printf("2...");
	Sleep(1000);
	printf("1...\n\n\n");
	Sleep(1000);

	setColor(white, black);

	printf("  ��, �ȵ�!!!!!!!!!!\n\n");
	Sleep(2000);

	system("cls");

	Sleep(1000);

	setColor(lightblue, black);
	printf("�ƹ� Ű�� ������ ����\n\n");

	Sleep(1000);

	setColor(white, black);
	printf("  ���轼�� ������ ����� ����鿡�� ������ ���ߴ�.\n\n");
	_getch();
	printf("  �״� �ּ��� ��������, �ù� ���ǿ� ��ź ��ü, \n");
	_getch();
	printf("  �� ������ ����� ���� ���� ���¿���.\n\n");
	_getch();
	printf("  �ᱹ ���轼�� ��ó �������� ���� ������ �Բ�,\n");
	_getch();
	printf("  �׸��� �μ��� �ǹ��� ���ؿ� �Բ�...\n");
	_getch();
	printf("  ���߿� ������ ���Ҵ�.\n");
	_getch();

	system("cls");

	setColor(lightred, black);

	printf("\n\n\n\n");
	printf(" .d8888b.         d8888 888b     d888 8888888888      .d88888b.  888     888 8888888888 8888888b.  \n");
	printf("d88P  Y88b       d88888 8888b   d8888 888            d88P   Y88b 888     888 888        888   Y88b \n");
	printf("888    888      d88P888 88888b.d88888 888            888     888 888     888 888        888    888 \n");
	printf("888            d88P 888 888Y88888P888 8888888        888     888 Y88b   d88P 8888888    888   d88P \n");
	printf("888  88888    d88P  888 888 Y888P 888 888            888     888  Y88b d88P  888        8888888P  \n");
	printf("888    888   d88P   888 888  Y8P  888 888            888     888   Y88o88P   888        888 T88b \n");
	printf("Y88b  d88P  d8888888888 888       888 888            Y88b..d88P     Y888P    888        888  T88b  \n");
	printf(" Y8888P88  d88P     888 888       888 8888888888       Y88888P       Y8P     8888888888 888   T88b \n\n\n");

	setColor(white, black);

	printf("                              5�� �� ������ ����˴ϴ�.");

	Sleep(5000);
}

//��� ��� �����ϰ�, ��� ��ź ��ü���� ��
void HAPPY_Ending() {

	Sleep(1000);

	setColor(lightblue, black);
	printf("�ƹ� Ű�� ������ ����\n\n");

	Sleep(1000);

	setColor(white, black);
	printf("\n\n");
	printf("�̰ɷ� �������ΰ�...\n\n");
	_getch();
	printf("��ź�� ��� ��ü�� �ǳ��� �ڷ��ϰ�, ���轼�� �ǹ� ������ ���´�.\n\n");
	_getch();

	setColor(yellow, black);
	printf("�;ƾƾƾƾƾ�!!!!!\n\n");
	_getch();
	printf(" ���轼!\n\n");
	_getch();
	printf("        ���轼!\n\n");
	_getch();
	printf("   ���轼!\n\n");
	_getch();

	setColor(white, black);
	printf("������ Ī���ϴ� ������ �Լ��� �׸� �ݰ��.\n\n");
	_getch();
	printf("���� : ���߳�, ���� ���߳� ���轼!\n\n");
	_getch();
	printf("�ƴմϴ�, ���� ���� �ؾ��� ���� ���� ���Դϴ�.\n\n");
	_getch();
	printf("���� : ����, ��ģ�� ��� �����. ���� ������ �ٸ� ����鿡�� �ñ�� �츮�� �׸� ���ư���.\n\n");
	_getch();
	printf("��, �����.\n\n");
	_getch();
	printf("�ڽ��� Ī���ϴ� ��Ҹ��� �ڷ��ϰ�, ������ �׷��� ������ ������.");
	_getch();

	system("cls");

	setColor(lightblue, black);

	printf("\n\n\n\n");

	printf("8888888888 888b    888 8888888b.  \n");
	printf("888        8888b   888 888   Y88b \n");
	printf("888        88888b  888 888    888 \n");
	printf("8888888    888Y88b 888 888    888 \n");
	printf("888        888 Y88b888 888    888 \n");
	printf("888        888  Y88888 888    888 \n");
	printf("888        888   Y8888 888  .d88P \n");
	printf("8888888888 888    Y888 8888888P   \n\n");

	setColor(white, black);

	printf(" 5�� �� ������ ����˴ϴ�.");

	Sleep(5000);


	
}

//��ź�� ����
void NORMAL_Ending_1() {

	Sleep(1000);

	setColor(lightblue, black);
	printf("�ƹ� Ű�� ������ ����\n\n");

	Sleep(1000);

	setColor(white, black);
	printf("���� ���ݸ� ��..!\n\n");
	_getch();
	printf("(����) : ���轼! ���ϰ� �־�?! ���� ������� ��� �����ϰ� �����ݵ� ��� ���߾�!\n");
	_getch();
	printf("         �� �����ִٰ� �ڳױ��� ���߿� �ָ����ɼ�!\n\n");
	_getch();
	printf("�׷�����, ����..!\n\n");
	_getch();
	printf("(����) : ����� �ָ��� ���� ����! �ǹ��� �ٽ� ������ ���ݾ�!\n");
	_getch();
	printf("         ������ Ż���ϴ°͵� �������� �ǹ���! � ����!\n\n");
	_getch();
	printf("...�˼��մϴ�, �����, �������� �־, \n������� �ϻ� �� � ���ص� ���� �ʵ��� �ϴ°� �� �ǹ��Դϴ�.\n\n");
	_getch();
	printf("(����) : ���! �ȵ� ����...!");
	_getch();
	printf("  (...��)\n\n");
	_getch();
	printf("...����α�, ����!\n\n");
	_getch();
	printf("���轼�� Ȱ������ ��ź�׷��� ����ڴ� 0���̾���. \n");
	_getch();
	printf("��źó���� ���轼�� ����...\n\n");
	_getch();
	printf("�״� ���� �� ���� ������\n");
	_getch();
	printf("�̸���ŭ�� ���������� ������� ���� ����� ��ģ ��������,\n");
	_getch();
	printf("��� ������� �����ӿ� ���Ҵ�.");
	_getch();

	system("cls");

	setColor(yellow, black);

	printf("\n\n\n\n");

	printf("8888888888 888b    888 8888888b.  \n");
	printf("888        8888b   888 888   Y88b \n");
	printf("888        88888b  888 888    888 \n");
	printf("8888888    888Y88b 888 888    888 \n");
	printf("888        888 Y88b888 888    888 \n");
	printf("888        888  Y88888 888    888 \n");
	printf("888        888   Y8888 888  .d88P \n");
	printf("8888888888 888    Y888 8888888P   \n\n");

	setColor(white, black);

	printf(" 5�� �� ������ ����˴ϴ�.");

	Sleep(5000);
                                  
                                  
}

//����� ����
void NORMAL_Ending_2() {

	Sleep(1000);

	setColor(lightblue, black);
	printf("�ƹ� Ű�� ������ ����\n\n");

	Sleep(1000);

	setColor(white, black);
	printf("\n\n");

	printf("(����) : ���� �Ƴ� ���轼. ���̻� ��ź ��ȣ�� �������� �ʾ�.\n");
	_getch();
	printf("         ���� ������� �������� �����״� �ڳ״� �̸� ���ϰ�.\n\n");
	_getch();
	printf("�ƴմϴ�, ���� ���� ���� ���� ��� ������ ���� ���°ڽ��ϴ�.\n\n");
	_getch();
	printf("(������) : �ƴϿ���, ���轼. ����� �̹� ���� ���� �ϼ��ݾƿ�. ���� ���񿡰� �ñ�� ���ư�����.\n\n");
	_getch();
	printf("(����) : �츮�� �������� �ϰ�, ���轼, ���� �׸� ǫ ����.\n\n");
	_getch();
	printf("...�˰ڽ��ϴ�, ��� �����ϼ���.\n\n");
	_getch();
	printf("�ӹ��� ��ġ�� ���ϴ� ���轼�� �߰����� ���ſ���.\n\n");
	_getch();


	system("cls");

	setColor(white, black);

	printf("\n\n\n\n");

	printf("8888888888 888b    888 8888888b.  \n");
	printf("888        8888b   888 888   Y88b \n");
	printf("888        88888b  888 888    888 \n");
	printf("8888888    888Y88b 888 888    888 \n");
	printf("888        888 Y88b888 888    888 \n");
	printf("888        888  Y88888 888    888 \n");
	printf("888        888   Y8888 888  .d88P \n");
	printf("8888888888 888    Y888 8888888P   \n\n");

	setColor(white, black);

	printf(" 5�� �� ������ ����˴ϴ�.");

	Sleep(5000);


}


void What_Ending(int Bomb, int Person) {

	system("cls");

	// �����ִ� ��ź�� ��� ���� ���� �ٸ� ���� ���

	if (Bomb == 0 && Person == 0) {
		HAPPY_Ending();
	}

	if (Bomb > 0 && Person > 0) {
		BAD_Ending();
	}

	if (Bomb > 0 && Person == 0) {
		NORMAL_Ending_1();
	}

	if (Bomb == 0 && Person > 0) {
		NORMAL_Ending_2();
	}

	

}
