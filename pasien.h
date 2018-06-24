#include <iostream>
#include <string>
#include <windows.h>
#include <mysql.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
class Registrasi{
protected:
    int id;
    string password,nama,jk,usname;
public:
  virtual void setNama(string nama){
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
    void setUsName(string usname){
        this->usname = usname;
    }
    string getUsName(){
        return usname;
    }
};
class Pasien : public Registrasi{
   private:
       string nama;
       string umur;
    public:
    void setUmur(int umur){
        this-> umur = umur;
    }
  std::string::size_type sz;   // alias of size_t
    string getUmur(){

    }
    int countUmur(int getUmur()){
        return 2016 - getUmur();
    }
};
