#version 410
layout(location = 0) in vec4 a_VertexPosition;
layout(location = 1) in vec2 a_Texcoord;
layout(location = 2) in vec4 a_Color;
layout(location = 3) in vec4 a_TexRange;
layout(location = 4) in mat4 a_ModelMatrix;

uniform mat4 M;
uniform mat4 V;
uniform mat4 P;

out VERTEX{
	vec2 uv;
	vec4 range;
	vec4 color;
}vertex;

void main()
{
	vertex.uv = a_Texcoord;
	vertex.range = a_TexRange;
	vertex.color = a_Color;
	gl_Position = P * V * M * a_ModelMatrix * a_VertexPosition;
}