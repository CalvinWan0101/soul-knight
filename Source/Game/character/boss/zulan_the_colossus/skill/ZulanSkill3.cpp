#include "stdafx.h"
#include "ZulanSkill3.h"

#include "ZulanSkill3Launcher.h"
#include "../../../Player.h"
#include "../../../../manager/ObjectManager.h"
#include "../../../../utils/Rand.h"

ZulanSkill3::ZulanSkill3(Monster* author) : BossSkill(author)
{
}

bool ZulanSkill3::Update()
{
    Vec playerToAuthor = ObjectManager::Instance()->GetPlayer()->GetPosition() - author->GetPosition();
    playerToAuthor.SetLength(Rand::Instance()->Get(20,100));
    ZulanSkill3Launcher* launcher = new ZulanSkill3Launcher(author->GetPosition() + playerToAuthor);
    ObjectManager::Instance()->AddObject(launcher);
    return true;
}
