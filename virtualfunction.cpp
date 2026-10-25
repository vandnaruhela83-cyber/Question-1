 #include <iostream>
 usage namespace std;
 classs shape{
 	public:
 		shape() {cout  <<"shape constructed\n";
		 }
		 virtual void draw()const {
		 cout <<"Drawing a generic shape\n";
		 }
		 virtual -shape() {
		 	cout <<"shape destroyed\n";
		 }
 };
 class circle :public shape {
 	int*radius;
 	public;
 	circle (int r): radius(new int (r)) {
 		cout <<"circle constructed\n";
	 }
	 void draw() const override {
	 cout << "Drawing a circle,r ="<<*radius<<"\n";
	 }
	 -circle() override {
	 cout <<"circle destroyed (memory freed)\n";
	 }
 };
 int main() {
 	shape* s = new Circle(5);
 	s->draw();
 	delete s;
 	return 0;
 }
