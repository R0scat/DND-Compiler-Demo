#pragma once
#ifndef DNDHELPER_H
#define DNDHELPER_H

#include <iostream>
#include <cstring>
#include <fstream>
#include "Class.h"
#include "Race.h"
#include "PlayerCharacter.h"

namespace dndHelper {
    inline void clearScreen()
    {
        std::cin.get();
        system("cls");
    }

    inline void pickClassMessage() { // mesajul dat la inceput de tot 

        std::cout << "Pick a class:\n";
        std::cout << "1.  Paladin\n";
        std::cout << "2.  Wizard\n";
        std::cout << "3.  Rogue\n";
        std::cout << "4.  Sorcerer\n";
        std::cout << "5.  Druid\n";
        std::cout << "6.  Warlock\n";
        std::cout << "7.  Fighter\n";
        std::cout << "8.  Barbarian\n";
        std::cout << "9.  Articifer\n";
        std::cout << "10. Cleric\n";
        std::cout << "11. Monk\n";
        std::cout << "12. Bard\n";
    }

    inline void pickRaceMessage() { // mesaj dat pt afisare alegere neam/ rasa

        std::cout << "Great! Now chose your race :P\n";
        std::cout << "1. Human\n";
        std::cout << "2. Elf\n";
        std::cout << "3. Dwarf\n";
        std::cout << "4. Halfling\n";
        std::cout << "5. Dragonborn\n";
		std::cout << "6. Half-Elf\n";
		std::cout << "7. Fairy\n";
		std::cout << "8. Tiefling\n";
    }

    inline int checkIfNumber(char optionString[50])
    {
        int nr[10], len = 0, option = 0;
        for (int i = 0; i < strlen(optionString); i++)
        {
            if (strchr("0123456789", optionString[i]) != NULL) // verifica daca e printre cifre
            {
				nr[len] = int(optionString[i] - '0'); // converteste in int
                len++;
            }
        }
        if (len == 0)
            return NULL; // returneaza null daca  nu e numar
        else
        {
			for (int i = 0; i < len; i++)
			{
				option = nr[i] + option * 10;
			}
           // std::cout << option; // debug
            return option; // retunreaza nr ales
        }
        
    }

    inline void convertStringToFormat(char optionString[50])
    {
        for (int i = 0; i < strlen(optionString); i++)
            if (optionString[i] >= 'A' && optionString[i] <= 'Z')
                optionString[i] += 'a' - 'A';
    }

    inline int makeInt(char optionString[50], int classOrRace) // class = 1; race = 2
    {
        char choises[12][40];
        dndHelper::convertStringToFormat(optionString);
        //std::cout << "\n" << optionString << "\n";    // cod pt debug 
        if (classOrRace == 1) // verifica daca tre sa caute printre clase
        {
            std::ifstream fin("resourcesClass.txt");
            for (int i = 0; i < 12; i++) // for pt a face matricea de char pt clase 
                fin >> choises[i];
            for (int i = 0; i < 12; i++)
                if (strstr(optionString, choises[i]) != NULL)
                    return i + 1; // sunt puse in ordinea din mesajul dat, deci se returneaza pozitia + 1 (indexare de la 0)
        }
		else if (classOrRace == 2) // verifica daca tre sa caute printre rase
		{
			std::ifstream fin("resourcesRace.txt");
			for (int i = 0; i < 8; i++) // for pt a face matricea de char pt rase 
				fin >> choises[i];
            for (int i = 0; i < 8; i++)
                if (strstr(optionString, choises[i]) != NULL)
                    return i + 1;
		}
        return 0;
    }

    inline int parseMessage(char optionString[50], int classOrRace)
    {
        int optionInt;

        if (dndHelper::checkIfNumber(optionString) == NULL)
            optionInt = dndHelper::makeInt(optionString, classOrRace); // cazul in care au introdus an entire ass word! lmao
        else
            optionInt = checkIfNumber(optionString);
        return optionInt;
    }

