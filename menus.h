#include <iostream>
#include <string>
#include "mylib.h"
#include "vattu.h"
#include "nhanvien.h"

/** Menu Vat Tu **/
int MenuDongVatTu(){
	DSVT ds; ds.n=0; char maso[10]; VATTU Vattu; 
  system("cls");
	int chon;
	while (1) {
		chon = MenuDong(thucdon_vt, so_item_vt);
		switch (chon) {
		case 1: gotoxy(10, 20);
			system("cls");
			NhapDSVT(ds, 0);
			break;
		case 2: gotoxy(10, 20);
			system("cls");
			LietKe(ds);
			break;
		case 3: gotoxy(10, 20);
			system("cls");
			break;
		case 4: gotoxy(10, 20);
			system("cls");
			cout << "Nhap ma so vat tu can xoa:";
			cin >> maso;
			XoaVatTu(ds,maso);
			break;
		case so_item_vt: return 0;
		}
		system("pause");
	}
}

int MenuDongNhanVien(){
  system("cls");
	int chon;
	while (1) {
		chon = MenuDong(thucdon_nv, so_item_nv);
		switch (chon) {
		case 1: gotoxy(10, 20);
			system("cls");
			//menu
			break;
		case 2: gotoxy(10, 20);
			system("cls");
			//menu
			break;
		case 3: gotoxy(10, 20);
			system("cls");
			break;
		case 4: gotoxy(10, 20);
			system("cls");
			break;
		case so_item_vt: return 0;
		}
		system("pause");
	}
}
