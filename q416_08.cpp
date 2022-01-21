#include <iostream>
#include <cstdlib>
using namespace std;
class FunctionOverload{
    public:
        int Stringop(char *s){
            int len=0;
            while (s[len] != '\0') {
                len++;
            }
        return len;
        }
        void Stringop(char *s1,char *s2){
            int l1=Stringop(s1);
            int l2=Stringop(s2);
            char* s3 = (char*) malloc((l1+l2)*sizeof(char));
            //while(*s1++=*s2++);
            int i=0;
            int j=0;
            while (i<l1){
                s3[j]=s1[i];
                i++;
                j++;
            }
            i=0;
            while (i<l2){
                s3[j]=s2[i];
                i++;
                j++;
            }
            cout<<"concatenating "<<s1<<" and "<<s2<<" : "<<s3;
        }
        bool Stringop(char *s1,char *s2,int flag)
        {
            int l1=Stringop(s1);
            int l2=Stringop(s2);
            if (l1==l2){
                while ((l1-1)>=0){
                    if (s1[l1-1]!=s2[l1-1]){
                        return false;
                    }
                    l1--;

                }
                return true;
            }
            return false;
        }
        void Stringop(char* s,int m,int n){
            int l1=Stringop(s);
            if (m<l1 && n<=l1){
                char* s1 = (char*) malloc((n-m)*sizeof(char));
                int i=0;
                while(m<=n){
                    s1[i]=s[m];
                    m++;
                    i++;
                }
                cout<<s1;
            }
            else{
                cout<<-1;
            }
        }
        void Stringop(char* str,int flag)
        {
            for(int i =Stringop(str) - 1; i >= 0; i--){
                cout<<str[i];
            }
        }
        void Stringop(char* s,bool flag){
            int i=0;
                if (flag ==0){
                    while(s[i]!='\0'){
                        if(s[i]>='A' && s[i]<='Z'){
                            s[i]=s[i]+32;
                        }
                        ++i;
                    }
                }
                else{
                    while(s[i]!='\0'){
                        if(s[i]>='a' && s[i]<='z'){
                            s[i]=s[i]-32;
                        }
                        ++i;
                    }
                }
            cout<<s;
            }

};
int main()
{
FunctionOverload obj;
char s1[100];
char s2[100];
int m = 0;
int n = 0;

cout<< "enter string to find length ";
cin>>s1;
cout<< obj.Stringop(s1);
cout<<"\nenter strings to concat :";
cout<<"1: ";
cin>>s1;
cout<<"2: ";
cin>>s2;
obj.Stringop(s1,s2);

cout<<"\nenter strings to compare :";
cout<<"1: ";
cin>>s1;
cout<<"2: ";
cin>>s2;
cout<<obj.Stringop(s1,s2,0);

cout<<"\nenter string to substring :";
cin>>s1;
cout<<"enter start index ";
cin>>m;
cout<<"enter end index ";
cin>>n;
obj.Stringop(s1,m,n);

cout<<"\nenter string to reverse :";
cin>>s1;

obj.Stringop(s1,-1);
cout<<"\nenter string:";
cin>>s1;
cout<<"0 for lower case and 1 for upper case :";
cin>>m;
obj.Stringop(s1,bool(m));

return 0;
}
