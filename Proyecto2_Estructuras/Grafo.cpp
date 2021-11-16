#include"Grafo.h"

Grafo::Grafo() {
  // nombreNodo=' ';
   siguienteNodo = NULL;
   nodoDestino = NULL;
   aristaADY = NULL;
   aristaSIG = NULL;
   peso = 0;
   raiz = NULL;
}

Grafo::Grafo(char nombreNodo) {
    this->nombreNodo=nombreNodo;
}

void Grafo::inicio() {
    //p = NULL;
    int opcion;     // opcion del menu

    do{
        menu();
        cin >> opcion;

        switch (opcion){
        case 1:
            insertarNodo(getRaiz());
            break;
        case 2: insertarArista();
            break;
        /*case 3: eliminar_nodo();
            break;
        case 4: eliminar_arista();
            break;*/
        case 5: mostrarGrafo();
            break;
       /* case 6: mostrar_aristas();
            break;*/

        default: cout << "OPCION NO VALIDA...!!!";
            break;


        }

        cout << endl << endl;
        system("pause");  system("cls");

    } while (opcion != 7);
}

void Grafo::menu(){
    cout << "\n\tREPRESENTACION DE GRAFOS DIRIGIDOS\n\n";
    cout << " 1. INSERTAR UN NODO                 " << endl;
    cout << " 2. INSERTAR UNA ARISTA              " << endl;
    cout << " 3. ELIMINAR UN NODO                 " << endl;
    cout << " 4. ELIMINAR UNA ARISTA              " << endl;
    cout << " 5. MOSTRAR  GRAFO                   " << endl;
    cout << " 6. MOSTRAR ARISTAS DE UN NODO       " << endl;
    cout << " 7. SALIR                            " << endl;
    cout << "\n INGRESE OPCION: ";
}


void Grafo::insertarNodo(Grafo* raiz)
{
    Grafo* t;
    Grafo* nuevo = new Grafo();

    char name;
    cout << "INGRESE VARIABLE:";
    cin >> name;
    nuevo->setNombreNodo(name);

    nuevo->setSigNodo(NULL);
    nuevo->setAristaADY(NULL);

    if (raiz == NULL)
    {
        setRaiz(nuevo);
        cout << "PRIMER NODO...!!!";
    }
    else
    {
        t = raiz;
        while (t->getSigNodo() != NULL)
        {
            t = t->getSigNodo();
        }
        t->setSigNodo(nuevo);
        cout << "NODO INGRESADO...!!!";
    }
}

void Grafo::agregaArista(Grafo*& aux, Grafo*& aux2, int peso, Grafo*& nuevo)
{
    Grafo* q;

    if (aux->getAristaADY()==NULL)
    {
        aux->setAristaADY(nuevo);
        nuevo->setNodoDest(aux2);
        nuevo->setPeso(peso);
        cout << "PRIMERA ARISTA....!";
    }else{
        q = aux->getAristaADY();
        while (q->getAristaSIG() != NULL) {
            q = q->getAristaSIG();
        }         
        nuevo->setNodoDest(aux2);
        nuevo->setPeso(peso);
        q->setAristaSIG(nuevo);
        cout << "ARISTA AGREGADA...!!!!";
    }

}

void Grafo::insertarArista(){
    char ini, fin;
    int peso;

    Grafo* nuevo = new Grafo();
    Grafo* aux,* aux2;

    if (getRaiz() == NULL)
    {
        cout << "GRAFO VACIO...!!!!";
        return;
    }

    //nuevo->siguiente = NULL;
    nuevo->setAristaSIG(NULL);
    cout << "INGRESE NODO DE INICIO:";
    cin >> ini;
    cout << "INGRESE NODO FINAL:";
    cin >> fin;
    cout << "PESO" << endl;
    cin >> peso;
    aux = getRaiz();
    aux2 = getRaiz();
    while (aux2 != NULL)
    {
        if (aux2->getNombreNodo() == fin)
        {
            break;
        }

        aux2 = aux2->getSigNodo();
    }
    while (aux != NULL)
    {
        if (aux->getNombreNodo() == ini)
        {
            agregaArista(aux, aux2, peso, nuevo);
            return;
        }

        aux = aux->getSigNodo();
    }
}

void Grafo::mostrarGrafo(){

    Grafo* auxNodo;
    Grafo* auxArista;

    auxNodo = getRaiz();
    cout << "NODO|LISTA DE ADYACENCIA\n";

    while (auxNodo != NULL)
    {
        cout << "   " << auxNodo->getNombreNodo() << "|";
        if (auxNodo->getAristaADY() != NULL)
        {
            auxArista = auxNodo->getAristaADY();
            while (auxArista != NULL)
            {
                cout << " " << auxArista->getNodoDest()->getNombreNodo();
                cout << auxArista->getPeso();
                auxArista = auxArista->getAristaSIG();
            }
        }
        auxNodo = auxNodo->getSigNodo();
        cout << endl;
    }
}

//--------------------------sets y gets-----------------------------------------
void Grafo::setNombreNodo(char nombre) {
    this->nombreNodo = nombre;
}

void Grafo::setSigNodo(Grafo* siguienteNodo) {
    this->siguienteNodo = siguienteNodo;
}

void Grafo::setNodoDest(Grafo* nodoDestino) {
    this->nodoDestino = nodoDestino;
}

void Grafo::setAristaADY(Grafo* aristaADY) {
    this->aristaADY = aristaADY;
}

void Grafo::setAristaSIG(Grafo* aristaSIG) {
    this->aristaSIG = aristaSIG;
}

void Grafo::setPeso(int peso) {
    this->peso = peso;
}

void Grafo::setRaiz(Grafo* raiz) {
    this->raiz = raiz;
}

char Grafo::getNombreNodo() {
    return nombreNodo;
}

Grafo* Grafo::getSigNodo() {
    return siguienteNodo;
}

Grafo* Grafo::getNodoDest() {
    return nodoDestino;
}

Grafo* Grafo::getAristaADY() {
    return aristaADY;
}

Grafo* Grafo::getAristaSIG() {
    return aristaSIG;
}

int Grafo::getPeso() {
    return peso;
}

Grafo* Grafo::getRaiz() {
    return raiz;
}
