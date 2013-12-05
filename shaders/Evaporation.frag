#version 400

uniform sampler2D u_terrainAttrTex;
uniform float u_deltaT;
uniform float u_Ke = 0.001;

in vec2 texcoord;
out vec4 out_terrainAttr;

void main (void)
{
	out_terrainAttr = texture( u_terrainAttrTex, texcoord);
	out_terrainAttr.g = out_terrainAttr.g* ( 1.0 - u_Ke*u_deltaT);
}
