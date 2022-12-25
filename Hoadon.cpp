#define _CRT_SECURE_NO_WARNINGS
#include "Hoadon.h"


HoaDon::HoaDon() {
	Node <HangHoa>* c = this->HD.GetHead();
	c = NULL;
	this->check = 1;
	this->tongtien = 0;
	this->chiphi1 = 0;
}

void HoaDon::Input(List<HangHoa>& a) {
	tongtien = 0;
	cout << "\n\n\n\n\n";
	cout << "Nhap ma hoa don (VD:HD____):  ";
	cin >> this->ID_hd;
	cin.ignore();
	cout << "Nhap id khach hang (VD: KH____): ";
	cin >> this->id;
	int e = 1;
label:	while (e == 1) {
	cin.ignore();
	cout << "Nhap ten san pham muon mua: ";
	getline(cin, this->tensp);
	if (LinearSearch(a, tensp) != -1) {
		cout << "Nhap so luong: ";
		cin >> this->soluong;
		if (checksoluong(a, tensp, soluong) == 0) {
			cout << "San pham cua ban da het so luong!" << endl;
			do {
				cout << "Ban co muon tiep tuc mua khong: 1(co), 0(khong): ";
				cin >> e;
				if (e > 1 || e < 0) cout << "So khong dung quy dinh!" << endl;
			} while (e > 1 || e < 0);
			if (e == 0) { 
				this->check = 0;
				return; 
			}
			goto label;
		}
		giaban = this->soluong * Getgiaban1(a, tensp);
		gianhap = this->soluong * Getgianhap1(a, tensp);
		tongtien += giaban;
		chiphi1 += gianhap;
		ChangeSoluong(a, tensp, soluong);
		Node <HangHoa>* c = this->HD.GetHead();
		while (c != NULL) {
			if (c->data.Gettensp() == tensp) {
				c->data.Setsoluong(c->data.Getsoluong() + soluong);
				c->data.Setgianhap(c->data.Getsoluong() * Getgianhap1(a, tensp));
				c->data.Setgiaban(c->data.Getsoluong() * Getgiaban1(a, tensp));
				cout << "Ban co muon tiep tuc mua khong: 1(co), 0(khong): ";
				cin >> e;
				goto label;
			}
			c = c->Next;
		}
		HangHoa temp(this->tensp, this->soluong, this->gianhap, this->giaban);
		HD.InsertLast(temp);
		do {
			cout << "Ban co muon tiep tuc mua khong: 1(co), 0(khong): ";
			cin >> e;
			if (e > 1 || e < 0) cout << "So khong dung quy dinh" << endl;
		} while (e > 1 || e < 0);

	}
	else {
		cout << "Da het hang!" << endl;
		do {
			cout << "Ban co muon tiep tuc mua khong: 1(co), 0(khong): ";
			cin >> e;
			if (e > 1 || e < 0) cout << "So khong dung quy dinh" << endl;
		} while (e > 1 || e < 0);
		if (e == 0) { 
			this->check = 0;
			return; 
		}
	}
}
	cout << "Tong tien cua ban la: " << tongtien << endl;
	bool choice = 1;
label5:	while (choice == 1) {
	do {
		cout << "Nhap so tien khach gui: ";
		cin >> this->tiengui;
		if (tiengui < 4000) cout << "So tien chua dat muc toi thieu !" << endl;
	} while (tiengui < 4000);
	label3:		if (tiengui < tongtien) {
		cout << "So tien ban gui khong du !" << endl;
		cout << "Ban co muon nhap lai so tien khong hoac xoa bot mon hang: 1(nhap lai tien), 0(xoa bot hang/so luong): ";
		cin >> choice;
		if (choice == 1) goto label5;
		cin.ignore();
		if (choice == 0) {
			Node <HangHoa>* c = this->HD.GetHead();
			cout << "\t\t\t\t\t\t\t---------------------------HoaDon cua khach hang: " << this->id << "----------------------------" << endl;
			cout << "\t\t\t\t\t\t\t|  " << setw(5) << "  STT    |" << setw(14) << "    Ten san pham" << right << setw(7) << "|" << setw(15) << "so luong" << right << setw(7) << "|" << setw(15) << "so tien" << setw(10) << "  |" << endl;
			cout << "\t\t\t\t\t\t\t___________________________________________________________________________________" << endl;
			int dem = 0;
			while (c != NULL) {
				cout << "\t\t\t\t\t\t\t|  " << setw(5) << ++dem << "    |" << setw(20) << c->data.Gettensp() << right << setw(3) << "|" << setw(15) << c->data.Getsoluong() << right << setw(7) << "  |" << setw(15) << c->data.Getgiaban() << setw(10) << "  |" << endl;
				cout << setw(10) << "\t\t\t\t\t\t\t___________________________________________________________________________________" << endl;
				c = c->Next;
			}
			cout << "\t\t\t\t\t\t\t-----------------------------------------------------------------------------------" << endl;
			cout << "\t\t\t\t\t\t\tTong tien: " << right << setw(62) << this->tongtien << endl;
			bool choice2 = 1;
		label4:				cout << "Ban muon xoa hang hay giam so luong: 1(xoa), 0(giam): ";
			cin >> choice2;
			string k;
			cin.ignore();
			cout << "Chon ten hang ban can xoa/giam so luong: ";
			getline(cin, k);
			Node <HangHoa>* d = this->HD.GetHead();
			if (d->Next == NULL && choice2 == 1) {
				cout << "Ban khong the xoa san pham vi ban chi co 1 san pham !" << endl;
				goto label4;
			}
			while (d != NULL) {
				if (d->data.Gettensp() == k) {
					if (choice2 == 0) {
						int z;
						do {
							cout << "Nhap so luong ban muon giam: ";
							cin >> z;
							if (z >= d->data.Getsoluong()) cout << "So lieu can xoa khong hop le !" << endl;
						} while (z >= d->data.Getsoluong());
						tongtien -= z * (d->data.Getgiaban() / d->data.Getsoluong());
						chiphi1 -= z * (d->data.Getgianhap() / d->data.Getsoluong());
						d->data.Setgiaban((d->data.Getgiaban() * (d->data.Getsoluong() - z)) / d->data.Getsoluong());
						d->data.Setgianhap(d->data.Getgianhap() * (d->data.Getsoluong() - z) / d->data.Getsoluong());
						d->data.Setsoluong(d->data.Getsoluong() - z);
						ChangeSoluong(a, k, -z);
						goto label3;
					}
					else {
						if (d->Pre == NULL) {
							ChangeSoluong(a, k, -d->data.Getsoluong());
							tongtien -= d->data.Getgiaban();
							chiphi1 -= d->data.Getgianhap();
							Node <HangHoa>* p = d->Next;
							Node <HangHoa>* temp = d;
							p->Pre = NULL;
							d = p;
							HD.SetHead(d);
							goto label3;
						}
						if (d->Next == NULL) {
							ChangeSoluong(a, k, -d->data.Getsoluong());
							tongtien -= d->data.Getgiaban();
							chiphi1 -= d->data.Getgianhap();
							Node<HangHoa>* p = d->Pre;
							Node <HangHoa>* temp = d;
							p->Next = NULL;
							d = p;
							goto label3;
						}
						else {
							ChangeSoluong(a, k, -d->data.Getsoluong());
							tongtien -= d->data.Getgiaban();
							chiphi1 -= d->data.Getgianhap();
							Node <HangHoa>* p = d->Pre;
							Node <HangHoa>* temp = d;
							Node <HangHoa>* p2 = temp->Next;
							p->Next = p2;
							p2->Pre = p;
							goto label3;
						}
					}
				}
				d = d->Next;
			}
		}
	}
	choice = 0;
	}

}

