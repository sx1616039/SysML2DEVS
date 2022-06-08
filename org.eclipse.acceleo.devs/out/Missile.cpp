#include "Missile.h"
int Missile::inTarget=1;
int Missile::inLnchlnfo=2;
int Missile::outDestroy=3;
Missile::Missile(int id, int type):ode_system<IOType>(9,0){
	
}
double Missile::init(double* q){
	for (int i = 0; i < 9; i++) {
		q[i] = 0;
	}
	q[9] = m_curTime;
}
double Missile::der_func(const double* q, double* dq){
	CVector der_m_curPos;
	m_curPos.x = q[0];
	m_curPos.y = q[1];
	m_curPos.z = q[2];
	CVector der_m_curVel;
	m_curVel.x = q[3];
	m_curVel.y = q[4];
	m_curVel.z = q[5];
	CVector der_m_acc;
	m_acc.x = q[6];
	m_acc.y = q[7];
	m_acc.z = q[8];
	der(m_curVel)=m_acc;der(m_curPos)=attt;
	dq[0] = der_m_curPos.x;
	dq[1] = der_m_curPos.y;
	dq[2] = der_m_curPos.z;
	dq[3] = der_m_curVel.x;
	dq[4] = der_m_curVel.y;
	dq[5] = der_m_curVel.z;
	dq[6] = der_m_acc.x;
	dq[7] = der_m_acc.y;
	dq[8] = der_m_acc.z;
}
void Missile::output_func(const double *q, const bool* state_event, Bag<IO_Type>& yb){
	while (!outEvents.empty()) {
		ExchangeData data = outEvents.front();
		ExchangeData *t = new ExchangeData();
		t->e_req = data.e_req;
		t->e_target = data.e_target;
		t->e_src = data.e_src;
		t->e_destroyInfo = data.e_destroyInfo;
		IO_Type y;
		y.port = data.e_port;
		y.value = t;
		yb.insert(y);
		outEvents.pop_front();
	}
}
void Missile::time_event_func(const double* q){
m_curTime=START_TIME + elapse;
	return DBL_MAX;
}
void Missile::external_event(double* q, double e, const Bag<IO_Type>& xb){	
	Bag<IO_Type>::const_iterator i = xb.begin();
	for (; i != xb.end(); i++){
		ModelType tar = (*i).value->e_target;
		ModelType src = (*i).value->e_src;
	}
}
void Missile::internal_event(double* q, const bool* state_event){
}
void Missile::confluent_event(double* q, const bool* state_event,const Bag<IO_Type>& xb){
	internal_event(q, state_event);
	external_event(q, 0.0, xb);
}

double Missile::gc_output(Bag<IO_Type>& g){
	Bag<IO_Type>::iterator i;
	for (i = g.begin(); i != g.end(); i++)
	{
		delete (*i).value;
	}
}
