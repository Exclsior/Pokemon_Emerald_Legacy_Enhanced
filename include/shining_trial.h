#ifndef GUARD_SHINING_TRIAL_H
#define GUARD_SHINING_TRIAL_H

#include "debug.h"

struct Trainer;
struct Pokemon;

const struct Trainer *GetShiningTrialTrainer(void);
bool8 ShiningTrial_CreateMirror(struct Pokemon *dest);
void ShiningTrial_CheckEligibility(void);
void ShiningTrial_Begin(void);
void ShiningTrial_RestoreParty(void);
void ShiningTrial_Finish(void);
void ShiningTrial_Cancel(void);

#if TX_DEBUG_SYSTEM_ENABLE == TRUE
void ShiningTrial_RunConversionTests(void);
#endif

#endif // GUARD_SHINING_TRIAL_H
