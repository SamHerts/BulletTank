//
// Created by SamHerts on 3/21/2023.
//

#ifndef BULLETTANK_APP_SDL_H
#define BULLETTANK_APP_SDL_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class App_SDL
{
public:
    SDL_Window* app_window;
    SDL_Renderer* app_renderer;

    int app_screen_width;
    int app_screen_height;
    std::string app_title;

    App_SDL(std::string title, int width, int height);
    ~App_SDL();

    bool initialize();
    bool clean_up();

    SDL_Texture* load_texture(const std::string& filename);

    void blit(SDL_Texture* texture, int x_position, int y_position);
};


#endif //BULLETTANK_APP_SDL_H
