#include "pulse.h"
#include "pulse.cpp"

int safeArr[2];

// int heartRate()
// {
//   int rate=0;
//   int chance=rand()%16;
//   if(chance==0)
//     rate=30;
//   if((chance==1)||(chance==2))
//     rate=45;
//   if((chance==3)||(chance==4))
//     rate=50;
//   if(chance==5)
//     rate=55;
//   if((chance==6)||(chance==7))
//     rate=65;
//   if((chance==8)||(chance==9))
//     rate=70;
//   if((chance==10)||(chance==11)||(chance==12))
//     rate=75;
//   if((chance==13)||(chance==14)||(chance==15))
//     rate=80;
//
//   return rate;
// }

int heartRate()
{
  int rate=0;
  int chance=rand()%16;
  if(chance==0)
    rate=rand()%(39-25+1)+25;
  if((chance>0)&&(chance<6))
    rate=rand()%(59-31+1)+31;
  if((chance>=6)&&(chance<16))
    rate=rand()%(80-60+1)+60;

  return rate;
}

void addBpmTest()
{
  pulse p(80);

  p.addBpm(2);
  p.addBpm(4);
  p.addBpm(6);
  p.addBpm(8);

  cout<<p.bpmArr[0]<<" "<<p.bpmArr[1]<<" "<<p.bpmArr[2]<<" "<<p.bpmArr[3]<<"\n";
  p.addBpm(10);
  cout<<p.bpmArr[0]<<" "<<p.bpmArr[1]<<" "<<p.bpmArr[2]<<" "<<p.bpmArr[3]<<"\n";
  p.addBpm(7);
  cout<<p.bpmArr[0]<<" "<<p.bpmArr[1]<<" "<<p.bpmArr[2]<<" "<<p.bpmArr[3]<<"\n";
  p.addBpm(11);
  p.addBpm(13);
  p.addBpm(17);
  cout<<p.bpmArr[0]<<" "<<p.bpmArr[1]<<"\n";
}

int checks(pulse p,int x)
{
  if((x==0)||(x==3))
    cout<<"\n";
  if(x==1)
    cout<<"persistent low pulse detected\n\n";
  if(x==2)
  {
    cout<<"Severe low pulse detected. Contacting dispatch center & ICE contaccts\n\n";
    // Sleep(1000);
    x=0;
    p.bpmArr[0]=80;
    p.bpmArr[1]=80;
  }

  return 0;
}

int main()
{
  ofstream file;
  file.open("moyo.txt");

  srand(time(0));

  pulse p(80);

  bool a=1;
  int i=0;

  while(a)
  {
    int r=heartRate();
    cout<<"\t-~-"<<r<<"-~-"<<endl;
    file.open("moyo.txt",ios::app);
    if(file)
      file<<"\t-~-"<<r<<"-~-\n";
    p.addBpm(r);

    int y=p.bpmArr[0];
    int z=p.bpmArr[1];
    int x=p.pulseSafe(y,z);

    file.close();
    // cout<<"bpmArr[0]: "<<p.bpmArr[0]<<endl;
    // cout<<"bpmArr[1]: "<<p.bpmArr[1]<<endl;

    // int b=p.calcSafe(p.bpmArr[0]);
    // cout<<"y safe: "<<b<<endl;
    // int c=p.calcSafe(p.bpmArr[1]);
    // cout<<"z safe: "<<c<<endl;

    // cout<<"final check: "<<x<<endl;
    // if((x==0)||(x==3)) //safe
    //   cout<<"safe\n";
    // if(x==1) //dangerous
    //   cout<<"danger\n";
    // if(x==2) //deadly
    //   cout<<"lethal\n";

    int v=checks(p,x);

    Sleep(2500);
  }


  // int y=p.bpmArr[0];
  // int z=p.bpmArr[1];
  // // cout<<p.bpmArr[0]<<endl;
  // // cout<<p.bpmArr[1]<<endl;
  // cout<<"y: "<<y<<"\tz: "<<z<<"\n\n";
  //
  // int b=p.calcSafe(y);
  // cout<<"calcSafe y: "<<b<<endl;
  // int c=p.calcSafe(z);
  // cout<<"calcSafe z: "<<c<<endl;
  //
  // int x=p.pulseSafe(b,c);
  // // if((x==0)||(x==3)) //safe
  // //   /*code*/
  // // if(x==1) //dangerous
  // //   /*code*/
  // // if(x==2) //deadly
  // //   /*code*/
  //
  // cout<<"x: "<<x<<endl;

  // file.close();
  return 0;
}
