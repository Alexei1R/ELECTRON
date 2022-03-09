#version 330 core
out vec4 FragColor;
  
  in vec2 Texcordinates;
  in vec3 FragPos;
  in vec3 normal;


  uniform vec3 camPos;
  uniform vec3 viewDir;

vec3 lightColor = vec3(1.0f);
vec3 objectColor = vec3(0.1f,0.5f,0.5f);
vec3 lightPos = vec3(1.0,2.0,2.0);
float specularStrength = 0.5;


void main()
{
	float ambientStrength = 0.4;
    vec3 ambient = ambientStrength * lightColor;


    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(lightPos - FragPos);  
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;


    vec3 vDir = normalize(viewDir - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(vDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;  




    vec3 result = (ambient + diffuse + specular) * objectColor;
    FragColor = vec4(result, 1.0);
   
}






