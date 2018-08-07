#pragma once
#include"Math.h"
#include"EngineDefine.h"

USING_NAMESPACE_ENGINE;

class InterpolateHelper
{
	static float Interpolate(float a, float b, float t);
	static Color Interpolate(const Color& a, const Color& b, float t);
	static Vector2 Interpolate(const Vector2& a, const Vector2& b, float t);
	static Vector3 Interpolate(const Vector3& a, const Vector3& b, float t);
	static Vector4 Interpolate(const Vector4& a, const Vector4& b, float t);
	static Matrix4x4 Interpolate(Matrix4x4& a, Matrix4x4& b, float t);
	static Quaternion Interpolate(const Quaternion& a, const Quaternion& b, float t);
};

template<typename T>
struct InterpolatorNode {
	T		value;
	float	time;

	InterpolatorNode() { }
	InterpolatorNode(float time, T value) : time(time), value(value) { }
};

template<typename T>
class Interpolator {
private:
	vector<InterpolatorNode<T>> m_List;

public:
	void Insert(float time, const T& t)
	{
		for (auto it = m_List.begin(); it != m_List.end(); ++it)
		{
			if (time < it->time)
			{
				m_List.insert(it, InterpolatorNode(t, time));
				return;
			}
		}
		m_List.push_back(InterpolatorNode(t, time));
	}

	T Get(float time)
	{
		for (uint sampleIndex = 0; sampleIndex < m_List.size() - 1; sampleIndex++)
		{
			InterpolatorNode<T>& a = m_List[sampleIndex];
			InterpolatorNode<T>& b = m_List[sampleIndex + 1];

			if (a.time <= t && b.time >= t)
			{
				float t = (time - a.time) / (b.time - a.time);
				return InterpolateHelper::Interpolate(a.value, b.value, t);
			}
		}
		return T{};
	}
};