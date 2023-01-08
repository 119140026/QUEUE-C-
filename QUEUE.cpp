#include <iostream>
#include <conio.h> 
#include <stdlib.h> 
#define MAX 10

using namespace std;

int nomer[MAX];
int head=-1;
int tail=-1;
				
bool IsEmpty(){ 
   if(tail == -1){
       return true;
   }else{
       return false;
   }
}             
bool IsFull(){ 
   if(tail == MAX-1){
       return true;
   }else{
       return false;
   }
}

void AntrianMasuk(int no){
    if (IsEmpty()){
        head=tail=0;
    }else {
        tail++;
    }
    nomer[tail]=no;
}

void AntrianKeluar(){
    if(IsEmpty()){
        cout<<"Antrian sudah kosong ! ";
        getch();
    }else {
        for(int a=head;a<tail;a++){
            nomer[a]=nomer[a+1];
        }
        tail--;
        if(tail == -1){
            head = -1;
        }
    }
}

void Clear(){
     head=tail=-1;
}

void View(){
     if(IsEmpty()){
         cout<<"Antrian kosong ! ";

     }else {
         cout << "== No. Antrian yang telah dilayani ==\n\n";
         cout << "== No. Antrian yang Belum dilayani ==\n";
         for(int a=head;a<=tail;a++){
              cout << "----------------------------------"
                   << "\nNo. Antrian : [" << nomer[a] <<"]"
                   << "\n----------------------------------"<< endl;
         }
     }
}

int main(){ 
	int choose, p=1, urut;
	do{
        system("cls");                  
        cout << "\n===== PROGRAM ANTRIAN ====="
             << "\n==============================="
             << "\n|1. Tambahkan Antrian         |"
             << "\n|2. Panggilkan Antrian        |"
             << "\n|3. Lihat semua daftar        |"
             << "\n|4. Hapus Semua daftar        |"
             << "\n|5. Exit                      |"
             << "\n=============================== \n";
        cout << "\nPilih : "; cin >> choose;
        cout << "\n";
        if(choose == 1){
            if(IsFull()) {
                cout<<"Antrian sudah penuh, mohon tunggu beberapa saat lagi ";
            }
            else{
                urut=p;
                AntrianMasuk(urut);
                cout << "No. Antrian		: " << p << endl;
                cout << "Antrian yang menunggu 	: " << tail;
                p++;
            }
        }
        else if(choose == 2){
            cout << "No. Antrian : "<<nomer[head] << endl;
            AntrianKeluar();
            cout << "Silahkan! Anda Dipanggil !" << endl;
        }
        else if(choose == 3){
            View();
        }
        else if(choose == 4){
            Clear();
            cout<<"Antrian dikosongkan ! ";
        }
        else if(choose == 5){
        }
        else{
            cout << "Masukan anda salah ! \n"<< endl;
        }
        getch();
    }while(choose!=5);
}
