#include "exploding_relic_monks.h"
#include "genie/dat/DatFile.h"
#include "ids.h"


void patchSaboteurForFirstRelicMonkExplosion(genie::Civ &civ) {
    genie::Unit &saboteur = civ.Units.at(ID_SABOTEUR);
    saboteur.HitPoints = -1;
    saboteur.DeadUnitID = ID_FURIOUS_THE_MONKEY_BOY;
    saboteur.Type50.Attacks.at(0).Amount = 5000;
    saboteur.Type50.Attacks.at(1).Amount = 5000;
    saboteur.Type50.Attacks.at(2).Amount = 5000;
    saboteur.Type50.MaxRange = 17;
    saboteur.Type50.BlastWidth = 17;
    saboteur.Type50.BlastAttackLevel = 0;
    saboteur.WwiseTrainSoundID = 0;
    std::cout << "Patched Saboteur unit for civ " << civ.Name << "\n";
}

void patchMonkeyForSecondRelicMonkExplosion(genie::Civ &civ) {
    genie::Unit &furious = civ.Units.at(ID_FURIOUS_THE_MONKEY_BOY);
    furious.HitPoints = -1;
    furious.Class = CLASS_PETARD;
    furious.Type50.Attacks.at(0).Amount = 5000;
    furious.Type50.Attacks.at(1).Amount = 5000;
    furious.Type50.MaxRange = 17;
    furious.Type50.BlastWidth = 17;
    furious.Type50.BlastAttackLevel = 0;
    std::cout << "Patched Furious the Monkey Boy unit for civ " << civ.Name << "\n";
}

void setSaboteurAsDeadUnitForMonkWithRelic(genie::Civ &civ) {
    genie::Unit *unit = &civ.Units.at(ID_MONK_WITH_RELIC);
    unit->DeadUnitID = ID_SABOTEUR;
    std::cout << "Set dying unit for unit " << unit->ID << " to " << ID_SABOTEUR << " for civ " << civ.Name
              << std::endl;
}

void configureExplodingRelicMonks(genie::DatFile *df) {
    for (genie::Civ &civ : df->Civs) {
        setSaboteurAsDeadUnitForMonkWithRelic(civ);
        patchSaboteurForFirstRelicMonkExplosion(civ);
        patchMonkeyForSecondRelicMonkExplosion(civ);
    }
}
