//header classes
#include "Date.h"
#include "DateFormat.h"



/***********************************************************************************/
/***********************************************************************************/
/***********************************************************************************/
/***********************************************************************************/


//Constructors

Date::Date (Day d, Month m, Year y) 
	throw( invalid_argument, domain_error, out_of_range )
{
	funct::checkDate ( (int)d , (int)m, y );
	day   = d;
	month = m;
	year  = y;
}

/***********************************************************************************/

Date::Date (const char* str)
	throw( invalid_argument, domain_error, out_of_range )
{
	if(format.getDF()==NULL || format.getMF()==NULL || format.getYF()==NULL){
		cout<<"Format Not Specified. Error."<<endl;
		throw invalid_argument("");
	}
	
	int n = funct::noOfHyphens ( static_cast<string> str );
	if( n!= 2 ){
		throw invalid_argument("");
	}
	
	////reh gaya
}	
	
/************************************************************************************/

Date::Date()                            
	throw(domain_error,out_of_range)                   // http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
{
	time_t t = time(0);   
    struct tm * now = localtime( & t );
    int y_ = now->tm_year + 1900; 
    int m_ = now->tm_mon + 1;
    int d_ = now->tm_mday;
    
	checkDate(d_,m_,y_);
	
	day   = static_cast<Day> d_;
	month = static_cast<Month> m_;
	year  = y_;
}

/**************************************************************************************/

Date::Date(const Date& d)
{
	day   = d.day;
	month = d.month;
	year  = d.year;
}

/**************************************************************************************/

Date::~Date() 
{
	cout<<"Date object Destroyed"<<endl;
}	

/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/

Date& Date::operator= (Date& date) 
{
	day   = date.day;
	month = date.month;
	year  = date.year;
	return *this;
}


/****************************************************************************************/
//UNARY operators

Date& Date::operator++ ()
	throw ( out_of_range )
{
	int dd = static_cast<int> day;
	int mm = static_cast<int> month;
	
	if( mm==4 || mm==6 || mm==9 || mm==11 ){
		if( dd==30 ) {
			mm += 1;
			dd = 1;
		}
		else {
			dd += 1;
		}
	}
	
	else if( mm == 2 ) {
		if( year%4 == 0 ){
			if( dd == 29 ) {
				mm += 1;
				dd = 1;
			}
			else {
				dd += 1;
			}	
		}
		else {
			if( dd == 28 ) {
				mm += 1;
				dd = 1;
			}
			else {
				dd += 1;
			}	
		}
	}
	
	else {
		if( dd == 31 ) {
			dd = 1;
			if( mm==12 ) {
				year++;
				mm = 1;
				if(year == 2051){
					throw out_of_range("");
				}	
			}
			else {
				mm += 1;
			}
		}
		else {
			dd += 1;
		}
	}
	
	
	day   = static_cast<Day> dd;
	month = static_cast<Month> mm;
	
	return *this;
}	

Date& Date::operator++ (int)
	throw (out_of_range)
{
	int dd = static_cast<int> day;
	int mm = static_cast<int> month;
	
	if( mm==4 || mm==6 || mm==9 || mm==11 ){
		if( dd>=24 ) {
			mm += 1;
			dd -= 23;
		}
		else {
			dd += 7;
		}
	}
	
	else if( mm == 2 ) {
		if( year%4 == 0 ){
			if( dd >= 23 ) {
				mm += 1;
				dd -= 22;
			}
			else {
				dd += 7;
			}	
		}
		else {
			if( dd >= 22 ) {
				mm += 1;
				dd -= 21;
			}
			else {
				dd += 7;
			}	
		}
	}
	
	else {
		if( dd >= 25 ) {
			dd -= 24;
			if( mm==12 ) {
				year++;
				mm = 1;
				if(year == 2051){
					throw out_of_range("");
				}	
			}
			else {
				mm += 1;
			}
		}
		else {
			dd += 7;
		}
	}
	
	
	day   = static_cast<Day> dd;
	month = static_cast<Month> mm;
	
	return *this;
}	



Date& Date::operator-- ()
	throw (out_of_range)
{
	int dd = static_cast<int> day;
	int mm = static_cast<int> month;
	
	if( mm==2 || mm==4 || mm==6 || mm==8 || mm==9 || mm==11 ){
		if( dd==1 ) {
			mm -= 1;
			dd = 31;
		}
		else {
			dd -= 1;
		}
	}
	
	else if( mm == 3 ) {
		if( year%4 == 0 ){
			if( dd == 1 ) {
				mm -= 1;
				dd = 29;
			}
			else {
				dd -= 1;
			}	
		}
		else {
			if( dd == 1 ) {
				mm -= 1;
				dd = 28;
			}
			else {
				dd -= 1;
			}	
		}
	}
	
	
	else {
		if( dd == 1 ) {
			dd = 30;
			if( mm==1 ) {
				mm = 12;
				dd = 31;
				year--;
				if(year <= 1949){
					throw out_of_range("");
				}	
			}
			else {
				mm -= 1;
			}
		}
		else {
			dd -= 1;
		}
	}
	
	
	day   = static_cast<Day> dd;
	month = static_cast<Month> mm;
	
	return *this;
}	

Date& Date::operator-- (int)
	throw (out_of_range)
{
	int dd = static_cast<int> day;
	int mm = static_cast<int> month;
	
	if( mm==2 || mm==4 || mm==6 || mm==8 || mm==9 || mm==11 ){
		if( dd<=7 ) {
			mm -= 1;
			dd += 24;
		}
		else {
			dd -= 7;
		}
	}
	
	else if( mm == 3 ) {
		if( year%4 == 0 ){
			if( dd <= 7 ) {
				mm -= 1;
				dd += 22;
			}
			else {
				dd -= 7;
			}	
		}
		else {
			if( dd <= 7 ) {
				mm -= 1;
				dd += 21;
			}
			else {
				dd -= 7;
			}	
		}
	}
	
	
	else {
		if( dd <= 7 ) {
			dd += 23;
			if( mm==1 ) {
				mm = 12;
				dd += 1;
				year--;
				if(year <= 1949){
					throw out_of_range("");
				}	
			}
			else {
				mm -= 1;
			}
		}
		else {
			dd -= 7;
		}
	}
	
	
	day   = static_cast<Day> dd;
	month = static_cast<Month> mm;
	
	return *this;
}

/****************************** UNARY COMPLETED ****************************************/


//Boolean

bool leapYear() const 
{
	if(year%4 == 0){
		return true;
	}
	return false;
}

bool operator==(const Date& otherDate)
{
	if(otherDate.day == day && otherDate.month == month && otherDate.year == year){
		return true;
	}
	return false;
}

bool operator!=(const Date& otherDate)
{
	if( this == otherDate ) {
		return false;
	}
	return true;
}

bool operator<
