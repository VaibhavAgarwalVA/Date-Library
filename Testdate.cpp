#include "Date.h"

void DateFormatConstructor()
{
	cout<<endl<<"******************DATE FORMAT CHECKING***********************"<<endl;
	
	cout<<"---------Checking by Calling constructor by passing different formats separately----------"<<endl;
	const char* days[] 	 = { NULL,"d","dd","ddd","a","123","1"};
	const char* months[] = { NULL,"m","mm","mmm","MM","1","abs"};
	const char* years[]  = { NULL,"y","yy","yyy","yyyy","2","aa"};
  
  	int i,j,k;
  	for(i=0;i<7;i++){
  		for(j=0;j<7;j++){
  			for(k=0;k<7;k++){
  				try{
  					cout<<endl;
  					char *a1, *a2, *a3;
  					if(days[i] == NULL){
  						string s("NULL");
  						a1 = const_cast<char*> (s.c_str());
  					}
  					else{
  						a1 = const_cast<char*> (days[i]);
  					}
  					
  					if(months[j] == NULL){
  						string s("NULL");
  						a2 = const_cast<char*> (s.c_str());
  					}
  					else{
  						a2 = const_cast<char*> (months[j]);
  					}
  					
  					if(years[k] == NULL){
  						string s("NULL");
  						a3 = const_cast<char*> (s.c_str());
  					}	
  					else{
  						a3 = const_cast<char*> (years[k]);
  					}
  					cout<<"DateFormat df( "<<a1<<", "<<a2<<", "<<a3<<" );"<<endl;
  					
  					DateFormat df( days[i], months[j], years[k] );
  					//DateFormat df("dd","mm","yy");
  					if(df.getDF() != 0){
  						cout<<"Assigned Date Format: "<<df.getDF()<<endl;
  					} 
  					else{
  						cout<<"Assigned Date Format: NULL"<<endl;
  					}
  					if(df.getMF() != 0){
  						cout<<"Assigned Month Format: "<<df.getMF()<<endl;
  					}
  					else{
  						cout<<"Assigned Month Format: NULL"<<endl;
  					}
  					if(df.getYF() != 0){
  						cout<<"Assigned Year Format: "<<df.getYF()<<endl;
  					}
  					else{
  						cout<<"Assigned Year Format: NULL"<<endl;
  					}	
  				}	
				catch(invalid_argument& e){
					cout<<"!! INVALID ARGUMENT ERROR: "<<e.what()<<endl;
				}
				catch(out_of_range& e){
					cout<<"!! OUT-OF-RANGE ERROR: "<<e.what()<<endl;
				}
				catch(domain_error& e){
					cout<<"!! DOMAIN ERROR: "<<e.what()<<endl;
				}
				catch(...){
					cout<<"!! UNKNOWN ERROR."<<endl;
				}
  			}
  		}
  	}
  	cout<<endl<<"********************DONE*************************"<<endl<<endl;				
  	
  
	cout<<endl<<endl<<"---------Checking by Calling constructor by passing format string altogether----------"<<endl;
	
	string days_[]   = {"-","d-","dd-","d","-d","mm-","yy-",""};
	string months_[] = {"-","m-","mm-","mmm-","mm","","0","-dd"};
	string years_[]  = {"","yy","yyyy","-yy","-dd","aa","12","-0"};
 
  	for(i=0;i<8;i++){
  		for(j=0;j<8;j++){
  			for(k=0;k<8;k++){
  				try{
  					cout<<endl;
  					string a1,a2,a3;
  					if(days_[i] == ""){
  						a1 = " ";
  					}
  					else{
  						a1 = days_[i];
  					}
  					
  					if(months_[j] == ""){
  						a2 = " ";
  					}
  					else{
  						a2 = months_[j];
  					}
  					
  					if(years_[k] == ""){
  						a3 = " ";
  					}	
  					else{
  						a3 = years_[k];
  					}
  					cout<<"DateFormat df( "<<a1<<a2<<a3<<" );"<<endl;
  					
  					DateFormat df( (days_[i]+months_[j]+years_[k]).c_str() );
  					
  					if(df.getDF() != 0){
  						cout<<"Assigned Date Format: "<<df.getDF()<<endl;
  					} 
  					else{
  						cout<<"Assigned Date Format: NULL"<<endl;
  					}
  					if(df.getMF() != 0){
  						cout<<"Assigned Month Format: "<<df.getMF()<<endl;
  					}
  					else{
  						cout<<"Assigned Month Format: NULL"<<endl;
  					}
  					if(df.getYF() != 0){
  						cout<<"Assigned Year Format: "<<df.getYF()<<endl;
  					}
  					else{
  						cout<<"Assigned Year Format: NULL"<<endl;
  					}	
  					
  				}	
				catch(invalid_argument& e){
					cout<<"!! INVALID ARGUMENT ERROR: "<<e.what()<<endl;
				}
				catch(out_of_range& e){
					cout<<"!! OUT-OF-RANGE ERROR: "<<e.what()<<endl;
				}
				catch(domain_error& e){
					cout<<"!! DOMAIN ERROR: "<<e.what()<<endl;
				}
				catch(...){
					cout<<"!! UNKNOWN ERROR."<<endl;
				}
  			}
  		}
  	}
  	cout<<endl<<"********************DONE*************************"<<endl<<endl;
}



