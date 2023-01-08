CXX = g++
CXXFLAGS = -ansi -pedantic -Wall -std=c++11
EXEC = Main

all: $(EXEC)


Main: Main.o Utilisateur.o Client.o Cleaner.o Capteur.o Gouvernement.o Fournisseur.o Attribut.o Mesure.o
	$(CXX) -o $@ $^

Main.o: Main.cpp 
	$(CXX) -o $@ -c $< $(CXXFLAGS)

Utilisateur.o: Utilisateur.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

Client.o: Client.cpp 
	$(CXX) -o $@ -c $< $(CXXFLAGS)

Cleaner.o: Cleaner.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

Capteur.o: Capteur.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

Gouvernement.o: Gouvernement.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

Fournisseur.o: Fournisseur.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

Attribut.o: Attribut.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

Mesure.o: Mesure.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)
	
clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)