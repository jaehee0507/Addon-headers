#pragma once

#include "../entity/AgableMob.h"

class Villager : public AgableMob {
public:
	static const int PROFESSION_DATAFLAG = 0x10; // TODO: Order all these, lol
	static const int INLOVEWITH_DATAFLAG = 0xd40;
	static const int CHASING_DATAFLAG = 0xd48;
	static const int WILLINGTOBREED_DATAFLAG = 0xd59;
	static const int REWARDPLAYERS_DATAFLAG = 0xd6c;
	static const int LASTHURTBY_DATAFLAG = 0xd78;
	static const int TRADINGWITH_DATAFLAG = 0xd4c;
public:
	Villager(TileSource&, int);
}
