#include "mod_appreciation.h"

#include "Config.h"
#include "Player.h"

class AppreciationPlayer : public PlayerScript
{
public:
    AppreciationPlayer() : PlayerScript("AppreciationPlayer") {}

    void OnPlayerLevelChanged(Player* player, uint8 oldlevel) override
    {
        if (!sConfigMgr->GetOption<bool>("Appreciation.RewardAtMaxLevel.Enabled", false))
        {
            return;
        }

        if (player->GetLevel() == sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL) && oldlevel == sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL) - 1)
        {
            SendMailTo(player, "Certificate of Appreciation", "We truly appreciate you sticking around, enjoying all that we have to offer. We hope you enjoy this certificate which can be redeemed at the nearest appreciation assistant to receive boosts for your characters.", ITEM_CERTIFICATE, 1);
        }
    }

private:
    void SendMailTo(Player* receiver, std::string subject, std::string body, uint32 itemId, uint32 itemCount)
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
};

void AddSC_appreciation_player()
{
    new AppreciationPlayer();
}
