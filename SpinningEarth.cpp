
#include "SpinningEarth.h"
#include "Factory.h"
#include <cmath>
#include <iostream>
void SpinningEarth::init(SDL_Renderer *renderer)
{

    // Initialize variables
    earthRadius = 511 / 2; // 177 * 2
    hypoteneuseSquared = pow(earthRadius, 2);
    spin = 0;

    // Create textures using the factory
    Factory* factory = Factory::getInstance();
    earthTexture = factory -> fromImage("resources/earth.png");
    globe = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, earthRadius*2, earthRadius*2);

    // Calculate map
    for(int i = 0; i<earthRadius; i++)
    {
        double i2 = pow(i, 2);
        line[i].size = (sqrt(hypoteneuseSquared - i2));
        line[i].steps = earthRadius / line[i].size;
    }
}

void SpinningEarth::update(SDL_Renderer* renderer)
{
    //Render to texture
    SDL_SetRenderTarget(renderer, globe);
    SDL_RenderClear(renderer);
    spin--;
    if(spin < 0) spin += 1022;

    for(int i = 0; i < earthRadius; i++)
    {
        double overflow = spin;
        double underflow = spin;

        if(overflow > 1021) overflow -= 1022;
        else if(underflow < 0) underflow += 1022;

        sourceNE = { underflow, earthRadius - i, 1, 1 };
        sourceNW = { overflow, earthRadius - i, 1, 1 };
        targetNE = { earthRadius, earthRadius - i, 1, 1 };
        targetNW = { earthRadius, earthRadius - i, 1, 1 };

        sourceSE = { underflow, earthRadius + i, 1, 1 };
        sourceSW = { overflow, earthRadius + i, 1, 1 };
        targetSE = { earthRadius, earthRadius + i, 1, 1 };
        targetSW = { earthRadius, earthRadius + i, 1, 1 };


        for(int j = 0; j < line[i].size; j++)
        {
            overflow += line[i].steps;
            if(overflow >= 1022) overflow -= 1022;
            underflow -= line[i].steps;
            if(underflow < 0) underflow += 1022;

            sourceNE.x = overflow; //%(int)line[i].size;
            sourceNW.x = underflow; //%(int)line[i].size;
            sourceSE.x = overflow; //%(int)line[i].size;
            sourceSW.x = underflow; //%(int)line[i].size;

            // sourceNE.x = (j * line[i].steps); //%(int)line[i].size;
            // sourceNW.x = 1021 - (j * line[i].steps); //%(int)line[i].size;
            // sourceSE.x = (j * line[i].steps); //%(int)line[i].size;
            // sourceSW.x = 1021 - (j * line[i].steps); //%(int)line[i].size;
            SDL_RenderCopy(renderer, earthTexture, &sourceNE, &targetNE);
            SDL_RenderCopy(renderer, earthTexture, &sourceNW, &targetNW);
            SDL_RenderCopy(renderer, earthTexture, &sourceSE, &targetSE);
            SDL_RenderCopy(renderer, earthTexture, &sourceSW, &targetSW);
            targetNE.x++;
            targetNW.x--;
            targetSE.x++;
            targetSW.x--;


        }
    }
    SDL_SetRenderTarget(renderer, NULL);
}



            // %sizes[i]
            // sizes[i] =
            // hypoteneuse^2 = o^2 * a^2;

        // }

void SpinningEarth::draw(SDL_Renderer* renderer) {
            // SDL_Rect currentPixel = { 0, 0, 1, 1}
            // int steps = equatorRadius
            // sizes[i]
//update
// g++ EarthDemo.cpp SpinningEarth.cpp Factory.o ../gameEngine/window.o
// UPDATING=
    //         SDL_Rect msgPosition = { 800, 500, 0, 0 };
    //     SDL_Texture* msgTexture = factory -> createTextBox(messages);
    // SDL_QueryTexture(msgTexture, NULL, NULL, &msgPosition.w, &msgPosition.h);
    // std::cout << theTexture << std::endl;
    // memory leak SDL_UpdateTexture(SD
        SDL_Rect target = { 200, 200, 400, 354 };
        SDL_RenderCopy(renderer, globe, NULL, &target );
        }

        // void SpinningEarth::changeColor(SDL_Renderer *renderer) {
        //     SDL_Texture newWorld = ;
        //
        //     for(int x = 0; x < xsize; x++) {
        //         for(int y = 0; y < height; y++)
        //         {
        //             SDL_Rect rect = { x, y, 1, 1 };
        //             SDL_RenderReadPixels(renderer,
        //                  rect,
        //                  format,
        //                  pixels,
        //                  pitch)
        //
        //
        //         }
            // }
        // }
