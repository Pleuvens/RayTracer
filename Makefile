CC= g++

OBJ= \
     main.o

VPATH= src/

Raytracer: $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o Raytracer

clean:
	$(RM) $(OBJ) Raytracer
