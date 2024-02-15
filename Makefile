CXX = g++
CXXFLAGS = -std=c++11
LIBS = -lkrpc -lprotobuf -lz

SRC = main.cpp spacecraft/*.cpp
TARGET = spacecraft_autopilot.run

all: build run

build: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
