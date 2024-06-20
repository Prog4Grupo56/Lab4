#include "../../include/CasosDeUso/CasosDeUso.h"


void CargarDatos(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();
    ICompra* IC = F->getICompra();
    IFecha* IF =  F->getIFecha();

    IF->setFechaActual(DTFecha(24,06,2024));

//INGRESO DE USUARIOS
    DTVendedor US1 = DTVendedor("ana23", "qwer1234", DTFecha(15,05,1988), "212345678001");
    IU->ingresarVendedor(US1);
    DTVendedor US2 = DTVendedor("carlos78", "asdfghj", DTFecha(18,06,1968), "356789012345");
    IU->ingresarVendedor(US2);
    DTVendedor US3 = DTVendedor("diegom", "zxcvbn", DTFecha(28,07,1993), "190123456789");
    IU->ingresarVendedor(US3);
    DTCliente US4 = DTCliente("juan87", "1qaz2wsx", DTFecha(20,10,1992), DTDireccion("Av. 18 de Julio", 456), "Melo");
    IU->ingresarCliente(US4);
    DTCliente US5 = DTCliente("laura", "3edc4rfv", DTFecha(22,9,1979), DTDireccion("Rondeau", 1617), "Montevideo");
    IU->ingresarCliente(US5);
    DTVendedor US6 = DTVendedor("maria01", "5tgb6yhn", DTFecha(25,03,1985), "321098765432");
    IU->ingresarVendedor(US6);
    DTCliente US7 = DTCliente("natalia", "poiuyt", DTFecha(14,04,1982), DTDireccion("Paysandú", 2021), "Salto");
    IU->ingresarCliente(US7);
    DTCliente US8 = DTCliente("pablo10", "lkjhgv", DTFecha(30,11,1995), DTDireccion("Av. Rivera", 1819), "Mercedes");
    IU->ingresarCliente(US8);
    DTCliente US9 = DTCliente("roberto", "mnbvcx", DTFecha(12,8,1990), DTDireccion("Av. Brasil", 1011), "Montevideo");
    IU->ingresarCliente(US9);
    DTVendedor US10 = DTVendedor("sofia25", "1234asdf", DTFecha(07,12,1983), "445678901234");
    IU->ingresarVendedor(US10);

//INGRESO DE PRODUCTOS
    //PR1
    Vendedor* V1 = IU->obtenerVendedor("carlos78");
    IC->confirmarAltaProducto(Ropa, "Camiseta Azul", "Camiseta de poliester, color azul", 50, 1400, V1);
    //PR2
    Vendedor* V2 = IU->obtenerVendedor("ana23");
    IC->confirmarAltaProducto(Electrodomesticos, "Televisor LED", "Televisor LED 55 pulgadas", 30, 40500, V2);
    //PR3
    Vendedor* V3 = IU->obtenerVendedor("carlos78");
    IC->confirmarAltaProducto(Ropa, "Chaqueta de Cuero", "Chaqueta de cuero, color negro", 20, 699.99, V3);
    //PR4
    Vendedor* V4 = IU->obtenerVendedor("ana23");
    IC->confirmarAltaProducto(Electrodomesticos, "Microondas Digital", "Microondas digital, 30L", 15, 1199.99, V4);
    //PR5
    Vendedor* V5 = IU->obtenerVendedor("diegom");
    IC->confirmarAltaProducto(Otros, "Luz LED", "Luz Bluetooth LED", 40, 599.99, V5);
    //PR6
    Vendedor* V6 = IU->obtenerVendedor("carlos78");
    IC->confirmarAltaProducto(Ropa, "Pantalones Vaqueros", "Pantalones vaqueros, talla 32", 25, 60, V6);
    //PR7
    Vendedor* V7 = IU->obtenerVendedor("diegom");
    IC->confirmarAltaProducto(Otros, "Auriculares Bluetooth", "Auriculares bluethooth para celular", 35, 199.99, V7);
    //PR8
    Vendedor* V8 = IU->obtenerVendedor("ana23");
    IC->confirmarAltaProducto(Electrodomesticos, "Refrigerador", "Refrigerador de doble puerta", 10, 15499, V8);
    //PR9
    Vendedor* V9 = IU->obtenerVendedor("ana23");
    IC->confirmarAltaProducto(Electrodomesticos, "Cafetera", "Cafetera de goteo programable", 50, 23000, V9);
    //PR10
    Vendedor* V10 = IU->obtenerVendedor("carlos78");
    IC->confirmarAltaProducto(Ropa, "Zapatillas Deportivas", "Zapatillas para correr, talla 42", 20, 5500, V10);
    //PR11
    Vendedor* V11 = IU->obtenerVendedor("carlos78");
    IC->confirmarAltaProducto(Otros, "Mochila", "Mochila de viaje, 40L", 30, 9000, V11);
    //PR12
    Vendedor* V12 = IU->obtenerVendedor("diegom");
    IC->confirmarAltaProducto(Electrodomesticos, "Plancha de Ropa", "Plancha a vapor, 1500W", 25, 2534, V12);
    //PR13
    Vendedor* V13 = IU->obtenerVendedor("sofia25");
    IC->confirmarAltaProducto(Ropa, "Gorra", "Gorra para deportes, color rojo", 50, 200, V13);
    //PR14
    Vendedor* V14 = IU->obtenerVendedor("diegom");
    IC->confirmarAltaProducto(Otros, "Tablet", "Tablet Android de 10 pulgadas", 15, 15000, V14);
    //PR15
    Vendedor* V15 = IU->obtenerVendedor("sofia25");
    IC->confirmarAltaProducto(Otros, "Reloj de Pared", "Reloj de pared vintage", 20, 150.50, V15);

//INGRESO DE PROMOCIONES
    //PM1
    DTPromocion PM1 = DTPromocion("Casa nueva", "Para que puedas ahorrar en la casa nueva", DTFecha(25, 10, 2024), 30);
    vector<DTCodigoCantidad> PC1;
    PC1.push_back(DTCodigoCantidad(2, 1));
    PC1.push_back(DTCodigoCantidad(4, 1));
    PC1.push_back(DTCodigoCantidad(8, 1));
    DataCrearPromocion* DCPM1 = new DataCrearPromocion(V2->getNickname(), PM1, PC1);
    IC->crearPromocion(V2, DCPM1);
    //PM2
    DTPromocion PM2 = DTPromocion("Fiesta", "Para que no te quedes sin ropa para las fiestas", DTFecha(26, 10, 2024), 20);
    vector<DTCodigoCantidad> PC2;
    PC2.push_back(DTCodigoCantidad(3, 2));
    PC2.push_back(DTCodigoCantidad(6, 3));
    DataCrearPromocion* DCPM2 = new DataCrearPromocion(V3->getNickname(), PM2, PC2);
    IC->crearPromocion(V3, DCPM2);
    //PM3
    DTPromocion PM3 = DTPromocion("Domotica", "Para modernizar tu casa", DTFecha(26, 10, 2024), 10);
    vector<DTCodigoCantidad> PC3;
    PC3.push_back(DTCodigoCantidad(5, 2));
    DataCrearPromocion* DCPM3 = new DataCrearPromocion(V5->getNickname(), PM3, PC3);
    IC->crearPromocion(V5, DCPM3);
    //PM4
    DTPromocion PM4 = DTPromocion("Liquidacion", "Hasta agotar stock", DTFecha(26, 03, 2024), 10);
    vector<DTCodigoCantidad> PC4;
    PC4.push_back(DTCodigoCantidad(14, 1));
    DataCrearPromocion* DCPM4 = new DataCrearPromocion(V14->getNickname(), PM4, PC4);
    IC->crearPromocion(V14, DCPM4);

//INGRESO DE COMPRAS
    //CO1
    IC->seleccionarCliente(US4.getNickname());
    IC->agregarProductoCantidad(DTCodigoCantidad(2, 2));
    IC->agregarProductoCantidad(DTCodigoCantidad(4, 1));
    IC->agregarProductoCantidad(DTCodigoCantidad(8, 1));
    IC->obtenerInfoCompra();
    IC->confirmarCompra(DTFecha(01,05,2024));
    //CO2
    IC->seleccionarCliente(US4.getNickname());
    IC->agregarProductoCantidad(DTCodigoCantidad(5, 1));
    IC->obtenerInfoCompra();
    IC->confirmarCompra(DTFecha(01,05,2024));
    //CO3
    IC->seleccionarCliente(US5.getNickname());
    IC->agregarProductoCantidad(DTCodigoCantidad(14, 10));
    IC->obtenerInfoCompra();
    IC->confirmarCompra(DTFecha(15,05,2024));
    //CO4
    IC->seleccionarCliente(US7.getNickname());
    IC->agregarProductoCantidad(DTCodigoCantidad(11, 1));
    IC->agregarProductoCantidad(DTCodigoCantidad(12, 1));
    IC->agregarProductoCantidad(DTCodigoCantidad(13, 1));
    IC->obtenerInfoCompra();
    IC->confirmarCompra(DTFecha(25,04,2024));
    //CO5
    IC->seleccionarCliente(US4.getNickname());
    IC->agregarProductoCantidad(DTCodigoCantidad(3, 2));
    IC->agregarProductoCantidad(DTCodigoCantidad(6, 3));
    IC->obtenerInfoCompra();
    IC->confirmarCompra(DTFecha(20,05,2024));
    //CO6
    IC->seleccionarCliente(US5.getNickname());
    IC->agregarProductoCantidad(DTCodigoCantidad(1, 2));
    IC->obtenerInfoCompra();
    IC->confirmarCompra(DTFecha(12,05,2024));
    //CO7
    IC->seleccionarCliente(US7.getNickname());
    IC->agregarProductoCantidad(DTCodigoCantidad(1, 3));
    IC->obtenerInfoCompra();
    IC->confirmarCompra(DTFecha(13,05,2024));
    //CO8
    IC->seleccionarCliente(US8.getNickname());
    IC->agregarProductoCantidad(DTCodigoCantidad(1, 4));
    IC->obtenerInfoCompra();
    IC->confirmarCompra(DTFecha(14,05,2024));
    //CO9
    IC->seleccionarCliente(US9.getNickname());
    IC->agregarProductoCantidad(DTCodigoCantidad(1, 5));
    IC->obtenerInfoCompra();
    IC->confirmarCompra(DTFecha(15,05,2024));

//INGRESO DE ENVIOS
    //EV1
    IC->enviarProducto(2, US4.getNickname());
    //EV2
    IC->enviarProducto(5, US4.getNickname());
    //EV3
    IC->enviarProducto(14, US5.getNickname());
    //EV4
    IC->enviarProducto(11, US7.getNickname());
    //EV5
    IC->enviarProducto(12, US7.getNickname());
    //EV6
    IC->enviarProducto(13, US7.getNickname());
    //EV7
    IC->enviarProducto(6, US4.getNickname());
    //EV8
    IC->enviarProducto(1, US7.getNickname());

//INGRESO DE COMENTARIOS
    //CM1
    IU->ingresarComentarioNuevo("juan87", 1, "¿La camiseta azul esta disponible en talla M?", DTFecha(01,06,2024));
    //CM2
    IU->ingresarComentarioRespuesta("carlos78", 1, "Si, tenemos la camiseta azul en talla M.", DTFecha(01,06,2024), 1);
    //CM3
    IU->ingresarComentarioRespuesta("laura", 1, "¿Es de buen material? Me preocupa la durabilidad.", DTFecha(02,06,2024), 2);
    //CM4
    IU->ingresarComentarioRespuesta("juan87", 1, "He comprado antes y la calidad es buena.", DTFecha(02,06,2024), 3);
    //CM5
    IU->ingresarComentarioNuevo("natalia", 1, "¿Como es el ajuste? ¿Es ajustada o holgada?", DTFecha(02,06,2024));
    //CM6
    IU->ingresarComentarioNuevo("laura", 2, "¿Cual es la resolucion del Televisor LED?", DTFecha(02,06,2024));
    //CM7
    IU->ingresarComentarioRespuesta("ana23", 2, "El televisor LED tiene una resolucion de 4K UHD.", DTFecha(02,06,2024), 6);
    //CM8
    IU->ingresarComentarioNuevo("pablo10", 2, "¿Tiene soporte para HDR10?", DTFecha(03,06,2024));
    //CM9
    IU->ingresarComentarioRespuesta("ana23", 2, "Si, soporta HDR10.", DTFecha(03,06,2024), 8);
    //CM10
    IU->ingresarComentarioNuevo("natalia", 3, "¿La chaqueta de cuero es resistente al agua?", DTFecha(03,06,2024));
    //CM11
    IU->ingresarComentarioRespuesta("carlos78", 3, "No, la chaqueta de cuero no es resistente al agua.", DTFecha(03,06,2024), 10);
    //CM12
    IU->ingresarComentarioRespuesta("laura", 3, "¿Viene en otros colores?", DTFecha(04,06,2024), 10);
    //CM13
    IU->ingresarComentarioRespuesta("carlos78", 3, "Si, tambien esta disponible en marron.", DTFecha(04,06,2024), 12);
    //CM14
    IU->ingresarComentarioRespuesta("roberto", 3, "¿Es adecuada para climas frios?", DTFecha(04,06,2024), 10);
    //CM15
    IU->ingresarComentarioNuevo("pablo10", 4, "¿El microondas digital tiene funcion de descongelacion rapida?", DTFecha(04,06,2024));
    //CM16
    IU->ingresarComentarioRespuesta("ana23", 4, "Si, el microondas digital incluye una funcion de descongelacion rapida.", DTFecha(04,06,2024), 15);
    //CM17
    IU->ingresarComentarioRespuesta("natalia", 4, "¿Cuantos niveles de potencia tiene?", DTFecha(05,06,2024), 15);
    //CM18
    IU->ingresarComentarioRespuesta("ana23", 4, "Tiene 10 niveles de potencia.", DTFecha(05,06,2024), 17);
    //CM19
    IU->ingresarComentarioRespuesta("roberto", 4, "¿Es facil de limpiar?", DTFecha(05,06,2024), 15);
    //CM20
    IU->ingresarComentarioNuevo("roberto", 5, "¿La luz LED se puede controlar con una aplicacion movil?", DTFecha(05,06,2024));
    //CM21
    IU->ingresarComentarioRespuesta("diegom", 5, "Si, la luz LED se puede controlar a traves de una aplicacion movil.", DTFecha(05,06,2024), 20);
    //CM22
    IU->ingresarComentarioRespuesta("pablo10", 5, "¿Es compatible con Alexa o Google Home?", DTFecha(06,06,2024), 20);
    //CM23
    IU->ingresarComentarioRespuesta("diegom", 5, "Si, es compatible con ambos.", DTFecha(06,06,2024), 22);
    //CM24
    IU->ingresarComentarioRespuesta("natalia", 5, "¿Cuanto dura la bateria?", DTFecha(06,06,2024), 20);
    //CM25
    IU->ingresarComentarioRespuesta("pablo10", 5, "¿La aplicacion movil es facil de usar?", DTFecha(07,06,2024), 20);

}