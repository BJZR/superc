#include "superc.h"

// Entrada
char* inputLine(const char* prompt) {
    printf("%s", prompt);
    char* buffer = malloc(1024);
    fgets(buffer, 1024, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    return buffer;
}

int inputInt(const char* prompt) {
    char* line = inputLine(prompt);
    int value = atoi(line);
    free(line);
    return value;
}

float inputFloat(const char* prompt) {
    char* line = inputLine(prompt);
    float value = atof(line);
    free(line);
    return value;
}

// Archivos
char* readfile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    long len = ftell(file);
    rewind(file);

    char* buffer = malloc(len + 1);
    fread(buffer, 1, len, file);
    buffer[len] = '\0';

    fclose(file);
    return buffer;
}

// Temporizador
static clock_t start_time;

void timerStart() {
    start_time = clock();
}

double timerStop() {
    return (double)(clock() - start_time) / CLOCKS_PER_SEC;
}

// Consola
void print(const char* msg) {
    printf("%s", msg);
}

void println(const char* msg) {
    printf("%s\n", msg);
}

void logmsg(const char* msg) {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    printf("[%02d:%02d:%02d] %s\n", t->tm_hour, t->tm_min, t->tm_sec, msg);
}

// Texto
char* toLower(const char* str) {
    char* res = strdup(str);
    for (int i = 0; res[i]; i++) res[i] = tolower(res[i]);
    return res;
}

char* toUpper(const char* str) {
    char* res = strdup(str);
    for (int i = 0; res[i]; i++) res[i] = toupper(res[i]);
    return res;
}

// Aleatorio
void randInit() {
    srand((unsigned int)time(NULL));
}

int randRange(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Lista
List* newList() {
    List* list = malloc(sizeof(List));
    list->items = malloc(sizeof(char*) * 10);
    list->size = 0;
    list->capacity = 10;
    return list;
}

void listAdd(List* list, const char* value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->items = realloc(list->items, sizeof(char*) * list->capacity);
    }
    list->items[list->size++] = strdup(value);
}

char* listGet(List* list, int index) {
    if (index < 0 || index >= list->size) return NULL;
    return list->items[index];
}

int listSize(List* list) {
    return list->size;
}

void freeList(List* list) {
    for (int i = 0; i < list->size; i++) free(list->items[i]);
    free(list->items);
    free(list);
}

// Mapa
Map* newMap() {
    Map* map = malloc(sizeof(Map));
    map->keys = malloc(sizeof(char*) * 10);
    map->values = malloc(sizeof(char*) * 10);
    map->size = 0;
    map->capacity = 10;
    return map;
}

void mapPut(Map* map, const char* key, const char* value) {
    for (int i = 0; i < map->size; i++) {
        if (strcmp(map->keys[i], key) == 0) {
            free(map->values[i]);
            map->values[i] = strdup(value);
            return;
        }
    }
    if (map->size == map->capacity) {
        map->capacity *= 2;
        map->keys = realloc(map->keys, sizeof(char*) * map->capacity);
        map->values = realloc(map->values, sizeof(char*) * map->capacity);
    }
    map->keys[map->size] = strdup(key);
    map->values[map->size++] = strdup(value);
}

char* mapGet(Map* map, const char* key) {
    for (int i = 0; i < map->size; i++) {
        if (strcmp(map->keys[i], key) == 0)
            return map->values[i];
    }
    return NULL;
}

void freeMap(Map* map) {
    for (int i = 0; i < map->size; i++) {
        free(map->keys[i]);
        free(map->values[i]);
    }
    free(map->keys);
    free(map->values);
    free(map);
}

// Utilidades
char* intToStr(int value) {
    char* str = malloc(20);
    sprintf(str, "%d", value);
    return str;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}
