#ifndef H_SHADERMANAGER
#define H_SHADERMANAGER

#include "common.h"
#include "context.h"

class CShaderManager final{
public:
    CShaderManager();
    ~CShaderManager();

    VkShaderModule vertShaderModule;
	VkShaderModule fragShaderModule;
    VkShaderModule computeShaderModule;

    void CreateVertexShader(const std::string shaderName);
    void CreateFragmentShader(const std::string shaderName);
    void CreateComputeShader(const std::string shaderName);

    //bool bEnablePushConstant;
    VkPushConstantRange pushConstantRange;
    template<typename T>
    void CreatePushConstantRange(VkShaderStageFlagBits shaderStageFlagBits, uint32_t offset){
        //bEnablePushConstant = true;
        pushConstantRange.stageFlags = shaderStageFlagBits;
        pushConstantRange.offset = offset;
        pushConstantRange.size = sizeof(T);
    }

    void Destroy();

#ifndef ANDROID
    bool InitSpirVShader(const std::string shaderName, VkShaderModule *pShaderModule);
#else
    //insert a string after separator: "ab/c","wxj",'/'=>ab/wxjc"
    std::string InsertString(std::string originalString, std::string insertString, char separator);
    VkShaderModule createShaderModule(const std::vector<uint8_t> &code);
#endif
private:
    bool readFile(const std::string& filename, std::vector<char> &buffer);
};

#endif