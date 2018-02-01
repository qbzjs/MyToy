#ifndef _MESH_BUFFER_H_
#define _MESH_BUFFER_H_

#include<gl\glew.h>
#include"RenderBuffer.h"
#include"Math.h"
#include"SpCommon\EngineDefine.h"
#include"SpCommon\Object.hpp"
#include"SkeletonAnimation.h"

BEGIN_NAMESPACE_ENGINE

enum class EBufferType
{
	VertexData = 0,
	IndexData = 1,
};

enum class EBufferUsage
{
	StaticDraw = GL_STATIC_DRAW,
	DynamicDraw = GL_DYNAMIC_DRAW,
};

enum class EDataType
{
	BYTE = GL_BYTE,
	UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
	SHORT = GL_SHORT,
	UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
	INT = GL_INT,
	UNSIGNED_INT = GL_UNSIGNED_INT,
	FLOAT = GL_FLOAT,
	_2_BYTES = GL_2_BYTES,
	_3_BYTES = GL_3_BYTES,
	_4_BYTES = GL_4_BYTES,
	DOUBLE = GL_DOUBLE,
};

SMART_CLASS(MeshBuffer) class MeshBuffer : public IRenderBuffer
{
public:
	MeshBuffer();
	MeshBuffer(PMesh mesh);
	virtual ~MeshBuffer();

	void MakePositionBuffer(const Vector3* vertices, int size);
	void UpdateVertices(const Vector3* vertices, int offset, int size);
	virtual void MakeBuffer(PMesh mesh);
	virtual void BindBuffer() override;
	virtual void ReleaseBuffer() override;
	inline void UnbindBuffer() { glBindVertexArray(0); }
	inline int GetVertexNum() const { return m_VertexNum; }

	static void MakeVertexBuffer(GLuint* bufferId, int dataSize, int componentCount, const void* pointer, int attrPos, EBufferUsage usage, EDataType dataType = EDataType::FLOAT);
	static void MakeIntegerVertexBuffer(GLuint* bufferId, int dataSize, int componentCount, const void* pointer, int attrPos, EBufferUsage usage, EDataType dataType = EDataType::INT);
	static void MakeInstanceVertexBuffer(GLuint* bufferId, int structSize, int componentCount, int instanceCount, const void* pointer, int attrPos, EBufferUsage usage, EDataType dataType = EDataType::FLOAT);
	static void MakeIndexBuffer(GLuint* bufferId, int dataSize, const void* pointer);
	static void UpdateVertexBuffer(GLuint bufferId, int offset, int dataSize, const void* pointer);
	static void DeleteBufer(GLuint* bufferId);

private:
	int				m_VertexNum;
	GLuint			m_VaoHandle;
	GLuint			m_VboPositionHandle;
};

END_NAMESPACE_ENGINE

#endif