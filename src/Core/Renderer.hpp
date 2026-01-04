/**
 * @file Renderer.hpp
 * @brief Déclaration de la classe Renderer.
 */

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL3/SDL.h>

/**
 * @class Renderer
 * @brief Gère le rendu graphique avec SDL3.
 */
class Renderer
{
public:
    /**
     * @brief Constructeur du renderer.
     * @param window Fenêtre SDL associée.
     */
    explicit Renderer(SDL_Window* window);

    /**
     * @brief Destructeur du renderer.
     */
    ~Renderer();

    /**
     * @brief Efface l'écran.
     */
    void Clear();

    /**
     * @brief Présente le rendu à l'écran.
     */
    void Present();

private:
    SDL_Renderer* mRenderer;
};

#endif // RENDERER_HPP
