#include "mod_appreciation.h"
#include "mod_appreciation_booster.h"

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
        uint32 TargetLevel = sConfigMgr->GetOption<uint32>("Appreciation.LevelBoost.TargetLevel", DEFAULT_LEVEL);

        if (TargetLevel != 60 && TargetLevel != 70 && TargetLevel != 80)
            TargetLevel = DEFAULT_LEVEL;

        uint32 IncludedCopper = sConfigMgr->GetOption<uint32>("Appreciation.LevelBoost.IncludedCopper", 2500000);

        if (IncludedCopper <= 0)
            return;

        CharacterBooster::BoostPlayerWithGear(player, TargetLevel, specialization, IncludedCopper);

        RemoveCertificate(player);
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
};

void AddSC_appreciation_creature()
{
    new AppreciationCreature();
}
