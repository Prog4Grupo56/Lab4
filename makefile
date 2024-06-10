TARGET      = main
SRC_DIR     = ./src
INC_DIR     = ./include
OBJ_DIR     = ./obj
CFLAGS      = -g -Wall 

# Encuentra todos los archivos .cpp y .h en las subcarpetas de src y include
SRC_FILES   = $(wildcard $(SRC_DIR)/CasosDeUso/*.cpp) $(wildcard $(SRC_DIR)/Clases/*.cpp) $(wildcard $(SRC_DIR)/Datatypes/*.cpp) main.cpp
INC_FILES   = $(wildcard $(INC_DIR)/CasosDeUso/*.h) $(wildcard $(INC_DIR)/Clases/*.h) $(wildcard $(INC_DIR)/Datatypes/*.h)
OBJ_FILES   = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# CREA EL EJECUTABLE
$(TARGET): $(OBJ_FILES)
	g++ $(CFLAGS) $^ -o $@

# COMPILAR LOS ARCHIVOS CPP
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(INC_FILES) | create_dirs
	g++ -I$(INC_DIR) -c $(CFLAGS) $< -o $@

# Compilar main.cpp
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_FILES) | create_dirs
	g++ -I$(INC_DIR) -c $(CFLAGS) $< -o $@

# Crear subcarpetas dentro de obj
.PHONY: create_dirs
create_dirs:
	@mkdir -p $(OBJ_DIR)/CasosDeUso
	@mkdir -p $(OBJ_DIR)/Clases
	@mkdir -p $(OBJ_DIR)/Datatypes

# BORRA LOS .o Y EL EJECUTABLE SI EXISTEN
.PHONY: clean
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
	rm -rf $(OBJ_DIR)/CasosDeUso
	rm -rf $(OBJ_DIR)/Clases
	rm -rf $(OBJ_DIR)/Datatypes

# EJECUTAR EL PROGRAMA
.PHONY: run
run: $(TARGET)
	./$(TARGET)
