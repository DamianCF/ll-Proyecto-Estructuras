#include"Grafo.h"

/*Grafo::Grafo()
{
    nombreNodo = 65;
    siguienteNodo = NULL;
    nodoDestino = NULL;
    aristaADY = NULL;
    aristaSIG = NULL;
    peso = 0;
    raiz = NULL;
}*/

Grafo::Grafo() {
   nombreNodo=65;
   siguienteNodo = NULL;
   nodoDestino = NULL;
   aristaADY = NULL;
   aristaSIG = NULL;
   peso = 0;
   coordenadax = 0;
   coordenaday = 0;
   suma = 999;
   contp = 0;
   cont = 0;
   raiz = NULL;

   letra = new char[10];
   letra[0] = 'A';
   letra[1] = 'B';
   letra[2] = 'C';
   letra[3] = 'D';
   letra[4] = 'E';
   letra[5] = 'F';
   letra[6] = 'G';
   letra[7] = 'H';
   letra[8] = 'I';
   letra[9] = 'J';

}


void Grafo::iniciar(int t) {

    let = new int* [t];

    mat = new int* [t];

    lista = new int [t];

    listamayor = new int[t];

    for (int i = 0; i < t; i++) {  // Inicializa la matriz de adyacencia
        mat[i] = new int[t];
    }

    for (int i = 0; i < t; i++) { // Inicializa la matriz de recorrido
        let[i] = new int[t];
    }

    for (int i = 0; i < t; i++) {  // Llena la matriz de adyacencia con el valor de INT_MIN
        for (int j = 0; j < t; j++) {
            mat[i][j] = INT_MIN;
        }
    }

    for (int i = 0; i < t; i++) {  // Llena la matriz de recorrido con el valor de su columna
        for (int j = 0; j < t; j++) {
            let[i][j] = j;
        }
    }

    for (int i = 0; i < t; i++) { //imprime la letra de la columna

        for (int j = 0; j < t; j++) {
            cout.width(10);
            cout << letra[let[i][j]];
        }
        cout << endl;
    }
         
}


