#include <SDL.h>
#include <SDL_image.h>

class Button {
    public:
        SDL_Renderer * renderer;
        SDL_Texture * tex;
        SDL_Rect srect, drect;
        bool isSelected = false;

        Button();
        Button(SDL_Renderer *);
        virtual ~Button();

        void update();
        void draw();
};
