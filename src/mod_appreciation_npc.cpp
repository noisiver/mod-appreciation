#include "mod_appreciation.h"

bool Appreciation::OnGossipHello(Player* player, Creature* creature)
{
    ClearGossipMenuFor(player);

    if (!HasCertificate(player))
    {
        SendGossipMenuFor(player, GOSSIP_TEXT_CERTIFICATE_MISSING, creature->GetGUID());
        return true;
    }

    if (EnableLevelBoost)
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want a character boost", GOSSIP_SENDER_MAIN, GOSSIP_MENU_CHOOSE_SPECIALIZATION);

    if (EnableUnlockContinents)
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to unlock flight paths", GOSSIP_SENDER_MAIN, GOSSIP_MENU_CHOOSE_CONTINENT);

    SendGossipMenuFor(player, GOSSIP_TEXT_DEFAULT, creature->GetGUID());
    return true;
}

bool Appreciation::OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
{
    if (sender != GOSSIP_SENDER_MAIN)
        return false;

    if (action == GOSSIP_MENU_CHOOSE_SPECIALIZATION)
    {
        ClearGossipMenuFor(player);

        switch (player->getClass())
        {
        case CLASS_WARRIOR:
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be an Arms Warrior", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Fury Warrior", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Protection Warrior", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
            break;
        case CLASS_PALADIN:
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Holy Paladin", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Protection Paladin", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Retribution Paladin", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
            break;
        case CLASS_HUNTER:
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Beast Mastery Hunter", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Marksmanship Hunter", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Survival Hunter", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
            break;
        case CLASS_ROGUE:
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be an Assassination Rogue", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Combat Rogue", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Subtlety Rogue", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
            break;
        case CLASS_PRIEST:
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Discipline Priest", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Holy Priest", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Shadow Priest", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
            break;
        case CLASS_DEATH_KNIGHT:
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Blood Death Knight", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Frost Death Knight", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Unholy Death Knight", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
            break;
        case CLASS_SHAMAN:
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be an Elemental Shaman", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be an Enhancement Shaman", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Restoration Shaman", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
            break;
        case CLASS_MAGE:
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be an Arcane Mage", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Fire Mage", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Frost Mage", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
            break;
        case CLASS_WARLOCK:
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be an Affliction Warlock", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Demonology Warlock", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Destruction Warlock", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
            break;
        case CLASS_DRUID:
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Balance Druid", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Feral Druid", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Restoration Druid", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
            break;
        }

        SendGossipMenuFor(player, GOSSIP_TEXT_CHOOSE_SPECIALIZATION, creature->GetGUID());
    }
    else if (action == GOSSIP_MENU_SPECIALIZATION_1 || action == GOSSIP_MENU_SPECIALIZATION_2 || action == GOSSIP_MENU_SPECIALIZATION_3)
    {
        ClearGossipMenuFor(player);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I'm sure!", GOSSIP_SENDER_MAIN, action + 100);
        SendGossipMenuFor(player, GOSSIP_TEXT_CONFIRM_SPECIALIZATION, creature->GetGUID());
    }
    else if (action == GOSSIP_MENU_SPECIALIZATION_1 + 100 || action == GOSSIP_MENU_SPECIALIZATION_2 + 100 || action == GOSSIP_MENU_SPECIALIZATION_3 + 100)
    {
        CloseGossipMenuFor(player);
        BoostPlayer(player, action - 300);
    }
    else if (action == GOSSIP_MENU_CHOOSE_CONTINENT)
    {
        ClearGossipMenuFor(player);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Eastern Kingdoms", GOSSIP_SENDER_MAIN, GOSSIP_MENU_CHOOSE_EASTERN_KINGDOMS);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Kalimdor", GOSSIP_SENDER_MAIN, GOSSIP_MENU_CHOOSE_KALIMDOR);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Outland", GOSSIP_SENDER_MAIN, GOSSIP_MENU_CHOOSE_OUTLAND);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Northrend", GOSSIP_SENDER_MAIN, GOSSIP_MENU_CHOOSE_NORTHREND);
        SendGossipMenuFor(player, GOSSIP_TEXT_CHOOSE_CONTINENT, creature->GetGUID());
    }
    else if (action == GOSSIP_MENU_CHOOSE_EASTERN_KINGDOMS || action == GOSSIP_MENU_CHOOSE_KALIMDOR || action == GOSSIP_MENU_CHOOSE_OUTLAND || action == GOSSIP_MENU_CHOOSE_NORTHREND)
    {
        CloseGossipMenuFor(player);
        UnlockContinent(player, action - 500);
    }

    return true;
}
