#include "../../include/CasosDeUso/CasosDeUso.h"


void CargarDatos(){
    Fabrica* F = Fabrica::getInstance();
    IUsuario* IU = F->getIUsuario();
    ICompra* IC = F->getICompra();

//INGRESO DE USUARIOS
    DataVendedor US1 = DataVendedor("ana23", "qwer1234", DTFecha(15,05,1988), "212345678001");
    IU->ingresarVendedor(US1);
    DataVendedor US2 = DataVendedor("carlos78", "asdfghj", DTFecha(18,06,1968), "356789012345");
    IU->ingresarVendedor(US2);
    DataVendedor US3 = DataVendedor("diegom", "zxcvbn", DTFecha(28,07,1993), "190123456789");
    IU->ingresarVendedor(US3);
    DataCliente US4 = DataCliente("juan87", "1qaz2wsx", DTFecha(20,10,1992), DTDireccion("Av. 18 de Julio", 456), "Melo");
    IU->ingresarCliente(US4);
    DataCliente US5 = DataCliente("laura", "3edc4rfv", DTFecha(22,9,1979), DTDireccion("Rondeau", 1617), "Montevideo");
    IU->ingresarCliente(US5);
    DataVendedor US6 = DataVendedor("maria01", "5tgb6yhn", DTFecha(25,03,1985), "321098765432");
    IU->ingresarVendedor(US6);
    DataCliente US7 = DataCliente("natalia", "poiuyt", DTFecha(14,04,1982), DTDireccion("Paysandú", 2021), "Salto");
    IU->ingresarCliente(US7);
    DataCliente US8 = DataCliente("pablo10", "lkjhgv", DTFecha(30,11,1995), DTDireccion("Av. Rivera", 1819), "Mercedes");
    IU->ingresarCliente(US8);
    DataCliente US9 = DataCliente("roberto", "mnbvcx", DTFecha(12,8,1990), DTDireccion("Av. Brasil", 1011), "Montevideo");
    IU->ingresarCliente(US9);
    DataVendedor US10 = DataVendedor("sofia25", "1234asdf", DTFecha(07,12,1983), "445678901234");
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
//     //PM1
//     DataPromocion PM1 = DataPromocion("Casa nueva", "Para que puedas ahorrar en la casa nueva", DTFecha(25, 10, 2024), 30);
//     vector<ParCodigoCantidad> PC1;
//     PC1.push_back(ParCodigoCantidad(2, 1));
//     PC1.push_back(ParCodigoCantidad(4, 1));
//     PC1.push_back(ParCodigoCantidad(8, 1));
//     DataCrearPromocion* DCPM1 = new DataCrearPromocion(V2->getNickname(), PM1, PC1);
//     IC->crearPromocion(V2, DCPM1);
//     //PM2
//     DataPromocion PM2 = DataPromocion("Fiesta", "Para que no te quedes sin ropa para las fiestas", DTFecha(26, 10, 2024), 20);
//     vector<ParCodigoCantidad> PC2;
//     PC2.push_back(ParCodigoCantidad(3, 2));
//     PC2.push_back(ParCodigoCantidad(6, 3));
//     DataCrearPromocion* DCPM2 = new DataCrearPromocion(V3->getNickname(), PM2, PC2);
//     IC->crearPromocion(V3, DCPM2);
//     //PM3
//     DataPromocion PM3 = DataPromocion("Domotica", "Para modernizar tu casa", DTFecha(26, 10, 2024), 10);
//     vector<ParCodigoCantidad> PC3;
//     PC3.push_back(ParCodigoCantidad(5, 2));
//     DataCrearPromocion* DCPM3 = new DataCrearPromocion(V5->getNickname(), PM3, PC3);
//     IC->crearPromocion(V5, DCPM3);
//     //PM4
//     DataPromocion PM4 = DataPromocion("Liquidacion", "Hasta agotar stock", DTFecha(26, 03, 2024), 10);
//     vector<ParCodigoCantidad> PC4;
//     PC1.push_back(ParCodigoCantidad(14, 1));
//     DataCrearPromocion* DCPM4 = new DataCrearPromocion(V14->getNickname(), PM4, PC4);
//     IC->crearPromocion(V14, DCPM4);

// //INGRESO DE COMPRAS
//     //CO1
//     vector<ParCodigoCantidad> PCC1;
//     PCC1.push_back(ParCodigoCantidad(2, 2));
//     PCC1.push_back(ParCodigoCantidad(4, 1));
//     PCC1.push_back(ParCodigoCantidad(8, 1));
//     DataInfoCompra* CO1 = new DataInfoCompra(US4.getNickname(), 57581.993, PCC1);
//     IC->confirmarCompraCargaDeDatos(CO1, DTFecha(01,05,2024));
//     //CO2
//     vector<ParCodigoCantidad> PCC2;
//     PCC2.push_back(ParCodigoCantidad(5, 1));
//     DataInfoCompra* CO2 = new DataInfoCompra(US4.getNickname(), 599.99, PCC2);
//     IC->confirmarCompraCargaDeDatos(CO2, DTFecha(01,05,2024));
//     //CO3
//     vector<ParCodigoCantidad> PCC3;
//     PCC3.push_back(ParCodigoCantidad(14, 10));
//     DataInfoCompra* CO3 = new DataInfoCompra(US5.getNickname(), 150000, PCC3);
//     IC->confirmarCompraCargaDeDatos(CO3, DTFecha(15,05,2024));
//     //CO4
//     vector<ParCodigoCantidad> PCC4;
//     PCC4.push_back(ParCodigoCantidad(11, 1));
//     PCC4.push_back(ParCodigoCantidad(12, 1));
//     PCC4.push_back(ParCodigoCantidad(13, 1));
//     DataInfoCompra* CO4 = new DataInfoCompra(US7.getNickname(), 11734, PCC4);
//     IC->confirmarCompraCargaDeDatos(CO4, DTFecha(25,04,2024));
//     //CO5
//     vector<ParCodigoCantidad> PCC5;
//     PCC5.push_back(ParCodigoCantidad(3, 2));
//     PCC5.push_back(ParCodigoCantidad(6, 3));
//     DataInfoCompra* CO5 = new DataInfoCompra(US4.getNickname(), 1263984, PCC5);
//     IC->confirmarCompraCargaDeDatos(CO5, DTFecha(20,05,2024));
//     //CO6
//     vector<ParCodigoCantidad> PCC6;
//     PCC6.push_back(ParCodigoCantidad(1, 2));
//     DataInfoCompra* CO6 = new DataInfoCompra(US5.getNickname(), 2800, PCC6);
//     IC->confirmarCompraCargaDeDatos(CO6, DTFecha(12,05,2024));
//     //CO7
//     vector<ParCodigoCantidad> PCC7;
//     PCC7.push_back(ParCodigoCantidad(1, 3));
//     DataInfoCompra* CO7 = new DataInfoCompra(US7.getNickname(), 4200, PCC7);
//     IC->confirmarCompraCargaDeDatos(CO7, DTFecha(13,05,2024));
//     //CO8
//     vector<ParCodigoCantidad> PCC8;
//     PCC8.push_back(ParCodigoCantidad(1, 4));
//     DataInfoCompra* CO8 = new DataInfoCompra(US8.getNickname(), 5600, PCC8);
//     IC->confirmarCompraCargaDeDatos(CO8, DTFecha(14,05,2024));
//     //CO9
//     vector<ParCodigoCantidad> PCC9;
//     PCC9.push_back(ParCodigoCantidad(1, 5));
//     DataInfoCompra* CO9 = new DataInfoCompra(US9.getNickname(), 7000, PCC9);
//     IC->confirmarCompraCargaDeDatos(CO9, DTFecha(015,05,2024));

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