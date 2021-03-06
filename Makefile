#======================================================
# Files and directories
#======================================================
LIB          := lib_connect_four.a
SRC_DIR      := src
INC_DIR      := inc
NN_DIR       := neural_network
TEST_DIR     := test
OBJ_DIR      := obj

SRC_FILES    := $(wildcard $(SRC_DIR)/*.cpp)
INC_FILES    := $(wildcard $(INC_DIR)/*.h)
OBJS         := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

#======================================================
# Compiler, Archiver, and flags
#======================================================
CPP            := g++
COMPILE_FLAGS  := -Wall -I$(INC_DIR) -I$(NN_DIR)/inc
AR             := ar rcs
AR_FLAGS       :=

#======================================================
# Targets
#======================================================
.PHONY: clean test

all: $(LIB)

#=========
# Library
#=========
lib: $(LIB)
connect_four: $(LIB)
$(LIB): lib_deps lib_objs
	@echo "============================================="; \
	 echo "= Building $(LIB)               ="; \
	 echo "============================================="
	$(AR) $@ $(OBJS) $(NN_DIR)/lib_neural_network.a

lib_deps:
	$(MAKE) -C $(NN_DIR) neural_network

$(OBJ_DIR)/%.o: src/%.cpp inc/%.h | $(OBJ_DIR)
	$(CPP) $(COMPILE_FLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

lib_objs:
	@echo "============================================="; \
	 echo "= Compiling $(LIB) objects      ="; \
 	 echo "============================================="
	$(MAKE) $(OBJS)

#=========
# Test
#=========
test: $(LIB)
	@echo "============================================="; \
	 echo "= make test                                 ="; \
	 echo "============================================="
	$(MAKE) -C $(TEST_DIR)

#=========
# Clean
#=========
clean:
	$(MAKE) -C $(NN_DIR) clean
	$(MAKE) -C $(TEST_DIR) clean
	rm -rf $(OBJ_DIR)

#======================================================
# Testing
#======================================================
try:
	@echo $(NN_DIR)/inc 
