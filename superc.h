#ifndef SUPERC_H
#define SUPERC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char** items;
    int size;
    int capacity;
} List;

typedef struct {
    char** keys;
    char** values;
    int size;
    int capacity;
} Map;

// Entrada
char* inputLine(const char* prompt);
int inputInt(const char* prompt);
float inputFloat(const char* prompt);

// Archivos
char* readfile(const char* filename);

// Temporizador
void timerStart();
double timerStop();

// Consola
void print(const char* msg);
void println(const char* msg);
void logmsg(const char* msg);

// Texto
char* toLower(const char* str);
char* toUpper(const char* str);

// Aleatorio
void randInit();
int randRange(int min, int max);

// Lista
List* newList();
void listAdd(List* list, const char* value);
char* listGet(List* list, int index);
int listSize(List* list);
void freeList(List* list);

// Mapa
Map* newMap();
void mapPut(Map* map, const char* key, const char* value);
char* mapGet(Map* map, const char* key);
void freeMap(Map* map);

// Utilidades
char* intToStr(int value);
int max(int a, int b);
int min(int a, int b);

#endif
