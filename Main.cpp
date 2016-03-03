#include "Date.h"

int main() 
{
	try{
		DateFormat dff("dd-mm-yy");
		Date::setFormat(dff);

		Date gh;
		cout<<gh<<endl;
		DateFormat df("dd-mm-yy");
		Date::setFormat(df);
		
		cout<<"Lets keep going..."<<endl;
		Date a;
		a++;
		++a;
		cout<<"Here"<<endl;
		Date b;//("28-Feb-16");
		--b;
		int n=a-b;
		cout<<a<<" - "<<b<<" = "<<n<<endl;
		Date c;
		cout<<"c = "<<c<<endl;
		cout<<b+n<<endl;
		c= b+n;
		cout<<c<<endl;
		// for(int i=0; i<53; i++,c++){
		// 	WeekNumber wn=WeekNumber(c);
		// 	cout<<c<<" "<<wn<<endl;
		// }
		DateFormat ddff=Date::getFormat();
		cout<<n;
	}
	catch(invalid_argument& e){
		cout<<"YOu typed an incorrect argument..."<<e.what()<<endl;
	}
	catch(out_of_range& e){
		cout<<"YOu typed an out-of-range argument..."<<e.what()<<endl;
	}
	catch(domain_error& e){
		cout<<"There seems to be a domain error..."<<e.what()<<endl;
	}
	

		
/**/
	return 0;
}
