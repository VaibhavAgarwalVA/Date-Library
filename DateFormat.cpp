#include "Date.h"


int noOfHyphens ( string st ) 
		
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
	
void checkFormat_NULL( char* df, char* mf, char* yf) 
	throw ( invalid_argument, domain_error, out_of_range )
{
	
	if(strcmp(df,"0")==0) {
		;
	}
	else if(df!=0 && strcmp(df,"d")!=0 && strcmp(df,"dd")!=0){
		cout<<"Date Format Assigned - NULL"<<endl;
		delete[] df;
		df= NULL;
	}
	if(mf!=0 && strcmp(mf,"0")!=0 && strcmp(mf,"mm")!=0 && strcmp(mf,"m")!=0 && strcmp(mf,"mmm")!=0){
		cout<<"Month Format Assigned - NULL"<<endl;
		delete[] mf;
		mf= NULL;
	}
	if(strcmp(yf,"0")==0){
		;
	}
	else if(yf!=0 && strcmp(yf,"yy")!=0 && strcmp(yf,"yyyy")!=0){
		cout<<"Year Format Assigned - NULL"<<endl;
		delete[] yf;
		yf= NULL;
	} 
}	

/*****************************************************/


void parser ( string form, char* &df, char* &mf, char* &yf )
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
		
		//cout<<"String received: "<<form<<endl;
		int size1 = first;
		if(size1 == 0) {
			throw invalid_argument("");
		}
		strcpy(df, const_cast<char*> ((form.substr( 0, size1 )).c_str()));
		//cout<<"Day format assigned: "<<df<<endl;
	
		int size2 = second - first - 1 ;
		if(size1 == 0) {
			throw invalid_argument("");
		}
		strcpy(mf ,const_cast<char*> ((form.substr( first + 1, size2 )).c_str()));
		//cout<<"Month Format assigned: "<<mf<<endl;
	
		int size3 = (size-1) - second;
		if(size1 == 0) {
			throw invalid_argument("");
		}
		strcpy(yf , const_cast<char*> ((form.substr( second + 1, size3 )).c_str()));
		//cout<<"Year format assigned: "<<yf<<endl;
	
		//cout<<"Exiting parser..."<<endl;
	}

/*****************************************************/
/*****************************************************/
/*****************************************************/

//constructors

DateFormat::DateFormat(const char* dForm, const char* mForm, const char* yForm)      //constructor taking in all formats
	throw ( invalid_argument, domain_error, out_of_range ) 
{	
 	dateFormat = new char[5];
 	monthFormat = new char[5];
 	yearFormat = new char[5];
 	
	//cout<<"here"<<endl;
	if(mForm == NULL){
		//cout<<"Abhi"<<endl;
		string s("0");
		char* temp = const_cast<char *> (s.c_str());
		strcpy ( monthFormat , temp);
		//cout<<"Ab"<<endl;
	}
	else{
		strcpy( monthFormat , const_cast<char *> (mForm));
	}
	
	//cout<<"here"<<endl;
	if(dForm == NULL){
		//cout<<"Abhi"<<endl;
		string s("0");
		char* temp = const_cast<char *> (s.c_str());
		strcpy ( dateFormat , temp);
		//cout<<"Ab"<<endl;
	}
	else{
		strcpy( dateFormat , const_cast<char *> (dForm));
	}
	
	//cout<<"here"<<endl;
	if(yForm == NULL){
		//cout<<"Abhi"<<endl;
		string s("0");
		char* temp = const_cast<char *> (s.c_str());
		strcpy ( yearFormat , temp);
		//cout<<"Ab"<<endl;
	}
	else{
		strcpy( yearFormat , const_cast<char *> (yForm));
	}
	checkFormat_NULL ( dateFormat, monthFormat, yearFormat );
}

/*****************************************************/

DateFormat::DateFormat(const char* format)                                           // constructor taking the parse string as input
	throw ( invalid_argument, domain_error, out_of_range ) 
{
	char* formatString = const_cast<char *> (format);
	string str(formatString);
	
	int n = noOfHyphens (str);
	if( n != 2 ){
		cout<<"Format Assigned - NULL-NULL-NULL"<<endl;
		dateFormat  = NULL;
		monthFormat = NULL;
		yearFormat  = NULL;
		return;
 	}
 	
 	dateFormat = new char[5];
 	monthFormat = new char[5];
 	yearFormat = new char[5];
 	
	parser( str, dateFormat, monthFormat, yearFormat );                     		// str has 2 hyphens
	//cout<<"Day format assigned: "  << dateFormat << endl;
	//cout<<"Month format assigned: "<< monthFormat<< endl;
	//cout<<"Year format assigned: " << yearFormat << endl;
	
	checkFormat_NULL ( dateFormat, monthFormat, yearFormat );
	
	//cout<<"Assigned Date Format: "<< dateFormat<<"-"<<monthFormat<<"-"<<yearFormat<<endl;
}

/*****************************************************/

DateFormat::DateFormat() 
	{
		dateFormat = new char[2];
		strcpy(dateFormat, "dd");
		
		monthFormat = new char[3];
		strcpy(monthFormat, "mmm");
		
		yearFormat = new char[4];
		strcpy(yearFormat, "yy");
		//cout<<"Default Constructor called. Format Assigned - dd-mmm-yy"<<endl;
	}

/*****************************************************/
/*****************************************************/

//Destructor
DateFormat::~DateFormat() {
	
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
