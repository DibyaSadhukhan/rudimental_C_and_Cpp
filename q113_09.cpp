#include <iostream>
using namespace std;
class shape{
    protected:
        double a;
        double b;

    public:
        void get_data(double ina,double inb){
            a=ina;
            b=inb;
        }
        void virtual display_area(){
            cout<<"The area is";
        }
};
class rectangle: public shape{
    private:
        double area;
    public:
        void calculate_area(){
            area=a*b;

        }
        void display_area(){
            cout<<"The area of the rectangle is "<<area<<"sq units";
        }
};
class triangle: public shape{
    private:
        double area;
    public:
        void calculate_area(){
            area=0.5*a*b;

        }
        void display_area(){
            cout<<"The area of the triangle is "<<area<<" sq units";
        }
};
int main(){
    int flag;
    double a;
    double b;
    cout<<"Press 1 for area of rectangle \npress 2 for area of triangle: \n";
	cin>>flag;
    if (flag==1){
        cout<<"enter length :";
        cin>>a;
        cout<<"enter bredth :";
        cin>>b;
        rectangle rec;
        rec.get_data(a,b);
        rec.calculate_area();
        rec.display_area();
    }
    else{
        cout<<"enter base :";
        cin>>a;
        cout<<"enter height :";
        cin>>b;
        triangle tri;
        tri.get_data(a,b);
        tri.calculate_area();
        tri.display_area();
    }
}
