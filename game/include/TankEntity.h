//
// Created by SamHerts on 3/21/2023.
//

#ifndef BULLETTANK_TANKENTITY_H
#define BULLETTANK_TANKENTITY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TankEntity
{
public:
    TankEntity(int x_position, int y_position);
    ~TankEntity();

    int x_position;
    int y_position;
    SDL_Texture* texture;

};


#endif //BULLETTANK_TANKENTITY_H
