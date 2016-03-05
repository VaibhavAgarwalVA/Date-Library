#include "Date.h"

void TestDate()
{
	try{
		DateFormat dff("aa-bb-yy");
		Date::setFormat(dff);
		cout<<"OK"<<endl;
		Date gh;
		cout<<gh<<endl;
		DateFormat df("dd-mmm-yy");
		Date::setFormat(df);
		
		cout<<"Lets keep going..."<<endl;
		Date a;
		a++;
		++a;
		cout<<"a = "<<a<<endl;
		cout<<"Here"<<endl;
		Date b( D28,Feb,2016 );
		cout<<"b= "<<b<<endl;
		//Date b("28-Feb-16");
		b = b+0;
		int n=a-b;
		cout<<a<<" - "<<b<<" = "<<n<<endl;
		Date c(D12,Feb,1981);
		cout<<"c = "<<c<<endl;
		Date cs(D01,Jan,2016);
		cout<<"cs = "<<cs<<endl;
		int nn = WeekNumber (cs);
		cout<<"Weeknumber: "<<nn<<endl;
		// for(int i=0; i<53; i++,c++){
		// 	WeekNumber wn=WeekNumber(c);
		// 	cout<<c<<" "<<wn<<endl;
		// }
		DateFormat ddff(0,0,0);
		Date::setFormat(ddff);
		Date ddae(D26,Feb,2002);
		cout<< ddae<<endl;;
		//cout<<n;
	}
	catch(invalid_argument& e){
		cout<<"You typed an incorrect argument..."<<e.what()<<endl;
	}
	catch(out_of_range& e){
		cout<<"You typed an out-of-range argument..."<<e.what()<<endl;
	}
	catch(domain_error& e){
		cout<<"There seems to be a domain error..."<<e.what()<<endl;
	}
	

}

int main() 
{
	TestDate();
/**/
	return 0;
}
