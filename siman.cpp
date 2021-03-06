#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <mysql.h>
#include <stdio.h>
#include <algorithm>
#include "indux.h"
#include "pasien.h"
#include "admin.h"
#include "koneksi.h"

using namespace std;
bool status= TRUE;

int menuPil;
Konek konek;
Pasien pasien;
Registrasi registasi;
PesanRegis pesanshow;

bool isLogin(int x);

void menuUtama(int i);
//OverloadingExample
void lihatData(int x);
void lihatData(int x,string y);

void inputPasien();
void deletePasien();

void getKoneksi(){
	MYSQL* conn;
	MYSQL_ROW row;
	int qstate;
    int getData;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn,"localhost","root","","simantri",0,NULL,0);
	if(conn){
		status = TRUE;
	}
	else{
		status = FALSE;
		cout<<"connection problem: "<<mysql_error(conn)<<endl;
	}
	mysql_close(conn);
}
int main()
{
    system("cls");
    getKoneksi();
	//MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES *res;
	int qstate;

	if(status==TRUE){

		int pilihan;
		//string user,pass;
		cout<<"CONNECTED TO DATABASE SIMANTRI"<<endl;
		cout<<"=============================="<<endl;
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
            //String
			qstate = mysql_query(konek.conn,query.c_str());
			res = mysql_store_result(konek.conn);
			if(mysql_num_rows(res)>0){
                //generic programming find
				if(user.find("admin")){
					menuPil =2;
					menuUtama(2);
				}else{
                    menuPil =1;
					menuUtama(1);
				}
			}else{
				cout<<"gagal";
                system("pause");
                main();
			}
		} else{
			string usname,name,jk,id, pass;
			cout<<"Registrasi Pengguna\n";
			cout<<"Username\n";
			cin>>usname;
			cout<< "Nama";
			cin>> name;
			cout<< "Jenis Kelamin \n";
			cin>> jk;
			cout<< "Password \n";
			cin >> pass;

            registasi.setUsName(usname);
			registasi.setPassword(pass);
			registasi.setJk(jk);
			registasi.setNama(name);
			string qrya="insert into admin(user, pass,nama, jk) values('"+registasi.getUsName()+"','"+registasi.getPassword()+"','"+registasi.getNama()+"','"+registasi.getJk()+"')";
            //STRING CLASS
			const char* q = qrya.c_str();

			cout<<"query is: "<<q<<endl;
			qstate = mysql_query(konek.conn,q);
            cout<<  pesanshow.pesan();
			if(!qstate)
			pesanshow.pesan();
			else
			cout<<"query problem: "<<mysql_error(konek.conn)<<endl;
            system("pause");
            main();
		}
	}
	else if (status== FALSE){
		cout<<"connection problem: "<<mysql_error(konek.conn)<<endl;
	}


	return 0;
}

void menuUtama(int i){
	if(i==1){
        system("cls");
		int pil;
		isLogin(1);
		cout<<"Selamat Datang Admin di RS MANTRI\n";
		cout<<"===========================\n";
		cout << "1. Lihat Data Pendaftaran Pasie\n";
		cout << "2. Pendaftaran Pasien \n";
		cout << "3. Antrian Pasien \n";
		cout << "4. Logout \n";

		cout << " Masukan Pilihan ";
		cin>> pil;
		switch(pil){
			case 1:
			lihatData(1);
			break;
			case 2 :
			inputPasien();
			break;
			case 3 :
			deletePasien();
			break;
			case 4:
                system("pause");
                main();
		}
	}else{
	    int pilihan;
		isLogin(1);
        system("cls");
		cout<<"Selamat Datang Pasien di RS MANTRI\n";
		cout<<"===========================\n";
        lihatData(1,"pasien");

	}
}
bool isLogin(int x){
	if(x!=1){
		status= FALSE;
	}
	return status;
}
int isLogin(bool x, int y){
    x= status;
    if(y ==1){
        cout<< "LOGIN";
    }else{
        cout<< "Logout";
    }
}

void lihatData(int x){
    system("cls");
	MYSQL_ROW row;
	MYSQL_RES *res;
	int qstate;
	if(status==TRUE){
		qstate = mysql_query(konek.conn,"select * from pasien");
        cout<< "DATA PASIEN\n";
        cout << "===========================\n";
		if(!qstate){
			res = mysql_store_result(konek.conn);
			while(row=mysql_fetch_row(res)){
				cout<<"ID: \t\t"<<row[0]<< " "
				<<"Name: \t\t"<<row[1]<< " "
				<<"Gender: "<<row[2]<<endl;
			}
			system("pause");
            menuUtama(menuPil);
		}else{
			cout<<"query error: "<<mysql_error(konek.conn)<<endl;
		}

	}
	else{
		cout<<"connection problem: "<<mysql_error(konek.conn)<<endl;
	}
	mysql_close(konek.conn);
}

void lihatData(int x , string y){
    system("cls");
	MYSQL_ROW row;
	MYSQL_RES *res;
	int qstate;
	if(status==TRUE){
		qstate = mysql_query(konek.conn,"select * from pasien");
        cout<< "DATA PASIEN\n";
        cout << "===========================\n";
		if(!qstate){
			res = mysql_store_result(konek.conn);
			while(row=mysql_fetch_row(res)){
				cout<<"ID: \t\t"<<row[0]<< " "
				<<"Name: \t\t"<<row[1]<< " "
				<<"Gender: "<<row[2]<<endl;
			}
			cout<< "1. Logout";
            int pil;
            cin>> pil;
            if (pil ==1 ){
                system("pause");
                main();
            }
		}else{
			cout<<"query error: "<<mysql_error(konek.conn)<<endl;
		}

	}
	else{
		cout<<"connection problem: "<<mysql_error(konek.conn)<<endl;
	}
	mysql_close(konek.conn);
}
void inputPasien(){
    system("cls");
    MYSQL_ROW row;
	MYSQL_RES *res;
	int qstate;
	string thn;
    string name,jk,id;
        cout<<"Registrasi Pasiesn\n";
        cout<<"Nama\n";
        cin>>name;
        cout<< "Jenis Kelamin";
        cin>> jk;
        cout<< "Tahun Lahir";
        cin >> thn;


        Registrasi * sm = &pasien;

        pasien.setUmur(thn);
        pasien.setNama(name);
        pasien.setJk(jk);

        string qrya="insert into pasien(id,name,jk,thn) values('"+id+"','"+pasien.getNama()+"','"+pasien.getJk()+"','"+pasien.getUmur()+"')";

        const char* q = qrya.c_str();

        cout<<"query is: "<<q<<endl;
        qstate = mysql_query(konek.conn,q);
        if(!qstate)
        cout<<"record inserted successfully..."<<endl;
        else
        cout<<"query problem: "<<mysql_error(konek.conn)<<endl;
        system("pause");
        menuUtama(menuPil);
}
void deletePasien(){
    system("cls");
    int qstate;
    MYSQL_ROW row;
	MYSQL_RES *res;
    string query = "DELETE from pasien LIMIT 1";
    qstate = mysql_query(konek.conn,query.c_str());
    res = mysql_store_result(konek.conn);
    system("pause");
    lihatData(1);
}
