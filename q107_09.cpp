#include <iostream>
using namespace std;
class person{
    protected:
        char name[100];
        char code;

};
class account : virtual public person
{
    protected:
        float pay;
};
class admin : virtual public person
{
    protected:
        int experience;
};
class master : public account, public admin
{
    public:
        void create (char* n, char cd,float p,int exp){
            int i;
            for(i=0; n[i]!='\0';i++){
                name[i]=n[i];
            }
            name[i]='\0';
            code=cd;
            pay=p;
            experience=exp;
        }
        void update (char* newn, char newcd,float newp,int newexp){
            int i;
            for(i=0; newn[i]!='\0';i++){
                name[i]=newn[i];
            }
            name[i]='\0';
            code=newcd;
            pay=newp;
            experience=newexp;
        }
        void display(){
            cout<<"Name: "<< name;
            cout<<"\ncode: "<< code;
            cout<<"\nexperience: "<<experience;
            cout<<"\npay: "<< pay;
        }
};
int main(){
    char n[100];
    float p;
    char cd;
    int exp;
    master a;
    cout<<"enter Name: ";
	cin.getline(n,100);
    cout<<"enter Code: ";
	cin>>cd;
    cout<<"enter Pay: ";
	cin>>p;
	cout<<"enter Experience: ";
	cin>>exp;
    a.create(n,cd,p,exp);
    a.display();
    cout<<"\nDo you want to update ";
    cin>>cd;
    if (cd == 'Y' or cd =='y'){
        cin.ignore();
        cout<<"enter Name: ";
        cin.getline(n,100);
        cout<<"enter Code: ";
        cin>>cd;
        cout<<"enter Pay: ";
        cin>>p;
        cout<<"enter Experience: ";
        cin>>exp;
        a.update(n,cd,p,exp);
    }
    a.display();
    return 0;
}
