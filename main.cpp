

//Using SDL, SDL_image, standard IO, and strings
#include <cstdio>
#include "app/include/App_SDL.h"
#include "game/include/TankEntity.h"

int main( int argc, char* args[] )
{
    App_SDL my_app("Bullet Tank v0.0.1", 640, 480);
    TankEntity player_one{};

    //Start up SDL and create window
    my_app.initialize();

    player_one.texture = my_app.load_texture("assets/images/FourTank.png");

    //Hack to get window to stay up
    SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }



    //Free resources and close SDL
    my_app.clean_up();

    return 0;
}