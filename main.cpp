#include <iostream>
#include <string>
using namespace std;

struct Page {
    string url;
    string title;
    int accessTime[3];
    Page* next;
    Page* prev;
};

Page* head = NULL;
Page* tail = NULL;
Page* current = NULL;

void visit(string url, string title, int saat, int dakika, int saniye) {
    Page* yeni = new Page();
    yeni->url = url;
    yeni->title = title;
    yeni->accessTime[0] = saat;
    yeni->accessTime[1] = dakika;
    yeni->accessTime[2] = saniye;
    yeni->next = NULL;
    yeni->prev = NULL;

    if (head == NULL) {
        head = yeni;
        tail = yeni;
        current = yeni;
}    else {
        tail->next = yeni;
        yeni->prev = tail;
        tail = yeni;
        current = yeni;
    }

    cout << "Eklendi: " << title << endl;
}

void geriGit() {
    if (current == NULL || current->prev == NULL) {
        cout << "geri yok." << endl;
        return;
    }
    current = current->prev;
    cout << "geri: " << current->title << endl;
}

void ileriGit() {
    if (current == NULL || current->next == NULL) {
        cout << "ileri yok" << endl;
        return;
    }
    current = current->next;
    cout << "ileri: " << current->title << endl;
}

void sil() {
    if (current == NULL) {
        cout << "silinecek sayfa yok." << endl;
        return;
    }

    Page* temp = current;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp == head)
        head = temp->next;

    if (temp == tail)
        tail = temp->prev;

    if (temp->next != NULL)
        current = temp->next;
    else
        current = temp->prev;

    cout << temp->title << " silindi." << endl;
    delete temp;
}

void goster() {
    if (head == NULL) {
        cout << "gecmis bos." << endl;
        return;
    }

    Page* p = head;
    int i = 1;

    cout << "gecmis:" << endl;
    while (p != NULL) {
        if (p == current)
            cout << ">> ";
        else
            cout << "   ";

        cout << i << ". " << p->title << " - " << p->url << " | ";

        for (int j = 0; j < 3; j++) {
            if (p->accessTime[j] < 10)
                cout << "0";
            cout << p->accessTime[j];
            if (j < 2)
                cout << ":";
        }
        cout << endl;

        p = p->next;
        i++;
    }
    cout << endl;
}

void temizle() {
    Page* p = head;
    while (p != NULL) {
        Page* next = p->next;
        delete p;
        p = next;
    }
    head = tail = current = NULL;
    cout << "bellek temizlendi." << endl;
}

int main() {
    int secim;
    cout << "tarayici gecmisi" << endl;

    while (true) {
        cout << "\n1. Sayfa Ekle" << endl;
        cout << "2. Geri Git" << endl;
        cout << "3. Ileri Git" << endl;
        cout << "4. Sayfayi Sil" << endl;
        cout << "5. Gecmisi Goster" << endl;
        cout << "6. Cikis" << endl;
        cout << "Seciminiz: ";
        cin >> secim;

        if (secim == 1) {
            string url, baslik;
            int s, d, sn;
            cout << "URL: "; cin >> url;
            cin.ignore();
            cout << "Baslik: "; getline(cin, baslik);
            cout << "Saat: "; cin >> s;
            cout << "Dakika: "; cin >> d;
            cout << "Saniye: "; cin >> sn;
            visit(url, baslik, s, d, sn);

              }

        else if (secim == 2) {
            geriGit();
        } else if (secim == 3) {
            ileriGit();
        } else if (secim == 4) {
            sil();
        } else if (secim == 5) {
            goster();
        } else if (secim == 6) {
            temizle();
            cout << "Cikiliyor..." << endl;
            break;
        } else {
            cout << "Gecersiz secim." << endl;
        }
    }

    return 0;
}
