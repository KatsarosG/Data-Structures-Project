CC = g++
# Για να γίνει ενα λειτουργικό main.out αρχειο πρεπει να υπάρχουν τα object files που περιέχουν τον εκτελέσιμο κωδικα των συναρτίσεων που καλεί η main. Για να γίνει αυτό με το g++ -c δημιουργούμε το καθε ενα object file (.o) και στο τελος τα κανουμε link.
main:
	$(CC) -c basicFunctions.cpp		# Make object file for basicFunctions.cpp
	$(CC) -c main.cpp				# Make object file for main.cpp
	$(CC) -c sortingFunctions.cpp	# Make object file for sortingFunctions.cpp
	$(CC) -o main.out basicFunctions.o sortingFunctions.o main.o	# Link object files together to create main.out

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
