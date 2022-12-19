/*#include "HoaDon.h"
#include <ctime>
#define _CRT_SECURE_NO_WARNINGS

int HoaDon::count = 1;


HoaDon::HoaDon() {
	this->tongtien = 0;
}

void HoaDon::Input(List<HangHoa>& a, List <HangHoa>& b) {
	cout << "nhap id khach hang: ";
	cin >> this->id;
	cin.ignore();
	cout << "nhap so tien khach gui: ";
	cin >> this->tiengui;
	cout << "Nhap thoi gian giao dich: " << endl;
	SetUpDate();
	bool e = 1;
	while (e == 1) {
		cin.ignore();
		cout << "nhap ten san pham muon mua: ";
		getline(cin, this->tensp);
		if (LinearSearch(a, tensp) != -1) {
			cout << "nhap so luong: ";
			cin >> this->soluong;
			cin.ignore();
			ChangeSoluong(a, this->tensp, this->soluong);
			this->giaban = this->soluong * Getgiaban(a, tensp);
			tongtien += this->giaban;
			HangHoa temp(this->tensp, this->soluong, this->giaban);
			b.InsertLast(temp);
			cout << "ban co muon tiep tuc mua khong: 1(co),0(khong): ";
			cin >> e;
		}
		else cout << "eu co hang nha ma" << endl;
	}
}


void HoaDon::show(List <HangHoa> b)
{
//	time_t now = time(0);
//	tm* tg = localtime(&now);
	Node <HangHoa>* c = b.GetHead();
	cout << "SIEU THI BINH DUONG                \t D/c: Doc la Binh Duong" << endl;
//	cout << "Xuat ngay: " << tg->tm_mday << "/" << 1 + tg->tm_mon << "/" << 1900 + tg->tm_year << " luc: " << tg->tm_hour << ":" << tg->tm_min << ":" << tg->tm_sec << endl;
	cout << "Xuat ngay: " << this->ngay;
	cout << " luc: " << this->thoigian << endl;
	cout << "-------------------HoaDon cua khach hang: " << this->id << "----------------------" << endl;
	while (c != NULL) {
		c->data.show();
		c = c->Next;
	}
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Tong tien: " << right << setw(37) << this->tongtien << endl;
	cout << "Tien khach gui: " << right << setw(32) << this->tiengui << endl;
	cout << "So tien tra lai: " << right << setw(31) << tiengui - tongtien << endl;
}
void HoaDon::ghiFile_LSBH(List<HangHoa> l)
{
	ofstream infile("LichSuBanHang.txt", ios::app);
	Node<HangHoa>* b = NULL;
	b = l.GetHead();
	if (b != NULL)
	{
		infile << "Ma hoa don: " << ++(this->count) << endl;
		infile << "SIEU THI BINH DUONG                \t D/c: Doc la Binh Duong" << endl;
	//	infile << "Xuat ngay: " << tg->tm_mday << "/" << 1 + tg->tm_mon << "/" << 1900 + tg->tm_year << " luc: " << tg->tm_hour << ":" << tg->tm_min << ":" << tg->tm_sec << endl;
		infile << "Xuat ngay: " << this->ngay;
		infile << " luc: " << this->thoigian << endl;
		infile << "-------------------HoaDon cua khach hang: " << this->id << "----------------------" << endl;
		while (b != NULL)
		{
			infile << b->getData().a << ": " << setw(15) << b->getData().tensp << right << setw(15) << b->getData().soluong << right << setw(15) << b->getData().giaban << endl;
			b = b->Next;
		}
		infile << "Tong tien: " << right << setw(37) << this->tongtien << endl;
		infile << "Tien khach gui: " << right << setw(32) << this->tiengui << endl;
		infile << "So tien tra lai: " << right << setw(31) << tiengui - tongtien << endl;
		infile << "------------------------------------------------------------------------------------------" << endl;
	}
	infile.close();
}*/
#define _CRT_SECURE_NO_WARNINGS
#include "Hoadon.h"
int HoaDon::count = 1;


HoaDon::HoaDon() {
	this->tongtien = 0;
}

