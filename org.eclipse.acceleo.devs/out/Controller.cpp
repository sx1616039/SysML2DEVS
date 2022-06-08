#include "Controller.h"
int Controller::inRadar=1;
int Controller::outStartRadar=2;
int Controller::outLnchlnfo=3;
int Controller::inDestroy=4;
Controller::Controller(int id, CVector pos, int type, double radius){
	
}
void Controller::output_func(Bag<IO_Type>& yb){
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
void Controller::delta_ext(double e, const Bag<IO_Type>& xb){	
	Bag<IO_Type>::const_iterator i = xb.begin();
	for (; i != xb.end(); i++){
		ModelType tar = (*i).value->e_target;
		ModelType src = (*i).value->e_src;
		if ((tar == BROADCAST || tar == CONTROLLER) && src == MISSILE){
			setDestroyBody
		}
	}
void Controller::delta_int(){
	if (m_state == WAITING){
	m_state = WAITING
	time = 0;
time = 1;}
	if (m_state == WAITING && a>c&& aa>b){
	m_state = PROCESSING
	processingBody}
}
void Controller::delta_conf(const Bag<IO_Type>& xb){
	delta_int();
	delta_ext(0.0, xb);
}
double Controller::ta(){
	m_curTime = START_TIME + elapse;
	return TIME_STEP;
}
double Controller::gc_output(Bag<IO_Type>& g){
	Bag<IO_Type>::iterator i;
	for (i = g.begin(); i != g.end(); i++)
	{
		delete (*i).value;
	}
}
