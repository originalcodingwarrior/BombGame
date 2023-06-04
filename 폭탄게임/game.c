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

};  //벽과 공백 미리 작성해놓은 맵

int keyControl() {
	char temp = _getch(); //_getch = 입력된 키값을 즉시 반환 ~ 키입력에 사용

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
	printf("                      <김톰슨과 천만 명의 인질>");

	setColor(white, black);

	gotoxy(0, 17);
	printf("     W: 위\n");
	printf("     S: 아래\n");
	printf("     SPACE: 선택");

	setColor(yellow, black);

	int x = 30;
	int y = 15;
	gotoxy(x - 2, y); // '>' 출력을 위해 x에 -2
	printf("> 게임시작");
	gotoxy(x, y + 1);
	printf("게임정보");
	gotoxy(x, y + 2);
	printf("  종료  ");

	while (1) {
		// 플레이어의 키 조작에 따라 '>' 위치 변경

		int n = keyControl(); //입력 받은 키 저장
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
			//플레이어 선택에 따라 각각 다른 값 반환
			//게임 시작 : 0, 게임 정보 : 1, 종료 : 2
			//menuCode 변수에 저장될 거임
		}

		}
	}

}

void infoDraw() {
	system("cls");
	printf("\n\n");
	printf("                        [ 조작법 ]\n\n");
	printf("                    이동 : W, A, S, D\n");
	printf("                    선택 : 스페이스바\n\n\n\n\n\n");
	printf("       스페이스바를 누르면 메인화면으로 이동합니다.");

	while (1) {
		if (keyControl() == SUBMIT) {
			break; //스페이스바 누르면 함수 빠져나가도록
		}
	}
}

int drawMap(int* x, int* y) {

	srand(time(NULL)); // 오브젝트 랜덤으로 배치하기 위해 난수 생성

	system("cls");
	int h, w; //세로, 가로
	int Bomb = 0;

	for (h = 0; h < 21; h++) {
		for (w = 0; w < 65; w++) {

			char temp = map[h][w]; // 맵 한 칸 한 칸 읽어나가기

			//'0'에는 빈 공간 또는 폭탄 또는 회복약
			if (temp == '0') {
				
				int BOMBorHorNOT = rand() % 100; //폭탄인지 하트인지 빈 공간인지 랜덤으로 정해지도록

				if (BOMBorHorNOT <= 2) {
					setColor(lightred, black);
					printf("o");
					map[h][w] = 'b'; // '0'에서 'b'로 맵 정보 바꾸기 ( 폭탄 자리 기억 )
					Bomb++; //생성된 폭탄 수 +1
				}

				else if (BOMBorHorNOT > 2 && BOMBorHorNOT <= 4) {
					setColor(lightgreen, black);
					printf("*");
					map[h][w] = 'h'; //'0'에서 'h'로 맵 정보 바꾸기 ( 회복약 자리 기억 )
				}

				else {
					setColor(black, black);
					printf(" ");
				}
				
			} 

			//'1'에는 벽
			else if (temp == '1') {
				setColor(white, white);
				printf("#");
			}

			//'s'에는 플레이어
			else if (temp == 's') {

				*x = w;
				*y = h;
				//플레이어 위치 저장

				setColor(cyan, black);
				printf("♀");
			}
		}
		printf("\n");
	}
	setColor(white, black);

	return Bomb;
	// 생성된 폭탄 개수 반환

}

int drawPerson() {

	srand(time(NULL)); // 랜덤으로 배치하기 위해 난수 생성

	int h, w; //세로, 가로
	int Person = 0;

	for (h = 0; h < 21; h++) {
		for (w = 0; w < 65; w++) {

			char temp = map[h][w]; //맵 한 칸 한 칸 읽어나가기

			//'0'이면 사람
			if (temp == '0') {

				int PorNOT = rand() % 100; //사람인지 아닌지 랜덤으로 정해지도록

				if (PorNOT <= 0) {
					setColor(yellow, black);
					gotoxy(w, h); //해당 위치로 가기 -> 이거 안 하면 엉뚱한 데에 그려짐
					printf("♀"); //출력
					map[h][w] = 'p'; // '0'에서 'p'로 맵 정보 바꾸기 ( 사람 위치 기억 )
					Person++; //생성된 사람 수 +1
				}
			}
		}
		printf("\n");
	}
	setColor(white, black);

	return Person;
	//생성된 사람 수 반환
}

