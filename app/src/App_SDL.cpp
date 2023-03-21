//
// Created by SamHerts on 3/21/2023.
//

#include "../include/App_SDL.h"
#include <cstdio>

App_SDL::App_SDL(std::string title, int width, int height)
{
    app_title = title;
    app_screen_width = width;
    app_screen_height = height;
}

App_SDL::~App_SDL()
{

}

bool App_SDL::initialize()
{
    //Initialization flag
    int renderer_flags = SDL_RENDERER_ACCELERATED;
    int window_flags = SDL_WINDOW_SHOWN;

    //initialize SDL
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        return false;
    }

    //Set texture filtering to linear
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
    {
        printf( "Warning: Linear texture filtering not enabled!" );
    }

    //Create window
    app_window = SDL_CreateWindow( app_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, app_screen_width, app_screen_height,  window_flags);
    if( app_window == nullptr )
    {
        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
        return false;
    }

    //Create renderer for window
    app_renderer = SDL_CreateRenderer( app_window, -1, renderer_flags );
    if( app_renderer == NULL )
    {
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        return false;
    }

    //initialize renderer color
    SDL_SetRenderDrawColor( app_renderer, 0xFF, 0xFF, 0xFF, 0xFF );

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    return true;
}

bool App_SDL::clean_up()
{
    //Destroy window
    SDL_DestroyWindow( app_window );
    app_window = nullptr;

    //Quit SDL subsystems
    SDL_Quit();
}

SDL_Texture *App_SDL::load_texture(const std::string& filename)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename.c_str());
    return IMG_LoadTexture(app_renderer, filename.c_str());
}

void App_SDL::blit(SDL_Texture *texture, int x_position, int y_position)
{
    SDL_Rect dest;

    dest.x = x_position;
    dest.y = y_position;
    SDL_QueryTexture(texture, nullptr, nullptr, &dest.w, &dest.h);

    SDL_RenderCopy(app_renderer, texture, nullptr, &dest);

}
