#include<iostream>
#include<mysql.h>
#include<mysqld_error.h>
#include<windows.h>

using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PW = "S0i8v0a4";
const char* DB = "mydb";

int main()
{
	MYSQL* conn;
	conn = mysql_init(NULL);
	
	if(!mysql_real_connect(conn,HOST,USER,PW,DB,3306,NULL,0)){
		cout<<endl<<endl;
		cout<<"\t\tERROR : "<<mysql_error(conn)<<endl;
	}
	else{
		cout<<endl;
		cout<<"\t\tDATABASE CONNECTED !"<<endl;
	}
	Sleep(3000);
	
	bool exit = false;
	
	while(!false){
		system("cls");
		int op;
		cout<<endl<<endl;
		cout<<"\t\t*** MYSQL DATABASE ***"<<endl;
		cout<<"\t\t1.INSERT INTO DATABASE"<<endl;
		cout<<"\t\t2.DELETE FROM DATABASE"<<endl;
		cout<<"\t\t3.READ FROM DATABASE"<<endl;
		cout<<"\t\t4.EXIT"<<endl;
		cout<<"\t\tENTER YOUR OPTION :";
		cin>>op;
		
		switch(op){
			case 1:{
				std::string name, roll,cgpa;
	
	cout<<"\t\tENTER YOUR NAME :";
	cin>>name;
	
	cout<<"\t\tENTER YOUR ROLL NO:";
	cin>>roll;
	
	cout<<"\t\tENTER YOUR CGPA:";
	cin>>cgpa;
	
	string qry = "INSERT INTO STUDENT(roll,name,CGPA) VALUES ('"+roll+"','"+name+"','"+cgpa+"')";
	
	if(mysql_query(conn,qry.c_str())){
		cout<<endl<<endl;
		cout<<"\t\tERROR : "<<mysql_error(conn)<<endl;
	}
	
	else{
		cout<<endl<<endl;
		cout<<"\t\tDATA INSERTED SUCCESSFULLY"<<endl;
	}
	Sleep(3000);
	mysql_close(conn);
	
				break;
			}
			
			case 2:{
				std::string id;
				cout<<endl;
				cout<<"\t\tENTER ROLL TO DELETE :";
				cin>>id;
				
				string qry = "DELETE FROM student WHERE roll = '"+id+"'";
				
				if(mysql_query(conn,qry.c_str())){
					cout<<endl<<endl;
					cout<<"\t\tERROR : "<<mysql_error(conn)<<endl;
				}
				
				else{
					cout<<endl;
					cout<<"\t\tSUCCESSFULLY DELETED"<<endl;
				}
				Sleep(3000);
				mysql_close(conn);
				break;
			}
				
				case 3:{
					string id;
					cout<<endl<<endl;
					cout<<"\t\tENTER ROLL TO SEE DETAILS:";
					cin>>id;
					
					string qry = "SELECT * FROM student WHERE roll = '"+id+"'";
					
					if(mysql_query(conn,qry.c_str())){
						cout<<endl<<endl;
						cout<<"\t\tERROR : "<<mysql_error(conn)<<endl;
					}
					
					else{
						MYSQL_RES* res = mysql_store_res(conn);
						MYSQL_ROW row;
						row = mysql_fetch_row(res);
						cout<<"\t\t"<<row[0];
					}
					Sleep(5000);
					break;
				}
			
		}
	}
	
	return 0;
}
