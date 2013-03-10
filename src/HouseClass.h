int8 Unk0x00; // 0x0
int32 ID; // 0x1
int32 HouseTypeClassPointer; // 0x5
int8 DifficultyMode; // 0x9
int8 Unk0x0A; // 0xa
int8 Unk0x0B; // 0xb
int32 Unk0x0C; // 0xc

int32 Unk0x10;
int32 Unk0x14;
int32 Unk0x18;
int32 Unk0x1C;

// Something with tech level
int32 TechLevel; 0x20

int32 Unk0x24;
int32 Unk0x28;
int32 Unk0x2C;

int32 Unk0x30;
int32 Unk0x34;
int32 Unk0x38;
int32 Unk0x3C;

int8 Unk0x40;
int8 HouseType;

// Bit field, also checks if House is AI
// AND 1 checks whether is allocated
// TEST 2 checks if AI, if result is zero the house is AI
// TEST 4: something with shrouding the map in the superweapon handler
// TEST 0x20 checks if player controlled or not, if result is zero house is AI controlled
// Test 0x80: Something with harvested, probably set when there's more credits than possible storage
// OR 56 to have computer control production
int8 IsAllocatedBitField; 0x42

// Byte bitfield
// First bit is related to defeating mplayer player, probably whether this house is defeated
// TEST 0x20: Might be a check if a building has been created or lost for the house
int8 Unk0x43; 0x43

// Byte bitfield
// TEST 8: Something to do with GPS
int8 Unk0x44; 0x44

// Byte bitfield
// If first bit is set calls DisplayClass::All_To_Look(int) in HouseClass::AI() for PlayerPtr
int8 Unk0x45; 0x45

int32 IQ; 0x46

// Something to do with AI and production
// If set to 4 the AI sells all it's buildings
int8 Unk0x4A; 0x4A

int8 Unk0x4B; 0x4B
int32 Unk0x4C; 0x4C

int32 Unk0x50;
int32 Unk0x54;
int32 Unk0x58;
int32 Unk0x5C;

int32 Unk0x60;
int32 Unk0x64;
int32 Unk0x68;
int32 Unk0x6C;

int32 Unk0x70;
int32 Unk0x74;
int32 Unk0x78;
int32 Unk0x7C;

int32 Unk0x80;
int32 Unk0x84;
int32 Unk0x88;
int32 Unk0x8C;

int32 Unk0x90;
int32 Unk0x94;
int32 Unk0x98;
int32 Unk0x9C;

int32 Unk0xA0;
int32 Unk0xA4;
int32 Unk0xA8;
int32 Unk0xAC;

int32 Unk0xB0;
int32 Unk0xB4;
int32 Unk0xB8;
int32 Unk0xBC;

int32 Unk0xC0;
int32 Unk0xC4;
int32 Unk0xC8;
int32 Unk0xCC;

int32 Unk0xD0;
int32 Unk0xD4;
int32 Unk0xD8;
int32 Unk0xDC;

int32 Unk0xE0;
int32 Unk0xE4;
int32 Unk0xE8;
int32 Unk0xEC;

int32 Unk0xF0;
int32 Unk0xF4;
int32 Unk0xF8;
int32 Unk0xFC;

int32 Unk0x100;
int32 Unk0x104;
int32 Unk0x108;
int32 Unk0x10C;

int32 Unk0x110;
int32 Unk0x114;
int32 SomethingWithWinning; // 0x118
int32 Unk0x11C;

int32 Unk0x120;
int32 Unk0x124;
int32 Unk0x128;
int32 Unk0x12C;

int32 Unk0x130;
int32 Unk0x134;
int32 Unk0x138;
int8 Unk0x13C;

// Byte bitfield
// TEST 1: Has Airfield or not
int8 Unk0x13D;

int8 Unk0x13E;
int8 Unk0x13F;

int32 Unk0x140;
int32 Unk0x144;
int8 Unk0x148;
int8 Unk0x149;
int8 Unk0x14A;

// Another byte bitfield
// TEST 0x40: Something to do with lower power?
// Test 1: Something to do with super weapons, maybe has Allies Tech Center?
int8 Unk0x14B;

int32 Unk0x14C;

int32 Unk0x150;
int32 Unk0x154;
int32 Unk0x158;
int32 Unk0x15C;

int32 Unk0x160;
int32 Unk0x164;
int32 Unk0x168;
int32 Unk0x16C;

int32 Unk0x170;
int32 Unk0x174;
int32 Unk0x178;
int32 Unk0x17C;

int32 Unk0x180;
int32 Unk0x184;
int32 Unk0x188;
int32 Unk0x18C;

int8 Unk0x190;
int8 Unk0x191;
int8 Unk0x192;
int32 CurrentOreStorage; 0x193
int32 Money; 0x197
int32 OreStorageMaximum; 0x19B
int8 Unk0x19C;

int32 Unk0x1A0;
int32 Unk0x1A4;
int32 Unk0x1A8;
int32 Unk0x1AC;

int32 Unk0x1B0;
int32 Unk0x1B4;
int32 Unk0x1B8;
int32 Unk0x1BC;

int32 Unk0x1C0;
int32 Unk0x1C4;
int32 Unk0x1C8;
int32 Unk0x1CC;

int32 Unk0x1D0;
int32 Unk0x1D4;
int32 Unk0x1D8;
int32 Unk0x1DC;

int32 Unk0x1E0;
int32 Unk0x1E4;
int32 Unk0x1E8;
int32 Unk0x1EC;

int32 Unk0x1F0;
int32 Unk0x1F4;
int32 Unk0x1F8;
int32 Unk0x1FC;

// 0x17B = Stolen Money?
// 0x32A = has AA guns
// 0x382 = has Tesla Coils
// 0x1790 = Name of player
// 0x176B = Some frame timer stuff for getting attacked