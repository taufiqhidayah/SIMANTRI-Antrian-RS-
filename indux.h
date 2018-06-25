#include <iostream>
#include <string>
#include <windows.h>
#include <mysql.h>
#include <stdio.h>
using namespace std;
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
//Overriding example
class Pesan {
    public:
    string pesan(){
        return "Sukses Menyimpan";
    }
};
class PesanRegis : public Pesan{
    public:
    string pesan(){
        return "Registrasi Sukses";
    }
};
