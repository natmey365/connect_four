#======================================================
# Files and directories
#======================================================
EXECUTABLE   := main
SRC_DIR      := src
NN_SRC_DIR   := neural_network/src
INC_DIR      := inc
NN_INC_DIR   := neural_network/inc
OBJ_DIR      := obj
SRC_FILES    := $(wildcard $(SRC_DIR)/*.cpp)
NN_SRC_FILES := $(wildcard $(NN_SRC_DIR)/*.cpp)
OBJ_FILES    := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES)) \
                $(patsubst $(NN_SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(NN_SRC_FILES))

#======================================================
# Compiler and flags
#======================================================
CXX         :=
CPP         := g++
LDFLAGS     :=
CPPFLAGS    := -I$(INC_DIR) -I$(NN_INC_DIR)
CXXFLAGS    := -Wall

#======================================================
# Targets
#======================================================
.PHONY: clean

# Targets
$(EXECUTABLE): $(OBJ_FILES)
	$(CPP) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h
	$(CPP) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

# Compile neural_network repository files
$(OBJ_DIR)/%.o: $(NN_SRC_DIR)/%.cpp $(NN_INC_DIR)/%.h
	$(CPP) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

all: $(OBJ_FILES)

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p ./obj

clean:
	rm -rf $(OBJ_DIR)  $(EXECUTABLE)
