#pragma once
#include<iostream>
using namespace std;

class Grafo {

private:

	char nombreNodo;

	Grafo* siguienteNodo;
	Grafo* nodoDestino;
	Grafo* aristaADY;
	Grafo* aristaSIG;
	int peso;

	Grafo* raiz;

public:
	Grafo();
	Grafo(char);
	void inicio();
	void menu();
	void insertarNodo(Grafo*);
	void agregaArista(Grafo*&, Grafo*&,int, Grafo*&);
	void mostrarGrafo();
	void insertarArista();
	/*void vaciarAristas(Grafo&);
	void eliminarNodo();
	void eliminarArista();
	void mostrarAristas();*/
	
	void setNombreNodo(char);
	void setSigNodo(Grafo*);
	void setNodoDest(Grafo*);
	void setAristaADY(Grafo*);
	void setAristaSIG(Grafo*);
	void setPeso(int);
	void setRaiz(Grafo*);
	void sumaNombre();

	char getNombreNodo();
	Grafo* getSigNodo();
	Grafo* getNodoDest();
	Grafo* getAristaADY();
	Grafo* getAristaSIG();
	int getPeso();
	Grafo* getRaiz();

};