void show_loinhuan(List <HoaDon>& a) {
	long doanhthu = 0;
	long chiphi = 0;
	int test = 0;
	int test2 = 0;
	Node<HoaDon>* hihi = a.GetHead();
	while (hihi != NULL) {
		if (hihi->data.check == 0) {
			cout << "khach hang nay khong mua hang nen khong co hoa don !" << endl;
			test++;
		}
		else test2++;
		hihi = hihi->Next;
	}
	if (test == test2) return;
	Node<HoaDon>* c = a.GetHead();
	List<HangHoa> temp;
	while (c != NULL) {
		Node <HangHoa>* k = c->data.HD.GetHead();
		while (k != NULL) {
			HangHoa temp2(k->data.Gettensp(), k->data.Getsoluong(), k->data.Getgianhap(), k->data.Getgiaban());
			temp.InsertLast(temp2);
			k = k->Next;
		}
		c = c->Next;
	}

	for (Node<HangHoa>* i = temp.GetHead(); i != NULL; i = i->Next) {
		string str = i->data.Gettensp();
		for (Node<HangHoa>* j = i->Next; j != NULL; j = j->Next) {
			if (j->data.Gettensp() == str) {
				i->data.Setsoluong(i->data.Getsoluong() + j->data.Getsoluong());
				i->data.Setgianhap(i->data.Getgianhap() + j->data.Getgianhap());
				i->data.Setgiaban(i->data.Getgiaban() + j->data.Getgiaban());
				if (j->Next == NULL) {
					Node<HangHoa>* p = j->Pre;
					Node <HangHoa>* temp = j;
					p->Next = NULL;
					j = p;
				}
				else {
					Node <HangHoa>* p = j->Pre;
					Node <HangHoa>* temp = j;
					Node <HangHoa>* p2 = temp->Next;
					p->Next = p2;
					p2->Pre = p;
				}

			}
		}
	}


	Node <HangHoa>* hh2 = temp.GetHead();
	cout << setw(10) << "\n\n\t\t\t\t\t\t\t\t-----------------------------LOI NHUAN TREN TUNG SAN PHAM-------------------------------" << endl;
	cout << setw(10) << "\t\t\t\t\t\t\t____________________________________________________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t|  " << setw(5) << "  STT    |" << setw(14) << "    Ten san pham" << right << setw(7) << "|" << setw(15) << "So luong" << right << setw(7) << "|" << setw(15) << "Gia nhap" << setw(10) << "  |" << setw(15) << "Gia ban" << setw(10) << "  |" << endl;
	cout << setw(10) << "\t\t\t\t\t\t\t____________________________________________________________________________________________________________" << endl;
	while (hh2 != NULL) {
		hh2->data.show();
		doanhthu += hh2->data.Getgiaban();
		chiphi += hh2->data.Getgianhap();
		hh2 = hh2->Next;
	}

	cout << "\t\t\t\t\t\t\t------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\tDoanh thu: " << right << setw(87) << doanhthu << endl;
	cout << "\t\t\t\t\t\t\tChi phi nhap hang: " << right << setw(79) << chiphi << endl;
	cout << "\t\t\t\t\t\t\tLoi nhuan: " << right << setw(87) << doanhthu - chiphi << endl;
}



