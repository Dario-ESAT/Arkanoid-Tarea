@echo off
cl /nologo /Zi /MDd /EHs /W1 /DSFML_STATIC /c -I ../include -I ../deps/sfml/x86/include ../src/main.cc
cl /nologo /Zi /MDd /EHs /W1 /DSFML_STATIC /c -I ../include -I ../deps/sfml/x86/include ../src/ball.cc
cl /nologo /Zi /MDd /EHs /W1 /DSFML_STATIC /c -I ../include -I ../deps/sfml/x86/include ../src/brick.cc
cl /nologo /Zi /MDd /EHs /W1 /DSFML_STATIC /c -I ../include -I ../deps/sfml/x86/include ../src/definitions.cc
cl /nologo /Zi /MDd /EHs /W1 /DSFML_STATIC /c -I ../include -I ../deps/sfml/x86/include ../src/platform.cc

cl /nologo /Zi /MDd /EHs /W1 main.obj ball.obj brick.obj definitions.obj platform.obj ../deps/sfml/x86/lib/sfml-system-s-d.lib ../deps/sfml/x86/lib/sfml-window-s-d.lib ../deps/sfml/x86/lib/sfml-graphics-s-d.lib ../deps/sfml/x86/lib/freetype.lib winmm.lib opengl32.lib shell32.lib gdi32.lib user32.lib advapi32.lib