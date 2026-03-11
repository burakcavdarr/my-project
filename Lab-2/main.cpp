#include <iostream>
#include <string>
using namespace std;


struct Node {
	string song;
	Node* next;
};

void listsongs(Node* head) {

	if (head == NULL) {
		cout << "playlist bos" << endl;
		return;
	}

	Node* temp = head;
	int i = 1;
	while (temp != NULL) {
		cout << i << ". " << temp->song << endl;
		temp = temp->next;
		i++;
	}
}

void addsong(Node*& head, string title) {
	Node* newNode = new Node();
	newNode->song = title;
	newNode->next = head;
	head = newNode;
	cout << "sarki eklendi" << endl;
}

void searchsong(Node* head, string title) {
	Node* temp = head;
	int pos = 1;
	bool found = false;

	while (temp != NULL) {
		if (temp->song == title) {
			cout << "bulundu! pozisyon: " << pos << endl;
			found = true;
			break;
		}
		temp = temp->next;
		pos++;
	}

	if (found == false) {
		cout << "sarki bulunamadi" << endl;
	}
}

int main()
{
    Node* head = NULL;
	int choice;
	string input;

	while(choice != 4) {
		cout << "\n1. Add" << endl;
		cout << "2. Search" << endl;
		cout << "3. List" << endl;
		cout << "4. Exit" << endl;
		cout << "secim: ";
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1:
			cout << "sarki adi gir: ";
			getline(cin, input);
			addsong(head, input);
			break;
		case 2:
			cout << "aranacak sarki: ";
			getline(cin, input);
			searchsong(head, input);
			break;
		case 3:
			listsongs(head);
			break;
		case 4:

			break;
		default:
			cout << "gecersiz secim" << endl;
			break;
		}
	}


	return 0;
}
