//header classes
#include "Date.h"


/***********************************************************************************/
/***********************************************************************************/
/***********************************************************************************/
/***********************************************************************************/

DateFormat Date::format("dd-mm-yy");

	void parsers ( string form, char* &df, char* &mf, char* &yf )
		throw (invalid_argument)
	{
		int first, second;                                                       //index of first and second hyphens
		int size = strlen(form.c_str());
	
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
		if(size1 == 0) {
			throw invalid_argument("");
		}
		strcpy( df , const_cast<char*> ((form.substr( 0, size1 )).c_str()));
	
		int size2 = second - first - 1 ;
		if(size1 == 0) {
			throw invalid_argument("");
		}
		strcpy( mf , const_cast<char*> ((form.substr( first + 1, size2 )).c_str()));
	
		int size3 = (size-1) - second;
		if(size1 == 0) {
			throw invalid_argument("");
		}
		strcpy( yf , const_cast<char*> ((form.substr( second + 1, size3 )).c_str()));
	
	}
	
	/********************************************************************************/	
	
	int noOfHyphen ( string st ) 
		
	{
		int num  = 0;
		int size = strlen( st.c_str() );
	
		for(int i=0; i<size; i++){
			if(st[i] == '-')
				num++;
		}
	
		return num;
	}	
	
	/*****************************************************/
	
	void checkDate( int day_, int month_, int year_ )                       //constant function. cannot alter values.
		
	{

		//condition on years
		if(year_>= 2050 || year_ < 1950){
			throw out_of_range("");
		}
	
		//general condition 
		if( day_<=0 || month_<=0  || month_>12 || month_>31 ){
			throw invalid_argument("");
		}
	
		//date and month condition
		int st= 0;
		switch(month_)
		{
			case 1: if( day_ > 31 )
					st=1; break;
			case 2: if( !year_%4 ){ 
						if( day_ > 29 ) {
							st=1;
							break;
						}
					}
					else{
						if( day_ > 28 ) {
							st=1;
							break;
						}
					}
			case 3: if( day_ > 31 )
					st=1; break;
			case 4: if( day_ > 30 )
					st=1; break;
			case 5: if( day_ > 31 )
					st=1; break;
			case 6: if( day_ > 30 )
					st=1; break;
			case 7: if( day_ > 31 )
					st=1; break;
			case 8: if( day_ > 31 )
					st=1; break;
			case 9: if( day_ > 30 )
					st=1; break;
			case 10: if( day_ > 31 )
					st=1; break;
			case 11: if( day_ > 30 )
					st=1; break;
			case 12: if( day_ > 31 )
					st=1; break;
			default: throw invalid_argument("");
					 break;			 
		}
		if(st==1){
			throw domain_error("");
		}
	
	}

	/*********************************************************************/
	
	int Date::countLeapYears( Date d ) 
	{
		int years = d.year;
	 
		// Check if the current year needs to be considered
		// for the count of leap years or not
		if (d.month <= 2)
		    years--;
	 
		// An year is a leap year if it is a multiple of 4,
		// multiple of 400 and not a multiple of 100.
		return ( years/4 - years/100 + years/400 );
	}
	
	/*********************************************************************/
	
	long long int Date::dayNumber( Date dt ) 
	{
		int m,d,y;
		m = (dt.month + 9)%12;
		y = dt.year - m/10;
		d = dt.day;
		
		return (365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + ( d - 1 ));
	}
	 
	/*********************************************************************/ 
	 
	

/*********************************************************************/ 
/*********************************************************************/ 
/*********************************************************************/ 
/*********************************************************************/ 




//Constructors

Date::Date (Day d, Month m, Year y) throw( invalid_argument, domain_error, out_of_range )
{
	checkDate ( (int)d , (int)m, y );
	day   = d;
	month = m;
	year  = y;
	//cout<<"Date constructed"<<endl;
}

/***********************************************************************************/

