#include"Resources.h"
#include"ColladaFile.h"

AnimationClip* CResources::LoadAnimation(string path)
{
	CColladaFile* modelFile = _Resources->Load<CColladaFile>(path);
	Model* model = modelFile->m_model;
	AnimationClip* clip = NULL;
	if (model->m_animationCount > 0)
		clip = &model->m_animations[0];
	for (int i = 0; i < model->m_meshCount; ++i)
	{
		delete(&model->m_meshes[i]);
	}
	for (int i = 1; i < model->m_animationCount; ++i)
	{
		delete(&model->m_animations[i]);
	}
	delete(model);
	delete(modelFile);
	return clip;
}

void CResources::Unload(string& path)
{
	auto it = m_sources.find(path);
	if (it != m_sources.end())
	{
		ISourceFile* sourceFile = it->second;
		sourceFile->ReleaseSource();
		m_sources.erase(it);
		delete(sourceFile);
	}
}