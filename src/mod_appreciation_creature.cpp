#include "mod_appreciation.h"

#include "Config.h"
#include "CreatureScript.h"
#include "Player.h"
#include "ScriptedGossip.h"

class AppreciationCreature : public CreatureScript
{
public:
    AppreciationCreature() : CreatureScript("npc_appreciation") {}

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        ClearGossipMenuFor(player);

        if (!HasCertificate(player))
        {
            SendGossipMenuFor(player, GOSSIP_TEXT_CERTIFICATE_MISSING, creature->GetGUID());
            return true;
        }

        uint32 TargetLevel = sConfigMgr->GetOption<uint32>("Appreciation.LevelBoost.TargetLevel", DEFAULT_LEVEL);

        if (TargetLevel != 60 && TargetLevel != 70 && TargetLevel != 80)
            TargetLevel = DEFAULT_LEVEL;

        if (sConfigMgr->GetOption<bool>("Appreciation.LevelBoost.Enabled", true) && player->GetLevel() < TargetLevel)
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want a character boost", GOSSIP_SENDER_MAIN, GOSSIP_MENU_CHOOSE_SPECIALIZATION);

        if (sConfigMgr->GetOption<bool>("Appreciation.UnlockContinents.Enabled", true) && (sConfigMgr->GetOption<bool>("Appreciation.UnlockContinents.EasternKingdoms.Enabled", true) || sConfigMgr->GetOption<bool>("Appreciation.UnlockContinents.Kalimdor.Enabled", true) || sConfigMgr->GetOption<bool>("Appreciation.UnlockContinents.Outland.Enabled", true) || sConfigMgr->GetOption<bool>("Appreciation.UnlockContinents.Northrend.Enabled", false)))
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to unlock flight paths", GOSSIP_SENDER_MAIN, GOSSIP_MENU_CHOOSE_CONTINENT);

