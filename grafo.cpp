#include <iostream>
using namespace std;
struct arista{ 
    int datoDestino; 
    arista*sgteArista; 
}; typedef arista*parista;


struct vertice{ 
    int datoOrigen; 
    arista*adyacente; 
    vertice*sgteVertice; 
    }; typedef vertice*pvertice;

class grafo{ 
    private: pvertice pGrafo;
    public: 
    grafo();
    ~grafo(); 
    void insertarVertice(int); 
    void insertarArista(int,int); 
    void imprimirGrafo(); };    

grafo::grafo(){
     pGrafo = nullptr; 
}

grafo::~grafo(){ 
    pvertice p,rp; 
    parista r,ra; 
    p=pGrafo; 
    while(p!=NULL){
        r=p->adyacente; 
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
     pvertice p; 
     p=new vertice;
     p->datoOrigen=x; 
     p->adyacente=NULL; 
     p->sgteVertice=pGrafo; 
     pGrafo=p;
}

void grafo::insertarArista(int x,int y){ 
    pvertice p; 
    parista a; 
    p=pGrafo; 
    if(p!= NULL){
        while(p->datoOrigen!=x&&p!=NULL) 
            p=p->sgteVertice;
        if(p!=NULL){ 
            a=new arista;
            a->datoDestino=y;
            a->sgteArista=p->adyacente;
            p->adyacente=a;
        }
    }
}
void grafo::imprimirGrafo(){
    pvertice p;
    parista a;
    p=pGrafo;
    if(p==NULL) cout<<"Grafovacio"<<endl;
    else 
        while(p!=NULL){
            cout<<p->datoOrigen<<"";
            a=p->adyacente;
            while(a!=NULL){ 
                cout<<a->datoDestino<<"";
                a=a->sgteArista; 
            } 
            cout<<endl;
            p=p->sgteVertice; 
        } 
}
int main(){
    grafo g;
    int x,y;
    g.insertarVertice(4);
    g.insertarVertice(6);
    g.insertarVertice(3);
    g.insertarArista(4,6);
    g.insertarArista(3,6);
    g.insertarArista(3,4); 
    cout<<"VertAristas"<<endl;
    g.imprimirGrafo(); }













