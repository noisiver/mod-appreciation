#include "mod_appreciation.h"

void Appreciation::OnAfterConfigLoad(bool /*reload*/)
{
    RequireCertificate = sConfigMgr->GetOption<bool>("Appreciation.RequireCertificate.Enabled", 1);
    EnableLevelBoost = sConfigMgr->GetOption<bool>("Appreciation.LevelBoost.Enabled", 1);
    TargetLevel = sConfigMgr->GetOption<uint32>("Appreciation.LevelBoost.TargetLevel", DEFAULT_LEVEL);
    IncludedCopper = sConfigMgr->GetOption<uint32>("Appreciation.LevelBoost.IncludedCopper", 2500000);

    if (TargetLevel != 60 && TargetLevel != 70 && TargetLevel != 80)
        TargetLevel = DEFAULT_LEVEL;

    EnableUnlockContinents = sConfigMgr->GetOption<bool>("Appreciation.UnlockContinents.Enabled", 1);
    RewardAtMaxLevel = sConfigMgr->GetOption<bool>("Appreciation.RewardAtMaxLevel.Enabled", 0);
}
