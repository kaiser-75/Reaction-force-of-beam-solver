#include <bits/stdc++.h>
using namespace std;


class beamcalc
{
    public:
        float beamLenght,supportPosition[5],pointLP,pointLV,distriLSP,distriLSPV;
        float distriLEP,distriLEPV,distriLoad,finalDistriPosition;
        string supportT;
        float momentP,momentV,ay,by;
        float ap,av,bp,bv,dp,dv,pp,pv;
        float a[5];
        int sT,n;
        int yesNo=0;
        void beamlength();
        void support();
        void pointload();
        void  distributedLoad();
        void moment();
        int calc();
        void set_value();

};

void beamcalc::beamlength(){
    cout<<"\tEnter beam length :";
    cin>>beamLenght;
    cout<<endl;
}
void beamcalc::support(){
    //sT,n; support type,n=no. of support
    cout<<"\tHow many support you want to add:";
    cin>>n;
    cout<<endl;
    for(int i=0;i<n;i++){
    cout<<"\tEnter support type: "<<endl;
    cout<<"\t1. Pin Support"<<endl;
    cout<<"\t2. Roller Support"<<endl;
    cin>>sT;
    switch(sT){
        case 1: supportT="pin";
                 break;
        case 2: supportT="roller";
                 break;
    }
    cout<<"\tEnter support position:";
    cin>>supportPosition[i];
    cout<<endl;
    }

}
void beamcalc::pointload(){
    cout<<"\tDo you want to add point load:"<<endl;
    cout<<"\t 1.Yes   2. No"<<endl;
    cin>>yesNo;
    if(yesNo==1){
        cout<<"\tIf the point load is upward then use a negative sign"<<endl;
        cout<<"\tEnter the position and value of Point Load :";
        cin>>pointLP>>pointLV;
        cout<<endl;
    }
    else {pointLP=0;
          pointLV=0;}
}
void beamcalc::distributedLoad(){
    cout<<"\tInformation about distributed load"<<endl;
    cout<<"\tIf the distributed load is upward then use a negtaive sign"<<endl;
    cout<<"\tEnter the starting position and it's value :";
    cin>>distriLSP>>distriLSPV;
    cout<<endl;
    cout<<"\tEnter the ending position and it's value :";
    cin>>distriLEP>>distriLEPV;
    cout<<endl;
    if(distriLSPV==distriLEPV){
            distriLoad=distriLSPV*(distriLEP-distriLSP);
            finalDistriPosition=distriLSP+(distriLEP-distriLSP)*0.5;
            }
    if(distriLSPV<distriLEPV){
        distriLoad=0.5*(distriLEP-distriLSP)*distriLEPV;
        finalDistriPosition=distriLEP-(distriLEP-distriLSP)*0.3333;
    }
    if(distriLSPV>distriLEPV){
        distriLoad=0.5*(distriLEP-distriLSP)*distriLSPV;
        finalDistriPosition=distriLSP+(distriLEP-distriLSP)*0.3333;
    }


}
void beamcalc::moment(){

    cout<<"\tIs there any moment :"<<endl;
    cout<<"\t1.Yes 2.No"<<endl;
    cin>>yesNo;
    if(yesNo==1){
        cout<<"\tTake anti-clock wise moment as positive"<<endl;
        cout<<"\tEnter moment position and value: ";
        cin>>momentP>>momentV;
        cout<<endl;
    }
    else {momentP=0; momentV=0;}
}
int  beamcalc::calc(){
      //Moment at first support A
     float supportDistance,temp,a,b;
     supportDistance=supportPosition[1]-supportPosition[0];
      a=(distriLoad*(finalDistriPosition-supportPosition[0]));
      b=pointLV*(pointLP-supportPosition[0]);
     //temp=(distriLoad*(finalDistriPosition-supportPosition[0]))+(pointLP*pointLV)-momentV;
     temp=round(a)+b-momentV;
     by=temp/supportDistance;
     //summation of f_y
     ay=pointLV+distriLoad-by;



     cout<<"\tReaction at A :"<<ay<<endl;
     cout<<"\tReaction at B :"<<by<<endl;
}

void beamcalc:: set_value(){
    ap=supportPosition[0];
    av=ay;
    bp=supportPosition[1];
    bv=by;
    dp=finalDistriPosition;
    dv=-distriLoad;
    pp=pointLP;
    pv=-pointLP;
}

class point:public beamcalc{
	double x;
	double y;
	public:
		point (double xx, double yy)
		{
			x = xx;
			y = yy;
		}


        double get_x ()
        {
            return x;
        }

        double get_y ()
        {
            return y;
        }

};







int main()
{
    beamcalc beam;
    //accessing all the information about beam
    beam.beamlength();
    beam.support();
    beam.pointload();
    beam.distributedLoad();
    beam.moment();
     //calculation
    beam.calc();

}
