#include "DateFormat.h"


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
	funct::checkFormat_NULL ( dateFormat, monthFormat, yearFormat );
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
 	
	funct::parser( str, dateFormat, monthFormat, yearFormat );                     		// str has 2 hyphens
	
	funct::checkFormat_NULL ( dateFormat, monthFormat, yearFormat );
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
