#include "MyLib.h"
#include "Console.h"
#include "DSLK.h"
#include "Hanghoa.h"
#include "Hoadon.h"
#define MAUNEN 229
#define MAUCHU 15
typedef char str[100];

void Begin() {
	cout << endl << endl;
	cout << "\t\t\t\t\t\t_____________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t|\tPBL2: DO AN CO SO LAP TRINH                                 |" << endl;
	cout << "\t\t\t\t\t\t|\tDE TAI: QUAN LY CUA HANG TAP HOA                            |" << endl;
	cout << "\t\t\t\t\t\t|\tLHP: 21Nh11 - NHOM: 41                                      |" << endl;
	cout << "\t\t\t\t\t\t|\tGVHD: DANG HOAI PHUONG                                      |" << endl;
	cout << "\t\t\t\t\t\t|\tSINH VIEN THUC HIEN: LE HOANH DUONG DINH   LSH: 21TCLC_DT3  |" << endl;
	cout << "\t\t\t\t\t\t|\t                     NGUYEN NHAT MINH      LSH: 21TCLC_DT3  |" << endl;
	cout << "\t\t\t\t\t\t|___________________________________________________________________|" << endl;
}
		
str luachon[6] = { "QUAN LY DANH SACH HANG HOA                      ", "NHAP HANG TU KHO VE CUA HANG                    ", "XUAT HOA DON                                    ", "QUAN LY HOA DON                                 ", "QUAN LY THU CHI CUA HANG                        ", "KET THUC CHUONG TRINH                           " };
str lc1[4] = { "DANH SACH HOA DON DA XUAT  ","TIM KIEM THEO MA HOA DON   ","TIM KIEM THEO MA KHACH HANG","QUAY VE                    " };
str lc2[4] = { "CHI PHI NHAP HANG                      ","DOANH THU CUA HANG                     ","LOI NHUAN TREN SAN PHAM BAN RA         ","QUAY VE                                " };
																																			 
enum TRANGTHAI { UP, DOWN, LEFT, RIGHT, ENTER, BACK };
void danhsach_KhoHang()
{
	cout << "\n\t\t\t\t\t\t\tDanh sach cac kho hang kha dung" << endl;
	cout << "\n\t\t\t\t\t\t\t-Khohang1" << endl;
	cout << "\t\t\t\t\t\t\t-Khohang2" << endl;
	cout << "\t\t\t\t\t\t\t-Khohang3" << endl;
}

string NhapFile(string file)
{
	cout << "\n\t\t\t\t\t\t\tNhap ten file tuong ung voi kho hang (Nhap theo cu phap: ten_kho_hang.txt): ";
	getline(cin, file);
	return file;
}


