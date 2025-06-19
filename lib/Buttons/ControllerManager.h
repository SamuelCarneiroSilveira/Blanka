#ifndef CONTROLLER_MANAGER_H
#define CONTROLLER_MANAGER_H

#include "ButtonManager.h"
#include <Arduino.h>
#include "config.h" // Assumindo que config.h define PIN_UP, PIN_DOWN, etc.

// Use 'extern' para indicar que a variável é definida em outro lugar (.cpp)
extern ButtonManager buttonManager; // Declarada aqui, definida no .cpp

// Declarações das funções (protótipos)
void ControlerBegin();
void getControlerData();

#endif