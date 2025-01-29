#pragma once

namespace Constants
{
    constexpr float RES_X = 1280.0;
    constexpr float RES_Y = 720.0;
	constexpr float GRAVITY = 5.0  ;
    constexpr float F_NORMAL = -5.0 ;
	constexpr float DELTATIME = 0.8  ;
    constexpr float STRT_VEL_PLYR_X = 2.5;
	constexpr float VEL_PLAYER_X = 8.0;
	constexpr float VEL_PLAYER_Y = 7.0;
    constexpr float JMP_HEIGHT = 200.0;
    constexpr float VEL_ENEMY_X = 1.0;
    constexpr float VEL_ENEMY_Y = 1.0;
    constexpr float E_TRGT_RADIUS_X = 200.0;
    constexpr float E_TRGT_RADIUS_Y = 200.0;
    constexpr float SIZE_PLYR_W = 75.0;
    constexpr float SIZE_PLYR_H = 100.0;
    constexpr float SIZE_ENEMY_H = 50.0;
    constexpr float SIZE_ENEMY_W = 50.0;
    constexpr float SIZE_PLTFORM_H = 50.0;
    constexpr float SIZE_PLTFORM_W = 1280.0;
    constexpr float DMG_SPIKES = 999;
    constexpr float SCALE_PLTFRM = 1.0;
    constexpr float VEL_PROJECTILE = 10.5;
    constexpr float SIZE_PROJECTILE_X = 20;
    constexpr float SIZE_PROJECTILE_Y = 20;
    constexpr float PROJECTILE_HOMING_RADIUS = 300.50;
    constexpr float PROJECTILE_DMG_ENEMY = 1;
    constexpr float SCALE_CAM = 2;
    constexpr float FONT_SIZE = 100.0;

    constexpr float BUTTON_X = 312.0;
    constexpr float BUTTON_Y = 84.0;
    constexpr float BUTTON_HIGHLIGHT_X = 360.0;
    constexpr float BUTTON_HIGHLIGHT_Y = 138.0;
	
	constexpr const char* PLYR_TEXTURE_FILE_PATH = "../assets/Formiga.png";
	constexpr const char* PLATFORM_TEXTURE_FILE_PATH = "../assets/Plataforma.png";
	constexpr const char* ESPINHOS_TEXTURE_FILE_PATH = "../assets/Espinhos.png";
	constexpr const char* TEIA_TEXTURE_FILE_PATH = "../assets/Teia.png";
	constexpr const char* SCENERY_TEXTURE_FILE_PATH= "../assets/BackGround.png";
	constexpr const char* PULGAS_TEXTURE_FILE_PATH = "../assets/Pulga.png";
	constexpr const char* ARANHAS_TEXTURE_FILE_PATH = "../assets/Aranha.png";
	constexpr const char* JOANINHA_TEXTURE_FILE_PATH = "../assets/Joaninha.png";
    constexpr const char* FONT_FILE_PATH = "../assets/monogram.ttf";
    constexpr const char* BUTTON_SELECTED_FILE_PATH = "../assets/Button_Highlight.png";
    constexpr const char* BUTTON_DEFAULT_FILE_PATH = "../assets/Button_basic.png";
}
