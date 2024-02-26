#ifndef ARENA_H
#define ARENA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


class Arena
{
public:
 /**
 * @class Arena
 * @brief Die Klasse Arena repräsentiert eine Arena, die aus einer 2D-Matrix besteht.
 *
 * Die Arena-Klasse enthält Funktionen zum Laden, Speichern und Verarbeiten von Dateien, um eine Arena-Karte zu erstellen, sowie Funktionen zum Zugreifen auf Eigenschaften der Arena, wie Spielerposition, Zielposition und Größe.
 */
    Arena();
     /**
     * @brief Kopierkonstruktor.
     * @param arenaCopy Referenz auf die zu kopierende Arena.
     */
    Arena(const Arena& arenaCopy);
       /**
     * @brief Öffnet eine Datei mit einem Labyrinth
     * @param fname - Name der Datei
     * @return ifstream-Objekt zur Verarbeitung der Datei
     */
    std::ifstream openFile(std::string fname);
     /**
     * @brief Speichert eine Arena in einer Datei
     * @param fname - Name der Datei
     * @param counter - Anzahl der Schritte des Spielers
     */
    void saveArena(std::string fname, int counter);
      /**
     * @brief Lädt eine gespeicherte Arena aus einer Datei
     * @param fname1 - Name der Datei
     * @return ifstream-Objekt zur Verarbeitung der geladenen Arena
     */
    std::ifstream loadArena(std::string fname1);
    /**
     * @brief Verarbeitet eine geöffnete Datei mit einem Labyrinth
     * @param inFile - Referenz auf das ifstream-Objekt zur Datei
     */
    void processFile(std::ifstream& inFile);
       /**
     * @brief Gibt die Position des Spielers im Labyrinth zurück
     * @return Pointer auf ein Array mit den Koordinaten des Spielers
     */
     int* getPlayerPosition();
     /**
     * @brief Gibt das Ziel im Labyrinth zurück
     * @return Pointer auf ein Array mit den Koordinaten des Zieles
     */
    int* getDestination();

    /**
     * @brief Gibt die Dimensionen des Labyrinths zurück
     * @return Pointer auf ein Array mit den Dimensionen des Labyrinths
     */
    int* getDimentions();

    /**
     * @brief Gibt das Labyrinth als 2D-Array zurück
     * @return Pointer auf das Labyrinth als 2D-Array
     */
    char** getArena();

    /**
     * @brief Druckt das Labyrinth auf der Konsole aus
     */
    void printMap();

    /**
     * @brief Setzt die Position des Spielers im Labyrinth
     */
    void setPlayerPosition(int x, int y);

    /**
     * @brief Setzt das Ziel im Labyrinth
     */
    void setDestinationOnMap();

    /**
     * @brief Setzt den Spieler im Labyrinth
     */
    void setPlayerOnMap();
 /**
   * @brief Ändert die Position des Spielers auf der Karte.
   * @param x X-Koordinate des neuen Spielerstandorts.
   * @param y Y-Koordinate des neuen Spielerstandorts.
   */
    void replacePlayerPosition(int x, int y);


    private:

    int rowNumber=0, columnNumber=0, counter=0;

   // Höhe des Spielfelds
    int h=0;

    //Breite des Spielfelds
    int w=0;

     // X-Koordinate des Startpunkts des Spielers
    int playerStartX=0;

    // Y-Koordinate des Startpunkts des Spielers
    int playerStartY=0;

    //X-Koordinate des Zielpunkts
    int DX=0;

    //Y-Koordinate des Zielpunkts
    int DY=0;

     //Schleifenvariable für Zeilen
    int i=0;

     //Schleifenvariable für Spalten
    int j=0;

    //Dateiname des Spielfelds
    std::string fname;

    // Dynamisches 2D-Array, das die Map des Spielfelds darstellt
    char **mymap;

};
#endif
