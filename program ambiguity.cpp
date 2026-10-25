#include <iostream>

using namespace std;
class intern {
	string name = "unknoclass";
};
class intern : public person {};
class Employeee : public person{};
class intern : public student,public Employee {};
int main(){
	intern i;
	i.student::name ="Ravi";
	i.Enployee::name ="Ankit";  
	cout <<i.student::name <<endl;
	cout <<i.employee::name<<emdl
	cout << sizeof (intern)<<endl
}
