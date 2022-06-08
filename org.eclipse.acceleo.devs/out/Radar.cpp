#include "Radar.h"
int Radar::inTarget=1;
int Radar::outRadar=2;
int Radar::inStartRadar=3;
Radar::Radar(int id, CVector pos, int type){
	
}
void Radar::output_func(Bag<IO_Type>& yb){
	while (!outEvents.empty()) {
		ExchangeData data = outEvents.front();
		ExchangeData *t = new ExchangeData();
		t->e_req = data.e_req;
		t->e_target = data.e_target;
		t->e_src = data.e_src;
		IO_Type y;
		y.port = data.e_port;
		y.value = t;
		yb.insert(y);
		outEvents.pop_front();
	}
}
void Radar::delta_ext(double e, const Bag<IO_Type>& xb){	
	Bag<IO_Type>::const_iterator i = xb.begin();
	for (; i != xb.end(); i++){
		ModelType tar = (*i).value->e_target;
		ModelType src = (*i).value->e_src;
	}
void Radar::delta_int(){
}
void Radar::delta_conf(const Bag<IO_Type>& xb){
	delta_int();
	delta_ext(0.0, xb);
}
double Radar::ta(){
	m_curTime = START_TIME + elapse;
	return TIME_STEP;
}
double Radar::gc_output(Bag<IO_Type>& g){
	Bag<IO_Type>::iterator i;
	for (i = g.begin(); i != g.end(); i++)
	{
		delete (*i).value;
	}
}
