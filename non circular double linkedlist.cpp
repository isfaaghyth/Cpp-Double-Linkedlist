#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
	int data;
	node *next;
	node *prev;
} *databaru, *head, *tail, *temp;

void HeadMe(string str) {
	cout<<"------------------------"<<endl;
	cout<<str<<endl;
	cout<<"------------------------"<<endl;
}

int counter = 0;
//penambahan
void TambahNode(int data);
void TambahDepan(int data);
void TambahBelakang(int data);
void TambahTengahSesudah(int key, int data);
void TambahTengahSebelum(int key, int data);
//penghapusan
void HapusDepan();
void HapusBelakang();
void HapusTengah(int key, string status);
//modifikasi
void EditTengah(int key, int databaru, string status);
void TampilkanData();
int CariData(int data);
int numberOfNode();

int main() {
	int menu, inputan, key;
	do {
		home:
		system("cls");
		HeadMe("Double Linkedlist");
		cout<<" 1. Tambah Depan"<<endl;
		cout<<" 2. Tambah Belakang"<<endl;
		cout<<" 3. Tambah Tengah Sesudah"<<endl;
		cout<<" 4. Tambah Tengah Sebelum"<<endl;
		cout<<" 5. Hapus Depan"<<endl;
		cout<<" 6. Hapus Belakang"<<endl;
		cout<<" 7. Hapus Tengah Sesudah"<<endl;
		cout<<" 8. Hapus Tengah Sebelum"<<endl;
		cout<<" 9. Modifikasi Depan"<<endl;
		cout<<"10. Modifikasi Belakang"<<endl;
		cout<<"11. Modifikasi Tengah Sesudah"<<endl;
		cout<<"12. Modifikasi Tengah Sebelum"<<endl;
		cout<<"13. Tampilkan Data"<<endl;
		cout<<"14. Cari Data"<<endl;
		cout<<"15. Jumlah data"<<endl;
		cout<<"16. Exit"<<endl;
		cout<<endl<<endl;
		cout<<"Pilih menu : ";
		cin>>menu;
		
		switch (menu) {
			case 1: {
				system("cls");
				HeadMe("Tambah Data Depan");
				cout<<"Masukkan data : ";
				cin>>inputan;
				TambahDepan(inputan);
				cout<<endl<<endl;
				system("pause");
				goto home;
				break;	
			}		
			case 2: {
				system("cls");
				HeadMe("Tambah Data Belakang");
				cout<<"Masukkan data : ";
				cin>>inputan;
				TambahBelakang(inputan);
				cout<<endl<<endl;
				system("pause");
				goto home;
				break;	
			}	
			case 3: {
				system("cls");
				HeadMe("Tambah Data Tengah Sesudah");
				cout<<"Masukkan data Setelah : "; cin>>key;
				cout<<"Masukkan data baru : "; cin>>inputan;
				TambahTengahSesudah(key, inputan);				
				cout<<endl<<endl;
				system("pause");
				goto home;
				break;	
			}	
			case 4: {
				system("cls");
				HeadMe("Tambah Data Sebelum");
				cout<<"Masukkan data Sebelum : "; cin>>key;
				cout<<"Masukkan data baru : "; cin>>inputan;
				TambahTengahSebelum(key, inputan);				
				cout<<endl<<endl;
				system("pause");
				goto home;
				break;	
			}
			case 5: {
				system("cls");
				HeadMe("Hapus Data Depan");
				cout<<"Data "<<head->data<<" sudah dihapus"<<endl;
				HapusDepan();
				cout<<endl<<endl;
				system("pause");
				goto home;
				break;
			}
			case 6: {
				system("cls");
				HeadMe("Hapus Data Belakang");
				cout<<"Data "<<tail->data<<" sudah dihapus"<<endl;
				HapusBelakang();
				cout<<endl<<endl;
				system("pause");
				goto home;
				break;
			}
			case 7: {
				system("cls");
				HeadMe("Hapus Data Tengah Sesudah");
				cout<<"Masukkan data setelah : ";
				cin>>key;
				HapusTengah(key, "sesudah");
				cout<<endl<<endl;
				system("pause");
				goto home;
				break;
			}
			case 8: {
				system("cls");
				HeadMe("Hapus Data Tengah Sebelum");
				cout<<"Masukkan data sebelum : ";
				cin>>key;
				HapusTengah(key, "sebelum");
				cout<<endl<<endl;
				system("pause");
				goto home;
				break;
			}
			case 9: {
				system("cls");
				HeadMe("Modifikasi Depan");
				cout<<"Masukkan data baru : ";
				cin>>key;
				head->data = key;
				cout<<"Data berhasil diperbaharui";
				cout<<endl<<endl;
				system("pause");
				goto home;
				break;
			}
			case 10: {
				system("cls");
				HeadMe("Modifikasi Belakang");
				cout<<"Masukkan data baru : ";
				cin>>key;
				tail->data = key;
				cout<<"Data berhasil diperbaharui";
				cout<<endl<<endl;
				system("pause");
				goto home;
				break;
			}
			case 11: {
				system("cls");
				HeadMe("Modifikasi Data Sesudah");
				cout<<"Masukkan data Sesudah : "; cin>>key;
				cout<<"Masukkan data baru : "; cin>>inputan;
				EditTengah(key, inputan, "sesudah");				
				cout<<endl<<endl;
				system("pause");
				goto home;
				break;
			}
			case 12: {
				system("cls");
				HeadMe("Modifikasi Data Sebelum");
				cout<<"Masukkan data Sebelum : "; cin>>key;
				cout<<"Masukkan data baru : "; cin>>inputan;
				EditTengah(key, inputan, "sebelum");				
				cout<<endl<<endl;
				system("pause");
				goto home;
				break;
			}
			case 13: {
				system("cls");
				HeadMe("Tampilkan Data");
				TampilkanData();			
				cout<<endl<<endl;
				system("pause");
				goto home;
				break;	
			}			
			case 14: {
				system("cls");
				HeadMe("Cari Data");
				cout<<"Masukkan data : ";
				cin>>inputan;
				cout<<CariData(inputan);
				cout<<endl<<endl;
				system("pause");
				goto home;
				break;	
			}
			case 15: {
				system("cls");
				HeadMe("Jumlah Node");
				cout<<numberOfNode();
				cout<<endl<<endl;
				system("pause");
				goto home;
				break;
			}
		}
	} while (menu != 16);
}

