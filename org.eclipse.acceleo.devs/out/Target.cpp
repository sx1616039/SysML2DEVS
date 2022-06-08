#include "Target.h"
int Target::outTarget=1;
int Target::inDestroy=2;
Target::Target(int id, double lnchTime, double totalFlyTime, CVector tarLnchPos, CVector tarfallSite){
	
}
void Target::output_func(Bag<IO_Type>& yb){
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
void Target::delta_ext(double e, const Bag<IO_Type>& xb){	
	Bag<IO_Type>::const_iterator i = xb.begin();
	for (; i != xb.end(); i++){
		ModelType tar = (*i).value->e_target;
		ModelType src = (*i).value->e_src;
	}
void Target::delta_int(){
}
void Target::delta_conf(const Bag<IO_Type>& xb){
	delta_int();
	delta_ext(0.0, xb);
}
double Target::ta(){
	m_curTime = START_TIME + elapse;
	return TIME_STEP;
}
double Target::gc_output(Bag<IO_Type>& g){
	Bag<IO_Type>::iterator i;
	for (i = g.begin(); i != g.end(); i++)
	{
		delete (*i).value;
	}
}
