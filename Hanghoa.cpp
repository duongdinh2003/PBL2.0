/*#include "HangHoa.h"
#include "Hoadon.h"
/*
void HangHoa::Input(List<HangHoa>& a,List<HangHoa> &b) {
	cin.ignore();
	cout << "nhap id khach hang: ";
	cin >> this->id;
	int e = 1;
	while (e == 1) {
		cout << "nhap ten san pham muon mua: ";
		getline(cin, this->tensp);
		if (LinearSearch(a, tensp) != 1) {
			cout << "nhap so luong: ";
			cin >> this->soluong;
			ChangeSoluong(a, this->tensp, this->soluong);
			this->giaban = this->soluong * Getgiaban(a, tensp);
			HangHoa temp(this->tensp, this->soluong, this->giaban);
			b.InsertLast(temp);
		}
	}
}


int LinearSearch(List<HangHoa> a, string tensp) {
	int temp = 0;
	Node<HangHoa>* b = a.GetHead();
	while (b != NULL) {
		if (b->data.tensp == tensp) {
			return temp;
		}
		++temp;
		b = b->Next;
	}
	return -1;
}

void ChangeSoluong(List<HangHoa>& a, string tensp, int i)
{
	Node <HangHoa>* b = a.GetHead();
	while (b != NULL) {
		if (b->data.tensp == tensp) {
			if (b->data.soluong >= i) {
				b->data.soluong -= i;
				break;
			}
			else throw "so hang ko du!";
		}
		b = b->Next;
	}
}

float Getgiaban(List<HangHoa> a, string tensp) {
	Node <HangHoa>* b = a.GetHead();
	while (b != NULL) {
		if (b->data.tensp == tensp) {
			return b->data.giaban;
		}
		b = b->Next;
	}
	return -1;
}


HangHoa::HangHoa() {
	this->a = 1;
	this->tensp = " ";
	this->soluong = 0;
	this->giaban = 0;
}

HangHoa::HangHoa(string tensp, int soluong, float giaban) {
	this->a = 1;
	this->tensp = tensp;
	this->soluong = soluong;
	this->giaban = giaban;
}

istream& operator >> (istream& in, HangHoa& a) {
	cout << "nhap ten sp: ";
	getline(in, a.tensp);
	cout << "nhap so luong: ";
	in >> a.soluong;
	cout << "nhap gia ban: ";
	in >> a.giaban;
	cin.ignore();
	return in;
}

void HangHoa::show() {
	cout << ++a << ": " << setw(15) << tensp << right << setw(15) << soluong << right << setw(15) << giaban << endl;
}
void HangHoa::ghiFile(List<HangHoa> l)
{
	ofstream output("Khohang.txt");
	Node<HangHoa>* a = NULL;
	a = l.GetHead();
	while (a != NULL)
	{
		output << a->getData().tensp << " / " << a->getData().soluong << " / " << a->getData().giaban << " ///" << endl;
		a = a->Next;
	}
	output.close();
}
void HangHoa::docFile(List<HangHoa>& l)
{
	string str[200];
	ifstream input("Khohang.txt");
	string s;
	int n = 0;
	int count = 0;
	while (input >> s)
	{
		if (count != 3) {

			++count;
		}
		else {

			count = 0;
		}
		str[n] = s;
		n++;
	}
	input.close();
	int temp = 0;
	string stt, ten;
	int sl;
	float gia;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == "/" && temp != 2)
		{
			temp++;
		}
		else if (temp == 2)
		{
			gia = stof(str[i]);
			i++;
			temp = 0;
			HangHoa hangHoa(ten, sl, gia);
			l.InsertLast(hangHoa);
			if (str[i] == "///")
			{
				ten = "";
				sl = 0;
				gia = 0;
			}
			continue;
		}
		else if (str[i] != "/" && temp == 0)
		{
			while (str[i] != "/")
			{
				ten = ten + str[i] + " ";
				i++;
			}
			ten.pop_back();
			i--;
		}

		else if (str[i] != "/" && temp == 1)
		{
			sl = stoi(str[i]);
		}
	}
}*/
#include "Hanghoa.h"
/*
void HangHoa::Input(List<HangHoa>& a,List<HangHoa> &b) {
	cin.ignore();
	cout << "nhap id khach hang: ";
	cin >> this->id;
	int e = 1;
	while (e == 1) {
		cout << "nhap ten san pham muon mua: ";
		getline(cin, this->tensp);
		if (LinearSearch(a, tensp) != 1) {
			cout << "nhap so luong: ";
			cin >> this->soluong;
			ChangeSoluong(a, this->tensp, this->soluong);
			this->giaban = this->soluong * Getgiaban(a, tensp);
			HangHoa temp(this->tensp, this->soluong, this->giaban);
			b.InsertLast(temp);
		}
	}
}
*/

int HangHoa::a = 1;
void HangHoa::reset() {
	a = 1;
}

void HangHoa::Setsoluong(int k) {
	this->soluong = k;
}

int HangHoa::Getsoluong() {
	return this->soluong;
}

long HangHoa::Getgiaban() {
	return this->giaban;
}

void HangHoa::Setgiaban(long k) {
	this->giaban = k;
}

long HangHoa::Getgianhap()
{
	return gianhap;
}

void HangHoa::Setgianhap(long k)
{
	this->gianhap = k;
}

string HangHoa::Gettensp() {
	return this->tensp;
}

