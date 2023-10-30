#include <iostream>
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
        cout<<"k: "<<k<<endl;
        Nodo*p=dist.primer;
        while(p!=nullptr){
        arista*ar=p->aris;
        while(ar!=nullptr){
            arista*dist1=dist.obtener(ar->datoOrigen+1,k);
            arista*dist2=dist.obtener(k,ar->datoDestino+1);
            int d=dist1->peso+dist2->peso;
            if(d<dist.obtener(ar->datoOrigen+1,ar->datoDestino+1)->peso){
                cam.obtener(ar->datoOrigen+1,ar->datoDestino+1)->peso=cam.obtener(ar->datoOrigen+1,k)->peso;
                dist.obtener(ar->datoOrigen+1,ar->datoDestino+1)->peso=d;
            }
            ar=ar->sgteArista;  
        }
        p=p->siguiente;       
        }
        cout<<"cam:"<<endl;
        cam.imprimir();
        cout<<"dist:"<<endl;
        dist.imprimir();
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
    listAdy.obtenerNodo(2)->insertarArista(4,3);
    listAdy.obtenerNodo(4)->insertarArista(3,2);
    listAdy.imprimir();
    FW prueba(listAdy);
    cout<<"bigrafo"<<endl;
    prueba.listAdy.imprimir();  
    cout<<"dist"<<endl;
    prueba.dist.imprimir();
    cout<<"cam"<<endl;
    prueba.cam.imprimir();
     
}