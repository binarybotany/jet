#version 330 core

out vec4 out_color;

in vec3 vs_color;
in vec2 vs_texture_coordinates;

uniform sampler2D texture_sampler;

void main() {
    out_color = 
        texture(texture_sampler, vs_texture_coordinates) * vec4(vs_color, 1.0);
}