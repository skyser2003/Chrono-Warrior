struct PixelInput
{
	float4 position : SV_POSITION;
	float4 color : COLOR;
	float2 tex : TEXCOORD;
};

Texture2D tex;
SamplerState MeshSampler;

float4 PixelTextureMain(PixelInput pixel) : SV_TARGET
{
	float4 textureColor;
	textureColor = tex.Sample(MeshSampler, pixel.tex) * pixel.color;

	return textureColor;
}