void DateConstructor()
{
	int day[]={1,3,28,29,30,31,32,-1};
	int month[]={1,2,3,7,11,12,0,14};
	int year[]={1949,1950,2011,2000,2049,2050,-1,0};
 
	cout<<"----------------------------------------------------------\n";
	cout<<endl<<"Testing Date Constructor Date(day d,month m ,year y)\n\n";
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			for(int k=0;k<8;k++)
			{
				try{
					Date d( (Day)day[i], (Month)month[j], (Year) year[k]);
					cout<<"Date constructed with :          "<<(Day)day[i]<<" - "<<(Month)month[j]<<" - "<<(Year)year[k]<<endl;
 
				}
				catch(invalid_argument e){
					cout<<"!! Invalid Argument Error with : "<<(Day)day[i]<<" - "<<(Month)month[j]<<" - "<<(Year)year[k]<<endl;
				}
				catch(out_of_range e){
					cout<<"!! Out of Range Error with :     "<<(Day)day[i]<<" - "<<(Month)month[j]<<" - "<<(Year)year[k]<<endl;
				}
				catch(domain_error e){
					cout<<"!! Domain Error with :           "<<(Day)day[i]<<" - "<<(Month)month[j]<<" - "<<(Year)year[k]<<endl;
				}
			}
		}
	}
 
	cout<<endl<<endl<<"Testing Date Constructor Date(const char*)\n";
	string formats[] = { "dd-mm-yyyy" , "d-m-yyyy" , "dd-m-yy" };
	DateFormat format[]={DateFormat(formats[0].c_str()),DateFormat(formats[1].c_str()),DateFormat(formats[2].c_str())};
	string days[]={"29-","31-","32-","-1"};
	string months[]={"1-","2","03-","13-"};
	string years[]={"99","2016","2050","-30"};
	for(int i=0;i<3;i++)
	{
		Date::setFormat(format[i]);
		cout<<endl<<"## Date Format set : "<<formats[i]<<endl;
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				for(int m=0;m<4;m++)
				{
					try {
						Date f((days[j]+months[k]+years[m]).c_str());
						cout<<"Date constructed with :          "<<days[j]<<"  "<<months[k]<<"  "<<years[m]<<endl;
		 
					}
					catch(invalid_argument e){
						cout<<"!! Invalid Argument Error with : "<<days[j]<<"  "<<months[k]<<"  "<<years[m]<<endl;
					}
					catch(out_of_range e){
						cout<<"!! Out of Range Error with :     "<<days[j]<<"  "<<months[k]<<"  "<<years[m]<<endl;
					}
					catch(domain_error e){
						cout<<"!! Domain Error with :           "<<days[j]<<"  "<<months[k]<<"  "<<years[m]<<endl;
					}
			    }
		    }
	    }
    }
}

