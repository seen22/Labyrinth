#include <fstream>
#include <sstream>
#include "Arena.h"


/**
 * @brief Die GameLogic Klasse implementiert das Spielmechanismus für das Spiel.
 *
 * Die Klasse GameLogic verwaltet das Spielfeld und die Regeln für das Spiel.
 * Es enthält auch die Methoden, um das Spiel auszuführen und dessen Fortschritt zu verfolgen.
 */
class GameLogic
{
      /**
     * @brief Arena-Objekt, das die Spielfeld-Informationen speichert
     */
    Arena newArena;

    /**
     * @brief Zählt die Anzahl der Spielzüge
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
     * @brief Zeiger auf ein 2D-Array, das das Spielfeld repräsentiert
     */
    char** gamePlayMap;

public:
    /**
     * @brief Konstruktor für die Klasse GameLogic
     */
    GameLogic();

    /**
     * @brief Führt das Spiel aus
     */
    void gamePlay();
};

