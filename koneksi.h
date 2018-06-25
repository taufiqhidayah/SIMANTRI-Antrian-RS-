#include <iostream>
#include <string>
#include <windows.h>
#include <mysql.h>
#include <stdio.h>
using namespace std;

class Konek{
	public:
    MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES *res;
	int qstate;

	    Konek(){
	    conn = mysql_init(0);
        conn = mysql_real_connect(conn,"localhost","root","","simantri",0,NULL,0);
	    }

};
