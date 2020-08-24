#======================================================
# Files and directories
#======================================================
EXECUTABLES  := main
SRC_DIR      := src
INC_DIR      := inc
OBJ_DIR      := obj
NN_DIR       := neural_network
NN_SRC_DIR   := $(NN_DIR)/src
NN_INC_DIR   := $(NN_DIR)/inc
NN_OBJ_DIR   := $(NN_DIR)/obj

SRC_FILES    := $(wildcard $(SRC_DIR)/*.cpp)
NN_SRC_FILES := $(wildcard $(NN_SRC_DIR)/*.cpp)
OBJ_FILES    := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES)) \
                $(patsubst $(NN_SRC_DIR)/%.cpp,$(NN_OBJ_DIR)/%.o,$(NN_SRC_FILES))

#======================================================
# Compiler and flags
#======================================================
CPP         := g++
LDFLAGS     := 
CPPFLAGS    := -Wall -I$(INC_DIR) -I$(NN_INC_DIR)

#======================================================
# Targets
#======================================================
.PHONY: clean

all: $(EXECUTABLES)

# Targets
main: $(OBJ_FILES)
	$(CPP) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h | $(OBJ_DIR)
	$(CPP) $(CPPFLAGS) -c -o $@ $<

# Compile neural_network repository files
$(NN_OBJ_DIR)/%.o: $(NN_SRC_DIR)/%.cpp $(NN_INC_DIR)/%.h | $(NN_OBJ_DIR)
	$(CPP) $(CPPFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NN_OBJ_DIR):
	mkdir -p $(NN_OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)/* $(NN_OBJ_DIR)/* $(EXECUTABLES)
