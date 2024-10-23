# University Team Project - Data Structrures

This repository contains the work developed by a team of students from the Computer Engineering and Informatics Department (CEID) at the University of Patras, for the Data Structures course.

## Team members:
- [Karamalikis Andreas](https://github.com/Andreaskaram)
- [Katsaros Georgios](https://github.com/KatsarosG)
- [Kotsalos Ioannis](https://github.com/GiannisKotsalos)
- [Papagianoulis Georgios](https://github.com/georgePpg)

##
The aim of this project is to apply and compare different classification and search algorithms to a dataset consisting of local birth and death counts. The main objectives are to run efficient classification and search algorithms on this data and analyze their performance. For the second part, structures such as Binary Search Trees (BSTs) and Hash Tables are used to implement efficient techniques for storing, retrieving and manipulating these data.

## Detailed Report:
The detailed report can be found [here](https://github.com/KatsarosG/Data-Structures-Project/blob/main/Report.pdf) (Language: Greek).

## Data source :
[stats.govt.nz](https://www.stats.govt.nz/large-datasets/csv-files-for-download/) > Population > "Births and deaths: Year ended December 2022 – CSV" > bd-dec22-births-deaths-natural-increase.csv

## Execution instructions:
The data file should be named bd-dec22-births-deaths-by-region.csv and should be located in the same directory as the executable.
Along with the requested files, we have included a makefile file for easier execution of the programs. Below are the commands.

### Part I.1
```
make part11
./partI.1.out
```
or alternatively without the make:
```
g++ -c basicFunctions.cpp
g++ -c sortingFunctions.cpp
g++ -c PartI.1.cpp
g++ -o partI.1.out basicFunctions.o sortingFunctions.o PartI.1.o
./partI.1.out
```

### Part I.2
```
make part12
./partI.2.out
```

or alternatively without the make:
```
g++ -c basicFunctions.cpp
g++ -c sortingFunctions.cpp
g++ -c PartI.2.cpp
g++ -o partI.2.out basicFunctions.o sortingFunctions.o PartI.2.o
./partI.2.out
```

### Part I.3
```
make part13
./partI.3.out
```

or alternatively without the make:
```
g++ -c basicFunctions.cpp
g++ -c sortingFunctions.cpp
g++ -c searchFunctions.cpp
g++ -c PartI.3.cpp
g++ -o partI.3.out searchFunctions.o basicFunctions.o sortingFunctions.o PartI.3.o
./partI.3.out
```

### Part I.4
```
make part14
./partI.4.out
```

or alternatively without the make:
```
g++ -c basicFunctions.cpp
g++ -c sortingFunctions.cpp
g++ -c searchFunctions.cpp
g++ -c PartI.4.cpp
g++ -o partI.4.out searchFunctions.o basicFunctions.o sortingFunctions.o PartI.4.o
./partI.4.out
```

### Part II
```
make part2
./partII.out
```

or alternatively without the make:
```
g++ -c basicFunctions.cpp
g++ -c sortingFunctions.cpp
g++ -c searchFunctions.cpp
g++ -c PartII.B.cpp
g++ -c PartII.A.cpp
g++ -c PartII.C.cpp
g++ -c PartII.cpp
g++ -o partII.out PartII.C.o PartII.B.o PartII.A.o searchFunctions.o basicFunctions.o
./partII.out
```