Date::Date (const char* str) throw(invalid_argument, domain_error, out_of_range)
{
	/*
	if(!strcmp(format.getMF(),"mmm")){
        throw invalid_argument("Output only field");
    }
    /***/
    
	if(format.getDF()==NULL || format.getMF()==NULL || format.getYF()==NULL){
		//cout<<"Format Not Specified. Error."<<endl;
		throw invalid_argument("Format Not Specified. Error.");
	}
	
	string stri (str);
	int n = noOfHyphen ( stri );
	if( n!= 2 ){
		throw invalid_argument("Less than the req no of separators found !!");
	}
	
	char* d;
	char* m;
	char* y;
	d = new char[5];
 	m = new char[5];
 	y = new char[5];
 	

	parsers( stri, d, m, y );
	
 	//cout<<"DATE: "<<d<<endl;
 	//cout<<"MONTH: "<<m<<endl;
 	//cout<<"YEAR: "<<y<<endl;
	
	
	int dd=atoi(d);
	//cout<<dd<<endl;
	if(dd<10){
		if(strlen(d)!=strlen(format.getDF())) {
			throw invalid_argument("");
		}
	}
	
	int mm=atoi(m);
	//cout<<mm<<endl;
	if(strcmp(format.getMF(),"mmm")==0){
		if(strcmp(m,"Jan")==0)	mm=1;
		else if(strcmp(m,"Feb")==0)	mm=2;
		else if(strcmp(m,"Mar")==0)	mm=3;
		else if(strcmp(m,"Apr")==0)	mm=4;
		else if(strcmp(m,"May")==0)	mm=5;
		else if(strcmp(m,"Jun")==0)	mm=6;
		else if(strcmp(m,"Jul")==0)	mm=7;
		else if(strcmp(m,"Aug")==0)	mm=8;
		else if(strcmp(m,"Sep")==0)	mm=9;
		else if(strcmp(m,"Oct")==0)	mm=10;
		else if(strcmp(m,"Nov")==0)	mm=11;
		else if(strcmp(m,"Dec")==0)	mm=12;
		else	throw invalid_argument("");
	}
	else if(mm<10) {
		if(strlen(m)!=strlen(format.getMF())) {
			throw invalid_argument("");
		}	
	}
	
	int yy=atoi(y);
	if(strcmp(format.getYF(),"yy")==0){
		if(yy>=50) {	
			yy+=1900;
		}	
		else if(yy>=0) {
			yy+=2000;
		}
		else {
			throw out_of_range("");
		}	
	}
	
	// cout<<dd<<mm<<yy;
	checkDate(dd,mm,yy);
	
	day   = static_cast<Day> (dd);
	month = static_cast<Month> (mm);
	year  = yy;
	
	delete[] m,d,y;
}	
	
/************************************************************************************/

Date::Date()                            
	  throw(invalid_argument, domain_error, out_of_range)               // http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
{
	time_t t = time(0);   
    struct tm * now = localtime( & t );
    int y_ = now->tm_year + 1900; 
    int m_ = now->tm_mon + 1;
    int d_ = now->tm_mday;
    
	checkDate(d_,m_,y_);
	
	day   = static_cast<Day> (d_);
	month = static_cast<Month> (m_);
	year  = y_;
}

/**************************************************************************************/

Date::Date(const Date& d)  throw(invalid_argument, domain_error, out_of_range)        //copy constructor
{
	day   = d.day;
	month = d.month;
	year  = d.year;
}

/**************************************************************************************/

Date::~Date()  //destructor
{
	
}	

/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/

//Assignment 
Date& Date::operator= (const Date& date) throw(invalid_argument, domain_error, out_of_range)
{
	day   = date.day;
	month = date.month;
	year  = date.year;
	return *this;
}


/****************************************************************************************/
								//UNARY operators

Date& Date::operator++ ()
	throw(invalid_argument, domain_error, out_of_range)
{
	int dd = static_cast<int> (day);
	int mm = static_cast<int> (month);
	
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
	
	
	day   = static_cast<Day> (dd);
	month = static_cast<Month> (mm);
	
	return *this;
}	

