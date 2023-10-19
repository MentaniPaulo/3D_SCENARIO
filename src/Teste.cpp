#include "Teste.h"
#include "Models/Shader.h"
#include <IndexBuffer.h>
#include <VertexArray.h>

namespace Test_initial {

float positions[] = {
    -0.5f, -0.5f,
     0.0f,  0.5f,
     0.5f, -0.5f
};

unsigned int indice[] = {
    0, 1, 2
};

 
bool fist_call_1 = 1;
bool fist_call_2 = 1;
VertexBuffer* form;
IndexBuffer* index;
VertexArray* VAO;

void SetBojectOnMemory() {
	//vertex array
    if (fist_call_1) {

        VAO = new VertexArray;
        form = new VertexBuffer(&positions, sizeof(positions));
        index = new IndexBuffer(indice, 3);
    
    }

	index->Bind();

	fist_call_1 = 0;
}


void initial_configuration(){

    //load shader file
    Shaders Fragmented;
    Fragmented.filepath = "D:\\Dev_Software\\C++\\3D_scenario\\src\\Shaders\\Fragmented\\FragmentedShader.shader";
    Fragmented.kind = ShaderKind::Fragmented;

    Shaders Vertex;
    Fragmented.filepath = "D:\\Dev_Software\\C++\\3D_scenario\\src\\Shaders\\Vertex\\VertexShaders.shader";
    Fragmented.kind = ShaderKind::Vertex;

    ShaderCompiler shaders({Fragmented, Vertex});

    SetBojectOnMemory();
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
	glEnableVertexAttribArray(0);
}

void loop_render(){
        SetBojectOnMemory();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);   

}
}