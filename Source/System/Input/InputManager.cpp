#include "InputManager.hpp"

static InputManager *inputManagerGlobalInstance = NULL;

void InputManager::Initialize()
{
    GetInstance();
}

void InputManager::Deinitialize()
{
    
}

InputManager *InputManager::GetInstance()
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
    
    //Setup some default player actions, if there are
    //custom keyboard actions these will be replaced
    currentKeyboardPlayerActions.Forward  = SDL_SCANCODE_UP;
    currentKeyboardPlayerActions.Backward = SDL_SCANCODE_DOWN;
    currentKeyboardPlayerActions.Left = SDL_SCANCODE_LEFT;
    currentKeyboardPlayerActions.Right = SDL_SCANCODE_RIGHT;
    
    currentKeyboardPlayerActions.ForwardLeft = SDL_SCANCODE_HOME;
    currentKeyboardPlayerActions.ForwardRight = SDL_SCANCODE_PAGEUP;
    currentKeyboardPlayerActions.BackwardLeft = SDL_SCANCODE_END;
    currentKeyboardPlayerActions.BackwardRight = SDL_SCANCODE_PAGEDOWN;
    
    currentKeyboardPlayerActions.Run = SDL_SCANCODE_LSHIFT;
    currentKeyboardPlayerActions.Use = SDL_SCANCODE_SPACE;
    currentKeyboardPlayerActions.Fire = SDL_SCANCODE_LCTRL;
    currentKeyboardPlayerActions.Strafe = SDL_SCANCODE_LALT;
    
    currentKeyboardPlayerActions.ReadyKnife = SDL_GetScancodeFromKey(SDLK_1);
    currentKeyboardPlayerActions.ReadyPistol = SDL_GetScancodeFromKey(SDLK_2);
    currentKeyboardPlayerActions.ReadyMachineGun = SDL_GetScancodeFromKey(SDLK_3);
    currentKeyboardPlayerActions.ReadyGatlingGun = SDL_GetScancodeFromKey(SDLK_4);
    
    
    keyboardPlayerActions = &currentKeyboardPlayerActions;
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