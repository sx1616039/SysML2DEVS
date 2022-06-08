#pragma once
#ifndef AGENT_H
#define AGENT_H
#include "ExchangeData.h"
#include "Vector.h"
#include "Radar.h" 
#include "Missile.h" 
#include "Controller.h" 
#include <iostream>
using namespace std;
using namespace adevs;
class Agent : public adevs::Digraph<ExchangeData*> {
public:
	static int inTarget;
	static int outDestroy;
	Radar *m_radar;
	Missile *m_missile;
	Hybrid<IO_Type> *m_hybrid_missile;
	Controller *m_controller;
public:
	
	~Agent();
};
#endif
