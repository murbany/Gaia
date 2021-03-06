#include "constants.h"

// Program flow switches

bool genNormalMap = false;
bool enableErosion = true;
bool enableTexcoords = false;
bool enableWaterTest = false;
bool enableTimers = false;

int NUM_QUADS = 1;
vec2 SUBDIV = vec2(32, 32);
float texScale = 1;
float heightScale = 200;
vec3 lightPosWorld = vec3(10, 10, 10);
float gridSpacing = 1;
float pixelsPerEdge = 10;
float tessLevelInner = 3;
float tessLevelOuter = 3;

WATER_SOURCE waterSource = NOSOURCE;
float deltaT = 0.05;
float virtualPipeLength = 1.0;
float virtualPipeArea = virtualPipeLength*virtualPipeLength;
float Kc = 0.01;
float Ks = 0.01;
float Ke = 0.001;
vec2 simRes(1280,720);
vec2 screenRes(1280,720);
//const char* heightmapPath = "../../textures/earthbump1024.png";
//const char* heightmapPath = "../../textures/random.png";
//const char* heightmapPath = "../../textures/test2.png";
//const char* heightmapPath = "../../textures/test1024.png";

const char* heightmapPath = "../../textures/terrain_heights.jpg";
const char* normalmapPath = "../../textures/terrain_normals.jpg";
const char* diffusemapPath = "../../textures/terrain_diffuse.jpg";
const char* grassTexPath = "../../textures/grass.jpg";
const char* rockTexPath = "../../textures/rock.jpg";
const char* dirtTexPath = "../../textures/dirt.jpg";

const char* cubeMapUpImgPath = "../../textures/skybox/sunnyUp.png";
const char* cubeMapDownImgPath = "../../textures/skybox/sunnyDown.png";
const char* cubeMapLeftImgPath = "../../textures/skybox/sunnyLeft.png";
const char* cubeMapRightImgPath = "../../textures/skybox/sunnyRight.png";
const char* cubeMapFrontImgPath = "../../textures/skybox/sunnyFront.png";
const char* cubeMapBackImgPath = "../../textures/skybox/sunnyBack.png";
const char* foamTextureImgPath = "../../textures/foam_texture.jpg";

const char* vertShaderPath = "../../shaders/static_heightmap.vert";
const char* tessCtrlShaderPath = "../../shaders/static_heightmap.tc";
const char* tessEvalShadePath = "../../shaders/static_heightmap.te"; 
const char* fragShaderPath = "../../shaders/static_heightmap.frag";

const char* vertQuadShaderPath = "../../shaders/static_quad_heightmap.vert";
const char* tessQuadCtrlShaderPath = "../../shaders/static_quad_heightmap.tc";
const char* tessQuadEvalShadePath = "../../shaders/static_quad_heightmap.te"; 
const char* fragQuadShaderPath = "../../shaders/static_quad_heightmap.frag";

const char* nmapVertShaderPath = "../../shaders/nmap.vert";
const char* nmapFragShaderPath = "../../shaders/nmap.frag";

const char* smooth1FragShaderPath = "../../shaders/smoothIntermediate.frag";
const char* smoothFragShaderPath = "../../shaders/smooth.frag";

const char* vertTerrainTexInitPath = "../../shaders/Terrain_Initialization.vert";
const char* fragTerrainTexInitPath = "../../shaders/Terrain_Initialization.frag";

const char* vertFboTestPath = "../../shaders/fbo_test.vert";
const char* fragFboTestPath = "../../shaders/fbo_test.frag";

const char* vertCopyPath = "../../shaders/Copy_Texture.vert";
const char* fragCopyPath = "../../shaders/Copy_Texture.frag";

const char* vertSkyboxShaderPath = "../../shaders/skybox.vert";
const char* fragSkyboxShaderPath = "../../shaders/skybox.frag";

const char* vertWaterPath = "../../shaders/water.vert";
const char* fragWaterPath = "../../shaders/water.frag";

// todo copy shader paths to copy textures