void show_gianhap(List <HoaDon>& a,long long chiphi) {
	int test = 0;
	int test2 = 0;
	long doanhthu = 0;
	Node<HoaDon>* hihi = a.GetHead();
	while (hihi != NULL) {
		if (hihi->data.check == 0) {
			cout << "khach hang nay khong mua hang nen khong co hoa don !" << endl;
			test++;
		}
		else test2++;
		hihi = hihi->Next;
	}
	if (test == test2) return;
	Node<HoaDon>* c = a.GetHead();
	List<HangHoa> temp;
	while (c != NULL) {
		Node <HangHoa>* k = c->data.HD.GetHead();
		while (k != NULL) {
			HangHoa temp2(k->data.Gettensp(), k->data.Getsoluong(), k->data.Getgianhap(), k->data.Getgiaban());
			temp.InsertLast(temp2);
			k = k->Next;
		}
		c = c->Next;
	}

	for (Node<HangHoa>* i = temp.GetHead(); i != NULL; i = i->Next) {
		string str = i->data.Gettensp();
		for (Node<HangHoa>* j = i->Next; j != NULL; j = j->Next) {
			if (j->data.Gettensp()==str) {
				i->data.Setsoluong(i->data.Getsoluong() + j->data.Getsoluong());
				i->data.Setgianhap(i->data.Getgianhap() + j->data.Getgianhap());
				i->data.Setgiaban(i->data.Getgiaban() + j->data.Getgiaban());
				if (j->Next == NULL) {
					Node<HangHoa>* p = j->Pre;
					Node <HangHoa>* temp = j;
					p->Next = NULL;
					j = p;

				}
				else {
					Node <HangHoa>* p = j->Pre;
					Node <HangHoa>* temp = j;
					Node <HangHoa>* p2 = temp->Next;
					p->Next = p2;
					p2->Pre = p;
				}

			}
		}
	}


	Node <HangHoa>* hh2 = temp.GetHead();
	cout << setw(10) << "\n\n\t\t\t\t\t\t\t\t-----------------------------------DOANH THU CUA QUAN-----------------------------------" << endl;
	cout << setw(10) << "\t\t\t\t\t\t\t____________________________________________________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t|  " << setw(5) << "  STT    |" << setw(14) << "    Ten san pham" << right << setw(7) << "|" << setw(15) << "So luong" << right << setw(7) << "|" << setw(15) << "Gia nhap" << setw(10) << "  |" << setw(15) << "Gia ban" << setw(10) << "  |" << endl;
	cout << setw(10) << "\t\t\t\t\t\t\t____________________________________________________________________________________________________________" << endl;
	while (hh2 != NULL) {
		hh2->data.show();
		doanhthu += hh2->data.Getgiaban();
		hh2 = hh2->Next;
	}

	cout << "\t\t\t\t\t\t\t------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\tDoanh thu: " << right << setw(87) << doanhthu << endl;
	cout << "\t\t\t\t\t\t\tChi phi nhap hang: " << right << setw(79) << chiphi << endl;
	cout << "\t\t\t\t\t\t\tLoi nhuan: " << right << setw(87) << doanhthu - chiphi << endl;
}


