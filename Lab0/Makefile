CXX = g++
CXXFLAGS = -Wall -std=c++11
OBJDIR = o

SRC = ejemplo_main_2026.cpp \
      cpp/turista.cpp \
      cpp/DTFecha.cpp \
      cpp/experiencia.cpp \
      cpp/alojamiento.cpp \
      cpp/tourGuiado.cpp \
      cpp/eventoCultural.cpp \
      cpp/DTExpe.cpp

OBJ = $(patsubst %.cpp,$(OBJDIR)/%.o,$(notdir $(SRC)))
TARGET = programa

all: $(OBJDIR) $(TARGET)

$(OBJDIR):
	mkdir $(OBJDIR)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/%.o: cpp/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /f /q $(subst /,\,$(OBJ)) $(TARGET).exe $(TARGET) 2>nul || true
