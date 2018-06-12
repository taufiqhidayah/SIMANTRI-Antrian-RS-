#include <iostream>
#include <string>
#include <windows.h>
#include <mysql.h>
#include <stdio.h>
#include "indux.h"

using namespace std;

class Admin : public Simantri{
	private:
	int stat;
	public:
	void setStatus(int stat){
		this->stat =stat;
	}
	int getStatus(){
		return stat;
	}
};
bool isLogin(int x){
    bool status= TRUE;
    if(x!=1){
        status= FALSE;
    }
    return status;
}
void menuUtama(int i);
void menuUtama(int i){
    if(i==1){
        isLogin(1);
        cout<<"Selamat Datang Admin di RS MANTRI\n";
        cout<<"===========================\n";
        cout<<"1.Lihat Data Pendaftaran Pasie\n";
    }else{
        isLogin(1);
        cout<<"Selamat Datang Pasien di RS MANTRI\n";
        cout<<"===========================\n";
        cout<<"1.Lihat Data Pendaftaran Pasie\n";
    }
}
Registrasi registasi;
int main()
{
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

        int pilihan;
        //string user,pass;
        cout<<"connected to database simantri"<<endl;
        cout<< "1 Login\n";
        cout<< "2 Registrasi";
        cin>>pilihan;
        if(pilihan ==1){

        cout<<"Login....\n";
        string user, password;
        cout<<"Username\n";
        cin>>user;
        cout<<"Password";
        cin>>password;
        string query = "SELECT * FROM admin WHERE user=\'" + user + "\' && pass=\'" + password + "\'";

        qstate = mysql_query(conn,query.c_str());
        res = mysql_store_result(conn);
        if(mysql_num_rows(res)>0){
            if(user.find("admin")){
                menuUtama(2);
            }else{
                menuUtama(1);
            }
        }else{
            cout<<"gagal";
        }
        } else{
            string name,jk,id;
            cout<<"Registrasi Pasiesn\n";
            cout<<"Nama\n";
            cin>>name;
            cout<< "Jenis Kelamin";
            cin>> jk;
            registasi.setJk(jk);
            registasi.setNama(name);
            string qrya="insert into pasien(id,name,jk) values('"+id+"','"+registasi.getNama()+"','"+registasi.getJk()+"')";

        const char* q = qrya.c_str();

        cout<<"query is: "<<q<<endl;
        qstate = mysql_query(conn,q);

        if(!qstate)
            cout<<"record inserted successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;

        }
    }
    else{
        cout<<"connection problem: "<<mysql_error(conn)<<endl;
    }

    mysql_close(conn);

    return 0;
}
