#include "Hanghoa.h"


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
