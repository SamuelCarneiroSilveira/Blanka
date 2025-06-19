// (guard) Impede que a classe inicie mais de uma vez
#ifndef BUTTON_MANAGER_H
#define BUTTON_MANAGER_H

#include <Arduino.h>

// Recebe os pinos dos botões e quando estão apertados
// Retorna o estado dos botões, com debounce
// Atualize a leitura no começo do loop

class ButtonManager 
{
private:
    int *pins; // Array de pinos dos botões
    bool *states; // Estado atual dos botões
    bool *lastStates; // ultimo estado dos botões
    unsigned long *lastTimes; // temporizador para debounce
    int numButtons; // Número de botões
    unsigned long debounceDelay; // Tempo de debounce

public:
    // Construtor
    ButtonManager(int *buttonPins, int numButtons, unsigned long debounce = 50);

    // Inicialização dos pinos
    void begin();

    // Atualização dos estados dos botões
    void update();

    // Retorna o estado de um botão (true = pressionado, false = não pressionado)
    bool isPressed(int buttonIndex);

    // Retorna true somente quando o botão vai de LOW para HIGH
    bool isReleased(int buttonIndex);
};

#endif // BUTTON_MANAGER_H