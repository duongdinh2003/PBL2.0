#include "MyLib.h"
#include "Console.h"
#include "DSLK.h"
#include "Hanghoa.h"
#include "Hoadon.h"
#define MAUNEN 229
#define MAUCHU 15
typedef char str[100];
											                   
str luachon[6] = { "Xuat danh sach kho hang", "Nhap kho hang          ", "Xuat hoa don           ", "Tim kiem hoa don       ", "Doanh thu cua hang     ", "Thoat                  " };
str lc1[3] = { "TIM KIEM THEO MA HOA DON","TIM KIEM THEO MA KHACH HANG","QUAY VE" };
str lc2[3] = { "DOANH THU THEO NGAY","DOANG THU THEO THANG","QUAY VE" };
enum TRANGTHAI { UP, DOWN, LEFT, RIGHT, ENTER, BACK };
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
int menu(str luachon[6], int n)
{
	List<HoaDon> lhd;
	List<HangHoa> a, temp;
	HoaDon hd;
//	HangHoa x;
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
		clrscr();
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
					clrscr();
					List<HangHoa> lhh;
					HangHoa x;
					if (x.checkFile("Khohang.txt"))
					{
						x.docFile(lhh);
						cout << setw(10) << "\t\t\t\t\t\t\t\t\t\tDANH SACH CAC MAT HANG CO SAN TAI CUA HANG" << endl;
						cout << setw(10) << "\t\t\t\t\t\t\t___________________________________________________________________________________" << endl;
						cout << "\t\t\t\t\t\t\t|  " << setw(5) << "  STT    |" << setw(14) << "    Ten san pham" << right << setw(7) << "|" << setw(15) << "so luong" << right << setw(7) << "|" << setw(15) << "so tien" << setw(10) << "  |" << endl;
						cout << setw(10) << "\t\t\t\t\t\t\t___________________________________________________________________________________" << endl;
						lhh.Show();
					}
					else cout << "\t\t\t\t\t\t\tKHO HANG BI TRONG!" << endl;
					system("pause");
					goto again;
				}
				case 2:
				{
					clrscr();
					List<HangHoa> l;
					system("pause");
					goto again;
				}
				case 3:
				{
					List<HangHoa> lhh;
					HangHoa x;
					clrscr();
					x.docFile(lhh);
					hd.Input(lhh, temp);
					hd.show(temp);
				//	lhh.Show();
					x.ghiFile(lhh);
					hd.ghiFile_LSBH(temp);
					system("pause");
					goto again;
				}
				case 4:
				{
					clrscr();
					int* mau = new int[3];
				//	int tieude;
					for (int i = 0; i < 3; i++)
						mau[i] = MAUCHU;
					mau[0] = MAUNEN;
					while (1)
					{
						clrscr();
						//	TextColor(tieude);
						cout << endl;
						//	cout << "\t\t\t\t\t\t\t";
						//	TextColor(tieude);
						//	cout << "-----------------------MENU------------------------" << endl;
						for (int i = 0; i < 3; i++)
						{
							TextColor(mau[i]);
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
								tt1 = 3 - 1;
								m1 = 3;
							}
							else {
								tt1--;
								m1--;
							}
							break;
						}
						case DOWN:
						{
							if (tt1 == 3 - 1)
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
									clrscr();
									system("pause");
									goto again1;
								}
								case 2:
								{
									clrscr();
									system("pause");
									goto again1;
								}
								case 3:
								{
									goto again;
								}
								}
							} while (1);
						}
						}	
					again1:
						for (int i = 0; i < 3; i++)
							mau[i] = MAUCHU;
						mau[tt1] = MAUNEN;
					}
				}
				case 5:
				{
					clrscr();
					int* mau = new int[3];
					for (int i = 0; i < 3; i++)
						mau[i] = MAUCHU;
					mau[0] = MAUNEN;
					while (1)
					{
						clrscr();
						//	TextColor(tieude);
						cout << endl;
						//	cout << "\t\t\t\t\t\t\t";
						//	TextColor(tieude);
						//	cout << "-----------------------MENU------------------------" << endl;
						for (int i = 0; i < 3; i++)
						{
							TextColor(mau[i]);
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
								tt2 = 3 - 1;
								m2 = 3;
							}
							else {
								tt2--;
								m2--;
							}
							break;
						}
						case DOWN:
						{
							if (tt2 == 3 - 1)
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
									clrscr();
									system("pause");
									goto again2;
								}
								case 2:
								{
									clrscr();
									system("pause");
									goto again2;
								}
								case 3:
								{
									goto again;
								}
								}
							} while (1);
						}
						}
					again2:
						for (int i = 0; i < 3; i++)
							mau[i] = MAUCHU;
						mau[tt2] = MAUNEN;
					}
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