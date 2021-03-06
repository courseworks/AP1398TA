CXX = g++
CXXFLAGS = -std=c++17 -Wall -I -c
LXXFLAGS = -std=c++17 -Ih -pthread
OBJECTS = main.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS)
./obj/main.o: ./cpp/main.cpp
	$(CXX) $(CXXFLAGS) ./cpp/main.cpp -o ./obj/main.o
clean:
	rm -fv $(TARGET) $(OBJECTS)
