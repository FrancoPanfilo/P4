CXX = g++
CXXFLAGS = -Wall -std=c++11

SRC = ejemplo_main_2026.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = programa

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET).exe $(TARGET)
