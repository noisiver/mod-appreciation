#include "mod_appreciation.h"

std::vector<std::vector<int>> Appreciation::GetItemList(uint32 classId, uint8 specialization)
{
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
