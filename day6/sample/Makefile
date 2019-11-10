CC=g++
GPP_FLAGS=--std=c++11
OBJ=Auto.o Main.o
auto: clean $(OBJ)
	$(CC) -o auto $(OBJ) $(GPP_FLAGS)
%.o: %.cpp
	$(CC) -c $< $(GPP_FLAGS)

clean:
	ls -l
	rm auto *.o
	ls -l
	