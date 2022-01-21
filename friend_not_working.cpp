#include <iostream>
using namespace std;
class DB;

class DM {
    private:
        float meter,centimeter;
    public:
        DM(){
            meter=0.0;
            centimeter=0.0;
        }
        void getdata(){
            cout<<"enter distance in meter\n";
            cin>>meter;
            cout<<"enter distance in centimeter\n";
            cin>>centimeter;
        }
        void displayData(){
            cout<<"The Distance is :"<<meter<<"m and "<<centimeter<<"cm\n";
        }
        friend void Add(DM,DB,int flag);
};

class DB {
    private:
        float feet,inches;
    public:
        DB(){
            feet=0.0;
            inches=0.0;
        }
        void getdata(){
            cout<<"enter distance in foot\n";
            cin>>feet;
            cout<<"enter distance in inches\n";
            cin>>inches;
        }
        void displayData(){
            cout<<"The Distance is :"<<feet<<"feet and "<<inches<<"inches\n";
        }

        friend void Add(DM,DB,int flag); // Friend function
};
//no need flag
void Add(DM x,DB y,int flag){
    if (flag==0){
        cout << "sum = " << (3.28084*x.meter)+y.feet<<"foot and "<<(0.3937008*x.centimeter)+y.inches<<"inches\n";
    }
    else{
        cout << "sum = " << x.meter+(y.feet/3.28084)<<"m and "<<x.centimeter+(y.inches/0.3937008)<<"cm\n";
    }
}

int main()
{
    DM x;
    DB y;
    x.getdata();
    x.displayData();
    y.getdata();
    y.displayData();
    int flag=0;
    cout<<"press 0 to add in inches or 1 to add in meter\n";
    cin>>flag;
    Add(x,y,flag);
    return 0;
}
