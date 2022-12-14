#pragma once
#include "stdfx.h"
#include"../../agrio_Server/agrio_Server/Protocol.h"

/******************************************** 좌표********************************************/
// 스프라이트
const RECT char_move_sprite_rect[8][4] = //스프라이트 좌표
{ { { 0,0,18,30 },{ 32,0,50,30 },{ 64,0,82,30 },{ 96,0,114,30 } }/*N*/,{ { 133,0,151,30 },{ 165,0,173,30 },{ 197,0,215,30 },{ 229,0,247,30 } }/*NE*/,
{ { 264,0,282,30 },{ 296,0,314,30 },{ 328,0,346,30 },{ 360,0,388,30 } }/*E*/,{ { 397,0,415,30 },{ 428,0,446,30 },{ 460,0,488,30 },{ 492,0,510,30 } }/*SE*/,
{ { 0,36,18,66 },{ 32,36,50,66 },{ 64,36,82,66 },{ 96,36,114,66 } }/*S*/,{ { 133,36,151,66 },{ 165,36,173,66 },{ 197,36,215,66 },{ 229,36,247,66 } }/*SW*/,
{ { 264,36,282,66 },{ 296,36,314,66 },{ 328,36,346,66 },{ 360,36,388,66 } }/*W*/,{ { 397,36,415,66 },{ 428,36,446,66 },{ 460,36,488,66 },{ 492,36,510,66 } }/*NW*/ };
const RECT char_atk_sprite_rect[8][2] =  //공격모션 스프라이트 좌표
{ {{0,0,30,32}, {30,0,60,32} }/*N*/, {{ 60,0,90,32 }, {90,0,120,32} }/*NE*/,{{120,0,150,32},{150,0,180,32}}/*E*/,{{180,0,210,32},{210,0,240,32}}/*SE*/,
{ { 0,32,30,64 },{ 30,32,60,64 } }/*S*/,{ { 60,32,90,64 },{ 90,32,120,64 } }/*SW*/,{ { 120,32,150,64 },{ 150,32,180,64 } }/*W*/,{ { 180,32,210,64 },{ 210,32,240,64 }/*NW*/ } };
const RECT char_weapon_sprite_rect[8][2] = //무기 스프라이트 좌표
{ {{0,0,50,52},{50,0,100,52}}/*N*/, {{100,0,150,52},{150,0,200,52}}/*NE*/ ,{ {200,0,250,52},{250,0,300,52}}/*E*/, {{300,0,350,52},{350,0,400,52}}/*SE*/,
{ { 0,52,50,104 },{ 50,52,100,104 } }/*S*/,{ { 100,52,150,104 },{ 150,52,200,104 } }/*SW*/ ,{ { 200,52,250,104 },{ 250,52,300,104 } }/*W*/,{ { 300,52,350,104 },{ 350,52,400,104 } }/*NW*/ };

// UI 좌표
const RECT logo_rect = //로고 위치      (스타트화면)
{
	120,120,750,370
};
const RECT play_button_rect = //play버튼 위치  (스타트화면)
{
	650,480,800,550
};
const RECT exit_button_rect = //exit버튼 위치  (스타트화면)
{
	650,600,800,670
};
const RECT weapon_image_rect[5] =  //인벤토리 5개 이미지 위치
{
	{ 285,730,335,780 },{ 355,730,405,780 },{ 425,730,475,780 },{ 495,730,545,780 }, { 565,730,615,780 }
};
const RECT GAMEOVER_rect = //게임오버 버튼 위치  (게임엔드화면)
{
	220,50,620,150
};
const RECT rankingbox_rect = //랭킹박스 위치       (게임엔드화면)
{
	100,200,745,600
};
const RECT replay_button_rect = //리플레이 버튼 위치  (게임엔드화면)
{
	150,640,300,710
};
const RECT exit2_button_rect = //exit버튼 위치       (게임엔드화면)    //exit버튼이 두 종류라는걸 깨닫았을땐 이미 늦었다 정답은 exit2
{
	530,640,680,710
};

/******************************************** 변수 ********************************************/
// 스프라이트
enum class SPRITE
{
	bgTitle, bgLobby, bgStage1, bgEnd, btnPlay, btnExit, btnReplay,
	Izuna, Izuna_Atk, GenAn, GenAn_Atk, Hinagiku, Hinagiku_Atk, Ichika, Ichika_Atk, Kagen, Kagen_Atk, Mitsumoto, Mitsumoto_Atk, Shino, Shino_Atk, Sizune, Sizune_Atk,
	pistol, uzi, shotgun, box,
	uiPistol, uiUzi, uiShotgun, uiPotion, uiBox,
	itemBox,
	bulletN, bulletNE, bulletE, bulletSE, bulletS, bulletSW, bulletW, bulletNW,
	wallCol, wallRow,
	bgWinner, bgGameover 
};

// Win API
MSG Message;
HINSTANCE g_hInst;
LPCTSTR lpszClass = _T("Agrio");

// SOCKET
SOCKET sock;

// 전역변수
const int character_width = 38;
const int character_height = 60;
const int win_x_size = 900;      //윈도우 x사이즈
const int win_y_size = 800;      //윈도우 y사이즈
bool isLoginOk = false;			// 로그인ok가 올때까지 대기
const int max_hp = 100;			// 플레이어의 최대 체력

bool isAlreadyConnect = false;

// 키 액션
struct KEY_ACTION
{
	bool left = false, right = false;
	bool up = false, down = false;
	bool space = false;
	bool reqSend = false;
};
KEY_ACTION keyAction;

unsigned __int64 TIMER;

// 애니메이션 출력 속도
const int ANIMATION_TIME = 100;

// 총알 발사 속도
const int ITEM_TIME[5] = { 500, 100, 500, 500, 500 };

// 타이틀 창에서 캐릭터 선택하게 해주는 변수들
int selAnimation = 0;
int selTimer = ANIMATION_TIME;
int selPlayer = (int)SPRITE::Izuna;

// 플레이어
int playerID = 0;		// 인덱스 값
int selectedWeapon = 0;	// 선택한 무기
int itemTimer = 0;

// 씬
SCENE scene = SCENE::title;

void GameLoop(HWND hWnd);