//header classes
#include "Date.h"
#include "DateFormat.h"

void checkDate( int day_, int month_, int year_ ) const                      //constant function. cannot alter values.
	throw ( invalid_argument, domain_error, out_of_range ) 
{

	//condition on years
	if(year_>= 2050 || year_ < 1950){
		throw out_of_range("");
	}
	
	//general condition 
	if( day_<=0 || month_<=0 ){
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


/***********************************************************************************/
/***********************************************************************************/
/***********************************************************************************/
/***********************************************************************************/


//Constructors

Date::Date (Day d, Month m, Year y) 
	throw( invalid_argument, domain_error, out_of_range )
{
	checkDate ( (int)d , (int)m, y );
	day   = d;
	month = m;
	year  = y;
}

/***********************************************************************************/

Date::Date (const char* str)
	throw( invalid_argument, domain_error, out_of_range )
{
	
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

	

