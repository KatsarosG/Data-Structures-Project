CC = g++
# Για να γίνει ενα λειτουργικό main.out αρχειο πρεπει να υπάρχουν τα object files που περιέχουν τον εκτελέσιμο κωδικα των συναρτίσεων που καλεί η main. Για να γίνει αυτό με το g++ -c δημιουργούμε το καθε ενα object file (.o) και στο τελος τα κανουμε link.
main:
	$(CC) -c basicFunctions.cpp		# Make object file for basicFunctions.cpp
	$(CC) -c main.cpp				# Make object file for main.cpp
	$(CC) -c sortingFunctions.cpp	# Make object file for sortingFunctions.cpp
	$(CC) -c searchFunctions.cpp
	$(CC) -o main.out searchFunctions.o basicFunctions.o sortingFunctions.o main.o	# Link object files together to create main.out
  
part11:
	$(CC) -c basicFunctions.cpp
	$(CC) -c sortingFunctions.cpp
	$(CC) -c PartI.1.cpp
	$(CC) -o partI.1.out basicFunctions.o sortingFunctions.o PartI.1.o

part12:
	$(CC) -c basicFunctions.cpp
	$(CC) -c sortingFunctions.cpp
	$(CC) -c PartI.2.cpp
	$(CC) -o partI.2.out basicFunctions.o sortingFunctions.o PartI.2.o

part13:
	$(CC) -c basicFunctions.cpp
	$(CC) -c sortingFunctions.cpp
	$(CC) -c searchFunctions.cpp
	$(CC) -c PartI.3.cpp
	$(CC) -o partI.3.out searchFunctions.o basicFunctions.o sortingFunctions.o PartI.3.o

part14:
	$(CC) -c basicFunctions.cpp
	$(CC) -c sortingFunctions.cpp
	$(CC) -c searchFunctions.cpp
	$(CC) -c PartI.4.cpp
	$(CC) -o partI.4.out searchFunctions.o basicFunctions.o sortingFunctions.o PartI.4.o

part2a:
	$(CC) -c basicFunctions.cpp
	$(CC) -c sortingFunctions.cpp
	$(CC) -c searchFunctions.cpp
	$(CC) -c PartII.A.cpp
	$(CC) -o partII.A.out searchFunctions.o basicFunctions.o sortingFunctions.o PartII.A.o

part2b:
	$(CC) -c basicFunctions.cpp
	$(CC) -c sortingFunctions.cpp
	$(CC) -c searchFunctions.cpp
	$(CC) -c PartII.B.cpp
	$(CC) -o partII.B.out searchFunctions.o basicFunctions.o sortingFunctions.o PartII.B.o

part2c:
	$(CC) -c basicFunctions.cpp
	$(CC) -c sortingFunctions.cpp
	$(CC) -c searchFunctions.cpp
	$(CC) -c PartII.C.cpp
	$(CC) -o partII.C.out searchFunctions.o basicFunctions.o sortingFunctions.o PartII.C.o

part2:
	$(CC) -c basicFunctions.cpp
	$(CC) -c sortingFunctions.cpp
	$(CC) -c searchFunctions.cpp
	$(CC) -c PartII.B.cpp
	$(CC) -c PartII.A.cpp
	$(CC) -c PartII.C.cpp
	$(CC) -c PartII.cpp
	$(CC) -o partII.out PartII.C.o PartII.B.o PartII.A.o searchFunctions.o basicFunctions.o sortingFunctions.o PartII.o
