#include "Date.h"

void checkFormat_NULL( char* df, char* mf, char* yf) 
	throw ( invalid_argument, domain_error, out_of_range )
{
	if(df!=0 && strcmp(df,"d")!=0 && strcmp(df,"dd")!=0){
		cout<<"Date Format Assigned - NULL"<<endl;
		delete[] df;
		df= NULL;
	}
	if(mf!=0 && strcmp(mf,"mm")!=0 && strcmp(mf,"m")!=0 && strcmp(mf,"mmm")!=0){
		cout<<"Month Format Assigned - NULL"<<endl;
		delete[] mf;
		mf= NULL;
	}
	if(yf!=0 && strcmp(yf,"yy")!=0 && strcmp(yf,"yyyy")!=0){
		cout<<"Year Format Assigned - NULL"<<endl;
		delete[] yf;
		yf= NULL;
	} 
}	

/*****************************************************/

void parser ( string form, char* df, char* mf, char* yf )
	throw ( invalid_argument, domain_error, out_of_range )
{
	int first, second;                                                       //index of first and second hyphens
	int size = strlen(form);

	first = -1;
	for(int i=0; i<size; i++) {
		if(form[i] == '-' && first==-1){
			first = i;
		}
		else if(form[i] == '-'){
			second = i;
		}
	}

	int size1 = first;
	df = static_cast<char*> (form.substr( 0, size1 ));

	int size2 = second - first - 1 ;
	mf = static_cast<char*> (form.substr( first + 1, size2 ));

	int size3 = (n-1) - second;
	yf = static_cast<char*> (form.substr( second + 1, size3 ));

}

/*****************************************************/
/*****************************************************/
/*****************************************************/

//constructors

DateFormat::DateFormat(const char* dForm, const char* mForm, const char* yForm)      //constructor taking in all formats
	throw ( invalid_argument, domain_error, out_of_range ) 
{	
	dateFormat  = const_cast<char *> dForm;
	monthFormat = const_cast<char *> mForm;
	yearFormat  = const_cast<char *> yForm;
	checkFormat_NULL ( dateFormat, monthFormat, yearFormat );
}

/*****************************************************/

DateFormat::DateFormat(const char* format)                                           // constructor taking the parse string as input
	throw ( invalid_argument, domain_error, out_of_range ) 
{
	char* formatString = const_cast<char *> format;
	string str = static_cast<string> formatString;
	
	int n = funct::noOfHyphens (str);
	if( n != 2 ){
		cout<<"Format Assigned - NULL-NULL-NULL"<<endl;
		dateFormat  = NULL;
		monthFormat = NULL;
		yearFormat  = NULL;
		return;
 	}
 	
 	DateFormat();
 	
	parser( str, dateFormat, monthFormat, yearFormat );                     		// str has 2 hyphens
	
	checkFormat_NULL ( dateFormat, monthFormat, yearFormat );
}

/*****************************************************/

DateFormat::DateFormat() :          //default constructor
	dateFormat("dd"),
	monthFormat("mmm"),
	yearFormat("yyyy")
	{
		cout<<"Default Constructor called. Format Assigned - dd-mmm-yyyy"<<endl;
	}

/*****************************************************/
/*****************************************************/

//Destructor
DateFormat::~DateFormat() {
	cout<<"Destructed DateFormat"<<endl;
}


/*****************************************************/

//getter and setters

char* DateFormat::getDF(){
	return dateFormat;
}

char* DateFormat::getMF(){
	return monthFormat;
}

char* DateFormat::getYF(){
	return yearFormat;
}

void DateFormat::setDF( char* st ){
	dateFormat = st;
}

void DateFormat::setMF( char* st ){
	monthFormat = st;
}

void DateFormat::setYF( char* st ){
	yearFormat = st;
}

/******************************************************/
