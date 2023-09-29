if(pp->arist!=NULL){
                int d_a=pp->arist->datoDestino;
                int d_o=p->datoOrigen;
                cout<<"dato arista , dato vertice actual"<<d_a<<d_o<<endl;
                if(d_a==d_o){
                    if(a_menor==NULL){
                        int aa=pp->arist->datoOrigen;
                        a_menor=pp->arist;
                        a_menor->datoDestino=aa;
                    }else{//cambiar datoOrigen datoDestino de la arista a_menor
                        if(a_menor->peso > pp->arist->peso){
                            int aa=pp->arist->datoOrigen;
                            a_menor=pp->arist;
                            a_menor->datoDestino=aa;
                            }
                        }
                }
            }

