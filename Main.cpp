# include <Siv3D.hpp> // Siv3Dライブラリをインクルード

void Main()
{
	// ウィンドウ設定
	Window::Resize(800, 600);

	// 色付き四角の定義
	struct ColoredRect
	{
		Rect rect;
		ColorF color;

		void draw() const
		{
			rect.draw(color);
		}
	};

	// 背景画像
	ColoredRect clayPipe{Rect(800,0,70,300), Palette::Green };

	// スクロール用変数


	// ゲームループ
	while (System::Update())
	{
		// 背景をスクロールさせる
		double deltaTime = Scene::DeltaTime();
		clayPipe.rect.x -= (deltaTime * 20);

		if (clayPipe.rect.x == 0)
		{
			clayPipe.rect.x = 800;
		}

		// 背景の描画
		clayPipe.draw();

	}
}
