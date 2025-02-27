#include "raylib.h"
#include "math.h"
#include <string>
#include <locale>
#include <stdlib.h>
#include "functions.h"

struct Ball {
	float x, y;
	float speedX, speedY;
	float radius;
	void Draw() {
		DrawCircle((int)x, (int)y, radius, GREEN);
	}
};

struct Bat {
	float x, y;
	float speedX, speedY;
	float radius;
	void Draw() {
		DrawCircle((int)x, (int)y, radius, PURPLE);
	}

};

struct Dot {
	float x, y;
	float width, height;
	void Draw() {
		DrawRectangleRec({ x, y, width, height }, YELLOW);
	}
};

struct Wall {
	float x, y;
	float width, height;
	bool IsDestroyed;
	Rectangle GetRec() {
		return Rectangle{ x, y, width, height };
	}
	void Draw() {
		if (IsDestroyed == 0)
			DrawRectangleRec(GetRec(), WHITE);
	}
};

int main() {
	const char* MenuStatus = nullptr;
	const char* winnertext = nullptr;
	const char* wallmode = nullptr;
	int LeftPoints = 0;
	int RightPoints = 0;
	int oldLeftPoints = 0;
	int oldRightPoints = 0;
	InitWindow(800, 600, "Pong");
	SetWindowState(FLAG_VSYNC_HINT);

	Ball ball;
	ball.x = GetScreenWidth() / 2.0f;
	ball.y = GetScreenHeight() / 2.0f;
	ball.radius = 10;
	ball.speedX = start_speed(oldLeftPoints, LeftPoints);
	ball.speedY = 1;

	Bat leftBat;
	leftBat.x = 50; leftBat.y = GetScreenHeight() / 2;
	leftBat.speedX = 500; leftBat.speedY = 600;
	leftBat.radius = 30;
	Bat rightBat;
	rightBat.x = GetScreenWidth() - 50; rightBat.y = GetScreenHeight() / 2;
	rightBat.speedX = 500; rightBat.speedY = 600;
	rightBat.radius = 30;

	Dot textDot;
	textDot.width = 5; textDot.height = 5;
	int flag = 0;

	Wall LeftHighWall;
	LeftHighWall.x = 0; LeftHighWall.y = 0;
	LeftHighWall.width = 2; LeftHighWall.height = 300; LeftHighWall.IsDestroyed = 0;
	Wall LeftLowWall;
	LeftLowWall.x = 0; LeftLowWall.y = 300;
	LeftLowWall.width = 2; LeftLowWall.height = 300; LeftLowWall.IsDestroyed = 0;
	Wall RightHighWall;
	RightHighWall.x = GetScreenWidth() - 2; RightHighWall.y = 0;
	RightHighWall.width = 2; RightHighWall.height = 300; RightHighWall.IsDestroyed = 0;
	Wall RightLowWall;
	RightLowWall.x = GetScreenWidth() - 2; RightLowWall.y = 300;
	RightLowWall.width = 2; RightLowWall.height = 300; RightLowWall.IsDestroyed = 0;

	while (!WindowShouldClose()) {
		while (!MenuStatus) {
			BeginDrawing();
			ClearBackground(BLACK);

			int textWidth1 = MeasureText("Start the game", 60);
			DrawText("Start the game", GetScreenWidth() / 2 - textWidth1 / 2, GetScreenHeight() / 2 - 60, 60, YELLOW);
			int textWidth2 = MeasureText("Close app", 40);
			DrawText("Close app", GetScreenWidth() / 2 - textWidth2 / 2, GetScreenHeight() / 2 + 100, 40, YELLOW);
			int textWidth3 = 0;
			if (wallmode) {
				textWidth3 = MeasureText("Wall Mode ON", 40);
				DrawText("Wall Mode ON", GetScreenWidth() / 2 - textWidth3 / 2, GetScreenHeight() / 2 + 50, 40, YELLOW);
			}
			else {
				textWidth3 = MeasureText("Wall Mode OFF", 40);
				DrawText("Wall Mode OFF", GetScreenWidth() / 2 - textWidth3 / 2, GetScreenHeight() / 2 + 50, 40, YELLOW);
			}

			if (IsKeyPressed(KEY_SPACE)) {
				flag = abs((flag + 1) % 3);
			}
			if (flag == 0) {
				textDot.x = float(GetScreenWidth() / 2) - textWidth1 / 2 - 20;
				textDot.y = (float)GetScreenHeight() / 2 - 35;
				if (IsKeyPressed(KEY_ENTER)) {
					MenuStatus = "Start the game";
				}
			}
			if (flag == 2) {
				textDot.x = (float)GetScreenWidth() / 2 - textWidth2 / 2 - 20;
				textDot.y = (float)GetScreenHeight() / 2 + 114;
				if (IsKeyPressed(KEY_ENTER)) {
					return 0;
				}
			}
			if (flag == 1) {
				textDot.x = (float)GetScreenWidth() / 2 - textWidth3 / 2 - 18;
				textDot.y = (float)GetScreenHeight() / 2 + 66;
				if (IsKeyPressed(KEY_ENTER)) {
					if (wallmode) {
						wallmode = nullptr;
					}
					else {
						wallmode = "on";
					}
				}
			}
			textDot.Draw();

			EndDrawing();
		}


		if (MenuStatus == "Start the game") {
			ball.x += ball.speedX * GetFrameTime();
			ball.y += ball.speedY * GetFrameTime();

			if (ball.y > GetScreenHeight()) {
				ball.y = GetScreenHeight();
				ball.speedY *= -0.9;
			}
			if (ball.y < 0) {
				ball.y = 0;
				ball.speedY *= -0.9;
			}
			if (IsKeyDown(KEY_W) and leftBat.y > 0) {
				leftBat.y -= leftBat.speedY * GetFrameTime();
			}
			if (IsKeyDown(KEY_S) and leftBat.y < GetScreenHeight()) {
				leftBat.y += leftBat.speedY * GetFrameTime();
			}
			if (IsKeyDown(KEY_A) and leftBat.x > 30) {
				leftBat.x -= leftBat.speedX * GetFrameTime();
			}
			if (IsKeyDown(KEY_D) and leftBat.x < GetScreenWidth() / 4 - 30) {
				leftBat.x += leftBat.speedX * GetFrameTime();
			}

			if (IsKeyDown(KEY_UP) and rightBat.y > 0) {
				rightBat.y -= rightBat.speedY * GetFrameTime();
			}
			if (IsKeyDown(KEY_DOWN) and rightBat.y < GetScreenHeight()) {
				rightBat.y += rightBat.speedY * GetFrameTime();
			}
			if (IsKeyDown(KEY_LEFT) and rightBat.x > GetScreenWidth() / 4 * 3 + 30) {
				rightBat.x -= rightBat.speedX * GetFrameTime();
			}
			if (IsKeyDown(KEY_RIGHT) and rightBat.x < GetScreenWidth() - 30) {
				rightBat.x += rightBat.speedX * GetFrameTime();
			}
			if (wallmode) {
				if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, RightHighWall.GetRec())
					and RightHighWall.IsDestroyed == 0) {
					ball.speedX *= -1.1;
					RightHighWall.IsDestroyed = 1;
				}
				else if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, RightLowWall.GetRec())
					and RightLowWall.IsDestroyed == 0) {
					ball.speedX *= -1.1;
					RightLowWall.IsDestroyed = 1;
				}
				if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, LeftLowWall.GetRec())
					and LeftLowWall.IsDestroyed == 0) {
					ball.speedX *= -1.1;
					LeftLowWall.IsDestroyed = 1;
				}
				else if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, LeftHighWall.GetRec())
					and LeftHighWall.IsDestroyed == 0) {
					ball.speedX *= -1.1;
					LeftHighWall.IsDestroyed = 1;
				}

			}
			if (CheckCollisionCircles(Vector2{ ball.x, ball.y }, ball.radius, Vector2{ leftBat.x, leftBat.y }, leftBat.radius)) {
				if (ball.speedX < 0) {
					ball.speedX *= -1.05;
					ball.speedX += leftBat.speedX * 0.1;
					int isnat = ball.speedX / abs(ball.speedX);
					ball.speedX = std::min((int)abs(ball.speedX), 850) * isnat;
					ball.speedY = (ball.y - leftBat.y) / (leftBat.radius / 1.5) * ball.speedX * 0.5;
				}
			}
			if (CheckCollisionCircles(Vector2{ ball.x, ball.y }, ball.radius, Vector2{ rightBat.x, rightBat.y }, rightBat.radius)) {
				if (ball.speedX > 0) {
					ball.speedX *= -1.05;
					ball.speedX -= rightBat.speedX * 0.1;
					int isnat = ball.speedX / abs(ball.speedX);
					ball.speedX = std::min((int)abs(ball.speedX), 850) * isnat;
					ball.speedY = (ball.y - rightBat.y) / (rightBat.radius / 1.5) * -ball.speedX * 0.5;
				}
			}
			if (ball.x < -ball.radius) {
				winnertext = "Right Player Wins!";
				RightPoints = oldRightPoints + 1;
				ball.speedX = 0;
				ball.speedY = 0;
			}
			if (ball.x > GetScreenWidth() + ball.radius) {
				winnertext = "Left Player Wins!";
				LeftPoints = oldLeftPoints + 1;
				ball.speedX = 0;
				ball.speedY = 0;
			}
			if (winnertext && IsKeyPressed(KEY_SPACE)) {
				ball.x = GetScreenWidth() / 2;
				ball.y = GetScreenHeight() / 2;
				
				ball.speedX = start_speed(oldLeftPoints, LeftPoints);
				oldLeftPoints = LeftPoints;
				oldRightPoints = RightPoints;
				ball.speedY = 1;
				winnertext = nullptr;
				leftBat.x = 50; leftBat.y = GetScreenHeight() / 2;
				rightBat.x = GetScreenWidth() - 50; rightBat.y = GetScreenHeight() / 2;
				LeftHighWall.IsDestroyed = 0; LeftLowWall.IsDestroyed = 0;
				RightHighWall.IsDestroyed = 0; RightLowWall.IsDestroyed = 0;
			}
			if (IsKeyPressed(KEY_P)) {
				ball.x = GetScreenWidth() / 2;
				ball.y = GetScreenHeight() / 2;
				if (oldLeftPoints != LeftPoints or oldRightPoints != RightPoints) {
					oldLeftPoints = LeftPoints;
					oldRightPoints = RightPoints;
					winnertext = nullptr;
					leftBat.x = 50; leftBat.y = GetScreenHeight() / 2;
					rightBat.x = GetScreenWidth() - 50; rightBat.y = GetScreenHeight() / 2;
					LeftHighWall.IsDestroyed = 0; LeftLowWall.IsDestroyed = 0;
					RightHighWall.IsDestroyed = 0; RightLowWall.IsDestroyed = 0;
				}

				ball.speedX = 300;
				ball.speedY = 100;
				MenuStatus = nullptr;
				winnertext = nullptr;
			}

			BeginDrawing();
			ClearBackground(BLACK);
			DrawRectangleRec({ 200, 0, 1, 800 }, GREEN);
			DrawRectangleRec({ 600, 0, 1, 800 }, GREEN);
			ball.Draw();
			leftBat.Draw();
			rightBat.Draw();
			if (wallmode) {
				LeftHighWall.Draw();
				LeftLowWall.Draw();
				RightHighWall.Draw();
				RightLowWall.Draw();
			}
			if (winnertext) {
				int textWidth = MeasureText(winnertext, 60);
				std::string Table = std::to_string(LeftPoints) + " : " + std::to_string(RightPoints);
				const char* table = Table.c_str();
				int tableWidth = MeasureText(table, 60);
				DrawText(winnertext, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 - 30, 60, YELLOW);
				DrawText(table, GetScreenWidth() / 2 - tableWidth / 2, GetScreenHeight() / 2 + 50, 60, YELLOW);
			}
			DrawFPS(10, 10);
			EndDrawing();
		}
	}

	CloseWindow();

	return 0;
}