#include "KhachHang.h"


KhachHang::KhachHang() {
	this->ngay = 0;
	this->thang = 0;
	this->nam = 0;
	this->gio = 0;
	this->phut = 0;
	this->giay = 0;
	this->id = " ";
	this->tiengui = 0;
}


istream& operator >> (istream& in, KhachHang& a) {
	cout << "nhap id khach: ";
	in >> a.id;
	in.ignore();
	return in;
}

void KhachHang::show() {
	cout << setw(6) << "Khach hang: " << this->id << endl;
}

