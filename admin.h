#include <iostream>
#include <string>
#include <windows.h>
#include <mysql.h>
#include <stdio.h>
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
