#include <iostream>
#include<vector>
using namespace std;
/*void busProf(grafo g,int*pre);
void dfs (grafo g,pvertice v,int *pr);*/
class Nodopi{
    int dato;
    Nodopi * anterior;
    friend class Pila;
    friend class grafo;
    friend class Lista;
    friend class Kruskal;
    public:
    Nodopi(int d){
        dato= d;
    }
};
class Pila{
    Nodopi *tope;
    friend class Dfs;
    friend class grafo;
    friend class Kruskal;
    public:
    int n;
    Pila();
    ~Pila();
    bool vacia();
    int obtenerTope();
    void insertar(int);
    int extraer();
    void imprimir();
};

Pila::Pila(){
    tope=NULL;
    n=0;
}

bool Pila::vacia(){
    return tope==NULL;
}

int Pila::obtenerTope(){
    if(vacia()){
        return -1;
    }
    return tope->dato;
}

void Pila::insertar(int x){
    Nodopi *nuevo=new Nodopi(x);
    if(vacia()){
        nuevo->anterior=NULL;
        tope=nuevo;
        n=1;
    }else{
        nuevo->anterior=tope;
        tope=nuevo;
        n++;
    }
}

int Pila::extraer(){
    if(vacia()){
        return -1;
    }else{
        Nodopi*aux=tope;
        tope=aux->anterior;
        int i=aux->dato;
        delete aux;
        n--;
        return i; 
    }
}

void Pila::imprimir(){
    Nodopi*p = tope;
    while(p!=NULL){
        cout<<p->dato<<endl;
        p=p->anterior;
    }
}

Pila::~Pila(){
    Nodopi*p=tope;
    while(p!=NULL){
        Nodopi*a=p;//solo copia 
        p=p->anterior;
        delete a;
    }
}
class Cola;
class Nodo;
class Nodo1{
    int dato;
    Nodo1*siguiente;
    friend class Cola;
    friend class Colabfs;
    friend class Lista;
    friend class Boruvka;
    public:
    Nodo1(int d){
        dato=d;
        siguiente=NULL;
    }
};
class Lista{
    Nodo1* primero ;
    friend class Kruskal;
    friend class grafo;
    friend class Boruvka;
    public:
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
};
Lista::Lista(){
    primero=NULL;
    n=0;
}
bool Lista::vacia(){
    return primero==NULL;
}

void Lista::insertarInicio(int d){
    Nodo1*nuevo=new Nodo1(d);
    if(primero==NULL){
        primero=nuevo;
    }else{
        nuevo->siguiente=primero;
        primero=nuevo;
    }
    n++;
}

void Lista::insertarFinal(int d){
    Nodo1*nuevo=new Nodo1(d);
    if(vacia()){
        primero=nuevo;
    }else{
        Nodo1*p=primero;
        while(p->siguiente!=NULL){
            p=p->siguiente;
        }
        p->siguiente=nuevo;
    }
    n++;
}
void Lista::insertar(int d,int pos){
    if(pos<1 || pos>n+1){
        cout<<"posicion invalida"<<endl;
    }
    else if(pos==1){
        insertarInicio(d);
    }
    else if(pos==n+1){
        insertarFinal(d);
    }
    else{
        Nodo1*p=primero;
        int i=0;
        while(i!=pos-2){
            p=p->siguiente;
            i++;
        }
        Nodo1*nuevo=new Nodo1(d);
        nuevo->siguiente=p->siguiente;
        p->siguiente=nuevo;
        n++;
    }
}
void Lista::imprimir(){
    Nodo1*p=primero;
    while(p!=NULL){
        cout<<p->dato<<"\t";
        p=p->siguiente;
    }
    cout<<endl;
}
int Lista::obtener(int pos){
    if(pos<1 || pos>n){
        cout<<"posicion invalida"<<endl;
    }else{
        int i=0;
        Nodo1*p=primero;
        while(i!=pos-1){
            p=p->siguiente;
            i++;
        }
        return p->dato;
    }
    return -1;
}
int Lista::extraer(int pos){
    if(pos<1 || pos>n){
        cout<<"posicion invalida"<<endl;
    }else if(pos==1){
        Nodo1*p=primero;
        primero=primero->siguiente;
        int dat=p->dato;
        delete p;
        n--;
        return dat; 
    }else{
        int i=0;
        Nodo1*p=primero;
        while(i!=pos-2){
            p=p->siguiente;
            i++;
        }
        Nodo1*a=p->siguiente;
        int dat=a->dato;
        p->siguiente=a->siguiente;
        delete a;
        n--;
        return dat;        
    }
    return -1;
}

Lista::~Lista(){
    Nodo1*p=primero;
    Nodo1*a;
    while(p!=NULL){
        a=p;    
        p=p->siguiente;
        delete a;
    }
}
struct vertice;
struct arista{ 
    int datoOrigen;
    int datoDestino; 
    float peso;
    arista*sgteArista;
    vertice*vdest; 
}; typedef arista*parista;


struct vertice{ 
    int datoOrigen; 
    arista*arist;  
    vertice*sgteVertice; 

}; typedef vertice*pvertice;

class Arista;
class Pilag;
class Pilap;

