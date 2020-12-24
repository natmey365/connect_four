#======================================================
# Files and directories
#======================================================
C4_LIB            := connect_four
NN_LIB            := neural_network
SRC_DIR           := src
INC_DIR           := inc
TEST_DIR          := test
BIN_DIR           := bin
NN_DIR            := ../neural_network

SRC_FILES     := $(wildcard $(SRC_DIR)/*.cpp)
INC_FILES     := $(wildcard $(INC_DIR)/*.h)
BINS          := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%,$(SRC_FILES))

#======================================================
# Compiler and flags
#======================================================
CPP            := g++
COMPILE_FLAGS  := -Wall -I$(INC_DIR) -I../inc -I../neural_network/inc -L../ -L../$(NN_DIR) -l_$(C4_LIB) -l_$(NN_LIB)

#======================================================
# Targets
#======================================================
.PHONY: test

all: test

#=========
# Run
#=========
test: compile
	@echo "============================================="; \
	 echo "= Running Tests                             ="; \
 	 echo "============================================="
	@for test in $(BINS); do \
		echo "./$$test"; \
		./$$test $(OPTS); \
		if [ $$? -ne 0 ]; then \
			echo "Failed $$test"; \
			break; \
		fi; \
	done

#=========
# Build
#=========
compile:
	@echo "============================================="; \
	 echo "= Compiling Tests                           ="; \
 	 echo "============================================="
	$(MAKE) $(BINS)

$(BIN_DIR)/%: src/%.cpp inc/%.h | $(BIN_DIR)
	$(CPP) $(COMPILE_FLAGS) -o $@ $<

$(BIN_DIR):
	mkdir -p $@

#=========
# Clean
#=========
clean:
	rm -rf bin

#======================================================
# Testing
#======================================================
bins:
	@echo $(BINS)
