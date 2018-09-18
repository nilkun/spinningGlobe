/***********************************
  GAME ENGINE WITH A FANTASTIC NAME
  ----------A NEW FACTORY----------
  ---------------------------------
  by nilkun

 **********************************/

#ifndef FACTORY_H_
#define FACTORY_H_

#include <SDL2/SDL.h>

#include <iostream>
#include <deque>
#include <string>
#include <unordered_map>


class Font 
        {
        public:
            std::unordered_map<int, SDL_Rect> fontMap;
            SDL_Texture *texture;
        };

class Factory {

/* CREATING A SINGLETON */

public:
    static Factory* getInstance()
      {
        static Factory singleton;
        return &singleton;
      }

private:
      Factory() {};                            
      Factory(const Factory&);                 
      Factory& operator=(const Factory&);      
    
/* END OF SINGLETON CREATION */

private:
    SDL_Color color;
    int spacing = 10;
    SDL_Renderer *renderer;
   

public:
    Font font;
    void setRenderer(SDL_Renderer *renderer);
    SDL_Renderer* getRenderer();
    SDL_Texture* createTextBox(std::deque<std::string> messages);
    Font create8bitAtlas();
    void init();
    SDL_Texture* fromImage(const char* imageLocation);
};


#endif