class grafo{ 
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
    vector<Arista*>arr;
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
    Pilag ordenarPesosAristas(int);
    //void borrarAristas(int);
    void imprimirAristas(int);
    vector<Arista*> grafoAristas();
    void dfs(int,int*,vector<Arista*>&a);
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
    if(p!=NULL&&q!=NULL){ 
        a=new arista;
        a->datoOrigen=x;
        a->datoDestino=y;
        a->peso = peso;
        a->sgteArista=p->arist;
        a->vdest=q;
        p->arist=a;//se inserta mas a la izquierda
        b=new arista;
        b->datoOrigen=y;
        b->datoDestino=x;
        b->peso = peso;
        b->sgteArista=q->arist;
        b->vdest=p;
        q->arist=b;
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
    cout<<"\t"<<p->datoOrigen<<"\t|";
    while(a!=NULL){ 
        cout<<" "<<a->datoDestino<<" ";
        a=a->sgteArista; 
    } 
    cout<<endl;
}
class Arista{ 
    public:
    int datoOrigen;
    int datoDestino; 
    int peso;
    friend class Pilag;
    friend class Pilap;
    friend class Prim;
    friend class grafo;
    friend class Boruvka;
    friend class Kruskal;
    Arista*anterior;
    Arista(int o,int d,int pes){
        datoOrigen=o;
        datoDestino=d;
        peso=pes;
        anterior=NULL;
    }
}; 
vector<Arista*> grafo::grafoAristas(){
    int n=lon();
    int pr[n];
    for(int i=0;i<n;i++){
        pr[i]=-1;
    }
    for(int v=0;v<n;v++){
        cout<<"\nvertice : "<<v;
        if(pr[v]==-1){
            dfs(v,pr,arr);
        }
    }
    cout<<endl;
    return arr;
}
void grafo::dfs(int v,int*visit,vector<Arista*>&arr){
        cout<<" dfs\n";
        visit[v]++;
        for(int i=0;i<n;i++){
            cout<<visit[i]<<"\t";
        }
        cout<<endl;
        parista w;
        pvertice vv=buscarPosV(v);
        w=vv->arist;
        imprimirAristas(vv->datoOrigen);
        while(w!=NULL){
            int dato=w->datoDestino;
            if(visit[dato]==-1){
                cout<<"arista "<<w->datoOrigen<<"-"<<w->datoDestino;
                arr.push_back(new Arista(w->datoOrigen,w->datoDestino,w->peso));
                dfs(dato,visit,arr);
            }
            w=w->sgteArista;
        }
}    
pvertice grafo::inicio(){
    return pGrafo;
}

float grafo::sumarPesos(){
    pvertice p= pGrafo;
    parista i;
    float suma=0;
    if(p!=NULL){
        while(p!=NULL){
            i=p->arist;
            while(i!=NULL){
                suma+=i->peso;
                //analizando la arista ←
                pvertice pp=pGrafo;
                while(pp!=p){ //para cada vertice anterior
                    if(i->vdest==pp){
                        parista j=pp->arist;//para cada arista de cada vertice anterior
                        while(j!=NULL){
                            if(j->vdest==p){
                                suma-=j->peso;        
                            }   
                            j=j->sgteArista;
                        }
                    }        
                    pp=pp->sgteVertice;
                }
                i=i->sgteArista;
            }
            p=p->sgteVertice;
        }
    }
    return suma;
}
int grafo::circuito(){
        int flag=0;
        cout<<"dentro de busqueda"<<endl;
        int visit[n];
        for(int i=0;i<n;i++){
            visit[i]=-1;
        }
        for(int i=0;i<n;i++){
            cout<<visit[i]<<"\t";
        }
        for(int v=0;v<n;v++){
            cout<<"posicion : "<<v<<endl;
            if(visit[v]==-1){
                flag=buscaCircuitoDfs(v,v,visit);
            }
            if(flag==1){
                break;
            }
        }
        return flag;
}
int grafo::circuito(int a,int b){
        if(pGrafo==nullptr){
            return 0;
        }
        int flag=0;
        cout<<"dentro de busqueda"<<endl;
        n=lon();
        int visit[n];
        for(int i=0;i<n;i++){
            visit[i]=-1;
        }
        for(int i=0;i<n;i++){
            cout<<visit[i]<<"\t";
        }
        //cout<<"posicion : "<<v<<endl;
        flag=buscaCircuitoDfs(a,b,visit);
        return flag;
}
int grafo::buscaCircuitoDfs(int inicio,int fin,int*pre){
        cout<<"dentro de busquedaCircuito"<<endl;
        pre[inicio]++;
        for(int i=0;i<n;i++){
            cout<<pre[i]<<"\t";
        }
        cout<<endl;
        parista w;
        pvertice vv=buscarPosV(inicio);
        w=vv->arist;
        while(w!=NULL){
            cout<<"vertice"<<w->datoOrigen<<"\t";
            int destino=w->datoDestino;
            if(pre[destino]==-1){
                cout<<"arista"<<w->datoOrigen<<"-"<<w->datoDestino;
                int p=buscaCircuitoDfs(destino,inicio,pre);
                if(p==1){return 1;}
            }else{
                if(fin==destino){
                    return 1;
                }
            }
            w=w->sgteArista;
        }
        return 0;
}

class Pilap{
    public:
    Arista* tope;
    friend class Dfs;
    friend class grafo;
    friend class Prim;
    int n;
    Pilap();
    ~Pilap();
    bool vacia();
    void insertar(int,int,int);
    void ordenar();
    Arista* obtenerTope();
    Arista* extraer();
    void imprimir();
    int lon();
};
Pilap::Pilap(){
    tope=nullptr;
    n=0;
}
int Pilap::lon(){
    return n;
}
bool Pilap::vacia(){
    return tope==nullptr;
}

Arista* Pilap::obtenerTope(){
    if(vacia()){
        return nullptr;
    }
    return tope;
}

void Pilap::insertar(int o,int d,int peso){
    Arista *nuevo=new Arista(o,d,peso);
    if(vacia()){
        nuevo->anterior=nullptr;
        tope=nuevo;
        n++;
    }else{
        nuevo->anterior=tope;
        tope=nuevo;
        n++;
    }
}
    //ordenar
void Pilap::ordenar() {
    cout<<"\ndentro de ordenar Pilap"<<endl;
    Arista*p=tope;
    int l=lon();
    Arista* arr[l];
    int i=0;
    while(p!=nullptr){
        arr[i]=p;
        p=p->anterior;
        i++;
    }
    cout<<"arr de Arista*"<<endl;
    for(int i=0;i<l;i++){
        //arr[i]->anterior=nullptr;
        cout<<arr[i]->datoOrigen<<"-"<<arr[i]->datoDestino<<" :"<<arr[i]->peso<<endl;
    }
    for(int i=l;i>0;i--){
        for(int j=0;j<i-1;j++){
            if(arr[j]->peso>arr[j+1]->peso){//intercambiar
                Arista*aux=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=aux;
            }
        }
    }
    arr[0]->anterior=arr[1];
    tope=arr[0];
    for(int i=1;i<l-1;i++){
        arr[i]->anterior=arr[i+1];
    }
    arr[l-1]->anterior=nullptr;
}
Arista* Pilap::extraer(){
    if(vacia()){
        return nullptr;
    }else{
        n--;
        Arista*aux=tope;//revisar
        tope=tope->anterior;
        int origen=aux->datoOrigen;
        int destino=aux->datoDestino;
        float peso=aux->peso;
        delete (aux);
        return new Arista(origen,destino,peso); 
    }
}

void Pilap::imprimir(){
    Arista*p = tope;
    while(p!=NULL){
        cout<<p->datoOrigen<<"-"<<p->datoDestino<<" :"<<p->peso<<endl;
        p=p->anterior;
    }
}

Pilap::~Pilap(){
    Arista*p=tope;
    while(p!=NULL){
        Arista*a=p;//solo copia 
        p=p->anterior;
        delete a;
    }
}
class Pilag{
    public:
    Arista* tope;
    friend class Dfs;
    friend class grafo;
    friend class Prim;
    int n;
    Pilag();
    ~Pilag();
    bool vacia();
    void insertar(int,int,int);
    Arista* obtenerTope();
    Arista* extraer();
    void imprimir();
};

Pilag::Pilag(){
    tope=NULL;
    n=0;
}

bool Pilag::vacia(){
    return tope==NULL;
}

Arista* Pilag::obtenerTope(){
    if(vacia()){
        return NULL;
    }
    return tope;
}

void Pilag::insertar(int o,int d,int peso){
    Arista *nuevo=new Arista(o,d,peso);
    if(vacia()){
        nuevo->anterior=NULL;
        tope=nuevo;
        n++;
    }else{
        nuevo->anterior=tope;
        tope=nuevo;
        n++;
    }
}

Arista* Pilag::extraer(){
    if(vacia()){
        return NULL;
    }else{
        Arista*aux=tope;
        tope=aux->anterior;
        int origen=aux->datoOrigen;
        int destino=aux->datoDestino;
        float peso=aux->peso;
        delete aux;
        n--;
        return new Arista(origen,destino,peso); 
    }
}

void Pilag::imprimir(){
    Arista*p = tope;
    while(p!=NULL){
        cout<<p->datoOrigen<<"-"<<p->datoDestino<<" :"<<p->peso<<endl;
        p=p->anterior;
    }
}

Pilag::~Pilag(){
    Arista*p=tope;
    while(p!=NULL){
        Arista*a=p;//solo copia 
        p=p->anterior;
        delete a;
    }
}

Pilag grafo::ordenarPesosAristas(int r){
    cout<<"dentro de ordenarPesosAristas"<<endl;
    pvertice p=buscarPosV(r);
    parista a=p->arist;
    int m=0;
    while(a!=NULL){
        a=a->sgteArista;
        m++;
    }
    parista arr[m];
    a=p->arist;
    int i=0;
    while(a!=NULL){
        arr[i]=a;
        a=a->sgteArista;
        i++;
    }
    for(int i=m;i>0;i--){
        for(int j=0;j<i-1;j++){
            if(arr[j]->peso>arr[j+1]->peso){//intercambiar
                parista aux=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=aux;
            }
        }
    }
    cout<<"imprimiendo pesos de aristas"<<endl;
    for(int j=0;j<m;j++){
        cout<<arr[j]->datoOrigen<<"-"<<arr[j]->datoDestino<<" "<<arr[j]->peso<<endl;
    }
    Pilag pi;
    //asignar las nuevas aristas
    for(int i=m-1;i>=0;i--){
        pi.insertar(arr[i]->datoOrigen,arr[i]->datoDestino,arr[i]->peso);
    }
    return pi;
}

class Camino{
    grafo gr;
    int n;
    int flag;
    public:
    Camino(grafo g,int v,int w){
    cout<<"constructor camino"<<endl;
    gr=g;
    flag=false;
    n=gr.lon();
    busqueda(v,w);
    }
    void busqueda(int,int);
    int buscaCamino(int ,int,int*);
    int flagg(){
        return flag;
    }
};

void Camino::busqueda(int v,int w){   
    int visit[n];
    for(int i=0;i<n;i++){
        visit[i]=-1;
    }
    flag=buscaCamino(v,w,visit);
}

int Camino::buscaCamino(int v,int w,int*visit){
    pvertice vv=gr.buscarPosV(v);
    pvertice ww=gr.buscarPosV(w);
    cout<<"t :"<<v<<" w:"<<w<<endl;
    if(v==w){
        return 1;
    }
    visit[v]++;
    for(int i=0;i<n;i++){
        cout<<visit[i]<<"\t";
    }
    cout<<endl;
    parista a=vv->arist;
    while(a!=NULL){
        int t=a->datoDestino;
        if(visit[t]==-1){
            cout<<"arista: "<<v<<"-"<<t<<"\t";
            int p=buscaCamino(t,w,visit);
            if(p==1){
                return p;
            }
        }
        a=a->sgteArista;        
    }
    return 0;
}
class Colabfs{
    Nodo1*frente;
    Nodo1*fin;
    friend class grafo;
    friend class Boruvka;
    public:
    int n;
    Colabfs();
    ~Colabfs();
    bool vacia();
    int lon();
    void insertar(int d);
    int extraer();
    void imprimir();
};
Colabfs::Colabfs(){
    frente =NULL;
    fin=NULL;
    n=0;
}
bool Colabfs::vacia(){
    return n==0;
}

Colabfs::~Colabfs(){
    Nodo1*p=frente;
    while(p!=NULL){
        Nodo1*a=p;
        p=p->siguiente;
        delete a;
    }
}

void Colabfs::insertar(int d){
    Nodo1*nuevo=new Nodo1(d);
    if(frente==NULL){
        frente=nuevo;
        fin=nuevo;
    }else{
        fin->siguiente=nuevo;
        fin=nuevo;
    }
    n++;
}
int Colabfs::extraer(){
    if(!vacia()){
        Nodo1*aux=frente;
        int dat=aux->dato;
        frente=frente->siguiente;
        delete aux;
        n--;
        return dat;
    }
    return -1;
}
void Colabfs::imprimir(){
    Nodo1*p=frente;
    while(p!=NULL){
        cout<<p->dato<<"\t";
        p=p->siguiente; 
    }
    cout<<endl;
}
class Bfs{
    public:
    Bfs(grafo g,int r){
        cout<<"BFS"<<endl;
        Colabfs cola;
        int n=g.lon();
        int ord[n];
        for(int i=0;i<n;i++){
            ord[i]=-1;
        }
        for(int i=0;i<n;i++){
            cout<<ord[i]<<" ";
        }
        cout<<endl;
        cola.insertar(r);
        cout<<"cola :";
        cola.imprimir();
        while(!cola.vacia()){
            int v=cola.extraer();
            cout<<"vertice extraido de cola: "<<v<<endl;
            ord[v]++;
            for(int i=0;i<n;i++){
            cout<<ord[i]<<" ";
            }
            cout<<endl;
            pvertice w=g.buscarPosV(v);
            g.imprimirAristas(w->datoOrigen);
            parista a=w->arist;
            while(a!=NULL){
                int w=a->datoDestino;
                if(ord[w]==-1){
                    cout<<v<<"←→"<<w<<"\t";
                    ord[w]++;
                    for(int i=0;i<n;i++){
                        cout<<ord[i]<<" ";
                    }
                    cola.insertar(w);
                    cout<<"\tcola :";
                    cola.imprimir();
                } 
                a=a->sgteArista;   
                }
            cout<<endl;
        }
    }
};

class Dfs{
    public:
    int n;
    grafo gr;
    void busqueda();  
    void dfs(int,int*);
    Dfs(grafo g){
    gr=g;
    n=g.lon();
    gr.imprimirGrafo();
    busqueda();
    cout<<endl;
    }
};

void Dfs::busqueda(){
    int pr[n];
    for(int i=0;i<n;i++){
        pr[i]=-1;
    }
    cout<<"visit :";
    for(int i=0;i<n;i++){
        cout<<pr[i]<<"\t";
    }
    for(int v=0;v<n;v++){
        cout<<"\nvertice : "<<v;
        if(pr[v]==-1){
            dfs(v,pr);
        }
    }
    cout<<endl;
}
void Dfs::dfs(int v,int*visit){
        cout<<" dfs\n";
        visit[v]=visit[v]+1;
        for(int i=0;i<n;i++){
            cout<<visit[i]<<"\t";
        }
        cout<<endl;
        parista w;
        pvertice vv=gr.buscarPosV(v);
        w=vv->arist;
        gr.imprimirAristas(vv->datoOrigen);
        while(w!=NULL){
            int dato=w->datoDestino;
            if(visit[dato]==-1){
                cout<<"arista "<<w->datoOrigen<<"-"<<w->datoDestino;
                dfs(dato,visit);
            }
            w=w->sgteArista;
        }
}    

class Circuito{
    public:
    int n;
    grafo gr;
    int flag;
    Circuito(grafo g){
        gr=g;
        n=g.lon();
        gr.imprimirGrafo();
        busqueda();
    }
    void busqueda();  
    int buscaCircuitoDfs(int,int,int*);
};

void Circuito::busqueda(){
        int visit[n];
        for(int i=0;i<n;i++){
            visit[i]=-1;
        }
        for(int i=0;i<n;i++){
            cout<<visit[i]<<"\t";
        }
        for(int v=0;v<n;v++){
            cout<<"\nvertice : "<<v;
            if(visit[v]==-1){
                flag=buscaCircuitoDfs(v,v,visit);
            }
            if(flag==1){
                break;
            }
        }
}
int Circuito::buscaCircuitoDfs(int v,int padrev,int*pre){
        cout<<" dfs\n";
        pre[v]++;
        for(int i=0;i<n;i++){
            cout<<pre[i]<<"\t";
        }
        cout<<endl;
        parista w;
        pvertice vv=gr.buscarPosV(v);
        w=vv->arist;
        gr.imprimirAristas(vv->datoOrigen);
        while(w!=NULL){
            //cout<<"vertice"<<w->datoOrigen<<"\t";
            int dato=w->datoDestino;
            if(pre[dato]==-1){
                cout<<"arista"<<w->datoOrigen<<"-"<<w->datoDestino;
                int p=buscaCircuitoDfs(dato,v,pre);
                if(p==1){return 1;}
            }else{
                if(padrev==dato){
                    return 1;
                }
            }
            w=w->sgteArista;
        }
        return 0;
}

class Bicolorable{
    public:
    int n;
    grafo gr;
    int flag=0;
    Bicolorable(grafo g){
        gr=g;
        n=g.lon();
        gr.imprimirGrafo();
        busqueda();
    }
    void busqueda();  
    int dfsColor(int,int,int*);
};

void Bicolorable::busqueda(){
        int color[n];
        for(int i=0;i<n;i++){
            color[i]=-1;
        }
        for(int i=0;i<n;i++){
            cout<<color[i]<<"\t";
        }
        for(int v=0;v<n;v++){
            cout<<"\nvertice : "<<v;
            if(color[v]==-1){
                flag=dfsColor(v,0,color);
            }
            if(flag==0){
                break;
            }
        }
}
int Bicolorable::dfsColor(int v,int color,int*visit){
        cout<<" dfs\n";
        visit[v]=color;
        for(int i=0;i<n;i++){
            cout<<visit[i]<<"\t";
        }
        cout<<endl;
        parista w;
        pvertice vv=gr.buscarPosV(v);
        w=vv->arist;
        gr.imprimirAristas(vv->datoOrigen);
        while(w!=NULL){
            cout<<"vertice"<<w->datoOrigen<<"\tcolor:"<<color<<endl;
            int dato=w->datoDestino;
            if(visit[dato]==-1){
                cout<<w->datoOrigen<<"←→"<<w->datoDestino;
                if(!dfsColor(dato,1-color,visit)){
                        return 0;
                }
            }else{
                if(visit[dato]==color){
                    return 0;
                }
            }
            w=w->sgteArista;
        }
        return 1;
}

class Prim{
    public:
    grafo gr,arbol;
    Pilap pila;
    Prim(grafo g,int r);
    void prim(int);
    void procesar(int,int*);
};
Prim::Prim(grafo g,int r){
    gr=g;
    prim(r);
}
void Prim::prim(int r){
    int n=gr.lon();
    int en_arbol[n];
    for(int i=0;i<n;i++){
        en_arbol[i]=-1;
    }
    Arista*aris;
    procesar(r,en_arbol);
    while(!pila.vacia()){
        aris=pila.extraer();
        if(en_arbol[aris->datoDestino]==-1){
            arbol.insertarVertice(aris->datoOrigen);
            arbol.insertarVertice(aris->datoDestino);
            arbol.insertarArista(aris->datoOrigen,aris->datoDestino,aris->peso);
            cout<<"el arbol es"<<endl;
            arbol.imprimirGrafo();
            procesar(aris->datoDestino,en_arbol);
        }
    }

}

void Prim::procesar(int r,int*pr){
     pr[r]++;
     for(int i=0;i<gr.lon();i++){
        cout<<pr[i]<<"\t";
    }
    cout<<endl;
     pvertice p=gr.buscarPosV(r);
     parista a=p->arist;
     gr.imprimirAristas(r);
     while(a!=NULL){
        int v=a->datoDestino;
        if(pr[v]==-1){
            //insertar pila* de prioridad
            pila.insertar(a->datoOrigen,a->datoDestino,a->peso);
            pila.ordenar();
            cout<<"pila hasta el momento es "<<endl;
            pila.imprimir(); 
        }
        a=a->sgteArista;
     }
}
class Nodo{
    public:
    int rango;
    int padre;
    Nodo*siguiente;
    friend class Cola;
    friend class Lista;
    friend class Colab;
    friend class Boruvka;
    Nodo(int rang,int padr){
        rango =rang;
        padre=padr;
        siguiente=NULL;
    }
};
class Colab{
    Nodo*frente;
    Nodo*fin;
    friend class grafo;
    friend class Boruvka;
    public:
    int n;
    Colab();
    ~Colab();
    bool vacia();
    int lon();
    void insertar(int d,int p);
    Nodo* extraer();
    void imprimir();
};
Colab::Colab(){
    frente =NULL;
    fin=NULL;
    n=0;
}
bool Colab::vacia(){
    return n==0;
}

Colab::~Colab(){
    Nodo*p=frente;
    while(p!=NULL){
        Nodo*a=p;
        p=p->siguiente;
        delete a;
    }
}

void Colab::insertar(int d,int p){
    Nodo*nuevo=new Nodo(d,p);
    if(frente==NULL){
        frente=nuevo;
        fin=nuevo;
    }else{
        fin->siguiente=nuevo;
        fin=nuevo;
    }
    n++;
}
Nodo* Colab::extraer(){
    if(!vacia()){
        Nodo*aux=frente;
        int rango=aux->rango;
        int padre=aux->padre;
        frente=frente->siguiente;
        delete aux;
        n--;
        return new Nodo(rango,padre);
    }
    return nullptr;
}
void Colab::imprimir(){
    Nodo*p=frente;
    while(p!=NULL){
        cout<<p->rango<<"<->"<<p->padre;
        p=p->siguiente; 
    }
    cout<<endl;
}
/*
class Boruvka{
    grafo gr,mst;
    int n;
    public:
    boruvka(grafo g){
        gr=g;
        boruvkaMst();
        mst.imprimirGrafo();
    }
    void boruvkaMst();
    void unir(vector<pair<int,int>>&arboles,int,int);
    int buscar(vector<pair<int,int>>&arboles,int);
};
void Boruvka::boruvkaMst(){
    vector<pair<int,int>>arboles;
    int V=gr.lon();
    for (int i=0;i<V;i++){
        arboles.push_back(0,i);
    }
    int total=V;
    int E=gr.Ee();
    Arista* arrgrafo[E];
    arrgrafo=gr.grafoAristas();//array de Aristas*
    while(total>1){
        int bq[V];
        for(int i=0;i<V;i++){
            bq[i]=-1;
        }
        for(int i=0;i<E;i++){
            int setA=buscar(arboles,arrgrafo[i]->datoOrigen);
            int setB=buscar(arboles,arrgrafo[i]->datoDestino);
            if(setA==setB){
                continue;
            }
            else{
                if(bq[setA==-1] || arrgrafo[bq[setA]]->peso>arrgrafo[i]->peso){
                    bp[setA]=i;
                }
                if(bp[setB]==-1 || arrgrafo[bp[setB]]->peso>arrgrafo[i]->peso){
                    bp[setB]=i;
                }
            }
        }
        for(int i=0;i<V;i++){
            if(bp[i]!=-1){
                int setA=(arboles,arrgrafo[bp[i]]->datoOrigen);
                int setB=(arboles,arrgrafo[bp[i]]->datoDestino);
                if(setA==setB){
                    continue;
                }
                //insertar al arbol de algun modo 
                if(!mst.existeVertice(arrgrafo[bp[i]]->datoOrigen)){
                    mst.insertarVertice(arrgrafo[bp[i]]->datoOrigen);
                }
                if(!mst.existeVertice(arrgrafo[bp[i]]->datoDestino)){
                    mst.insertarVertice(arrgrafo[bp[i]]->datoDestino);
                }
                if(!mst.existeArista(arrgrafo[bp[i]]->datoOrigen,arrgrafo[bp[i]]->datoDestino)){
                    mst.insertarArista(arrgrafo[bp[i]]->datoOrigen,arrgrafo[bp[i]]->datoDestino,arrgrafo[bp[i]]->peso);
                }
                //union de arboles
                unir(arboles,setA,setB);
                total--;
            }
        }          
    }
}
int Boruvka::buscar(vector<pair<int,int>>&trees,int i){
    if(arboles[i].second!=i){
        arboles[i].second =buscar(arboles,arboles[i].second);
    }
    return arboles[i].second;
}
void Boruvka::unir(vector<pair<int,int>>&trees,int a,int b){
    int setA=buscar(arboles,a);
    int setB=buscar(arboles,b);
    if(arboles[setA].first<arboles[setB].first){
        arboles[setA].second=setB;
    }
    else if(arboles[setA].first>arboles[setB].first)
            arboles[setB].second=setA;
    else{
            arboles[setB].second=setA;
            arboles[setA].first++;
        }
}
*/

/*class Kruskal{
    grafo gr,mst;
    int e;
    int n;
    Kruskal(grafo g){
        gr=g;
        n=gr.lon();
        e=gr.Ee();
        int E=e;
        vector<Arista*>arrgrafo;
        arrgrafo=gr.grafoAristas();
        ordenar(arrgrafo);//ordenando menos peso→mas peso aristas
        for(int i=0;i<E;i++){
            int a=arrgrafo[i]->datoOrigen;
            int b=arrgrafo[i]->datoDestino;
            int peso=arrgrafo[i]->peso;
            pvertice p=gr.inicio();
            int flag=0;
            while(p!=nullptr){
                flag=mst.circuito(p->datoOrigen,b);   //ya hace un dfs para cada vertice
                if(flag){
                    break;
                }
                p=p->sgteVertice;
            }
            if(!flag){//si existe circuito no hace nada
                if(!mst.existeVertice(a)){
                    mst.insertarVertice(a);
                }
                if(!mst.existeVertice(b)){
                    mst.insertarVertice(b);
                }
                if(!mst.existeArista(a,b)){
                    mst.insertarArista(a,b,peso);
                }
            }
        }
        mst.imprimirGrafo();   
    }
    void ordenar(Arista&);

};
void Kruskal::ordenar(vector<Arista*>arr&){
    /*cout<<"arr de Arista*"<<endl;
    for(int i=0;i<arr.size();i++){
        //arr[i]->anterior=nullptr;
        cout<<arr[i]->datoOrigen<<"-"<<arr[i]->datoDestino<<" :"<<arr[i]->peso<<endl;
    }
    for(int i=l;i>0;i--){
        for(int j=0;j<i-1;j++){
            if(arr[j]->peso>arr[j+1]->peso){//intercambiar
                Arista*aux=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=aux;
            }
        }
    }*/
//arr=sort(arr.begin(),arr.end());
//}*/
 
class Nodod{ 
    public:
    int vertice; 
    int costo;
    friend class Pilapd;
    friend class grafo;
    friend class Dijkstra;
    Nodod*anterior;
    Nodod(int v,int cos){
        vertice=v;
        costo=cos;
        anterior=NULL;
    }
};

class Pilapd{
    public:
    Nodod* tope;
    friend class Dfs;
    friend class grafo;
    friend class Prim;
    friend class Dijkstra;
    int n;
    Pilapd();
    ~Pilapd();
    bool vacia();
    void insertar(int,int);
    void ordenar();
    Nodod* obtenerTope();
    Nodod* extraer();
    void imprimir();
    int lon();
};
Pilapd::Pilapd(){
    tope=nullptr;
    n=0;
}
int Pilapd::lon(){
    return n;
}
bool Pilapd::vacia(){
    return tope==nullptr;
}

Nodod* Pilapd::obtenerTope(){
    if(vacia()){
        return nullptr;
    }
    return tope;
}

void Pilapd::insertar(int v,int costo){
    Nodod *nuevo=new Nodod(v,costo);
    if(vacia()){
        nuevo->anterior=nullptr;
        tope=nuevo;
        n++;
    }else{
        nuevo->anterior=tope;
        tope=nuevo;
        n++;
    }
    ordenar();
}
    //ordenar
void Pilapd::ordenar() {
    Nodod*p=tope;
    int l=lon();
    Nodod* arr[l];
    int i=0;
    while(p!=nullptr){
        arr[i]=p;
        p=p->anterior;
        i++;
    }
    for(int i=l;i>0;i--){
        for(int j=0;j<i-1;j++){
            if(arr[j]->costo>arr[j+1]->costo){//intercambiar
                Nodod*aux=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=aux;
            }
        }
    }
    arr[0]->anterior=arr[1];
    tope=arr[0];
    for(int i=1;i<l-1;i++){
        arr[i]->anterior=arr[i+1];
    }
    arr[l-1]->anterior=nullptr;
    imprimir();
}
Nodod* Pilapd::extraer(){
    if(vacia()){
        return nullptr;
    }else{
        n--;
        Nodod*aux=tope;//revisar
        tope=tope->anterior;
        int origen=aux->vertice;
        float costo=aux->costo;
        delete (aux);
        return new Nodod(origen,costo); 
    }
}

void Pilapd::imprimir(){
    Nodod*p = tope;
    while(p!=NULL){
        cout<<p->vertice<<"-"<<p->costo<<endl;
        p=p->anterior;
    }
}

Pilapd::~Pilapd(){
    Nodod*p=tope;
    while(p!=NULL){
        Nodod*a=p;//solo copia 
        p=p->anterior;
        delete a;
    }
}
class Dijkstra{
    public:
    grafo gr,arbol;
    Pilapd cola;
    Dijkstra(grafo ,int );
    void dijkstra(int);
};
Dijkstra::Dijkstra(grafo g,int r){
    gr=g;
    dijkstra(r); 
}
void Dijkstra::dijkstra(int s){
    int n=gr.lon();
    int visit[n];
    for(int i=0;i<n;i++){
        visit[i]=-1;
    }
    cout<<"visit:"<<endl;
    for(int i=0;i<gr.lon();i++){
        cout<<visit[i]<<"\t";
    }
    cout<<endl;
    int  dist[n];
    for(int i=0;i<n;i++){
        dist[i]=1e5;
    }
    cout<<"dist:"<<endl;
    for(int i=0;i<gr.lon();i++){
        cout<<dist[i]<<"\t";
    }
    cout<<endl;
    int rutas[n];
    for(int i=0;i<n;i++){
        rutas[i]=-1;
    }
    cout<<"rutas:"<<endl;
    for(int i=0;i<gr.lon();i++){
        cout<<rutas[i]<<"\t";
    }
    cout<<endl;
    cola.insertar(s,0);
    dist[s]=0;
    Nodod*nodo;
    while(!cola.vacia()){
        nodo=cola.extraer();
        if(visit[nodo->vertice]==-1){
            visit[nodo->vertice]++;
            cout<<"visit:"<<endl;
            for(int i=0;i<gr.lon();i++){
                cout<<visit[i]<<"\t";
            }
            cout<<endl;
            pvertice p=gr.buscarPosV(nodo->vertice);
            parista a=p->arist;
            arbol.insertarVertice(nodo->vertice);
            if(rutas[nodo->vertice]!=-1){
                arbol.insertarVertice(rutas[nodo->vertice]);
                parista aa=gr.existeAristap(rutas[nodo->vertice],nodo->vertice);
                arbol.insertarArista(rutas[nodo->vertice],nodo->vertice,aa->peso);
            }
            cout<<"arbol"<<endl;
            arbol.imprimirGrafo();
            int costo;
            cout<<"vertice: "<<nodo->vertice<<" distancia: "<<nodo->costo<<endl;
            cout<<"grafo analizado"<<endl;
            gr.imprimirAristas(p->datoOrigen);
            cout<<"dist:"<<endl;
            for(int i=0;i<gr.lon();i++){
                cout<<dist[i]<<"\t";
            }
            cout<<endl;
            while(a!=NULL){
                cout<<"arista"<<a->datoOrigen<<"←→"<<a->datoDestino<<"\t";
                costo=a->peso;
                if(visit[a->datoDestino]==-1){        
                    if(dist[a->datoDestino]>dist[nodo->vertice]+costo){
                        cout<<dist[a->datoDestino]<<">"<<dist[nodo->vertice]<<"+"<<costo<<endl;
                        dist[a->datoDestino]=dist[nodo->vertice]+costo;
                        rutas[a->datoDestino]=nodo->vertice;
                        cola.insertar(a->datoDestino,dist[a->datoDestino]);
                    }
                }
                a=a->sgteArista;
            }
            cout<<"\ndist:"<<endl;
            for(int i=0;i<gr.lon();i++){
                cout<<dist[i]<<"\t";
            }
            cout<<endl;
        }
    }
    arbol.imprimirGrafo();
}
int main(){
    grafo g;
    g.insertarVertice(0);
    g.insertarVertice(1);
    g.insertarVertice(2);
    g.insertarVertice(3);
    g.insertarVertice(4);
    g.insertarVertice(5);
    g.insertarVertice(6);
    g.insertarVertice(7);
    g.insertarArista(0,6,53);
    g.insertarArista(0,1,32);
    g.insertarArista(0,2,29);
    g.insertarArista(0,5,60);
    g.insertarArista(4,3,34);
    g.insertarArista(5,3,18);
    g.insertarArista(5,4,40);
    g.insertarArista(6,4,51);
    g.insertarArista(7,4,46);
    g.insertarArista(7,0,31);
    g.insertarArista(7,6,25);
    g.insertarArista(7,1,21);
    g.imprimirGrafo();
    //cout<<"el dato del inicio del grafo es :"<<g.inicio()->datoOrigen<<endl;
    //cout<<"suma de pesos"<<g.sumarPesos()<<endl;
            //se recomienda descomentar para ejecutar Bfs
    //Bfs bfs(g,2);
            //se recomienda descomentar para ejecutar Dfs
    //Dfs obj(g);  //por alguna razon Dfs , Bfs y Camino no ejecutan juntos en main
    //cout<<"menu despues de dfs"<<endl;
            //se recomienda descomentar para ejecutar Camino
    //Camino cam(g,3,7);
    //cout<<"existe camino de 3-7?"<<cam.flagg()<<endl;
            //se recomienda descomentar para ejecutar circuito
    //Circuito cir(g);
    //cout<<"existe algun ciclo? si:1   no:0 \t"<<cir.flag<<endl;
            //se recomienda descomentar para ejecutar Bicolorable
    //Bicolorable bi(g);
    //cout<<"es bicolorable? si:1   no:0 \t"<<bi.flag<<endl;
    //cout<<"existe circuito? 0 no 1 si"<<g.circuito()<<endl;
            //se recomienda descomentar para ejecutar prim
    //Prim pri(g,0);
    //pri.arbol.imprimirGrafo();
    //int opcion;
    //en vscode no he podido pedir dato desde terminal
    //cout<<"ingresar opcion deseada 1:Bfs    2:Dfs   3:camino  4:circuito  5:Bicolorabilidad   6:Prim"<<endl;
    /*cin>>opcion;
    switch (opcion){
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
}