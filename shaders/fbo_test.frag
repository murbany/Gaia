#version 400

uniform sampler2D u_fluxTex;
uniform sampler2D u_velTex;
uniform sampler2D u_terrainAttrTex;


in vec2 fs_Texcoord;

out vec4 fragColor;


vec4 sampleTerrainAttrTex(vec2 texcoord)
{
	return texture(u_terrainAttrTex, texcoord);
}

vec4 sampleFluxTex(vec2 texcoord)
{
	return texture(u_fluxTex, texcoord);
}

vec4 sampleVelocityTex(vec2 texcoord)
{
	return texture(u_velTex, texcoord);
}

void main(void)
{
	vec4 fluxColor = sampleFluxTex(fs_Texcoord);
	vec4 velocityColor = sampleVelocityTex(fs_Texcoord);
	vec4 terrainColor = sampleTerrainAttrTex(fs_Texcoord);
	terrainColor.r = terrainColor.r/200;
	//fragColor = vec4(terrainColor.rgb, 1.0);
	
	//fragColor = terrainColor + fluxColor + velocityColor;
	
	//fragColor = terrainColor;
	//fragColor = fluxColor;
	fragColor = abs(velocityColor);
	

	//fragColor = vec4(fs_Texcoord, 0, 1);
	//fragColor = vec4(0,terrainColor.g, 0, 1);
	//fragColor = vec4(terrainColor.r,0, 0, 1);


}
