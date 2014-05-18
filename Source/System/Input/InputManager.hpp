/*!
 *  \brief
 *  \details
 *  \author    Bradley Clemetson
 *  \version   0.01
 *  \date      May 17, 2014
 *  \copyright GPLv2
 */

#ifndef InputManager_Header
#define InputManager_Header

//SDL2 Keyboard Handling
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_scancode.h>

//SDL2 Mouse Handling
#include <SDL2/SDL_mouse.h>

//Joystick Handling
#include <SDL2/SDL_joystick.h>

#include <vector>



class InputManager
{
    public:
        //Structure to allow for different player
        //keyboard mappings
        struct PlayerActions
        {
            int Forward, Backward, Left, Right,
                ForwardLeft, ForwardRight, BackwardLeft, BackwardRight,
                Run, Use, Fire, Strafe, ReadyKnife, ReadyPistol, ReadyMachineGun,
                ReadyGatlingGun;
        };
    
        static void Initialize();
        static void Deinitialize();
    
        static InputManager *GetInstance();
    
        //Force update the state of all
        //user input devices
        void ForceUpdateStateAll();
    
        void ForceUpdateStateKeyboard();
        void ForceUpdateStateMouse();
        void ForceUpdateStateJoystick();
    
        //An array of all the Keyboard Keys
        unsigned int GetNumberOfKeyboardKeys();
        const Uint8 *currentKeyboardState;
        const PlayerActions *keyboardPlayerActions;
    
    protected:
        PlayerActions currentKeyboardPlayerActions;
    private:
    
        InputManager();
        ~InputManager();
};
#endif