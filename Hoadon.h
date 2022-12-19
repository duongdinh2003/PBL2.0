#ifndef HoaDon_H
#define HoaDon_H
#include "Khachhang.h"
#include "Hanghoa.h"
using namespace std;

class HoaDon :public KhachHang, public HangHoa {
protected:
	static int count;
	long tongtien;
public:
	HoaDon();
	~HoaDon()
	{

	}
	void Input(List<HangHoa>&, List<HangHoa>&);
	void show(List <HangHoa>);
	void ghiFile_LSBH(List<HangHoa>);
	long getTongTien();
};


#endif // !HoaDon_H
