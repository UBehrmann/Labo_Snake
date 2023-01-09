//---------------------------------------------------------
// Demo           : 03_moving_point_SDL
// Fichier        : 03_moving_point_SDL.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 01 - 2023-01-02
// But            : SDL2 démo
// Modifications  :
// Remarque(s)    : remember (0,0) is on the top left corner
//---------------------------------------------------------

//-----------------------------------------------------------------------------
//    SDL installation and XCode config
//    https://www.libsdl.org/
//    https://github.com/rosejoshua/QuickSDL2MAC
//    https://lazyfoo.net/tutorials/SDL/01_hello_SDL/mac/xcode/index.php
//    https://wiki.libsdl.org/SDL2/CategoryAPI
//-----------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <sdl.h>

using namespace std;

int main (int argc, char* args[]) {
    //--------------------------------------------------------------------------
    //    Instructions
    //--------------------------------------------------------------------------
    cout << "This program is an SDL2 demo."            << endl
         << " - use the array keys to move the point"  << endl
         << " - close the window to terminate the app" << endl
         << endl;

    //--------------------------------------------------------------------------
    //    SDL settings
    //--------------------------------------------------------------------------
    SDL_Window*    window         = nullptr;
    SDL_Renderer*  renderer       = nullptr;
    bool           appIsRunning   = true;

    const int      WINDOW_WIDTH   = 80;
    const int      WINDOW_HEIGTH  = 50;
    const int      SCALE          = 10;
    int      stepX           =  0;
    int      stepY           =  0;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH  * SCALE,
                                WINDOW_HEIGTH * SCALE,
                                SDL_WINDOW_SHOWN,
                                &window, &renderer);
    if (window == nullptr or renderer == nullptr) {
        cout << "SDL not ready ... quitting" << endl;
        exit(EXIT_FAILURE);
    }

    SDL_SetWindowTitle(window, "SDL Demo / Moving points");
    SDL_RenderSetScale(renderer, SCALE, SCALE);

    // point to show
    SDL_Point point;
    point.x = WINDOW_WIDTH  / 2;
    point.y = WINDOW_HEIGTH / 2;

    //--------------------------------------------------------------------------
    // main loop
    //--------------------------------------------------------------------------
    while (appIsRunning) {

        // Events management
        SDL_Event event;
        while (SDL_PollEvent(&event)) {

            switch (event.type) {
                case SDL_QUIT     :  appIsRunning = false;
                    break;

                    // keyboard API for key pressed
                case SDL_KEYDOWN  :

                    if(event.key.keysym.scancode == SDL_SCANCODE_UP) stepY = -1;

                    if(event.key.keysym.scancode == SDL_SCANCODE_LEFT) stepX = -1;

                    if(event.key.keysym.scancode == SDL_SCANCODE_DOWN) stepY = 1;

                    if(event.key.keysym.scancode == SDL_SCANCODE_RIGHT) stepX = 1;

                    break;

                case SDL_KEYUP:

                    if(event.key.keysym.scancode == SDL_SCANCODE_UP) stepY = 0;

                    if(event.key.keysym.scancode == SDL_SCANCODE_LEFT) stepX = 0;

                    if(event.key.keysym.scancode == SDL_SCANCODE_DOWN) stepY = 0;

                    if(event.key.keysym.scancode == SDL_SCANCODE_RIGHT) stepX = 0;

                    break;

            } // switch event.type

            point.y += stepY;
            point.x += stepX;


        } // while PollEvent

        //-----------------------------------------------------------------------
        // bounderies
        //-----------------------------------------------------------------------
        // right boundary
        if (point.x >= WINDOW_WIDTH)
            point.x = WINDOW_WIDTH - 1;

        // left boundary
        if (point.x < 0)
            point.x = 0;

        // bottom boundary
        if (point.y >= WINDOW_HEIGTH)
            point.y = WINDOW_HEIGTH - 1;

        // upper boundary
        if (point.y < 0)
            point.y = 0;

        //-----------------------------------------------------------------------
        // draw the point
        //-----------------------------------------------------------------------
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawPoint(renderer, point.x, point.y);
        SDL_RenderPresent(renderer);

    } // app running

    // destroy SDL ressources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}