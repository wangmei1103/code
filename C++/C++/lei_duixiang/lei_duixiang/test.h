/*
#pragma once
//友元关系是单向的
#include"time.h"
class Date
{
	friend class Time;
public:
	Date(int year = 1900, int month = 1, int day = 1); 
	void SetTimeOfDate(int hour, int minute, int second);
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};*/
