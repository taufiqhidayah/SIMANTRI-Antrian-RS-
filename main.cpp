#include <iostream>
#include <string>
#include <windows.h>
#include <mysql.h>

using namespace std;

int main(){
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    int qstate;

    conn = mysql_init(0);
   // if(conn)
      //  cout<<"connection object ok, conn="<<conn<<endl;
    //else
        //cout<<"conn object problem: "<<mysql_error(conn);

    conn = mysql_real_connect(conn,"localhost","root","","simantri",0,NULL,0);

    if(conn){


        cout<<"connected to database simantri"<<endl;

        string id,name,jk;
        cout<<"enter id: "<<endl; cin>>id;
        cout<<"enter name: "<<endl; cin>>name;
        cout<<"enter jk: "<<endl; cin>>jk;


        string query="insert into pasien(id,name,jk) values('"+id+"','"+name+"','"+jk+"')";


        const char* q = query.c_str();

        cout<<"query is: "<<q<<endl;
        qstate = mysql_query(conn,q);

        if(!qstate)
            cout<<"record inserted successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;

        qstate = mysql_query(conn,"select * from pasien");

        if(!qstate){
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res)){
                cout<<"id: "<<row[0]<< " "
                    <<"name: "<<row[1]<< " "
                    <<"jk: "<<row[2]<<endl;
            }
        }else{
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
    }
    else{
        cout<<"connection problem: "<<mysql_error(conn)<<endl;
    }

    mysql_close(conn);

    return 0;
}