void TambahNode(int data) {
	databaru = new node;
	databaru->data = data;
	databaru->next = NULL;
	databaru->prev = NULL;
}

int numberOfNode() {
	return counter;
}

int CariData(int data) {
	int posisi = 0;
	temp = head;
	while (temp != NULL) {
		if (temp->data == data) {
			posisi++;
			break;
		}
		temp = temp->next;
		posisi++;
	}
	return posisi;
}

void TambahDepan(int data) {
	TambahNode(data);
	if (head == NULL) {
		head = databaru;
		tail = databaru;
	} else {
		databaru->next = head;
		head->prev = databaru;
		head = databaru;
	}
	counter++;
}

void TambahBelakang(int data) {
	TambahNode(data);
	if (head == NULL) {
		head = databaru;
		tail = databaru;
	} else {
		databaru->prev = tail;
		tail->next = databaru;
		tail = databaru;
	}
	counter++;	
}

void TambahTengahSebelum(int key, int data) {
	node *temp2;
	temp2 = NULL;
	if (CariData(key) != 0) {
		TambahNode(data);
		databaru->next = temp;
		temp2 = temp->prev;
		databaru->prev = temp2;
		temp2->next = databaru;
		temp->prev = databaru;
		counter++;
		cout<<"Penambahan Data Berhasil";
	} else {
		cout<<"Maaf, data tidak ditemukan";
	}
}

void TambahTengahSesudah(int key, int data) {
	node *temp2;
	temp2 = NULL;
	if (CariData(key) != 0) {
		TambahNode(data);
		databaru->prev = temp;
		temp2 = temp->next;
		databaru->next = temp2;
		temp2->prev = databaru;
		temp->next = databaru;
		counter++;
		cout<<"Penambahan Data Berhasil";
	} else {
		cout<<"Maaf, data tidak ditemukan";
	}	
}

void HapusDepan() {
	node *temp2;
	if (head != NULL) {
		temp2 = head;
		if (numberOfNode() == 1) {
			head = NULL;
			tail = NULL;	
			delete temp2;
			counter--;
		} else {
			head = temp2->next;
			head->prev = NULL;	
			delete temp2;
			counter--;
		}
	} else {
		cout<<"Maaf, data tidak ditemukan"<<endl;
	}
}

void HapusBelakang() {
	node *temp2;
	if (head != NULL) {
		temp2 = tail;
		if (numberOfNode() == 1) {
			head = NULL;
			tail = NULL;	
			delete temp2;
			counter--;
		} else {
			tail = temp2->prev;
			tail->next = NULL;
			delete temp2;
			counter--;
		}
	} else {
		cout<<"Maaf, data tidak ditemukan"<<endl;
	}	
}

void HapusTengah(int key, string status) {
	node *temp2, *datadihapus;
	temp2 = NULL;
	if (CariData(key) != 0) {
		if (status == "sesudah") {
			cout<<"Data "<<temp->next->data<<" sudah dihapus";
			datadihapus = temp->next;
			temp2 = datadihapus->next;
			delete datadihapus;
			temp->next = temp2;
			temp2->prev = temp;
		} else if (status == "sebelum") {
			cout<<"Data "<<temp->prev->data<<" sudah dihapus";
			datadihapus = temp->prev;
			temp2 = datadihapus->prev;
			delete datadihapus;
			temp->prev = temp2;
			temp2->next = temp;
		}
		counter--;
	} else {
		cout<<"Maaf, data tidak ditemukan";
	}	
}

void EditTengah(int key, int databaru, string status) {
	node *temp2, *dataedit;
	temp2 = NULL;
	if (CariData(key) != 0) {
		if (status == "sesudah") {
			dataedit = temp->next;
			dataedit->data = databaru;
		} else if (status == "sebelum") {
			dataedit = temp->prev;
			dataedit->data = databaru;
		}
		cout<<"Data sudah dimodifikasi";
	} else {
		cout<<"Maaf, data tidak ditemukan";
	}	
}

void TampilkanData() {
	temp = head;
	if (temp != NULL) {
		while (temp != NULL) {
			cout<<temp->data<<" ";
			temp = temp->next;
		}
	} else {
		cout<<"Data tidak ada";
	}
}