void HoaDon::show_HD() {

	if (this->check == 0) {
		cout << "khach hang nay khong mua nen khong xuat hoa don !" << endl;
		return;
	}
	int d = 0;
	time_t now = time(0);
	tm* tg = localtime(&now);
	this->ngay = tg->tm_mday;
	this->thang = 1 + tg->tm_mon;
	this->nam = 1900 + tg->tm_year;
	this->gio = tg->tm_hour;
	this->phut = tg->tm_min;
	this->giay = tg->tm_sec;
	Node <HangHoa>* c = this->HD.GetHead();
	cout << "\t\t\t\t\t\t\t---------------------------HoaDon cua khach hang: " << this->id << "----------------------------" << endl << endl;
	cout << "\t\t\t\t\t\t\tXuat ngay: " << this->ngay << "/" << this->thang << "/" << this->nam << " luc: " << this->gio << ":" << this->phut << ":" << this->giay << endl << endl;
	cout << "\t\t\t\t\t\t\t___________________________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t|  " << setw(5) << "  STT    |" << setw(14) << "    Ten san pham" << right << setw(7) << "|" << setw(15) << "so luong" << right << setw(7) << "|" << setw(15) << "so tien" << setw(10) << "  |" << endl;
	cout << "\t\t\t\t\t\t\t___________________________________________________________________________________" << endl;
	while (c != NULL) {
		cout << "\t\t\t\t\t\t\t|  " << setw(5) << ++d << "    |" << setw(20) << c->data.Gettensp() << right << setw(3) << "|" << setw(15) << c->data.Getsoluong() << right << setw(7) << "  |" << setw(15) << c->data.Getgiaban() << setw(10) << "  |" << endl;
		cout << setw(10) << "\t\t\t\t\t\t\t___________________________________________________________________________________" << endl;
		c = c->Next;
	}
	cout << "\t\t\t\t\t\t\t-----------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\tTong tien: " << right << setw(62) << this->tongtien << endl;
	cout << "\t\t\t\t\t\t\tTien khach gui: " << right << setw(57)  << this->tiengui << endl;
	cout << "\t\t\t\t\t\t\tSo tien tra lai: " << right << setw(56)  << (tiengui - tongtien) << endl;
	delete[] c;
}

