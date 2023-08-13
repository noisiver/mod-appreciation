#include "mod_appreciation.h"

void Appreciation::OnLevelChanged(Player* player, uint8 oldlevel)
{
    if (!RewardAtMaxLevel)
        return;

    if (player->GetLevel() == sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL) && oldlevel == sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL) - 1)
        SendMailTo(player, "Certificate of Appreciation", "We truly appreciate you sticking around, enjoying all that we have to offer. We hope you enjoy this certificate which can be redeemed at the nearest appreciation assistant to receive boosts for your characters.", ITEM_CERTIFICATE, 1);
}

void Appreciation::SendMailTo(Player* receiver, std::string subject, std::string body, uint32 itemId, uint32 itemCount)
{
    uint32 guid = receiver->GetGUID().GetCounter();

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    MailDraft* mail = new MailDraft(subject, body);
    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(itemId);
    if (pProto)
    {
        Item* mailItem = Item::CreateItem(itemId, itemCount);
        if (mailItem)
        {
            mailItem->SaveToDB(trans);
            mail->AddItem(mailItem);
        }
    }

    mail->SendMailTo(trans, receiver ? receiver : MailReceiver(guid), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM), MAIL_CHECK_MASK_RETURNED);
    delete mail;
    CharacterDatabase.CommitTransaction(trans);
}

bool Appreciation::HasCertificate(Player* player)
{
    if (!RequireCertificate)
        return true;

    return player->HasItemCount(ITEM_CERTIFICATE);
}

void Appreciation::BoostPlayer(Player* player, uint8 specialization)
{
    UpdatePlayerLevel(player);
    UpdateProficiencies(player, specialization);
    EquipNewItems(player, specialization);
    GiveCopper(player);
    RemoveCertificate(player);
}

void Appreciation::UpdatePlayerLevel(Player* player)
{
    if (player->GetLevel() >= TargetLevel)
        return;

    player->GiveLevel(TargetLevel);
    player->SetUInt32Value(PLAYER_XP, 0);
}

void Appreciation::UpdateProficiencies(Player* player, uint8 specialization)
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

void Appreciation::EquipNewItems(Player* player, uint8 specialization)
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

void Appreciation::GiveCopper(Player* player)
{
    if (IncludedCopper <= 0)
        return;

    player->ModifyMoney(IncludedCopper);
}

void Appreciation::UnlockContinent(Player* player, uint8 continent)
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

void Appreciation::RemoveCertificate(Player* player)
{
    if (!RequireCertificate)
        return;

    player->DestroyItemCount(ITEM_CERTIFICATE, 1, true);
}