void HoaDon::Input(List<HangHoa>& a, List <HangHoa>& b) {
	cout << "nhap id khach hang (VD: KH____): ";
	cin >> this->id;
	cin.ignore();
	cout << "nhap so tien khach gui: ";
	cin >> this->tiengui;
	bool e = 1;
label:	while (e == 1) {
	cin.ignore();
	cout << "nhap ten san pham muon mua: ";
	getline(cin, this->tensp);
	if (LinearSearch(a, tensp) != -1) {
		cout << "nhap so luong: ";
		cin >> this->soluong;
		if (checksoluong(a, tensp, soluong) == 0) {
			cout << "san pham cua ban da het so luong!" << endl;
			cout << "ban co muon tiep tuc mua khong: 1(co),0(khong): ";
			cin >> e;
			goto label;
		}
		giaban = this->soluong * Getgiaban1(a, tensp);
		tongtien += giaban;
		if (tiengui < tongtien) {
			tongtien -= giaban;
			cout << "so tien ban ko du de mua san pham nay! " << endl;
			cout << "ban co muon tiep tuc mua khong: 1(co),0(khong): ";
			cin >> e;
			goto label;
		}
		ChangeSoluong(a, tensp, soluong);
		Node <HangHoa>* c = b.GetHead();
		while (c != NULL) {
			if (c->getData().Gettensp() == tensp) {
				c->data.Setsoluong(c->getData().Getsoluong() + soluong);
				c->data.Setgiaban(c->getData().Getsoluong() * Getgiaban1(a, tensp));
				cout << "ban co muon tiep tuc mua khong: 1(co),0(khong): ";
				cin >> e;
				goto label;
			}
			c = c->Next;
		}
		HangHoa temp(this->tensp, this->soluong, this->giaban);
		b.InsertLast(temp);
		cout << "ban co muon tiep tuc mua khong: 1(co),0(khong): ";
		cin >> e;

	}
	else cout << "da het hang" << endl;
}
}


void HoaDon::show(List <HangHoa> b) {
	time_t now = time(0);
	tm* tg = localtime(&now);
	this->ngay = tg->tm_mday;
	this->thang = 1 + tg->tm_mon;
	this->nam = 1900 + tg->tm_year;
	this->gio = tg->tm_hour;
	this->phut = tg->tm_min;
	this->giay = tg->tm_sec;
	Node <HangHoa>* c = b.GetHead();
	cout << "\t\t\t\t\t\t\t---------------------------HoaDon cua khach hang: " << this->id << "----------------------------" << endl << endl;
	cout << "\t\t\t\t\t\t\tXuat ngay: " << this->ngay << "/" << this->thang << "/" << this->nam << " luc: " << this->gio << ":" << this->phut << ":" << this->giay << endl << endl;
	cout << "\t\t\t\t\t\t\t___________________________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t|  " << setw(5) << "  STT    |" << setw(14) << "    Ten san pham" << right << setw(7) << "|" << setw(15) << "so luong" << right << setw(7) << "|" << setw(15) << "so tien" << setw(10) << "  |" << endl;
	cout << "\t\t\t\t\t\t\t___________________________________________________________________________________" << endl;
	while (c != NULL) {
		c->data.show();
		c = c->Next;
	}
	cout << "\t\t\t\t\t\t\t-----------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\tTong tien: " << right << setw(62) << this->tongtien << endl;
	cout << "\t\t\t\t\t\t\tTien khach gui: " << right << setw(57) << fixed << this->tiengui << endl;
	cout << "\t\t\t\t\t\t\tSo tien tra lai: " << right << setw(56)  << (tiengui - tongtien) << endl;
	delete[] c;
}

void HoaDon::ghiFile_LSBH(List<HangHoa> l)
{
	int d = 0;
	ofstream infile("LichSuBanHang.txt", ios::app);
	Node<HangHoa>* b = NULL;
	b = l.GetHead();
	if (b != NULL)
	{
		infile << "Ma hoa don: " << ++(this->count) << endl;
		infile << "CUA HANG TIEN LOI SINH VIEN                \t D/c: 75 Nguyen Luong Bang," << endl;
		infile << "                                                  Lien Chieu, TP Da Nang" << endl;
		infile << "Xuat ngay: " << this->ngay << "/" << this->thang << "/" << this->nam << " luc: " << this->gio << ":" << this->phut << ":" << this->giay << endl;
		infile << "---------------------------HoaDon cua khach hang: " << this->id << "----------------------------" << endl;
		infile << "|  " << setw(5) << "  STT    |" << setw(14) << "    Ten san pham" << right << setw(7) << "|" << setw(15) << "so luong" << right << setw(7) << "|" << setw(15) << "so tien" << setw(10) << "  |" << endl;
		while (b != NULL)
		{
			infile << "|  " << setw(5) << ++d << "    |" << setw(20) << b->getData().Gettensp() << right << setw(3) << "|" << setw(15) << b->getData().Getsoluong() << right << setw(7) << "|" << setw(15) << b->getData().Getgiaban() << setw(10) << "  |" << endl;
			b = b->Next;
		}
		infile << "Tong tien: " << right << setw(62) << this->tongtien << endl;
		infile << "Tien khach gui: " << right << setw(57) << this->tiengui << endl;
		infile << "So tien tra lai: " << right << setw(56) << tiengui - tongtien << endl;
		infile << "------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	infile.close();
}

long HoaDon::getTongTien()
{
	return this->tongtien;
}