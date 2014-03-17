struct PixelInput
{
	float4 position : SV_POSITION;
	float4 color : COLOR;
	float2 tex : TEXCOORD;
};

float4 PixelColorMain(PixelInput pixel) : SV_TARGET
{
	float4 textureColor = pixel.color;

	return textureColor;
}