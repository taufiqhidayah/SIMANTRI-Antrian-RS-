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
