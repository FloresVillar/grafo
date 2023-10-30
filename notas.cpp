/*
class boruvka(grafo g){
    pvertice p= pGrafo;
    //buscar arista menor peso 
    float me;
    grafo aux;
    cout<<"dentro de boruka while externo"<<endl;
    while(p!=NULL){
        parista a,a_menor;
        a=p->arist;
        a_menor =a;
        while(a!=NULL){
            cout<<"inicio de while interno"<<"a_menor->peso:"<<a_menor->peso<<endl;
            cout<<"pesos de aristas"<<a->peso<<endl;
            if(a->sgteArista!=NULL){
                if(a->peso > a->sgteArista->peso){
                    a_menor=a->sgteArista;
                    cout<<"a_menor->peso:"<<a_menor->peso<<endl;
                    }
                a=a->sgteArista;
            }else {
                a=NULL;
            }   
        }//si datoOrigen es datoDestino de alguna arista de algun vertice  //entonces hay una arista en sentido contrario           
        pvertice pp;
        pp=p->sgteVertice;   
        while(pp!=NULL){
            cout<<"dentro de pp"<<endl;
            parista ar=pp->arist;
            while(ar!=NULL){
                cout<<pp->datoOrigen<<ar->datoDestino<<endl;
                if(ar->datoDestino==p->datoOrigen){
                    cout<<"ar->datoDestino == pp->datoOrigen"<<endl;
                    if(a_menor!=NULL && a_menor->peso > ar->peso){
                        a_menor= ar;
                        cout<<"a_menor->peso"<<a_menor->peso<<endl;
                    }
                }
                ar=ar->sgteArista;
            }
            pp=pp->sgteVertice;
        }
        // grafo auxiliar
        cout<<"fuera de pp"<<endl;
        if(a_menor!=NULL){ 
            //si el vertice ya existe
            cout<<"dentro de if aux"<<endl;
            if(aux.buscarPosV(p->datoOrigen)==NULL){
                cout<<"buscar pos de p->datoOrigen"<<endl;
                aux.insertarVertice(p->datoOrigen);
                cout<<"imprimiendo aux"<<endl;
                aux.imprimirGrafo();
                if(aux.buscarPosV(a_menor->datoDestino)==NULL){
                    aux.insertarVertice(a_menor->datoDestino);  
                    cout<<"imprimiendo aux"<<endl;
                    aux.imprimirGrafo();           
                }  
                aux.insertarArista(p->datoOrigen,a_menor->datoDestino,a_menor->peso);
                cout<<"imprimiendo aux"<<endl;
                aux.imprimirGrafo(); 
            }
            //si el vertice ya existe
        }
        cout<<"siguiente p"<<endl;
        p=p->sgteVertice;
        cout<<"dato"<<p->datoOrigen<<endl;
    }
    cout<<"imprimiendo grafo auxiliar"<<endl;
    aux.imprimirGrafo();
}
*/


