.POSIX:

TARGET = pxemi
OBJ = pxemInterpreter.o pxem.o
SRC = $(OBJ:.o=.cpp)

.SUFFIXES: .cpp .o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $?

$(OBJ): $(SRC)

pxemInterpreter.o: pxemInterpreter.cpp

pxem.o: pxem.cpp

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