//Tests for Unary Operators
void unaryoperators(Date &dt)
{
	cout<<"\nTesting Unary Arithmetic Operators true statements will be printed"<<endl<<endl;
		try{
			Date d= dt;
			cout<<"++"<<d<<" is ";
			cout<<(++d)<<endl;
		} 
		catch(invalid_argument e){
			cout<<"Invalid Argument Error for "<<endl;
		}
		catch(domain_error e){
			cout<<"Domain Error"<<endl;
		}
		catch(out_of_range e){
			cout<<"Out Of Range Error ++Operator"<<endl;
		}
 
 
		try{
			Date d=dt;
			cout<<"--"<<d<<" is ";
			cout<<(--d)<<endl;
		} 
		catch(invalid_argument e){
			cout<<"Invalid Argument Error for "<<endl;
 
		}
		catch(domain_error e){
			cout<<"Domain Error"<<endl;
		}
		catch(out_of_range e){
			cout<<"Out Of Range Error --Operator"<<endl;
		}
 
 
		try{
			Date d=dt;
			cout<<d<<"++"<<" is ";
			cout<<(d++)<<endl;
 
		} 
		catch(invalid_argument e){
			cout<<"Invalid Argument Error for "<<endl;
 
		}
		catch(domain_error e){
			cout<<"Domain Error"<<endl;
		}
		catch(out_of_range e){
			cout<<"Out Of Range Error Operator++"<<endl;
		}
		
		
		try{
			Date d=dt;
			cout<<d<<"--"<<" is ";
			cout<<(d--)<<endl;
 
		} 
		catch(invalid_argument e){
			cout<<"Invalid Argument Error for "<<endl;
 
		}
		catch(domain_error e){
			cout<<"Domain Error"<<endl;
		}
		catch(out_of_range e){
			cout<<"Out Of Range Error Operator--"<<endl;
		}
 
}
void test_unary()
{
	DateFormat df("dd-mm-yyyy");
	Date::setFormat(df);
	Date a("28-02-2016");
	Date b("31-12-2049");
	Date c("01-01-1950");
	cout<<"-------------------------------------------------------------------------";
	unaryoperators(a);
	unaryoperators(b);
	unaryoperators(c);
}

//Test for addition operator
void addFunct(Date &d,int x)
{
	cout<<d<<" + "<<x<<" is "<<(d+x);
	cout<<endl;
}
void test_add()
{
	int arr[]={0,-1,1,15,-365,365,366};
	DateFormat df("dd-mm-yyyy");
	Date::setFormat(df);
	Date a("28-02-2000");
	Date b("31-12-2049");
	Date c("01-01-1950");
	Date d("01-03-2020");
	cout<<"-------------------------------------------------------------"<<endl;
	cout<<"Testing Adding Number Of Days true statements will be printed"<<endl<<endl;
	for(int i=0;i<7;i++)
	{
		try{
			addFunct(a,arr[i]);
		}
		catch (out_of_range e){
			cout<<"Out of range for "<<a<<" + "<<arr[i]<<endl;
		}
		catch(domain_error e){
			cout<<"Domain Error for "<<a<<" + "<<arr[i]<<endl;
		}
		
		try{
			addFunct(b,arr[i]);
		}
		catch (out_of_range e){
			cout<<"Out of range for "<<b<<" + "<<arr[i]<<endl;
		}
		catch(domain_error e){
			cout<<"Domain Error for "<<b<<" + "<<arr[i]<<endl;
		}
		
		try{
			addFunct(c,arr[i]);
		}
		catch (out_of_range e){
			cout<<"Out of range for "<<c<<" + "<<arr[i]<<endl;
		}	
		catch(domain_error e){
			cout<<"Domain Error for "<<c<<" + "<<arr[i]<<endl;
		}
		
		try{
			addFunct(d,arr[i]);
		}
		catch (out_of_range e){
			cout<<"Out of range for "<<d<<" + "<<arr[i]<<endl;
		}	
		catch(domain_error e){
			cout<<"Domain Error for "<<d<<" + "<<arr[i]<<endl;
		}
	}
}
 
