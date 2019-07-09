#include <iostream>
#include <string>
#include "mylib.h"
#include "common.h"

using namespace std;

/** **/
struct NHANVIEN {
	int MANV;
	string HO;
	string TEN;
	string PHAI;
	ListHD listHD;
	int nListHD = 0;
};

struct NODENV {
	NHANVIEN nhanvien;
	struct NODENV *pLeft;
	struct NODENV *pRight;
}

typedef struct NodeNV NODENV;
typedef NODENV* Tree;
