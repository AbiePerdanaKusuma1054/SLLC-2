#include <iostream>
using namespace std;

class TNode
{
  public:
    int data;
    TNode *next;
};

TNode *head;
TNode *tail;
TNode *del;

void init()
{
    head = NULL;
    tail = NULL;
}

int isEmpty ()
{
	if (tail==NULL){
	return true;
	}
	else{
	return false;
	}
}

void tambahDepan(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = baru;

    if (isEmpty() == 1)
    {
        head = baru;
        tail = baru;
        head->next = head;
        tail->next = tail;
    }
    else
    {
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

void tambahBelakang(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = baru;

    if (isEmpty() == 1)
    {
        head = baru;
        tail = baru;
        head->next = head;
        tail->next = tail;
    }
    else
    {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
}

void cetak(){
    
        TNode *bantu;
        bantu = head;
    if (isEmpty() == 0){
		
        do{
            cout<<bantu->data<<" ==> ";
            bantu=bantu->next;
        }while (bantu!=tail->next);
    } else {
        cout<<"List Kosong";
    }
}



void hapusDepan(){
	TNode *hapus;
	if (isEmpty()==0){
		int d;
		hapus = head;
		d = head->data;
		if(head != tail){
			hapus = head;
			head = head->next;
			tail->next = head;
			delete hapus;
		}else{
			head=NULL;
			tail=NULL;
		}
		cout<<"terhapus "<<d<<endl;
	} else cout<<"Masih kosong\n";
}

void hapusBelakang(){
	TNode *hapus,*bantu;
	if (isEmpty()==0){
		int d;
		if(head == tail){
			d = tail->data;
			head = NULL;
			tail = NULL;
		}else{
			bantu = head;
			while(bantu->next != tail){
				bantu = bantu->next;
			}
			hapus = tail;
			tail = bantu;
			d = hapus->data;
			tail->next = head;
			delete hapus;
		}
		cout<<"terhapus "<<d<<endl;
	} else cout<<"Masih kosong\n";
}

void insertNode(int databaru, int datasebelum){
	
	   TNode *bantu;
        bantu = head;
    if (isEmpty() == 0){
        do{
            if(bantu->data == datasebelum){
			TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = baru;

    if (isEmpty() == 1)
    {
        head = baru;
        tail = baru;
        head->next = head;
        tail->next = tail;
    }
    else
    {
        baru->next = head;
        head = baru;
        tail->next = head;
    }
			
			
			}
            bantu=bantu->next;
        }while (bantu!=tail->next);
    } else {
        cout<<"List Kosong";
    }
	
	
	}


/*void hapusNode(int datahapus){
    
         TNode *bantu;
        bantu = head;
    if (isEmpty() == 0){
		
        do{
            if(bantu->data == datahapus){
				 
				}
            bantu=bantu->next;
        }while (bantu!=tail->next);
    } else {
        cout<<"List Kosong";
    }
}
*/

/*void hapusNode(int datahapus){
	TNode *bantu,*hapus;
	if(isEmpty() == 0){
		bantu = head;
		do{
			if(bantu->data == datahapus){
			hapus = bantu;
			bantu = bantu->next;
			delete hapus;
			}
			
			}
		while(bantu!=tail->next);
	}
}
*/


/*void hapusNode(int datahapus){
	TNode *hapus,*bantu,*deldat;
	if (isEmpty()==0){
		int d;
		deldat = new TNode;
		deldat->data = deldat;
		if(head == tail){
			d = tail->data;
			head = NULL;
			tail = NULL;
		}else{
			bantu = head;
			while(bantu->next != deldat->data){
				bantu = bantu->next;
			}
			hapus = deldat->data;
			deldat->data = bantu;
			d = hapus->data;
			deldat->data->next = head;
			delete hapus;
		}
		cout<<"terhapus "<<d<<endl;
	} else cout<<"Masih kosong\n";
}*/


int main()
{
    init();
    tambahBelakang(9);
    tambahBelakang(3);
    tambahDepan(5);
    tambahDepan(6);
    tambahBelakang(11);
    cetak();
    hapusDepan();
    hapusBelakang();
    cetak();
    cout<<endl;
    insertNode(3,5);
    cetak();
    cout<<endl;
    cout<<endl;
    hapusNode(9);
    cout<<endl;
    cetak();
    
    return 0;
}

