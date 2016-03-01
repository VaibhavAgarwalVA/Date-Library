//include headers
#include <bits/stdc++.h>

//include namespaces
using namespace std;

namespace funct {

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
		df = form.substr( 0, size1 );
	
		int size2 = second - first - 1 ;
		mf = form.substr( first + 1, size2 );
	
		int size3 = (n-1) - second;
		yf = form.substr( second + 1, size3 );
	
	}

	/*****************************************************/

	int noOfHyphens ( string st ) const
		throw ( invalid_argument, domain_error, out_of_range )
	{
		int num  = 0;
		int size = strlen( st );
	
		for(int i=0; i<size; i++){
			if(st[i] == '-')
				num++;
		}
	
		return num;
	}	
	
	/*****************************************************/
	
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

	
}

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