Date& Date::operator++ (int)
	throw(invalid_argument, domain_error, out_of_range)
{
	int dd = static_cast<int> (day);
	int mm = static_cast<int> (month);
	
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
	
	
	day   = static_cast<Day> (dd);
	month = static_cast<Month> (mm);
	
	return *this;
}	



Date& Date::operator-- ()
	throw(invalid_argument, domain_error, out_of_range)
{
	int dd = static_cast<int> (day);
	int mm = static_cast<int> (month);
	
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
	
	
	day   = static_cast<Day> (dd);
	month = static_cast<Month> (mm);
	
	return *this;
}	

Date& Date::operator-- (int)
	throw(invalid_argument, domain_error, out_of_range)
{
	int dd = static_cast<int> (day);
	int mm = static_cast<int> (month);
	
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
	
	
	day   = static_cast<Day> (dd);
	month = static_cast<Month> (mm);
	
	return *this;
}

/****************************** UNARY COMPLETED ****************************************/
/***************************************************************************************/ 


//Boolean

bool Date::leapYear() const 
{
	if(year%4 == 0){
		return true;
	}
	return false;
}



/*********************************************************************/ 
/*********************************************************************/ 
				// binary comparator functions

bool Date::operator==(const Date& otherDate)
{
	if(otherDate.day == day && otherDate.month == month && otherDate.year == year){
		return true;
	}
	return false;
}

