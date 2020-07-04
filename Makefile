EXECUTABLE := main
SRC_DIR    := ./src
NN_SRC_DIR := ./neural_network/src/
INC_DIR    := ./inc
NN_INC_DIR := ./neural_network/inc/
OBJ_DIR    := ./obj
SRC_FILES  := $(wildcard $(SRC_DIR)/*.cpp) 
OBJ_FILES  := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS    :=
CPPFLAGS   :=
CXXFLAGS   := -Wall

.PHONY: clean

$(EXECUTABLE): $(OBJ_FILES)
	g++ $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h
	@mkdir -p obj
	g++ $(CPPFLAGS) $(CXXFLAGS) -I$(INC_DIR) -I$(NN_INC_DIR) -c -o $@ $<

clean:
	rm -rf ./obj/ ./$(EXECUTABLE)
