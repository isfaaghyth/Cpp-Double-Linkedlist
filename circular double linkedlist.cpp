#include <iostream>
#include <stdlib.h>
using namespace std;

struct node2P {
	int data;
	node2P *next;
	node2P *prev;
} *databaru, *head, *bantu, *hapus, *bantu1;

void TambahNode(int data_input);
void Tampilkan();
int isEmpty();
// penambahan
void TambahDepan(int data_input);
void TambahBelakang(int data_input);
// penghapusan
void HapusDepan();
void HapusBelakang();
// modifikasi
void EditDataDepan(int data_input);
void EditDataBelakang(int data_input);
void EditDataTengah(int posisi, int data_input);

int counter = 0;

int main() {
	int menu, inputan, posisi;
	do {
		home:
		system("cls");
		cout<<"Double Linkedlist Circular"<<endl;
		cout<<"1. Tambah Depan"<<endl;
		cout<<"2. Tambah Belakang"<<endl;
		cout<<"3. Hapus Depan"<<endl;
		cout<<"4. Hapus Belakang"<<endl;
		cout<<"5. Edit Depan"<<endl;
		cout<<"6. Edit Belakang"<<endl;		
		cout<<"7. Edit Tengah"<<endl;	
		cout<<"8. Tampilkan"<<endl;
		cout<<"9. Exit"<<endl;
		cout<<endl;
		cout<<"Pilih menu : ";
		cin>>menu;
		
		switch (menu) {
			case 1: {
				system("cls");
				cout<<"Tambah Depan"<<endl;
				cout<<"Masukkan nilai : ";
				cin>>inputan;
				TambahDepan(inputan);
				system("pause");
				goto home;
				break;
			}
			case 2: {
				system("cls");
				cout<<"Tambah Belakang"<<endl;
				cout<<"Masukkan nilai : ";
				cin>>inputan;
				TambahBelakang(inputan);
				system("pause");
				goto home;
				break;
			}
			case 3: {
				system("cls");
				cout<<"Hapus Depan"<<endl;
				HapusDepan();
				system("pause");
				goto home;
				break;
			}
			case 4: {
				system("cls");
				cout<<"Hapus Belakang"<<endl;
				HapusBelakang();
				system("pause");
				goto home;
				break;
			}
			case 5: {
				system("cls");
				cout<<"Edit Depan"<<endl;
				cout<<"Masukkan data baru: ";
				cin>>inputan;
				EditDataDepan(inputan);
				system("pause");
				goto home;
				break;
			}
			case 6: {
				system("cls");
				cout<<"Edit Belakang"<<endl;
				cout<<"Masukkan data baru: ";
				cin>>inputan;
				EditDataBelakang(inputan);
				system("pause");
				goto home;
				break;
			}
			case 7: {
				system("cls");
				cout<<"Edit Tengah"<<endl;
				cout<<"Posisi: ";
				cin>>posisi;
				cout<<"Masukkan data baru: ";
				cin>>inputan;
				EditDataTengah(posisi, inputan);
				system("pause");
				goto home;
				break;
			}
			case 8: {
				system("cls");
				cout<<"Data";
				Tampilkan();
				cout<<endl;
				system("pause");
				goto home;
				break;
			}
		}
	} while (menu != 9);
}

void TambahNode(int data_input) {
	databaru = new node2P;
	databaru->data = data_input;
	databaru->next = databaru;
	databaru->prev = databaru;
}

int isEmpty() {
	if (head == NULL) {
		return 0;
	} else {
		return 1;
	}
}

void TambahDepan(int data_input) {
	TambahNode(data_input);
	if (isEmpty() == 0) {
		head = databaru;
	} else {
		bantu = head->prev;
		databaru->next = head;
		head->prev = databaru;
		databaru->prev = bantu;
		bantu->next = databaru;
		head = databaru;
	}
	counter++;
}

void TambahBelakang(int data_input) {
	TambahNode(data_input);
	if (isEmpty() == 0) {
		head = databaru;
	} else {
		bantu = head->prev;
		databaru->next = head;
		head->prev = databaru;
		databaru->prev = bantu;
		bantu->next = databaru;
	}	
	counter++;
}

void HapusDepan() {
	if (isEmpty() == 1) {
		cout<<"Data "<<head->data<<" sudah dihapus"<<endl;
		hapus = head;
		bantu = head->next;
		bantu1 = head->prev;
		bantu->prev = bantu1;
		bantu1->next = bantu;
		head = bantu;
		delete hapus;
		counter--;
	} else {
		cout<<"Data tidak ada";
	}
}

void HapusBelakang() {
	if (isEmpty() == 1) {
		cout<<"Data "<<head->prev->data<<" sudah dihapus"<<endl;
		hapus = head->prev;
		bantu = hapus->prev;
		head->prev = bantu;
		bantu->next = head;
		delete hapus;
		counter--;
	} else {
		cout<<"Data tidak ada";
	}	
}

void EditDataDepan(int data_input) {
	if (isEmpty() == 1) {
		head->data = data_input;
	} else {
		cout<<"Tidak ada data";
	}
}

void EditDataBelakang(int data_input) {
	if (isEmpty() == 1) {
		bantu = head->prev; //data paling belakang sebelum head
		bantu->data = data_input;
	} else {
		cout<<"Tidak ada data";
	}
}

void EditDataTengah(int posisi, int data_input) {
	bantu = head;
	if (isEmpty() == 1) {
		if (posisi == 1) {
			EditDataDepan(data_input);
		} else if (posisi == counter) {
			EditDataBelakang(data_input);
		} else if (posisi != counter) {
			while (--posisi != 0) {
				bantu = bantu->next;
			} 
			bantu->data = data_input;
		} else {
			cout<<"Data hanya ada "<<counter;
		}
	} else {
		cout<<"Tidak ada data";
	}
}

void Tampilkan() {
	bantu = head;
	cout<<endl;
	if (isEmpty() == 1) {
		do {
			cout<<bantu->data<<" ";
			bantu = bantu->next;
		}
		while (bantu != head);	
	}
}
