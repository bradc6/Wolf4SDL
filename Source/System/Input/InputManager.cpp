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
    currentKeyboardPlayerActions.Forward.assignedButton  = SDL_SCANCODE_UP;
    currentKeyboardPlayerActions.Backward.assignedButton = SDL_SCANCODE_DOWN;
    currentKeyboardPlayerActions.Left.assignedButton = SDL_SCANCODE_LEFT;
    currentKeyboardPlayerActions.Right.assignedButton = SDL_SCANCODE_RIGHT;
    
    currentKeyboardPlayerActions.ForwardLeft.assignedButton = SDL_SCANCODE_HOME;
    currentKeyboardPlayerActions.ForwardRight.assignedButton = SDL_SCANCODE_PAGEUP;
    currentKeyboardPlayerActions.BackwardLeft.assignedButton = SDL_SCANCODE_END;
    currentKeyboardPlayerActions.BackwardRight.assignedButton = SDL_SCANCODE_PAGEDOWN;
    
    currentKeyboardPlayerActions.Run.assignedButton = SDL_SCANCODE_LSHIFT;
    currentKeyboardPlayerActions.Use.assignedButton = SDL_SCANCODE_SPACE;
    currentKeyboardPlayerActions.Fire.assignedButton = SDL_SCANCODE_LCTRL;
    currentKeyboardPlayerActions.Strafe.assignedButton = SDL_SCANCODE_LALT;
    
    currentKeyboardPlayerActions.ReadyKnife.assignedButton = SDL_GetScancodeFromKey(SDLK_1);
    currentKeyboardPlayerActions.ReadyPistol.assignedButton = SDL_GetScancodeFromKey(SDLK_2);
    currentKeyboardPlayerActions.ReadyMachinegun.assignedButton = SDL_GetScancodeFromKey(SDLK_3);
    currentKeyboardPlayerActions.ReadyChaingun.assignedButton = SDL_GetScancodeFromKey(SDLK_4);
    
    
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
    currentKeyboardState = SDL_GetKeyboardState(NULL);
}

void InputManager::ForceUpdateStateMouse()
{

}

void InputManager::ForceUpdateStateJoystick()
{
    
}

unsigned int InputManager::GetNumberOfKeyboardKeys()
{
    return sizeof(currentKeyboardState);
}