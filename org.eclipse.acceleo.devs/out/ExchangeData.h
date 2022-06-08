#pragma once
#ifndef EXCHANGEDATA_H
#define EXCHANGEDATA_H
#include "adevs\include\adevs.h"
#include "Vector.h"
typedef struct StartRadarInfo{
	bool isStart;
}StartRadarInfo;
typedef struct LnchInfo{
	double l_InchTime;
	int l_misId;
	int l_tarId;
	CVector l_lnchPos;
	CVector l_lnchVel;
	CVector l_tarPos;
	CVector l_tarVel;
	double l_curTime;
}LnchInfo;
typedef struct TarInfo{
	int t_id;
	double t_InchTime;
	CVector t_Pos;
	double t_totalTime;
	CVector t_Vel;
	CVector t_InchVel;
	CVector t_InchPos;
	CVector t_fallPos;
}TarInfo;
typedef struct DestroyInfo{
	int d_tarId;
	int d_misId;
	double d_destroyTime;
}DestroyInfo;
typedef struct RadarInfo{
	int r_id;
	List<TarInfo> r_targets;
}RadarInfo;
enum ModelType{
 AGENT, MISSILE, RADAR, CONTROLLER};
enum State{
,,,WAITING,PROCESSING,HITTED};
