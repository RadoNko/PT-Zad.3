//
//  main.cpp
//  Jankech_Daniel_97814_du03
//
//  Created by Daniel Jankech on 09/10/2019.
//  Copyright © 2019 Daniel Jankech. All rights reserved.
//

/*
 Meno a priezvisko:
 
 POKYNY:
 (1)  Subor premenujte na Priezvisko_Meno_ID_du03.cpp (pouzite vase udaje bez diakritiky).
 (2)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
 (3)  Cela implementacia musi byt v tomto jednom subore.
 (4)  Odovzdajte len tento (spravne premenovany) zdrojovy subor.
 (5)  Program musi byt kompilovatelny.
 (6)  Globalne a staticke premenne su zakazane.
 (7)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
 (nemente nazvy, navratove hodnoty ani typ a pocet parametrov v zadanych funkciach).
 Nemente implementacie hotovych pomocnych funkcii, ani implementacie zadanych datovych typov.
 (8)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo struktury.
 (9)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo struktur).
 Testovaci kod ale nebude hodnoteny.
 (10) Funkcia 'main' musi byt v zdrojovom kode posledna.
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <iterator>

using namespace std;

#define LENGTH(array) (sizeof(array)/sizeof(array[0]))

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Uzol zretazeneho zoznamu
struct Node {
    int data; // hodnota uzla
    Node* next; // smernik na dalsi uzol zoznamu
};

// Zretazeny zoznam
struct List {
    Node* first; // smernik na prvy uzol zoznamu
};

//-------------------------------------------------------------------------------------------------
// ULOHA (0.2 boda)
//-------------------------------------------------------------------------------------------------
/*
 Usporiada pole 'data' od najvacsieho po najmensi prvok.
 Pouzite algoritmus insertion sort.
 Usporiadanie je od najvacsieho po najmensi prvok (opacne ako na tutorialy)!
 
 PARAMETRE:
 [in, out] data - pole, ktore funkcia usporiada
 [in] length - pocet prvkov pola
 
 VSTUPNE PODMIENKY:
 'length' moze mat lubovolnu hodnotu
 'data' ukazuje na platne pole
 
 PRIKLADY:
 {1,3,2} -> {3, 2, 1}
 {} -> {}
 */

void insertionSort(int *data, const size_t length) {
    // TODO
    for(size_t i = 1; i < length; ++i ) { // 'i' oznacuje hranicu usporiadanej casti pola
        int current = data[i];
        size_t j = i;
        while(j > 0 && data[j-1] < current) {
            data[j] = data[j-1];
            --j;
        }
        data[j] = current;
    }
}

void println(const char * label, const int *data, const size_t length) {
    cout << label << ": ";
    for(size_t i = 0; i < length; ++i) {
        cout << setw(3) << data[i] << ' ';
    }
    cout << endl;
}

void test_insertionSort(){
    cout << "insertion sort" << endl;
    
    int d1[] = {10, 5, 2, 1, 8, 7, 5};
    insertionSort(d1, LENGTH(d1));
    println("d1", d1, LENGTH(d1));
    
    int d2[] = {100, -5, 1, 2 };
    insertionSort(d2, LENGTH(d2));
    println("d2", d2, LENGTH(d2));
    
//    insertionSort(d2, 1);
//    println("d2", d2, LENGTH(d2));
//    
//    insertionSort(d2, 0);
//    println("d2", d2, LENGTH(d2));
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.2 boda)
//-------------------------------------------------------------------------------------------------
/*
 Usporiada textove retazce v poli 'data' od najvacsieho po najmensi prvok (lexikograficky).
 Pouzite algoritmus insertion sort.
 Usporiadanie je od najvacsieho po najmensi prvok!
 
 PARAMETRE:
 [in, out] data - pole, ktore funkcia usporiada.
 Pole obsahuje smerniky na textove retazce.
 Kazdy textovy retazec je ukonceny '\0'.
 Posledny smernik ma hodnotu 'nullptr'. Podla toho urcite pocet prvkov pola (pocet textovych retazcov).
 
 VSTUPNE PODMIENKY:
 'data' obsahuje minimalne jeden smernik.
 Posledny smernik ma hodnotu 'nullptr'.
 
 PRIKLADY:
 {"Juraj", "Peter", "Andrej", nullptr} -> {"Peter", "Juraj", "Andrej", nullptr}
 {nullptr} -> {nullptr}
 
 POZNAMKY:
 Pri testovani mozete jednoducho pole vytvorit nasledovnym sposobom:
 const char *mena[] = {"Juraj", "Peter", "Andrej", nullptr};
 
 Na porovnanie obsahu textovych retazcov vyuzite prislusnu funkciu zo standardnej kniznice.
 */
void insertionSort(const char *data[]) {
    // TODO
    int i=1;
    while (data[i]) {
        char *current = new char;
        strcpy(current, data[i]);

        size_t j = i;
        
        while(j > 0 && strcmp(data[i-1],data[i])<0) {
            data[j] = data[j-1];
            --j;
        }
        i++;
        data[j] = current;
        
    }
}

Node* createNode(const int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}