        SendGossipMenuFor(player, GOSSIP_TEXT_DEFAULT, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
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

            if (sConfigMgr->GetOption<bool>("Appreciation.UnlockContinents.EasternKingdoms.Enabled", true))
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Eastern Kingdoms", GOSSIP_SENDER_MAIN, GOSSIP_MENU_CHOOSE_EASTERN_KINGDOMS);

            if (sConfigMgr->GetOption<bool>("Appreciation.UnlockContinents.Kalimdor.Enabled", true))
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Kalimdor", GOSSIP_SENDER_MAIN, GOSSIP_MENU_CHOOSE_KALIMDOR);

            if (sConfigMgr->GetOption<bool>("Appreciation.UnlockContinents.Outland.Enabled", true))
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Outland", GOSSIP_SENDER_MAIN, GOSSIP_MENU_CHOOSE_OUTLAND);

            if (sConfigMgr->GetOption<bool>("Appreciation.UnlockContinents.Northrend.Enabled", false))
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

private:
    bool HasCertificate(Player* player)
    {
        if (!sConfigMgr->GetOption<bool>("Appreciation.RequireCertificate.Enabled", true))
            return true;

        return player->HasItemCount(ITEM_CERTIFICATE);
    }

    void BoostPlayer(Player* player, uint8 specialization)
    {
        UpdatePlayerLevel(player);
        UpdateProficiencies(player, specialization);
        EquipNewItems(player, specialization);
        GiveCopper(player);
        RemoveCertificate(player);
    }

    void UpdatePlayerLevel(Player* player)
    {
        uint32 TargetLevel = sConfigMgr->GetOption<uint32>("Appreciation.LevelBoost.TargetLevel", DEFAULT_LEVEL);

        if (TargetLevel != 60 && TargetLevel != 70 && TargetLevel != 80)
            TargetLevel = DEFAULT_LEVEL;

        if (player->GetLevel() >= TargetLevel)
            return;

        player->GiveLevel(TargetLevel);
        player->SetUInt32Value(PLAYER_XP, 0);
    }

    void UpdateProficiencies(Player* player, uint8 specialization)
    {
        player->SetSkill(SKILL_DEFENSE, 0, player->GetMaxSkillValue(SKILL_DEFENSE), player->GetMaxSkillValue(SKILL_DEFENSE));

        uint8 classId = player->getClass();

        if ((classId == CLASS_WARRIOR || classId == CLASS_PALADIN) && !player->HasSkill(SKILL_PLATE_MAIL))
            player->learnSpell(SPELL_PLATE_MAIL);

        if ((classId == CLASS_SHAMAN || classId == CLASS_HUNTER) && !player->HasSkill(SKILL_MAIL))
            player->learnSpell(SPELL_MAIL);

        if ((classId == CLASS_WARRIOR && (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3)) ||
            (classId == CLASS_PALADIN && specialization == SPECIALIZATION_2))
        {
            if (!player->HasSkill(SKILL_SWORDS))
                player->learnSpell(SPELL_ONE_HANDED_SWORDS);

            player->SetSkill(SKILL_SWORDS, 0, player->GetMaxSkillValue(SKILL_SWORDS), player->GetMaxSkillValue(SKILL_SWORDS));
        }

        if ((classId == CLASS_WARRIOR && specialization == SPECIALIZATION_2) ||
            (classId == CLASS_PALADIN && specialization == SPECIALIZATION_3))
        {
            if (!player->HasSkill(SKILL_2H_SWORDS))
                player->learnSpell(SPELL_TWO_HANDED_SWORDS);

            player->SetSkill(SKILL_2H_SWORDS, 0, player->GetMaxSkillValue(SKILL_2H_SWORDS), player->GetMaxSkillValue(SKILL_2H_SWORDS));
        }

        if (classId == CLASS_WARRIOR || classId == CLASS_HUNTER)
        {
            if (!player->HasSkill(SKILL_BOWS))
                player->learnSpell(SPELL_BOWS);

            player->SetSkill(SKILL_BOWS, 0, player->GetMaxSkillValue(SKILL_BOWS), player->GetMaxSkillValue(SKILL_BOWS));
        }

        if ((classId == CLASS_WARRIOR && specialization == SPECIALIZATION_1) || classId == CLASS_ROGUE)
        {
            if (!player->HasSkill(SKILL_DUAL_WIELD))
                player->learnSpell(SPELL_DUAL_WIELD);
        }

        if ((classId == CLASS_PALADIN && specialization == SPECIALIZATION_1) ||
            classId == CLASS_SHAMAN)
        {
            if (!player->HasSkill(SKILL_MACES))
                player->learnSpell(SPELL_ONE_HANDED_MACES);

            player->SetSkill(SKILL_MACES, 0, player->GetMaxSkillValue(SKILL_MACES), player->GetMaxSkillValue(SKILL_MACES));
        }

        if (classId == CLASS_HUNTER || classId == CLASS_PRIEST || classId == CLASS_MAGE || classId == CLASS_WARLOCK || (classId == CLASS_DRUID && (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3)))
        {
            if (!player->HasSkill(SKILL_STAVES))
                player->learnSpell(SPELL_STAVES);

            player->SetSkill(SKILL_STAVES, 0, player->GetMaxSkillValue(SKILL_STAVES), player->GetMaxSkillValue(SKILL_STAVES));
        }

        if (classId == CLASS_DRUID && specialization == SPECIALIZATION_2)
        {
            if (!player->HasSkill(SKILL_POLEARMS))
                player->learnSpell(SPELL_POLEARMS);

            player->SetSkill(SKILL_POLEARMS, 0, player->GetMaxSkillValue(SKILL_POLEARMS), player->GetMaxSkillValue(SKILL_POLEARMS));
        }

        if (classId == CLASS_PRIEST || classId == CLASS_MAGE || classId == CLASS_WARLOCK)
        {
            if (!player->HasSkill(SKILL_WANDS))
                player->learnSpell(SPELL_WANDS);

            player->SetSkill(SKILL_WANDS, 0, player->GetMaxSkillValue(SKILL_WANDS), player->GetMaxSkillValue(SKILL_WANDS));
        }

        if (classId == CLASS_ROGUE)
        {
            if (!player->HasSkill(SKILL_DAGGERS))
                player->learnSpell(SPELL_DAGGERS);

            player->SetSkill(SKILL_DAGGERS, 0, player->GetMaxSkillValue(SKILL_DAGGERS), player->GetMaxSkillValue(SKILL_DAGGERS));

            if (!player->HasSkill(SKILL_THROWN))
                player->learnSpell(SPELL_THROWN);

            player->SetSkill(SKILL_THROWN, 0, player->GetMaxSkillValue(SKILL_THROWN), player->GetMaxSkillValue(SKILL_THROWN));
        }
    }

    void EquipNewItems(Player* player, uint8 specialization)
    {
        std::vector<std::vector<int>> itemList = GetItemList(player->getClass(), specialization);

        if (itemList.empty())
            return;

        for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_TABARD; slot++)
        {
            player->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);

            uint32 itemId = itemList[slot][ITEM_ENTRY];
            uint32 randomProperty = itemList[slot][ITEM_RANDOM_PROPERTY];

            if (itemId > 0)
            {
                if (sObjectMgr->GetItemTemplate(itemId))
                {
                    if (Item* item = Item::CreateItem(itemId, 1, player, false, randomProperty > 0 ? randomProperty : 0))
                    {
                        if (randomProperty < 0)
                            item->SetUInt32Value(ITEM_FIELD_PROPERTY_SEED, std::abs((int)randomProperty));

                        player->EquipItem(slot, item, true);

                        if (player->getClass() == CLASS_SHAMAN && specialization == SPECIALIZATION_2 && slot == SLOT_MAIN_HAND)
                        {
                            ItemPosCountVec dest;
                            InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, 1);
                            if (msg == EQUIP_ERR_OK)
                            {
                                Item* item = player->StoreNewItem(dest, itemId, true, randomProperty > 0 ? randomProperty : 0);

                                if (randomProperty < 0)
                                    item->SetUInt32Value(ITEM_FIELD_PROPERTY_SEED, std::abs((int)randomProperty));

                                player->SendNewItem(item, 1, true, false);
                            }
                        }
                    }
                }
            }
        }
    }

    void GiveCopper(Player* player)
    {
        uint32 IncludedCopper = sConfigMgr->GetOption<uint32>("Appreciation.LevelBoost.IncludedCopper", 2500000);

        if (IncludedCopper <= 0)
            return;

        player->ModifyMoney(IncludedCopper);
    }

    void UnlockContinent(Player* player, uint8 continent)
    {
        switch (continent)
        {
        case CONTINENT_EASTERN_KINGDOMS:
            player->GetSession()->SendDiscoverNewTaxiNode(205); // Hatchet Hills, Ghostlands
            player->GetSession()->SendDiscoverNewTaxiNode(383); // Thondoril River, Western Plaguelands

            if (player->GetTeamId() == TEAM_ALLIANCE)
            {
                player->GetSession()->SendDiscoverNewTaxiNode(2); // Stormwind City
                player->GetSession()->SendDiscoverNewTaxiNode(4); // Sentinel Hill, Westfall
                player->GetSession()->SendDiscoverNewTaxiNode(5); // Lakeshire, Redridge Mountains
                player->GetSession()->SendDiscoverNewTaxiNode(6); // Ironforge, Dun Morogh
                player->GetSession()->SendDiscoverNewTaxiNode(7); // Menethil Harbor, Wetlands
                player->GetSession()->SendDiscoverNewTaxiNode(8); // Thelsamar, Loch Modan
                player->GetSession()->SendDiscoverNewTaxiNode(12); // Darkshire, Duskwood
                player->GetSession()->SendDiscoverNewTaxiNode(14); // Southshore, Hillsbrad Foothills
                player->GetSession()->SendDiscoverNewTaxiNode(16); // Refuge Pointe, Arathi Highlands
                player->GetSession()->SendDiscoverNewTaxiNode(19); // Booty Bay, Stranglethorn Vale
                player->GetSession()->SendDiscoverNewTaxiNode(43); // Aerie Peak, The Hinterlands
                player->GetSession()->SendDiscoverNewTaxiNode(45); // Nethergarde Keep, Blasted Lands
                player->GetSession()->SendDiscoverNewTaxiNode(66); // Chillwind Camp, Western Plaguelands
                player->GetSession()->SendDiscoverNewTaxiNode(67); // Light's Hope Chapel, Eastern Plaguelands
                player->GetSession()->SendDiscoverNewTaxiNode(71); // Morgan's Vigil, Burning Steppes
                player->GetSession()->SendDiscoverNewTaxiNode(74); // Thorium Point, Searing Gorge
                player->GetSession()->SendDiscoverNewTaxiNode(195); // Rebel Camp, Stranglethorn Vale
            }
            else
            {
                player->GetSession()->SendDiscoverNewTaxiNode(10); // The Sepulcher, Silverpine Forest
                player->GetSession()->SendDiscoverNewTaxiNode(11); // Undercity
                player->GetSession()->SendDiscoverNewTaxiNode(13); // Tarren Mill, Hillsbrad Foothills
                player->GetSession()->SendDiscoverNewTaxiNode(17); // Hammerfall, Arathi Highlands
                player->GetSession()->SendDiscoverNewTaxiNode(18); // Booty Bay, Stranglethorn Vale
                player->GetSession()->SendDiscoverNewTaxiNode(20); // Grom'gol, Stranglethorn Vale
                player->GetSession()->SendDiscoverNewTaxiNode(21); // Kargath, Badlands
                player->GetSession()->SendDiscoverNewTaxiNode(56); // Stonard, Swamp of Sorrows
                player->GetSession()->SendDiscoverNewTaxiNode(68); // Light's Hope Chapel, Eastern Plaguelands
                player->GetSession()->SendDiscoverNewTaxiNode(70); // Flame Crest, Burning Steppes
                player->GetSession()->SendDiscoverNewTaxiNode(75); // Thorium Point, Searing Gorge
                player->GetSession()->SendDiscoverNewTaxiNode(76); // Revantusk Village, The Hinterlands
                player->GetSession()->SendDiscoverNewTaxiNode(82); // Silvermoon City
                player->GetSession()->SendDiscoverNewTaxiNode(83); // Tranquillien, Ghostlands
                player->GetSession()->SendDiscoverNewTaxiNode(384); // The Bulwark, Tirisfal Glades
            }
            break;
        case CONTINENT_KALIMDOR:
            player->GetSession()->SendDiscoverNewTaxiNode(79); // Marshal's Refuge, Un'Goro Crater
            player->GetSession()->SendDiscoverNewTaxiNode(80); // Ratchet, The Barrens
            player->GetSession()->SendDiscoverNewTaxiNode(166); // Emerald Sanctuary, Felwood
            player->GetSession()->SendDiscoverNewTaxiNode(179); // Mudsprocket, Dustwallow Marsh

            if (player->GetTeamId() == TEAM_ALLIANCE)
            {
                player->GetSession()->SendDiscoverNewTaxiNode(26); // Auberdine, Darkshore
                player->GetSession()->SendDiscoverNewTaxiNode(27); // Rut'theran Village, Teldrassil
                player->GetSession()->SendDiscoverNewTaxiNode(28); // Astranaar, Ashenvale
                player->GetSession()->SendDiscoverNewTaxiNode(31); // Thalanaar, Feralas
                player->GetSession()->SendDiscoverNewTaxiNode(32); // Theramore Isle, Dustwallow Marsh
                player->GetSession()->SendDiscoverNewTaxiNode(33); // Stonetalon Peak, Stonetalon Mountains
                player->GetSession()->SendDiscoverNewTaxiNode(37); // Nijel's Point, Desolace
                player->GetSession()->SendDiscoverNewTaxiNode(38); // Shadowprey Village, Desolace
                player->GetSession()->SendDiscoverNewTaxiNode(39); // Gadgetzan, Tanaris
                player->GetSession()->SendDiscoverNewTaxiNode(41); // Feathermoon Stronghold, Feralas
                player->GetSession()->SendDiscoverNewTaxiNode(49); // Moonglade
                player->GetSession()->SendDiscoverNewTaxiNode(52); // Everlook, Winterspring
                player->GetSession()->SendDiscoverNewTaxiNode(62); // Nighthaven, Moonglade
                player->GetSession()->SendDiscoverNewTaxiNode(64); // Talrendis Point, Azshara
                player->GetSession()->SendDiscoverNewTaxiNode(65); // Talonbranch Glade, Felwood
                player->GetSession()->SendDiscoverNewTaxiNode(73); // Cenarion Hold, Silithus
                player->GetSession()->SendDiscoverNewTaxiNode(93); // Blood Watch, Bloodmyst Isle
                player->GetSession()->SendDiscoverNewTaxiNode(94); // The Exodar
                player->GetSession()->SendDiscoverNewTaxiNode(167); // Forest Song, Ashenvale
            }
            else
            {
                player->GetSession()->SendDiscoverNewTaxiNode(22); // Thunder Bluff
                player->GetSession()->SendDiscoverNewTaxiNode(23); // Orgrimmar
                player->GetSession()->SendDiscoverNewTaxiNode(25); // The Crossroads, The Barrens
                player->GetSession()->SendDiscoverNewTaxiNode(29); // Sun Rock Retreat, Stonetalon Mountains
                player->GetSession()->SendDiscoverNewTaxiNode(30); // Freewind Post, Thousand Needles
                player->GetSession()->SendDiscoverNewTaxiNode(38); // Shadowprey Village, Desolace
                player->GetSession()->SendDiscoverNewTaxiNode(40); // Gadgetzan, Tanaris
                player->GetSession()->SendDiscoverNewTaxiNode(42); // Camp Mojache, Feralas
                player->GetSession()->SendDiscoverNewTaxiNode(44); // Valormok, Azshara
                player->GetSession()->SendDiscoverNewTaxiNode(48); // Bloodvenom Post, Felwood
                player->GetSession()->SendDiscoverNewTaxiNode(53); // Everlook, Winterspring
                player->GetSession()->SendDiscoverNewTaxiNode(55); // Brackenwall Village, Dustwallow Marsh
                player->GetSession()->SendDiscoverNewTaxiNode(58); // Zoram'gar Outpost, Ashenvale
                player->GetSession()->SendDiscoverNewTaxiNode(61); // Splintertree Post, Ashenvale
                player->GetSession()->SendDiscoverNewTaxiNode(63); // Nighthaven, Moonglade
                player->GetSession()->SendDiscoverNewTaxiNode(69); // Moonglade
                player->GetSession()->SendDiscoverNewTaxiNode(72); // Cenarion Hold, Silithus
                player->GetSession()->SendDiscoverNewTaxiNode(77); // Camp Taurajo, The Barrens
            }
            break;
        case CONTINENT_OUTLAND:
            player->GetSession()->SendDiscoverNewTaxiNode(122); // Area 52, Netherstorm
            player->GetSession()->SendDiscoverNewTaxiNode(128); // Shattrath City
            player->GetSession()->SendDiscoverNewTaxiNode(139); // The Stormspire, Netherstorm
            player->GetSession()->SendDiscoverNewTaxiNode(140); // Altar of Sha'tar, Shadowmoon Valley
            player->GetSession()->SendDiscoverNewTaxiNode(150); // Cosmowrench, Netherstorm
            player->GetSession()->SendDiscoverNewTaxiNode(159); // Sanctum of the Stars, Shadowmoon Valley
            player->GetSession()->SendDiscoverNewTaxiNode(160); // Evergrove, Blade's Edge Mountains
            player->GetSession()->SendDiscoverNewTaxiNode(213); // Sun's Reach Harbor, Isle of Quel'Danas

            if (player->GetTeamId() == TEAM_ALLIANCE)
            {
                player->GetSession()->SendDiscoverNewTaxiNode(100); // Honor Hold, Hellfire Peninsula
                player->GetSession()->SendDiscoverNewTaxiNode(101); // Temple of Telhamat, Hellfire Peninsula
                player->GetSession()->SendDiscoverNewTaxiNode(117); // Telredor, Zangarmarsh
                player->GetSession()->SendDiscoverNewTaxiNode(119); // Telaar, Nagrand
                player->GetSession()->SendDiscoverNewTaxiNode(124); // Wildhammer Stronghold, Shadowmoon Valley
                player->GetSession()->SendDiscoverNewTaxiNode(125); // Sylvanaar, Blade's Edge Mountains
                player->GetSession()->SendDiscoverNewTaxiNode(129); // The Dark Portal, Hellfire Peninsula
                player->GetSession()->SendDiscoverNewTaxiNode(149); // Shatter Point, Hellfire Peninsula
                player->GetSession()->SendDiscoverNewTaxiNode(156); // Toshley's Station, Blade's Edge Mountains
                player->GetSession()->SendDiscoverNewTaxiNode(164); // Orebor Harborage, Zangarmarsh
            }
            else
            {
                player->GetSession()->SendDiscoverNewTaxiNode(99); // Thrallmar, Hellfire Peninsula
                player->GetSession()->SendDiscoverNewTaxiNode(102); // Falcon Watch, Hellfire Peninsula
                player->GetSession()->SendDiscoverNewTaxiNode(118); // Zabra'jin, Zangarmarsh
                player->GetSession()->SendDiscoverNewTaxiNode(120); // Garadar, Nagrand
                player->GetSession()->SendDiscoverNewTaxiNode(123); // Shadowmoon Village, Shadowmoon Valley
                player->GetSession()->SendDiscoverNewTaxiNode(126); // Thunderlord Stronghold, Blade's Edge Mountains
                player->GetSession()->SendDiscoverNewTaxiNode(127); // Stonebreaker Hold, Terokkar Forest
                player->GetSession()->SendDiscoverNewTaxiNode(130); // The Dark Portal, Hellfire Peninsula
                player->GetSession()->SendDiscoverNewTaxiNode(141); // Spinebreaker Ridge, Hellfire Peninsula
                player->GetSession()->SendDiscoverNewTaxiNode(142); // Reaver's Fall, Hellfire Peninsula
                player->GetSession()->SendDiscoverNewTaxiNode(151); // Swamprat Post, Zangarmarsh
                player->GetSession()->SendDiscoverNewTaxiNode(163); // Mok'Nathal Village, Blade's Edge Mountains
            }
            break;
        case CONTINENT_NORTHREND:
            player->GetSession()->SendDiscoverNewTaxiNode(226); // Transitus Shield, Coldarra
            player->GetSession()->SendDiscoverNewTaxiNode(252); // Wyrmrest Temple, Dragonblight
            player->GetSession()->SendDiscoverNewTaxiNode(289); // Amber Ledge, Borean Tundra
            player->GetSession()->SendDiscoverNewTaxiNode(294); // Moa'ki, Dragonblight
            player->GetSession()->SendDiscoverNewTaxiNode(295); // Kamagua, Howling Fjord
            player->GetSession()->SendDiscoverNewTaxiNode(296); // Unu'pe, Borean Tundra
            player->GetSession()->SendDiscoverNewTaxiNode(304); // The Argent Stand, Zul'Drak
            player->GetSession()->SendDiscoverNewTaxiNode(305); // Ebon Watch, Zul'Drak
            player->GetSession()->SendDiscoverNewTaxiNode(306); // Light's Breach, Zul'Drak
            player->GetSession()->SendDiscoverNewTaxiNode(307); // Zim'Torga, Zul'Drak
            player->GetSession()->SendDiscoverNewTaxiNode(308); // River's Heart, Sholazar Basin
            player->GetSession()->SendDiscoverNewTaxiNode(309); // Nesingwary Base Camp, Sholazar Basin
            player->GetSession()->SendDiscoverNewTaxiNode(310); // Dalaran
            player->GetSession()->SendDiscoverNewTaxiNode(320); // K3, The Storm Peaks
            player->GetSession()->SendDiscoverNewTaxiNode(321); // The Frost Hold, The Storm Peaks
            player->GetSession()->SendDiscoverNewTaxiNode(325); // Death's Rise, Icecrown
            player->GetSession()->SendDiscoverNewTaxiNode(326); // Ulduar, The Storm Peaks
            player->GetSession()->SendDiscoverNewTaxiNode(327); // Bouldercrag's Refuge, The Storm Peaks
            player->GetSession()->SendDiscoverNewTaxiNode(331); // Dubra'Jin, Zul'Drak
            player->GetSession()->SendDiscoverNewTaxiNode(334); // The Argent Vanguard, Icecrown
            player->GetSession()->SendDiscoverNewTaxiNode(340); // Argent Tournament Grounds, Icecrown

            if (player->GetTeamId() == TEAM_ALLIANCE)
            {
                player->GetSession()->SendDiscoverNewTaxiNode(183); // Valgarde Port, Howling Fjord
                player->GetSession()->SendDiscoverNewTaxiNode(184); // Fort Wildervar, Howling Fjord
                player->GetSession()->SendDiscoverNewTaxiNode(185); // Westguard Keep, Howling Fjord
                player->GetSession()->SendDiscoverNewTaxiNode(244); // Wintergarde Keep, Howling Fjord
                player->GetSession()->SendDiscoverNewTaxiNode(245); // Valiance Keep, Borean Tundra
                player->GetSession()->SendDiscoverNewTaxiNode(246); // Fizzcrank Airstrip, Borean Tundra
                player->GetSession()->SendDiscoverNewTaxiNode(247); // Stars' Rest, Dragonblight
                player->GetSession()->SendDiscoverNewTaxiNode(251); // Fordragon Hold, Dragonblight
                player->GetSession()->SendDiscoverNewTaxiNode(253); // Amberpine Lodge, Grizzly Hills
                player->GetSession()->SendDiscoverNewTaxiNode(255); // Westfall Brigade, Grizzly Hills
                player->GetSession()->SendDiscoverNewTaxiNode(321); // Frosthold, The Storm Peaks
                player->GetSession()->SendDiscoverNewTaxiNode(336); // Windrunner's Overlook, Crystalsong Forest
            }
            else
            {
                player->GetSession()->SendDiscoverNewTaxiNode(190); // New Agamand, Howling Fjord
                player->GetSession()->SendDiscoverNewTaxiNode(191); // Vengeance Landing, Howling Fjord
                player->GetSession()->SendDiscoverNewTaxiNode(192); // Camp Winterhoof, Howling Fjord
                player->GetSession()->SendDiscoverNewTaxiNode(248); // Apothecary Camp, Howling Fjord
                player->GetSession()->SendDiscoverNewTaxiNode(249); // Camp Oneqwah, Grizzly Hills
                player->GetSession()->SendDiscoverNewTaxiNode(250); // Conquest Hold, Grizzly Hills
                player->GetSession()->SendDiscoverNewTaxiNode(254); // Venomspite, Dragonblight
                player->GetSession()->SendDiscoverNewTaxiNode(256); // Agmar's Hammer, Dragonblight
                player->GetSession()->SendDiscoverNewTaxiNode(257); // Warsong Hold, Borean Tundra
                player->GetSession()->SendDiscoverNewTaxiNode(258); // Taunka'le Village, Borean Tundra
                player->GetSession()->SendDiscoverNewTaxiNode(259); // Bor'gorok Outpost, Borean Tundra
                player->GetSession()->SendDiscoverNewTaxiNode(260); // Kor'koron Vanguard, Dragonbligh
                player->GetSession()->SendDiscoverNewTaxiNode(323); // Grom'arsh Crash-Site, The Storm Peaks
                player->GetSession()->SendDiscoverNewTaxiNode(324); // Camp Tunka'lo, The Storm Peaks
                player->GetSession()->SendDiscoverNewTaxiNode(337); // Sunreaver's Command, Crystalsong Forest
            }
            break;
        }

        RemoveCertificate(player);
    }

    void RemoveCertificate(Player* player)
    {
        if (!sConfigMgr->GetOption<bool>("Appreciation.RequireCertificate.Enabled", true))
            return;

        player->DestroyItemCount(ITEM_CERTIFICATE, 1, true);
    }

    std::vector<std::vector<int>> GetItemList(uint32 classId, uint8 specialization)
    {
        uint32 TargetLevel = sConfigMgr->GetOption<uint32>("Appreciation.LevelBoost.TargetLevel", DEFAULT_LEVEL);

        if (TargetLevel != 60 && TargetLevel != 70 && TargetLevel != 80)
            TargetLevel = DEFAULT_LEVEL;

        std::vector<std::vector<int>> itemList;
        std::vector<int> item;

        switch (classId)
        {
        case CLASS_WARRIOR:
            // Head
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 14979, 1232 };
                else // Protection
                    item = { 14979, 1231 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 25018, -41 };
                else // Protection
                    item = { 25018, -16 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 36327, -7 };
                else // Protection
                    item = { 36327, -45 };
            }
            itemList.push_back(item);

            // Neck
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 12048, 1208 };
                else // Protection
                    item = { 12048, 1207 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 25070, -41 };
                else // Protection
                    item = { 25070, -16 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 36435, -7 };
                else // Protection
                    item = { 36435, -45 };
            }
            itemList.push_back(item);

            // Shoulders
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 14981, 2151 };
                else // Protection
                    item = { 14981, 338 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 25028, -41 };
                else // Protection
                    item = { 25028, -16 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 36329, -7 };
                else // Protection
                    item = { 36329, -45 };
            }
            itemList.push_back(item);

            // Body
            item = { 0, 0 };
            itemList.push_back(item);

            // Chest
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 14975, 1232 };
                else // Protection
                    item = { 14975, 346 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 25008, -41 };
                else // Protection
                    item = { 25008, -16 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 36325, -7 };
                else // Protection
                    item = { 36325, -45 };
            }
            itemList.push_back(item);

            // Waist
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 14977, 2151 };
                else // Protection
                    item = { 14977, 1213 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 25014, -41 };
                else // Protection
                    item = { 25014, -16 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 36323, -7 };
                else // Protection
                    item = { 36323, -45 };
            }
            itemList.push_back(item);

            // Legs
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 14980, 2158 };
                else // Protection
                    item = { 14980, 1228 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 25019, -41 };
                else // Protection
                    item = { 25019, -16 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 36328, -7 };
                else // Protection
                    item = { 36328, -45 };
            }
            itemList.push_back(item);

            // Feet
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 14978, 2154 };
                else // Protection
                    item = { 14978, 338 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 25015, -41 };
                else // Protection
                    item = { 25015, -16 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 36324, -7 };
                else // Protection
                    item = { 36324, -45 };
            }
            itemList.push_back(item);

            // Wrists
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 14983, 1205 };
                else // Protection
                    item = { 14983, 287 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 25021, -41 };
                else // Protection
                    item = { 25021, -16 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 36330, -7 };
                else // Protection
                    item = { 36330, -45 };
            }
            itemList.push_back(item);

            // Hands
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 14976, 1217 };
                else // Protection
                    item = { 14976, 1216 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 25017, -41 };
                else // Protection
                    item = { 25017, -16 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 36326, -7 };
                else // Protection
                    item = { 36326, -45 };
            }
            itemList.push_back(item);

            // Finger 1
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 12017, 1208 };
                else // Protection
                    item = { 12017, 333 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 25056, -41 };
                else // Protection
                    item = { 25056, -16 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 36421, -7 };
                else // Protection
                    item = { 36421, -45 };
            }
            itemList.push_back(item);

            // Finger 2
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 11980, 1206 };
                else // Protection
                    item = { 11980, 333 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 25056, -41 };
                else // Protection
                    item = { 25056, -16 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 36420, -7 };
                else // Protection
                    item = { 36420, -45 };
            }
            itemList.push_back(item);

            // Trinket 1
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 17774, 0 };
                else // Protection
                    item = { 1490, 0 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 29776, 0 };
                else // Protection
                    item = { 25787, 0 };
            }
            else
            {
                item = { 38080, 0 };
            }
            itemList.push_back(item);

            // Trinket 2
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 5079, 0 };
                else // Protection
                    item = { 4130, 0 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 25937, 0 };
                else // Protection
                    item = { 25996, 0 };
            }
            else
            {
                item = { 38081, 0 };
            }
            itemList.push_back(item);

            // Back
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 15437, 1205 };
                else // Protection
                    item = { 15437, 287 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 25042, -41 };
                else // Protection
                    item = { 25042, -16 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 36407, -7 };
                else // Protection
                    item = { 36407, -45 };
            }
            itemList.push_back(item);

            // Main hand
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1) // Arms
                    item = { 15221, 1199 };
                else if (specialization == SPECIALIZATION_2) // Fury
                    item = { 15256, 1226 };
                else // Protection
                    item = { 15221, 1199 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1) // Arms
                    item = { 25154, -41 };
                else if (specialization == SPECIALIZATION_2) // Fury
                    item = { 25168, -41 };
                else // Protection
                    item = { 25154, -41 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1) // Arms
                    item = { 38146, 0 };
                else if (specialization == SPECIALIZATION_2) // Fury
                    item = { 38181, 0 };
                else // Protection
                    item = { 38146, 0 };
            }
            itemList.push_back(item);

            // Off hand
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1) // Arms
                    item = { 15219, 1197 };
                else if (specialization == SPECIALIZATION_2) // Fury
                    item = { 0, 0 };
                else // Protection
                    item = { 14982, 1197 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1) // Arms
                    item = { 25153, -41 };
                else if (specialization == SPECIALIZATION_2) // Fury
                    item = { 0, 0 };
                else // Protection
                    item = { 25084, -41 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1) // Arms
                    item = { 38198, 0 };
                else if (specialization == SPECIALIZATION_2) // Fury
                    item = { 0, 0 };
                else // Protection
                    item = { 36449, -45 };
            }
            itemList.push_back(item);

            // Ranged
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 15289, 683 };
                else // Protection
                    item = { 15289, 185 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_2) // Arms, Fury
                    item = { 25252, -41 };
                else // Protection
                    item = { 25252, -16 };
            }
            else
            {
                item = { 38157, 0 };
            }
            itemList.push_back(item);
            break;
        case CLASS_PALADIN:
            // Head
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 14979, 891 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 14979, 1231 };
                else // Retribution
                    item = { 14979, 1232 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 25018, -9 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 25018, -16 };
                else // Retribution
                    item = { 25018, -41 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 36327, -37 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 36327, -45 };
                else // Retribution
                    item = { 36327, -43 };
            }
            itemList.push_back(item);

            // Neck
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 12048, 784 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 12048, 1207 };
                else // Retribution
                    item = { 12048, 1208 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 25070, -44 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 25070, -16 };
                else // Retribution
                    item = { 25070, -41 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 36435, -37 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 36435, -45 };
                else // Retribution
                    item = { 36435, -43 };
            }
            itemList.push_back(item);

            // Shoulders
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 14981, 876 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 14981, 338 };
                else // Retribution
                    item = { 14981, 2151 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 25028, -44 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 25028, -16 };
                else // Retribution
                    item = { 25028, -41 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 36329, -37 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 36329, -45 };
                else // Retribution
                    item = { 36329, -43 };
            }
            itemList.push_back(item);

            // Body
            item = { 0, 0 };
            itemList.push_back(item);

            // Chest
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 14975, 891 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 14975, 346 };
                else // Retribution
                    item = { 14975, 1232 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 25008, -44 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 25008, -16 };
                else // Retribution
                    item = { 25008, -41 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 36325, -37 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 36325, -45 };
                else // Retribution
                    item = { 36325, -43 };
            }
            itemList.push_back(item);

            // Waist
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 14977, 873 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 14977, 1213 };
                else // Retribution
                    item = { 14977, 2151 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 25014, -44 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 25014, -16 };
                else // Retribution
                    item = { 25014, -41 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 36323, -37 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 36323, -45 };
                else // Retribution
                    item = { 36323, -43 };
            }
            itemList.push_back(item);

            // Legs
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 14980, 888 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 14980, 1228 };
                else // Retribution
                    item = { 14980, 2158 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 25019, -44 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 25019, -16 };
                else // Retribution
                    item = { 25019, -41 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 36328, -37 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 36328, -45 };
                else // Retribution
                    item = { 36328, -43 };
            }
            itemList.push_back(item);

            // Feet
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 14978, 876 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 14978, 338 };
                else // Retribution
                    item = { 14978, 2154 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 25015, -44 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 25015, -16 };
                else // Retribution
                    item = { 25015, -41 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 36324, -37 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 36324, -45 };
                else // Retribution
                    item = { 36324, -43 };
            }
            itemList.push_back(item);

            // Wrists
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 14983, 864 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 14983, 287 };
                else // Retribution
                    item = { 14983, 1205 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 25021, -44 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 25021, -16 };
                else // Retribution
                    item = { 25021, -41 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 36330, -37 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 36330, -45 };
                else // Retribution
                    item = { 36330, -43 };
            }
            itemList.push_back(item);

            // Hands
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 14976, 876 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 14976, 1216 };
                else // Retribution
                    item = { 14976, 1217 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 25017, -44 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 25017, -16 };
                else // Retribution
                    item = { 25017, -41 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 36326, -37 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 36326, -45 };
                else // Retribution
                    item = { 36326, -43 };
            }
            itemList.push_back(item);

            // Finger 1
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 12017, 867 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 12017, 333 };
                else // Retribution
                    item = { 12017, 1208 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 25056, -44 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 25056, -16 };
                else // Retribution
                    item = { 25056, -41 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 36421, -37 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 36421, -45 };
                else // Retribution
                    item = { 36421, -43 };
            }
            itemList.push_back(item);

            // Finger 2
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 11980, 868 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 11980, 333 };
                else // Retribution
                    item = { 11980, 1206 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 25056, -44 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 25056, -16 };
                else // Retribution
                    item = { 25056, -41 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 36420, -37 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 36420, -45 };
                else // Retribution
                    item = { 36420, -43 };
            }
            itemList.push_back(item);

            // Trinket 1
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 10659, 0 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 1490, 0 };
                else // Retribution
                    item = { 17774, 0 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 25634, 0 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 25787, 0 };
                else // Retribution
                    item = { 29776, 0 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 38073, 0 };
                else // Protection, Retribution
                    item = { 38080, 0 };
            }
            itemList.push_back(item);

            // Trinket 2
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 17774, 0 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 4130, 0 };
                else // Retribution
                    item = { 5079, 0 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 30293, 0 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 25996, 0 };
                else // Retribution
                    item = { 25937, 0 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 35935, 0 };
                else // Protection, Retribution
                    item = { 38081, 0 };
            }
            itemList.push_back(item);

            // Back
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 15437, 864 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 15437, 287 };
                else // Retribution
                    item = { 15437, 1205 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 25042, -44 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 25042, -16 };
                else // Retribution
                    item = { 25042, -41 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 36407, -37 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 36407, -45 };
                else // Retribution
                    item = { 36407, -43 };
            }
            itemList.push_back(item);

            // Main hand
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 15229, 2040 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 15221, 1199 };
                else // Retribution
                    item = { 15256, 1226 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 25322, -44 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 25154, -41 };
                else // Retribution
                    item = { 25168, -41 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 36490, -44 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 36518, -45 };
                else // Retribution
                    item = { 36532, -41 };
            }
            itemList.push_back(item);

            // Off hand
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 14982, 2043 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 14982, 1197 };
                else // Retribution
                    item = { 0, 0 };
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 25084, -44 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 25084, -41 };
                else // Retribution
                    item = { 0, 0 };
            }
            else
            {
                if (specialization == SPECIALIZATION_1) // Holy
                    item = { 36449, -36 };
                else if (specialization == SPECIALIZATION_2) // Protection
                    item = { 36449, -45 };
                else // Retribution
                    item = { 0, 0 };
            }
            itemList.push_back(item);

            // Ranged
            item = { 0, 0 };
            itemList.push_back(item);
            break;
        case CLASS_HUNTER:
            // Head
            if (TargetLevel == 60)
            {
                item = { 15684, 468 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24906, -5 };
            }
            else
            {
                item = { 36215, -40 };
            }
            itemList.push_back(item);

            // Neck
            if (TargetLevel == 60)
            {
                item = { 12048, 612 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25070, -5 };
            }
            else
            {
                item = { 36435, -40 };
            }
            itemList.push_back(item);

            // Shoulders
            if (TargetLevel == 60)
            {
                item = { 15686, 621 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24908, -5 };
            }
            else
            {
                item = { 36217, -40 };
            }
            itemList.push_back(item);

            // Body
            item = { 0, 0 };
            itemList.push_back(item);

            // Chest
            if (TargetLevel == 60)
            {
                item = { 15680, 636 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24904, -5 };
            }
            else
            {
                item = { 36213, -40 };
            }
            itemList.push_back(item);

            // Waist
            if (TargetLevel == 60)
            {
                item = { 15683, 618 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24902, -5 };
            }
            else
            {
                item = { 36211, -40 };
            }
            itemList.push_back(item);

            // Legs
            if (TargetLevel == 60)
            {
                item = { 15685, 633 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24907, -5 };
            }
            else
            {
                item = { 36216, -40 };
            }
            itemList.push_back(item);

            // Feet
            if (TargetLevel == 60)
            {
                item = { 15678, 621 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24903, -5 };
            }
            else
            {
                item = { 36212, -40 };
            }
            itemList.push_back(item);

            // Wrists
            if (TargetLevel == 60)
            {
                item = { 15679, 609 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24909, -5 };
            }
            else
            {
                item = { 36218, -40 };
            }
            itemList.push_back(item);

            // Hands
            if (TargetLevel == 60)
            {
                item = { 15682, 621 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24905, -5 };
            }
            else
            {
                item = { 36214, -40 };
            }
            itemList.push_back(item);

            // Finger 1
            if (TargetLevel == 60)
            {
                item = { 12017, 612 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25056, -5 };
            }
            else
            {
                item = { 36421, -40 };
            }
            itemList.push_back(item);

            // Finger 2
            if (TargetLevel == 60)
            {
                item = { 12005, 609 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25055, -5 };
            }
            else
            {
                item = { 36420, -40 };
            }
            itemList.push_back(item);

            // Trinket 1
            if (TargetLevel == 60)
            {
                item = { 5079, 0 };
            }
            else if (TargetLevel == 70)
            {
                item = { 29776, 0 };
            }
            else
            {
                item = { 38080, 0 };
            }
            itemList.push_back(item);

            // Trinket 2
            if (TargetLevel == 60)
            {
                item = { 17774, 0 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25937, 0 };
            }
            else
            {
                item = { 38081, 0 };
            }
            itemList.push_back(item);

            // Back
            if (TargetLevel == 60)
            {
                item = { 10249, 609 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25042, -5 };
            }
            else
            {
                item = { 36407, -40 };
            }
            itemList.push_back(item);

            // Main hand
            if (TargetLevel == 60)
            {
                item = { 15278, 629 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25182, -5 };
            }
            else
            {
                item = { 36602, -40 };
            }
            itemList.push_back(item);

            // Off hand
            item = { 0, 0 };
            itemList.push_back(item);

            // Ranged
            if (TargetLevel == 60)
            {
                item = { 15289, 597 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25252, -40 };
            }
            else
            {
                item = { 36616, -40 };
            }
            itemList.push_back(item);
            break;
        case CLASS_ROGUE:
            // Head
            if (TargetLevel == 60)
            {
                item = { 15439, 636 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24794, -40 };
            }
            else
            {
                item = { 36103, -40 };
            }
            itemList.push_back(item);

            // Neck
            if (TargetLevel == 60)
            {
                item = { 12048, 612 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25070, -5 };
            }
            else
            {
                item = { 36435, -40 };
            }
            itemList.push_back(item);

            // Shoulders
            if (TargetLevel == 60)
            {
                item = { 15441, 621 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24796, -40 };
            }
            else
            {
                item = { 36105, -40 };
            }
            itemList.push_back(item);

            // Body
            item = { 0, 0 };
            itemList.push_back(item);

            // Chest
            if (TargetLevel == 60)
            {
                item = { 15442, 636 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24792, -40 };
            }
            else
            {
                item = { 36101, -40 };
            }
            itemList.push_back(item);

            // Waist
            if (TargetLevel == 60)
            {
                item = { 15434, 621 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24790, -40 };
            }
            else
            {
                item = { 36099, -40 };
            }
            itemList.push_back(item);

            // Legs
            if (TargetLevel == 60)
            {
                item = { 15440, 633 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24795, -40 };
            }
            else
            {
                item = { 36104, -40 };
            }
            itemList.push_back(item);

            // Feet
            if (TargetLevel == 60)
            {
                item = { 15435, 621 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24791, -40 };
            }
            else
            {
                item = { 36100, -40 };
            }
            itemList.push_back(item);

            // Wrists
            if (TargetLevel == 60)
            {
                item = { 15436, 609 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24797, -40 };
            }
            else
            {
                item = { 36106, -40 };
            }
            itemList.push_back(item);

            // Hands
            if (TargetLevel == 60)
            {
                item = { 15438, 621 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24793, -40 };
            }
            else
            {
                item = { 36102, -40 };
            }
            itemList.push_back(item);

            // Finger 1
            if (TargetLevel == 60)
            {
                item = { 12017, 612 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25056, -40 };
            }
            else
            {
                item = { 36421, -40 };
            }
            itemList.push_back(item);

            // Finger 2
            if (TargetLevel == 60)
            {
                item = { 11992, 611 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25055, -40 };
            }
            else
            {
                item = { 36420, -40 };
            }
            itemList.push_back(item);

            // Trinket 1
            if (TargetLevel == 60)
            {
                item = { 17774, 0 };
            }
            else if (TargetLevel == 70)
            {
                item = { 29776, 0 };
            }
            else
            {
                item = { 38080, 0 };
            }
            itemList.push_back(item);

            // Trinket 2
            if (TargetLevel == 60)
            {
                item = { 5079, 0 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25937, 0 };
            }
            else
            {
                item = { 38081, 0 };
            }
            itemList.push_back(item);

            // Back
            if (TargetLevel == 60)
            {
                item = { 10249, 609 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25042, -40 };
            }
            else
            {
                item = { 36407, -40 };
            }
            itemList.push_back(item);

            // Main hand
            if (TargetLevel == 60)
            {
                item = { 15247, 603 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25112, -40 };
            }
            else
            {
                item = { 38151, 0 };
            }
            itemList.push_back(item);

            // Off hand
            if (TargetLevel == 60)
            {
                item = { 15246, 603 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25111, -40 };
            }
            else
            {
                item = { 38155, 0 };
            }
            itemList.push_back(item);

            // Ranged
            if (TargetLevel == 60)
            {
                item = { 29203, 0 };
            }
            else if (TargetLevel == 70)
            {
                item = { 28543, -40 };
            }
            else
            {
                item = { 36616, -40 };
            }
            itemList.push_back(item);
            break;
        case CLASS_PRIEST:
        case CLASS_MAGE:
        case CLASS_WARLOCK:
            // Head
            if (TargetLevel == 60)
            {
                item = { 14332, 891 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24681, -37 };
            }
            else
            {
                item = { 35991, -37 };
            }
            itemList.push_back(item);

            // Neck
            if (TargetLevel == 60)
            {
                item = { 12027, 864 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25070, -37 };
            }
            else
            {
                item = { 36435, -37 };
            }
            itemList.push_back(item);

            // Shoulders
            if (TargetLevel == 60)
            {
                item = { 14335, 876 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24683, -37 };
            }
            else
            {
                item = { 35993, -37 };
            }
            itemList.push_back(item);

            // Body
            item = { 0, 0 };
            itemList.push_back(item);

            // Chest
            if (TargetLevel == 60)
            {
                item = { 14328, 891 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24679, -37 };
            }
            else
            {
                item = { 35989, -37 };
            }
            itemList.push_back(item);

            // Waist
            if (TargetLevel == 60)
            {
                item = { 14337, 876 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24677, -37 };
            }
            else
            {
                item = { 35987, -37 };
            }
            itemList.push_back(item);

            // Legs
            if (TargetLevel == 60)
            {
                item = { 14334, 888 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24682, -37 };
            }
            else
            {
                item = { 35992, -37 };
            }
            itemList.push_back(item);

            // Feet
            if (TargetLevel == 60)
            {
                item = { 14329, 876 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24678, -37 };
            }
            else
            {
                item = { 35988, -37 };
            }
            itemList.push_back(item);

            // Wrists
            if (TargetLevel == 60)
            {
                item = { 14330, 864 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24684, -37 };
            }
            else
            {
                item = { 35994, -37 };
            }
            itemList.push_back(item);

            // Hands
            if (TargetLevel == 60)
            {
                item = { 14333, 879 };
            }
            else if (TargetLevel == 70)
            {
                item = { 24680, -37 };
            }
            else
            {
                item = { 35990, -37 };
            }
            itemList.push_back(item);

            // Finger 1
            if (TargetLevel == 60)
            {
                item = { 11992, 864 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25056, -37 };
            }
            else
            {
                item = { 36421, -37 };
            }
            itemList.push_back(item);

            // Finger 2
            if (TargetLevel == 60)
            {
                item = { 12017, 867 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25055, -39 };
            }
            else
            {
                item = { 36420, -37 };
            }
            itemList.push_back(item);

            // Trinket 1
            if (TargetLevel == 60)
            {
                item = { 10659, 0 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25634, 0 };
            }
            else
            {
                item = { 35935, 0 };
            }
            itemList.push_back(item);

            // Trinket 2
            if (TargetLevel == 60)
            {
                item = { 17774, 0 };
            }
            else if (TargetLevel == 70)
            {
                item = { 30293, 0 };
            }
            else
            {
                item = { 37555, 0 };
            }
            itemList.push_back(item);

            // Back
            if (TargetLevel == 60)
            {
                item = { 10249, 864 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25042, -37 };
            }
            else
            {
                item = { 36407, -37 };
            }
            itemList.push_back(item);

            // Main hand
            if (TargetLevel == 60)
            {
                item = { 15278, 802 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25181, -39 };
            }
            else
            {
                item = { 36546, -39 };
            }
            itemList.push_back(item);

            // Off hand
            item = { 0, 0 };
            itemList.push_back(item);

            // Ranged
            if (TargetLevel == 60)
            {
                item = { 15283, 854 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25294, -39 };
            }
            else
            {
                item = { 36658, -39 };
            }
            itemList.push_back(item);
            break;
        case CLASS_DEATH_KNIGHT:
            // Head
            if (TargetLevel == 60)
            {
                item = { 14979, 1232 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25018, -41 };
            }
            else
            {
                item = { 36327, -7 };
            }
            itemList.push_back(item);

            // Neck
            if (TargetLevel == 60)
            {
                item = { 12048, 1208 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25070, -41 };
            }
            else
            {
                item = { 36435, -7 };
            }
            itemList.push_back(item);

            // Shoulders
            if (TargetLevel == 60)
            {
                item = { 14981, 2151 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25028, -41 };
            }
            else
            {
                item = { 36329, -7 };
            }
            itemList.push_back(item);

            // Body
            item = { 0, 0 };
            itemList.push_back(item);

            // Chest
            if (TargetLevel == 60)
            {
                item = { 14975, 1232 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25008, -41 };
            }
            else
            {
                item = { 36325, -7 };
            }
            itemList.push_back(item);

            // Waist
            if (TargetLevel == 60)
            {
                item = { 14977, 2151 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25014, -41 };
            }
            else
            {
                item = { 36323, -7 };
            }
            itemList.push_back(item);

            // Legs
            if (TargetLevel == 60)
            {
                item = { 14980, 2158 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25019, -41 };
            }
            else
            {
                item = { 36328, -7 };
            }
            itemList.push_back(item);

            // Feet
            if (TargetLevel == 60)
            {
                item = { 14978, 2154 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25015, -41 };
            }
            else
            {
                item = { 36324, -7 };
            }
            itemList.push_back(item);

            // Wrists
            if (TargetLevel == 60)
            {
                item = { 14983, 1205 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25021, -41 };
            }
            else
            {
                item = { 36330, -7 };
            }
            itemList.push_back(item);

            // Hands
            if (TargetLevel == 60)
            {
                item = { 14976, 1217 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25017, -41 };
            }
            else
            {
                item = { 36326, -7 };
            }
            itemList.push_back(item);

            // Finger 1
            if (TargetLevel == 60)
            {
                item = { 12017, 1208 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25056, -41 };
            }
            else
            {
                item = { 36421, -7 };
            }
            itemList.push_back(item);

            // Finger 2
            if (TargetLevel == 60)
            {
                item = { 11980, 1206 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25056, -41 };
            }
            else
            {
                item = { 36420, -7 };
            }
            itemList.push_back(item);

            // Trinket 1
            if (TargetLevel == 60)
            {
                item = { 17774, 0 };
            }
            else if (TargetLevel == 70)
            {
                item = { 29776, 0 };
            }
            else
            {
                item = { 38080, 0 };
            }
            itemList.push_back(item);

            // Trinket 2
            if (TargetLevel == 60)
            {
                item = { 5079, 0 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25937, 0 };
            }
            else
            {
                item = { 38081, 0 };
            }
            itemList.push_back(item);

            // Back
            if (TargetLevel == 60)
            {
                item = { 15437, 1205 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25042, -41 };
            }
            else
            {
                item = { 36407, -7 };
            }
            itemList.push_back(item);

            // Main hand
            if (TargetLevel == 60)
            {
                item = { 15258, 1232 };
            }
            else if (TargetLevel == 70)
            {
                item = { 25168, -41 };
            }
            else
            {
                item = { 36532, -41 };
            }
            itemList.push_back(item);

            // Off hand
            item = { 0, 0 };
            itemList.push_back(item);

            // Ranged
            item = { 0, 0 };
            itemList.push_back(item);
            break;
        case CLASS_SHAMAN:
            // Head
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 15684, 891 };
                }
                else // Enhancement
                {
                    item = { 15684, 636 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 24906, -39 };
                }
                else // Enhancement
                {
                    item = { 24906, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 36215, -37 };
                }
                else // Enhancement
                {
                    item = { 36215, -40 };
                }
            }
            itemList.push_back(item);

            // Neck
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 12027, 864 };
                }
                else // Enhancement
                {
                    item = { 12027, 287 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 25070, -39 };
                }
                else // Enhancement
                {
                    item = { 25070, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 36435, -37 };
                }
                else // Enhancement
                {
                    item = { 36435, -40 };
                }
            }
            itemList.push_back(item);

            // Shoulders
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 15686, 876 };
                }
                else // Enhancement
                {
                    item = { 15686, 621 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 24908, -39 };
                }
                else // Enhancement
                {
                    item = { 24908, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 36217, -37 };
                }
                else // Enhancement
                {
                    item = { 36217, -40 };
                }
            }
            itemList.push_back(item);

            // Body
            item = { 0, 0 };
            itemList.push_back(item);

            // Chest
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 15680, 891 };
                }
                else // Enhancement
                {
                    item = { 15680, 639 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 24904, -39 };
                }
                else // Enhancement
                {
                    item = { 24904, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 36213, -37 };
                }
                else // Enhancement
                {
                    item = { 36213, -40 };
                }
            }
            itemList.push_back(item);

            // Waist
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 15683, 873 };
                }
                else // Enhancement
                {
                    item = { 15683, 618 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 24902, -39 };
                }
                else // Enhancement
                {
                    item = { 24902, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 36211, -37 };
                }
                else // Enhancement
                {
                    item = { 36211, -40 };
                }
            }
            itemList.push_back(item);

            // Legs
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 15685, 888 };
                }
                else // Enhancement
                {
                    item = { 15685, 633 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 24907, -39 };
                }
                else // Enhancement
                {
                    item = { 24907, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 36216, -37 };
                }
                else // Enhancement
                {
                    item = { 36216, -40 };
                }
            }
            itemList.push_back(item);

            // Feet
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 15678, 876 };
                }
                else // Enhancement
                {
                    item = { 15678, 621 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 24903, -39 };
                }
                else // Enhancement
                {
                    item = { 24903, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 36212, -37 };
                }
                else // Enhancement
                {
                    item = { 36212, -40 };
                }
            }
            itemList.push_back(item);

            // Wrists
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 15679, 864 };
                }
                else // Enhancement
                {
                    item = { 15679, 609 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 24909, -39 };
                }
                else // Enhancement
                {
                    item = { 24909, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 36218, -37 };
                }
                else // Enhancement
                {
                    item = { 36218, -40 };
                }
            }
            itemList.push_back(item);

            // Hands
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 15682, 876 };
                }
                else // Enhancement
                {
                    item = { 15682, 621 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 24905, -39 };
                }
                else // Enhancement
                {
                    item = { 24905, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 36214, -37 };
                }
                else // Enhancement
                {
                    item = { 36214, -40 };
                }
            }
            itemList.push_back(item);

            // Finger 1
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 12017, 867 };
                }
                else // Enhancement
                {
                    item = { 12017, 612 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 25057, -39 };
                }
                else // Enhancement
                {
                    item = { 25057, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 36421, -37 };
                }
                else // Enhancement
                {
                    item = { 36421, -40 };
                }
            }
            itemList.push_back(item);

            // Finger 2
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 11992, 611 };
                }
                else // Enhancement
                {
                    item = { 11992, 611 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 25056, -39 };
                }
                else // Enhancement
                {
                    item = { 25056, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 36420, -37 };
                }
                else // Enhancement
                {
                    item = { 36420, -40 };
                }
            }
            itemList.push_back(item);

            // Trinket 1
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 10659, 0 };
                }
                else // Enhancement
                {
                    item = { 17774, 0 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 25634, 0 };
                }
                else // Enhancement
                {
                    item = { 29776, 0 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 35935, 0 };
                }
                else // Enhancement
                {
                    item = { 38080, 0 };
                }
            }
            itemList.push_back(item);

            // Trinket 2
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 17774, 0 };
                }
                else // Enhancement
                {
                    item = { 5079, 0 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 30293, 0 };
                }
                else // Enhancement
                {
                    item = { 25937, 0 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 37555, 0 };
                }
                else // Enhancement
                {
                    item = { 38081, 0 };
                }
            }
            itemList.push_back(item);

            // Back
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 10249, 864 };
                }
                else // Enhancement
                {
                    item = { 10249, 609 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 25042, -39 };
                }
                else // Enhancement
                {
                    item = { 25042, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 36407, -37 };
                }
                else // Enhancement
                {
                    item = { 36407, -40 };
                }
            }
            itemList.push_back(item);

            // Main hand
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 15229, 2040 };
                }
                else // Enhancement
                {
                    item = { 15229, 602 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 25323, -44 };
                }
                else // Enhancement
                {
                    item = { 25127, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 36686, -44 };
                }
                else // Enhancement
                {
                    item = { 36490, -40 };
                }
            }
            itemList.push_back(item);

            // Off hand
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 10367, 384 };
                }
                else // Enhancement
                {
                    item = { 0, 0 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 25084, -39 };
                }
                else // Enhancement
                {
                    item = { 0, 0 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Elemental, Restoration
                {
                    item = { 36449, -39 };
                }
                else // Enhancement
                {
                    item = { 0, 0 };
                }
            }
            itemList.push_back(item);

            // Ranged
            item = { 0, 0 };
            itemList.push_back(item);
            break;
        case CLASS_DRUID:
            // Head
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 10261, 888 };
                }
                else // Feral Combat
                {
                    item = { 10261, 633 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 24802, -39 };
                }
                else // Feral Combat
                {
                    item = { 24802, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 36103, -37 };
                }
                else // Feral Combat
                {
                    item = { 36103, -40 };
                }
            }
            itemList.push_back(item);

            // Neck
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 12048, 867 };
                }
                else // Feral Combat
                {
                    item = { 12048, 612 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 25070, -39 };
                }
                else // Feral Combat
                {
                    item = { 25070, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 36435, -37 };
                }
                else // Feral Combat
                {
                    item = { 36435, -40 };
                }
            }
            itemList.push_back(item);

            // Shoulders
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 10263, 876 };
                }
                else // Feral Combat
                {
                    item = { 10263, 621 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 24804, -39 };
                }
                else // Feral Combat
                {
                    item = { 24804, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 36105, -37 };
                }
                else // Feral Combat
                {
                    item = { 36105, -40 };
                }
            }
            itemList.push_back(item);

            // Body
            item = { 0, 0 };
            itemList.push_back(item);

            // Chest
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 10264, 891 };
                }
                else // Feral Combat
                {
                    item = { 10264, 636 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 24800, -39 };
                }
                else // Feral Combat
                {
                    item = { 24800, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 36101, -37 };
                }
                else // Feral Combat
                {
                    item = { 36101, -40 };
                }
            }
            itemList.push_back(item);

            // Waist
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 10259, 876 };
                }
                else // Feral Combat
                {
                    item = { 10259, 621 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 24798, -39 };
                }
                else // Feral Combat
                {
                    item = { 24798, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 36099, -37 };
                }
                else // Feral Combat
                {
                    item = { 36099, -40 };
                }
            }
            itemList.push_back(item);

            // Legs
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 10262, 891 };
                }
                else // Feral Combat
                {
                    item = { 10262, 636 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 24803, -39 };
                }
                else // Feral Combat
                {
                    item = { 24803, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 36104, -37 };
                }
                else // Feral Combat
                {
                    item = { 36104, -40 };
                }
            }
            itemList.push_back(item);

            // Feet
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 10257, 876 };
                }
                else // Feral Combat
                {
                    item = { 10257, 621 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 24799, -39 };
                }
                else // Feral Combat
                {
                    item = { 24799, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 36100, -37 };
                }
                else // Feral Combat
                {
                    item = { 36100, -40 };
                }
            }
            itemList.push_back(item);

            // Wrists
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 10256, 864 };
                }
                else // Feral Combat
                {
                    item = { 10256, 609 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 24805, -39 };
                }
                else // Feral Combat
                {
                    item = { 24805, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 36106, -37 };
                }
                else // Feral Combat
                {
                    item = { 36106, -40 };
                }
            }
            itemList.push_back(item);

            // Hands
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 10260, 876 };
                }
                else // Feral Combat
                {
                    item = { 10260, 621 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 24801, -39 };
                }
                else // Feral Combat
                {
                    item = { 24801, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 36102, -37 };
                }
                else // Feral Combat
                {
                    item = { 36102, -40 };
                }
            }
            itemList.push_back(item);

            // Finger 1
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 12017, 867 };
                }
                else // Feral Combat
                {
                    item = { 12017, 612 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 25057, -39 };
                }
                else // Feral Combat
                {
                    item = { 25057, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 36421, -37 };
                }
                else // Feral Combat
                {
                    item = { 36421, -40 };
                }
            }
            itemList.push_back(item);

            // Finger 2
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 12005, 865 };
                }
                else // Feral Combat
                {
                    item = { 12005, 609 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 25056, -39 };
                }
                else // Feral Combat
                {
                    item = { 25056, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 36420, -37 };
                }
                else // Feral Combat
                {
                    item = { 36420, -40 };
                }
            }
            itemList.push_back(item);

            // Trinket 1
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 10659, 0 };
                }
                else // Feral Combat
                {
                    item = { 17774, 0 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 25634, 0 };
                }
                else // Feral Combat
                {
                    item = { 29776, 0 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 35935, 0 };
                }
                else // Feral Combat
                {
                    item = { 38080, 0 };
                }
            }
            itemList.push_back(item);

            // Trinket 2
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 17774, 0 };
                }
                else // Feral Combat
                {
                    item = { 5079, 0 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 30293, 0 };
                }
                else // Feral Combat
                {
                    item = { 25937, 0 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 37555, 0 };
                }
                else // Feral Combat
                {
                    item = { 38081, 0 };
                }
            }
            itemList.push_back(item);

            // Back
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 10249, 864 };
                }
                else // Feral Combat
                {
                    item = { 10249, 609 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 25042, -39 };
                }
                else // Feral Combat
                {
                    item = { 25042, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 36407, -37 };
                }
                else // Feral Combat
                {
                    item = { 36407, -40 };
                }
            }
            itemList.push_back(item);

            // Main hand
            if (TargetLevel == 60)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 15278, 885 };
                }
                else // Feral Combat
                {
                    item = { 15278, 630 };
                }
            }
            else if (TargetLevel == 70)
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 25182, -39 };
                }
                else // Feral Combat
                {
                    item = { 25182, -40 };
                }
            }
            else
            {
                if (specialization == SPECIALIZATION_1 || specialization == SPECIALIZATION_3) // Balance, Restoration
                {
                    item = { 36602, -36 };
                }
                else // Feral Combat
                {
                    item = { 36602, -40 };
                }
            }
            itemList.push_back(item);

            // Off hand
            item = { 0, 0 };
            itemList.push_back(item);

            // Ranged
            item = { 0, 0 };
            itemList.push_back(item);
            break;
        default:
            break;
        }

        return itemList;
    }
};

void AddSC_appreciation_creature()
{
    new AppreciationCreature();
}
