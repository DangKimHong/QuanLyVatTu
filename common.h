#include <iostream>
#include <string>
#include "mylib.h"

using namespace std;

void BaoLoi (char *s){
  int x=wherex() , y=wherey();
  gotoxy (10,24);
  cout <<s;
  Sleep(4000);
  gotoxy(10,24);
  clreol();
  gotoxy(x,y);
}
void NhapChuoi (char *tieude, char *S) {
	cout << tieude ;  fflush(stdin);
    do
	  gets(S);
    while (strcmp(S,"")==0)  ;	
}

//***Thieu check kieu du lieu
void NhapTonKho (char *tieude, float &num){
	cout << tieude ;  fflush(stdin);
    cin >> num;
}
