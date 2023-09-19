#include <iostream>
using namespace std;
struct arista{ 
    int datoDestino; 
    float peso;
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
    void insertarArista(int,int,float peso); 
    void imprimirGrafo();
    float sumarPesos(); 
};    

grafo::grafo(){
     pGrafo = NULL; 
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

void grafo::insertarArista(int x,int y,float peso){ 
    pvertice p; 
    parista a; 
    p=pGrafo; 
    if(p!= NULL){
        while(p->datoOrigen!=x&&p!=NULL) 
            p=p->sgteVertice;
        if(p!=NULL){ 
            a=new arista;
            a->datoDestino=y;
            a->peso = peso;
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
                cout<<" "<<a->datoDestino<<" ";
                a=a->sgteArista; 
            } 
            cout<<endl;
            p=p->sgteVertice; 
        } 
}
float grafo::sumarPesos(){
    pvertice p= pGrafo;
    parista i;
    float suma=0;
    if(p!=NULL){
        while(p!=NULL){
            i=p->adyacente;
            while(i!=NULL){
                suma+=i->peso;
                i=i->sgteArista;
            }
            p=p->sgteVertice;
        }
    }
    return suma;

}

int main(){
    grafo g;
    int x,y;
    g.insertarVertice(4);
    cout<<"vertice insertado"<<endl;
    g.imprimirGrafo();
    g.insertarVertice(6);
    cout<<"vertice insertado"<<endl;
    g.imprimirGrafo();
    g.insertarArista(6,4,12);
    cout<<"arista insertado"<<endl;
    g.imprimirGrafo();
    g.insertarVertice(3);
    cout<<"vertice insertado"<<endl;
    g.imprimirGrafo();
    g.insertarArista(6,3,12.5);
    cout<<"arista insertado"<<endl;
    g.imprimirGrafo();
    cout<<"sumando pesos de aristas"<<g.sumarPesos()<<endl;
    g.insertarArista(3,4,100);
    cout<<"arista insertado"<<endl;
    g.imprimirGrafo();
    cout<<"sumando pesos de aristas"<<g.sumarPesos()<<endl;


}
    /*
    g.insertarVertice(3);
    
    g.insertarArista(3,6);
    g.insertarArista(3,4); 
    cout<<"VertAristas"<<endl;
    g.imprimirGrafo(); }*/














