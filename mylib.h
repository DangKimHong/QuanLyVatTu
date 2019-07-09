#pragma once
#ifndef _MYLIB_H_
#define _MYLIB_H_


#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
using namespace std;

#define Enter 13
#define PASSWORD "abcdef"

const int so_item_title = 6;
const int so_item = 5;
const int so_item_nv = 7;
const int so_item_hd = 7;
const int so_item_lop = 8;
const int so_item_vt= 8;

const int dong = 10;
const int cot = 40;
const int Up = 72;
const int Down = 80;

char Title[so_item_title][50] = {
	"CTDL&GT",
	"GVHD: LUU NGUYEN KY THU",
	"TEN DE TAI: QUAN LI VAT TU",
	"SVTH: DANG KIM HONG - TRAN THI NGOC MY",
	"MSSV: N14DCPT102    - N14DCPT029",
	"LOP: D14CQPU01-N"
};

char thucdon[so_item][50] = { "1. QUAN LI VAT TU			",
"2. QUAN LI NHAN VIEN 			",
"3. QUAN LI HOA DON				",
"4. QUAN LI CHI TIET HOA DON	",
"0. THOAT						"
};

char thucdon_nv[so_item_nv][50] = {
"1. Xem Danh Sach Nhan vien (ASC)	",
"2. Them Nhan Vien					",
"3. Chinh Sua Nhan Vien				",
"4. Xoa Nhan Vien					",
"5. Open File						",
"6. Save File						",
"0. Thoat							",
};

char thucdon_hd[so_item_hd][50] = {
	"1. Lap Hoa Don	Nhap		    			",
	"2. Lap Hoa Don Xuat		    			",
	"3. Xem Hoa Don Theo So Hoa Don				",
	"4. Xem Hoa Don Theo Nhan vien va Thoi gian	",
	"5. Open File								",
	"6. Save File								",
	"0. Thoat					   				"
};

char thucdon_lop[so_item_lop][50] = {
	"1. In DS Lop theo Nien khoa",
	"2. In tat ca ca Lop        ",
	"3. Them Lop				",
	"4. Sua Lop					",
	"5. Xoa Lop					",
	"6. Load DS Lop	tu file     ",
	"7. Save DS Lop ra file		",
	"0. Thoat					"
};

char thucdon_vt[so_item_vt][50] = { 
"1. Nhap Vat Tu					",
"2. In Danh Sach Vat Tu			",
"3. In Danh Sach Vat Tu Ton Kho	",
"4. Chinh Sua Vat Tu			",
"5. Xoa Vat Tu					",
"6. Open File					",
"7. Save File					",
"0. Thoat						"
};

char* Pwd() {
	char S[50]; int i = 0;
	while ((S[i] = _getch()) != Enter)
	{
		printf("%c", '*'); i++;
	}
	S[i] = '\0';
	return S;
}

int CheckPwd() {
	int dem = 0;
	for (dem = 1; dem <= 3; dem++)
	{
		printf("Password :");
		if (strcmp(Pwd(), PASSWORD) == 0)   return 1;
		else printf("\nPassword sai. Hay nhap lai\n");
	}
	return 0;
}

void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

int wherex(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.X;
}

int wherey(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.Y;
}
void clreol() {
	COORD coord;
	DWORD written;
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	coord.X = info.dwCursorPosition.X;
	coord.Y = info.dwCursorPosition.Y;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ',
		info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
	gotoxy(info.dwCursorPosition.X + 1, info.dwCursorPosition.Y + 1);
}

void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void setcolor(int background, int textcolor) {
	SetBGColor(background);
	SetColor(textcolor);
}

void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void khung(int x, int y, int width, int height) {
	gotoxy(x, y);
	printf("%c", 218);
	for (int i = 1; i < width; i++) {
		gotoxy(x + i, y);
		printf("%c", 196);
	}
	gotoxy(x, y + height);
	printf("%c", 192);
	for (int j = 1; j < height; j++) {
		gotoxy(x, y + j);
		printf("%c", 179);
	}
	gotoxy(x + width, y);
	printf("%c", 191);
	for (int i = 1; i < height; i++) {
		gotoxy(x + width, y + i);
		printf("%c", 179);
	}
	gotoxy(x + width, y + height);
	printf("%c", 217);
	for (int j = 1; j < width; j++) {
		gotoxy(x + j, y + height);
		printf("%c", 196);
	}
}

void thongtin() {
	gotoxy(50, 1);
	for (int i = 0; i < so_item; i++)
	{
		cout << Title[i];
		gotoxy(40, 4 + i);
	}
}
void Normal() {
	SetColor(3);
	SetBGColor(0);
}
void HighLight() {
	SetColor(0);
	SetBGColor(15);
}
int MenuDong(char td[][50], int num) {
	Normal();
	system("cls");
	thongtin();
	int chon = 0;
	int i;
	for (i = 0; i < num; i++)
	{
		gotoxy(cot, dong + i);
		cout << td[i];
	}

	HighLight();
	gotoxy(cot, dong + chon);
	cout << td[chon];
	char kytu;
	do {
		kytu = _getch();
		if (kytu == 0) kytu = _getch();
		switch (kytu) {
		case Up:if (chon + 1 > 1)
		{
			Normal();
			gotoxy(cot, dong + chon); cout << td[chon];
			chon--;
			HighLight();
			gotoxy(cot, dong + chon); 	cout << td[chon];
		}
				break;
		case Down:if (chon + 1 < num)
		{
			Normal();
			gotoxy(cot, dong + chon);	cout << td[chon];
			chon++;
			HighLight();
			gotoxy(cot, dong + chon); 	cout << td[chon];

		}
				  break;
		case 13: return chon + 1;
		}  // end switch
	} while (1);
}

#endif //