/*  Pila pi;
    pi.insertar(1);
    pi.insertar(2);
    pi.insertar(3);
    cout<<"longitud"<<pi.n<<endl;
    pi.imprimir();
    cout<<"elemento de la pila"<<pi.extraer() <<endl;
    cout<<"longitud"<<pi.n<<endl;
    pi.imprimir();
    cout<<"elemento de la pila"<<pi.extraer() <<endl;
    cout<<"longitud"<<pi.n<<endl;
    pi.imprimir();*/
    /*Cola co;
    co.insertar(12);
    co.imprimir();
    co.insertar(11);
    co.imprimir();
    cout<<"tamaño"<<co.n<<endl;*/
    /*Lista li;
    li.insertar(12,1);
    li.imprimir();
    li.insertar(13,1);
    li.imprimir();
    li.insertar(15,2);
    li.imprimir();
    li.extraer(1);
    li.imprimir();
    li.extraer(2);
    li.imprimir();*/


    /*
    int k=l;
    Arista*aux;
    cout<<"elemento de tope"<<endl;
    cout<<tope->datoOrigen<<"-"<<tope->datoDestino<<" :"<<tope->peso<<endl;
    while(k>0){
        cout<<"extrayendo k: "<<k<<endl;
        aux=extraer();//ccorregir
        if(aux==nullptr){
            break;
        }
        cout<<aux->datoOrigen<<"-"<<aux->datoDestino<<" :"<<aux->peso<<endl;
        cout<<"luego de extraer lon()="<<lon();
        k--;
    }
    cout<<"tope es"<<tope<<"lon() es"<<lon()<<endl;
    imprimir();
    cout<<"arr ordenado *"<<endl;
    for(int i=0;i<l;i++){
        //arr[i]->anterior=nullptr;
        cout<<arr[i]->datoOrigen<<"-"<<arr[i]->datoDestino<<" :"<<arr[i]->peso<<endl;
    }
    cout<<"l es "<<l<<endl;
    for(int j=0;j<l;j++){
        Arista*a=arr[j];
        cout<<"arista a insertar"<<endl;
        cout<<a->datoOrigen<<"-"<<a->datoDestino<<" :"<<a->peso<<endl;
        insertar(a->datoOrigen,a->datoDestino,a->peso);
        cout<<"imprimiendo nueva pila"<<endl;
        imprimir();
    }*/
    /*
    int k=l;
    Arista*aux;
    cout<<"elemento de tope"<<endl;
    cout<<tope->datoOrigen<<"-"<<tope->datoDestino<<" :"<<tope->peso<<endl;
    while(k>0){
        cout<<"extrayendo k: "<<k<<endl;
        aux=extraer();//ccorregir
        if(aux==nullptr){
            break;
        }
        cout<<aux->datoOrigen<<"-"<<aux->datoDestino<<" :"<<aux->peso<<endl;
        cout<<"luego de extraer lon()="<<lon();
        k--;
    }
    cout<<"tope es"<<tope<<"lon() es"<<lon()<<endl;
    imprimir();
    cout<<"arr ordenado *"<<endl;
    for(int i=0;i<l;i++){
        //arr[i]->anterior=nullptr;
        cout<<arr[i]->datoOrigen<<"-"<<arr[i]->datoDestino<<" :"<<arr[i]->peso<<endl;
    }
    cout<<"l es "<<l<<endl;
    for(int j=0;j<l;j++){
        Arista*a=arr[j];
        cout<<"arista a insertar"<<endl;
        cout<<a->datoOrigen<<"-"<<a->datoDestino<<" :"<<a->peso<<endl;
        insertar(a->datoOrigen,a->datoDestino,a->peso);
        cout<<"imprimiendo nueva pila"<<endl;
        imprimir();
    }*/
    /*
    int k=l;
    Arista*aux;
    cout<<"elemento de tope"<<endl;
    cout<<tope->datoOrigen<<"-"<<tope->datoDestino<<" :"<<tope->peso<<endl;
    while(k>0){
        cout<<"extrayendo k: "<<k<<endl;
        aux=extraer();//ccorregir
        if(aux==nullptr){
            break;
        }
        cout<<aux->datoOrigen<<"-"<<aux->datoDestino<<" :"<<aux->peso<<endl;
        cout<<"luego de extraer lon()="<<lon();
        k--;
    }
    cout<<"tope es"<<tope<<"lon() es"<<lon()<<endl;
    imprimir();
    cout<<"arr ordenado *"<<endl;
    for(int i=0;i<l;i++){
        //arr[i]->anterior=nullptr;
        cout<<arr[i]->datoOrigen<<"-"<<arr[i]->datoDestino<<" :"<<arr[i]->peso<<endl;
    }
    cout<<"l es "<<l<<endl;
    for(int j=0;j<l;j++){
        Arista*a=arr[j];
        cout<<"arista a insertar"<<endl;
        cout<<a->datoOrigen<<"-"<<a->datoDestino<<" :"<<a->peso<<endl;
        insertar(a->datoOrigen,a->datoDestino,a->peso);
        cout<<"imprimiendo nueva pila"<<endl;
        imprimir();
    }*/

    /* g.imprimirGrafo();
    Pilag pg;
    pg.insertar(1,2,50);
    pg.imprimir();
    pg.insertar(2,3,50);
    pg.imprimir();
    Pilag pi_cero;
    pi_cero=g.ordenarPesosAristas(0);
    cout<<"aristas de 0 ordenados en pila ↓"<<endl;
    pi_cero.imprimir();
    g.imprimirGrafo();*/
    /*Pilap pila;
    pila.insertar(1,2,10);
    pila.imprimir();
    cout<<endl;
    pila.insertar(2,8,9);
    pila.imprimir();
    cout<<endl;
    pila.insertar(5,8,25);
    pila.imprimir();
    cout<<endl;
    pila.insertar(3,4,2);
    pila.imprimir();
    cout<<endl;
    pila.insertar(10,4,5);
    pila.imprimir();
    pila.ordenar();
    cout<<endl;
    pila.imprimir();
    cout<<endl;
    pila.insertar(8,3,10);
    pila.imprimir();
    cout<<endl;
    pila.ordenar();
    cout<<"luego de ordenar"<<endl;
    pila.imprimir();
    cout<<endl;
    pila.imprimir();
    cout<<endl;
    pila.insertar(1,3,13);
    pila.imprimir();
    cout<<endl;
    pila.ordenar();
    cout<<"luego de ordenar"<<endl;
    pila.imprimir();*/

     //g.borrarAristas(3);
    //g.imprimirGrafo();
    //g.ordenarPesosAristas(0);




    /*  switch (opcion){
    case 1:{
        int inicio;
        cout<<"ingresar vertice inicio"<<endl;
        cin>>inicio;
        Bfs bfs(g,inicio);
    }
    break;
    case 2:{
        Dfs obj(g);
    }
    break;
    case 3:{
        int a,b;
        cout<<"ingresar nodos a analizar"<<endl;
        cin>>a;     
        cin>>b;
        Camino cam(g,a,b);
        cout<<"existe camino de"<<a<<"- "<<b<<"?: 1:si  0:no "<<cam.flagg()<<endl;       
    }
    break;
    case 4:{
        Circuito cir(g);
        cout<<"existe algun ciclo? si:1   no:0 \t"<<cir.flag<<endl;
    }
    case 5:{
        Bicolorable bi(g);
        cout<<"es bicolorable? si:1   no:0 \t"<<bi.flag<<endl;
    }
    break;
    case 6:{
        int inicio;
        cout<<"ingresa el nodo de inicio"<<endl;
        cin>>inicio;
        Prim pri(g,inicio);
        pri.arbol.imprimirGrafo();       
    }
    default:
        break;
    }*/



    //borrador para lista de adyacencia
 /*   class grafo{ 
    private: pvertice pGrafo;
    int n;
    int ar;
    friend class Boruvka;
    friend class Kruskal;
    friend class Bfs;
    friend class Dfs;
    friend class Camino;
    friend class Circuito;
    friend class Bicolorable;
    friend class Prim;
    public: 
    int Ee();
    //vector<Arista*>arr;
    grafo();
    ~grafo(); 
    void insertarVertice(int); 
    void insertarArista(int,int,float peso); 
    void imprimirGrafo();
    float sumarPesos();
    int lon();
    pvertice buscarPosV(int);
    pvertice inicio();
    bool existeVertice(int);
    bool existeArista(int,int);
    parista existeAristap(int,int);
    int circuito();
    int circuito(int , int);
    int buscaCircuitoDfs(int,int,int*);
    //Pilag ordenarPesosAristas(int);
    //void borrarAristas(int);
    void imprimirAristas(int);
    //vector<Arista*> grafoAristas();
    //void dfs(int,int*,vector<Arista*>&a);
};    

grafo::grafo(){
     pGrafo = NULL; 
     n=0;
     ar=0;
}
int grafo::lon(){
    return n;
}
int grafo::Ee(){
    return ar;
}
grafo::~grafo(){ 
    pvertice p,rp; 
    parista r,ra; 
    p=pGrafo; 
    while(p!=NULL){
        r=p->arist; 
        while(r!=NULL){ 
            ra=r; 
            r=r->sgteArista; 
            delete ra; 
            }
        rp=p;
        p=p->sgteVertice;
        delete rp; }
}
void grafo::insertarVertice(int x){
     if(!existeVertice(x)){
     pvertice p,aux; 
     p=new vertice;
     n++;
     p->datoOrigen=x; 
     p->arist=NULL;
     if(pGrafo==NULL){ 
        p->sgteVertice=pGrafo; 
        pGrafo=p;
     }
     else{//
        aux=pGrafo;
        while(aux->sgteVertice!=NULL){
            aux=aux->sgteVertice;
        }
        aux->sgteVertice=p;
        p->sgteVertice=NULL;
     }
    }else{
        cout<<"ya existe ese vertice"<<endl;
    }
}
pvertice grafo::buscarPosV(int dato){
    pvertice p =pGrafo;
    if(p==NULL) {
        return NULL;
    }
    else{
        while(p!=NULL){
            if(p->datoOrigen==dato){
                return p;
            }
            p=p->sgteVertice;
        }
    }
    return NULL;
}
bool grafo::existeVertice(int r){
    pvertice p=pGrafo;
    while(p!=NULL){
        if(p->datoOrigen==r){
            return true;
        }
        p=p->sgteVertice;
    }
    return false;
}
bool grafo::existeArista(int r,int t){
    pvertice p=pGrafo;
    parista a;
    while(p!=NULL){
        a=p->arist;
        while(a!=NULL){
            if(a->datoDestino==t){
                return true;
            }
            a=a->sgteArista;
        }
        p=p->sgteVertice;
    }
    return false;
}
parista grafo::existeAristap(int r,int t){
    pvertice p=pGrafo;
    parista a;
    while(p!=NULL){
        a=p->arist;
        while(a!=NULL){
            if(a->datoDestino==t){
                return a;
            }
            a=a->sgteArista;
        }
        p=p->sgteVertice;
    }
    return nullptr;
}
void grafo::insertarArista(int x,int y,float peso){ 
    pvertice p,q; 
    parista a,b; 
    p=buscarPosV(x);
    q=buscarPosV(y);
    ar++;
    if(p!=nullptr &&q!=nullptr){ 
        a=new arista;
        a->datoOrigen=x;
        a->datoDestino=y;
        a->peso = peso;
        a->sgteArista=p->arist;
        a->vdest=q;
        p->arist=a;//se inserta mas a la izquierda?
        }
}
void grafo::imprimirGrafo(){
    pvertice p;
    parista a;
    p=pGrafo;
    if(p==NULL) {cout<<"Grafovacio"<<endl;}
    else{ 
        cout<<"vertice | aristas"<<endl;
        while(p!=NULL){
            cout<<"\t"<<p->datoOrigen<<"\t|";
            a=p->arist;
            while(a!=NULL){ 
                cout<<" "<<a->datoDestino<<" ";
                a=a->sgteArista; 
            } 
            cout<<endl;
            p=p->sgteVertice; 
        }
    } 
}
void grafo::imprimirAristas(int r){
    pvertice p=buscarPosV(r);
    parista a=p->arist;
    cout<<"origen"<<"\tdestino"<<"\tpeso\n";
    while(a!=NULL){ 
        cout<<"\t("<<a->datoOrigen<<")"<<" → "<<"("<<a->datoDestino<<")"<<"\t{"<<a->peso<<"}"<<"\n";
        a=a->sgteArista; 
    } 
    cout<<endl;
}*/