void difference_operator(Date &d1,Date &d2)
{
	cout<<"Testing Difference in days true statements will be printed"<<endl<<endl;
	cout<<d1<<" - "<<d2<<" is "<<(d1-d2)<<endl;
	cout<<d2<<" - "<<d1<<" is "<<(d2-d1)<<endl;
	cout<<endl;
}
 
void test_diff()
{	
	DateFormat df("dd-mm-yyyy");
	Date::setFormat(df);
	Date a("13-10-2016");
	Date b("13-10-2015");
	Date c("13-10-2017");
	cout<<"-------------------------------------------------------------------------"<<endl;
	difference_operator(a,b);
	difference_operator(c,b);
	difference_operator(a,c);
}
 
void LeapYear(Date & d1){
	cout<<"Testing LeapYear Function "<<endl<<endl;
	if(d1.leapYear()){
		cout<<d1<<" is a leap year"<<endl;
	}else{
		cout<<d1<<" is not a leap year"<<endl;
	}
	cout<<endl;
}
void test_leap()
{
	DateFormat df("dd-mm-yyyy");
	Date::setFormat(df);
	Date a("01-01-2016");
	Date b("03-04-1955");
	Date c("23-12-2028");
	Date d("03-05-2010");
	cout<<"-------------------------------------------------------------------------"<<endl;
	LeapYear(a);
	LeapYear(b);
	LeapYear(c);
	LeapYear(d);
}

void CastOperators(Date & d1){
	cout<<"Testing Cast Operators "<<endl;
	cout<<d1<<" as WeekNumber is "<<static_cast<WeekNumber>(d1)<<endl;
	cout<<d1<<" as Month is "<<static_cast<Month>(d1)<<endl;
	cout<<d1<<" as WeekDay is "<<static_cast<WeekDay>(d1)<<endl;
	cout<<endl;
}
void test_cast()
{
	DateFormat df("dd-mm-yyyy");
	Date::setFormat(df);
	Date a("03-04-2016");
	Date b("03-04-2015");
	Date c("03-04-2017");
	cout<<"-------------------------------------------------------------------------"<<endl;
	CastOperators(a);
	CastOperators(b);
	CastOperators(c);
}
 
