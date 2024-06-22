#include "../../include/CasosDeUso/CasosDeUso.h"

void ExpedienteDeUsuario(){

    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();

    ListadoDeUsuarios();

    string nickname;

    cout << "\nIngrese un nickname: ";
    cin >> nickname;

    DTExpedienteCliente infoC = IU->obtenerInfoCliente(nickname);
    DTExpedienteVendedor infoV = IU->obtenerInfoVendedor(nickname);

    string aImprimir = "";

    if (infoC.getDTCliente().getNickname()!=""){

        aImprimir = "\nNickname: " + infoC.getDTCliente().getNickname() + " | Fecha de nacimiento: " + infoC.getDTCliente().getFecha().toString();
        aImprimir += "\n\tCompras:";
        vector<DTCompraProductos> vDTCompraProductos = infoC.getVDTCompraProductos();
        for ( unsigned int i = 0; i < vDTCompraProductos.size() ; i++ ){

            DTCompraProductos DTCPActual = vDTCompraProductos[i];
            aImprimir+= "\n\t\tFecha: " + DTCPActual.getFecha().toString() + " | Monto final: " + to_string(DTCPActual.getMontoFinal());
            for ( unsigned int j = 0; j<DTCPActual.getProductos().size(); j++){
                aImprimir += "\n\t\t\t" + DTCPActual.getProductos()[j].toString();
            }

        }

    }

    if (infoV.getDTVendedor().getNickname()!=""){

        aImprimir = "\nNickname: " + infoV.getDTVendedor().getNickname() + " | Fecha de nacimiento: " + infoV.getDTVendedor().getFecha().toString();
        aImprimir += "\n\tProductos:";
        for ( unsigned int i = 0; i < infoV.getDTProductos().size(); i++ ){
            aImprimir += "\n\t\t" + infoV.getDTProductos()[i].toString();
        }
        aImprimir += "\n\tPromociones:";
        for ( unsigned int i = 0; i < infoV.getDTPromociones().size(); i++ ){
            aImprimir += "\n\t\t" + infoV.getDTPromociones()[i].toString();
        }

    }

    cout << aImprimir << endl;

}