void Grafo::inicio(int t) {

    let = new int*[t];
    
    mat = new int* [t];

    for (int i = 0; i < t; i++) {  // Inicializa la matriz de adyacencia
        mat[i] = new int[t];
    }

    for (int i = 0; i < t; i++) { // Inicializa la matriz de recorrido
        let[i] = new int[t];
    }

    for (int i = 0; i < t; i++) {  // Llena la matriz de adyacencia con el valor de INT_MIN
        for (int j = 0; j < t; j++) {
            mat[i][j] = INT_MIN;
        }
    }

    for (int i = 0; i < t; i++) {  // Llena la matriz de recorrido con el valor de su columna
        for (int j = 0; j < t; j++) {
            let[i][j] = j;
        }
    }

    for (int i = 0; i < t; i++) { //imprime la letra de la columna

        for (int j = 0; j < t; j++) {
            cout.width(10);
            cout << letra[let[i][j]];
        }
        cout << endl;
    }
    cout << endl;
    cout << "  ";
    
    //p = NULL;
    int opcion;     // opcion del menu

    do{
        menu();
        cin >> opcion;

        switch (opcion){
        case 1:
            insertarNodo(300,400);
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


void Grafo::insertarNodo(int x, int y)
{
    Grafo* raiz = getRaiz();
    Grafo* t;
    Grafo* nuevo = new Grafo();

    nuevo->setSigNodo(NULL);
    nuevo->setAristaADY(NULL);

    if (raiz == NULL)
    {
        nuevo->setNombreNodo(getNombreNodo());
        nuevo->setCoorx(x);
        nuevo->setCoory(y);
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
        nuevo->setNombreNodo(t->getNombreNodo() + 1);
        nuevo->setCoorx(x);
        nuevo->setCoory(y);
        t->setSigNodo(nuevo);
        cout << "NODO INGRESADO...!!!";
        insertarArista(t, nuevo);
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
    int peso,i=0,j=0;

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

    if (ini == 'A')
    {
        i = 0;
    }
    else
    {
        if (ini == 'B')
        {
            i = 1;
        }
        else
        {
            if (ini == 'C')
            {
                i = 2;
            }
            else
            {
                if (ini == 'D')
                {
                    i = 3;
                }
                else
                {
                    if (ini == 'E')
                    {
                        i = 4;
                    }
                    else
                    {
                        if (ini == 'F')
                        {
                            i = 5;
                        }
                    }
                }
            }
        }
    }

    if (fin == 'A')
    {
        j = 0;
    }
    else
    {
        if (fin == 'B')
        {
            j = 1;
        }
        else
        {
            if (fin == 'C')
            {
                j = 2;
            }
            else
            {
                if (fin == 'D')
                {
                    j = 3;
                }
                else
                {
                    if (fin == 'E')
                    {
                        j = 4;
                    }
                    else
                    {
                        if (fin == 'F')
                        {
                            j = 5;
                        }
                    }
                }
            }
        }
    }

    mat[i][j] = peso;

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

void Grafo::insertarArista(Grafo* ant, Grafo* nuevoN) {
    int peso, i = 0, j = 0;

    Grafo* nuevo = new Grafo();
    Grafo* aux, * aux2;

    if (getRaiz() == NULL)
    {
        cout << "GRAFO VACIO...!!!!";
        return;
    }

    
    nuevo->setAristaSIG(NULL);
  
    peso = 2;

    if (ant->getNombreNodo() == 'A')
    {
        i = 0;
    }
    else
    {
        if (ant->getNombreNodo() == 'B')
        {
            i = 1;
        }
        else
        {
            if (ant->getNombreNodo() == 'C')
            {
                i = 2;
            }
            else
            {
                if (ant->getNombreNodo() == 'D')
                {
                    i = 3;
                }
                else
                {
                    if (ant->getNombreNodo() == 'E')
                    {
                        i = 4;
                    }
                    else
                    {
                        if (ant->getNombreNodo() == 'F')
                        {
                            i = 5;
                        }
                    }
                }
            }
        }
    }

    if (nuevoN->getNombreNodo() == 'A')
    {
        j = 0;
    }
    else
    {
        if (nuevoN->getNombreNodo() == 'B')
        {
            j = 1;
        }
        else
        {
            if (nuevoN->getNombreNodo() == 'C')
            {
                j = 2;
            }
            else
            {
                if (nuevoN->getNombreNodo() == 'D')
                {
                    j = 3;
                }
                else
                {
                    if (nuevoN->getNombreNodo() == 'E')
                    {
                        j = 4;
                    }
                    else
                    {
                        if (nuevoN->getNombreNodo() == 'F')
                        {
                            j = 5;
                        }
                    }
                }
            }
        }
    }

    mat[i][j] = peso;

    aux = ant;
    aux2 = nuevoN;

    agregaArista(aux, aux2, peso, nuevo);
    
}

void Grafo::mostrarGrafo(){

    cout << endl;
    cout << "  ";
    for (int i = 0; i < 5; i++) {
        cout.width(10);
        cout << letra[i];
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {
            cout.width(10);
            if (j == 0)
            {
                cout.width(10);
                cout << letra[i] << " ";
            }
            if (mat[i][j] == INT_MAX)
            {
                cout << 0;
            }
            else
                if (mat[i][j] == INT_MIN)
                {
                    cout << -1;
                }
                else
                    cout << mat[i][j];
        }
        cout << endl;
    }

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

void Grafo::insertar(int x)
{
    lista[contp] = x;
    contp++;
}

int Grafo::saca()
{
    int aux;
    contp--;
    aux = lista[contp];
    lista[contp] = NULL;

    return aux;
}

void Grafo::recorrido(int ini, int fin, int x)
{
    bool band = false;
    for (int i = 0; i < contp; i++) {
        if (ini == lista[i]) {
            band = true;
        }
    }
    insertar(ini);
    if (!band) {
        if (ini == fin) {

            if (x < suma) {
                suma = x;
                for (int i = 0; i < 5; i++) {
                    listamayor[i] = -1;
                }
                //cout<<endl;
                for (int i = 0; i < contp; i++) {
                    listamayor[i] = lista[i];
                    //cout<<letra[listamayor[i]];
                    //cout<<listamayor[i];
                }
                //cout<<suma;
            }
        }
        else
        {
            for (int i = 0; i < 5; i++) {
                if (mat[ini][i] > 0) {
                    recorrido(i, fin, x + mat[ini][i]);
                }
            }
        }
    }
    saca();
}


void Grafo::dijkstra(int ini, int fin, int x) {
    recorrido(ini, fin, x);
    cout << endl << listamayor[1] << endl;
    for (int i = 0; i < 5; i++) {
        if (listamayor[i] >= 0) {
            cout << letra[listamayor[i]]<<"->";
        }
    }
    cout << endl;
    cout << "Peso: " << suma << endl;
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

void Grafo::setCoorx(int x) {
    this->coordenadax = x;
}

void Grafo::setCoory(int y) {
    this->coordenaday = y;
}

void Grafo::setRaiz(Grafo* raiz) {
    this->raiz = raiz;
}

void Grafo::sumaNombre() {
    this->nombreNodo = nombreNodo + 1;
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

int Grafo::getCoorx() {
    return coordenadax;
}

int Grafo::getCoory() {
    return coordenaday;
}

Grafo* Grafo::getRaiz() {
    return raiz;
}