    inline Class pickClass(int option) {// big switch case for every available class lol - de la 1 la 12

        int lvl, optionInt;
		Class chosenClass;
        char optionString[50];
        switch (option)
        {

        case 1: // paladin
        {
            chosenClass.setName("Paladin");
            chosenClass.setHitDice("1d10");
            chosenClass.setDescription("A holy warrior bound to a sacred oath");
            break;
        }
        case 2: // wizard 
        {
            chosenClass.setName("Wizard");
            chosenClass.setHitDice("1d6");
            chosenClass.setDescription("A scholarly magic-user capable of manipulating reality");
            break;
        }
        case 3: // rogue
        {
            chosenClass.setName("Rogue");
            chosenClass.setHitDice("1d8");
            chosenClass.setDescription("A scoundrel who uses stealth and trickery to overcome obstacles and enemies");
            break;
        
        }
        case 4: // sorcerer
        {
            chosenClass.setName("Sorcerer");
            chosenClass.setHitDice("1d6");
            chosenClass.setDescription("A spellcaster who draws on inherent magic from a gift or bloodline");
            break;

        }
        case 5: // druid 
        {
            chosenClass.setName("Druid");
            chosenClass.setHitDice("1d8");
            chosenClass.setDescription("A priest of the Old Faith, wielding the powers of nature and adopting animal forms");
            break;
        }
        case 6: // warlock
        {
            chosenClass.setName("Warlock");
            chosenClass.setHitDice("1d8");
            chosenClass.setDescription("A wielder of magic that is derived from a bargain with an extraplanar entity");
            break;
        }
        case 7: // fighter
        {
            chosenClass.setName("Fighter");
            chosenClass.setHitDice("1d10");
            chosenClass.setDescription("A master of martial combat, skilled with a variety of weapons and armor");
            break;
        }
        case 8: // barbarian
        {
            chosenClass.setName("Barbarian");
            chosenClass.setHitDice("1d12");
            chosenClass.setDescription("A fierce warrior of primitive background who can enter a battle rage");
            break;
        }
        case 9: // artificer
        {
            chosenClass.setName("Artificer");
            chosenClass.setHitDice("1d8");
            chosenClass.setDescription("A master of invention, artificers use ingenuity and magic to unlock extraordinary capabilities in objects");
            break;
        }
        case 10: // cleric
        {
            chosenClass.setName("Cleric");
            chosenClass.setHitDice("1d8");
            chosenClass.setDescription("A priestly champion who wields divine magic in service of a higher power");
            break;
        }
        case 11: // monk
        {
            chosenClass.setName("Monk");
            chosenClass.setHitDice("1d8");
            chosenClass.setDescription("A master of martial arts, harnessing the power of the body in pursuit of physical and spiritual perfection");
            break;
        }
        case 12: // bard
        {
            chosenClass.setName("Bard");
            chosenClass.setHitDice("1d8");
            chosenClass.setDescription("An inspiring magician whose power echoes the music of creation");
            break;
        }
        default: // functia se reapeleaza daca optiunea e invalida
        {
            std::cout << "Option invalid, try again?\n";
            std::cin.getline(optionString, 51);
			optionInt = dndHelper::parseMessage(optionString, 1); // pt clasa parseaza cu 1; pt rasa cu 2
			//std::cout << optionString << std::endl;  // linie de debug
            chosenClass = dndHelper::pickClass(optionInt);
        }

        }
        return chosenClass;
    }

    inline Race pickRace(int option) // returneaza race-ul corect ales de utilizator
    {
		int optionInt;
        char optionString[51];
		Race chosenRace;
        switch (option)
        {

        case 1: // human 
        {
            chosenRace.setName("Human");
            chosenRace.setDescription("Found throughout the multiverse, humans are as varied as they are numerous.");
            break;
        }
        case 2: // elf
        {
            chosenRace.setName("Elf");
            chosenRace.setDescription("The elves� curiosity led many of them to explore other planes of existence.");
            break;
        }
        case 3: // dwarf
        {
            chosenRace.setName("Dwarf");
            chosenRace.setDescription("Dwarves were raised from the earth in the elder days by a deity of the forge.");
            break;
        }
        case 4: // halfling
        {
            chosenRace.setName("Halfling");
            chosenRace.setDescription("Halflings possess a brave and adventurous spirit that leads them on journeys of discovery.");
            break;
        }
        case 5: // dragonborn
        {
            chosenRace.setName("Dragonborn");
            chosenRace.setDescription("The ancestors of dragonborn hatched from the eggs of chromatic and metallic dragons.");
            break;
        }
        case 6: // half-elf
        {
            chosenRace.setName("Half-Elf");
            chosenRace.setDescription("");
            break;
        }
        case 7: // fairy
        {
            chosenRace.setName("Fairy");
            chosenRace.setDescription("Infused with the magic of the Feywild, most fairies look like Small elves with insectile wings, but each fairy has a special physical characteristic that sets the fairy apart.");
            break;
        }
        case 8: // tiefling
        {
            chosenRace.setName("Tiefling");
            chosenRace.setDescription("Tieflings are either born in the Lower Planes or have fiendish ancestors who originated there.");
            break;
        }
        default: // cand nu introduce o valoare existenta
        {
            std::cout << "Option not available, try again?\n";
            //std::cin.get();
            std::cin.getline(optionString, 51);
            optionInt = dndHelper::parseMessage(optionString, 2);
			chosenRace = dndHelper::pickRace(optionInt);
        }

        }
        return chosenRace;
    }

