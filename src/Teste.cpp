#include "Teste.h"
#include "Models/Shader.h"

namespace Test_initial {

float positions[] = {
    -0.5f, -0.5f,
     0.0f,  0.5f,
     0.5f, -0.5f
};

unsigned int indice[] = {
    0, 1, 2
};

unsigned int VAO_principal;

unsigned int IB0_principal;

void initial_configuration(){

    //load shader file
    Shaders Fragmented;
    Fragmented.filepath = "D:\\Dev_Software\\C++\\3D_scenario\\src\\Shaders\\Fragmented\\FragmentedShader.shader";
    Fragmented.kind = ShaderKind::Fragmented;

    Shaders Vertex;
    Fragmented.filepath = "D:\\Dev_Software\\C++\\3D_scenario\\src\\Shaders\\Vertex\\VertexShaders.shader";
    Fragmented.kind = ShaderKind::Vertex;

    ShaderCompiler shaders({Fragmented, Vertex});

    VertexBuffer form(&positions, sizeof(positions));

    glGenVertexArrays(1, &VAO_principal); //Vertex Array
    glBindVertexArray(VAO_principal);
    
	glGenBuffers(1, &IB0_principal);//Index buffer

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB0_principal);
	
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indice), indice, GL_STATIC_DRAW);
}

void loop_render(){
    glBindVertexArray(VAO_principal);
    
}

}