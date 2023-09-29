#include <iostream>
using namespace std;
/*void busProf(grafo g,int*pre);
void dfs (grafo g,pvertice v,int *pr);*/
struct arista{ 
    int datoOrigen;
    int datoDestino; 
    float peso;
    arista*sgteArista; 
}; typedef arista*parista;


struct vertice{ 
    int datoOrigen; 
    arista*arist; 
    vertice*sgteVertice; 
    }; typedef vertice*pvertice;

class grafo{ 
    private: pvertice pGrafo;
    int n;
    public: 
    grafo();
    ~grafo(); 
    void insertarVertice(int); 
    void insertarArista(int,int,float peso); 
    void imprimirGrafo();
    float sumarPesos();
    int lon();
    pvertice buscarPosV(int);
    pvertice inicio();
    void boruvka(); 
};    

grafo::grafo(){
     pGrafo = NULL; 
     n=0;
}
int grafo::lon(){
    return n;
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
            a->datoOrigen=x;
            a->datoDestino=y;
            a->peso = peso;
            a->sgteArista=p->arist;
            p->arist=a;
            //agregar la arista contraria, pero no es dirigido 
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
            a=p->arist;
            while(a!=NULL){ 
                cout<<" "<<a->datoDestino<<" ";
                a=a->sgteArista; 
            } 
            cout<<endl;
            p=p->sgteVertice; 
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
                i=i->sgteArista;
            }
            p=p->sgteVertice;
        }
    }
    return suma;

}
void grafo::boruvka(){
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

int main(){
    grafo g;
    int x,y;
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
    cout<<"el dato del inicio del grafo es :"<<g.inicio()->datoOrigen<<endl;
    g.boruvka();
}