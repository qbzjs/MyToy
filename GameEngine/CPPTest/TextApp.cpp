#include "TextApp.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glew32.lib")

TextApp::TextApp(const wchar_t* className, const wchar_t* title, int width, int height)
	: GLAppBase(className, title, width, height) {}

void TextApp::InitGL(HWND hwnd)
{
	GLRenderingStartUpParams params;
	params.m_HWND = hwnd;
	m_RI = new GLRendering();
	m_RI->StartUp(&params);
}

void TextApp::OnInitialize()
{
	GLAppBase::OnInitialize();
	CInput::Init(GetModuleHandle(NULL), m_Hwnd);

	CTrueTypeFont* f = FontManager->LoadFont(1, FONT_PATH);
	font = new CFontRenderer();
	font->SetFont(f);
	font->SetColor(Color::green);
	font->SetEffect(EFontEffect::Shadow)->SetEffectVector(Vector3(1, -1, 0))->SetEffectColor(Color::black);
	font->SetFontSize(font_size);
	font->SetTextAlignment(EAlignment::CENTER_MIDDLE);
	font->SetRenderType(ERenderType::Smart);
	font->SetTextRect(SRect2D(0, 0, 4, 1));
	font->SetText(SHOW_TEXT);
	font->SetIntervalX(font_interval_x);
	font->SetIntervalY(font_interval_y);

	modelMat = Matrix4x4::Identity();
	viewMat = Matrix4x4::LookAt(Vector3(0, 0, 10), Vector3::zero, Vector3::up);
}

void TextApp::OnWindowSizeChanged(int width, int height)
{
	GLAppBase::OnWindowSizeChanged(width, height);
	projectionMat = Matrix4x4::Perspective(45, width / (float)height, 0.1, 1000);
}

void TextApp::OnUpdate(float deltaTime)
{
	GLAppBase::OnUpdate(deltaTime);
	m_Angle += deltaTime * 200;

	CInput::GetState(RECT{});

	if (CInput::GetKeyDown(DIK_NUMPAD1))
	{
		font->SetTextAlignment(EAlignment::LEFT_BOTTOM);
	}
	if (CInput::GetKeyDown(DIK_NUMPAD2))
	{
		font->SetTextAlignment(EAlignment::CENTER_BOTTOM);
	}
	if (CInput::GetKeyDown(DIK_NUMPAD3))
	{
		font->SetTextAlignment(EAlignment::RIGHT_BOTTOM);
	}
	if (CInput::GetKeyDown(DIK_NUMPAD4))
	{
		font->SetTextAlignment(EAlignment::LEFT_MIDDLE);
	}
	if (CInput::GetKeyDown(DIK_NUMPAD5))
	{
		font->SetTextAlignment(EAlignment::CENTER_MIDDLE);
	}
	if (CInput::GetKeyDown(DIK_NUMPAD6))
	{
		font->SetTextAlignment(EAlignment::RIGHT_MIDDLE);
	}
	if (CInput::GetKeyDown(DIK_NUMPAD7))
	{
		font->SetTextAlignment(EAlignment::LEFT_TOP);
	}
	if (CInput::GetKeyDown(DIK_NUMPAD8))
	{
		font->SetTextAlignment(EAlignment::CENTER_TOP);
	}
	if (CInput::GetKeyDown(DIK_NUMPAD9))
	{
		font->SetTextAlignment(EAlignment::RIGHT_TOP);
	}

	if (CInput::GetKeyDown(DIK_1))
	{
		font->SetColor(Color::orange);
	}
	if (CInput::GetKeyDown(DIK_2))
	{
		font->SetColor(Color::cyan);
	}
	if (CInput::GetKeyDown(DIK_3))
	{
		font->SetColor(Color::green);
	}
	if (CInput::GetKeyDown(DIK_4))
	{
		font->SetColor(Color::red);
	}

	float h = CInput::GetAxis("Horizontal");
	float v = CInput::GetAxis("Vertical");
	if (h != 0.0f)
	{
		font_interval_x += h * 0.01f;
		font->SetIntervalX(font_interval_x);
	}
	if (v != 0.0f)
	{
		font_interval_y += v * 0.05f;
		font->SetIntervalY(font_interval_y);
	}
}

void TextApp::OnRender()
{
	GLAppBase::OnRender();

	glPushMatrix();
	glRotatef(m_Angle, 0, 0, 1);
	glBegin(GL_QUADS);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glEnd();
	glPopMatrix();

	font->OnRender(modelMat, viewMat, projectionMat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);
}