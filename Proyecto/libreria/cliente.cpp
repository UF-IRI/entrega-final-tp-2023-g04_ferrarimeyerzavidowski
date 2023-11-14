#include "cliente.h"

bool EstadoCuenta(sCliente* cliente)
{
    srand(time(NULL));
    int num=rand()%2 +1;
    //print(num);//para ver en el testing si funciona
    if (cliente->estado <0){ //endeudado
       if (num ==1){ //lo quiere pagar
            cliente->estado=0;
           return true;
       } else{ //no lo quiere pagar
           return false;
       }
    }
    return true; //no estuvo endeudado
}
sTipo* Inscribirse(){

}
