#version 330 core
out vec4 FragColor;
  
  in vec2 Texcordinates;
  in vec3 FragPos;
  in vec3 normal;





void main()
{
	
   FragColor = vec4(1.0,Texcordinates,1.0);
   
}