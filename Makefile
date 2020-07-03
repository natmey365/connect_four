SRC_DIR   := ./src
OBJ_DIR   := ./obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS   :=
CPPFLAGS  :=
CXXFLAGS  :=

main: $(OBJ_FILES)
	g++ $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p build
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<
