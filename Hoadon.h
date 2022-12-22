#ifndef HoaDon_H
#define HoaDon_H
#include "Khachhang.h"
#include "Hanghoa.h"
using namespace std;

class HoaDon :public KhachHang, public HangHoa {
protected:
	string ID_hd;
	long tongtien;
	long chiphi1;
	List <HangHoa> HD;
	bool check;
public:
	HoaDon();
	friend void SearchMKH(List<HoaDon>);
	void Input(List<HangHoa>&);
	void show_HD();
	void show();
	void ghiFile_LSBH();
	long getTongTien();
	friend void show_gianhap(List <HoaDon>&, long long);
	friend void show_loinhuan(List <HoaDon>&);
	friend void SearchMHD(List<HoaDon>);
	int getNgay();
	int getThang();
	int getNam();
	int getGio();
	int getPhut();
	int getGiay();
};


#endif // !HoaDon_H