void HoaDon::ghiFile_LSBH()
{
	int d = 0;
	ofstream infile("LichSuBanHang.txt", ios::app);
	Node<HangHoa>* b = NULL;
	b = HD.GetHead();
	if (b != NULL)
	{
		infile << "Ma hoa don: " << (this->ID_hd) << endl;
		infile << "CUA HANG TIEN LOI SINH VIEN                \t D/c: 75 Nguyen Luong Bang," << endl;
		infile << "                                                  Lien Chieu, TP Da Nang" << endl;
		infile << "Xuat ngay: " << this->ngay << "/" << this->thang << "/" << this->nam << " luc: " << this->gio << ":" << this->phut << ":" << this->giay << endl;
		infile << "---------------------------HoaDon cua khach hang: " << this->id << "----------------------------" << endl;
		infile << "|  " << setw(5) << "  STT    |" << setw(14) << "    Ten san pham" << right << setw(7) << "|" << setw(15) << "so luong" << right << setw(7) << "|" << setw(15) << "so tien" << setw(10) << "  |" << endl;
		while (b != NULL)
		{
			infile << "|  " << setw(5) << ++d << "    |" << setw(20) << b->data.Gettensp() << right << setw(3) << "|" << setw(15) << b->data.Getsoluong() << right << setw(7) << "|" << setw(15) << b->data.Getgiaban() << setw(10) << "  |" << endl;
			b = b->Next;
		}
		infile << "Tong tien: " << right << setw(62) << this->tongtien << endl;
		infile << "Tien khach gui: " << right << setw(57) << this->tiengui << endl;
		infile << "So tien tra lai: " << right << setw(56) << tiengui - tongtien << endl;
		infile << "------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	infile.close();
}

void SearchMKH(List <HoaDon> a) {
	string k;
	int count = 0;
	cout << "Nhap ma khach hang can tim: ";
	cin >> k;
	cin.ignore();
	Node<HoaDon>* b = a.GetHead();
	b->data.reset();
	while (b != NULL) {
		if (b->data.id == k) {
			b->data.show();
			count++;
			cout << endl;
			if (b == NULL) 
				return;
		}
		 b = b->Next;
	}
	if (count == 0) cout << "\t\t\t\t\t\t\tKHONG TIM THAY MA KHACH HANG NAY!" << endl;
}

void SearchMHD(List <HoaDon> a)
{
	string k;
	cout << "Nhap ma hoa don can tim: ";
	cin >> k;
	cin.ignore();
	Node<HoaDon>* b = a.GetHead();
	b->data.reset();
	while (b != NULL) {
		if (b->data.ID_hd == k) {
			b->data.show();
			cout << endl;
			return;
		}
		b = b->Next;
	}
	cout << "\t\t\t\t\t\t\tKHONG TIM THAY MA HOA DON NAY!" << endl;
}

void HoaDon::show()
{
	int d = 0;
	Node <HangHoa>* c = this->HD.GetHead();
	c->data.reset();
	cout << "\t\t\t\t\t\t\t--Ma hoa don: " << this->ID_hd << endl;
	cout << "\t\t\t\t\t\t\t---------------------------HoaDon cua khach hang: " << this->id << "----------------------------" << endl << endl;
	cout << "\t\t\t\t\t\t\tXuat ngay: " << this->getNgay() << "/" << this->getThang() << "/" << this->getNam() << " luc: " << this->getGio() << ":" << this->getPhut() << ":" << this->getGiay() << endl << endl;
	cout << "\t\t\t\t\t\t\t___________________________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t|  " << setw(5) << "  STT    |" << setw(14) << "    Ten san pham" << right << setw(7) << "|" << setw(15) << "so luong" << right << setw(7) << "|" << setw(15) << "so tien" << setw(10) << "  |" << endl;
	cout << "\t\t\t\t\t\t\t___________________________________________________________________________________" << endl;
	while (c != NULL) {
		cout << "\t\t\t\t\t\t\t|  " << setw(5) << ++d << "    |" << setw(20) << c->data.Gettensp() << right << setw(3) << "|" << setw(15) << c->data.Getsoluong() << right << setw(7) << "|" << setw(15) << c->data.Getgiaban() << setw(10) << "  |" << endl;
		cout << setw(10) << "\t\t\t\t\t\t\t___________________________________________________________________________________" << endl;
		c = c->Next;
	}
	cout << "\t\t\t\t\t\t\t-----------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\tTong tien: " << right << setw(62) << this->tongtien << endl;
	cout << "\t\t\t\t\t\t\tTien khach gui: " << right << setw(57) << this->tiengui << endl;
	cout << "\t\t\t\t\t\t\tSo tien tra lai: " << right << setw(56) << (tiengui - tongtien) << endl;
	cout << "\t\t\t\t\t\t-----------------------------------------------------------------------------------------------------" << endl << endl << endl;
	delete[] c;
}


long HoaDon::getTongTien()
{
	return this->tongtien;
}

int HoaDon::getNgay()
{
	return ngay;
}
int HoaDon::getThang()
{
	return thang;
}
int HoaDon::getNam()
{
	return nam;
}
int HoaDon::getGio()
{
	return gio;
}
int HoaDon::getPhut()
{
	return phut;
}
int HoaDon::getGiay()
{
	return giay;
}