//notas de fw
/*cout<<"cantidad de datos="<<listAdy.n;
    ListArray dist;
    for(int i=0;i<listAdy.n;i++){
        dist.insertarNodo();
    }
    cout<<"dist";
    dist.imprimir();
    cout<<"posicion 1,5 dest[1,5] : "<<dist.obtener(1,5)<<"\n";
    ListArray cam;
    for(int i=0;i<listAdy.n;i++){
        cam.insertarNodo();
    }  
    cout<<"camino";
    cam.imprimir();
    //actualizar distancias con la info del digrafo
    Nodo*p=listAdy.primero;
    while(p!=nullptr){
        arista*a=p->aris;
        while(a!=nullptr){
            dist.obtener(a->datoOrigen,a->datoDestino)->peso=a->peso;
            a=a->sgteArista;
        }
        p=p->siguiente;
    }
    //listAdy.imprimir();
    cout<<"dist";
    dist.imprimir();
    //ahora inicializar listArray cam
    Nodo*pp=listAdy.primero;
    while(pp!=nullptr){
        arista*aa=pp->aris;
          while(aa!=nullptr){
            arista*adist=dist.obtener(aa->datoOrigen,aa->datoDestino);
            arista*acam=cam.obtener(aa->datoOrigen,aa->datoDestino);
            if(adist->peso<100000){
                acam->peso=aa->datoDestino;
            }
            aa=aa->sgteArista;
        }
        pp=pp->siguiente;
    }*/
    //fw funciona
    /*#include <iostream>
#include<vector>
using namespace std;
class arista{ 
    public:
    int datoOrigen;
    int datoDestino; 
    float peso;
    arista*sgteArista;
    friend class Nodo;
    friend class Lista;
    friend class ListArray;
    arista(int dor,int des,int pes){
        datoOrigen=dor;
        datoDestino=des;
        peso=pes;
        sgteArista=nullptr;
    }
};

class Nodo;
class Nodo{
    public:
    int dato;
    Nodo*siguiente;
    arista *aris;
    int peso;
    friend class Lista;
    friend class Fw;
    friend class ListArray;
    Nodo(int d){
        dato=d;
        siguiente=nullptr;
        aris=nullptr;
    }
    void insertarArista(int destino,int peso){
        arista*nuevo=new arista(dato,destino,peso);
        if(aris==nullptr){
            aris=nuevo;
        }else{
            arista*a=aris;
            while(a->sgteArista!=nullptr){
                a=a->sgteArista;
            }
            a->sgteArista=nuevo;
        }
    }
};

class Lista{
    public:
    Nodo* primero ;
    friend class FW;
    int n;
    Lista();
    ~Lista();
    bool vacia();
    void insertarInicio(int d);
    void insertarFinal(int d);
    void insertar(int d,int pos);
    void imprimir();
    int obtener(int pos);
    int extraer(int pos);
    Nodo*obtenerNodo(int dat);
    int obtenerPos(int);
};
Lista::Lista(){
    primero=nullptr;
    n=0;
}
bool Lista::vacia(){
    return primero==nullptr;
}

void Lista::insertarInicio(int dato){
    Nodo*nuevo=new Nodo(dato);
    if(primero==nullptr){
        primero=nuevo;
    }else{
        nuevo->siguiente=primero;
        primero=nuevo;
    }
    n++;
}

void Lista::insertarFinal(int dato){
    Nodo*nuevo=new Nodo(dato);
    if(vacia()){
        primero=nuevo;
    }else{
        Nodo*p=primero;
        while(p->siguiente!=nullptr){
            p=p->siguiente;
        }
        p->siguiente=nuevo;
    }
    n++;
}
void Lista::insertar(int dato,int pos){
    if(pos<1 || pos>n+1){
        cout<<"posicion invalida"<<endl;
    }
    else if(pos==1){
        insertarInicio(dato);
    }
    else if(pos==n+1){
        insertarFinal(dato);
    }
    else{
        Nodo*p=primero;
        int i=0;
        while(i!=pos-2){
            p=p->siguiente;
            i++;
        }
        Nodo*nuevo=new Nodo(dato);
        nuevo->siguiente=p->siguiente;
        p->siguiente=nuevo;
        n++;
    }
}
void Lista::imprimir(){
    Nodo*p=primero;
    while(p!=nullptr){
        cout<<p->dato<<"|";
        arista*a=p->aris;
        while(a!=nullptr){
            cout<<""<<a->datoDestino<<"{"<<a->peso<<"}";
            a=a->sgteArista;
        }
        cout<<endl;
        p=p->siguiente;
    }
    cout<<endl;
}
int Lista::obtener(int pos){
    if(pos<1 || pos>n){
        cout<<"posicion invalida"<<endl;
    }else{
        int i=0;
        Nodo*p=primero;
        while(i!=pos-1){
            p=p->siguiente;
            i++;
        }
        return p->dato;
    }
    return -1;
}
int Lista::obtenerPos(int dat){
    Nodo*p=primero;
    int i=0;
    while(p!=nullptr){
        i++;
        if(p->dato==dat){
            return i;
        }
        p=p->siguiente;
    }
    return -1;
        
}
Nodo*Lista::obtenerNodo(int dat){
    Nodo*p=primero;
    while(p!=nullptr){
        if(p->dato==dat){
            return p;
        }
        p=p->siguiente;
    }
    cout<<"no existe tal nodo";
    return nullptr;
}
int Lista::extraer(int pos){
    if(pos<1 || pos>n){
        cout<<"posicion invalida"<<endl;
    }else if(pos==1){
        Nodo*p=primero;
        primero=primero->siguiente;
        int dat=p->dato;
        delete p;
        n--;
        return dat; 
    }else{
        int i=0;
        Nodo*p=primero;
        while(i!=pos-2){
            p=p->siguiente;
            i++;
        }
        Nodo*a=p->siguiente;
        int dat=a->dato;
        p->siguiente=a->siguiente;
        delete a;
        n--;
        return dat;        
    }
    return -1;
}

Lista::~Lista(){
    Nodo*p=primero;
    Nodo*a;
    while(p!=nullptr){
        a=p;    
        p=p->siguiente;
        delete a;
    }
}


class ListArray{
    public:
    Nodo*primer;
    int n;
    ListArray();
    void insertarNodo();
    void imprimir();
    arista* obtener(int,int);
    Nodo*obtenerFila(int);
};
ListArray::ListArray(){
    primer=nullptr;
    n=0;
}
void ListArray::insertarNodo(){
    if(primer==nullptr){//idexacion desde 0 pero no al momento de imprimir se suma 1
        Nodo*nuevo=new Nodo(0);
        primer=nuevo;
        primer->insertarArista(n,100000);
        n++;
    }else{
        Nodo*p=primer;
        while(p!=nullptr){
            p->insertarArista(n,100000);
            p=p->siguiente;
        }
        Nodo*nuevo=new Nodo(n);
        for(int i=0;i<=n;i++){
            nuevo->insertarArista(i,100000);
        }
        Nodo*pp=primer;
        while(pp->siguiente!=nullptr){
            pp=pp->siguiente;
        }
        pp->siguiente=nuevo;
        n++;
    }
}
void ListArray::imprimir(){
    Nodo*p=primer;
    cout<<endl;
    while(p!=nullptr){
        cout<<""<<p->dato+1<<"|";
        arista*a=p->aris;
        while(a!=nullptr){
            cout<<""<<a->datoDestino+1<<"{"<<a->peso<<"}\t";
            a=a->sgteArista;
        }
        cout<<endl;
        p=p->siguiente;
    }
}
arista* ListArray::obtener(int i,int j){
    if(i-1>=n || j-1>=n){
        cout<<"posiciones incorrectas"<<endl;
        return nullptr;
    }
    Nodo*p=primer;
    while(p!=nullptr){
        if(p->dato==i-1){
            arista*a=p->aris;
            while(a!=nullptr){
            if(a->datoDestino==j-1){
                return a;
            }
            a=a->sgteArista;
            }
        }
        p=p->siguiente;
    }
    return nullptr;
}
Nodo* ListArray::obtenerFila(int i){
    Nodo*p=primer;
    while(p!=nullptr){
        if(p->dato==i-1){
            return p;
        }
        p=p->siguiente;
    }
    return p;
}

class FW{
    public:
    Lista listAdy;
    ListArray dist;
    ListArray cam;
    FW(Lista);
    void fw(ListArray& dist,ListArray& cam);
    void iniciarDist(ListArray& dist);
    void iniciarCam(ListArray& cam);
    void actualizarDist(ListArray& dist);
    void actualizarCam(ListArray& cam);
};
FW::FW(Lista list ){
    listAdy=list;
    iniciarDist(dist);
    iniciarCam(cam);
    actualizarDist(dist);
    actualizarCam(cam);
    fw(dist,cam);
}

void FW::iniciarDist(ListArray& dist){
    for(int i=0;i<listAdy.n;i++){
        dist.insertarNodo();
    }
}
void FW::iniciarCam(ListArray& cam){
    for(int i=0;i<listAdy.n;i++){
        cam.insertarNodo();
    }
}
void FW::actualizarDist(ListArray& dist){
    Nodo*p=listAdy.primero;
    while(p!=nullptr){
        arista*a=p->aris;
        while(a!=nullptr){
            dist.obtener(a->datoOrigen,a->datoDestino)->peso=a->peso;
            a=a->sgteArista;
        }
        p=p->siguiente;
    }
    cout<<"imprimiendo dist";
    dist.imprimir();
}

void FW::actualizarCam(ListArray& cam){
    Nodo*p=listAdy.primero;
    while(p!=nullptr){
        arista*a=p->aris;
          while(a!=nullptr){
            arista*adist=dist.obtener(a->datoOrigen,a->datoDestino);
            arista*acam=cam.obtener(a->datoOrigen,a->datoDestino);
            if(adist->peso<100000){
                acam->peso=a->datoDestino;
            }
            a=a->sgteArista;
        }
        p=p->siguiente;
    }
    cout<<"imprimiendo cam";
    cam.imprimir();
}
void FW::fw(ListArray& dist,ListArray& cam){
    for(int k=1;k<=listAdy.n;k++){
        Nodo*p=dist.primer;
        while(p!=nullptr){
        arista*ar=p->aris;
        while(ar!=nullptr){
            arista*dist1=dist.obtener(ar->datoOrigen+1,k);
            arista*dist2=dist.obtener(k,ar->datoDestino+1);
            int d=dist1->peso+dist2->peso;
            //cout<<"d:"<<d<<endl;
            if(d<dist.obtener(ar->datoOrigen+1,ar->datoDestino+1)->peso){
                cam.obtener(ar->datoOrigen+1,ar->datoDestino+1)->peso=cam.obtener(ar->datoOrigen+1,k)->peso;
                dist.obtener(ar->datoOrigen+1,ar->datoDestino+1)->peso=d;
            }
            ar=ar->sgteArista;  
        }
        p=p->siguiente;       
        }
    } 
}
int main(){
    Lista listAdy;
    listAdy.insertarInicio(1);
    listAdy.insertarFinal(2);
    listAdy.insertarFinal(3);
    listAdy.insertarFinal(4);
    listAdy.obtenerNodo(1)->insertarArista(2,8);
    listAdy.obtenerNodo(2)->insertarArista(1,6);
    listAdy.obtenerNodo(1)->insertarArista(3,-1);
    listAdy.obtenerNodo(3)->insertarArista(2,5);
    listAdy.obtenerNodo(2)->insertarArista(4,5);
    listAdy.obtenerNodo(4)->insertarArista(3,2);
    listAdy.obtenerNodo(4)->insertarArista(2,3);
    listAdy.imprimir();
    FW prueba(listAdy);
    cout<<"bigrafo"<<endl;
    prueba.listAdy.imprimir();  
    cout<<"dist"<<endl;
    prueba.dist.imprimir();
    cout<<"cam"<<endl;
    prueba.cam.imprimir();
     
}*/