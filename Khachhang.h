#ifndef KhachHang_H
#define KhachHang_H
#include <string>
#include "Date.h"
using namespace std;
class KhachHang : public Date {
protected:
	string id;
	long tiengui;
public:
	KhachHang();
	~KhachHang()
	{

	}
	friend istream& operator >> (istream&, KhachHang&);
	void show();
};

#endif // !KhachHang_H
