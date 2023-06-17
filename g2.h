#include <SFML/Graphics.hpp>
#include <iostream> 
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <signal.h>
#include <chrono>
#include <thread>
#include <pthread.h>
#include <cstring>
#include <sstream>
#include <cmath>
#include <future>
#include <vector>
#include <queue>

using namespace std;


// ------------------------------- GLOBALS ---------------------------
int grid_size= 0;//, score1=0, score2=0;

// positions of obstacles 
int positions1[10]= {400,300,142,590,0,200,470,320,550,130};
int positions2[10]= {100,300,450,300,350,100,500,400,0,550};
sf::Texture texture;
sf::Texture texture2;
// Define the movement speed
float speed = 2.0f;
int obj_on_board = 10;
int key= 0;int playerno= 1;int turn =0;int obj_no[9]= {0};

// array of boundaries of all oibjects 
sf::FloatRect objbounds[9];


// ------------------------- STEP 1 ----------------------
// Generate random number 
void generate_grid_size() 

{
            // Generate a random number between 10 and 99
    srand(time(nullptr)); // Seed the random number generator with the current time
    int randomNum = rand() % 90 + 10;

    // Multiply the generated number by 8
    int multipliedNum = randomNum * 8;

    // Divide your roll number with the generated number
    int rollNum = 780; // Replace with your actual roll number
    int divisionResult = rollNum / multipliedNum;

    // Take the mod of the respective number with 25
    int modResult = divisionResult % 25;

    // If the result is less than 10, add 15 to it
    if (modResult < 10) {
        modResult += 15;
    }
    ::grid_size= modResult;
    
}


// ------------------------- STEP 2 ----------------------
// Make a grid 



// ------------------------  STEP 4 ----------------------
// thread functions



// ---------------------------- STRUCTURES ------------------------------
// --------------------------------- 1 ----------------------------------
struct player1
{
    int status; // for movement up down left right
    int score= 0;
    sf::Sprite sprite;// send different for different players 
    int x, y;
    sf::FloatRect object1Bounds ;
    
    // 1.
    //    MOvement 
    void move()
    {
        cout << "Moving"<< endl;
        
           // Move the player based on user input
           if (this->status==1)// up left down right
           {
               this->sprite.move(0, -::speed);
               this->y= (this->y-speed);
               cout << "moved"<< endl;
           }
           if (this->status==2)
           {
               this->sprite.move(-::speed, 0);
               this->x= (this->x-speed);
               cout << "moved"<< endl;
           }
           if (this->status==3)
           {
               this->sprite.move(0, ::speed);
               this->y= (this->y-speed);
               cout << "moved"<< endl;
           }
           if (this->status==4)
           {
               this->sprite.move(::speed, 0);
               this->x= (this->x+speed);
               cout << "moved"<< endl;
           }

        return;
        
    }
    // 2.
    // Collision
    void collided()
    {
        int flag = -1;
        this->object1Bounds= this->sprite.getGlobalBounds();
        for (int i =0 ; i< 9; i++)
        {
            if (object1Bounds.intersects(::objbounds[i]))
            {
                flag = 0;
                obj_no[i]=1;  
                this-> score++;
                
            }

        }
       
    }


    
};
// --------------------------------- 2 ----------------------------------
struct to_send
{
    int key; int player_number;
    sf::FloatRect object2Bounds [9];
    // _____________ COnstructor ______________

    to_send(int key=0, int playerno=0, sf::FloatRect object2Bounds [9]={0})
    {
        this->key = key;
        this->player_number= playerno;
        for (int i =0; i<9 ; i++)
        {
            this->object2Bounds[i]= object2Bounds[i];
        }
    }


    
};


player1 p1; player1 p2;

// ----------------------------------------------------------------------
// ______________________________________________________________________



void * p1_func(void*arg)
{
    cout << "p1_func"<< endl;
    ::p1.move(); // do movement
    ::p1.collided(); // do collision
    sleep(50);
    pthread_exit(NULL);  

    // Sleep for a short amount of time to avoid hogging the CPU
     //std::this_thread::sleep_for(std::chrono::milliseconds(10));


}

void *p2_func(void*arg)
{
    cout << "p2_func"<< endl;
    ::p2.move(); // do movement
    ::p2.collided(); // do collision
    sleep(50);
    

    pthread_exit(NULL);
}