const char* vertErosDepoPath = "../../shaders/Erosion_Deposition.vert";
const char* fragErosDepoPath = "../../shaders/Erosion_Deposition.frag";
const char* vertEvapPath = "../../shaders/Evaporation.vert";
const char* fragEvapPath = "../../shaders/Evaporation.frag";
const char* vertFlowSimFluxPath = "../../shaders/Flow_Sim_Flux_Update.vert";
const char* fragFlowSimFluxPath = "../../shaders/Flow_Sim_Flux_Update.frag";
const char* vertFlowSimVelPath = "../../shaders/Flow_Sim_Velocity_Field_Update.vert";
const char* fragFlowSimVelPath = "../../shaders/Flow_Sim_Velocity_Field_Update.frag";
const char* vertFlowSimWatHeightPath = "../../shaders/Flow_Sim_Water_Height_Update.vert";
const char* fragFlowSimWatHeightPath = "../../shaders/Flow_Sim_Water_Height_Update.frag";
const char* vertSedTransPath = "../../shaders/Sediment_Transport.vert";
const char* fragSedTransPath = "../../shaders/Sediment_Transport.frag";
const char* vertWatIncPath = "../../shaders/Water_Increment.vert";
const char* fragWatIncPath = "../../shaders/Water_Increment.frag";

// uniform ids
char* U_FARID = "u_Far";
char* U_NEARID = "u_Near";
char* U_MODELID = "u_Model";
char* U_VIEWID = "u_View";
char* U_PERSPID = "u_Persp";
char* U_TESSINNERID = "u_tessLevelInner";
char* U_TESSOUTERID = "u_tessLevelOuter";
char* U_TEXSCALEID = "u_texScale";
char* U_GRIDSPACINGID = "u_gridSpacing";
char* U_NUMPATCHESID = "u_numPatches";
char* U_HEIGHTMAPID = "u_heightMap";
char* U_HEIGHTSCALEID = "u_heightScale";
char* U_MVINVTRANSID = "u_mvInvTrans";
char* U_PVMID = "u_pvm";
char* U_LIGHTPOSWORLDID = "u_lightPosWorld";
char* U_PIXELSPEREDGE = "u_pixelsPerEdge";
char* U_NORMALMAPID = "u_normalMap";
char* U_DIFFUSEMAPID = "u_diffuseMap";
char* U_TOGGLENORMALID = "u_toggleNormal";
char* U_SCREENSIZEID = "u_screen_size";
char* U_SOURCETEXID = "u_sourceTex";
char* U_TERRAINATTRTEXID = "u_terrainAttrTex";
char* U_DELTATID = "u_deltaT";
char* U_FLUXTEXID = "u_fluxTex";
char* U_VELTEXID = "u_velTex";
char* U_VIRTUALPIPEAREAID = "u_virtualPipeArea";
char* U_VIRTUALPIPELENGTHID = "u_virtualPipeLength";
char* U_KCID = "u_Kc";
char* U_KSID = "u_Ks";
char* U_KEID = "u_Ke";
char* U_UP = "u_up";
char* U_CUBEMAPID = "u_cubemap";
char* U_LIGHTCOLORID = "u_lightColor";
char* U_LIGHTDIRECTIONID = "u_lightDirection";
char* U_FRESNELTERMID = "u_fresnelR0";
char* U_CAMPOSID = "u_cameraPosition";
char* U_FOAMTEXID = "u_foamMap";
char* U_MANIPCENTERID = "u_manipCenter";
char* U_MANIPRADIUSID = "u_manipRadius";
char* U_WTRSRCID = "u_waterSrc";
char* U_USERINTID = "u_userInteraction";
char* U_RANDSEED = "u_randomSeed";
char* U_COMPUTEDNORMALMAPID = "u_computedNormalMap";
char* U_KERNELSIZEXID = "u_kernelX";
char* U_KERNELSIZEYID = "u_kernelY";
char* U_GRASSTEXID = "u_grassTex";
char* U_ROCKTEXID = "u_rockTex";
char* U_DIRTTEXID = "u_dirtTex";
