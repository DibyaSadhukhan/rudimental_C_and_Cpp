#include <iostream>
using namespace std;

class opoverload{
    private:
        int  num;
        string str;
	public:
		opoverload(int n, string s){
			num = n;
			str = s;
		}

		opoverload operator += (opoverload obj){
			str+=obj.str;
			num+=obj.num;
			opoverload newObj(num,str);
			return newObj;
		}

		void display(){
			cout<< "\nNumber : "<< num;
			cout<< "\nString : "<< str;
		}
};

int main(){
    int i;
    string s;
    cout<<"enter integer: ";
	cin>>i;
	cout<<"enter string : ";
	cin>>s;
	opoverload s1(i,s);
	cout<<"enter integer : ";
	cin>>i;
	cout<<"enter string : ";
	cin>>s;
	opoverload s2(i,s);
	//s1.display();
	//s2.display();
	s1+=s2;
	s1.display();
    cout<<"\nenter integer : ";
	cin>>i;
	cout<<"enter string : ";
	cin>>s;
    opoverload s3(i,s);
    s3+=(s1+=s2);
    s3.display();
    return 0;
}
