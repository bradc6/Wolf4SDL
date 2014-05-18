#include "InputManager.hpp"

static InputManager *inputManagerGlobalInstance = NULL;

void InputManager::Initialize()
{
    GetInstace();
}

void InputManager::Deinitialize()
{
    
}

InputManager *InputManager::GetInstace()
{
    if(!inputManagerGlobalInstance)
    {
        inputManagerGlobalInstance = new InputManager;
    }
    
    return inputManagerGlobalInstance;
}

InputManager::InputManager()
{
    ForceUpdateStateAll();
}

InputManager::~InputManager()
{
    
}

void InputManager::ForceUpdateStateAll()
{
    ForceUpdateStateKeyboard();
    ForceUpdateStateMouse();
    ForceUpdateStateJoystick();
}

void InputManager::ForceUpdateStateKeyboard()
{
    
}

void InputManager::ForceUpdateStateMouse()
{
       currentKeyboardState = SDL_GetKeyboardState(NULL);
}

void InputManager::ForceUpdateStateJoystick()
{
    
}

unsigned int InputManager::GetNumberOfKeyboardKeys()
{
    return sizeof(currentKeyboardState);
}