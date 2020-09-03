#======================================================
# Files and directories
#======================================================
EXECUTABLES  := main

C4_DIR       := .
C4_SRC_DIR   := $(C4_DIR)/src
C4_INC_DIR   := $(C4_DIR)/inc
NN_DIR       := neural_network
NN_SRC_DIR   := $(NN_DIR)/src
NN_INC_DIR   := $(NN_DIR)/inc
OBJ_DIR      := obj
DEP_DIR      := $(OBJ_DIR)/.dep
SRC_DIRS     := $(SRC_DIR) $(NN_SRC_DIR)
INC_DIRS     := $(INC_DIR) $(NN_INC_DIR)
REPO_DIRS    := $(C4_DIR) $(NN_DIR)

C4_SRC_FILES    := $(wildcard $(C4_SRC_DIR)/*.cpp)
NN_SRC_FILES    := $(wildcard $(NN_SRC_DIR)/*.cpp)
C4_INC_FILES    := $(wildcard $(C4_INC_DIR)/*.h)
NN_INC_FILES    := $(wildcard $(NN_INC_DIR)/*.h)
OBJS            := $(patsubst $(C4_SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(C4_SRC_FILES)) \
                   $(patsubst $(NN_SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(NN_SRC_FILES))

#======================================================
# Compiler and flags
#======================================================
CPP            := g++
COMPILE_FLAGS  := -Wall -I$(C4_INC_DIR) -I$(NN_INC_DIR)
DEP_FLAGS      := -MT $$@ -MMD -MP -MF $(DEP_DIR)/$$*.d

#======================================================
# Includes
#======================================================
include makefiles/templates.mk

#======================================================
# Targets
#======================================================
.PHONY: clean

all: $(EXECUTABLES)

main: $(OBJS)
	@#cat obj/.dep/argParse.d
	@#cat obj/.dep/board.d
	$(CPP) -o $@ $^

$(foreach repo_dir,$(REPO_DIRS),$(eval $(call COMPILE_template,$(repo_dir))))

$(OBJ_DIR):
	mkdir -p $@

$(DEP_DIR): | $(OBJ_DIR)
	mkdir -p $@

.PRECIOUS: $(DEP_DIR)/%.d
$(DEP_DIR)/%.d: ;

#DEP_FILES := $(C4_SRC_FILES:%.cpp=$(DEP_DIR)/%.d) $(NN_SRC_FILES:%.cpp=$(NN_DEP_DIR)/%.d)
DEP_FILES := $(wildcard $(DEP_DIR)/*.d)
$(DEP_FILES):
include $(wildcard $(DEP_FILES))

clean:
	rm -rf $(OBJ_DIR) $(EXECUTABLES)

#======================================================
# Testing
#======================================================
C4_SRC_FILES:
	@echo $(C4_SRC_FILES)

deps: | $(DEP_DIR)
	$(CPP) $(COMPILE_FLAGS) -MM inc/board.h
	@#@echo $@:; \
	@#cat $(DEP_FILES)

dep_files: 
	@echo $(DEP_FILES)	
