#include <fstream>
#include <sstream>
#include "Arena.h"


/**
 * @brief Die GameLogic Klasse implementiert das Spielmechanismus f�r das Spiel.
 *
 * Die Klasse GameLogic verwaltet das Spielfeld und die Regeln f�r das Spiel.
 * Es enth�lt auch die Methoden, um das Spiel auszuf�hren und dessen Fortschritt zu verfolgen.
 */
class GameLogic
{
      /**
     * @brief Arena-Objekt, das die Spielfeld-Informationen speichert
     */
    Arena newArena;

    /**
     * @brief Z�hlt die Anzahl der Spielz�ge
     */
    int counter=0;

    /**
     * @brief Zeiger auf ein Array, das die Spielfeldabmessungen speichert
     */
    int* arenaDimentions;

    /**
     * @brief Zeiger auf ein Array, das die Spielerpositionen speichert
     */
    int* playerPosition;

    /**
     * @brief Zeiger auf ein Array, das die Zielpositionen speichert
     */
    int* destination;

    /**
     * @brief Zeiger auf ein 2D-Array, das das Spielfeld repr�sentiert
     */
    char** gamePlayMap;

public:
    /**
     * @brief Konstruktor f�r die Klasse GameLogic
     */
    GameLogic();

    /**
     * @brief F�hrt das Spiel aus
     */
    void gamePlay();
};

