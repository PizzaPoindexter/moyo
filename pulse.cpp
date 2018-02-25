#include "pulse.h"

pulse::pulse(int a)
{
  avgRate=a;
  bpmIndex=0;
  bpmArr[1]=80;
}

pulse::~pulse()
{

}

void pulse::awakeRate(int inaRate)
{
  aRate=inaRate;
}

int pulse::get_aRate()
{
  return aRate;
}

void pulse::sleepRate(int insRate)
{

}

int pulse::get_sRate()
{
  return sRate;
}

//called every interval of time (15 seconds optimal)
void pulse::addBpm(int bpm)
{
  bpmArr[bpmIndex]=bpm;
  bpmIndex++;
  if (bpmIndex==2)
  {
    bpmIndex=0;
  }
}

int pulse::calcSafe(int sr)
{
  if((sr>=60)&&(sr<=80))
  {
    return 0; //safe
  }
  else if((sr>=40)&&(sr<=59))
  {
    return 1; //danger
  }
  else
  {
    return 2; //deadly
  }
}

int pulse::pulseSafe(int y, int z)
{
  int a=calcSafe(y);
  int b=calcSafe(z);

  if((a==0)&&(b==0))
    return 0; //safe
  if((a==1)&&(b==1))
    return 1; //dangerous
  if((a==2)||(b==2))
    return 2; //deadly
  else
    return 3; //mismatch, safe
}

//checks if current avg is in normal, danger, or deadly range
void pulse::calcRange(int ar)
{
  ar=80;
  for(int i=0;i<21;i++)
  {
    noRange[i]=ar-i; //80-0 -> 80-20 = 80->60
  }
  for(int j=21;j<41;j++)
  {
    daRange[j]=ar-j; //80-21 -> 80-40 = 59->40
  }
}