    inline void pickPlayerCharacter() // just chooses and creates the PC, IF YOU WANT TO DISPLAY ATRIBUTES USE THE CLASS FUNCTION!!!
    {
        int optionInt, lvl;
        char optionString[51];
        Class chosenClass;
        Race chosenRace;

        dndHelper::pickClassMessage();
        std::cin.get();
        std::cin.getline(optionString, 51);
		optionInt = dndHelper::parseMessage(optionString, 1); 
        chosenClass = dndHelper::pickClass(optionInt);

        std::cout << "Now, choose your level (reminder: unless multi-classing, your character can be at most lvl 20)\n";
        std::cin >> lvl;
        chosenClass.setLevel(lvl);

        dndHelper::pickRaceMessage();
        std::cin.get();
        std::cin.getline(optionString, 51);
        optionInt = dndHelper::parseMessage(optionString, 2);
        chosenRace = dndHelper::pickRace(optionInt);
    }

    inline void menu()
    {
        std::cout << "Your character basics have all been set up, what would you like to do?\n";
        std::cout << "1. show character details\n";
        std::cout << "2. add another class\n";
        std::cout << "3. add equipment\n";
        std::cout << "4. add backstory\n";
        std::cout << "5. pick abilities (available at current level)\n";
        std::cout << "6. level up\n";
        std::cout << "7. quit (deleting the character...)\n";
    }

	inline void menuPicker(int option, int &ongoing, PlayerCharacter &PC)
	{
        char optionString[50];
        int optionInt;
        Class chosenClass;
        dndHelper::clearScreen();
		switch (option)
		{
		case 1:
			PC.showPlayerCharacterDetails();
			break;
		case 2:
        {
            std::cout << "Adding another class...\n\n";
            dndHelper::pickClassMessage();
            std::cin.getline(optionString, 51);
			optionInt = dndHelper::parseMessage(optionString, 1);
			chosenClass = dndHelper::pickClass(optionInt);
            std::cout << chosenClass << std::endl;

            std::cout << "Choose level for this class (total character level will be equal to the sum of thhe two classes)\n";
			std::cin >> optionInt;
			chosenClass.setLevel(optionInt);
	
			PC.addCharacterClass(chosenClass);
            PC.recalculateLevel(PC);
            break;
        }
		case 3:
			std::cout << "Adding equipment...\n\n";
			break;
		case 4:
			std::cout << "Adding backstory...\n\n";
			break;
		case 5:
			std::cout << "Picking abilities...\n\n";
			break;
		case 6:
        {
            int classNo;
            if (PC.getNumberOfClasses() != 1)
            {
                std::cout << "Please select the class index that you'd like to level up\n";
                std::cin >> classNo;
                PC.modifyClass(PC, classNo - 1, "", 1);
            }
            else
            {
                std::cout << "Leveling up!!\n";
                PC.modifyClass(PC, 0, "", 1);
            }
            break;
        }
		case 7:
        {
            std::cout << "Quitting...\n";
            ongoing = 0;
            break;
        }
        default:
        {
            std::cout << "Invalid option, try again!\n";
            std::cin >> option;
            dndHelper::menuPicker(option, ongoing, PC);
            break;
        }
		}
	}
}


#endif // !DNDHELPER
