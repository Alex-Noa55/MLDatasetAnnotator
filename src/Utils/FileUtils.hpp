/**
 * @file FileUtils.hpp
 * @brief Fonctions utilitaires pour la gestion des fichiers.
 */

#ifndef FILEUTILS_HPP
#define FILEUTILS_HPP

#include <string>
#include "../GUI/Annotator.hpp"

/**
 * @class FileUtils
 * @brief Fournit des outils de sauvegarde des annotations.
 */
class FileUtils
{
public:
    /**
     * @brief Sauvegarde une annotation dans un fichier texte.
     * @param filePath Chemin du fichier de sortie.
     * @param annotation Annotation à sauvegarder.
     * @return true si succès, false sinon.
     */
    static bool SaveAnnotation(
        const std::string& filePath,
        const Annotation& annotation
    );
};

#endif // FILEUTILS_HPP

