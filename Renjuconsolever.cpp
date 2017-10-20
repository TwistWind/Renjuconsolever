// Renjuconsolever.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string"
#include "iostream"
#include "ctime"
#include "sstream"
#include "windows.h"
using namespace std;

void default_board();
void show_board();
void put_chess(short, short, short);
bool winner(short i, short j, short whosturn);
int score(short i, short j, short whosturn);
void multiplayer();
string computerplayer();

int board[17][17];
bool endtry;
int mode = 1;

int main()
{
	cout << "遊戲名稱：五子棋" << endl
		<< "　　版本：3.0" << endl
		<<"輸入pve或pvp可切換模式。"
		<< endl;
	string choose;
	system("Pause");
	modeone:
			default_board();
			multiplayer();
			cout << "輸入 y 再玩一次？：";
			getline(cin, choose);
			if (choose == "y" || choose == "Y")
			{
				goto modeone;
			}
	return 0;
}

void default_board() {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (i == 0 && j == 0) {
				board[i][j] = 0;
			}
			else if (i == 16 || j == 16) {
				board[i][j] = 0;
			}
			else if (i == 0) {
				board[i][j] = j + 30;
			}
			else if (j == 0) {
				board[i][j] = i + 10;
			}
			else if (i == 1 && j == 1) {
				board[i][j] = -7;
			}
			else if (i == 1 && j == 15) {
				board[i][j] = -9;
			}
			else if (i == 15 && j == 1) {
				board[i][j] = -1;
			}
			else if (i == 15 && j == 15) {
				board[i][j] = -3;
			}
			else if (i == 1) {
				board[i][j] = -8;
			}
			else if (j == 1) {
				board[i][j] = -4;
			}
			else if (j == 15) {
				board[i][j] = -6;
			}
			else if (i == 15) {
				board[i][j] = -2;
			}
			else {
				board[i][j] = -5;
			}
		}
	}
}


void show_board() {
	for (int i = 0; i <= 16; i++) {
		for (int j = 0; j <= 16; j++) {
			switch (board[i][j]) {
			case -1:
				cout << "└";
				break;
			case -2:
				cout << "┴";
				break;
			case -3:
				cout << "┘";
				break;
			case -4:
				cout << "├";
				break;
			case -5:
				cout << "┼";
				break;
			case -6:
				cout << "┤";
				break;
			case -7:
				cout << "┌";
				break;
			case -8:
				cout << "┬";
				break;
			case -9:
				cout << "┐";
				break;
			case 0:
				cout << "　";
				break;
			case 1:
				cout << "○";
				break;
			case 2:
				cout << "●";
				break;
			case 11:
				cout << "１";
				break;
			case 12:
				cout << "２";
				break;
			case 13:
				cout << "３";
				break;
			case 14:
				cout << "４";
				break;
			case 15:
				cout << "５";
				break;
			case 16:
				cout << "６";
				break;
			case 17:
				cout << "７";
				break;
			case 18:
				cout << "８";
				break;
			case 19:
				cout << "９";
				break;
			case 20:
				cout << "10";
				break;
			case 21:
				cout << "11";
				break;
			case 22:
				cout << "12";
				break;
			case 23:
				cout << "13";
				break;
			case 24:
				cout << "14";
				break;
			case 25:
				cout << "15";
				break;
			case 31:
				cout << "Ａ";
				break;
			case 32:
				cout << "Ｂ";
				break;
			case 33:
				cout << "Ｃ";
				break;
			case 34:
				cout << "Ｄ";
				break;
			case 35:
				cout << "Ｅ";
				break;
			case 36:
				cout << "Ｆ";
				break;
			case 37:
				cout << "Ｇ";
				break;
			case 38:
				cout << "Ｈ";
				break;
			case 39:
				cout << "Ｉ";
				break;
			case 40:
				cout << "Ｊ";
				break;
			case 41:
				cout << "Ｋ";
				break;
			case 42:
				cout << "Ｌ";
				break;
			case 43:
				cout << "Ｍ";
				break;
			case 44:
				cout << "Ｎ";
				break;
			case 45:
				cout << "Ｏ";
				break;

			}
		}
		cout << endl;
	}
}

