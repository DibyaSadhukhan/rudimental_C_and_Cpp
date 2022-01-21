#include <iostream>
using namespace std;
class person{
    protected:
        char name[100];
        int code;
    public:
        person(char* n, int cd){
            name=n;
            code=cd;
        }
        void display(){
            cout<<"Name: "<< name;
            cout<<"code: "<< code;
        }
};
int main(){
    person a("gg",3);
    a.display();
    return 0;
}
