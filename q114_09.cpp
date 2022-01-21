#include <iostream>
#include <cstdlib>
using namespace std;
class DETS_DB {
    private:
        char name[100];
        char dicipline[3];
        int Roll;
        int sem;
        float cgpa;
    public:
    void add(char* n, char* dic,float grade,int rl,int s){
        int i;
        for(i=0; n[i]!='\0';i++){
                name[i]=n[i];
        }
        name[i]='\0';
        for(i=0; dic[i]!='\0';i++){
                dicipline[i]=dic[i];
        }
        dicipline[i]='\0';
        Roll=rl;
        sem=s;
        cgpa=grade;
    }
    void display(){
        cout<<"\n\n\nROLL number: "<<Roll;
        cout<<"\nName: "<<name;
        cout<<"\nStream: "<<dicipline;
        cout<<"\nSemester: "<<sem;
        cout<<"\nCGPA: "<<cgpa<<"\n\n\n";
    }
};
int main()
{
  char name[100];
  char dic[3];
  int sem;
  float cgpa;
  int n;
  cout<<"Enter number of students:";
  cin>>n;
  DETS_DB* arr = (DETS_DB*)malloc(sizeof(DETS_DB) * n);
  int i;
  //
  //Entering the student details
  //
  for(i=0; i < n; i++){
    cout<<"Roll of Student is "<<i;
    cin.ignore();
    cout<<"Enter name:";
    cin.getline(name,100);
    cout<<"Enter Stream:";
    cin>>dic;
    cout<<"Enter Semester and CGPA:";
    cin>>sem>>cgpa;
    arr[i].add(name,dic,cgpa,i,sem);
  }
  //
  // Deleting Student Details
  //
  char c;
  cout<<"Do you want to delete a student? (Y/N)";
  cin>>c;
  while(c=='y'||c=='Y'){
    cout<<"Enter Roll of student:";
    cin>>roll;
    for (i=roll-1;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n=n-1;
    cout<<"Do you want to delete more? (Y/N) :";
    cin>>c;
  }
  cout<<"Displaying Data";
  for(i=0; i < n; i++)
    arr[i].display();
return 0;
}
