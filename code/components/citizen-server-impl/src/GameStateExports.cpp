#include <StdInc.h>
#include <GameServer.h>

#include <GameBuilds.h>
#include <charconv>

static bool g_bigMode;
static bool g_lengthHack;
static bool g_oneSyncPopulation;
static bool(*g_onesync)();

extern fx::GameBuild g_enforcedGameBuild;
extern bool g_replaceExecutable;

namespace fx
{
bool IsBigMode()
{
	// enforce: big mode 
	return true;
}

bool IsLengthHack()
{
	return g_lengthHack;
}

bool IsOneSync()
{
	return true; // Always enable OneSync
}

bool IsOneSyncPopulation()
{
	return g_oneSyncPopulation;
}

void SetOneSyncGetCallback(bool (*cb)())
{
	g_onesync = cb;
}

void SetBigModeHack(bool bigMode, bool lengthHack)
{
	g_bigMode = bigMode;
	g_lengthHack = lengthHack;
}

void SetOneSyncPopulation(bool population)
{
	g_oneSyncPopulation = population;
}

std::string_view GetEnforcedGameBuild()
{
	return g_enforcedGameBuild;
}

int GetEnforcedGameBuildNumber()
{
	int build = 0;
	auto buildNum = GetEnforcedGameBuild();
	std::from_chars(buildNum.data(), buildNum.data() + buildNum.size(), build);

	return build;
}

bool GetReplaceExecutable()
{
	return g_replaceExecutable;
}
}
