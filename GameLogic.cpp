#include <iostream>
#include <fstream>
#include <sstream>
#include "Arena.h"
#include "GameLogic.h"

GameLogic::GameLogic(){

}
void GameLogic::gamePlay()
{
    char playOrder, choice;
    std::ifstream inFile;
    std::cout<<"Do you want to start a new game or load an old game(N for new game or D for load an old game)"<<std::endl;
    while (true)
    { std::cin>>choice;
        // 1.open file
        if(choice=='N'||choice=='n')
        {

            inFile = newArena.openFile("new.txt");
            newArena.processFile(inFile);                   //öffnet eine Datei.
            break;
        }
        else if(choice=='D'||choice=='d')
        {
            inFile=newArena.loadArena("save.txt");          //lädt eine gespeicherte Arena.
            break;
        }
        else
        {
            std::cout<<"please try again. N for new game and D for load an old game"<<std::endl;
        }
    }
    playerPosition = newArena.getPlayerPosition();
    destination = newArena.getDestination();
    arenaDimentions = newArena.getDimentions();
    gamePlayMap = newArena.getArena();
    newArena.setDestinationOnMap();
    newArena.setPlayerOnMap();
    newArena.printMap();

    while(1)
    {
        std::cout<<"please press (s) to save your current state of playing"<<std::endl;
        std::cin>>playOrder;
        if(playOrder=='8'||playOrder=='U'||playOrder=='u')
        {
            playerPosition[0] = playerPosition[0] - 1; //nach Oben
            if(playerPosition[0]<0)
            {
                std::cout<<"you can't go up"<<std::endl;
                continue;
            }
            else if(gamePlayMap[playerPosition[0]][playerPosition[1]]=='*')
            {

                std::cout<<"you can't go up"<<std::endl;
                continue;
            }
            else if(playerPosition[0]==destination[0]&&playerPosition[1]==destination[1])
            {
                std::cout<<"You win"<<std::endl<<"Number of moves you did are:"<<counter<<std::endl;
                newArena.setPlayerPosition(playerPosition[0], playerPosition[1]);
                newArena.setPlayerOnMap();
                newArena.printMap();
                exit(-1);
            }
            else
            {
                counter++;
                newArena.replacePlayerPosition((playerPosition[0]+1), playerPosition[1]);
                newArena.setPlayerPosition(playerPosition[0], playerPosition[1]);
                newArena.setPlayerOnMap();
                newArena.printMap();

            }
        }
        else if(playOrder=='2'||playOrder=='O'||playOrder=='o')
        {
            playerPosition[0] = (playerPosition[0] + 1);        //nach unten
            if(playerPosition[0]>arenaDimentions[0])
            {

                std::cout<<"you can't go down"<<std::endl;
                continue;
            }
            else if(gamePlayMap[playerPosition[0]][playerPosition[1]]=='*')
            {
                std::cout<<"you can't go down"<<std::endl;
                continue;
            }
            else if(playerPosition[0]==destination[0]&&playerPosition[1]==destination[1])
            {
                std::cout<<"You win"<<std::endl<<"Number of moves you did are:"<<counter<<std::endl;
                newArena.setPlayerPosition(playerPosition[0], playerPosition[1]);
                newArena.setPlayerOnMap();
                newArena.printMap();
                exit(-1);
            }
            else
            {
                counter++;
                newArena.replacePlayerPosition((playerPosition[0]-1), playerPosition[1]);
                newArena.setPlayerPosition(playerPosition[0], playerPosition[1]);
                newArena.setPlayerOnMap();
                newArena.printMap();
            }
        }
        else if(playOrder=='4'||playOrder=='R'||playOrder=='r')
        {
            playerPosition[1] = playerPosition[1] - 1; //nach rechts
            if(playerPosition[1]<0)
            {
                std::cout<<"you can't go right"<<std::endl;
                continue;
            }
            else if(gamePlayMap[playerPosition[0]][playerPosition[1]]=='*')
            {
                std::cout<<"you can't go right"<<std::endl;
                continue;
            }
            else if(playerPosition[0]==destination[0]&&playerPosition[1]==destination[1])
            {
                std::cout<<"You win"<<std::endl<<"Number of moves you did are:"<<counter<<std::endl;
                newArena.setPlayerPosition(playerPosition[0], playerPosition[1]);
                newArena.setPlayerOnMap();
                newArena.printMap();
                exit(-1);
            }
            else
            {
                counter++;
                newArena.replacePlayerPosition((playerPosition[0]), playerPosition[1]+1);
                newArena.setPlayerPosition(playerPosition[0], playerPosition[1]);
                newArena.setPlayerOnMap();
                newArena.printMap();
            }
        }
        else if(playOrder=='6'||playOrder=='L'||playOrder=='l')
        {
            playerPosition[1] = playerPosition[1] + 1;      //nach links
            if(playerPosition[1]>arenaDimentions[1])
            {
                std::cout<<"you can't go left"<<std::endl;
                continue;
            }
            else if(gamePlayMap[playerPosition[0]][playerPosition[1]]=='*')
            {
                std::cout<<"you can't go left"<<std::endl;
                continue;
            }
            else if(playerPosition[0]==destination[0]&&playerPosition[1]==destination[1])
            {
                std::cout<<"You win"<<std::endl<<"Number of moves you did are:"<<counter<<std::endl;
                newArena.setPlayerPosition(playerPosition[0], playerPosition[1]);
                newArena.setPlayerOnMap();
                newArena.printMap();
                exit(-1);
            }
            else
            {
                counter++;
                newArena.replacePlayerPosition((playerPosition[0]), (playerPosition[1]-1));
                newArena.setPlayerPosition(playerPosition[0], playerPosition[1]);
                newArena.setPlayerOnMap();
                newArena.printMap();
            }
        }
        else if(playOrder=='S'||playOrder=='s')
        {
            newArena.saveArena("save.txt", counter);
            break;
        }
    }
}

