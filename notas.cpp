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