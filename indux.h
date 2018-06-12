#include <iostream>
#include <string>
#include <windows.h>
#include <mysql.h>
#include <stdio.h>
using namespace std;
class Registrasi{
private:
    int id;
    string password,nama,jk;
public:
    void setNama(string nama){
        this->nama = nama;
    }
    string getNama(){
        return nama;
    }
    void setPassword(string pass){
        this-> password= pass;
    }
    string getPassword(){
        return password;
    }

    void setJk(string jk){
        this-> jk = jk;
    }
    string getJk(){
        return jk;
    }

};
class Simantri{
	private:
		int id;
		string nama,poli;
	public:

		void setNama(string nama){
			this->nama = nama;
		}
		void setPoli(string poli){
			this->poli = poli;
		}
		string getNama(){
			return nama;
		}
		string getPoli(){
			return poli;
		}
};