bool Date::operator!=(const Date& otherDate)
{
	if( *this == otherDate ) {
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


/*********************************************************************/ 
/*********************************************************************/ 
				// Binary operators (+,-)

unsigned int Date::operator- (const Date& other)
	throw(invalid_argument, domain_error, out_of_range)
{
	//Implementation 1: inspired from geeksforgeeks
	const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	int n1 = year*365 + day ;
	for(int i=0; i< month-1; i++){
		n1 += monthDays[i];
	}
	n1 += countLeapYears(*this);
	
	int n2 = other.year*365 + other.day ;
	for(int i=0; i< other.month-1; i++){
		n2 += monthDays[i];
	}
	n2 += countLeapYears(other);
	
	return (n1-n2)>0 ? (n1-n2) : (n2-n1);

	
	//Implementation 2: inspired from concordia
/*	
	long long int n1, n2;
	n1 = dayNumber(this);
	n2 = dayNumber(other);
	return (n1 - n2);

/**/	
}


Date Date::operator+ (int noOfDays)
	throw(invalid_argument, domain_error, out_of_range)
{
	tm t = {};
    t.tm_year = static_cast<unsigned int>(year)-1900;
    t.tm_mon  = static_cast<unsigned int>(month)-1;
    t.tm_mday = static_cast<unsigned int>(day);
    t.tm_mday += noOfDays;
    mktime(&t);
    Date d;
    d.year  = static_cast<Year> (1900+t.tm_year);
    d.month = static_cast<Month>(t.tm_mon+1);
    d.day   = static_cast<Day>  (t.tm_mday);
    
    checkDate( d.day, d.month, d.year );
    
    return d;
    
	/*
	int n = dayNumber(*this);
	n += noOfDays;
	cout<<"No of days: "<<noOfDays<<endl;
	cout<<"Day number: "<<n<<endl;
	
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
	
	Date d ( (Day) dd, (Month) mm, (Year) y);
	cout<<"New Day Number :"<<dayNumber(d)<<endl;
	if(y>=2050 || y<1950){
		throw out_of_range("");
	}
	return d;
	/***/
}


/*********************************************************************/ 
/*********************************************************************/ 

Date::operator WeekDay() const                                 //Sakamoto Algorithm
{
	//Works on called date:
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	int ye = year;
   	ye -= (month < 3);
   	int res = (ye + ye/4 - ye/100 + ye/400 + t[month-1] + day) % 7;
   	if(res == 0){
   		res = 7;
   	}
   	return (WeekDay) res;
   	
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

/*********************************************************************/ 

Date GetIsoWeekOne(int Year) {
	  // get the date for the 4-Jan for this year
	Date dt (D04, Jan, Year);

	  // get the ISO day number for this date 1==Monday, 7==Sunday
	int dayNumber = (int) WeekDay(dt);

	  // return the date of the Monday that is less than or equal
	  // to this date
	return dt + (1 - dayNumber);
} 


Date::operator WeekNumber() const                            // ISO 8601 Certified Date.
{	
	int IsoYear = year;
	Date week1;
	Date dte ( D29 , Dec, IsoYear );
	if (dte <= *this) {
		week1 = GetIsoWeekOne(IsoYear + 1);
		if (week1 > *this) {
		  	week1 = GetIsoWeekOne(IsoYear);
		}
		else {
	  		IsoYear++;
		}
	}
	else {
		week1 = GetIsoWeekOne(IsoYear);
		if (week1 > *this) {
			week1 = GetIsoWeekOne(--IsoYear);
		}
	}
	
	if(week1 == *this){
		return (WeekNumber)1;
	}
	return (WeekNumber)((week1 - *this - 1) / 7 + 1);
}


/*********************************************************************/ 
/*********************************************************************/ 

//FORMATS
void Date::setFormat(DateFormat& df)
{
	format= df;
	//cout<<format<<endl;
}

DateFormat& Date::getFormat()
{
	return format;
}


/*********************************************************************/ 
/*********************************************************************/ 

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
	int dd = static_cast<int> (d.day);
	int mm = static_cast<int> (d.month);
	
	if(strcmp(Date::format.getDF(),"0")==0){
		os<<"*-";
	}
	else if(Date::format.getDF()!=0)
	{
		if(dd>=10) {
			os<<dd;
		}
		else{
			if(strcmp(Date::format.getDF(),"d")==0){
				os<<dd;	
			}
			else {
				os<<"0"<<dd;
			}
		}
		os<<"-";
	}
	
	string full[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	string half[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	
	if(strcmp(Date::format.getMF(),"mmm")==0){
		if(mm>12 || mm<=0){
			os<<"Invalid format";
		}
		else{
			os<< half[mm-1];
		}
	}
	else if(strcmp(Date::format.getMF(),"0")!=0 && Date::format.getMF()!=0)
	{
		if(mm>9) {
			os<<mm;
		}
		else{
			if(strcmp(Date::format.getMF(),"m")==0){
				os<<mm;	
			}
			else {
				os<<"0"<<mm;
			}
		}
	}
	else{
		if(mm>12 || mm<=0){
			os<<"Invalid format";
		}
		else{
			os<< full[mm-1];
		}
	}
	
	if(strcmp(Date::format.getYF(),"0")==0){
		os<<"-*";
	}
	else if(Date::format.getYF()!=0){
		os<<"-";
		if(strcmp(Date::format.getYF(),"yy")==0){
			if(d.year%100<10) {
				os<<'0'<<d.year%100;
			}
			else {
				os<<d.year%100;
			}
		}
		else {
			os<<d.year;
		}
	}
	
	return os;
}



/*
//Main
int main() 
{
	DateFormat dff;
	
	Date::setFormat(dff);
	Date gh;
	cout<<gh<<endl;
	DateFormat df("dd-mmm-yy");
	Date::setFormat(df);
	Date a("22-Dec-96");
	Date b("28-Feb-16");
	cin>>a;
	int n=a-b;
	Date c("22-May-12");
	c=b+n;
	cout<<c<<endl;
	// for(int i=0; i<53; i++,c++){
	// 	WeekNumber wn=WeekNumber(c);
	// 	cout<<c<<" "<<wn<<endl;
	// }
	DateFormat ddff=Date::getFormat();
	cout<<n;
	
	return 0;
}
/***/
