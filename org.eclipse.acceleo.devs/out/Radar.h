#pragma once
#ifndef RADAR_H
#define RADAR_H
#include "ExchangeData.h"
#include "Vector.h"
#include <iostream>
using namespace std;
using namespace adevs;
class Radar : public adevs::Atomic<IO_Type> {
public:
	static int inTarget;
	static int outRadar;
	static int inStartRadar;	
	static Integer m_id;
	Integer m_tarId;
	CVector m_radarPos;
	double m_radius;
	double m_angle;
	bool m_isInView[5];
	List<TarInfo> m_targets;
	double m_curTime;	
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
	const char* getClassName() { return "RADAR"; };
	State getState() {return m_state;}
	void setStateToEnd() {m_state = ENDED;}
	void scanning(TarInfo target); 
	Radar(int id, CVector pos, int type); 
	startRadar(); 
	scanTarget();
	~Radar();
};
#endif
