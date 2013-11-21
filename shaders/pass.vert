#version 400

uniform mat4x4 u_Model;
uniform mat4x4 u_View;
uniform mat4x4 u_Persp;

in vec3 Position;
in vec3 Texcoords;
out vec3 vPosition;
out vec3 vPositionCamSpace;

void main(void) {
    vec4 world = u_Model * vec4(Position, 1.0);
    vec4 camera = u_View * world;
	vPositionCamSpace = camera.xyz;
    //vPosition =  (u_Persp * camera).xyz;
	//gl_Position = u_Persp*camera;
	vPosition = Position.xyz;
}
