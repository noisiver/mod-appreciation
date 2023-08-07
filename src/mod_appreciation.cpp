#include "mod_appreciation.h"

Appreciation::Appreciation() : CreatureScript("npc_appreciation"), PlayerScript("AppreciationPlayerScript"), WorldScript("AppreciationWorldScript") {}

void Addmod_appreciationScripts()
{
    new Appreciation();
}
