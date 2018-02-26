#pragma once

#include<physx_3.2\PxPhysicsAPI.h>
#include"SpCommon\Math.h"
#include"SpRendering\MeshBuffer.h"
#include"SpRendering\Material.h"
#include"SpRendering\GLRendering.h"

USING_NAMESPACE_ENGINE;

SMART_CLASS(GameObject) class GameObject : public Object
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void OnRender(IRenderingInterface& ri, const Matrix4x4& v, const Matrix4x4& p);
	virtual void OnUpdate(float deltaTime);
	inline void SetPosition(const Vector3& position) { m_Position = position; }
	inline void SetScale(const Vector3& scale) { m_Scale = scale; }
	inline void SetRotation(const Quaternion& rotation) { m_Rotation = rotation; }
	inline void SetMaterial(PMaterial material) { m_Material = material; }
	inline void SetMeshBuffer(PMeshBuffer meshbuffer) { m_MeshBuffer = meshbuffer; }
	inline Vector3 position() const { return m_Position; }
	inline Vector3 scale() const { return m_Scale; }
	inline Quaternion rotation() const { return m_Rotation; }
	inline PMaterial material() const { return m_Material; }
	inline PMeshBuffer meshBuffer() const { return m_MeshBuffer; }
	void GetModelMatrix(Matrix4x4& out) const;

protected:
	Vector3			m_Position;
	Vector3			m_Scale;
	Quaternion		m_Rotation;
	PMaterial		m_Material;
	PMeshBuffer		m_MeshBuffer;
	Matrix4x4		m_ModelMatrix;
};
