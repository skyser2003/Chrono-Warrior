struct VertexInput
{
	float4 position : POSITION;
	float4 color : COLOR;
	float2 tex : TEXCOORD;
};

struct PixelInput
{
	float4 position : SV_POSITION; // what is the difference between SV_POSITION and POSITION?
	float4 color : COLOR;
	float2 tex : TEXCOORD;
};

cbuffer MatrixBuffer
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projectionMatrix;
};

PixelInput VertexTextureMain(VertexInput vertex)
{
	PixelInput pixel;

	vertex.position.w = 1.0f;
	pixel.position = mul(vertex.position, worldMatrix);
	pixel.position = mul(pixel.position, viewMatrix);
	pixel.position = mul(pixel.position, projectionMatrix);

	pixel.tex = vertex.tex;
	pixel.color = vertex.color;

	return pixel;
}