#include "superc.h"

int main() {
    println("¡Bienvenido al programa!");

    char* texto = inputLine("Ingresa una línea de texto: ");
    int numero = inputInt("Ingresa un número entero: ");
    float flotante = inputFloat("Ingresa un número flotante: ");

    println("Mostrando valores ingresados:");
    println(texto);
    free(texto);

    char* contenido = readfile("ejemplo.txt");
    if (contenido != NULL) {
        println("Contenido del archivo:");
        println(contenido);
        free(contenido);
    }

    timerStart();
    for (int i = 0; i < 1000000; i++) {} // Simula trabajo
    double tiempo = timerStop();
    println("Tiempo transcurrido:");
    printf("%.6f segundos\n", tiempo);

    logmsg("Todo salió bien.");

    print("Texto sin salto.");
    println(" <- ahora con salto");

    char* minusculas = toLower("HOLA MUNDO");
    println(minusculas);
    free(minusculas);

    char* mayusculas = toUpper("hola mundo");
    println(mayusculas);
    free(mayusculas);

    randInit();
    int aleatorio = randRange(1, 10);
    printf("Número aleatorio: %d\n", aleatorio);

    List* lista = newList();
    listAdd(lista, "uno");
    listAdd(lista, "dos");
    listAdd(lista, "tres");

    println("Elemento en índice 1:");
    println(listGet(lista, 1));

    printf("Tamaño de la lista: %d\n", listSize(lista));
    freeList(lista);

    Map* mapa = newMap();
    mapPut(mapa, "clave1", "valor1");
    mapPut(mapa, "numero", intToStr(123));

    println("Valor de 'clave1':");
    println(mapGet(mapa, "clave1"));

    println("Valor de 'numero':");
    println(mapGet(mapa, "numero"));

    freeMap(mapa);

    printf("Máximo: %d\n", max(10, 20));
    printf("Mínimo: %d\n", min(10, 20));

    return 0;
}
