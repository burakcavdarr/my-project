#include <iostream>
#include <string>
using namespace std;

struct MoneyBundle {
	string serialNumber;
	string currencyType;
	int billCounts[3];
	MoneyBundle* next;
};

struct Customer {
	string customerName;
	string transactionType;
};

MoneyBundle* top = NULL;


Customer queue[5];
int front = 0;
int rear = 0;
int customerCount = 0;

void pushMoney(string serial, string currency, int a, int b, int c) {
	MoneyBundle* newNode = new MoneyBundle();
	newNode->serialNumber = serial;
	newNode->currencyType = currency;
	newNode->billCounts[0] = a;
	newNode->billCounts[1] = b;
	newNode->billCounts[2] = c;
	newNode->next = top;
	top = newNode;
	cout << "Para destesi eklendi: " << serial << endl;
}

void popMoney() {
	if (top == NULL) {
		cout << "Kasada para yok!" << endl;
		return;
	}
	cout << "Kullanilan deste: " << top->serialNumber << " " << top->currencyType << endl;
	cout << "100ler: " << top->billCounts[0] << " 50ler: " << top->billCounts[1] << " 20ler: " << top->billCounts[2] << endl;
	MoneyBundle* temp = top;
	top = top->next;
	delete temp;
}

void enqueueCustomer(string name, string tx) {
	if (customerCount == 5) {
		cout << "Kuyruk dolu" << endl;
		return;
	}
	queue[rear].customerName = name;
	queue[rear].transactionType = tx;
	rear = (rear + 1) % 5;
	customerCount++;
	cout << name << " siraya eklendi" << endl;
}

void dequeueCustomer() {
	if (customerCount == 0) {
		cout << "Kuyrukta musteri yok" << endl;
		return;
	}
	cout << "Isleme alinan musteri: " << queue[front].customerName << " - " << queue[front].transactionType << endl;
	front = (front + 1) % 5;
	customerCount--;
}

void processTransaction() {
	if (customerCount == 0) {
		cout << "Kuyrukta musteri yok" << endl;
		return;
	}
	if (top == NULL) {
		cout << "Kasada para demeti yok" << endl;
		return;
	}
	cout << "\n Islem yapiliyor " << endl;
	dequeueCustomer();
	popMoney();
	cout << "Islem tamamlandi." << endl;
}

void displayAll() {
	cout << "\n KASA  " << endl;
	MoneyBundle* cur = top;
	if (cur == NULL) {
		cout << "Kasa bos" << endl;
	}
	while (cur != NULL) {
		cout << cur->serialNumber << " | " << cur->currencyType << " | 100: " << cur->billCounts[0] << " 50: " << cur->billCounts[1] << " 20: " << cur->billCounts[2] << endl;
		cur = cur->next;
	}

	cout << "\n siradakiler" << endl;
	if (customerCount == 0) {
		cout << "Sirada kimse yok" << endl;
	}
	for (int i = 0; i < customerCount; i++) {
		int index = (front + i) % 5;
		cout << i + 1 << ". " << queue[index].customerName << " - " << queue[index].transactionType << endl;
	}
}

int main() {
	int secim;

	while (true) {
		cout << "\n1- Para destesi ekle" << endl;
		cout << "2- Musteri ekle" << endl;
		cout << "3- Islem yap" << endl;
		cout << "4- Goster" << endl;
		cout << "5- Cikis" << endl;
		cout << "Secim: ";
		cin >> secim;

		if (secim == 1) {
			string serial, currency;
			int a, b, c;
			cout << "Seri no: ";
			cin >> serial;
			cout << "Para birimi (TL/USD): ";
			cin >> currency;
			cout << "100luk sayi: ";
			cin >> a;
			cout << "50lik sayi: ";
			cin >> b;
			cout << "20lik sayi: ";
			cin >> c;
			pushMoney(serial, currency, a, b, c);
		}
		else if (secim == 2) {
			string name, tx;
			cout << "Musteri adi: ";
			cin >> name;
			cout << "Islem turu (Cekim/Yatirma): ";
			cin >> tx;
			enqueueCustomer(name, tx);
		}
		else if (secim == 3) {
			processTransaction();
		}
		else if (secim == 4) {
			displayAll();
		}
		else if (secim == 5) {
			break;
		}
		else {
			cout << "Gecersiz secim" << endl;
		}
	}

	return 0;
}
