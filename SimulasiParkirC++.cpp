#include <iostream>
#include <stdlib.h>
#include <limits>
#include <windows.h>

using namespace std;

struct node {
	string info;
	struct node *link;
};

void display(struct node *start);
struct node *addatbeg(struct node *start, string num);
void addatend(struct node *start, string num);
struct node *del (struct node *start, string num);
struct node *keluar(struct node *start);

int slotParkir = 10, counter = -1;

int main () {
	struct node *start = NULL;
	int k;
	string num;
	bool condition = true;
	
	while (condition) {
		cout << "\n************ PARKIR TOKO X ************" << endl;
		cout << "1. Masukkan Mobil" << endl;
		cout << "2. Keluarkan Mobil" << endl;
		cout << "3. Program Keluar" << endl;
		cout << "***************************************" << endl;
		cout << "Slot Parkir = "<< slotParkir << endl;
		cout << "Pilih (1/2/3): "; cin >> k;
		
		while(cin.fail()) {
		    cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(),'\n');
		    cout << "Input Salah! Masukkan pilihan: "; cin >> k;
		}
		
		switch (k) {
			case 1: 
				cout << "Masukkan nomor plat yang akan masuk: "; cin >> num;
				if (start == NULL) {
					system("cls");
					start = addatbeg(start, num);
				} else {
					if (slotParkir == 0) {
						system("cls");
						cout << "PARKIR PENUH" << endl;
					} else{
						system("cls");
						addatend(start, num);
					}
				} 
            	display(start);
				break;
			case 2: 
				start = keluar(start);
				display(start);
				break;
			case 3: 
				cout << "\nProgram Keluar....." << endl; 
				Sleep(1000);
				condition = false;
				break;
			default: 
				system("cls");
				cout << "Input salah. Ulangi kembali" << endl;
            	display(start);
            	break;
		}
	}
}

void display(struct node *start) {
	struct node *p;
	if (start == NULL) {
		cout << "\nPARKIR KOSONG" << endl;
		return;
	}
	
	p = start;
	cout << "\nKeluar Pintu Selatan (Depan)\n=+=+=+=+=+=+=+=+=" << endl;
	while (p != NULL) {
		cout << " - "<< p -> info << endl;
		p = p -> link;
	}
	cout << "=+=+=+=+=+=+=+=+=\nMasuk Pintu Utara (Belakang)" << endl;
}

struct node *addatbeg(struct node *start, string num) {
	struct node *temp;
	temp = new node;
	temp -> info = num;
	temp -> link = start;
	start = temp;
	
	slotParkir--; counter++;
	return start;
}

void addatend(struct node *start, string num) {
	struct node *temp, *p;
	if (start == NULL) {
		cout << "Fungsi Error" << endl;
		return;
	}
	
	temp = new node;
	temp -> info = num;
	p = start;
	while (p -> link != NULL) {
		p = p -> link;
	}
	p -> link = temp;
	temp -> link = NULL;
	
	slotParkir--; counter++;
}

struct node *keluar(struct node *start) {
	int selesai;
	string temp[10];
    
    if (start == NULL) {
    	system("cls");
		cout << "\nParkir dalam keadaan kosong" << endl;
		return 0;
	}
	
    cout << "Masukkan urutan mobil yang akan keluar: ";
    cin >> selesai;
    while(cin.fail()) {
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(),'\n');
	    cout << "Input Salah! Masukkan urutan: "; cin >> selesai;
	} 
	
	selesai -= 1;
	
	if (selesai > counter || selesai < 0) {
		system("cls");
		cout << "Mobil pada urutan " << selesai + 1 << " tidak ada" << endl;
		return start;
	}
	
	cout << endl;  
	system("cls");
	
	for (int i = 0; i < selesai; i++) {
        // PUSH
        temp[i] = start -> info;
        start = del(start, temp[i]);
        cout << "- Mobil " << temp[i] << " Keluar terlebih dahulu" << endl;
    }

    cout << "- Mobil " << start -> info << " Keluar dari tempat parkir" << endl;
    string target =  start -> info;
    start = del(start, target);

    for (int j = selesai - 1; j >= 0; j--) {
        // POP
        start = addatbeg(start, temp[j]);
        cout << "- Mobil " << temp[j] << " sudah kembali" << endl;
    }

	slotParkir++; counter--;
    return start;
}

struct node *del (struct node *start, string num) {
	struct node *temp, *p;
	if (start == NULL) {
		cout << "List Kosong" << endl;
		return start;
	}
	
	if (start -> info == num) {
		temp = start;
		start = start -> link;
		free(temp);
		return start;
	}
}