int gLoop() {
	int x, y; //플레이어 좌표 저장 변수

	int playing = 1; //1이면 게임 중, 0이면 게임 종료

	int Bomb = drawMap(&x, &y); // 맵 설정 후 출력
	//맵에 좌표 포인터 전달
	//생성된 폭탄 개수 받기
	
	int Person = drawPerson(); // 사람 생성
	//생성된 사람 수 받기

	int Walking = (Bomb + Person) * 3; // 걸음 수 설정


	//게임 루프
	while (playing) {

		if ((Bomb == 0 && Person == 0) || (Walking == 0)) {
			playing = 0; // 게임 종료 -> 루프 빠져나오고 엔딩으로 넘어갈 것임

		}

		drawUI(Bomb, Person, Walking); // 계속해서 값 받으면서 UI 갱신

		switch (keyControl()) { //키입력에 따라 증감할 위치 전달
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
	printf("           "); //대사 출력해야하니까 빈공간으로 비워두기
	gotoxy(x + 1, y);
	printf("< 끝이다..."); //대사 출력

	Sleep(3000);

	setColor(white, black);

	What_Ending(Bomb, Person); //엔딩 출력 ~ 남은 폭탄과 사람 수 전달

}


// W = 구조된 사람 출력할 가로 좌표
// H = 구조된 사람 출력할 세로 좌표
// 원래 좌표 (x, y) 증감할 좌표(_x, _y)
void move(int* x, int* y, int _x, int _y, int* Bomb, int* Person, int W, int H, int* Walking) {

	char mapObject = map[*y + _y][*x + _x]; //이동할 위치
	setColor(white, black);

	//벽 못 지나가게 위치데이터가 0이나 s일 때만 이동
	if (mapObject == '0'||mapObject == 's') { // 이동할 위치가 빈 공간이면

		*Walking -= 1; // 걸음 수 -1

		gotoxy(*x, *y); //플레이어 있던 위치
		printf(" "); //지우기

		setColor(cyan, black);
		gotoxy(*x + _x, *y + _y); //플레이어 이동할 위치
		printf("♀"); //플레이어 출력

		*x += _x; 
		*y += _y;
		// 플레이어 위치 갱신

	}
	else if (mapObject == 'b') { //이동할 위치에 폭탄이 있으면
		*Bomb -= 1; // 폭탄 개수 -1
		*Walking -= 1;
		map[*y + _y][*x + _x] = '0'; // 빈 공간으로 맵 정보 바꾸기
		gotoxy(*x + _x, *y + _y); // 폭탄 해체할 위치
		printf(" "); // 빈 공간으로 출력

	}

	else if (mapObject == 'h') { //이동할 위치에 회복약이 있으면
		*Walking += 10; // 걸음 수 +10
		map[*y + _y][*x + _x] = '0'; // 빈 공간으로 맵 정보 바꾸기
		gotoxy(*x + _x, *y + _y); //회복약 획득할 위치
		printf(" "); // 빈 공간으로 출력
	}

	else if (mapObject == 'p') { //이동할 위치에 사람이 있으면
		*Person -= 1;
		*Walking -= 1;
		map[*y + _y][*x + _x] = '0'; // 빈 공간으로 맵 정보 바꾸기
		gotoxy(*x + _x, *y + _y); //사람 구조할 위치
		printf(" "); // 빈 공간으로 출력
		

		//구조된 사람 표시할 위치 랜덤으로 설정
		int RW = rand() % 20; 
		int RH = rand() % 20; 

		W += RW;
		H += RH;
		// 맵과 UI 범위 침범하지 않도록 + 랜덤값

		setColor(yellow, black);
		gotoxy(W, H);
		printf("♀");
		setColor(white, black);
		gotoxy(W + 2, H);

		int Psay = rand() % 4; // 사람 대사 랜덤하게 출력

		switch (Psay) {
		case 0:
			printf("와 살았다!");
			break;

		case 1:
			printf("앗싸~");
			break;

		case 2:
			printf("감사합니다");
			break;

		case 3:
			printf("죽는줄;");
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
	printf("| 남은 사람 : %3d명 |", Person);
	setColor(white, black);
	gotoxy(35, 24);
	printf("+-------------------+");

	gotoxy(35, 25);
	printf("+-------------------+");
	setColor(yellow, black);
	gotoxy(35, 26);
	printf("| 남은 폭탄 : %3d개 |", Bomb);
	setColor(white, black);
	gotoxy(35, 27);
	printf("+-------------------+");

	gotoxy(3, 22);
	printf("+-------------------+");
	setColor(yellow, black);
	gotoxy(3, 23);
	printf("| 남은 걸음 : %3d   |", Walking);
	setColor(white, black);
	gotoxy(3, 24);
	printf("+-------------------+");

}

int Opening_SKIP() {

	system("cls");

	setColor(white, black);

	printf("\n\n\n\n\n\n");
	printf("                                스토리를 스킵하시겠습니까?");

	setColor(yellow, black);

	int x = 30;
	int y = 15;
	gotoxy(x - 2, y); // '>' 출력을 위해 x에 -2
	printf("> 예");
	gotoxy(x, y + 1);
	printf("아니오");

	while (1) {
		// 플레이어의 키 조작에 따라 '>' 위치 변경

		int n = keyControl(); //입력 받은 키 저장
		switch (n) {
		case UP: {
			if (y > 15) {
				gotoxy(x - 2, y); //화살표 지우고
				printf(" ");
				gotoxy(x - 2, --y); //y값 -1해서 화살표 위로 올리기
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 16) {
				gotoxy(x - 2, y); //화살표 지우고
				printf(" ");
				gotoxy(x - 2, ++y); //y값 +1해서 화살표 아래로 내리기
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			return y - 15;
			//플레이어 선택에 따라 각각 다른 값 반환
			//0이면 스킵 1이면 스킵안함
			//SKIPorNOT 변수에 저장될 것임
		}

		}
	}
}

void Opening() {


		system("cls");

		setColor(lightblue, black);

		printf("아무 키나 눌러서 진행");

		setColor(white, black);

		printf("\n\n어느 평화로운 오후, C 백화점에서 사람들이 즐거운 쇼핑을 즐기던 중이었다. 그러나...\n\n");
		_getch();

		printf("모두 대피하세요!! 이 건물에 ");
		setColor(lightred, black);
		printf("폭탄");
		setColor(white, black);
		printf("이 있다고 합니다!!!!\n\n");
		_getch();

		setColor(yellow, black);
		printf("        뭐?! 폭탄이라고?!\n\n");
		_getch();
		printf("              우린 이제 다 죽는다!\n\n");
		_getch();
		printf("   끄아아아아악~ 엄마~!\n\n");
		_getch();

		setColor(white, black);
		printf("다들 진정하세요! 폭탄은 저희가 처리할테니 대피원의 지시에 따라 질서있게 대피해주세요! 김톰슨!\n\n");
		_getch();
		printf("알겠습니다! 폭탄 탐지기 작동!\n");
		_getch();
		printf("...저기로군, 간다!\n\n");
		_getch();
		printf("제발...시민들만이라도 무사할수 있기를...\n");
		_getch();

	
}

void Tutorial() {

	system("cls");

	setColor(white, black);
	printf("\n\n");
	printf("                                     [ 조작법 ]\n\n");

	printf("                                이동 : W, A, S, D\n\n");

	setColor(white, black);

	printf("                                    [ 오브젝트 ]\n\n");

	printf("                                    플레이어: ");
	setColor(cyan, black);
	printf("♀\n");

	setColor(white, black);
	printf("                                       폭탄: ");
	setColor(lightred, black);
	printf("o\n");

	setColor(white, black);
	printf("                                       사람: ");
	setColor(yellow, black);
	printf("♀\n");

	setColor(white, black);
	printf("                                      회복약: ");
	setColor(lightgreen, black);
	printf("*\n\n");


	setColor(white, black);
	printf("               제한된 걸음 수 안에 폭탄을 해체하고 사람을 구조해야 합니다.\n\n");
	printf("                   회복약 획득 시 걸음 수를 10만큼 회복할 수 있습니다.\n\n\n");
	printf("           오브젝트 방향으로 이동키를 누르면 [해체/구조/획득] 할 수 있습니다.\n\n\n\n");

	setColor(yellow, black);
	printf("                         스페이스바를 누르면 게임을 시작합니다.");

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}

}


//폭탄, 사람 둘 다 남음
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

	printf("  아, 안돼!!!!!!!!!!\n\n");
	Sleep(2000);

	system("cls");

	Sleep(1000);

	setColor(lightblue, black);
	printf("아무 키나 눌러서 진행\n\n");

	Sleep(1000);

	setColor(white, black);
	printf("  김톰슨의 마지막 비명은 사람들에게 기억되지 못했다.\n\n");
	_getch();
	printf("  그는 최선을 다했지만, 시민 대피와 폭탄 해체, \n");
	_getch();
	printf("  그 무엇도 제대로 되지 않은 상태였다.\n\n");
	_getch();
	printf("  결국 김톰슨은 미처 구조되지 못한 사람들과 함께,\n");
	_getch();
	printf("  그리고 부서진 건물의 잔해와 함께...\n");
	_getch();
	printf("  폭발에 묻히고 말았다.\n");
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

	printf("                              5초 뒤 게임이 종료됩니다.");

	Sleep(5000);
}

//모든 사람 구조하고, 모든 폭탄 해체했을 때
void HAPPY_Ending() {

	Sleep(1000);

	setColor(lightblue, black);
	printf("아무 키나 눌러서 진행\n\n");

	Sleep(1000);

	setColor(white, black);
	printf("\n\n");
	printf("이걸로 마지막인가...\n\n");
	_getch();
	printf("폭탄이 모두 해체된 실내를 뒤로하고, 김톰슨은 건물 밖으로 나온다.\n\n");
	_getch();

	setColor(yellow, black);
	printf("와아아아아아아!!!!!\n\n");
	_getch();
	printf(" 김톰슨!\n\n");
	_getch();
	printf("        김톰슨!\n\n");
	_getch();
	printf("   김톰슨!\n\n");
	_getch();

	setColor(white, black);
	printf("영웅을 칭송하는 군중의 함성이 그를 반겼다.\n\n");
	_getch();
	printf("대장 : 잘했네, 정말 잘했네 김톰슨!\n\n");
	_getch();
	printf("아닙니다, 저는 그저 해야할 일을 했을 뿐입니다.\n\n");
	_getch();
	printf("대장 : 하하, 이친구 겸손 떨기는. 이제 뒷일은 다른 사람들에게 맡기고 우리는 그만 돌아가지.\n\n");
	_getch();
	printf("네, 대장님.\n\n");
	_getch();
	printf("자신을 칭송하는 목소리를 뒤로하고, 영웅은 그렇게 현장을 떠난다.");
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

	printf(" 5초 뒤 게임이 종료됩니다.");

	Sleep(5000);


	
}

//폭탄만 남음
void NORMAL_Ending_1() {

	Sleep(1000);

	setColor(lightblue, black);
	printf("아무 키나 눌러서 진행\n\n");

	Sleep(1000);

	setColor(white, black);
	printf("이제 조금만 더..!\n\n");
	_getch();
	printf("(무전) : 김톰슨! 뭐하고 있어?! 이제 사람들은 모두 대피하고 구조반도 모두 퇴각했어!\n");
	_getch();
	printf("         더 남아있다간 자네까지 폭발에 휘말릴걸세!\n\n");
	_getch();
	printf("그렇지만, 아직..!\n\n");
	_getch();
	printf("(무전) : 사람이 휘말릴 일은 없어! 건물은 다시 지으면 되잖아!\n");
	_getch();
	printf("         무사히 탈출하는것도 구조대의 의무다! 어서 나와!\n\n");
	_getch();
	printf("...죄송합니다, 대장님, 무슨일이 있어도, \n사람들의 일상에 그 어떤 피해도 가지 않도록 하는게 제 의무입니다.\n\n");
	_getch();
	printf("(무전) : 잠깐! 안돼 김톰...!");
	_getch();
	printf("  (...뚝)\n\n");
	_getch();
	printf("...저기로군, 간다!\n\n");
	_getch();
	printf("김톰슨의 활약으로 폭탄테러의 사상자는 0명이었다. \n");
	_getch();
	printf("폭탄처리반 김톰슨만 빼고...\n\n");
	_getch();
	printf("그는 이제 이 세상에 없지만\n");
	_getch();
	printf("이름만큼은 마지막까지 사람들을 위해 목숨을 바친 영웅으로,\n");
	_getch();
	printf("모든 사람들의 마음속에 남았다.");
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

	printf(" 5초 뒤 게임이 종료됩니다.");

	Sleep(5000);
                                  
                                  
}

//사람만 남음
void NORMAL_Ending_2() {

	Sleep(1000);

	setColor(lightblue, black);
	printf("아무 키나 눌러서 진행\n\n");

	Sleep(1000);

	setColor(white, black);
	printf("\n\n");

	printf("(무전) : 이제 됐네 김톰슨. 더이상 폭탄 신호는 감지되지 않아.\n");
	_getch();
	printf("         남은 사람들은 구조반이 구할테니 자네는 이만 퇴각하게.\n\n");
	_getch();
	printf("아닙니다, 저도 여기 남아 남은 사람 구조에 힘을 보태겠습니다.\n\n");
	_getch();
	printf("(구조반) : 아니에요, 김톰슨. 당신은 이미 많은 일을 하셨잖아요. 여긴 저희에게 맡기고 돌아가세요.\n\n");
	_getch();
	printf("(무전) : 우리의 구조반을 믿게, 김톰슨, 이제 그만 푹 쉬어.\n\n");
	_getch();
	printf("...알겠습니다, 모두 조심하세요.\n\n");
	_getch();
	printf("임무를 마치고 퇴각하는 김톰슨의 발걸음은 무거웠다.\n\n");
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

	printf(" 5초 뒤 게임이 종료됩니다.");

	Sleep(5000);


}


void What_Ending(int Bomb, int Person) {

	system("cls");

	// 남아있는 폭탄과 사람 수에 따라 다른 엔딩 출력

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
