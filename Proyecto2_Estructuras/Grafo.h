#pragma once
#include<iostream>
using namespace std;

class Grafo {

private:

	char* letra;
	int** mat;
	int** let;

	char nombreNodo;

	Grafo* siguienteNodo;
	Grafo* nodoDestino;
	Grafo* aristaADY;
	Grafo* aristaSIG;


	int coordenadax;
	int coordenaday;

	int peso;

	Grafo* raiz;

public:
	Grafo();
	Grafo(int);
	void inicio(int);
	void iniciar(int);
	void menu();
	void insertarNodo(int,int);
	void agregaArista(Grafo*&, Grafo*&,int, Grafo*&);
	void mostrarGrafo();
	void insertarArista();
	void insertarArista(Grafo*, Grafo*);

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
	void setCoorx(int);
	void setCoory(int);
	void setRaiz(Grafo*);
	void sumaNombre();

	char getNombreNodo();
	Grafo* getSigNodo();
	Grafo* getNodoDest();
	Grafo* getAristaADY();
	Grafo* getAristaSIG();
	int getPeso();
	int getCoorx();
	int getCoory();
	Grafo* getRaiz();

};