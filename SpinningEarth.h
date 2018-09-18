#ifndef SPINNINGEARTH_H_
#define SPINNINGEARTH_H_
#include <SDL2/SDL.h>

class SpinningEarth {
    public:

        const int radius = 511;

        void init(SDL_Renderer *renderer);
        void update(SDL_Renderer *renderer);
        void draw(SDL_Renderer* renderer); 
        // void changeColor(SDL_Renderer *renderer);
        struct Lines {
            double steps;
            double size;
        };

        Lines line[511/2];
        SDL_Texture* earthTexture;
        SDL_Texture* globe;

        SDL_Rect sourceNE;
        SDL_Rect sourceNW;
        SDL_Rect targetNE;
        SDL_Rect targetNW;
        SDL_Rect sourceSE;
        SDL_Rect sourceSW;
        SDL_Rect targetSE;
        SDL_Rect targetSW;

        int spin;


       //48 bytes;
    // 100 * 100 = 10,000 bytes, 480,000 bytes = 480 kilobytes

    // 11 974 borders
    // 974 - 12 = 962 * 2 = 1924

    // 1909 10 length
    // 783 - 354 = 429
// MAP 783 x 354;
    /*
        Get length of each arc

        half earth

        cos and sin of earth

        length 1 >> length half earth
        circumference
    */
        // float length;

        // vector<float> pixels;

        double earthRadius;
        int equatorRadius; // 391.5 /2 = 195.75 = 196
        double hypoteneuseSquared;
        // float sizes[earthRadius];

};

#endif
