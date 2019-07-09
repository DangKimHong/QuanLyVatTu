#include <iostream>
#include <string>
#include "mylib.h"
#include "common.h"

using namespace std;

const int MAXLIST =100;
struct VATTU{
	char MAVT[10];
	char TENVT[10];
	char DVT[10];
	float SLT;
};

typedef struct DSVT{
	int n;
	VATTU *nodes[MAXLIST];
};

int Search(DSVT &ds, char *x) {
  for (int i =0; i < ds.n ; i++)
     if (strcmp(ds.nodes[i]->MAVT, x) == 0) return i;
  return -1;
}

void NhapDSVT(DSVT &ds, int flag){
	VATTU *p;
	VATTU vattu;
	p = &vattu;

	if(flag == 0){
		while(ds.n > 0){
			delete ds.nodes[(ds.n)-1];
			ds.n--;
		}
	}
	
	while (ds.n <MAXLIST)
 {  
   cout << "Nhap ma so (0 la ket thuc) : " ; 
   string x;
   cin.ignore();
   getline(cin,x);
   strcpy(vattu.MAVT,x.c_str());
   if (strcmp(vattu.MAVT, "0") == 0) break;
   if (Search(ds, vattu.MAVT)>=0){
       BaoLoi ("Ma vat tu bi trung");
       continue;
   }
    NhapChuoi (  "Nhap Ten Vat tu: ", vattu.TENVT);
    NhapChuoi (  "Nhap Don vi tinh: ", vattu.DVT);
	NhapTonKho (  "Nhap So luong ton: ", vattu.SLT);
    ds.nodes[ds.n]= new VATTU;
    *ds.nodes[ds.n] = *p;
    ds.n++;
}
}

void LietKe(DSVT &dsvt){
	
	for (int i = 0; i< dsvt.n;i++){
		cout<< "Vat tu thu " << i+1 <<": ";
		cout<<dsvt.nodes[i]->MAVT << " ";
		cout<<dsvt.nodes[i]->TENVT <<" ";
		cout<<dsvt.nodes[i]->DVT<<" ";
		cout<<dsvt.nodes[i]->SLT<<" ";
		cout<<endl;
	}
	string x;
	cout<<"Nhap phim Enter de thoat ra :))";
	getline(cin,x);
}
void XoaVatTu(DSVT &ds, char *maso){
   int i = Search (ds,maso) ;
   if (i==-1) BaoLoi("Ma so vat tu khong co trong danh sach");
   else  
   {
   	delete ds.nodes[i];
     for (int j=i+1; j <ds.n; j++)
       ds.nodes[j-1]=ds.nodes[j];
     ds.n--;  
	}
}
