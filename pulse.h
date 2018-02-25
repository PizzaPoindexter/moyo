#ifndef PULSE_H
#define PULSE_H

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <windows.h>
#include <fstream>
using namespace std;

class pulse
{
public:
  pulse();
  pulse(int);
  ~pulse();

  void awakeRate(int);
  int get_aRate();
  void sleepRate(int);
  int get_sRate();

  int calcSafe(int);
  int pulseSafe(int,int);
  void calcRange(int);
  void addBpm(int);

  //int *deRange; //deadly

  int bpmArr[2];
  // int bpmIndex;

  int avgRate;

private:
  int noRange[21]; //normal heartrate range (includes 80 and 60)
  int daRange[40]; //dangerous

  int bpmIndex;
  int aRate; //hertrate while awake
  int sRate; //heartrate while asleep

  bool isDanger; //below 40
  //over 180
  bool isDeadly;
  //+-20 safe
  //+-30 for atheletes
};

#endif
