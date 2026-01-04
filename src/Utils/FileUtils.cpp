/**
 * @file FileUtils.cpp
 * @brief Implémentation des fonctions utilitaires de fichiers.
 */

#include "FileUtils.hpp"
#include <fstream>

bool FileUtils::SaveAnnotation(
    const std::string& filePath,
    const Annotation& annotation
)
{
    std::ofstream file(filePath);
    if (!file.is_open())
    {
        return false;
    }

    file << "x=" << annotation.x << std::endl;
    file << "y=" << annotation.y << std::endl;
    file << "width=" << annotation.width << std::endl;
    file << "height=" << annotation.height << std::endl;

    file.close();
    return true;
}

