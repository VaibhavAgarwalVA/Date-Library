//include headers
#include <bits/stdc++.h>

//include namespaces
using namespace std;

class DateFormat 
{
	public:
	//constructors
	DateFormat(const char* dateFormat, const char* monthFormat, const char* yearFormat);
	DateFormat(const char* format);
	DateFormat();
	
	//destructor
	~DateFormat();

	//getters
	char* getDF();
	char* getMF();
	char* getYF();
	
	//setters
	void getDF(char* st);
	void getMF(char* st);
	void getYF(char* st);
	
	private:
	char* dateFormat;
	char* monthFormat;
	char* yearFormat;		
};
