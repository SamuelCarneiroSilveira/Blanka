#include "ControllerManager.h" // Inclui o próprio header para garantir consistência
#include "../../src/config.h" // Inclui o arquivo de configuração para os pinos dos botões

// Certifique-se de que os pinos estão definidos em config.h, por exemplo:
// #define PIN_UP    2
// #define PIN_DOWN  3
// #define PIN_LEFT  4
// #define PIN_RIGHT 5

int buttonPins[] = {PIN_UP, PIN_DOWN, PIN_LEFT, PIN_RIGHT}; // Adicionar aqui mais botões
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);

// Definições das instâncias globais (sem 'extern' aqui)
// As instâncias são criadas AQUI e são visíveis para todo o projeto através do 'extern' no .h
ButtonManager buttonManager(buttonPins, numButtons);

// Implementação das funções


void ControlerBegin()
{
    buttonManager.begin(); // Inicializa os botões
}

void getControlerData()
{
    buttonManager.update();
}