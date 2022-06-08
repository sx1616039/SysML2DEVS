#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "ExchangeData.h"
#include "Vector.h"
#include <iostream>
using namespace std;
using namespace adevs;
class Controller : public adevs::Atomic<IO_Type> {
public:
	static int inRadar;
	static int outStartRadar;
	static int outLnchlnfo;
	static int inDestroy;	
	double m_threatIndex[35];
	bool m_lockedTarget[35];
	int m_id;
	CVector m_pos;
	CVector m_centerPos;
	double m_curTime;
	double m_radius;
	int m_type;
	TarInfo m_tars[5];
	double m_misAvrgVel;	
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
	const char* getClassName() { return "CONTROLLER"; };
	State getState() {return m_state;}
	void setStateToEnd() {m_state = ENDED;}
	void Kepler2(CVector *curPos, CVector *curVel, CVector launchPos, CVector launchVel, double flyTime); 
	double threatEvaluate(double v, double leftTime, CVector fallSite); 
	double findMaxThreat(int *id, int *tarId); 
	interceptPlanning(CVector tarLnchPos, CVector tarLnchVel, double lnchTime, double totalTime, double); 
	void assignTarget(); 
	Controller(int id, CVector pos, int type, double radius); 
	processing(); 
	setDestroy();
	~Controller();
};
#endif
