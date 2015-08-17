#pragma once

#include <functional>
#include <memory>

class MinecraftClient;
class SignTileEntity;
class SurvivalInventoryScreen {
	public:
	enum CraftingType {};
};
class TilePos;
class SkinPack;
class AbstractScreen;
class MCOServerListItem;
class LevelSummary;
class StorageVersion;
class Player;
class FurnaceTileEntity;
class EnchantingTableEntity;
class CreateWorldScreenType;
class ChestTileEntity;
class BrewingStandTileEntity;

//Size : 20
class ScreenChooser {
	public:
	MinecraftClient* mc;			//0
	char filler1[16];				//4

	public:
	ScreenChooser(MinecraftClient&, bool, bool);
	~ScreenChooser();
	void setXblLoginScreen();
	void setUpsellScreen(bool);
	void setStartMenuScreen();
	void setGameplayScreen();
	void setDisconnectScreen(std::string const&);
	void pushTextEditScreen(SignTileEntity*);
	void pushSurvivalInventoryScreen(SurvivalInventoryScreen::CraftingType, TilePos const&);
	void pushSkinsScreen();
	void pushShowSkinPackScreen(SkinPack const&, std::string const&, bool);
	void pushSelectSkinTypeScreen(bool, bool, std::string const&);
	void pushScreen(std::shared_ptr<AbstractScreen>, bool);
	void pushRemotePlayScreen();
	void pushProgressScreen(bool, std::function<void ()>);
	void pushPauseScreen();
	void pushPausePrevScreen();
	void pushOptionsScreen(bool, bool, std::string const&);
	void pushMobEffectsScreen();
	void pushMessageBoxScreen(std::string const&);
	void pushManageMCOServerScreen(MCOServerListItem const&);
	void pushMakeInfiniteScreen(LevelSummary const&, StorageVersion);
	void pushLocalPlayScreen(bool);
	void pushLanguageScreen();
	void pushKeyboardLayoutScreen(bool);
	void pushInBedScreen();
	void pushGamePadLayoutScreen(bool);
	void pushFurnaceScreen(Player*, FurnaceTileEntity*);
	void pushEnchantingScreen(Player*, EnchantingTableEntity*);
	void pushDeleteWorldScreen(LevelSummary const&);
	void pushDeathScreen();
	void pushCreateWorldScreen(LevelSummary const&);
	void pushCreateWorldScreen(CreateWorldScreenType, MCOServerListItem const&);
	void pushConsoleScreen();
	void pushChestScreen(Player*, ChestTileEntity*);
	void pushChatScreen();
	void pushBrewingStandScreen(Player*, BrewingStandTileEntity*);
	void pushBlockSelectionScreen();
	void pushAnvilScreen(Player*, TilePos const&);
	void pushAddExternalServerScreen();
	void popScreen(AbstractScreen&);
	bool isNewScreensEnabled() const;
	void getInBedScreen();
	void enableNewScreens(bool);
};
