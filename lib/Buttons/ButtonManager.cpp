#include "ButtonManager.h"

// Comstrutor
ButtonManager::ButtonManager(int *buttonPins, int numButtons, unsigned long debounce)
{
    this->numButtons = numButtons;
    this->debounceDelay = debounce;

    // Alocar memória para os arrays 
    pins = new int[numButtons];
    states = new bool[numButtons];
    lastStates = new bool[numButtons];
    lastTimes = new unsigned long[numButtons];
    
    // Inicializa os arrays
    for(int i = 0; i < numButtons; i++)
    {
        pins[i] = buttonPins[i];
        states[i] = false;
        lastStates[i] = false;
        lastTimes[i] = 0;
    }
}

// Inicialização dos pinos
void ButtonManager::begin()
{
  for (int i = 0; i < numButtons; i++)
  {
    pinMode(pins[i], INPUT_PULLUP); // Configura como input pull up
  }   
}

// Atualiza o estado dos botões
void ButtonManager::update()
{
    for (int i =0; i < numButtons; i++)
    {
        bool currentState = digitalRead(pins[i]) == LOW;
        
        // Verifica debounce
        if (currentState != lastStates[i])
        {
            lastTimes[i] = millis(); // Atualiza o temporazador
        }

        if((millis() - lastTimes[i]) > debounceDelay)
        {
            if(currentState != states[i])
            {
                states[i] = currentState; // Atualiza o estado do botão
            }
        }
        
        lastStates[i] = currentState; // Atualiza o estado anterior
    
    }
}

// retorna o estado de um botão (true = pressionado, false = não pressionado)
bool ButtonManager::isPressed(int buttonIndex)
{
    if (buttonIndex >= 0 && buttonIndex < numButtons)
    {
        return states[buttonIndex];
    }
    return false; // retorna false se o indicador for inválido
}

// Retorna true somente quando o botão vai de LOW para HIGH
bool ButtonManager::isReleased(int buttonIndex)
{
    if (buttonIndex >= 0 && buttonIndex < numButtons)
    {
        return lastStates[buttonIndex] && !states[buttonIndex];
    }
    return false; // Retorna false se o índice for inválido
}