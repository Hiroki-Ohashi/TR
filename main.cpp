#include <Novice.h>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include <math.h>


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

	int pixels[width * height];

	int gh1 = Novice::LoadTexture("./particle.png");

	//int pixels[width * height] = { 0 };

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



		// 全ての画素を見るfor分
		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {

				int index = x + y * width;
				float sum = 0;

				//↓一つの画素に対し、すべてのmetaballからの距離を積算している。      
				for (int i = 0; i < /*メタボールの位置*/; i++) {
					
					//↓画素からボール中心への距離
					float d = sqrtf(powf(y - pos.y, 2) + powf(y - pos.x, 2));
					sum += d;
				}

				//２．

				pixels[index] = RGB(sum, 255, 255);
				//pixels[index] = color(sum, 255, 255);
			}

		///
		/// ↑更新処理ここまで
		///



		///
		/// ↓描画処理ここから
		///

		Novice::DrawBox(
			0, 0,
			width, height,
			0.0f,
			BLACK,
			kFillModeSolid
		);

		Novice::SetBlendMode(BlendMode::kBlendModeAdd);

		Novice::DrawSprite(
			(int)pos.x, (int)pos.y,
			gh1,
			0.2f, 0.2f,
			0.0f,
			WHITE
		);

		Novice::DrawSprite(
			(int)pos2.x - 150, (int)pos2.y - 100,
			gh1,
			0.2f, 0.2f,
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
