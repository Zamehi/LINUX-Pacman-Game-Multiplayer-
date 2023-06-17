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

#include <pthread.h>
#include <cstring>
#include <sstream>
#include <cmath>
#include <chrono>
#include <future>
#include <thread>
#include <future>
#include <vector>
#include <queue>

#include "g2.h"
// g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
using namespace std;




// *******************************************************
//________________________________________________________
int main()
{

   

// ------------------------- STEP 2 ----------------------
// Make a grid 

     // Create the window
    sf::RenderWindow window(sf::VideoMode(650, 650), "Grid Example");
    generate_grid_size();
    cout << "The size of grid is "<< ::grid_size<< endl;
   

    // Define the grid size and spacing
   
    const float spacing = 50.0f;

    // Create the grid
    sf::VertexArray lines(sf::Lines);

    for (int i = 0; i <= ::grid_size; i++)
    {
        // Horizontal line
        lines.append(sf::Vertex(sf::Vector2f(0, i * spacing)));
        lines.append(sf::Vertex(sf::Vector2f(grid_size * spacing, i * spacing)));

        // Vertical line
        lines.append(sf::Vertex(sf::Vector2f(i * spacing, 0)));
        lines.append(sf::Vertex(sf::Vector2f(i * spacing, ::grid_size * spacing)));
    }

   
    // ------------------------- STEP 3 -------------------------
     // Load the image

     // 1 -
    
    if (!::texture.loadFromFile("img1.png"))
    {
        // Error loading the image
        return -1;
    }
    // 2 -
    
    if (!::texture2.loadFromFile("img2.png"))
    {
        // Error loading the image
        return -1;
    }

    // ------------------------- objects ----------------------------
    sf::Texture obj11;
    if (!obj11.loadFromFile("obj.png"))
    {
        // Error loading the image
        return -1;
    }
    sf::Texture obj12;
    if (!obj12.loadFromFile("obj.png"))
    {
        // Error loading the image
        return -1;
    }
    sf::Texture obj13;
    if (!obj13.loadFromFile("obj4.png"))
    {
        // Error loading the image
        return -1;
    }
    sf::Texture obj14;
    if (!obj14.loadFromFile("obj4.png"))
    {
        // Error loading the image
        return -1;
    }
    // ----------------------------------
    sf::Texture obj21;
    if (!obj21.loadFromFile("obj2.png"))
    {
        // Error loading the image
        return -1;
    }
     sf::Texture obj22;
    if (!obj22.loadFromFile("obj2.png"))
    {
        // Error loading the image
        return -1;
    }
     sf::Texture obj23;
    if (!obj23.loadFromFile("obj2.png"))
    {
        // Error loading the image
        return -1;
    }
//   // -------------------------------------
       sf::Texture obj31;
    if (!obj31.loadFromFile("obj3.png"))
    {
        // Error loading the image
        return -1;
    }
     sf::Texture obj32;
    if (!obj32.loadFromFile("obj3.png"))
    {
        // Error loading the image
        return -1;
    }
     sf::Texture obj33;
    if (!obj33.loadFromFile("obj3.png"))
    {
        // Error loading the image
        return -1;
    }
    // Create the sprite
    sf::Sprite sprite(texture);
    sf::Sprite sprite2(texture2);
    sf::Sprite o11(obj11);
    sf::Sprite o12(obj12);
    sf::Sprite o13(obj13);
    sf::Sprite o14(obj14);
    sf::Sprite o21(obj21);
    sf::Sprite o22(obj22);
    sf::Sprite o23(obj23);
    sf::Sprite o31(obj31);//
    sf::Sprite o32(obj32);
    sf::Sprite o33(obj33);
     
  



    
      // Set the *SIZE* of the sprite
    sprite.setScale(0.2f, 0.2f);
    sprite2.setScale(0.2f, 0.2f);
    o11.setScale(0.1f, 0.1f);
    o12.setScale(0.1f, 0.1f);
    o13.setScale(0.1f, 0.1f);
    o14.setScale(0.1f, 0.1f);
    o21.setScale(0.1f, 0.1f);
    o22.setScale(0.1f, 0.1f);
    o23.setScale(0.1f, 0.1f);
    o32.setScale(0.11f, 0.11f);
    o33.setScale(0.11f, 0.11f);
    o31.setScale(0.11f, 0.11f);




    // Set the initial *POSITION* of the sprite
    sprite.setPosition(0.0, 0.0);
    sprite2.setPosition(550, 520);
    o11.setPosition(400, 100);
    o12.setPosition(300, 300);
    o13.setPosition(142, 450);
    o14.setPosition(590, 300);
    o21.setPosition(0.0, 350);
    o22.setPosition(200, 100);
    o23.setPosition(470, 500);
    o31.setPosition(320, 400);
    o32.setPosition(550, 0);
    o33.setPosition(130, 550);
    

          // Putting all sprites in an array
    sf:: Sprite all_objs[9];
    all_objs[0]= o11;
    all_objs[1]= o12;
    all_objs[2]= o13;
    all_objs[3]= o14;
    all_objs[4]= o21;
    all_objs[5]= o22;
    all_objs[6]= o23;
    all_objs[7]= o32;
    all_objs[8]= o33;
    // Array of *boundaries* of objects 

    //sf::FloatRect objbounds[9];
    // putting value in global obj bounds 
    for (int i =0; i< 9; i++)
    {
        ::objbounds[i]= all_objs[i].getGlobalBounds();
    }
    
   



    // ---------------------------- STEP 4 -------------------------
    // Create threads 
    // Creating threads for each player 
    pthread_t pid1;
    pthread_t pid2;
    for (int i =0; i< 9; i++)
    {
        
    }

    // Creating attr
    pthread_attr_t p1;
    pthread_attr_t p2;

    // Sendiing arguments
   // player1 p1struct;
    //player1 p2struct;

    //two player objects made global 
    ::p1.sprite= sprite;
    ::p2.sprite= sprite2;


    
    to_send arg(key,playerno, objbounds);
    // Creating Threads
  // pthread_create (&pid1,   &p1,       p1_func,    NULL);
    //            id        attribute    function   arguments
  // pthread_create (&pid2,   &p2,       p2_func,    NULL); // sending by refernce
     
     cout << "Step 1"<< endl;
     
    int k =0;
    // Start the game loop

    // ------------------ PRINTING CONSOLE ---------------------
    while (window.isOpen())
    {
        // Process events
         sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
         
        // Handle keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            cout << "up"<< endl;
            ::p1.status= 1;
            k = 0;
            //::p1.move();
            //::p1.collided();
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            cout << "left"<< endl;
            ::p1.status= 2;k = 0;
            //::p1.move();
            //::p1.collided();
     
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            cout << "down"<< endl;
            ::p1.status= 3;k = 0;
           // ::p1.move();
            //::p1.collided();
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            cout << "right"<< endl;
            ::p1.status= 4;k = 0;

            
           //::p1.move();
            //::p1.collided();
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            cout << "w"<< endl;
            ::p2.status= 1;k = 1;
            //::p2.move();
            //::p2.collided();
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            cout << "a"<< endl;
            ::p2.status= 2;k = 1;

            //::p2.move();
            //::p2.collided();
     
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            ::p2.status= 3;
            cout << "S"<< endl;k = 1;

            //::p2.move();
            //::p2.collided();
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            cout << "d"<< endl;k = 1;
            ::p2.status= 4;

            //::p2.move();
            //::p2.collided();
        }
        //p1_func(NULL);
        if (k ==0)
        {
           pthread_create (&pid1,   NULL,       p1_func,    NULL);
        }
        else if (k ==1)
        {
            pthread_create (&pid2,   NULL,      p2_func,    NULL); // sending by refernce
        }
        
    //            id        attribute    function   arguments
        //pthread_create (&pid2,   &p2,       p2_func,    NULL); // sending by refernce

         // sleep(5);+
         // Set the background color to white
        sf::Color color(0, 51, 51);
        window.clear(color);
        cout << "Step 2"<< endl;
         // Draw the grid
        window.draw(lines);
        // draw objects
        for (int i =0 ;i< 9; i++)
        {
            if (obj_no[i]==0)
            {
                window.draw(all_objs[i]);
            }
        }
       

        // Draw the sprite
        window.draw(::p1.sprite);

        // Draw the sprite2
        window.draw(::p2.sprite);

       
         //pthread_join(pid1, NULL);
        // Display the window
        window.display();

    }


// Exitting threads

         //pthread_join(pid1, NULL);
 
         //pthread_join(pid2, NULL);
    
    cout << "THe score of player 1 is "<< ::p1.score<< endl;
    cout << "THe score of player 2 is "<< ::p2.score<< endl;
    if (::p1.score> ::p2.score)
    {
        cout << "P1 wins"<< endl;
    }
    else 
    {
        cout << "P2 wins"<< endl;
    }
    return 0;
}