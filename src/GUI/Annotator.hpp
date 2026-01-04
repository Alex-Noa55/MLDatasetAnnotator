/**
 * @file Annotator.hpp
 * @brief Déclaration de la classe Annotator.
 */

#ifndef ANNOTATOR_HPP
#define ANNOTATOR_HPP

#include <SDL3/SDL.h>

/**
 * @struct Annotation
 * @brief Représente une annotation rectangulaire.
 */
struct Annotation
{
    int x;
    int y;
    int width;
    int height;
};

/**
 * @class Annotator
 * @brief Gère les interactions utilisateur pour l'annotation.
 */
class Annotator
{
public:
    /**
     * @brief Constructeur de l'annotator.
     */
    Annotator();

    /**
     * @brief Gère un événement SDL.
     * @param event Événement SDL.
     */
    void HandleEvent(const SDL_Event& event);

    /**
     * @brief Met à jour l'état de l'annotation.
     */
    void Update();

    /**
     * @brief Récupère l'annotation courante.
     * @return Annotation active.
     */
    const Annotation& GetAnnotation() const;

    /**
     * @brief Indique si une annotation est terminée.
     * @return true si terminée, false sinon.
     */
    bool IsAnnotationComplete() const;

private:
    bool mIsDrawing;
    Annotation mCurrentAnnotation;
};

#endif // ANNOTATOR_HPP