void show_chess() {
	for (int i = 0; i <= 16; i++) {
		for (int j = 0; j <= 16; j++) {
			switch (board[i][j]) {
			case -1:
				cout << "└";
				break;
			case -2:
				cout << "┴";
				break;
			case -3:
				cout << "┘";
				break;
			case -4:
				cout << "├";
				break;
			case -5:
				cout << "┼";
				break;
			case -6:
				cout << "┤";
				break;
			case -7:
				cout << "┌";
				break;
			case -8:
				cout << "┬";
				break;
			case -9:
				cout << "┐";
				break;
			case 0:
				cout << "　";
				break;
			case 1:
				cout << "○";
				break;
			case 2:
				cout << "●";
				break;

			case 11:
				cout << "１";
				break;
			case 12:
				cout << "２";
				break;
			case 13:
				cout << "３";
				break;
			case 14:
				cout << "４";
				break;
			case 15:
				cout << "５";
				break;
			case 16:
				cout << "６";
				break;
			case 17:
				cout << "７";
				break;
			case 18:
				cout << "８";
				break;
			case 19:
				cout << "９";
				break;
			case 20:
				cout << "10";
				break;
			case 21:
				cout << "11";
				break;
			case 22:
				cout << "12";
				break;
			case 23:
				cout << "13";
				break;
			case 24:
				cout << "14";
				break;
			case 25:
				cout << "15";
				break;
			case 31:
				cout << "Ａ";
				break;
			case 32:
				cout << "Ｂ";
				break;
			case 33:
				cout << "Ｃ";
				break;
			case 34:
				cout << "Ｄ";
				break;
			case 35:
				cout << "Ｅ";
				break;
			case 36:
				cout << "Ｆ";
				break;
			case 37:
				cout << "Ｇ";
				break;
			case 38:
				cout << "Ｈ";
				break;
			case 39:
				cout << "Ｉ";
				break;
			case 40:
				cout << "Ｊ";
				break;
			case 41:
				cout << "Ｋ";
				break;
			case 42:
				cout << "Ｌ";
				break;
			case 43:
				cout << "Ｍ";
				break;
			case 44:
				cout << "Ｎ";
				break;
			case 45:
				cout << "Ｏ";
				break;

			}
		}
		cout << endl;
	}
}

void put_chess(short i, short j, short whosturn) {
	if (i == 0 || i >= 16 || j == 0 || j >= 16) {
		cout <<i<<" "<<(char)(j + 64) << "下棋的範圍超出格子外！" << endl;
		endtry = 0;
		Sleep(1000);
	}
	else if (board[i][j] == 1 || board[i][j] == 2) {
		cout << i<<" "<<(char)(j+64)<<"此位置已經有棋子了！" << endl;
		endtry = 0;
		Sleep(1000);
	}
	else {
		board[i][j] = whosturn;
	}

}

bool winner(short i, short j, short whosturn) {
	short count, tempi, tempj;
	bool win = 0;
	short score=0;
	//←→ 
	count = 1;
	tempi = i;
	while (board[--tempi][j] == whosturn) {
		count++; 
	}
	tempi = i;
	while (board[++tempi][j] == whosturn) {
		count++; 
	}
	if (count >= 5) { win = 1; goto winner_check_end; }
	score += count;
	//↑↓ 
	count = 1;
	tempj = j;
	while (board[i][--tempj] == whosturn) { 
		count++; 
	}
	tempj = j;
	while (board[i][++tempj] == whosturn) { 
		count++; 
	}
	if (count >= 5) { win = 1; goto winner_check_end; }
	score += count;
	//↖↘ 
	count = 1;
	tempi = i, tempj = j;
	while (board[--tempi][--tempj] == whosturn) {
		count++; 
	}
	tempi = i, tempj = j;
	while (board[++tempi][++tempj] == whosturn) { 
		count++; 
	}
	if (count >= 5) { win = 1; goto winner_check_end; }
	score += count;
	//↙↗ 
	count = 1;
	tempi = i, tempj = j;
	while (board[++tempi][--tempj] == whosturn) { 
		count++; 
	}
	tempi = i, tempj = j;
	while (board[--tempi][++tempj] == whosturn) { 
		count++;
	}
	if (count >= 5) { win = 1; goto winner_check_end; }
	score += count;
winner_check_end:
	return win;
}

