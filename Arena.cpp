#include <iostream>
#include <fstream>
#include <sstream>
#include "Arena.h"

Arena::Arena()
{

}
Arena::Arena(const Arena& arenaCopy)
{
    h=arenaCopy.h;
    w=arenaCopy.w;
    playerStartX=arenaCopy.playerStartX;
    playerStartY=arenaCopy.playerStartY;
    DX=arenaCopy.DX;
    DY=arenaCopy.DY;
    mymap=arenaCopy.mymap;

}
void Arena::processFile(std::ifstream& inFile)                //Liest eine Datei ein, die den Inhalt der Areana beschreibt und speichet ihn in einem char-Array

{
    char ch, ch1;
    while (inFile >> std::noskipws >> ch)
    {
        if (ch!='*')
        {
            if(i==0)
            {
                if(ch=='\n')
                {
                    i++;
                    j=0;
                    continue;
                }
                if(ch==' ')
                {
                    j++;
                    continue;
                }
                if (j==0)
                    h = int(ch - '0');
                else
                    w = int(ch - '0');
            }
            else if(i==1)
            {
                if(ch=='\n')
                {
                    i++;
                    j=0;
                    continue;
                }
                if(ch==' ')
                {
                    j++;
                    continue;
                }
                else if (j==0)
                    playerStartX = int(ch - '0');
                else
                    playerStartY = int(ch - '0');
            }
            else if(i==2)
            {
                if(ch=='\n')
                {
                    i++;
                    j=0;
                    continue;
                }
                if(ch==' ')
                {
                    j++;
                    continue;
                }
                else if (j==0)
                    DX = int(ch - '0');
                else
                    DY = int(ch - '0');
            }
        }
        else
            i++;
    }
    inFile.clear();
    inFile.seekg(15);
    mymap=new char*[(h)];
    for (int q=0; q<h; q++)
        mymap[q]=new char[w];
    while (inFile >> std::noskipws >> ch1)
    {
        if(ch1=='*'||ch1==' '||ch1=='\n')
        {

            if (ch1=='*'||ch1==' ')
            {
                mymap[rowNumber][columnNumber] = ch1;
                columnNumber++;
            }
            else
            {
                rowNumber++;
                columnNumber=0;
            }
        }
    }
}

void Arena::saveArena(std::string fname, int counter)       //speichert der aktuellen Zustand der Arena in einer Datei.

{
    std::ofstream outFile;
    outFile.open(fname);
    outFile<<std::to_string(h)<<" "<<std::to_string(w)<<std::endl;
    outFile<<std::to_string(playerStartX)<<" "<<std::to_string(playerStartY)<<std::endl;
    outFile<<std::to_string(DX)<<" "<<std::to_string(DY)<<std::endl;
    outFile<<std::to_string(counter)<<std::endl;
    for(int q=0; q<h; q++)
    {
        for(int k=0; k<w; k++)
        {
            outFile<<mymap[q][k];
        }                                                //Schreibt die karte Zeile für Zeile in eine Datei
        outFile<<std::endl;
    }
}
std::ifstream Arena::openFile(std::string fname)         //Datei eoffnen
{
    std::ifstream inFile;
    inFile.open(fname);
    if (inFile.is_open())
    {
        return inFile;
    }

    else
        exit(-1);
}
std::ifstream Arena::loadArena(std::string fname1)      //lädet eine Datei mit dem gegebenen Dateinamen, um die Arena zu erstellen.

{
    int line=0;
    char ch2, ch3;
    std::ifstream inFile;
    inFile.open(fname1);

    while (inFile >> std::noskipws >> ch2)
    {
        if (ch2!='*')
        {
            if(i==0)
            {
                if(ch2=='\n')
                {
                    i++;
                    j=0;
                    continue;
                }
                if(ch2==' ')
                {
                    j++;
                    continue;
                }
                if (j==0)
                    h = int(ch2 - '0');
                else
                    w = int(ch2 - '0');
            }
            else if(i==1)
            {
                if(ch2=='\n')
                {
                    i++;
                    j=0;
                    continue;
                }
                if(ch2==' ')
                {
                    j++;
                    continue;
                }
                else if (j==0)
                    playerStartX = int(ch2 - '0');
                else
                    playerStartY = int(ch2 - '0');
            }
            else if(i==2)
            {
                if(ch2=='\n')
                {
                    i++;
                    j=0;
                    continue;
                }
                if(ch2==' ')
                {
                    j++;
                    continue;
                }
                else if (j==0)
                    DX = int(ch2 - '0');
                else
                    DY = int(ch2 - '0');
            }
            else if(i==3)
            {
                if(ch2=='\n')
                {
                    i++;
                    j=0;
                    continue;
                }
                if(ch2==' ')
                {
                    j++;
                    continue;
                }
                else
                    counter = int(ch2 - '0');
            }
        }
        else
            i++;
    }
    inFile.clear();
    inFile.seekg(18);
    mymap=new char*[(h)];
    for (int q=0; q<h; q++)
        mymap[q]=new char[w];
    while (inFile >> std::noskipws >> ch3)
    {
        if(ch3=='*'||ch3==' '||ch3=='\n'||ch3=='+'||ch3=='e'||ch3=='.')
        {

            if (ch3=='*'||ch3==' '||ch3=='+'||ch3=='e'||ch3=='.')
            {
                mymap[rowNumber][columnNumber] = ch3;
                columnNumber++;
            }
            else
            {
                rowNumber++;
                columnNumber=0;
            }
        }
    }
    return inFile;
}

int* Arena::getPlayerPosition()         //gibt die Position des Spielers zurück.

{
    static int playerPostionsArray[2];

    playerPostionsArray[0] = playerStartX;
    playerPostionsArray[1] = playerStartY;
    return playerPostionsArray;
}
int* Arena::getDestination()            //gibt des Ziel des Spielers zurück.

{
    static int destination[2];
    destination[0] = DX;
    destination[1] = DY;
    return destination;
}
int* Arena::getDimentions()              //gibt die Abmessung der Arena zurück.

{
    static int dimentions[2];
    dimentions[0] = h;
    dimentions[1] = w;
    return dimentions;
}
char** Arena::getArena()                //gibt die Arena zurück.

{
    return mymap;
}

void Arena::printMap()
{
    for(int q=0; q<h; q++)
    {
        for(int k=0; k<w; k++)
        {
            std::cout<<mymap[q][k];
        }
        std::cout<<std::endl;
    }
}
void Arena::setPlayerPosition(int x, int y)     //setzt die Startposition des Spielers im Labyrinth.

{
    playerStartX = x;
    playerStartY = y;
}
void Arena::setDestinationOnMap()               //setzt die Ziel im Labyrinth.

{
    mymap[DX][DY]='e';
}
void Arena::setPlayerOnMap()                   //setzt der Spieler im Labyrinth.

{
    mymap[playerStartX][playerStartY]='+';
}

void Arena::replacePlayerPosition(int x, int y)    //ändert die Position des Spielers im Labyrinth.

{
    mymap[x][y] = '.';
}
