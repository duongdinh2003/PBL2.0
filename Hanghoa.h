#ifndef Hanghoa_H
#define Hanghoa_H
#include "DSLK.h"
#include "Khachhang.h"
#include "MyLib.h"
using namespace std;

class HangHoa {
protected:
	string tensp;
	int soluong;
	long gianhap;
	long giaban;
	static int a;
public:
	HangHoa();
	HangHoa(string, int, long, long);
	HangHoa(string, int, long);
	void reset();
	void show_ungianhap();
	void show();
	int Getsoluong();
	void Setsoluong(int);
	long Getgiaban();
	void Setgiaban(long);
	long Getgianhap();
	void Setgianhap(long);
	string Gettensp();
	friend bool checksoluong(List<HangHoa>, string, int);
	friend istream& operator >> (istream&, HangHoa&);
	friend int LinearSearch(List<HangHoa>, string);
	friend void ChangeSoluong(List<HangHoa>&, string, int);
	friend long Getgiaban1(List<HangHoa>, string);
	friend long Getgianhap1(List<HangHoa>, string);
	void ghiFile(List<HangHoa>, string);
	void docFile(List<HangHoa>&, string);
	bool checkFile(string);
};

#endif // !Hanghoa_H