﻿#pragma once
#include <Windows.h>
#include <algorithm>
#include <locale>
#include <cstdlib>
#include <fstream>
#include <map>
#include <unordered_map>
#include "Constants.h"
#include "Common.h"
#include "D2Structs.h"

/*
 * MPQInit handles the data we can initialize from MPQ files, provided we
 * are able to load StormLib. It also provides defaults in case we cannot
 * read the MPQ archive.
 */

extern unsigned int STAT_MAX;
extern unsigned int SKILL_MAX;
extern unsigned int PREFIX_MAX;
extern unsigned int SUFFIX_MAX;

// Item attributes from ItemTypes.txt and Weapon/Armor/Misc.txt
struct ItemAttributes {
	std::string name;
	char code[5];
	std::string category;
	BYTE width;
	BYTE height;
	BYTE stackable;
	BYTE useable;
	BYTE throwable;
	BYTE itemLevel;		// 1=normal, 2=exceptional, 3=elite
	BYTE unusedFlags;
	unsigned int flags;
	unsigned int flags2;
	BYTE qualityLevel;
	BYTE magicLevel;
	unsigned int maxac;
	unsigned int cost;
};

// Properties from ItemStatCost.txt that we need for parsing incoming 0x9c packets, among other things
struct StatProperties {
	std::string name;
	//std::string localizedName;
	BYTE saveBits;
	BYTE saveParamBits;
	BYTE saveAdd;
	BYTE op;
	BYTE sendParamBits;
	unsigned short ID;
	unsigned int costAdd;
	unsigned int costMultiply;
};

struct ItemAffixProperties {
	unsigned int ID;
	unsigned int costAdd;
	unsigned int costMultiply;
};

struct CharStats {
	int toHitFactor;
};

extern std::vector<StatProperties*> AllStatList;
extern std::unordered_map<std::string, StatProperties*> StatMap;
extern std::vector<CharStats*> CharList;
extern std::map<std::string, ItemAttributes*> ItemAttributeMap;
extern std::map<std::string, InventoryLayout*> InventoryLayoutMap;
extern std::vector<ItemAffixProperties*> AllPrefixList;
extern std::vector<ItemAffixProperties*> AllSuffixList;


#define STAT_NUMBER(name) (StatMap[name]->ID)

bool IsInitialized();
void InitializeMPQData();
