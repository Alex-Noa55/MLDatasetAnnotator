/**
 * @file Renderer.cpp
 * @brief Implémentation de la classe Renderer.
 */

#include "Renderer.hpp"
#include <iostream>

Renderer::Renderer(SDL_Window* window)
    : mRenderer(nullptr)
{
    mRenderer = SDL_CreateRenderer(window, nullptr);
    if (mRenderer == nullptr)
    {
        std::cerr << "SDL_CreateRenderer error: " << SDL_GetError() << std::endl;
    }
}

Renderer::~Renderer()
{
    if (mRenderer != nullptr)
    {
        SDL_DestroyRenderer(mRenderer);
        mRenderer = nullptr;
    }
}

void Renderer::Clear()
{
    if (mRenderer == nullptr)
    {
        return;
    }

    SDL_SetRenderDrawColor(mRenderer, 30, 30, 30, 255);
    SDL_RenderClear(mRenderer);
}

void Renderer::Present()
{
    if (mRenderer == nullptr)
    {
        return;
    }

    SDL_RenderPresent(mRenderer);
}
