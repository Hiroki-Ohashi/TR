#include <Novice.h>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>





const char kWindowTitle[] = "学籍番号";


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	const int width = 500;
	const int height = 500;

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, width, height);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Vector2 pos{ 150, 250 };
	Vector2 pos2{ 0, 0 };

	int x = 0;
	int y = 0;

	//int index[width][height] = { 0 };

	//int pixels[width * height];

	int gh1 = Novice::LoadTexture("./particle.png");

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		Novice::GetMousePosition(&x, &y);

		pos2.x = (float)x;
		pos2.y = (float)y;

		///
		/// ↑更新処理ここまで
		///



		///
		/// ↓描画処理ここから
		///

		//Novice::DrawBox(
		//	0, 0,
		//	500, 500,
		//	0.0f,
		//	BLACK,
		//	kFillModeSolid
		//);

		Novice::SetBlendMode(BlendMode::kBlendModeSubtract);

		Novice::DrawSprite(
			(int)pos.x - 45, (int)pos.y - 170,
			gh1,
			0.5f, 0.5f,
			0.0f,
			WHITE
		);

		Novice::DrawSprite(
			(int)pos2.x - 150, (int)pos2.y - 150,
			gh1,
			0.5f, 0.5f,
			0.0f,
			WHITE
		);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;

}
