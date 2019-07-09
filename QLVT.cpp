#include <iostream>
#include <string>
#include "mylib.h"
#include "menus.h"
using namespace std;

int main() {
system("cls");
	int chon;
	while (1) {
		chon = MenuDong(thucdon, so_item);
		switch (chon) {
		case 1: gotoxy(40, 40);
			system("cls");
			MenuDongVatTu();
			break;
		case 2:gotoxy(40, 40);
			system("cls");
			//menu
			break;
		case 3: gotoxy(40, 40);
			system("cls");
		//	menu
			break;
		case 4: gotoxy(40, 40);
			system("cls");
			//MenuDong
		case so_item: return 0;
		}
		system("pause");
	}
};
