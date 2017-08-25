#include"ColladaTest.h"
#include"ColladaFile.h"
#include"MeshCube.h"
#include"Maker.h"
#include<glm\glm.hpp>

void CColladaTest::OnStart()
{
	_MainCamera->SetCameraClearFlag(ECameraClearFlag::SolidColor);
	_MainCamera->SetCameraClearColor(Color::Hex(0x314D79FF));
	_MainCameraGo->SetLocalPosition(Vector3(0, 6.8, 10));
	_MainCameraGo->SetLocalEulerAngles(Vector3(-25, 180, 0));

	model = _Maker->Instantiate("model");

	//model->SetLocalScale(Vector3(0.1f, 0.1f, 0.1f) * 2);
	//model->SetLocalEulerAngles(Vector3(0, 90, 0));
	//CMaterial* model_mat = _Maker->Instantiate<CMaterial>()->SetShader(CShader::Get("skinning"))
	//	->SetMainTexture(CTexture2D::Create("textures/longxia.png"));
	//collada = _Resources->Load<CColladaFile>("models/longxia.dae");

	model->SetLocalScale(Vector3(0.1f, 0.1f, 0.1f) * 10);
	model->SetLocalEulerAngles(Vector3(0, 0, 0));
	CMaterial* model_mat = _Maker->Instantiate<CMaterial>()->SetShader(CShader::Get("skinning"));
	collada = _Resources->Load<CColladaFile>("models/walk.dae");

	model->AddComponent<CSkinnedMeshRenderer>()->SetModel(collada)->SetMaterial(model_mat);
}

void CColladaTest::OnUpdate()
{
	//Vector3 euler = model->GetLocalEulerAngles();
	//euler.y += CTime::deltaTime * 50;
	//model->SetLocalEulerAngles(euler);

	float h = CInput::GetAxis("Horizontal") * CTime::deltaTime * 20;
	float v = CInput::GetAxis("Vertical") * CTime::deltaTime * 20;
	Vector3 position = model->GetLocalPosition();
	position.x += h;
	position.y += v;
	if (CInput::GetKey(DIK_NUMPAD2))
	{
		position.z += CTime::deltaTime * 20;
	}
	if (CInput::GetKey(DIK_NUMPAD8))
	{
		position.z -= CTime::deltaTime * 20;
	}
	//model->SetLocalPosition(position);
	static float t = 0;
	t += h * 0.1f;
	collada->Sample(t);
}

void CColladaTest::OnRender()
{

}

void CColladaTest::OnClose()
{

}

void CColladaTest::GetApplicationInfo(SApplicationInfo* info)
{
	if (info)
	{
		info->windowWidth = _Config->GetValue<int>("window", "width");
		info->windowHeight = _Config->GetValue<int>("window", "height");
		info->isFullScreen = _Config->GetValue<bool>("window", "full_screen");
		info->windowBits = 32;
		info->appName = L"GameEngineTest";
		info->className = L"MainClass";
	}
}