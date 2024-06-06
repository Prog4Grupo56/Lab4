TARGET  	= main
SRC_DIR 	= ./src
INC_DIR 	= ./include
OBJ_DIR 	= ./obj
OBJ__O_DIR 	= obj
OBJ     	=  main.o Comentario.o Usuario.o Cliente.o DTFecha.o DataVendedor.o DataUsuario.o
CFLAGS  	= -g -Wall 

#CREA EL EJECUTABLE
$(TARGET): $(addprefix $(OBJ_DIR)/, $(OBJ))
	g++ $(CFLAGS) $^ -o $@

#COMPILAR LOS ARCHIVOS CPP
$(OBJ_DIR)/main.o: main.cpp $(INC_DIR)/Comentario.h $(INC_DIR)/Usuario.h $(INC_DIR)/Cliente.h $(INC_DIR)/DataVendedor.h $(INC_DIR)/DTFecha.h $(INC_DIR)/DataUsuario.h | ${OBJ__O_DIR}
	g++ -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(INC_DIR)/%.h | ${OBJ__O_DIR}
	g++ -c $(CFLAGS) $< -o $@

${OBJ__O_DIR}:
	@mkdir -p ${OBJ__O_DIR}

#BORRA LOS .o Y EL EJECUTABLE SI EXISTEN
.PHONY: clean
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

#EJECUTAR EL PROGRAMA
.PHONY: run
run: $(TARGET)
	./$(TARGET)
