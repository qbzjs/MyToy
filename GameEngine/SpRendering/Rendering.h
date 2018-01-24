#ifndef _RENDERING_H_
#define _RENDERING_H_

#include"SkeletonAnimation.h"
#include"Material.h"
#include"MeshBuffer.h"

namespace spgameengine
{

	class RenderingStartUpParams
	{

	};

	SMART_CLASS(RenderingObject) class RenderingObject
	{
	public:
		PMeshBuffer mesh;
		shared_ptr<Material> material;
	};

	class IRenderingInterface
	{
	public:
		virtual void StartUp(const RenderingStartUpParams* params) = 0;
		virtual void Render(PRenderingObject obj, Matrix4x4& modelMatrix,
			Matrix4x4& viewMatrix, Matrix4x4& projectionMatrix) = 0;
		virtual void MakeRenderContext() = 0;
		virtual void ShutDown() = 0;
	};

	class GraphicsManager {
	private:
		IRenderingInterface* m_RenderingInterface;
	};

}

#endif