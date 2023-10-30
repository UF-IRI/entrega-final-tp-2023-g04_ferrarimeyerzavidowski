#include <cliente.h>

void EstadoCuenta(sCliente* cliente,int num)
{
   // srand(time(NULL));
   // num=rand()%2 +1;
    if (cliente->estado <0){
        if (num ==1) //lo quiere pagar
            cliente->estado=0;
    }
}
