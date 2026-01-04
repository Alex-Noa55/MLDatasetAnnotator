/**
 * @file App.hpp
 * @brief Déclaration de la classe App.
 */

#ifndef APP_HPP
#define APP_HPP

#include <SDL3/SDL.h>
#include "Core/Renderer.hpp"
#include "GUI/Annotator.hpp"

/**
 * @class App
 * @brief Classe principale de l'application.
 */
class App
{
public:
    App();
    ~App();

    /**
     * @brief Lance l'application.
     */
    void Run();

private:
    bool Init();
    void ProcessEvents();
    void Update();
    void Render();
    void Shutdown();

private:
    SDL_Window* mWindow;
    Renderer* mRenderer;
    Annotator mAnnotator;
    bool mIsRunning;
};

#endif // APP_HPP
