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
    //Polymorphysm
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
       string umur;
    public:
    //Polymorphysm
    void setNama(string nama){
        this->nama = nama;
    }
    void setUmur(int umur){
        this-> umur = umur;
    }
    void setUmur(string umur){
        this-> umur = umur;
    }

    string getUmur(){
        return umur;

    }

};
