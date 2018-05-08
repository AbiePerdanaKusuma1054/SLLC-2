//Patar Martua Doli Siahaan
//Universitas Lampung - Ilmu Komputer - 1717051051
//Array menggunakan Head SLLC


#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
	};

int panjang;	//untuk membuat indeks array
Node *head = NULL; //mendefenisikan bahwa data awal masih kosong


//iDepan = Input data di Depan
void iDepan(int databaru){
	Node *baru,*bantu;
	baru = new Node;
	baru->data = databaru;
	//baru->next = baru;
	if(head == NULL){
		head = baru;
		head->next = head;
		}
	
	else{
		bantu = head;
		for(int i=0;i<panjang;i++){
			if(bantu->next == head){
				baru->next = head;
				head = baru;	
				bantu->next = head;
				break;}
				bantu = bantu->next;
			}
		}
	panjang++;
	}
	
	
//iBelakang = Input data di Belakang
void iBelakang(int databaru){
	Node *baru,*bantu;
	baru = new Node;
	baru->data = databaru;
	//baru->next = baru;
	
	if(head == NULL){
		head = baru;
		head->next = head;
		}
		
	else{
		bantu = head;
		for(int i=0;i<panjang;i++){
			
			if(bantu->next == head){
				bantu->next = baru;
				baru->next = head;
				break;
				}
			bantu = bantu->next;
			}
		}
	panjang++;
	}


//hDepan = Hapus data di Depan	
void hDepan(){
	Node *bantu;
	bantu = head;
	if(panjang == 0){
		cout<<"Data Kosong\n";
		}
	else if(panjang == 1){
		head = NULL;
		}
	else {
		for(int i=0;i<panjang;i++){
			if(bantu->next == head){
				head = head->next;
				bantu->next = head;
				break;
				}
			bantu = bantu->next;
			}
		}
	panjang--;
	}
	
	
//hBelakang = Hapus data di belakang	
void hBelakang(){
	Node *bantu;
	bantu = head;
	if(panjang == 0){
		cout<<"Data Kosong\n";
		}
	else if(panjang == 1){
		head = NULL;
		}	
	else{
		for(int i=0;i<panjang;i++){
			if(bantu->next->next == head){
				bantu->next = head;
				break;
				}
			bantu = bantu->next;
			}
		
		}
	panjang--;
	}


//iSetelah = Input nilai P, setelah data ke-N
void iSetelah(int databaru,int pos){
	if (pos >= panjang){
		cout<<"Maaf Posisi Belum Ada\n";
		}
	else {
	Node *bantu,*baru;
	baru = new Node;
	baru->data = databaru;
	//baru->next = baru;
	bantu = head;
	for(int i=0;i<pos;i++){
		bantu = bantu->next;
		}
	baru->next = bantu->next;	
	bantu->next = baru;
	panjang++;
	}
	
}


//iSebelum = Input nilai P, sebelum data ke-N
void iSebelum(int databaru,int pos){
	if (pos >= panjang){
		cout<<"Maaf Posisi Belum Ada\n";
		}
	else if(pos == 0){
		iDepan(databaru);
		}
	else {
	Node *bantu,*baru;
	baru = new Node;
	baru->data = databaru;
	//baru->next = baru;
	bantu = head;
	for(int i=0;i<pos-1;i++){
		bantu = bantu->next;
		}
	baru->next = bantu->next;	
	bantu->next = baru;
	panjang++;
	}
	
}


//cData = Cetak semua data (cetak semua isi array)
void cData(){
	if (panjang == 0){
		cout<<"Data Kosong\n";
		}
	Node *bantu;
	bantu = head;
	for(int i=0;i<panjang;i++){
		cout<<bantu->data<<" ";
		bantu = bantu->next;
		}
	cout<<endl;
	}
	

//cDatake = Cetak data ke-N
void cDatake(int datake){
	if (panjang == 0){
		cout<<"Data Kosong\n";
		}
	else if(datake >= panjang){
		cout<<"Maaf, data yang anda minta melebihi indeks\n";}	
	else {
		Node *bantu;
		bantu = head;
		for(int i=0;i<=datake;i++){
			if (i == datake){
			cout<<bantu->data;}
			bantu = bantu->next;
			}
		}
	}
	
	
//hDatake = Hapus data ke-N	
void hDatake(int datake){
	if (panjang == 0){
		cout<<"Data Kosong\n";
		}
	else if(datake >= panjang){
		cout<<"Maaf, Banyak data hanya "<<panjang<<" \n";
		}
	else if(datake == 0){
		hDepan();
		}
	else{
		Node *bantu;
		bantu = head;
		for(int i=0;i<datake-1;i++){
			bantu = bantu->next;
			}
		bantu->next = bantu->next->next;
		panjang--;
		
		}
		
	}




int main(){
	iDepan(1);
	cData();
	iBelakang(2);
	cData();
	iSetelah(3,1); // Array dimulai dari 0, jadi artinya 3,1 adalah input angka 3, setelah array[1]
	cData();
	iSebelum(4,0); // Array dimulai dari 0, jadi artinya 4,0 adalah input angka 4, sebelum array[0]
	cData();
	hBelakang();
	cData();
	hDepan();
	cData();
	hDatake(1);
	cData();
	cout<<endl;
	iDepan(1);
	iDepan(2);
	iBelakang(3);
	//Cara cetak seluruh data dengan looping, caranya sama seperti looping array
	for(int i=0;i<panjang;i++){
		cDatake(i);
		cout<<endl;
		}
	}
