"""
@file build.py
@brief Script de compilation du projet MLDatasetAnnotator.
"""

import os
import sys

OUTPUT_NAME = "application.exe"
COMPILER = "g++"

SOURCES = [
    "src/main.cpp",
    "src/App.cpp",
    "src/GUI/Annotator.cpp",
    "src/Core/Renderer.cpp",
    "src/Utils/FileUtils.cpp"
]

INCLUDE_DIR = "thirdparty/SDL3/include"
LIB_DIR = "thirdparty/SDL3/lib"

command = (
    f"{COMPILER} "
    + " ".join(SOURCES)
    + f" -I{INCLUDE_DIR} "
    + f" -L{LIB_DIR} -lSDL3 "
    + f"-o {OUTPUT_NAME}"
)

print("Compilation en cours...")
print(command)

result = os.system(command)

if result != 0:
    print("❌ Erreur de compilation")
    sys.exit(1)

print("✅ Compilation réussie")
print(f"Exécutable généré : {OUTPUT_NAME}")