int score(short i, short j, short whosturn) {
	short count, tempi, tempj;
	int snc[6] = { 0,1,10,50,1000,10000 };
	int score = 0;
	//←→ 
	count = 1;
	tempi = i;
	while (board[--tempi][j] == whosturn) {count++;}
	tempi = i;
	while (board[++tempi][j] == whosturn) {count++;}
	score += snc[count];
	//↑↓ 
	count = 1;
	tempj = j;
	while (board[i][--tempj] == whosturn) {count++;}
	tempj = j;
	while (board[i][++tempj] == whosturn) {count++;}
	score += snc[count];
	//↖↘ 
	count = 1;
	tempi = i, tempj = j;
	while (board[--tempi][--tempj] == whosturn) {count++;}
	tempi = i, tempj = j;
	while (board[++tempi][++tempj] == whosturn) {count++;}
	score += snc[count];
	//↙↗ 
	count = 1;
	tempi = i, tempj = j;
	while (board[++tempi][--tempj] == whosturn) {count++;}
	tempi = i, tempj = j;
	while (board[--tempi][++tempj] == whosturn) {count++;}
	score += snc[count];
	
	return score;
}

void multiplayer() {
	string keyin;
	short whosturn = 1, I, J;
	system("cls");
	show_board();
nextstep:
	I = 0;
	J = 0;
	endtry = 1;
	system("cls");
	show_board();
	if (whosturn == 1) {
		cout << "○換黑子下：";
	}
	else
	{
		cout << "●換白子下：";
	}
	if (whosturn == 2 && mode ==2)
	{
		keyin = computerplayer();
	}
	else
		getline(cin, keyin);
	if (keyin == "pve" && mode ==1 )
	{
		cout << "切換為PVE模式:" << endl;
		mode = 2 ;
		system("pause");
		goto nextstep;
	}
	else if (keyin == "pvp" && mode == 2) {
		cout << "切換為PVP模式:" << endl;
		mode = 1;
		system("pause");
		goto nextstep;
	}
	for (int n = 0; n<keyin.length(); n++) {          //處理字串keyin 
		if (keyin[n] >= 'a' && keyin[n] <= 'o') {
			J = keyin[n] - 'a' + 1;
		}
		else if (keyin[n] >= 'A' && keyin[n] <= 'O') {
			J = keyin[n] - 'A' + 1;
		}
		else if (keyin[n] >= '0' && keyin[n] <= '9') {
			I = I * 10 + keyin[n] - '0';
		}
		else if (keyin[n] == ' ') {
			continue;
		}
		else {
			cout << "輸入了不合法的字元！" << endl;
			system("pause");
			goto nextstep;
		}
	}
	put_chess(I, J, whosturn);
	if (endtry == 0) { goto nextstep; }
	endtry = winner(I, J, whosturn);
	whosturn = (whosturn == 1 ? 2 : 1);
	if (endtry == 0) { goto nextstep; }
	else {
		whosturn = (whosturn == 1 ? 2 : 1);
		system("cls");
		show_board();
		if (whosturn == 1) {
			cout << "黑棋贏了！" << endl; 
		}
		else {
			cout << "白棋贏了！" << endl; 
		}
	}
}

string computerplayer() {
	srand(time(NULL));
	int x=1, y=1;
	int pscore, escore,hscore =0,tscore;
	int rd;
	for (int i = 1; i < 16; i++) {
		for (int j = 1; j < 16; j++) {
			pscore = score(i, j, 1);
			escore = score(i, j, 2);
			tscore = pscore + escore;
			if (tscore > hscore) {        //該點電腦權重+玩家權重=總權重
				hscore = tscore;
				x = i;
				y = j;
			}
		}
	}
	while (board[x][y] == 1 || board[x][y] == 2)
	{
		x = x + rand() % 3 - 1;
		y = y + rand() % 3 - 1;
	}
	stringstream ss;
	ss << x;
	string re;
	ss >> re;
	re = re + (char)(y + 64);
	return re;
}
