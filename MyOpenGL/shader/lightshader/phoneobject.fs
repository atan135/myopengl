#version 330 core
in vec3 Normal;
in vec3 FragPos;
out vec4 FragColor;
uniform vec3 lightColor;
uniform vec3 objectColor;
uniform vec3 lightPos;
uniform vec3 viewPos;
void main()
{
	float ambientStrength = 0.2f;
	vec3 ambient = ambientStrength * lightColor;

	vec3 lightDir = normalize(lightPos - FragPos);
	vec3 diffuse = max(dot(lightDir, Normal), 0.0) * lightColor;

	vec3 reflectDir = reflect(-lightDir, Normal);
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 specular = pow(max(dot(viewDir, reflectDir), 0.0), 32) * lightColor;

	vec3 result = (ambient + diffuse + specular) * objectColor;;
	FragColor = vec4(result, 1.0);
}