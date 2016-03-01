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

explicit Date::Date (const char* str)
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

bool Date::leapYear() const 
{
	if(year%4 == 0){
		return true;
	}
	return false;
}

bool Date::operator==(const Date& otherDate)
{
	if(otherDate.day == day && otherDate.month == month && otherDate.year == year){
		return true;
	}
	return false;
}

bool Date::operator!=(const Date& otherDate)
{
	if( this == otherDate ) {
		return false;
	}
	return true;
}

bool Date::operator< (const Date& other)
{
	if(year < other.year){
		return true;
	}
	else if(year == other.year && month < other.month){
		return true;
	}
	else if(year == other.year && month == other.month && day < other.day){
		return true;
	}
	else {
		return false;
	}
}

bool Date::operator<= (const Date& other)
{
	if(year < other.year){
		return true;
	}
	else if(year == other.year && month < other.month){
		return true;
	}
	else if(year == other.year && month == other.month && day <= other.day){
		return true;
	}
	else {
		return false;
	}
}

bool Date::operator> (const Date& other)
{
	if(year > other.year){
		return true;
	}
	else if(year == other.year && month > other.month){
		return true;
	}
	else if(year == other.year && month == other.month && day > other.day){
		return true;
	}
	else {
		return false;
	}
}

bool Date::operator>= (const Date& other)
{
	if(year > other.year){
		return true;
	}
	else if(year == other.year && month > other.month){
		return true;
	}
	else if(year == other.year && month == other.month && day >= other.day){
		return true;
	}
	else {
		return false;
	}
}

unsigned int Date::operator- (const char& other)
{
	//Implementation 1: inspired from geeksforgeeks
	const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	unsigned int n1 = year*365 + day ;
	for(int i=0; i< month-1; i++){
		n1 += monthDays[i];
	}
	n1 += funct::countLeapYears(*this);
	
	unsigned int n2 = other.year*365 + other.day ;
	for(int i=0; i< other.month-1; i++){
		n2 += monthDays[i];
	}
	n2 += funct::countLeapYears(other);
	
	return (n1 - n2);

	
	//Implementation 2: inspired from concordia
/*	
	long long int n1, n2;
	n1 = funct::dayNumber(this);
	n2 = funct::dayNumber(other);
	return (n1 - n2);

/**/	
}


Date Date::operator+ (int noOfDays)
	throw( domain_error, out_of_range )
{
	int n = funct::dayNumber(*this);
	n += noOfDays;
	
	int y = (10000*n + 14780)/3652425 ;
	int ddd = n - (365*y + y/4 - y/100 + y/400) ;
	if (ddd < 0) {
	 	y = y - 1 ;
	 	ddd = n - (365*y + y/4 - y/100 + y/400) ;
	}
	int mi = (100*ddd + 52)/3060;
	int mm = (mi + 2)%12 + 1;
	y = y + (mi + 2)/12;
	int dd = ddd - (mi*306 + 5)/10 + 1;	
	
	Date d= new Date(dd,mm,y);
	if(y>=2050 || y<1950){
		throw out_of_range("");
	}
	return d;
}


Date::operator Weekday() const                                 //Sakamoto Algorithm
{
	//Works on called date:
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
   	year -= month < 3;
   	int res = (year + year/4 - year/100 + year/400 + t[m-1] + day) % 7;
   	if(res == 0){
   		res = 7;
   	}
   	return (Weekday) res;
   	
   	//Implementation using Library:
   	/*
   	tm time_in = { 0, 0, 0, (int)day, (int) month- 1, year-1900 }; 
	time_t time_temp = mktime( &time_in );
	tm const *time_out = localtime( & time_temp );
	int res = time_out->tm_wday;
	if(res==0) {
		res=7;
	}
	return WeekDay( res );
	/**/
}


Date::operator Month() const
{
	return month;
}


Date GetIsoWeekOne(int Year) {
	  // get the date for the 4-Jan for this year
	Date dt = new Date(Year, 1, 4);

	  // get the ISO day number for this date 1==Monday, 7==Sunday
	int dayNumber = (int) WeekDay(dt);

	  // return the date of the Monday that is less than or equal
	  // to this date
	return dt + (1 - dayNumber);
} 


Date::operator WeekNumber() const                            // ISO 8601 Certified Date.
{	
	int IsoYear = year;
	if (*this >= new Date(IsoYear, 12, 29)) {
		Date week1 = GetIsoWeekOne(IsoYear + 1);
		if (*this < week1) {
		  	week1 = GetIsoWeekOne(IsoYear);
		}
		else {
	  		IsoYear++;
		}
	}
	else {
		Date week1 = GetIsoWeekOne(IsoYear);
		if (*this < week1) {
			week1 = GetIsoWeekOne(--IsoYear);
		}
	}

	return ((*this - week1) / 7 + 1);
}


//FORMATS
void Date::setFormat(DateFormat& df)
{
	format=df;
}

DateFormat& Date::getFormat()
{
	return format;
}


//Streams
istream& operator>> (istream& is, Date& d){
	char s[20];                          //2+4+2+9
	is>>s;
	try{
		Date temp(s);
		d= temp;
	}
	catch(...){
		Date temp(D26,Feb,1996);	//default date
		d= temp;
		return is;
	}
	return is;
}

ostream& operator<<(ostream& os, const Date& d){
	int dd = static_cast<int> d.day;
	int mm = static_cast<int> d.month;
	if(Date::format.getdateFormat()!=0)
	{
		if(dd>9) {
			os<<dd;
		}
		else{
			if(strcmp(Date::format.getdateFormat(),"d")==0){
				os<<dd;	
			}
			else {
				os<<"0"<<dd;
			}
		}
		os<<"-";
	}
	
	if(strcmp(Date::format.getmonthFormat(),"mmm")==0){
		switch(mm){
		case 1:	os<<"Jan";	break;
		case 2:	os<<"Feb";	break;
		case 3:	os<<"Mar";	break;
		case 4:	os<<"Apr";	break;
		case 5:	os<<"May";	break;
		case 6:	os<<"Jun";	break;
		case 7:	os<<"Jul";	break;
		case 8:	os<<"Aug";	break;
		case 9:	os<<"Sep";	break;
		case 10: os<<"Oct"; break;
		case 11: os<<"Nov";	break;
		case 12: os<<"Dec";	break;
		default: os<<"Not valid";
		}
	}
	else if(Date::format.getmonthFormat()!=0)
	{
		if(mm>9) {
			os<<mm;
		}
		else{
			if(strcmp(Date::format.getmonthFormat(),"m")==0){
				os<<mm;	
			}
			else {
				os<<"0"<<mm;
			}
		}
	}
	else{
		switch(mm){
		case 1:	os<<"January";	break;
		case 2:	os<<"February"; break;
		case 3:	os<<"March";	break;
		case 4:	os<<"April";	break;
		case 5:	os<<"May";		break;
		case 6:	os<<"June";		break;
		case 7:	os<<"July";		break;
		case 8:	os<<"August";	break;
		case 9:	os<<"September";break;
		case 10: os<<"October"; break;
		case 11: os<<"November";break;
		case 12: os<<"December";break;
		default: os<<"Invalid";
		}
	}
	
	if(Date::format.getyearFormat()!=0){
		os<<"-";
		if(strcmp(Date::format.getyearFormat(),"yy")==0){
			if(d.year%100<10) {
				os<<'0'<<d.year%100;
			}
			else {
				os<<d.year%100;
			}
		}
		else {
			cout<<d.year;
		}
	}
	return os;
}


