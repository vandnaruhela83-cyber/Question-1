#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
 using namespace std;
 
class  Employee {
	int id;
	string name ;
	double salary;
	public:
	Employee(int i ,string n, double s) : id(i), name(n), salary(s) {
	}
	
	friend ostream& operator<<(ostream& out, const Employee& e) {
	   out << left << setw(6)<< e.id
	       << setw(10) << e.name
	       << right << setw(8) << e.salary;
	   return out;	
	}
};
class  Employees {
	vector<Employee> list;
	public:
	void add(const Employee& e){list.push_back(e);
	}
	friend ostream& operator<<(ostream& out,  const Employees& es) 
{
    	out << left << setw(6) << "ID"
	        << setw(10) << "Name"
    	    << right << setw(8) <<"salary" << "\n";
	    out << "------------------------\n";
	    for (const  auto&  e : es.list)
	        out << e << "\n";
	    return out;
    }
};
int main() {
	Employees team;
	team.add(Employee(101, "Aarav", 55000));
	team.add(Employee(102, "Meera", 48000));
	team.add(Employee(103, "karan", 62000));
	
	cout << "Employee List\n" <<  team;
	return 0;
	}
