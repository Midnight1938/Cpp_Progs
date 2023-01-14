#include <iostream>
#include <random>
#include <ranges>
#include <algorithm>
#include <SDL2/SDL.h>

/*
! Sort Visualizes: https://invidious.osi.kr/embed/V7Nyq6-dzCI
* Making a sorting visualizer for 
*/

void draw_states(
    std::vector<int> &vector,
    SDL_Renderer *renderer,
    unsigned int red, unsigned int blue)
{
    unsigned int index = 0;
    for (int i : vector)
    {
        if (index == red){SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);}
        else if (index == blue){SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);}
        else{SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);}

        SDL_RenderDrawLine(renderer, index, 199, index, i);
        index += 1;
    };
}

int main()
{
    std::random_device rd;
    std::uniform_int_distribution<int> distrib(1, 199);
    std::vector<int> vect;

    //? Populate the vector
    for (int i = 0; i < 200; i++)
    {
        vect.push_back(distrib(rd));
    }

    //? Window renderer
    SDL_Window *window = nullptr;
    SDL_Renderer *rendrr = nullptr;
    SDL_CreateWindowAndRenderer(40 * 10, 40 * 10, 0, &window, &rendrr);
    SDL_RenderSetScale(rendrr, 2, 2);

    //? Sort Algo
    for (unsigned int i = 0; i < vect.size(); i++) //! RED
    {
        for (unsigned int j = i; j < vect.size(); j++) //? BLUE
        {
            if (vect[j] < vect[i])
            {
                std::swap(vect[j], vect[i]);
            }
            SDL_SetRenderDrawColor(rendrr, 0, 0, 0, 255);
            SDL_RenderClear(rendrr);

            //? Draw sort state
            draw_states(vect, rendrr, i, j);
            //? Show state in window
            SDL_RenderPresent(rendrr);
            SDL_Delay(1);
        }
    };

    return 0;
}