#ifndef MOD_KICKSTARTER_H
#define MOD_KICKSTARTER_H

#include "Chat.h"
#include "Config.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"

enum
{
    ITEM_CERTIFICATE                    = 20460,

    GOSSIP_MENU_CHOOSE_SPECIALIZATION   = 100,
    GOSSIP_MENU_SPECIALIZATION_1        = 200,
    GOSSIP_MENU_SPECIALIZATION_2        = 201,
    GOSSIP_MENU_SPECIALIZATION_3        = 202,
    GOSSIP_MENU_CHOOSE_CONTINENT        = 400,
    GOSSIP_MENU_CHOOSE_EASTERN_KINGDOMS = 500,
    GOSSIP_MENU_CHOOSE_KALIMDOR         = 501,
    GOSSIP_MENU_CHOOSE_OUTLAND          = 502,
    GOSSIP_MENU_CHOOSE_NORTHREND        = 503,
    GOSSIP_TEXT_DEFAULT                 = 48,
    GOSSIP_TEXT_CERTIFICATE_MISSING     = 6000000,
    GOSSIP_TEXT_CHOOSE_SPECIALIZATION   = 6000001,
    GOSSIP_TEXT_CONFIRM_SPECIALIZATION  = 6000002,
    GOSSIP_TEXT_CHOOSE_CONTINENT        = 6000003,

    CONTINENT_EASTERN_KINGDOMS          = 0,
    CONTINENT_KALIMDOR                  = 1,
    CONTINENT_OUTLAND                   = 2,
    CONTINENT_NORTHREND                 = 3,

    ITEM_ENTRY                          = 0,
    ITEM_RANDOM_PROPERTY                = 1,

    DEFAULT_LEVEL                       = 60,

    SPECIALIZATION_1                    = 0,
    SPECIALIZATION_2                    = 1,
    SPECIALIZATION_3                    = 2,

    SPELL_ONE_HANDED_MACES              = 198,
    SPELL_TWO_HANDED_MACES              = 199,
    SPELL_ONE_HANDED_SWORDS             = 201,
    SPELL_TWO_HANDED_SWORDS             = 202,
    SPELL_STAVES                        = 227,
    SPELL_BOWS                          = 264,
    SPELL_DUAL_WIELD                    = 674,
    SPELL_PLATE_MAIL                    = 750,
    SPELL_DAGGERS                       = 1180,
    SPELL_THROWN                        = 2567,
    SPELL_WANDS                         = 5009,
    SPELL_MAIL                          = 8737
};

using namespace Acore::ChatCommands;

class Appreciation : public CreatureScript, WorldScript
{
public:
    Appreciation();

    // CreatureScript
    bool OnGossipHello(Player* /*player*/, Creature* /*creature*/) override;
    bool OnGossipSelect(Player* /*player*/, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/) override;

    // WorldScript
    void OnAfterConfigLoad(bool /*reload*/) override;

private:
    bool RequireCertificate;
    bool EnableLevelBoost;
    uint32 TargetLevel;
    uint32 IncludedCopper;
    bool EnableUnlockContinents;

    bool HasCertificate(Player* /*player*/);
    std::vector<std::vector<int>> GetItemList(uint32 /*classId*/, uint8 /*specialization*/);
    void BoostPlayer(Player* /*player*/, uint8 /*specialization*/);
    void UpdatePlayerLevel(Player* /*player*/);
    void UpdateProficiencies(Player* /*player*/, uint8 /*specialization*/);
    void EquipNewItems(Player* /*player*/, uint8 /*specialization*/);
    void GiveCopper(Player* /*player*/);
    void UnlockContinent(Player* /*player*/, uint8 /*continent*/);
    void RemoveCertificate(Player* /*player*/);
};

#endif
