CC = gcc
AR = ar
OBJ_LOOPS = basicClassification.o advancedClassificationLoop.o
OBJ_RECURSIVES = basicClassification.o advancedClassificationRecursion.o
OBJ_RECURSIVED = basicClassification.o advancedClassificationRecursion.o
OBJ_LOOPD = basicClassification.o advancedClassificationLoop.o
FLAGS = -Wall -g


all: loops recursives recursived loopd mains maindloop maindrec

loops: libclassloops.a

recursives: libclassrec.a

recursived: libclassrec.so

loopd: libclassloops.so


libclassloops.a: $(OBJ_LOOPS)
	$(AR) -rcs libclassloops.a $(OBJ_LOOPS)

libclassrec.a: $(OBJ_RECURSIVES) 
	$(AR) -rcs libclassrec.a $(OBJ_RECURSIVES)

libclassrec.so: $(OBJ_RECURSIVED)
	$(CC) -shared -o libclassrec.so $(OBJ_RECURSIVED)

libclassloops.so: $(OBJ_LOOPD)
	$(CC) -shared -o libclassloops.so $(OBJ_LOOPD)


basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c

advancedClassifictionLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c

advancedClassifictionRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c

mains: main.o libclassrec.a
	$(CC) $(FLAGS) -o mains main.o libclassrec.a  

maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so

maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c -o main.o



.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maindrec maindloop