#pragma once
#ifndef TARGET_H
#define TARGET_H
#include "ExchangeData.h"
#include "Vector.h"
#include <iostream>
using namespace std;
using namespace adevs;
class Target : public adevs::Atomic<IO_Type> {
public:
	static int outTarget;
	static int inDestroy;	
	int m_id;
	char array[4];	
	private:
	State              m_state;
	list<ExchangeData> outEvents;
public:
	void delta_int();
	void delta_ext(double e, const adevs::Bag<IO_Type>& xb);
	void delta_conf(const adevs::Bag<IO_Type>& xb);
	void output_func(adevs::Bag<IO_Type>& yb);
	double ta();
	void gc_output(adevs::Bag<IO_Type>& g);
	const char* getClassName() { return "TARGET"; };
	State getState() {return m_state;}
	void setStateToEnd() {m_state = ENDED;}
	Target(int id, double lnchTime, double totalFlyTime, CVector tarLnchPos, CVector tarfallSite); 
	ended(); 
	CVector Gauss(CVector launchPos, CVector fallSite, double totalFlyTime);
	~Target();
};
#endif
