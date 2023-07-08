#include "mod_appreciation.h"

Appreciation::Appreciation() : CreatureScript("npc_appreciation"), WorldScript("AppreciationWorldScript") {}

void Addmod_appreciationScripts()
{
    new Appreciation();
}
