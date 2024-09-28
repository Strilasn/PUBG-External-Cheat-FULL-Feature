#pragma once
#include "Defines.hpp"
#include "globals.hpp"
#include "Overlay.hpp"
#include <d3dx9core.h>
ImFont* m_pFont;
LPDIRECT3DDEVICE9 d3ddev;
ID3DXLine* dx_Line;
ID3DXFont* dx_Font;
IDirect3DDevice9Ex* p_Device;
#define M_PI	3.14159265358979323846264338327950288419716939937510
int box;
std::string string_To_UTF8(const std::string& str)
{
	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

	wchar_t* pwBuf = new wchar_t[nwLen + 1];
	ZeroMemory(pwBuf, nwLen * 2 + 2);

	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char* pBuf = new char[nLen + 1];
	ZeroMemory(pBuf, nLen + 1);

	::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr(pBuf);

	delete[]pwBuf;
	delete[]pBuf;

	pwBuf = NULL;
	pBuf = NULL;

	return retStr;
}
void DrawCorneredBox(int X, int Y, int W, int H, const ImU32& color, int thickness)
{
	float lineW = (W / 3);
	float lineH = (H / 3);

	////black outlines
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);

	//corners
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
}
void DrawBox(float X, float Y, float W, float H, const ImU32 color)
{
	ImGui::GetOverlayDrawList()->AddRect(ImVec2(X + 1, Y + 1), ImVec2(((X + W) - 1), ((Y + H) - 1)), ImGui::GetColorU32(color));
	ImGui::GetOverlayDrawList()->AddRect(ImVec2(X, Y), ImVec2(X + W, Y + H), ImGui::GetColorU32(color));
}
void DrawStrokeText(int x, int y, const char* str)
{
	ImFont a;
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = string_To_UTF8(utf_8_1);

	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x - 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(255, 255, 255, 255)), utf_8_2.c_str());
}
void DrawFilledRect(float x, float y, float w, float h, D3DCOLOR color)
{
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), color, NULL, NULL);
}
void Line(ImVec2 pos, ImVec2 size, ImU32 color, float thickness)
{
	ImGui::GetWindowDrawList()->AddLine(pos, size, color, thickness);
}
void crosshair()
{
	float MidX = 1920 / 2;
	float MidY = 1080 / 2;

	Line({ MidX - 10, MidY }, { MidX - 0, MidY }, ImColor(255.f, 255.f, 255.f, 1.f), 1.6);
	Line({ MidX, MidY - 10 }, { MidX, MidY - 0 }, ImColor(255.f, 255.f, 255.f, 1.f), 1.6);
	Line({ MidX + 10, MidY }, { MidX + 0, MidY }, ImColor(255.f, 255.f, 255.f, 1.f), 1.6);
	Line({ MidX, MidY + 10 }, { MidX, MidY + 0 }, ImColor(255.f, 255.f, 255.f, 1.f), 1.6);
}
void FillArea(float x, float y, float width, float height, D3DCOLOR color)
{
	D3DXVECTOR2 vectorLine[2];
	dx_Line->SetWidth(width);

	vectorLine[0].x = x + width / 2;
	vectorLine[0].y = y;
	vectorLine[1].x = x + width / 2;
	vectorLine[1].y = y + height;

	dx_Line->Draw(vectorLine, 2, color);
}
void DrawString(int x, int y, DWORD color, LPD3DXFONT g_pFont, const char* fmt, ...)
{
	char buf[1024] = { 0 };
	va_list va_alist;
	RECT FontPos = { x, y, x + 120, y + 16 };
	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);
	g_pFont->DrawTextA(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
}
void DrawCircle(int x, int y, int radius, const ImU32& color, int segments)
{
	ImGui::GetOverlayDrawList()->AddCircle(ImVec2(x, y), radius, ImGui::GetColorU32(color), segments);
}
void DrawFilledRectangle1(int x, int y, int w, int h, D3DCOLOR color)
{
	D3DRECT rect = { x, y, x + w, y + h };
	p_Device->Clear(1, &rect, D3DCLEAR_TARGET, color, 0, 0);
}
// Hope this pissed you off lmaoo ^^^^

DWORD blackColor = D3DCOLOR_ARGB(255, 0, 0, 0);
DWORD healthBarColor = D3DCOLOR_ARGB(200, 000, 255, 000);
DWORD Name = D3DCOLOR_ARGB(255, 255, 255, 255);


/*namespace Visuals
{
	std::vector<entity_t> entities = {};

	void Esp()
	{
		for (int i = 1; i < entities.size(); i++)
		{
			auto Entities = entities[i];
			if (!Entities.controller || !Entities.pawn) continue;

			vec3 rootPos = Game::GetPos(Entities.pawn);
			vec2 rootPosScreen;

			vec3 Head = Game::GetBoneLocationByIndex(Entities.pawn, 6);
			vec2 HeadScreen;

			vec3 Foot = Game::GetBoneLocationByIndex(Entities.pawn, 0);
			vec2 FootScreen;

			if (!Game::WorldToScreen(rootPos, rootPosScreen)) continue;
			if (!Game::WorldToScreen(Head, HeadScreen)) continue;
			if (!Game::WorldToScreen(Foot, FootScreen)) continue;

			float height = abs(HeadScreen.y - rootPosScreen.y);
			float width = height * 0.65;

			std::string testName = Game::name(Entities.controller); // Profile Name
			std::string opname = Game::OpName(Entities.controller); // Player Operator Name

			float Health = Game::Health(Entities.pawn); // Entities Health
			float CurrentHealth = Health / 120.0f;
			if (CurrentHealth < 0 || CurrentHealth >= 1) CurrentHealth = 1;


			if (globals.enableEsp)
			{
				if (globals.cornerbox)
				{
					switch (globals.BoxType)
					{
					case corner:
					{
						DrawCorneredBox(HeadScreen.x - (width / 2) - 1, HeadScreen.y - (height / 5) - 1, width + 2, height + 12, ImColor(255, 255, 255, 255), 0.5);
						break;
					}
					case boxd:
					{
						DrawBox(HeadScreen.x - (width / 2) - 1, HeadScreen.y - (height / 5) - 1, width + 2, height + 12, ImColor(255, 255, 255, 255));
						break;
					}
					}
				}
				if (globals.filledbox)
				{
					DrawFilledRect(HeadScreen.x - (width / 2) - 1, HeadScreen.y - (height / 5) - 1, width + 2, height + 12, D3DCOLOR_ARGB(93, 0, 0, 0));
				}
				if (globals.healthbar)
				{
					DrawFilledRect(HeadScreen.x - (width / 2) - 6 - 1, HeadScreen.y - (height / 5) - 1, 5, height + 10 + 2, blackColor);
					DrawFilledRect(HeadScreen.x - (width / 2) - 6, HeadScreen.y - (height / 5), 3, (height + 10) * CurrentHealth, healthBarColor);
				}
			}
		}
	}
}*/

