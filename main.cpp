//
//  main.cpp
//  Jamir Nunley - MP4
//
//  Created by Jamir Nunley on 12/5/21.
//

// MP4

// This program is a text-based adventure game that uses a 2D vector to move through the world. The game involves
// the debugging rubber ducks tracking down the snow steeling peeps in a cave that contains 20 different rooms that
// the player moves through. There are 3 rounds, in round 1 the player with control the debugging rubber ducks, in
// round 2 the player will control the snow steeling peeps. While the players move through the game there a hazards
// that will attempt to interfere with the player, such as vulters that transport you to a random room and pits of
// taffy that will cause you to lose a round. The player starts by selecting a random room 1-20 that is modeled
// after a dodacahedron which has 20 vertices, and each room will lead to 3 adjacent rooms with 3 possibilities
// for each room. The user can select M to move, C to shoot at the opposing enemies with arrows, E to exit, and
// I to display instructions. Enemies can also be detected by smell from 2 steps away and by footsteps from 1 step
// away. Each opposing group can keep playing be continuing to win consecutive rounds. If ducks win the first round
// the game will continue and if peeps win on round 2 the game will end. Round 3 will last until ducks win or lose
// and the game will end displaying the winner.

#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <vector>
#include <stdlib.h>

using namespace std;

    // Prototypes
    vector<int> getAdjacentRooms(vector<vector<int>> map, int currentRoom);
    int hazards[3];
    void displayInstructions();
    int LocationNew(int currentRoom, vector<vector<int>> map);
    int RandRoom();
    bool isValidMove(int to, vector<int> connections);
    void printCurrentRoom(int room);
    char Choice(string roundAction);
    int HazardCheck(int& currentRoom);
    int attackDirection(vector<vector<int>> dodecahedron, int currentRoom);
    void printAdjacentRooms(vector<int> rooms);
    void Hazards();
    void displayHazardsNearby(vector<vector<int>> map, int currentRoom, int round);
    
    // Definitions
    const int numofHazards = 3;

    void Hazards() {
        for (int l = 0; l < numofHazards; l++)
        {
            hazards[l] = rand() % 20 + 1;
        }
    }

    // getAdjacentRooms - lets you know what rooms you can directly move to from the current room.
    // @param map - 2-D vector of integers containing the game's room map
    // @param currentRoom - integer value indicating one's current location
    // @return integer vector containing list of rooms that it's legal to move to
    vector<int> getAdjacentRooms(vector<vector<int>> map, int currentRoom) {
        return map[currentRoom];
    }

    // isValidMove - given a room number, can one directly move there from where they currently are?
    // @param to - proposed room to move to
    // @param connections - list of rooms adjacent to the current room
    // @return true if specific room is adjacent, false otherwise
    bool isValidMove(int to, vector<int> connections) {
        for (int i = 0; i < connections.size(); i++) {
            if (to == connections[i])
                return true;
        }

        return false;
    }

    // printCurrentRoom - display message containing current room number.
    // @param room - current room number
    void printCurrentRoom(int room) {
        cout << "You are in room " << room << endl;
    }

    // printAdjacentRooms - display message listing those rooms adjacent to the current room.
    // @param rooms - list of rooms adjacent to the current room.
    void printAdjacentRooms(vector<int> rooms) {
        cout << "Tunnels lead to rooms ";

        for (int i = 0; i < rooms.size(); i++) {
            cout << rooms[i];
            if (i < rooms.size() - 1)
                cout << ", ";
            else
                cout << endl;
        }
    }
    // Display the introductory message to the player explaining the game
    void displayInstructions() {
        
        cout << "Welcome to Rubber Ducks vs. Peeps Game" << endl << endl;
        cout << "The Debugging Rubber Ducks are tracking down the evil Snow Stealing Peeps living in a 20-room cave system." << endl;
        cout << "The Snow Stealing Peeps are taking all the snow and magically creating snow beasties." << endl << endl;
        
        cout << "Using their cunning skill and logic, the rubber ducks are going to hunt down the snow stealing peeps." << endl;
        cout << "The peeps cannot hide their sugary stench smell or muffle their squishy marshmallow footsteps." << endl << endl;

        cout << "This text-based adventure game will have three rounds." << endl;
        cout << "In round 1 and round 3, the user will be playing the role of the rubber ducks." << endl;
        cout << "In round 2, the tables will be turned, and the user will be play as the Snow Stealer Peeps." << endl << endl;

        cout << "For each round, you will be moving through the cave system trying to find your enemy." << endl;
        cout << "You can move to any of the ajointing rooms. You can also view the instructors or exit the game." << endl << endl;

        cout << "You will have a warning that you will be approaching your enemy if you hear footsteps or smell sugar." << endl;
        cout << "If you think you have located the enemy, you can use your candy cane arrow (round 1) or toothpick sword (round 2 or 3) to capture the enemy and win around." << endl << endl;

        cout << "Hazards:" << endl;
        cout << "Taffy - the rubber ducks or peeps can get 'stuck' on the taffy and this will end the game/round." << endl;
        cout << "Vultures - these carry ducks or peeps to a random location within the cave system" << endl << endl;

}
    
    // Checks for hazards in each room while hazards occur at random
    // Hazards will effect the player accordingly for switch statement
    int HazardCheck(int& currentRoom) {
        int outcome = - 1;
        for (int k = 0; k < numofHazards; k++)
        {
            if (currentRoom == hazards[k])
            {
                switch (k)
                {
                    case 0: cout << "Enemy attacks you before you can. you lose this round." << endl; outcome = 0; break;
                    case 1: currentRoom = rand() % 20 + 1;  cout << "Vultures transport you to." << currentRoom << endl; break;
                    case 2: cout << "You got stuck in a taffy. You lose this round." << endl; outcome = 0; break;

                }

            }
    }
        return outcome;
}

    // Allows for player to hear opponent footsteps or smell them based on how close they are
    // If within 1 step you will hear footsteps, if within 2 steps you will smell them
    // For loop with check for enemies using user position
    void displayHazardsNearby(vector<vector<int>> map, int currentRoom, int round)
    {
        vector<int> adjacentRooms = getAdjacentRooms(map, currentRoom);

        for (int i = 0; i < adjacentRooms.size(); i++)
        {
            // Check for footsteps according to round/distance
            if (hazards[0] == adjacentRooms[i])
            {
                cout << "I hear footsteps!" << endl;
            }

            if (round == 2)
            {
                return;
            }
            
            // Check for smell according to round/distance
            vector<int> adjacentAdjacentRooms = getAdjacentRooms(map, adjacentRooms[i]);
            for (int j = 0; j < adjacentAdjacentRooms.size(); j++)
            {
                if (hazards[0] == adjacentAdjacentRooms[j])
                {
                    cout << "I smell marshmellows" << endl;
                }
            }


        }
    }
    
    // Player will choose to move, exit, see instructions, or shoot arrow
    // Keeps player from choosing more than 1 option at a time with do while loop
    // Actions are stored in M, E, I, C
    char Choice(string roundAction)
    {
        char Move = 'M';
        char Action = roundAction[0];

        do
        {
            cout << "(M) Move, (E) Exit, (I) Instructions, or (C) " << roundAction << endl;
            cin >> Move;
        }
        while (Move != 'M' && Move != 'E' && Move != 'I' && Move != Action);

        return Move;
    }
    
    // If player chooses to shoot, room they are shooting at is stored
    // Can only shoot at adjacent rooms from the room they are currently in using do while loop
    // If enemy is hit, player will be prompted with message
    int attackDirection(vector<vector<int>> dodecahedron, int currentRoom)
    {
        int aimArrow = 0;
        vector<int> adjacentRooms = getAdjacentRooms(dodecahedron, currentRoom);
        do
        {
            cout << "Room to aim at?" << endl;
            printAdjacentRooms(adjacentRooms);
            cin >> aimArrow;
        }
        while (isValidMove(aimArrow, getAdjacentRooms(dodecahedron, currentRoom)) == false);

        if (hazards[0] == aimArrow)
        {
            
            cout << "Great Job! You found the enemy!" << endl;
            return 1;
        }

        return 0;
}

    // Random rooms for dodecahedron map are generated using rand() and keeps player from going to a room
    // That does not exist
    // While(true) if else statement will only let player enter adjacent room that is 1 of 3 possibilities
    int RandRoom()
    {
        return rand() % 20 + 1;
    }

    int LocationNew(int currentRoom, vector<vector<int>> dodecahedron)
    {
        while (true)
        {
            int nextRoom = 0;
            vector<int> adjacentRooms;

            adjacentRooms = getAdjacentRooms(dodecahedron, currentRoom);
            printCurrentRoom(currentRoom);
            printAdjacentRooms(adjacentRooms);
            cout << "where to? ";
            cin >> nextRoom;

            if (cin.fail())
            {
                // Doesn't let player choose room that isn't en existing room number
                cout << "Oops. That is not a room" << endl;
            }

            if (isValidMove(nextRoom, getAdjacentRooms(dodecahedron, currentRoom)))
            {
                currentRoom = nextRoom;
                return currentRoom;
            }
            else
            {
                // Notifies player if a room outiside of the current dodecahedron cannot be reached (not 1 of 3)
                cout << "You can't get there from here." << endl;
            }
        }
}

    
    int main() {
        
        // Room and next room and stored as ints while the character wins are stored as ints
        srand((unsigned int)time(NULL));
        int currentRoom = 0;
        int*ptr = &currentRoom;
        int ducksWin = 0;
        int peepsWin = 0;
        int roomEntered = 0;
        
        displayInstructions();

        // Dodecahedron run, maps all 20 rooms using 2D vector while setting each room == to possible 3 rooms
        // Starts at 0 and has player choose room on first turn
        vector<vector<int>> map
        {
            
        {0, 0, 0}, // 0
        {2, 5, 8}, // 1
        {1, 3, 10}, // 2
        {2, 4, 12}, // 3
        {3, 5, 14}, // 4
        {1, 4,  6}, // 5
        {5, 7, 15}, // 6
        {6, 8, 17}, // 7
        {1, 7,  9}, // 8
        {8, 10, 18}, // 9
        {2, 9, 11}, // 10
        {10, 12, 19}, // 11
        {3, 11, 13}, // 12
        {12, 14, 20}, // 13
        {4, 13, 15}, // 14
        {6, 14, 16}, // 15
        {15, 17, 20}, // 16
        {7, 16, 18}, // 17
        {9, 17, 19}, // 18
        {11, 18, 20}, // 19
        {13, 16, 19}, // 20
            
        };


        // Round 1
        
        // Includes hazards in round one in which player will control ducks, outcomes are stored as 0 and 1
        // Round is stored as True or False with the outcome of the round being stored to determine the next round
        // Duck will choose room as hazards are mapped at random, and player choice will be M,E,I, or C
        Hazards();
        cout << "Round 1" << endl;
        cout << "Enter value 1-20 to start at that room: ";
        cin >> roomEntered;
        if (roomEntered < 1 || roomEntered > 20) // Easter Egg
            currentRoom = rand() % 20 + 1;
        else
            currentRoom = roomEntered;
        bool Round1 = false;
        int outcome = 1;
        
        // While loop will end round if ducks lose and continue of ducks win
        // Ducks will win if enemy is found by player
        while (Round1 == false)
        {
            outcome = HazardCheck(currentRoom);
            if (outcome == 0)
            {
                cout << "You lose this round" << endl; peepsWin++;
                Round1 = true; return 0;
                break;
            
            }

            displayHazardsNearby(map, currentRoom, 1);
            vector<int> adjacentRooms = getAdjacentRooms(map, currentRoom);
            printCurrentRoom(currentRoom);
            printAdjacentRooms(adjacentRooms);

            char action = Choice("Candy Cane");

            switch (action)
            {
                // Stores each turn option Move, Exit, Instructions, or Candy cane arrow
                case 'M': currentRoom = LocationNew(currentRoom, map); break;
                case 'E': cout << "Thank you for playing!" << endl; exit(0); break;
                case 'I': displayInstructions(); break;
                case 'C': outcome = attackDirection(map, currentRoom); break;
            }

            if (outcome == 0)
            {
                cout << "You lose this round" << endl; peepsWin++;
                Round1 = true;
                return 0; break;
                
            }
            if (outcome == 1)
            {
                cout << "You win this round" << endl; ducksWin++;
                Round1 = true;
            }
        }


        // Round 2
        
        // User will ply as peeps in this round with same mechanics
        // Duck footsteps are sqeaky
        // Peep fight back with toothpicks instead of arrows
        Hazards();
        
        
        cout << "Round 2" << endl;
        cout << "Enter value 1-20 to start at that room: ";
        cin >> roomEntered;
        if (roomEntered < 1 || roomEntered > 20) // Easter Egg
            currentRoom = rand() % 20 + 1;
        else
            currentRoom = roomEntered;
        bool Round2 = false;
        while (Round2 == false)
        {
            outcome = HazardCheck(currentRoom);
            if (outcome == 0)
            {
                cout << "You lose this round" << endl; peepsWin++;
                Round2 = true; break;
            }

            displayHazardsNearby(map, currentRoom, 1);
            vector<int> adjacentRooms = getAdjacentRooms(map, currentRoom);
            printCurrentRoom(currentRoom);
            printAdjacentRooms(adjacentRooms);

            char action = Choice("Sword Toothpick");

            switch(action)
            {
                case 'M': currentRoom = LocationNew(currentRoom, map); break;
                case 'E': cout << "Thank you for playing!" << endl; exit(0); break;
                case 'I': displayInstructions(); break;
                case 'S': outcome = attackDirection(map, currentRoom); break;
            }

            if (outcome == 0)
            {
    
                cout << "You lose this round" << endl; peepsWin++;
                Round2 = true;
    
            }
    
            if (outcome == 1)
            {
    
                cout << "You win this round" << endl; ducksWin++;
                Round2 = true;
                return 0; break;
    
            }
    
        }

        // Round 3
        
        // Back to Playing as ducks for final round
        Hazards();
        cout << "Round 3" << endl;
        cout << "Enter value 1-20 to start at that room: ";
        cin >> roomEntered;
        if (roomEntered < 1 || roomEntered > 20)
            currentRoom = rand() % 20 + 1;
        else
            currentRoom = roomEntered;
        bool Round3 = false;
        while (Round3 == false)
        {
            outcome = HazardCheck(currentRoom);
            if (outcome == 0)
            {
                cout << "You lose this round" << endl; peepsWin++;
                Round3 = true; break;
            }

            displayHazardsNearby(map, currentRoom, 1);
            vector<int> adjacentRooms = getAdjacentRooms(map, currentRoom);
            printCurrentRoom(currentRoom);
            printAdjacentRooms(adjacentRooms);

            char action = Choice("Pastry Torch");

            switch (action)
            {
                case 'M': currentRoom = LocationNew(currentRoom, map); break;
                case 'E': cout << "Thank you for playing!" << endl; exit(0); break;
                case 'I': displayInstructions(); break;
                case 'P': outcome = attackDirection(map, currentRoom); break;
            }

            if (outcome == 0)
            {
                // Determines winner using if statements and outcome of current round or previos round
                // 0 == Peep win, 1 == Ducks win
                cout << "You lose this round" << endl; peepsWin++;
                Round3 = true;
            }
            if (outcome == 1)
            {
                cout << "You win this round" << endl; ducksWin++;
                Round3 = true;
            }
        }

        // Outputes the winner based on 0 and 1 values
        // if statement determines game ending and who won or if the peeps got away
        if (ducksWin > peepsWin)
        {
            cout << "The Rubber Ducks defeat the Snow Stealing Peeps!" << endl;
        }
        else if (peepsWin > ducksWin)
        {
            cout << "The Snow Stealing Peeps beat the Rubber Ducks." << endl;
        }
        else
        {
            cout << "The Snow Stealing Peeps slipped through the Rubber Ducks Fingers. Darn." << endl;
        }

            cout << "Thanks for playing!" << endl;

        return 0;
        
        // Function Definition with a Vector as a Parameter and Function Call - Line 68 (3)
        // Vector - Line 60 (3)
        // 2D Array/Vector - Line 275 (3)
        // Pointer - Line 266 (6)
        // For/While/Do Loop - Line 150 (5)
        // Switch Statement - Line 130 (5)
        // If statement - Line 451 (3)
        
        // Total = 28
}

