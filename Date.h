/*#ifndef Date_h
#define Date_h
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Date {
protected:
	string date;
	string time;
public:
	virtual void Output_Date();
};
#endif // !Date_h*/
#ifndef Date_H
#define Date_H
#include "MyLib.h"
class Date {
protected:
	int ngay;
	int thang;
	int nam;
	int gio;
	int phut;
	int giay;
public:
	Date()
	{
		this->ngay = this->thang = this->nam = this->gio = this->phut = this->giay = 0;
	}
	~Date()
	{

	}
};
#endif // !Date_H

