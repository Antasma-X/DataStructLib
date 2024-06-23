CC=gcc
CFlags = -Wall -g 

all: DataStructures.a

SinglyLinkedLists.o: src/SinglyLinkedLists.c 
	$(CC) $(CFlags) -c $^

DoublyLinkedLists.o: src/DoublyLinkedLists.c 
	$(CC) $(CFlags) -c $^

Queues.o: src/Queues.c  SinglyLinkedLists.o
	$(CC) $(CFlags) -c $^

Graphs.o: src/Graphs.c
	$(CC) $(CFlags) -c $^

BinaryTrees.o: src/BinaryTrees.c
	$(CC) $(CFlags) -c $^

Stacks.o: src/Stacks.c 
	$(CC) $(CFlags) -c $^


DataStructures.a: Stacks.o DoublyLinkedLists.o Queues.o SinglyLinkedLists.o BinaryTrees.o Graphs.o
	ar rcs $@ $^
clean:
	rm *.o 