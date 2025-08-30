#version 330 core
in vec3 ourColor; // received from vertex shader
out vec4 FragColor;

void main(){
    FragColor = vec4(ourColor, 1.0);//Cyan-Like color
}
