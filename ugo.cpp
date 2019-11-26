
//Questa cavalla qui non è la stessa più, non è la stessa più!
//  main.cpp
//  Esercizio puntatori a struct
//
//
//  main.cpp
//  Lezione 93
//
//  Created by Mattia Serpelloni on 12/11/18.
//  Copyright © 2018 Mattia Serpelloni. All rights reserved.
//
//Prova a dichiarare una struct che dichiari un triangolo nello spazio---> una struttura con dentro un array di tre punti. O meglio ancora una struct con array di 3 puntatori a tre ounti dello spazio
//
//
#include<iostream>
#include<stdlib.h> //Per fare system pause?
#include<limits> // header che include oggetti come rappresentazione del più grande numero intero (anche se a me va comunque anche col solo iostream).
#include<cstdint>
#include<cctype>//il c davanti sta per c++ che non c'è nelle librerie di c. (qui serve peer caratterizzare )
#include<cmath> //abbiamo una nuova libreria
#include<cstdlib> //  Per accedere alle funzioni rand() e srand().
#include<ctime>//la libreria che segue serve per usare il comando time
//che restituisce l'ora al momento del lancio del programma
//ed usare i secondi come punto di partenza difficilmente ripetibile
//per la generazione di numeri casuali
//#include <ctime> permette di accedere alla struttura time che voglio sfruttare per dare una struttura di verosimiglianza di casualità, agganciando il generatore di numeri casuali all'istante di partenza del programma. Diversamente la seguenza sarebbe casuale all'interno del programma ma rilanciando riprenderebbe con la stessa sequenza.
//srand() ed un valore estratto da ctime dall'orologio di sistema per avere numeri casuali.
//Inizialmente estraiamo numeri fregandoci che la sequenza sia  del tutto casuale.
#include<fstream> //per gestire flusso di byte.
#include<iomanip> //imput output manipulator per setw
#include<string>
#include<algorithm>
#include <vector>
using namespace std;

struct t_punto3D//rappresento punto nello spazio tridimensionale
{
    long double x,y,z;
};
t_punto3D *punto_medio_3d(const t_punto3D *a, const t_punto3D *b )//
{
    long double x=(a->x+b->x)/2;
    long double y=(a->y+b->y)/2;
    long double z=(a->z+b->z)/2;
    return new t_punto3D {x,y,z};//Restituisco un indirizzo creato dalla new del punto appena creato
}
struct t_triangolo
{
    t_punto3D *a,*b,*c;//Tre puntatori a tre punti, uno per ogni vertice dl triangolo.
};
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::numeric_limits;
    using std::string;
    using std::ifstream;
    using std::setprecision;
    using std::bad_alloc;
    using std::cerr;
    t_punto3D *a=new t_punto3D {-4,2,8};//puntatore  'a' memorizza l'inderizzo restituito della creazione del punto 3d con le coordinate date.
    cout<<a<<endl;
    t_punto3D *b=new t_punto3D {-6,12,56};
    t_punto3D *medio=punto_medio_3d(a, b);//devo dereferenziarlo perchè punto medio restituisce un indirizzo
    cout<<"\nx="<<(*medio).x
    <<" y="<<(*medio).y
    <<" z="<<(*medio).z//medio è l'indirizzo, per passare dall'indirizzo della struct alla struct devo derefernziarlo, e poi possiamo accedere alla coordinata x. Le parentesi servono altrimenti le priorità potrebbero non funzionare.
    <<endl;
    //Esiste un modo miglio per puntare alle struct una migliore sintassi. OPERATORE freccia
    //Se medio è il puntatore ad una struct che contine come membro la variabile x
    cout<<"\nx="<<medio->x
    <<" y="<<medio->y
    <<" z="<<medio->z//medio è l'indirizzo, per passare dall'indirizzo della struct alla struct devo derefernziarlo, e poi possiamo accedere alla coordinata x. Le parentesi servono altrimenti le priorità potrebbero non funzionare.
    <<endl;
    delete a;
    delete b;
    delete medio;
    t_triangolo t1{new t_punto3D{1,2,3},new t_punto3D{4,5,6},new t_punto3D{7,8,9}};
    //oppure
    t_triangolo t1_bis;
    t1_bis.a=new t_punto3D{1,2,3};
    t1_bis.b=new t_punto3D{4,5,6};
    t1_bis.c=new t_punto3D{7,8,9};
    cout<<t1.a->y<<endl;//t1 è una strut, si prosegue con la notazione del punto. Accediamo ad 'a' che è un puntatore ad una struct (quindi possiamo usare la freccia).
    //Per chiamare la funzione punto medio 3d siamo a posto perchè vuole proprio puntatori e t1.a è un puntatore che punta alla struct t_punto3d
    t_punto3D *medio2=punto_medio_3d(t1.a, t1.c);
    cout<<"\nx="<<medio2->x
    <<" y="<<medio2->y
    <<" z="<<medio2->z<<endl;
    //Vediamo la versione che utilizza  un puntatore t2 che è un puntatore ad una struct di  tipo triangolo
    t_triangolo *t2=new t_triangolo {new t_punto3D{1,2,3},new t_punto3D{4,5,6},new t_punto3D{7,8,9}};
    cout<<t2->a->y<<endl;
    t_punto3D *medio3=punto_medio_3d(t2->a,t2->c);
    cout<<"\nx="<<medio3->x
    <<" y="<<medio3->y
    <<" z="<<medio3->z<<endl;
    return 0;
}

