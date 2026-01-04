/**
 * @file App.cpp
 * @brief Implémentation de la classe App.
 */

#include "App.hpp"
#include "Utils/FileUtils.hpp"
#include <iostream>

App::App()
    : mWindow(nullptr),
      mRenderer(nullptr),
      mIsRunning(false)
{
}

App::~App()
{
    Shutdown();
}

bool App::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
        return false;
    }

    mWindow = SDL_CreateWindow(
        "ML Dataset Annotator",
        800,
        600,
        SDL_WINDOW_RESIZABLE
    );

    if (mWindow == nullptr)
    {
        std::cerr << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
        return false;
    }

    mRenderer = new Renderer(mWindow);
    mIsRunning = true;
    return true;
}

void App::Run()
{
    if (!Init())
    {
        return;
    }

    while (mIsRunning)
    {
        ProcessEvents();
        Update();
        Render();
        SDL_Delay(16);
    }
}

void App::ProcessEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
        {
            mIsRunning = false;
        }

        mAnnotator.HandleEvent(event);
    }
}

void App::Update()
{
    if (mAnnotator.IsAnnotationComplete())
    {
        FileUtils::SaveAnnotation(
            "annotation.txt",
            mAnnotator.GetAnnotation()
        );
    }
}

void App::Render()
{
    mRenderer->Clear();
    mRenderer->Present();
}

void App::Shutdown()
{
    delete mRenderer;
    mRenderer = nullptr;

    if (mWindow != nullptr)
    {
        SDL_DestroyWindow(mWindow);
        mWindow = nullptr;
    }

    SDL_Quit();
}