void appendNode(List* list, const int val) {
    // TODO
    Node* newNode = createNode(val);
    if (!list->first) {
        
        list->first = newNode;
    } else {
        
        Node* tmp = list->first;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}


List* createListFromArray(const int* data, const int n) {
    // TODO
    List* newList=new List;
    if (n>=0) {
        for (int i=0; i<n; i++) {
            appendNode(newList,data[i]);
        }
        return newList; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
        
    } else {
        return nullptr;
    }
}


//-------------------------------------------------------------------------------------------------
// ULOHA (0.2 boda)
//-------------------------------------------------------------------------------------------------
/*
 Usporiada zretazeny zoznam 'list' od najvacsieho po najmensi prvok.
 Pouzite algoritmus insertion sort.
 Usporiadanie je od najvacsieho po najmensi prvok!
 
 PARAMETRE:
 [in, out] list - zretazeny zoznam, ktory funkcia usporiada
 
 VSTUPNE PODMIENKY:
 'list' obsahuje lubovolny pocet uzlov (moze byt prazdny)
 'list' nie je 'nullptr'
 
 PRIKLADY:
 vstup: 2->1->3, vystup: 3->2->1
 vstup: prazdny zoznam, vystup: prazdny zoznam
 */


void insertionSort(List * list) {
    Node* head=list->first;
    if(head== NULL || head->next == NULL) {
        return;
    }
    Node* t1 = head->next;
    while(t1 != NULL) {
        int sec_data = t1->data;
        int found = 0;
        Node *t2 = head;
        while(t2 != t1) {
            if(t2->data < t1->data && found == 0) {
                sec_data = t2->data;
                t2->data = t1->data;
                found = 1;
                t2 = t2->next;
            } else {
                if(found == 1) {
                    int temp = sec_data;
                    sec_data = t2->data;
                    t2->data = temp;
                }
                t2 = t2->next;
            }
        }
        t2->data = sec_data;
        t1 = t1->next;
    }
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.2 boda)
//-------------------------------------------------------------------------------------------------
/*
 Vykona algoritmus merge (cast algoritmu merge sort).
 Kombinuje dve susedne usporiadane casti v poli 'input' do jednej usporiadanej casti v poli 'output'
 Usporiadanie je od najvacsieho po najmensi prvok!
 
 PARAMETRE:
 [out] 'output' - vystupne pole, ktoreho cast output[low]...output[high-1] bude po vykonani funkcie usporiadana
 [in] 'input'   - vstupne pole, ktoreho casti input[low]...input[middle-1] a input[middle]...input[high-1]
 musia byt pri volani funkcie usporiadane od najvacsieho po najmensi prvok
 [in] 'low'     - index 1. prvku lavej usporiadanej casti pola 'input'
 [in] 'middle'  - index 1. prvku pravej usporiadanej casti pola 'input'
 [in] 'high'    - index za poslednym prvkom pravej usporiadanej casti pola 'input'
 
 VYSTUPNE PODMIENKY:
 output[low] ... output[high-1] obsahuje usporiadane prvky z input[low] ... input[high-1]
 obsah 'input' sa nemeni
 prvky s indexami mensimi ako 'low' sa nemenia (v obidvoch poliach)
 prvky s indexami vacsimi alebo rovnymi ako 'high' sa nemenia (v obidvoch poliach)
 
 PRIKLAD:
 low: 4
 middle: 8
 hight: 12
 input:  {10, 20, 30, 40 > 7, 5, 2, 0 , 8, 4, 2, 1 > 10, 20, 30, 40}
 output: {10, 20, 30, 40 > 8, 7, 5, 4, 2, 2, 1, 0 >10, 20, 30, 40}
 */

void merge(int* output, const int* input, const size_t low, const size_t middle, const size_t high)
{
    // TODO
    int in1 = low;
    int in2 = middle;
    int out = low;

    while (in1 < middle && in2 < high) {
        if (input[in1] >= input[in2]) {
            output[out] = input[in1];
            out++;
            in1++;
        }
        else{
            output[out] = input[in2];
            out++;
            in2++;
        }
    }
    while (in1 < middle) {
        output[out] = input[in1];
        out++;
        in1++;
    }
    while (in2 < middle) {
        output[out] = input[in2];
        out++;
        in2++;
    }
}
void mergeSortRecursive(int* arrayA, int* arrayB, const size_t low, const size_t high)
{
    if (low + 1 >= high) {
        return;
    }
    int middle = (high + low) / 2;
    mergeSortRecursive(arrayB, arrayA, low, middle);
    mergeSortRecursive(arrayB, arrayA, middle, high);
    merge(arrayA, arrayB, low, middle, high);
}
//-------------------------------------------------------------------------------------------------
// ULOHA (0.2 boda)
//-------------------------------------------------------------------------------------------------
/*
 Usporiada prvky v poli 'data' od najvacsieho po najmensi.
 Pouzite algoritmus merge sort.
 Usporiadanie je od najvacsieho po najmensi prvok!
 
 PARAMETRE:
 [in, out] data - pole, ktore funkcia usporiada
 [int]   length - pocet prvkov pola
 
 VSTUPNE PODMIENKY:
 'data' ukazuje na platne pole
 
 PRIKLADY:
 {1,3,2} -> {3, 2, 1}
 {} -> {}
 
 POZNAMKA:
 Pri implementacii top-down bude vhodne vytvorit a zavolat rekurzivnu funkciu.
 */
void mergeSort(int *data, const size_t length) {
    // TODO
    
    
    
    int* tmpArray = new int[length]; // pomocne pole
    std::memcpy(tmpArray, data, length * sizeof(int));
    mergeSortRecursive(data, tmpArray, 0, length);
    delete[] tmpArray;
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury

int main() {
    
    // tu mozete doplnit testovaci kod
    //test_insertionSort();
//    int pole[]={1,2,5,2,9,3};
//
//    List *list=new List;
//    list=createListFromArray(pole, 6);
//    Node* tmp=list->first;
//    insertionSort(list);
//    while (tmp) {
//        cout<<tmp->data<<" ";
//        tmp=tmp->next;
//    }
//    cout<<endl;
    
    
    const char *mena[] = {nullptr};
    insertionSort(mena);
    int i = 0;
    while (mena[i]!=nullptr) {
        cout<<mena[i]<<" ";
        i++;
    }
    cout<<endl;
    
    return 0;
}