int LinearSearch(List<HangHoa> a, string tensp) {
	int temp = 0;
	Node<HangHoa>* b = a.GetHead();
	while (b != NULL) {
		if (b->data.tensp == tensp) {
			return temp;
		}
		++temp;
		b = b->Next;
	}
	return -1;
}

void ChangeSoluong(List<HangHoa>& a, string tensp, int i)
{
	Node <HangHoa>* b = a.GetHead();
	while (b != NULL) {
		if (b->data.tensp == tensp) {
			if (b->data.soluong >= i) {
				b->data.soluong -= i;
				break;
			}
			else cout << "so hang ko du!";
		}
		b = b->Next;
	}
}

bool checksoluong(List<HangHoa> a, string tensp, int i) {
	Node <HangHoa>* b = a.GetHead();
	while (b != NULL) {
		if (b->data.tensp == tensp) {
			if (b->data.soluong < i) {
				return 0;
			}
		}
		b = b->Next;
	}
	return 1;
}

long Getgiaban1(List<HangHoa> a, string tensp) {
	Node <HangHoa>* b = a.GetHead();
	while (b != NULL) {
		if (b->data.tensp == tensp) {
			return b->data.giaban;
		}
		b = b->Next;
	}
	return -1;
}


HangHoa::HangHoa() {
	this->tensp = " ";
	this->soluong = 0;
	this->gianhap = 0;
	this->giaban = 0;
}

HangHoa::HangHoa(string tensp, int soluong, long gianhap, long giaban)
{
	this->tensp = tensp;
	this->soluong = soluong;
	this->gianhap = gianhap;
	this->giaban = giaban;
}

HangHoa::HangHoa(string tensp, int soluong, long giaban)
{
	this->tensp = tensp;
	this->soluong = soluong;
	this->giaban = giaban;
}

istream& operator >> (istream& in, HangHoa& a) {
	cout << "nhap ten sp: ";
	getline(in, a.tensp);
	cout << "nhap so luong: ";
	in >> a.soluong;
	cout << "nhap gia nhap hang: ";
	in >> a.gianhap;
	cout << "nhap gia ban: ";
	in >> a.giaban;
	cin.ignore();
	return in;
}

void HangHoa::show()
{
	cout << "\t\t\t\t\t\t\t|  " << setw(5) << a++ << "    |" << setw(20) << tensp << right << setw(3) << "|" << setw(15) << soluong << right << setw(7) << "|" << setw(15) << gianhap << setw(10) << "  |" << setw(15) << giaban << setw(10) << "  |" << endl;
	cout << setw(10) << "\t\t\t\t\t\t\t____________________________________________________________________________________________________________" << endl;
}

void HangHoa::show_ungianhap() {
	cout << "\t\t\t\t\t\t\t|  " << setw(5) << a++ << "    |" << setw(20) << tensp << right << setw(3) << "|" << setw(15) << soluong << right << setw(7) << "|" << setw(15) << giaban << setw(10) << "  |" << endl;
	cout << setw(10) << "\t\t\t\t\t\t\t___________________________________________________________________________________" << endl;
}
long Getgianhap1(List<HangHoa> a, string tensp) {
	Node <HangHoa>* b = a.GetHead();
	while (b != NULL) {
		if (b->data.tensp == tensp) {
			return b->data.gianhap;
		}
		b = b->Next;
	}
	return -1;
}



bool HangHoa::checkFile(string name)
{
	ifstream isf(name);
	return isf.good();
}

void HangHoa::ghiFile(List<HangHoa> l, string filename)
{

	ofstream output(filename, ios::out | ios::trunc);
	Node<HangHoa>* a = NULL;
	a = l.GetHead();
	while (a != NULL)
	{
		output << a->data.tensp << " / " << a->data.soluong << " / " << a->data.gianhap << " / " << a->data.giaban << " ///" << endl;
		a = a->Next;
	}
	output.close();
}

bool is_empty(ifstream& pFile)
{
	return pFile.peek() == ifstream::traits_type::eof();
}

void HangHoa::docFile(List<HangHoa>& l, string filename)
{
	string str[500];
	ifstream input(filename);
//	if (input.peek() == ifstream::traits_type::eof()) cout << "FILE RONG!" << endl;
		string s;
		int n = 0;
		int count = 0;
		while (input >> s)
		{
			if (count != 4) {

				++count;
			}
			else {

				count = 0;
			}
			str[n] = s;
			n++;
		}
		input.close();
		int temp = 0;
		string stt, ten;
		int sl;
		long gian, giab;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == "/" && temp != 3)
			{
				temp++;
			}
			else if (temp == 3)
			{
				giab = stol(str[i]);
				i++;
				temp = 0;
				HangHoa hangHoa(ten, sl, gian, giab);
				l.InsertLast(hangHoa);
				if (str[i] == "///")
				{
					ten = "";
					sl = 0;
					gian = 0;
					giab = 0;
				}
				continue;
			}
			else if (str[i] != "/" && temp == 0)
			{
				while (str[i] != "/")
				{
					ten = ten + str[i] + " ";
					i++;
				}
				ten.pop_back();
				i--;
			}

			else if (str[i] != "/" && temp == 1)
			{
				sl = stoi(str[i]);
			}
			else if (str[i] != "/" && temp == 2)
			{
				gian = stol(str[i]);
			}
		}
}