TRANGTHAI key(int z)
{
	if (z == 224)
	{
		char c;
		c = _getch();
		if (c == 72)
			return UP;
		if (c == 80)
			return DOWN;
		if (c == 77)
			return RIGHT;
		if (c == 75)
			return LEFT;
	}
	else if (z == 13)
		return ENTER;
}
string filename;
long long chiphinhap = 0;
int menu(str luachon[6], int n)
{
	int pos[5] = { 0,0,0,0,0 };
	List<HoaDon> lhd;
	List<HangHoa> khohang;
	int tt = 0, tt1 = 0, tt2 = 0;
	int m = 1, m1 = 1, m2 = 1;
	int* mau = new int[n];
	int tieude;
	for (int i = 0; i < n; i++)
		mau[i] = MAUCHU;
	mau[0] = MAUNEN;
	tieude = MAUCHU;
	while (1)
	{
		system("cls");
		Begin();
		TextColor(tieude);
		cout << "\t\t\t\t\t\t\t";
		TextColor(tieude);
		cout << "-----------------------MENU------------------------" << endl;
		for (int i = 0; i < n; i++)
		{
			TextColor(mau[i]);
			cout << "\t\t\t\t\t\t\t" << i + 1 << ". " << luachon[i] << endl;
		}
		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai)
		{
		case UP:
		{
			if (tt == 0)
			{
				tt = n - 1;
				m = n;
			}
			else {
				tt--;
				m--;
			}
			break;
		}
		case DOWN:
		{
			if (tt == n - 1)
			{
				tt = 0;
				m = 1;
			}
			else {
				tt++;
				m++;
			}
			break;
		}
		case ENTER:
		{
			cout << endl;
			do
			{
				switch (m)
				{
				case 1:
				{
					system("cls");
					if (pos[1] == 0) {
						cout << "\t\t\t\t\t\t\tban chua nhap buoc so 2 !!!" << endl;
						system("pause");
						goto again;
					}
					pos[0] = 1;
					List<HangHoa> lhh;
					HangHoa x;
					ifstream input(filename);
					if (input.peek() == ifstream::traits_type::eof()) { 
						cout << "\t\t\t\t\t\t\tKHO HANG BI TRONG!" << endl; 
						for (int i = 0; i < 5; i++) {
							pos[i] = 0;
							system("pause");
							goto again;
						}
					}
					else
					{
						x.docFile(lhh, filename);
						cout << setw(10) << "\n\n\t\t\t\t\t\t\t\t\t\t\tDANH SACH CAC MAT HANG CO SAN TAI CUA HANG" << endl;
						cout << setw(10) << "\t\t\t\t\t\t\t____________________________________________________________________________________________________________" << endl;
						cout << "\t\t\t\t\t\t\t|  " << setw(5) << "  STT    |" << setw(14) << "    Ten san pham" << right << setw(7) << "|" << setw(15) << "So luong" << right << setw(7) << "|" << setw(15) << "Gia nhap" << setw(10) << "  |" << setw(15) << "Gia ban" << setw(10) << "  |" << endl;
						cout << setw(10) << "\t\t\t\t\t\t\t____________________________________________________________________________________________________________" << endl;
						lhh.Show();
						x.reset();

						Node <HangHoa>* c = lhh.GetHead();
						
						while (c != NULL) {
							chiphinhap += c->data.Getgianhap() * c->data.Getsoluong();
							c = c->Next;
						}
					}
					
					system("pause");
					goto again;
				}
				case 2:
				{
					pos[1] = 1;
					system("cls");
					List<HangHoa> l;
					danhsach_KhoHang();
				
			dc:		filename = NhapFile(filename);
					ifstream isf(filename);
					if (!isf.good()) {
						cout << "\t\t\t\t\t\t\tFILE KHONG TON TAI!" << endl<<"\t\t\t\t\t\t\tMOI NHAP LAI!"<<endl;
						goto dc;
					}
					else cout << "\n\t\t\t\t\t\t\tDA NHAP KHO HANG!" << endl;
					system("pause");
					goto again;
				}
				case 3:
				{
					if ( pos[0] == 0) {
						if (pos[1] == 0) cout << "\t\t\t\t\t\t\tban chua nhap buoc 1 va 2! " << endl;
						else cout << "\t\t\t\t\t\t\tban chua nhap buoc 1!" << endl;
						system("pause");
						goto again;
					}
					pos[2] = 1;
					List<HangHoa> lhh;
					HoaDon hd;
					HangHoa x;
					system("cls");
					x.docFile(lhh, filename);
					hd.Input(lhh);
					hd.show_HD();
					x.ghiFile(lhh, filename);
					hd.ghiFile_LSBH();
					lhd.InsertLast(hd);
					x.reset();
					system("pause");
					goto again;
				}
				case 4:
				{		
					if (pos[2] == 0) {
						cout << "ban chua nhap buoc 3! " << endl;
						system("pause");
						goto again;
					}
					system("cls");
					int* mau1 = new int[4];
					for (int i = 0; i < 4; i++)
						mau1[i] = MAUCHU;
					mau1[0] = MAUNEN;
					while (1)
					{
						system("cls");
						cout << endl;
						for (int i = 0; i < 4; i++)
						{
							TextColor(mau1[i]);
							cout << "\t\t\t\t\t\t\t" << i + 1 << ". " << lc1[i] << endl;
						}
						int z = _getch();
						TRANGTHAI trangthai1 = key(z);
						switch (trangthai1)
						{
						case UP:
						{
							if (tt1 == 0)
							{
								tt1 = 3;
								m1 = 4;
							}
							else {
								tt1--;
								m1--;
							}
							break;
						}
						case DOWN:
						{
							if (tt1 == 3)
							{
								tt1 = 0;
								m1 = 1;
							}
							else {
								tt1++;
								m1++;
							}
							break;
						}
						case ENTER:
						{
							cout << endl;
							do
							{
								switch (m1)
								{
								case 1:
								{
									system("cls");							
									lhd.Show();
									cout << endl;
									system("pause");
									goto again1;
								}
								case 2:
								{
									system("cls");
									SearchMHD(lhd);
									system("pause");
									goto again1;
								}
								case 3:
								{
									system("cls");
									SearchMKH(lhd);
									system("pause");
									goto again1;
								}
								case 4:
								{
									goto again;
								}
								}
							} while (1);
						}
						}	
					again1:
						for (int i = 0; i < 4; i++)
							mau1[i] = MAUCHU;
						mau1[tt1] = MAUNEN;
					}
					delete[] mau1;
				}
				case 5:
				{
					if (pos[2] == 0) {
						cout << "ban chua nhap buoc 3! " << endl;
						system("pause");
						goto again;
					}
					system("cls");
					int* mau2 = new int[4];
					for (int i = 0; i < 4; i++)
						mau2[i] = MAUCHU;
					mau2[0] = MAUNEN;
					while (1)
					{
						system("cls");
						cout << endl;
						for (int i = 0; i < 4; i++)
						{
							TextColor(mau2[i]);
							cout << "\t\t\t\t\t\t\t" << i + 1 << ". " << lc2[i] << endl;
						}
						int z = _getch();
						TRANGTHAI trangthai2 = key(z);
						switch (trangthai2)
						{
						case UP:
						{
							if (tt2 == 0)
							{
								tt2 = 3;
								m2 = 4;
							}
							else {
								tt2--;
								m2--;
							}
							break;
						}
						case DOWN:
						{
							if (tt2 == 3)
							{
								tt2 = 0;
								m2 = 1;
							}
							else {
								tt2++;
								m2++;
							}
							break;
						}
						case ENTER:
						{
							cout << endl;
							do
							{
								switch (m2)
								{
								case 1:
								{
									system("cls");
									cout << "\t\t\t\t\t\t\tChi phi nhap kho la : " << chiphinhap << endl;
									system("pause");
									goto again2;
								}
								case 2:
								{
									system("cls");
									List<HangHoa> lhh;
									HangHoa x;
									x.docFile(lhh, filename);
									show_gianhap(lhd, chiphinhap);
									x.reset();
									system("pause");
									goto again2;
								}
								case 3:
								{
									system("cls");
									List<HangHoa> lhh;
									HangHoa x;
									x.docFile(lhh, filename);
									show_loinhuan(lhd);
									x.reset();
									system("pause");
									goto again2;
								}
								case 4:
								{
									goto again;
								}
								}
							} while (1);
						}
						}
					again2:
						for (int i = 0; i < 4; i++)
							mau2[i] = MAUCHU;
						mau2[tt2] = MAUNEN;
					}
					delete[] mau2;
				}
				case 6:
				{
					return 0;
				}
				}
			} while (1);
		}
		}
	again:
		for (int i = 0; i < n; i++)
			mau[i] = MAUCHU;
		mau[tt] = MAUNEN;
	}
	delete[] mau;
}
