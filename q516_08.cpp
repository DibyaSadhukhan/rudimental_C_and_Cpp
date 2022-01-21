#include<iostream>
using namespace std;

class Time{
	private:
		int hours;
		int minutes;
		int seconds;
	public:
		Time(){
			hours=0;
			minutes=0;
			seconds=0;
        }
        Time(int hr,int mn,int sec){
                hours=hr;
                minutes=mn;
                seconds=sec;
        }
        void display(){
            cout<<hours<<":"<<minutes<<":"<<seconds;
        }
        void addTime(Time &T1, Time &T2){
            int temp=0;
            seconds=T1.seconds + T2.seconds;
            if(seconds>59){
                seconds=seconds - 60;
                temp++;
            }
            minutes=T1.minutes + T2.minutes+temp;
            temp=0;
            if(minutes>59){
                minutes=minutes - 60;
                temp++;
            }
            hours=T1.hours + T2.hours+temp;
        }
};

int main(){
    int hr,mn,sec;
    cout<<"enter hours";
    cin>>hr;
	cout<<"enter minutes";
    cin>>mn;
	cout<<"enter seconds";
    cin>>sec;
	Time t1(hr,mn,sec);
	cout<<"enter hours";
    cin>>hr;
	cout<<"enter minutes";
    cin>>mn;
	cout<<"enter seconds";
    cin>>sec;
	Time t2(hr,mn,sec);

	cout<<"\nFirst Time is: ";
	t1.display();
	cout<<"Second Time is: ";
	t2.display();
	Time t3;
	cout<<"\nAfter adding, Final Time is: ";
	t3.addTime(t1, t2);
	t3.display();

	return 0;
}
