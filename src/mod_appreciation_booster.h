#ifndef MOD_APPRECIATION_BOOSTER_H
#define MOD_APPRECIATION_BOOSTER_H

#include "Player.h"

class CharacterBooster
{
public:
    static void BoostPlayerWithGear(Player *player, uint32 targetLevel, uint8 specialization, uint32 copperAmount);
private:
    static void UpdatePlayerLevel(Player *player, uint32 targetLevel); 
    static void UpdateProficiencies(Player *player, uint8 specialization);
    static void EquipNewItems(Player *player, uint8 specialization, uint32 targetLevel);
    static void GiveCopper(Player *player, uint32 copperAmount);
    static std::vector<std::vector<int>> GetItemList(uint32 classId, uint8 specialization, uint32 targetLevel);
};

#endif
