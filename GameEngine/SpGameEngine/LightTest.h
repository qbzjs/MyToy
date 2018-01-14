#include"Application.h"
#include"Engine.h"
#include"SpCommon\EngineDefine.h"
#include"Input.h"
#include"Time.h"
#include"SpRendering\RenderTexture.h"
#include"SpAssetLoader\3DSModelLoader.h"
#include"Resources.h"
#include "SpCommon\Debug.h"
#include"Config.h"
#include"SkinnedMeshRenderer.h"
#include"SpAssetLoader\ColladaLoader.h"
#include"LightComponent.h"
#include<vector>

using namespace std;

class CLightTest : public CGameWindow
{
	ColladaLoader* collada;
	Model* m_model;
	CGameObject* model;
	CGameObject* directionalGo;
	CGameObject* pointGo;
	CLightComponent* pointLight;
	vector<AnimationClip*> m_clips;
	CTexture* m_texture;
public:
	virtual void OnStart();

	virtual void OnUpdate();

	virtual void OnRender();

	virtual void OnClose();

	//Ӧ�ó������ʵ�ֵĺ���
	virtual void GetApplicationInfo(SApplicationInfo* info);
};