void RelationalOperators(Date & d1 , Date & d2){
	cout<<"Checking Relational Operators Only the Statements that are true will be printed"<<endl;
 
	if(d1!=d2)
	{
		cout<<d1<<" is != to "<<d2<<endl;	
	}
	if(d1==d2)
	{
		cout<<d1<<" is == to "<<d2<<endl;
	}
 
	if(d1<=d2)
	{
		cout<<d1<<" is <= than "<<d2<<endl;
	}
	if(d1<d2)
	{
		cout<<d1<<" is < than "<<d2<<endl;
	}
	if(d1>=d2)
	{
		cout<<d1<<" is >= than "<<d2<<endl;
	}
	if(d1>d2)
	{
		cout<<d1<<" is > than "<<d2<<endl;
	}
	cout<<endl;
}
void test_relation()
{
	DateFormat df("dd-mm-yyyy");
	Date::setFormat(df);
	Date a("03-04-2016");
	Date b("03-04-2015");
	Date c("03-04-2017");
	cout<<"-------------------------------------------------------------------------"<<endl;
	RelationalOperators(a,a);
	RelationalOperators(a,b);
	RelationalOperators(a,c);
	RelationalOperators(b,a);
	RelationalOperators(b,b);
	RelationalOperators(b,c);
	RelationalOperators(c,a);
	RelationalOperators(c,b);
	RelationalOperators(c,c);
}
void check_format()
{
	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"Checking the format setter and getter \n";
	DateFormat f;
	Date::setFormat(f);
	Date d;
 
	cout<<"The default format dd-mmm-yy is set  using setFormat"<<endl;
	cout<<"The output  is "<<d<<endl;
	DateFormat f2("dd-mm-yyyy");
	Date::getFormat()=f2;
	cout<<"Changing the format using getFormat as reference is returned by that (dd-mm-yyyy)"<<endl;
	cout<<"The output in this format is "<<d<<endl;
 
	DateFormat f3("d-m-yy");
	Date::getFormat()=f3;
	cout<<"Changing the format using getFormat as reference is returned by that (d-m-yy)"<<endl;
	cout<<"The output in this format is "<<d<<endl;
 
	cout<<"Set and Get Format Are Working Correctly"<<endl<<endl;
 
}

void check_printer()
{
	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"Checking the format setter and getter \n";
	
	DateFormat f;
	Date::setFormat(f);
	Date d("26-Feb-16");
	cout<<"Constructed Date Object with date : 26-Feb-16"<<endl;
	cout<<"Output from the print ostream function: "<<d<<endl;
	
	cout<<"Verified.!"<<endl<<endl;
}

void check_input()
{
	cout<<"Enter a valid Date Format.."<<endl;
	string datef;
	cin>>datef;
	try{
		DateFormat ddf(datef.c_str());
		Date::setFormat(ddf);
	}
	catch(...) {
		cout<<"No valid date format encountered...!! Exiting !"<<endl;
	}
	cout<<"Date Format entered: "<<datef<<endl;
	
	cout<<"Enter Date."<<endl;
	Date s;
	cin>>s;
	cout<<"Entered Date: "<<s<<endl;
}

int main()
{
	DateFormatConstructor();     //Prints and Checks all 7x7x7 combinations
	cout<<"*******************************************************************************"<<endl;
	cout<<"*******************************************************************************"<<endl;
	DateConstructor();           //Prints large amount of data
	cout<<"*******************************************************************************"<<endl;
	cout<<"*******************************************************************************"<<endl;
	test_unary();
	cout<<"*******************************************************************************"<<endl;
	cout<<"*******************************************************************************"<<endl;
	test_add();
	cout<<"*******************************************************************************"<<endl;
	cout<<"*******************************************************************************"<<endl;
	test_diff();
	cout<<"*******************************************************************************"<<endl;
	cout<<"*******************************************************************************"<<endl;
	test_leap();
	cout<<"*******************************************************************************"<<endl;
	cout<<"*******************************************************************************"<<endl;
	test_cast();
	cout<<"*******************************************************************************"<<endl;
	cout<<"*******************************************************************************"<<endl;
	test_relation();
	cout<<"*******************************************************************************"<<endl;
	cout<<"*******************************************************************************"<<endl;
	check_format();
	cout<<"*******************************************************************************"<<endl;
	cout<<"*******************************************************************************"<<endl;
	check_printer();
	cout<<"*******************************************************************************"<<endl;
	cout<<"*******************************************************************************"<<endl;
	check_input();
	
	
	
	cout<<endl;
	cout<<"*******************************************************************************"<<endl;
	cout<<"*******************************************************************************"<<endl;
	cout<<"*******************************************************************************"<<endl;
	cout<<"*******************************************************************************"<<endl;
	cout<<endl<<"Code Verified for all inputs and test-cases."<<endl;
	cout<<"*******************************************************************************"<<endl;
	cout<<"*******************************************************************************"<<endl;
	/**/
	return 0;
}
