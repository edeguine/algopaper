CXX=g++

CXXFLAGS=-g -std=c++11 `libpng-config --cflags` -I/Users/etienne/Algopaper/cpp/src
LDFLAGS=-g `libpng-config --ldflags` -L/Users/etienne/Algopaper/cpp/src

SRC_DIR=../src
OBJ_DIR=./obj
SRC_FILES=$(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

SRC_TEST_FILES=test.cpp
OBJ_TEST_FILES=$(OBJ_DIR)/test.o

info:
	$(info    VAR is $(SRC_FILES))
	$(info    VAR is $(OBJ_FILES))
	$(info    VAR is $(SRC_TEST_FILES))
	$(info    VAR is $(OBJ_TEST_FILES))

clean:
	rm -f obj/*.o
obj:
	mkdir -p $@

test: $(OBJ_FILES) $(OBJ_TEST_FILES)
	g++ $(LDFLAGS) -o $@ $^

$(OBJ_TEST_FILES): $(SRC_TEST_FILES)
	g++ $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp 
	g++ $(CXXFLAGS) -c -o $@ $<
